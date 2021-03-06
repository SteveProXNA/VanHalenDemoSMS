#include "sample_manager.h"

#ifdef _CONSOLE

void engine_sample_manager_init( const void *psginit )
{
}

void engine_sample_manager_play( const void *sample )
{
}

#else

void engine_sample_manager_init( const void *psginit ) __naked __z88dk_fastcall
{
	( void ) psginit;

	/* ********************************************************************
	Inits Psg
	*/
	__asm


	; Init PSG
		ld bc, #0x0b7f
		otir
		ret
		__endasm;
}

void engine_sample_manager_play( const void *sample )  __naked __z88dk_fastcall
{
	( void ) sample;

	/* ********************************************************************
	Plays a Sample
	*/
	__asm
	; Replayer core to play RLE encoded 8.000kHz samples generated by pcmenc
		;
	; pcmenc should use the following command line arguments :
	;
	; pcmenc - rto 1 - dt1 12 - dt2 12 - dt3 423 file.wav
		;
	; and optionally - r to split sample into blocks for rom replayer
		;

	; There are three channel updates per underlying sample.
		; We emit three channel updates together, as fast as possible, looping
		; every 447 cycles, to match an underlying sample at 8008Hz
		; ( 3579545 / 447 = 8007.9 ).
		; Work costs 309 cycles so we waste 139.


		PLAY_SAMPLE:
	; disable interrupts
		di
		; save ix
		push ix
		ld de, #0x0000
		ld bc, #0x0000
		ld a, ( hl )
		inc hl
		LDIXLA
		ld a, ( hl )
		inc hl
		LDIXHA

		PsgLoop :
	; Calculate channel A volume
		ld a, b; 4
		sub #0x10; 7
		jr nc, PsgWaitA; 7 / 12
		ld a, ( hl ); 7
		inc hl; 6
		ld b, a; 4
		and #0x0f; 7
		or #0x90; 7
		LDIYHA; 8 -> 57
		PsgDoneA:

	; Calculate channel B volume
		ld a, d; 4
		sub #0x10; 7
		jr nc, PsgWaitB; 7 / 12
		ld a, ( hl ); 7
		inc hl; 6
		ld d, a; 4
		and #0x0f; 7
		or #0xb0; 7
		LDIYLA; 8 -> 57
		PsgDoneB:

	; Calculate channel C volume
		ld a, e; 4
		sub #0x10; 7
		jr nc, PsgWaitC; 7 / 12
		ld a, ( hl ); 7
		inc hl; 6
		ld e, a; 4
		and #0x0f; 7
		or #0xd0; 7
		ld c, a; 4 -> 53
		PsgDoneC:

	; Output channels
		push de; 11
		LDDIYH; 8
		LDEIYL; 8
		ld a, c; 4
		push bc; 11
		ld c, #0x7f; 7 -> 49

		out( c ), d; 12
		out( c ), e; 12
		out( c ), a; 12
		pop bc; 10
		pop de; 10 -> 66

		; Waste cycles
		call Delay

		; Decrement length and return if zero
		dec ix; 10
		LDAIXH; 8
		ORIXL; 8
		jp nz, PsgLoop; 10 -> 36
		; restore ix
		pop ix
		; enable interrupts
		ei
		ret

		PsgWaitA :
	ld b, a; 4
		ld a, i; 9
		ld a, i; 9
		jr PsgDoneA; 12 -> 34

		PsgWaitB:
	ld d, a; 4
		ld a, i; 9
		ld a, i; 9
		jr PsgDoneB; 12 -> 34

		PsgWaitC:
	ld e, a; 4
		and #0x0; 7
		and #0x0; 7
		jr PsgDoneC; 12 -> 30

		Delay:
	; call Delay 17
		push bc; 11
		ld b, #0x6; 7
		inner_loop: djnz inner_loop; 13 * 5 + 8
		pop bc; 10
		in a, ( #0x7f ); 11
		ret; 10
		; -- -
		; 139
		__endasm;
}

#endif