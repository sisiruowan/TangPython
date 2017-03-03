/*
	The excute environment
*/

#include "TangPython.h"

TyDictObject* m_LocalEnvironment = new TyDictObject;
void ExcuteCommand(string& command) {
	string::size_type pos = 0;
	if ((pos = command.find("print ")) != string::npos){
		ExcutePrint(command.substr(6));
	}
	else if ((pos = command.find(" = ")) != string::npos) {
		string target = command.substr(0, pos);
		string source = command.substr(pos + 3);
		ExcuteAdd(target, source);
	}
}

void ExcuteAdd(string& target, string& source) {
	string::size_type pos;
	TyObject* strValue = NULL;
	TyObject* resultValue = NULL;
	// source is digit
	if (IsSourceAllDigit(source)) {
		TyObject* intValue = TyInt_Create(atoi(source.c_str()));
		TyObject* key = TyStr_Create(target.c_str());
		TyDict_SetItem((TyObject*)m_LocalEnvironment, key, intValue);
	}// source is string
	else if ((pos = source.find("\"") != string::npos)) {
		strValue = TyStr_Create(source.substr(1, source.size()-2).c_str());
		TyObject* key = TyStr_Create(target.c_str());
		TyDict_SetItem((TyObject*)m_LocalEnvironment, key, strValue);
	}// source is add command
	else if ((pos = source.find("+")) != string::npos) {
		TyObject* leftObject = GetObjectBySymbol(source.substr(0, pos));
		TyObject* rightObject = GetObjectBySymbol(source.substr(pos + 1));
		if (leftObject != NULL && rightObject != NULL && leftObject->type == rightObject->type) {
			resultValue = (leftObject->type)->add(leftObject, rightObject);
			TyObject* key = TyStr_Create(target.c_str());
			TyDict_SetItem((TyObject*)m_LocalEnvironment, key, resultValue);
		}
		(m_LocalEnvironment->type)->print((TyObject*)m_LocalEnvironment);
	}
}
bool IsSourceAllDigit(string& source) {
	bool result = true;
	for (int i = 0; i < source.size(); i++) {
		result = isdigit(source[i]);
		if (result == false) {
			break;
		}
	}
	return result;
}

void ExcutePrint(string symbol) {
	TyObject* object = GetObjectBySymbol(symbol);
	if (object != NULL) {
		TyTypeObject* type = object->type;
		type->print(object);
	}
}

TyObject* GetObjectBySymbol(string& symbol) {
	TyObject* key = TyStr_Create(symbol.c_str());
	TyObject* value = TyDict_GetItem((TyObject*)m_LocalEnvironment, key);
	if (value == NULL) {
		//cout<< "[Error] : " << symbol << " is not defined!!" << endl;
		printf("[Error] : %s is not defined!!\n", symbol);
		return NULL;
	}
	return value;
}

const char* info = "********** Python Research **********\n";
const char* prompt = ">>> ";
string m_Command;
void Excute() {
	cout << info;
	cout << prompt;
	while (getline(cin, m_Command))
	{
		if (m_Command.size() == 0) {
			cout << prompt;
			continue;
		}
		else if (m_Command == "exit") {
			return;
		}
		else
		{
			ExcuteCommand(m_Command);
		}
		cout << prompt;
	}
}

int main() {
	Excute();
	return 0;
}