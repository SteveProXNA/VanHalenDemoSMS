#include "hack_manager.h"

// Global variable.
struct_hack_object global_hack_object;

#define PEEK( addr)			(* ( unsigned char *)( addr ) )
#define POKE( addr, data )	(* ( unsigned char *)( addr ) = ( data ) )

#define HACKER_START		0x0050

// TODO delete this - set only during debugging / play testing
#ifdef _CONSOLE
#else
#pragma disable_warning 110
#pragma disable_warning 126
#endif

void engine_hack_manager_init()
{
	struct_hack_object *ho = &global_hack_object;
	ho->hack_object_sound_play = 0;
}

void engine_hack_manager_load()
{
	struct_hack_object *ho = &global_hack_object;

#ifndef _CONSOLE

	ho->hack_object_sound_play = PEEK( HACKER_START + 0 );			// 0x0050		// Non-zero value disables sound on load.

#endif
}

void engine_hack_manager_invert()
{
	// Invert default values.
	struct_hack_object *ho = &global_hack_object;
	ho->hack_object_sound_play = !ho->hack_object_sound_play;
}