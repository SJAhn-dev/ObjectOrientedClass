#include "vehicle.h"

class car : public vehicle {
private:
	char* car_name;

public:
	car();
	car(int num, int speed);
	car(int num, int speed, char* name);
	car(int num, int speed, char* name, bool has);
	
	char* get_car_name();
	virtual const char* get_class_name();
	void set_car_name(char* name);
};
