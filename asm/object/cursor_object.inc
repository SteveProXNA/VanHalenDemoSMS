;.section "Cursor object" free
; const unsigned char cursor_gridX[ MAX_GRID_X ] = { 4, 11, 18, 25 };
cursor_gridX:
	.db $04 $0B $12 $19

; const unsigned char cursor_gridY[ MAX_GRID_Y ] = { 16, 19, 22 };
cursor_gridY:
	.db $10 $13 $16

; "1978"
	.db $31 $39 $37 $38 $00

; "1978"
	.db $31 $39 $37 $39 $00

; "1980"
	.db $31 $39 $38 $30 $00

; "1981"
	.db $31 $39 $38 $31 $00

; "1982"
	.db $31 $39 $38 $32 $00

; "1984"
	.db $31 $39 $38 $34 $00

; "1986"
	.db $31 $39 $38 $36 $00

; "1988"
	.db $31 $39 $38 $38 $00

; "1991"
	.db $31 $39 $39 $31 $00

; "1995"
	.db $31 $39 $39 $35 $00

; "1995"
	.db $31 $39 $39 $38 $00

; "2012"
	.db $32 $30 $31 $32 $00

;.ends