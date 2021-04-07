#include "record_screen.h"
#include "..\engine\asm_manager.h"
#include "..\engine\cursor_manager.h"
#include "..\engine\enum_manager.h"
#include "..\engine\font_manager.h"
#include "..\engine\hack_manager.h"
#include "..\engine\input_manager.h"
#include "..\engine\record_manager.h"
#include "..\engine\riff_manager.h"
#include "..\engine\storage_manager.h"
#include "..\engine\scroll_manager.h"
#include "..\engine\timer_manager.h"
#include "..\devkit\_sms_manager.h"

static void load_record();
static void play_riff();

void screen_record_screen_load()
{
	engine_scroll_manager_reset();
	load_record();
}

void screen_record_screen_update( unsigned char *screen_type )
{
	struct_record_object *ro = &global_record_object;
	unsigned char input1;
	unsigned char input2;

	input1 = engine_input_manager_hold( input_type_left );
	if( input1 )
	{
		engine_record_manager_decrement();
		load_record();
	}
	input1 = engine_input_manager_hold( input_type_right );
	if( input1 )
	{
		engine_record_manager_increment();
		load_record();
	}

	input1 = engine_input_manager_hold( input_type_fire1 );
	if( input1 )
	{
		play_riff();
	}

	input2 = engine_input_manager_hold( input_type_fire2 );
	if( input2 )
	{
		devkit_SMS_setBGScrollY( GAP_OFFSET );

		engine_record_manager_init( ro->record_album_index );
		engine_cursor_manager_init( ro->record_album_index );
		engine_storage_manager_write();

		*screen_type = screen_type_select;
		return;
	}

	*screen_type = screen_type_record;
}

static void load_record()
{
	struct_hack_object *ho = &global_hack_object;

	devkit_SMS_displayOff();
	engine_asm_manager_clear_VRAM();
	engine_record_manager_load();
	devkit_SMS_displayOn();

	if( ho->hack_object_sound_play )
	{
		play_riff();
	}
}

static void play_riff()
{
	struct_record_object *ro = &global_record_object;
	engine_riff_manager_play( ro->record_album_index );
}
