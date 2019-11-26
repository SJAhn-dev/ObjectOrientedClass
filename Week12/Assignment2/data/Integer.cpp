#ifndef INTEGER_CPP
#define INTEGER_CPP

#include "Integer.h"
#include "../json_object.h"

Integer::Integer(int value) {
	this->_val = value;
}

int Integer::val(){
	return this->_val;
}

void Integer::set_val(const int& value) {
	this->_val = value;
}

json_object* Integer::parse(const char *value, int length) {
	int val = atoi(value);
	return new Integer(val);
}

json_object::_type Integer::type(){
	return INT;
}

std::string Integer::to_string(){
	return std::to_string(this->_val);
}

#endif
