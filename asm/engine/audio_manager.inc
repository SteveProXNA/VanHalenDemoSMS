.section "Audio manager" free
engine_audio_manager_sfx_right:
		ld hl, sfx_right_psg
		push hl
		call play_sfx
		pop af
		ret

engine_audio_manager_sfx_wrong:
		ld hl, sfx_wrong_psg
		push hl
		call play_sfx
		pop af
		ret

engine_audio_manager_sfx_cheat:
		ld hl, sfx_cheat_psg
		push hl
		call play_sfx
		pop af
		ret

 play_sfx:
		call devkit_PSGSFXGetStatus
		ld a, l
		or a
		ret nz
		call devkit_SFX_CHANNEL2
		ld h, l
		pop de
		pop bc
		push bc
		push de
		push hl
		inc sp
		push bc
		call devkit_PSGSFXPlay
		pop af
		inc sp
		ret

.ends