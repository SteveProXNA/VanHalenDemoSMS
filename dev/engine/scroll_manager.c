#include "scroll_manager.h"
#include "global_manager.h"
#include "..\devkit\_sms_manager.h"

// Global variable.
struct_scroll_object global_scroll_object;

void engine_scroll_manager_reset()
{
	engine_scroll_manager_load( GAP_OFFSET );
	devkit_SMS_setBGScrollY( GAP_OFFSET );
}

void engine_scroll_manager_load( unsigned char offset )
{
	struct_scroll_object *so = &global_scroll_object;
	so->scroll_value_offset = offset;
}