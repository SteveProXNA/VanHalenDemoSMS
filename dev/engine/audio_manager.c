#include "audio_manager.h"
#include "..\devkit\_snd_manager.h"
#include "..\psg.h"

// IMPORTANT disable compiler warning 196
#ifdef _CONSOLE
#else
#pragma disable_warning 196
#endif

#define sfx_right_psg			sfx_right_psg
#define sfx_wrong_psg			sfx_wrong_psg
#define sfx_cheat_psg			sfx_cheat_psg

// Private helper functions.
static void play_sfx( unsigned char *sfx );

void engine_audio_manager_sfx_right()
{
	play_sfx( ( unsigned char* ) sfx_right_psg );
}
void engine_audio_manager_sfx_wrong()
{
	play_sfx( ( unsigned char* ) sfx_wrong_psg );
}
void engine_audio_manager_sfx_cheat()
{
	play_sfx( ( unsigned char* ) sfx_cheat_psg );
}

static void play_sfx( unsigned char *sound )
{
	unsigned char status;

	// If sound effect already playing then return.
	status = devkit_PSGSFXGetStatus();
	if( status )
	{
		return;
	}

	devkit_PSGSFXPlay( sound, devkit_SFX_CHANNEL2() );
}