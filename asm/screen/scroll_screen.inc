.section "Scroll screen" free
screen_scroll_screen_load:
		ld hl, scroll_screen_offset		; scroll_screen_offset = $C056
		ld (hl), $00					; offset = 0;
		ret

screen_scroll_screen_update:
		dec sp
		ld a, (scroll_screen_offset)	; scroll_screen_offset = $C056
		sub a, $20						; TOP_SCROLL	32
		jr nz, scroll_screen_goto_01
		ld a, $01						; offset++
		jr scroll_screen_goto_02
scroll_screen_goto_01:
		xor a

scroll_screen_goto_02:
		inc sp
		push af
		inc sp
		ld iy, scroll_screen_offset		; scroll_screen_offset = $C056
		ld b, (iy + $00)
		inc (iy + $00)
		push bc
		inc sp
		call devkit_SMS_setBGScrollY
		inc sp
		ld a, $10						; input_type_fire1	16
		push af
		inc sp
		call engine_input_manager_hold
		inc sp
		ld c, l
		ld hl, $0003
		add hl, sp
		ld a, (hl)
		inc hl
		ld h, (hl)
		ld l, a
		ld a, c
		or a
		jr nz, scroll_screen_goto_03
		ld iy, $0000
		add iy, sp
		ld a, (iy + $00)
		or a
		jr z, scroll_screen_goto_04
scroll_screen_goto_03:
		push hl
		ld a, $04						; TOP_OFFSET	4
		push af
		inc sp
		call engine_scroll_manager_load
		inc sp
		ld a, $20						; TOP_SCROLL	32
		push af
		inc sp
		call devkit_SMS_setBGScrollY
		inc sp
		pop hl
		ld (hl), $04					; screen_type_select = 4
		jr scroll_screen_goto_05
scroll_screen_goto_04:
		ld (hl), $03					; screen_type_scroll = 3
scroll_screen_goto_05:
		inc sp
		ret

.ends