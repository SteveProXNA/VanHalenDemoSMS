.section "PSG" free

sfx_cheat_psg:
	.db $CE $4B $D0 $3B $D1 $38 $CF $47 $08 $02 $00 $C7 $49 $0A $02 $00
	.db $09 $02 $00 $45 $D0 $3B $D1 $3B $D2 $3A $D3 $39 $D4 $39 $C3 $55
	.db $DF $3C $00

sfx_right_psg:
	.db $C5 $4D $D0 $3B $CE $48 $3B $C7 $44 $D5 $3A $CA $46 $3B $C5 $4D
	.db $DA $3A $09 $04 $00 $DB $3B $CA $46 $DD $3A $C0 $40 $DF $38 $00

sfx_wrong_psg:
	.db $C5 $4D $D0 $3B $C0 $4A $3B $C7 $49 $3B $CE $48 $D5 $3B $C5 $4D
	.db $3B $C0 $4A $3B $C7 $49 $DA $3B $CE $48 $3B $C0 $49 $3B $C0 $40
	.db $DF $3B $00

.ends