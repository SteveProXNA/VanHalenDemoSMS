.section "Record manager" free
engine_record_manager_init:
		ld hl, record_album_index		; record_album_index = $C02A
		ld iy, $0002
		add iy, sp
		ld a, (iy + $00)
		ld (hl), a
		ret

engine_record_manager_load:
		push ix
		ld ix, $0000
		add ix, sp
		dec sp
		ld a, (record_album_index)		; ro->record_album_index
		ld (ix - 1), a
		ld l, a
		ld h, $00
		add hl, hl
		ld c, l
		ld b, h
		ld hl, record_tiles_data		; record_tiles_data = $C162
		add hl, bc
		ld e, (hl)
		inc hl
		ld d, (hl)
		ld hl, record_tilemap_data		; record_tilemap_data = $C17A
		add hl, bc
		ld c, (hl)
		inc hl
		ld b, (hl)
		ld a, (ix - 1)
		add a, $89
		ld l, a
		ld a, $00
		adc a, $11
		ld h, a
		ld h, (hl)
		push bc
		push de
		push hl
		inc sp
		call devkit_SMS_mapROMBank
		inc sp
		pop de
		ld hl, $0000					; RECORD_TILES	0
		push hl
		push de
		call devkit_SMS_loadPSGaidencompress
		pop af
		ld hl, $0000					; devkit_SMS_loadSTMcompressedTileMap( 0, 0
		ex (sp), hl
		call devkit_SMS_loadSTMcompressedTil
		pop af
		pop af
		ld hl, (record_palette_data)	; record_palette_data = $C192
		push hl
		call devkit_SMS_loadBGPalette
		pop af
		inc sp
		pop ix
		ret

engine_record_manager_decrement:
		ld bc, record_album_index		; ro->record_album_index
		ld a, (bc)
		or a							; if( 0 == ro->record_album_index )
		jr nz, record_goto_01
		ld a, $0B
		ld (bc), a						; ro->record_album_index = MAX_RECORDS - 1;
		ret
record_goto_01:
		add a, $FF
		ld (bc), a						; ro->record_album_index--;
		ret

engine_record_manager_increment:
		ld bc, record_album_index	; ro->record_album_index
		ld a, (bc)
		cp $0B						; if( ( MAX_RECORDS - 1 ) == ro->record_album_index )
		jr nz, record_goto_02
		xor a						; ro->record_album_index = 0;
		ld (bc), a
		ret
record_goto_02:
		inc a						; ro->record_album_index++;
		ld (bc), a
		ret

.ends