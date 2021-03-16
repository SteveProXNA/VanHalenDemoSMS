#ifndef _RECORD_MANAGER_H_
#define _RECORD_MANAGER_H_

#include "..\object\record_object.h"

// Global variable.
extern struct_record_object global_record_object;

void engine_record_manager_init( unsigned char index );
void engine_record_manager_load();

void engine_record_manager_decrement();
void engine_record_manager_increment();

#endif//_RECORD_MANAGER_H_
