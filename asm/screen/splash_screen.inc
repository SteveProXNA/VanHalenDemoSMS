.section "Splash screen" free
screen_splash_screen_load:
		call devkit_SMS_displayOff				; $082B
		call engine_content_manager_load_til	; $0AA2
		call engine_content_manager_load_spl	; $0AB8
		call devkit_SMS_displayOn				; $0825
		ld hl, $0096							; SPLASH_SCREEN_DELAY	150
		push hl
		call engine_delay_manager_load			; $10CD
		ld hl, $004B							; DELETE_SCREEN_DELAY	75
		ex (sp), hl
		call engine_reset_manager_load			; $1108
		pop af
		ret

screen_splash_screen_update:
		push ix
		ld ix, $0000
		add ix, sp
		push af
		call engine_delay_manager_update		; $10E6
		ld (ix - 2), l
		ld a, $10								; input_type_fire1	16
		push af
		inc sp
		call engine_input_manager_hold
		inc sp
		ld (ix - 1), l
		ld a, $20								; input_type_fire2	32
		push af
		inc sp
		call engine_input_manager_move			; $0F00
		inc sp
		ld a, l
		or a
		jr z, splash_screen_goto_01
		call engine_reset_manager_update		; $111D
		ld a, l
		or a
		jr z, splash_screen_goto_02
		call engine_storage_manager_erase		; $10AB
		call engine_reset_manager_reset			; $113F
		ld hl, $171C							; ; 17 = 23	1C = 28
		push hl
		ld hl, fiftyonefifty					; $121B
		push hl
		call engine_font_manager_draw_text		; $0DE9
		pop af
		pop af
		jr splash_screen_goto_02
splash_screen_goto_01:
		call engine_reset_manager_reset			; $113F
splash_screen_goto_02:
		ld l, (ix + $04)
		ld h, (ix + $05)
		ld a, (ix - 2)
		or a
		jr nz, splash_screen_goto_03
		ld a, (ix - 1)
		or a
		jr z, splash_screen_goto_04
splash_screen_goto_03:
		ld (hl), $02							; screen_type
		jr splash_screen_goto_05
splash_screen_goto_04:
		ld (hl), $01							; screen_type_splash
splash_screen_goto_05:
		ld sp, ix
		pop ix
		ret

; "5150"
fiftyonefifty:
	.db $35 $31 $35 $30 $00

.ends