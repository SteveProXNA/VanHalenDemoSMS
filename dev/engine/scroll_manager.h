#ifndef _SCROLL_MANAGER_H_
#define _SCROLL_MANAGER_H_

#include "..\object\scroll_object.h"

// Global variable.
extern struct_scroll_object global_scroll_object;

void engine_scroll_manager_reset();
void engine_scroll_manager_load( unsigned char offset );

#endif//_SCROLL_MANAGER_H_
