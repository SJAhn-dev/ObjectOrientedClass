#include "car.h"
#include "vehicle.h"

car::car(){
	this->has_name = false;
	this->wheel_number = 0;
	this->max_speed = 0;
	this->car_name = "";
}

car::car(int num, int speed){
	this->wheel_number = num;
	this->max_speed = speed;
	this->has_name = false;
	this->car_name = "";
}

car::car(int num, int speed, char* name){
	this->wheel_number = num;
	this->max_speed = speed;
	this->has_name = true;
	this->car_name = name;
}

car::car(int num, int speed, char* name, bool has){
	this->wheel_number = num;
	this->max_speed = speed;
	this->has_name = true;
	this->car_name = name;
}

char* car::get_car_name(){
	return this->car_name;
}

const char* car::get_class_name(){
	return "car";
}

void car::set_car_name(char* name){
	this->car_name = name;
}

