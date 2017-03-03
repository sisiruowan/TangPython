#include "TyDictObject.h"

TyTypeObject TyDict_Type = {
	TyObject_HEAD_INIT(&TyType_Type),
	"dict",
	dict_print,
	0,
	0
};

TyObject* TyDict_Create() {
	TyDictObject* object = new TyDictObject;
	object->refCount = 1;
	object->type = &TyDict_Type;
	return (TyObject*)object;
}

TyObject* TyDict_GetItem(TyObject* target, TyObject* key) {
	long keyHashValue = (key->type)->hash(key);
	map<long, TyObject*>& dict = ((TyDictObject*)target)->dict;
	map<long, TyObject*>::iterator it = dict.find(keyHashValue);
	map<long, TyObject*>::iterator end = dict.end();
	if (it == end) {
		return NULL;
	}
	return it->second;
}

int TyDict_SetItem(TyObject* target, TyObject* key, TyObject* value) {
	long keyHashValue = (key->type)->hash(key);
	TyDictObject* dictObject = (TyDictObject*)target;
	(dictObject->dict)[keyHashValue] = value;
	return 0;
}



