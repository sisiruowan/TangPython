/*
	int object head file
*/
#ifndef TY_INT_OBJECT_H
#define TY_INT_OBJECT_H

#include "object.h"
#include "TyTypeObject.h"

typedef struct tagTyIntObject{
	TyObject_HEAD;
	int value;
}TyIntObject;

TyObject* TyInt_Create(int value) {
	TyIntObject* object = new TyIntObject;
	object->refCount = 1;
	object->type = &TyInt_Type;
	object->value = value;
	return (TyObject*)object;
}

TyTypeObject TyInt_Type = {
	TyObject_HEAD_INIT(&TyType_Type),
	"int",
	int_print,
	int_add,
	int_hash
};

#endif // !TY_INT_OBJECT_H