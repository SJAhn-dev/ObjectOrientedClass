#ifndef JSON_DICT_CPP
#define JSON_DICT_CPP

#include "json_dict.h"

void json_dict::put(json_object *key, json_object *val)
{
}

int json_dict::find(json_object *key)
{
    this->v;
}

json_dict::json_dict()
{
    this->v = std::vector<std::pair<json_object *, json_object *>>();
}

json_object* json_dict::parse(const char* str, int length){
    int start_idx = _index;
    int vec_idx = 0;
    int key_start=0, key_end=0;
    int partition_index=0;
    int val_start=0, val_end=0;
	std::string input = str;
	json_dict *jdict = new json_dict();
	json_object* key = NULL;
    json_object* val = NULL;
	
	_index++;
    while(_index < length){
        if(str[_index]==':'){
            partition_index = _index;
            key_end = _index-1;
            val_start = _index+1;
        } else if( str[_index]==','){
            val_end = _index-1;
            std::string first = input.substr(key_start,key_end);
            std::string second = input.substr(val_start,val_end);
            jdict->v[vec_idx].first = json_object::parse(first);
            jdict->v[vec_idx].second = json_object::parse(second);
            key_start = _index+1;
        }
        _index++;
    }
    

    return jdict;
}

json_object* json_dict::operator[](json_object* key) const{
    if (key->type() == json_object::INT)
	{
		return operator[](atoi(key->to_string().c_str()));
	}
	else if (key->type() == json_object::STRING)
	{
		return operator[](key->to_string());
	}

	return NULL;
}

json_object* json_dict::operator[](const std::string& key) const
{
	std::string _key = '\'' + key + '\'';
	for (std::pair<json_object*, json_object*> _tmp : v)
	{
		if (_tmp.first->to_string() == _key)
			return _tmp.second;
	}
	return NULL;
}

json_object* json_dict::operator[](int key) const
{
	for (std::pair<json_object*, json_object*> _tmp : v)
	{
		int _key = atoi(_tmp.first->to_string().c_str());
		if (_key == key)
			return _tmp.second;
	}
	return NULL;
}

json_object::_type json_dict::type()
{
	return DICT;
}

std::string json_dict::to_string()
{
	if (v.size() == 0)
		return "{}";

	std::string string = "{";
	for (int i = 0; i < v.size() - 1; i++)
	{
		string += v[i].first->to_string() + ": " + v[i].second->to_string();
		string += ", ";
	}
	string += v[v.size() - 1].first->to_string() + ": " + v[v.size() - 1].second->to_string() + '}';
	return string;
}




#endif