.section "None screen" free
screen_none_screen_load:
		ret

screen_none_screen_update:
		pop de
		pop bc
		push bc
		push de
		xor a					; screen_type_none = 0
		ld (bc), a
		ret

.ends