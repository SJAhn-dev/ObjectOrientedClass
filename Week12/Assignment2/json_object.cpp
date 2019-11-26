#ifndef JSON_OBJECT_CPP
#define JSON_OBJECT_CPP

#include "json_object.h"
#include "json_dict.h"
#include "json_list.h"
#include "data/String.h"
#include "data/Integer.h"
#include <typeinfo>;

int json_object::_index = 0;

json_object* json_object::parse(const char *data, int length) {
	if(_index==length) { return nullptr; }
	if(data[0]=='{'){
		json_object* obj = json_dict::parse(data,length);
		return obj;
	} else if(data[0]=='[') {
		json_object* obj = json_list::parse(data,length);
		return obj;
	} else if(typeid(data[0]).name()=="int") {
		json_object* obj = Integer::parse(data,length);
		return obj;
	} else {
		json_object* obj = String::parse(data,length,data[0]);
		return obj;
	}
}

json_object* json_object::parse(const std::string& str) {
	const char* cstr = str.c_str();
	int lth = str.length();
	return parse(cstr,lth);
}

#endif
