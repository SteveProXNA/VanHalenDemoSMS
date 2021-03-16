.ORG $0099
.section "OUT128 section" force

OUTI128:	
.rept 64
		outi
.endr
.ends


.ORG $0119
.section "OUT64 section" force
OUTI64:	
		.rept 32
		outi
.endr
.ends


.ORG $0159
.section "OUT32 section" force
OUTI32:	
		.rept 32
		outi
.endr
		ret
	
.rept 102
	nop
.endr	
.ends