#include "vehicle.h"

class bike : public vehicle{
private:
	char* bike_name;
	int bike_number;

public:
	bike();
	bike(int num, int speed);
	bike(int num, int speed, char* name);
	bike(int num, int speed, char* name, int bike_num);
	bike(int num, int speed, char* name, int bike_num, bool has);

	int get_bike_number();
	char* get_bike_name();
	virtual const char* get_class_name();
	void set_bike_name(char* name);
	void set_bike_number(int num);
};
