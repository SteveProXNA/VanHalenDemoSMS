#include "record_manager.h"
#include "..\devkit\_sms_manager.h"
#include "..\engine\global_manager.h"
#include "..\object\record_object.h"

#define RECORD_TILES	0

// Global variable.
struct_record_object global_record_object;


void engine_record_manager_init( unsigned char index )
{
	struct_record_object *ro = &global_record_object;
	ro->record_album_index = index;
}
void engine_record_manager_load()
{
	struct_record_object *ro = &global_record_object;
	unsigned char index = ro->record_album_index;

	const unsigned char *tiles = ( const unsigned char * ) record_tiles_data[ index ];
	const unsigned char *tilemap = ( const unsigned char * ) record_tilemap_data[ index ];
	const unsigned char bank = ( const unsigned char ) record_tiles_bank[ index ];

	devkit_SMS_mapROMBank( bank );
	devkit_SMS_loadPSGaidencompressedTiles( tiles, RECORD_TILES );
	devkit_SMS_loadSTMcompressedTileMap( 0, 0, ( void * ) tilemap );

	// Not too sure why this works but it works!
	devkit_SMS_loadBGPalette( ( void * ) record_palette_data[ 0 ] );
}

void engine_record_manager_decrement()
{
	struct_record_object *ro = &global_record_object;
	if( 0 == ro->record_album_index )
	{
		ro->record_album_index = MAX_RECORDS - 1;
	}
	else
	{
		ro->record_album_index --;
	}
}
void engine_record_manager_increment()
{
	struct_record_object *ro = &global_record_object;
	if( ( MAX_RECORDS - 1 ) == ro->record_album_index )
	{
		ro->record_album_index = 0;
	}
	else
	{
		ro->record_album_index++;
	}
}