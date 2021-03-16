#ifndef _STORAGE_OBJECT_H_
#define _STORAGE_OBJECT_H_

// Reference: http://www.smspower.org/forums/16013-DevkitSMSSMSlibMissingRequestingFeatures#91899
typedef struct tag_struct_storage_object
{
	unsigned long Magic;
	unsigned char save_album_index;
	unsigned char terminal;

} struct_storage_object;

#endif//_STORAGE_OBJECT_H_