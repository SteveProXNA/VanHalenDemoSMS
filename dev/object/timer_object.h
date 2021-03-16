#ifndef _TIMER_OBJECT_H_
#define _TIMER_OBJECT_H_

// Delay Object.
typedef struct tag_struct_delay_object
{
	unsigned int delay_value;
	unsigned int delay_timer;

} struct_delay_object;


// Reset Object.
typedef struct tag_struct_reset_object
{
	unsigned int reset_value;
	unsigned int reset_timer;

} struct_reset_object;

#endif//_TIMER_OBJECT_H_