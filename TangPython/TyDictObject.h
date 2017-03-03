/*
	Dict object head file 
*/
#ifndef TY_DICT_OBJECT_H
#define TY_DICT_OBJECT_H
#include <map>

#include "object.h"
#include "TyTypeObject.h"
using namespace std;

extern TyTypeObject TyType_Type;

typedef struct tagTyDictObject {
	TyObject_HEAD;
	map<long, TyObject*> dict;
}TyDictObject;

TyObject* TyDict_Create();
TyObject* TyDict_GetItem(TyObject* target, TyObject* key);
int TyDict_SetItem(TyObject* target, TyObject* key, TyObject* value);

static void dict_print(TyObject* object) {
	TyDictObject* dictObject = (TyDictObject*)object;
	printf("{");
	map<long, TyObject*>::iterator it = (dictObject->dict).begin();
	map<long, TyObject*>::iterator end = (dictObject->dict).end();
	for (; it != end; ++it) {
		printf("%ld : ", it->first);
		TyObject* value = it->second;
		(value->type)->print(value);
		printf(", ");
	}
	printf("\n");
}



#endif // !TY_DICT_OBJECT_H

