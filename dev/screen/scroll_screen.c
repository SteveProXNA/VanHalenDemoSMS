#include "scroll_screen.h"
#include "..\engine\asm_manager.h"
#include "..\engine\content_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\global_manager.h"
#include "..\engine\input_manager.h"
#include "..\engine\locale_manager.h"
#include "..\engine\scroll_manager.h"
#include "..\devkit\_sms_manager.h"

static unsigned char offset;

void screen_scroll_screen_load()
{
	offset = 0;
}

void screen_scroll_screen_update( unsigned char *screen_type )
{
	unsigned char input;
	unsigned char value;

	value = TOP_SCROLL == offset;
	devkit_SMS_setBGScrollY( offset++ );

	input = engine_input_manager_hold( input_type_fire1 );
	if( input || value )
	{
		engine_scroll_manager_load( TOP_OFFSET );
		devkit_SMS_setBGScrollY( TOP_SCROLL );

		*screen_type = screen_type_select;
		return;
	}

	*screen_type = screen_type_scroll;
}
