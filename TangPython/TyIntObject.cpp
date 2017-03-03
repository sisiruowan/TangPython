#include "TyIntObject.h"
TyTypeObject TyInt_Type = {
	TyObject_HEAD_INIT(&TyType_Type),
	"int",
	int_print,
	int_add,
	int_hash
};
TyObject* TyInt_Create(int value) {
	TyIntObject* object = new TyIntObject;
	object->refCount = 1;
	object->type = &TyInt_Type;
	object->value = value;
	return (TyObject*)object;
}


