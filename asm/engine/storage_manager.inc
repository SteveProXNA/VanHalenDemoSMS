.section "Storage manager" free
engine_storage_manager_availabl:
		call devkit_SMS_SRAM
		push hl
		call devkit_SMS_enableSRAM
		pop hl
		ld c, (hl)
		inc hl
		ld b, (hl)
		inc hl
		ld e, (hl)
		inc hl
		ld d, (hl)
		ld a, c
		sub a, $04		; MAGIC			0xACE0B004
		jr nz, storage_goto_01
		ld a, b
		sub a, $B0		; MAGIC			0xACE0B004
		jr nz, storage_goto_01
		ld a, e
		sub a, $E0		; MAGIC			0xACE0B004
		jr nz, storage_goto_01
		ld a, d
		sub a, $AC		; MAGIC			0xACE0B004
		jr nz, storage_goto_01
		ld a, $01
		jr storage_goto_02
storage_goto_01:
		xor a
storage_goto_02:
		ld l, a
		push hl
		call devkit_SMS_disableSRAM
		pop hl
		ret

engine_storage_manager_read:
		call devkit_SMS_SRAM
		push hl
		call devkit_SMS_enableSRAM
		pop iy
		ld c, (iy + $04)
		ld hl, record_album_index		; record_album_index = $C02A		; ro->record_album_index
		ld (hl), c
		jp devkit_SMS_disableSRAM

engine_storage_manager_write:
		call devkit_SMS_SRAM
		push hl
		call devkit_SMS_enableSRAM
		pop bc
		ld l, c
		ld h, b
		ld (hl), $04		; MAGIC			0xACE0B004
		inc hl
		ld (hl), $B0		; MAGIC			0xACE0B004
		inc hl
		ld (hl), $E0		; MAGIC			0xACE0B004
		inc hl
		ld (hl), $AC		; MAGIC			0xACE0B004
		ld hl, $0004
		add hl, bc
		ex de, hl
		ld a, (record_album_index)		; record_album_index = $C02A	; ro->record_album_index
		ld (de), a
		ld hl, $0005
		add hl, bc
		ld (hl), $FE					; savegame->terminal = FINAL;
		jp devkit_SMS_disableSRAM

engine_storage_manager_erase:
		call devkit_SMS_SRAM
		push hl
		call devkit_SMS_enableSRAM
		pop bc
		ld l, c
		ld h, b
		xor a							; savegame->Magic = 0x00000000;
		ld (hl), a
		inc hl
		ld (hl), a
		inc hl
		xor a							; savegame->save_album_index = 0;
		ld (hl), a
		inc hl
		ld (hl), a
		ld hl, $0004
		add hl, bc
		ld (hl), $00
		ld hl, $0005
		add hl, bc
		ld (hl), $FE					; FINAL		0xFE
		jp devkit_SMS_disableSRAM

.ends