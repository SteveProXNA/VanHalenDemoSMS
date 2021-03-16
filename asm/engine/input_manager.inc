.section "Input manager" free
engine_input_manager_update:
		ld hl, (curr_joypad1)		; Finput_manager$curr_joypad1$0$0 = curr_joypad1
		ld (prev_joypad1), hl		; Finput_manager$prev_joypad1$0$0 = prev_joypad1
		call devkit_SMS_getKeysStatus
		ld (curr_joypad1), hl		; Finput_manager$curr_joypad1$0$0 = curr_joypad1
		ret

engine_input_manager_hold:
		ld hl, $0002
		add hl, sp
		ld c, (hl)
		ld b, $00
		ld iy, curr_joypad1
		ld a, (iy + $00)
		and c
		ld e, a
		ld a, (iy + $01)
		and b
		or e
		jr z, input_goto_01
		ld a, c
		ld iy, prev_joypad1
		and (iy + $00)
		ld c, a
		ld a, b
		and (iy + $01)
		or c
		jr z, input_goto_02
input_goto_01:
		ld l, $00
		ret
input_goto_02:
		ld l, $01
		ret

engine_input_manager_move:
		ld hl, $0002
		add hl, sp
		ld c, (hl)
		ld a, (curr_joypad1)
		and c
		ld l, a
		ret

.ends