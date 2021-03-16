;==============================================================
; WLA-DX banking setup
;==============================================================
.MEMORYMAP	
SLOTSIZE $7FF0	
SLOT 0 $0000	
SLOTSIZE $10	
SLOT 1 $7FF0	
SLOTSIZE $4000	
SLOT 2 $8000	
SLOT 3 $C000	
DEFAULTSLOT 2	
.ENDME	
.ROMBANKMAP	
BANKSTOTAL 16	
BANKSIZE $7FF0	
BANKS 1	
BANKSIZE $10	
BANKS 1	
BANKSIZE $4000	
BANKS 14	
.ENDRO	