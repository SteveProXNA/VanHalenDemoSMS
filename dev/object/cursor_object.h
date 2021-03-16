#ifndef __CURSORT_OBJECT_H__
#define __CURSORT_OBJECT_H__

#include "..\engine\global_manager.h"

extern const char *cursor_album[ MAX_ALBUMS ];
extern const unsigned char cursor_gridX[ MAX_GRID_X ];
extern const unsigned char cursor_gridY[ MAX_GRID_Y ];

typedef struct tag_struct_cursor_object
{
	unsigned char cursor_index_x;
	unsigned char cursor_index_y;
	unsigned char cursor_value_x;
	unsigned char cursor_value_y;

} struct_cursor_object;

#endif//__CURSORT_OBJECT_H__