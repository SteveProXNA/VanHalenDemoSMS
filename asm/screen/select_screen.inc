.section "Select screen" free
screen_select_screen_load:
		ld a, (scroll_object)			; scroll_object = $C045	; so->scroll_value_offset
		or a
		jr nz, select_screen_goto_01
		call devkit_SMS_displayOff
		call engine_asm_manager_clear_VRAM
		call engine_content_manager_load_til
		call fngine_content_manager_load_tit
		call engine_content_manager_load_spr
		ld hl, $0806	; x = $06	y = $08
		push hl
		ld hl, select_record_label
		push hl
		call engine_font_manager_draw_text
		pop af
		ld hl, $0814	; x = $08	y = $14 (20)
		ex (sp), hl
		ld hl, select_covers_label
		push hl
		call engine_font_manager_draw_text
		pop af
		pop af
		call devkit_SMS_displayOn
select_screen_goto_01:
		ld hl, scroll_object			; so->scroll_value_offset	; $C045
		ld b, (hl)
		push bc
		inc sp
		call engine_cursor_manager_load
		inc sp
		ld hl, $000F		; SELECT_FLASH_DELAY	15
		push hl
		call engine_delay_manager_load
		ld hl, $004B		; SELECT_VALUE_RESET	75
		ex (sp), hl
		call engine_reset_manager_load
		pop af
		ld hl, select_screen_event		; static unsigned char event_stage	; select_screen_event = $C057
		ld (hl), $00
		ld hl, select_screen_flash		; static unsigned char flash	; select_screen_flash = $C058
		ld (hl), $01
		ret

select_record_label:
	; "RECORD"
	.db $52 $45 $43 $4F $52 $44 $00

select_covers_label:
	; "COVERS"
	.db $43 $4F $56 $45 $52 $53 $00

screen_select_screen_update:
		ld a, (select_screen_event)		; static unsigned char event_stage	; $C057
		dec a
		jr nz, select_screen_goto_06
		ld a, (select_screen_flash)		; static unsigned char flash		; $C058
		or a
		jr z, select_screen_goto_02
		call engine_cursor_manager_draw
select_screen_goto_02:
		call engine_delay_manager_update
		ld a, l
		or a
		jr z, select_screen_goto_03
		ld hl, select_screen_flash		; static unsigned char flash	; select_screen_flash = $C058
		ld a, $01						; flash = 1;
		sub a, (hl)
		ld (hl), a
select_screen_goto_03:
		call engine_reset_manager_update
		pop de
		pop bc
		push bc
		push de
		ld a, l
		or a
		jr z, select_screen_goto_04
		ld a, $05		; screen_type_record	5
		jr select_screen_goto_05
select_screen_goto_04:
		ld a, $04		; screen_type_select	4
select_screen_goto_05:
		ld (bc), a
		ret

select_screen_goto_06:
		call engine_cursor_manager_draw
		ld a, $10		; input_type_fire1
		push af
		inc sp
		call engine_input_manager_hold
		inc sp
		ld a, l
		or a
		jr z, select_screen_goto_07
		call engine_cursor_manager_save
		ld b, l
		push bc
		inc sp
		call engine_record_manager_init
		inc sp
		call engine_audio_manager_sfx_right
		ld hl, select_screen_event 		; static unsigned char event_stage	; select_screen_event = $C057
		ld (hl), $01
		ret
select_screen_goto_07:
		ld a, $04		; input_type_left
		push af
		inc sp
		call engine_input_manager_hold
		inc sp
		ld a, l
		or a
		jr z, select_screen_goto_08
		call engine_cursor_manager_decX
select_screen_goto_08:
		ld a, $08		; input_type_right
		push af
		inc sp
		call engine_input_manager_hold
		inc sp
		ld a, l
		or a
		jr z, select_screen_goto_09
		call engine_cursor_manager_incX
select_screen_goto_09:
		ld a, $01		; input_type_up
		push af
		inc sp
		call engine_input_manager_hold
		inc sp
		ld a, l
		or a
		jr z, select_screen_goto_10
		call engine_cursor_manager_decY
select_screen_goto_10:
		ld a, $02		; input_type_down
		push af
		inc sp
		call engine_input_manager_hold
		inc sp
		ld a, l
		or a
		jr z, select_screen_goto_11
		call engine_cursor_manager_incY
select_screen_goto_11:
		pop bc
		pop hl
		push hl
		push bc
		ld (hl), $04		; screen_type_select	4
		ret

.ends