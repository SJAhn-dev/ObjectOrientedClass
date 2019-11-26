#ifndef JSON_LIST_CPP
#define JSON_LIST_CPP

#include "json_list.h"


json_object::_type json_list::type()
{
	return LIST;
}

json_list::json_list()
{
	this->v = std::vector<json_object*>();
}

json_object *json_list::parse(const char *str, int length)
{
	int start_idx = _index;
	std::string input = str;
	json_list *jlist = new json_list();

	while (_index != length)
	{
		if (str[_index] == ',')
		{	
			json_object* obj = json_object::parse(input.substr(start_idx,_index-1));
			jlist->v.push_back(obj);
			start_idx = _index;
		}
		_index++;
	}

	return jlist;
}

json_object *json_list::operator[](int key) const
{
	return this->v[key];
}

std::string json_list::to_string()
{
	std::string toStr = "[";
	for(int i=0; i<v.size(); i++){
		toStr += v[i]->to_string() + ", ";
	}
	return toStr+"]";
}

#endif