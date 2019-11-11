#include <iostream>

#ifndef VEHICLE_H
#define VEHICLE_H

class vehicle{
public:
	bool has_name;
	int wheel_number;
	int max_speed;

	vehicle();
	vehicle(int num, int speed);
	vehicle(int num, int speed, bool has);

	int get_wheel_number();
	int get_max_speed();
	bool get_has_name();
	virtual const char* get_class_name();
	void set_wheel_number(int number);
	void set_max_speed(int speed);
	void set_has_name(bool has);
};

#endif
