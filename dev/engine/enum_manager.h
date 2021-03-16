#ifndef _ENUM_MANAGER_H_
#define _ENUM_MANAGER_H_

typedef enum tag_enum_screen_type
{
	screen_type_none = 0,
	screen_type_splash = 1,
	screen_type_title = 2,
	screen_type_scroll = 3,
	screen_type_select = 4,
	screen_type_record = 5,

} enum_screen_type;

typedef enum tag_enum_direction_type
{
	direction_type_none = 0x00,
	direction_type_upxx = 0x01,
	direction_type_down = 0x02,
	direction_type_left = 0x04,
	direction_type_rght = 0x08,

} enum_direction_type;

typedef enum tag_enum_input_type
{
	input_type_up    = 0x01,
	input_type_down  = 0x02,
	input_type_left	 = 0x04,
	input_type_right = 0x08,
	input_type_fire1 = 0x10,
	input_type_fire2 = 0x20,

} enum_input_type;

typedef enum tag_enum_stage_type
{
	event_stage_start = 0,
	event_stage_delay = 1,

} enum_stage_type;

#endif//_ENUM_MANAGER_H_