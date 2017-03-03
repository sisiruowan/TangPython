/*
	String object head file
*/
#ifndef TY_STR_OBJECT_H
#define TY_STR_OBJECT_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "object.h"
#include "TyTypeObject.h"

extern TyTypeObject TyType_Type;

typedef struct tagTyStrObject{
	TyObject_HEAD;
	int length;
	long hashValue;
	char value[50];
}TyStringObject;

TyObject* TyStr_Create(const char* value);
static void string_print(TyObject* object) {
	TyStringObject* strObject = (TyStringObject*)object;
	printf("%s\n", strObject->value);
}

static long string_hash(TyObject* object) {
	TyStringObject* strObject = (TyStringObject*)object;
	register int len;
	register unsigned char *p;
	register long x;

	if (strObject->hashValue != -1) {
		return strObject->hashValue;
	}
	len = strObject->length;
	p = (unsigned char*)strObject->value;
	x = *p << 7;
	while (--len >= 0)
	{
		x = (1000003 * x) ^ *p++;
	}
	x ^= strObject->length;
	if (x == -1) {
		x = -2;
	}
	strObject->hashValue = x;
	return x;
}

static TyObject* string_add(TyObject* left, TyObject* right) {
	TyStringObject* leftStr = (TyStringObject*)left;
	TyStringObject* rightStr = (TyStringObject*)right;
	TyStringObject* result = (TyStringObject*)TyStr_Create(NULL);
	if (result == NULL)
	{
		printf("We have no enough memory!!");
		exit(1);
	}
	else
	{
		strcpy_s(result->value, leftStr->value);
		strcat_s(result->value, rightStr->value);
	}
	return (TyObject*)result;

}


#endif // !TY_STR_OBJECT_H

