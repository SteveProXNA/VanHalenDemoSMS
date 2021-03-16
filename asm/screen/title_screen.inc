.section "Title screen" free
screen_title_screen_load:
		call devkit_SMS_displayOff
		call engine_content_manager_load_til
		call engine_content_manager_load_spr
		call engine_content_manager_load_tit
		ld hl, $150A					; engine_font_manager_draw_text( ..., 10, 21 );
		push hl
		ld hl, press_start				; engine_font_manager_draw_text( LOCALE_PRESS_START
		push hl
		call engine_font_manager_draw_text
		pop af
		ld hl, $0C06					; engine_font_manager_draw_text( ..., 6, 12 );
		ex (sp), hl
		ld hl, title_record_label		; engine_font_manager_draw_text( LOCALE_RECORD_TEXT
		push hl
		call engine_font_manager_draw_text
		pop af
		ld hl, $0C14					; engine_font_manager_draw_text( ..., 20, 12 );
		ex (sp), hl
		ld hl, title_covers_label		; engine_font_manager_draw_text( LOCALE_COVERS_TEXT
		push hl
		call engine_font_manager_draw_text
		pop af
		ld hl, $171C					; engine_font_manager_draw_text( ..., 28, 23 );
		ex (sp), hl
		ld hl, title_build_label		; engine_font_manager_draw_text( LOCALE_BUILD_VALUE
		push hl
		call engine_font_manager_draw_text
		pop af
		pop af
		call devkit_SMS_displayOn
		ld hl, $0032		; TITLE_FLASH_DELAY	50
		push hl
		call engine_delay_manager_load
		ld hl, $004B		; TITLE_VALUE_RESET	75
		ex (sp), hl
		call engine_reset_manager_load
		pop af
		xor a
		push af
		inc sp
		call engine_record_manager_init
		inc sp
		call engine_storage_manager_availabl
		ld a, l
		or a
		jr z, title_screen_goto_01
		call engine_storage_manager_read
title_screen_goto_01:
		ld hl, record_album_index		; record_album_index = $C02A		; ro->record_album_index
		ld b, (hl)
		push bc
		inc sp
		call engine_record_manager_init
		inc sp
		ld hl, record_album_index		; record_album_index = $C02A		; ro->record_album_index
		ld b, (hl)
		push bc
		inc sp
		call engine_cursor_manager_init
		inc sp
		ld hl, title_screen_event		; title_screen_event = $C054
		ld (hl), $00					; event_stage_start = 0
		ld hl, title_screen_flash		; title_screen_flash = $C055
		ld (hl), $00					; flash = 0;
		ret

press_start:
	; "PRESS START"
	.db $50 $52 $45 $53 $53 $20 $53 $54 $41 $52 $54 $00

title_record_label:
	; "RECORD"
	.db $52 $45 $43 $4F $52 $44 $00

title_covers_label:
	; "COVERS"
	.db $43 $4F $56 $45 $52 $53 $00

title_build_label:
	; "V1.0"
	.db $56 $31 $2E $30 $00

screen_title_screen_update:
		push ix
		ld ix, $0000
		add ix, sp
		push af
		dec sp
		ld a, (ix + $04)
		ld (ix - 2), a
		ld a, (ix + $05)
		ld (ix - 1), a
		ld a, (title_screen_event)		; title_screen_event = $C054
		dec a
		jr nz, title_screen_goto_05
		call engine_reset_manager_update
		ld c, l
		ld a, c
		or a
		jr z, title_screen_goto_02
		push bc
		ld hl, $150A					; engine_font_manager_draw_text( ..., 10, 21 );
		push hl
		ld hl, blank_clear				; engine_font_manager_draw_text( LOCALE_BLANK_CLEAR
		push hl
		call engine_font_manager_draw_text
		pop af
		ld hl, $1715					; engine_font_manager_draw_text( ..., 21, 23 );
		ex (sp), hl
		ld hl, blank_clear				; engine_font_manager_draw_text( LOCALE_BLANK_CLEAR
		push hl
		call engine_font_manager_draw_text
		pop af
		pop af
		pop bc
title_screen_goto_02:
		ld a, c
		or a
		jr z, title_screen_goto_03
		ld c, $03						; screen_type_scroll = 3
		jr title_screen_goto_04
title_screen_goto_03:
		ld c, $02						; screen_type_title = 2
title_screen_goto_04:
		ld l, (ix - 2)
		ld h, (ix - 1)
		ld (hl), c
		jr title_screen_goto_08
title_screen_goto_05:
		call engine_delay_manager_update
		ld (ix - 3), l
		ld a, l
		or a
		jr z, title_screen_goto_07
		ld hl, title_screen_flash		; title_screen_flash = $C055
		ld a, $01
		sub a, (hl)
		ld (hl), a
		ld a,(title_screen_flash)		; title_screen_flash = $C055
		or a
		jr z, title_screen_goto_06
		ld hl, $150A					; engine_font_manager_draw_text( ..., 10, 21 );
		push hl
		ld hl, blank_clear				; engine_font_manager_draw_text( LOCALE_BLANK_CLEAR
		push hl
		call engine_font_manager_draw_text
		pop af
		pop af
		jr title_screen_goto_07
title_screen_goto_06:
		ld hl, $150A					; engine_font_manager_draw_text( ..., 10, 21 );
		push hl
		ld hl, press_start2				; engine_font_manager_draw_text( LOCALE_PRESS_START
		push hl
		call engine_font_manager_draw_text
		pop af
		pop af
title_screen_goto_07:
		ld a, $10						; input_type_fire1
		push af
		inc sp
		call engine_input_manager_hold
		inc sp
		ld a, l
		or a
		jr z, $15
		ld hl, $150A					; engine_font_manager_draw_text( ..., 10, 21 );
		push hl
		ld hl, press_start2				; engine_font_manager_draw_text( LOCALE_PRESS_START
		push hl
		call engine_font_manager_draw_text
		pop af
		pop af
		call engine_audio_manager_sfx_right
		ld hl, title_screen_event		; title_screen_event = $C054
		ld (hl), $01
		ld l, (ix - 2)
		ld h, (ix - 1)
		ld (hl), $02					; screen_type_title = 2
title_screen_goto_08:
		ld sp, ix
		pop ix
		ret

blank_clear:
	; "           "
	.dsb 11, $20
	.db $00

press_start2:
	; "PRESS START"
	.db $50 $52 $45 $53 $53 $20 $53 $54 $41 $52 $54 $00

.ends