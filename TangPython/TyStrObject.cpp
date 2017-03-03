#include "TyStrObject.h"

TyTypeObject TyString_Type = {
	TyObject_HEAD_INIT(&TyType_Type),
	"str",
	string_print,
	string_add,
	string_hash
};


TyObject* TyStr_Create(const char* value) {
	TyStringObject* object = new TyStringObject;
	object->refCount = 1;
	object->type = &TyString_Type;
	object->length = (value == NULL) ? 0 : strlen(value);
	object->hashValue = -1;
	memset(object->value, 0, 50);
	if (value != NULL)
	{
		strcpy_s(object->value, value);
	}
	return (TyObject*)object;
}

