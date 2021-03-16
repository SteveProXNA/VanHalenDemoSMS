#include "timer_manager.h"

// Global variables.
struct_delay_object global_delay_object;
struct_reset_object global_reset_object;


// Delay Manager.
void engine_delay_manager_load( unsigned int delay )
{
	struct_delay_object *dObj = &global_delay_object;
	dObj->delay_value = delay;
	dObj->delay_timer = 0;
}
unsigned char engine_delay_manager_update()
{
	struct_delay_object *dObj = &global_delay_object;
	unsigned char test;

	dObj->delay_timer++;
	test = dObj->delay_timer >= dObj->delay_value;
	if( test )
	{
		dObj->delay_timer = 0;
	}

	return test;
}


// Reset Manager.
void engine_reset_manager_load( unsigned int delay )
{
	struct_reset_object *ro = &global_reset_object;
	ro->reset_value = delay;
	engine_reset_manager_reset();
}
unsigned char engine_reset_manager_update()
{
	struct_reset_object *ro = &global_reset_object;
	unsigned char test;

	ro->reset_timer++;
	test = ro->reset_timer >= ro->reset_value;
	if( test )
	{
		ro->reset_timer = 0;
	}

	return test;
}
void engine_reset_manager_reset()
{
	struct_reset_object *ro = &global_reset_object;
	ro->reset_timer = 0;
}