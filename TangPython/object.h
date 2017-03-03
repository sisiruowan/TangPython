/*
	object head file
*/
#ifndef OBJECT_H
#define OBJECT_H

#define TyObject_HEAD	\
	int refCount;\
	struct tagTyTypeObject *type

#define TyObject_HEAD_INIT(typePtr)\
	0, typePtr 

typedef struct tagTyObject {
	TyObject_HEAD;
}TyObject;

#endif // !OBJECT_H
