#ifndef _CURSOR_MANAGER_H_
#define _CURSOR_MANAGER_H_

#include "..\object\cursor_object.h"

// Global variable.
extern struct_cursor_object global_cursor_object;

void engine_cursor_manager_init( unsigned char index );
void engine_cursor_manager_load( unsigned char offset );
unsigned char engine_cursor_manager_save();
void engine_cursor_manager_draw();

void engine_cursor_manager_decX();
void engine_cursor_manager_incX();
void engine_cursor_manager_decY();
void engine_cursor_manager_incY();

#endif//_CURSOR_MANAGER_H_