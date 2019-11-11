#include "bike.h"
#include "vehicle.h"

bike::bike(){
	this->max_speed = 0;
	this->wheel_number = 0;
	this->has_name = false;
	this->bike_name = "";
	this->bike_number = 0;
}

bike::bike(int num, int speed){
	this->max_speed = speed;
	this->wheel_number = num;
	this->has_name = false;
	this->bike_name = "";
	this->bike_number = 0;
}

bike::bike(int num, int speed, char* name){
	this->wheel_number = num;
	this->max_speed = speed;
	this->has_name = true;
	this->bike_name = name;
	this->bike_number = 0;
}

bike::bike(int num, int speed, char* name, int bike_num){
	this->wheel_number = num;
	this->max_speed = speed;
	this->has_name = true;
	this->bike_name = name;
	this->bike_number = bike_num;
}

int bike::get_bike_number(){
	return this->bike_number;
}

char* bike::get_bike_name(){
	return this->bike_name;
}

const char* bike::get_class_name(){
	return "bike";
}

void bike::set_bike_name(char* name){
	this->bike_name = name;
}

void bike::set_bike_number(int num){
	this->bike_number = num;
}


