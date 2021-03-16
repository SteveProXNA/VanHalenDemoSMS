#include "storage_manager.h"
#include "enum_manager.h"
#include "global_manager.h"
#include "record_manager.h"
#include "..\devkit\_sms_manager.h"

#define MAGIC			0xACE0B004
#define FINAL			0xFE

// Global variable.
struct_storage_object global_savegame_object;


// Reference:
// https://www.smspower.org/forums/16013-DevkitSMSSMSlibMissingRequestingFeatures
unsigned char engine_storage_manager_available()
{
	struct_storage_object *savegame = ( struct_storage_object* ) ( devkit_SMS_SRAM() );
	unsigned char foundMagic;

	devkit_SMS_enableSRAM();
	foundMagic = MAGIC == savegame->Magic;
	devkit_SMS_disableSRAM();
	return foundMagic;
}

void engine_storage_manager_read()
{
	struct_storage_object *savegame = ( struct_storage_object* ) ( devkit_SMS_SRAM() );
	struct_record_object *ro = &global_record_object;

	devkit_SMS_enableSRAM();
	ro->record_album_index = savegame->save_album_index;
	devkit_SMS_disableSRAM();
}

void engine_storage_manager_write()
{
	struct_storage_object *savegame = ( struct_storage_object* ) ( devkit_SMS_SRAM() );
	struct_record_object *ro = &global_record_object;

	devkit_SMS_enableSRAM();
	savegame->Magic = MAGIC;
	savegame->save_album_index = ro->record_album_index;
	savegame->terminal = FINAL;
	devkit_SMS_disableSRAM();
}

void engine_storage_manager_erase()
{
	struct_storage_object *savegame = ( struct_storage_object* ) ( devkit_SMS_SRAM() );

	devkit_SMS_enableSRAM();
	savegame->Magic = 0x00000000;
	savegame->save_album_index = 0;
	savegame->terminal = FINAL;
	devkit_SMS_disableSRAM();
}