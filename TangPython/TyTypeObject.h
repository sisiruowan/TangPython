/*
	type object head file
*/
#ifndef TY_TYPE_OBJECT_H
#define TY_TYPE_OBJECT_H

#include"object.h"

typedef void (*PrintFun) (TyObject* object);
typedef TyObject* (*AddFun) (TyObject* left, TyObject* right);
typedef long (*HashFun) (TyObject* object);

typedef struct tagTyTypeObject {
	TyObject_HEAD;
	char* name;
	PrintFun print;
	AddFun add;
	HashFun hash;
}TyTypeObject;



#endif // !TY_TYPE_OBJECT_H
