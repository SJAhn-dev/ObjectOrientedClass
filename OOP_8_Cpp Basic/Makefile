.SUFFIXES: .cpp .h .o

OBJECTS = main.o vehicle.o bike.o car.o
CPP = main.cpp vehicle.cpp bike.cpp car.cpp


CXX = g++
CPPFLAGS = -c

TARGET = test

$(TARGET) : $(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS)

clean :
	rm -rf $(OBJECTS)

main.o : main.cpp
vehicle.o : vehicle.cpp
bike.o : bike.cpp
car.o : car.cpp
