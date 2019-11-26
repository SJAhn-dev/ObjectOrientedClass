#ifndef STRING_CPP
#define STRING_CPP

#include "String.h"
#include "Integer.h"
#include "../json_object.h"

String::String(const std::string& str){
	this->_val = str;
}

std::string String::val(){
	return this->_val;
}

void String::set_val(const std::string&str){
	this->_val = str;
}

json_object* String::parse(const char* str, int length, char base) {
	int& a = json_object::_index;
	std::string temp = "";
	while (a < length)
	{
		switch (str[a])
		{
		case '\'':
			return new String(temp);
		default:
			temp += str[a];
			break;
		}
		++a;
	}

	return NULL;
}

json_object::_type String::type() {
	return STRING;
}

std::string String::to_string() {
	return this->_val;
}


#endif
