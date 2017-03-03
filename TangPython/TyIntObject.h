/*
	int object head file
*/
#ifndef TY_INT_OBJECT_H
#define TY_INT_OBJECT_H

#include <stdio.h>
#include <stdlib.h>
#include "object.h"
#include "TyTypeObject.h"

extern TyTypeObject TyType_Type;

typedef struct tagTyIntObject{
	TyObject_HEAD;
	int value;
}TyIntObject;

TyObject* TyInt_Create(int value);

static void int_print(TyObject* object) {
	TyIntObject* intObject = (TyIntObject*)object;
	printf("%d\n", intObject->value);
}

static TyObject* int_add(TyObject* left, TyObject* right) {
	TyIntObject* leftInt = (TyIntObject*)left;
	TyIntObject* rightInt = (TyIntObject*)right;
	TyIntObject* result = (TyIntObject*)TyInt_Create(0);
	if (result == NULL) {
		printf("We have no enough memory!!");
		exit(1);
	}
	else {
		result->value = leftInt->value + rightInt->value;
	}
	return (TyObject*)result;
}

static long int_hash(TyObject* object) {
	return (long)((TyIntObject*)object)->value;
}



#endif // !TY_INT_OBJECT_H