.section "Record screen" free
screen_record_screen_load:
		call engine_scroll_manager_reset
		jp load_record

screen_record_screen_update:
		push ix
		ld ix, $0000
		add ix, sp
		ld a, $04			; input_type_left
		push af
		inc sp
		call engine_input_manager_hold
		inc sp
		ld a, l
		or a
		jr z, record_screen_goto_01
		call engine_record_manager_decrement
		call load_record
record_screen_goto_01:
		ld a, $08			; input_type_right
		push af
		inc sp
		call engine_input_manager_hold
		inc sp
		ld a, l
		or a
		jr z, record_screen_goto_02
		call engine_record_manager_increment
		call load_record
record_screen_goto_02:
		ld a, $10		; input_type_fire2
		push af
		inc sp
		call engine_input_manager_hold
		inc sp
		ld c, l
		push bc
		ld a, $20		; input_type_fire2
		push af
		inc sp
		call engine_input_manager_hold
		inc sp
		pop bc
		ld e, (ix + $04)
		ld d, (ix + $05)
		ld a, c
		or a
		jr nz, record_screen_goto_03
		or l
		jr z, record_screen_goto_04
record_screen_goto_03:
		push de
		xor a
		push af
		inc sp
		call devkit_SMS_setBGScrollY
		inc sp
		pop de
		ld hl, record_album_index		; ro->record_album_index	; record_album_index = $C02A
		ld b, (hl)
		push de
		push bc
		inc sp
		call engine_record_manager_init
		inc sp
		pop de
		ld hl, record_album_index		; ro->record_album_index	; record_album_index = $C02A
		ld b, (hl)
		push de
		push bc
		inc sp
		call engine_cursor_manager_init
		inc sp
		call engine_storage_manager_write
		pop de
		ld a, $04
		ld (de), a
		jr record_screen_goto_05
record_screen_goto_04:
		ld a, $05						; screen_type_record = 5
		ld (de), a
record_screen_goto_05:
		pop ix
		ret

; static void load_record()
load_record:
		call devkit_SMS_displayOff
		call engine_asm_manager_clear_VRAM
		call engine_record_manager_load
		jp devkit_SMS_displayOn

.ends