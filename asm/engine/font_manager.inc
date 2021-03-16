.section "Font manager" free
engine_font_manager_draw_char:
		push ix
		ld ix, $0000
		add ix, sp
		ld a, (ix + $04)
		add a, $E0
		ld c, a
		push bc
		ld h, (ix + $06)
		ld l, (ix + $05)			; TEXT_ROOT	5
		push hl
		call devkit_SMS_setNextTileatXY
		pop af
		pop bc
		ld hl, font__tilemap__bin
		ld l, (hl)
		ld h, $00
		ld b, $00
		add hl, bc
		push hl
		call devkit_SMS_setTile
		pop af
		pop ix
		ret

engine_font_manager_draw_text:
		push ix
		ld ix, $0000
		add ix, sp
		dec sp
		ld c, (ix + $06)
		ld (ix -1), $00
 font_goto_01:
		ld a, (ix + $04)
		add a, (ix - 1)
		ld e, a
		ld a, (ix + $05)
		adc a, $00
		ld d, a
		ld a, (de)
		or a
		jr z, font_goto_02
		add a, $E0
		ld b, a
		ld d, c
		inc c
		ld (ix + $06), c
		push bc
		ld a, (ix + $07)
		push af
		inc sp
		push de
		inc sp
		call devkit_SMS_setNextTileatXY
		pop af
		pop bc
		ld hl, font__tilemap__bin
		ld e, (hl)
		ld d, $00
		ld a, b
		ld l, a
		rla
		sbc a, a
		ld h, a
		add hl, de
		push bc
		push hl
		call devkit_SMS_setTile
		pop af
		pop bc
		inc (ix - 1)
		jr font_goto_01
font_goto_02:
		inc sp
		pop ix
		ret

engine_font_manager_draw_data:
		push ix
		ld ix, $0000
		add ix, sp
		push af
		ld a, (ix + $06)
		ld (ix - 1), a
		ld (ix - 2), $00
font_goto_03:
		ld hl, $000A					; UNIT_ROOT	10 is decimal
		push hl
		ld l, (ix + $04)
		ld h, (ix + $05)
		push hl
		call divuint					; quotient = data / UNIT_ROOT;
		pop af
		pop af
		ld e, l
		ld d, h
		push hl
		push de
		ld bc, $000A					; UNIT_ROOT	10 is decimal
		push bc
		ld c, (ix + $04)
		ld b, (ix + $05)
		push bc
		call moduint					; remainder = data % UNIT_ROOT;
		pop af
		pop af
		ld b, l
		pop de
		pop hl
		ld (ix + $04), l
		ld (ix + $05), h
		ld a, b
		add a, $10
		ld c, a
		ld a, d
		or e
		jr nz, font_goto_04
		or b
		jr nz, font_goto_04
		ld a, (ix - 2)
		or a
		jr z, font_goto_04
		ld c, $00
font_goto_04:
		ld b, (ix - 1)
		dec (ix - 1)
		ld a, (ix - 1)
		ld (ix + $06), a
		push bc
		ld a, (ix + $07)
		push af
		inc sp
		push bc
		inc sp
		call devkit_SMS_setNextTileatXY
		pop af
		pop bc
		ld hl, font__tilemap__bin
		ld l, (hl)
		ld h, $00
		ld a, c
		rla
		sbc a, a
		ld b, a
		add hl, bc
		push hl
		call devkit_SMS_setTile
		pop af
		inc (ix - 2)
		ld a, (ix - 2)
		sub a, $05
		jr c, font_goto_03
		ld sp, ix
		pop ix
		ret

.ends