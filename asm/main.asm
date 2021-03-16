.sdsctag 1.0,"Van Halen","Van Halen Record Covers for the SMS Power! 2021 Competition","StevePro Studios"

.include "devkit/memory_manager.inc"
.include "devkit/enum_manager.inc"
.include "devkit/define_manager.inc"


.BANK 0 SLOT 0
.ORG $0000

.section "Boot" force	
LABEL_0_:
		di
		im 1
		jp LABEL_70_

SMS_crt0_RST08:
	.db $00 $00

LABEL_8_:
		ld c, Port_VDPAddress
		di
		out (c), l
		out (c), h
		ei
		ret

SMS_crt0_RST18:
.rept 7
	nop
.endr

	ld a, l
	out ($be), a
	ld a, h
	sub a, $00
	nop
	out ($be), a
	ret

.rept 22
	nop
.endr
.ends


.ORG $0038
.section "VDP interrupt" force
LABEL_38_:
		jp SMS_isr
.ends

	.dsb 43, $00

.ORG $0066
.section "Pause interrupt" force
LABEL_66_:
		jp SMS_nmi_isr
.ends

	.db $00 $00 $00 $00 $00 $00 $00


.section "Init section" free	; semisubfree
LABEL_70_:
		ld sp, $DFF0
		ld de, _RAM_FFFC_
		xor a
		ld (de), a
		ld b, $03
-:
		inc de
		ld (de), a
		inc a
		djnz -
		xor a
		ld hl, pause_status		; Lmain.main$global_pause$1$55 = $C000
		ld (hl), a
		ld de, PSGMusicStatus	; PSGMusicStatus = $C001
		ld bc, $1FF0
		ldir
		call gsinit
		call SMS_init
		ei
		call main
		jp exit
.ends

.include "content/out.inc"


.section "Other functions" free
clock:
		ld a, $02
		rst $08
		ret

exit:
		ld a, $00
		rst $08	; LABEL_8_
-:
		halt
		jr -
.ends


.section "Main section" free
main:
		call engine_asm_manager_clear_VRAM
		call devkit_SMS_init
		call devkit_SMS_displayOff
		call devkit_SPRITEMODE_NORMAL
		ld b, l
		push bc
		inc sp
		call devkit_SMS_setSpriteMode
		inc sp
		call devkit_SMS_useFirstHalfTilesfor
		call devkit_VDPFEATURE_HIDEFIRSTCOL
		push hl
		call devkit_SMS_VDPturnOnFeature
		pop af
		call engine_content_manager_load_til
		call engine_content_manager_load_spr
		call engine_scroll_manager_reset
		ld a, $01			; screen_type_splash
		push af
		inc sp
		call engine_screen_manager_init
		inc sp
		call devkit_SMS_displayOn
infinite_loop:
		call devkit_SMS_queryPauseRequested
		ld a, l
		or a
		jr z, global_pause
		call devkit_SMS_resetPauseRequest
		ld iy, pause_status		; Lmain.main$global_pause$1$55 = $C000
		ld a, (iy+0)
		xor $01
		ld (iy+0), a
		bit 0, (iy+0)
		jr z, else_clause
		call devkit_PSGSilenceChannels
		jr global_pause

else_clause:
		call devkit_PSGRestoreVolumes
global_pause:
		ld hl, pause_status		; Lmain.main$global_pause$1$55 = $C000
		bit 0, (hl)
		jr nz, infinite_loop
		call devkit_SMS_initSprites
		call engine_input_manager_update
		call engine_screen_manager_update
		call devkit_SMS_finalizeSprites
		call devkit_SMS_waitForVBlank
		call devkit_SMS_copySpritestoSAT
		call devkit_PSGFrame
		call devkit_PSGSFXFrame
		jr infinite_loop
.ends

; devkit
.include "devkit/psg_manager.inc"
.include "devkit/devkit_manager.inc"


; engine
.include "engine/asm_manager.inc"
.include "engine/audio_manager.inc"
.include "engine/content_manager.inc"
.include "engine/cursor_manager.inc"
.include "engine/font_manager.inc"
.include "engine/input_manager.inc"
.include "engine/record_manager.inc"
.include "engine/screen_manager.inc"
.include "engine/scroll_manager.inc"
.include "engine/storage_manager.inc"
.include "engine/timer_manager.inc"


; object
.include "object/cursor_object.inc"
.include "object/record_object.inc"


; screen
.include "screen/none_screen.inc"
.include "screen/splash_screen.inc"
.include "screen/title_screen.inc"
.include "screen/scroll_screen.inc"
.include "screen/select_screen.inc"
.include "screen/record_screen.inc"


; content
.include "content/gfx.inc"
.include "content/psg.inc"


.section "Math functions" free
divuint:
		pop af
		pop hl
		pop de
		push de
		push hl
		push af
		jr $0A

divuchar:
		ld hl, $0003
		add hl, sp
		ld e, (hl)
		dec hl
		ld l, (hl)

divu8:
		ld h, $00
		ld d, h

divu16:
		ld a, e
		and $80
		or d
		jr nz, $10
		ld b, $10
		adc hl, hl
		rla
		sub a, e
		jr nc, $01
		add a, e
		ccf

		adc hl, hl
		djnz $F6
		ld e,a
		ret
		ld b, $09
		ld a, l
		ld l, h
		ld h, $00
		rr l
		adc hl, hl

		sbc hl, de
		jr nc, $01
		add hl, de
		ccf
		rla
		djnz $F5
		rl b
		ld d, b
		ld e, a
		ex de, hl
		ret
.ends

; devkit
.include "devkit/sms_manager.inc"


.section "Additional helpers" free
init_curr_joyp:
; static unsigned int curr_joypad1 = 0;
	.db $00 $00

init_prev_joyp:
; static unsigned int prev_joypad1 = 0;
	.db $00 $00

; Data from 2107 to 211E (24 bytes)
init_cursor_al:
; extern const char *cursor_album[ MAX_ALBUMS ];
; $114D $1152 $1157 $115C $1161 $1166	
; $116B $1170 $1175 $117A $117F $1184
	.db $4D $11 $52 $11 $57 $11 $5C $11 $61 $11 $66 $11 $6B $11 $70 $11
	.db $75 $11 $7A $11 $7F $11 $84 $11

init_record_tiles:
; const unsigned char *record_tiles_data[]
	.db $89 $80 $32 $81 $70 $80 $9F $80 $18 $81 $8D $80 $87 $80 $67 $80
	.db $67 $80 $9F $80 $C7 $80 $7A $80

init_record_tilemap:
; const unsigned char *record_tilemap_data[]
	.db $10 $80 $10 $80 $10 $80 $10 $80 $10 $80 $10 $80 $10 $80 $10 $80
	.db $10 $80 $10 $80 $10 $80 $10 $80

init_record_pa:
; const unsigned char *record_palette_data[]
	.db $00 $80 $00 $80 $00 $80 $00 $80 $00 $80 $00 $80 $00 $80 $00 $80
	.db $00 $80 $00 $80 $00 $80 $00 $80 $04 $20 $08 $08

gsinit:
		ld bc, $0068
		ld a, b
		or c
		jr z, +
		ld de, curr_joypad1			; Finput_manager$curr_joypad1$0$0 = $C146
		ld hl, init_curr_joyp		; Finput_manager$__xinit_curr_joyp = $2103
		ldir
+:
		ret
.ends


; Banks.
.include "engine/bank_manager.inc"