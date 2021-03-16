.section "Scroll manager" free
engine_scroll_manager_reset:
		xor a						; GAP_OFFSET	0
		push af
		inc sp
		call engine_scroll_manager_load
		inc sp
		xor a
		push af
		inc sp
		call devkit_SMS_setBGScrollY
		inc sp
		ret

engine_scroll_manager_load:
		ld hl, scroll_object		; scroll_object = $C045
		ld iy, $0002
		add iy, sp
		ld a, (iy+0)
		ld (hl), a
		ret

.ends