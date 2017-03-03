#ifndef TANG_PYTHON_H
#define TANG_PYTHON_H
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "object.h"
#include "TyTypeObject.h"
#include "TyStrObject.h"
#include "TyIntObject.h"
#include "TyDictObject.h"
using namespace std;

void ExcuteCommand(string& command);
void ExcuteAdd(string& target, string& source);
void ExcutePrint(string symbol);
TyObject* GetObjectBySymbol(string& symbol);
bool IsSourceAllDigit(string& source);

#endif // !TANG_PYTHON_H

