.enum $C000 export	
pause_status db		                ; Lmain.main$global_pause$1$55 = $C000
PSGMusicStatus db                   ; PSGMusicStatus = $C001
PSGMusicStart dw                    ; PSGMusicStart = $C002
PSGMusicPointer dw		            ; PSGMusicPointer = $C004
PSGMusicLoopPoint dw		        ; PSGMusicLoopPoint = $C006
PSGMusicSkipFrames db		        ;  PSGMusicSkipFrames = $C008
PSGLoopFlag db		                ; PSGLoopFlag = $C009
PSGMusicLastLatch db		        ; PSGMusicLastLatch = $C00A
PSGMusicVolumeAttenuation db		; PSGMusicVolumeAttenuation = $C00B
PSGMusicSubstringLen db		        ; PSGMusicSubstringLen = $C00C
PSGMusicSubstringRetAddr dw		    ; PSGMusicSubstringRetAddr = $C00D
PSGChan0Volume db		            ; PSGChan0Volume = $C00F
PSGChan1Volume db		            ; PSGChan1Volume = $C010
PSGChan2Volume db		            ; PSGChan2Volume = $C011
PSGChan3Volume db		            ; PSGChan3Volume = $C012
PSGChan2LowTone db		            ; PSGChan2LowTone = $C013
PSGChan2HighTone db		            ; PSGChan2HighTone = $C014
PSGChan3LowTone db		            ; PSGChan3LowTone = $C015
PSGChannel2SFX db		            ; PSGChannel2SFX = $C016
PSGChannel3SFX db		            ; PSGChannel3SFX = $C017
PSGSFXChan2Volume db		        ; PSGSFXChan2Volume = $C018
PSGSFXChan3Volume db		        ; PSGSFXChan3Volume = $C019
PSGSFXStatus db		                ; PSGSFXStatus = $C01A
PSGSFXStart dw		                ; PSGSFXStart = $C01B
PSGSFXPointer dw		            ; PSGSFXPointer = $C01D
PSGSFXLoopPoint dw		            ; PSGSFXLoopPoint = $C01F
PSGSFXSkipFrames db		            ; PSGSFXSkipFrames = $C021
PSGSFXLoopFlag db		            ; PSGSFXLoopFlag = $C022
PSGSFXSubstringLen db		        ; PSGSFXSubstringLen = $C023
PSGSFXSubstringRetAddr dw		    ; PSGSFXSubstringRetAddr = $C024
.ende	


.enum $C026 export		
cursor_index_x db                   ; cursor_index_x = $C026
cursor_index_y db                   ; cursor_index_x = $C027
cursor_value_x db                   ; cursor_index_x = $C028
cursor_value_y db                   ; cursor_index_x = $C029
.ende	


.enum $C02A export	
record_album_index db	            ; ro->record_album_index = $C02A
.ende	

.enum $C02B export	
curr_screen_type db	    ; Fscreen_manager$curr_screen_type = $C02B      ; TODO update
next_screen_type db	    ; Fscreen_manager$next_screen_type = $C02C
load_type_none dw	    ; _RAM_C02D_ = $C02D
load_type_splash dw	    ; _RAM_C02F_ = $C02F
load_type_title dw	    ; _RAM_C031_ = $C031
load_type_scroll dw	    ; _RAM_C033_ = $C033
load_type_select dw	    ; _RAM_C035_ = $C035
load_type_record dw	    ; _RAM_C037_ = $C037
update_type_none dw	    ; _RAM_C039_ = $C039
update_type_splash dw   ; _RAM_C03B_ = $C03B
update_type_title dw	; _RAM_C03D_ = $C03D
update_type_scroll dw	; _RAM_C03F_ = $C03F
update_type_select dw   ; _RAM_C041_ = $C041
update_type_record dw	; _RAM_C043_ = $C043
;G$global_scroll_object$0$0 db	        ; G$global_scroll_object$0$0 = $C045
scroll_object db	        ; G$global_scroll_object$0$0 = $C045
.ende	


.enum $C04C export	
delay_object_value dw                   ; delay_object_value = $C04C
delay_object_timer dw                   ; delay_object_timer = $C04E
reset_object_value dw                   ; reset_object_value = $C050
reset_object_timer dw                   ; reset_object_timer = $C052
.ende	


.enum $C054 export	
title_screen_event db                 ; title_screen_event = $C054
title_screen_flash db                 ; title_screen_flash = $C055
scroll_screen_offset db                 ; scroll_screen_offset = $C056
select_screen_event db                  ; select_screen_event = $C057
select_screen_flash db                  ; select_screen_event = $C058
.ende	


	
.enum $C05B export	
VDPBlank db		                        ; VDPBlank = $C05B
SMS_VDPFlags db		                    ; SMS_VDPFlags = $C05C
PauseRequested db		                ; PauseRequested = $C05D
VDPType db		                        ; VDPType = $C05E
KeysStatus dw		                    ; KeysStatus = $C05F
PreviousKeysStatus dw		            ; PreviousKeysStatus = $C061
SpriteTableY db		                    ; SpriteTableY = $C063
.ende	
	
.enum $C0A3 export	
SpriteTableXN db	                    ; SpriteTableXN = $C0A3
.ende	
	
.enum $C123 export	
SpriteNextFree db		                ; SpriteNextFree = $C123
SMS_theLineInterruptHandler dw		    ; SMS_theLineInterruptHandler = $C124
decompBuffer db		                    ; decompBuffer = $C126
	
.ende	
	
    
.enum $C14A export	
cursor_album db                         ; cursor_album = $C14A
.ende	
	
.enum $C146 export	
curr_joypad1 dw		; Finput_manager$curr_joypad1$0$0 = $C146       ; todo update
prev_joypad1 dw		; Finput_manager$prev_joypad1$0$0 = $C148       ; todo update
.ende	

.enum $C162 export	
record_tiles_data db		            ; record_tiles_data = $C162
.ende	
.enum $C17A export	
record_tilemap_data db                  ; record_tilemap_data = $C17A	
.ende
.enum $C192 export	
record_palette_data db                  ; record_palette_data = $C192	
.ende

.enum $C1AA export	
VDPReg db                               ; VDPReg = $C1AA
.ende

.enum $C1AC export	
spritesHeight db		                ; spritesHeight = $C1AC
spritesWidth db		                    ; spritesWidth = $C1AD
.ende	


.enum $FFFC export	
_RAM_FFFC_ db	
.ende	