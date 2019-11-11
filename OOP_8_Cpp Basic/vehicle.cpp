#include "vehicle.h"

vehicle::vehicle(){
	this->has_name = false;
	this->wheel_number = 0;
	this->max_speed = 0;
}

vehicle::vehicle(int num, int speed){
	this->has_name = false;
	this->wheel_number = num;
	this->max_speed = speed;
}

vehicle::vehicle(int num, int speed, bool has){
	this->has_name = has;
	this->wheel_number = num;
	this->max_speed = speed;
}

int vehicle::get_wheel_number(){
	return this->wheel_number;
}

int vehicle::get_max_speed(){
	return this->max_speed;
}

bool vehicle::get_has_name(){
	return this->has_name;
}

const char* vehicle::get_class_name(){
	return "Vehicle";
}

void vehicle::set_wheel_number(int number){
	this->wheel_number = number;
}

void vehicle::set_max_speed(int speed){
	this->max_speed = speed;
}

void vehicle::set_has_name(bool has){
	this->has_name = has;
}

