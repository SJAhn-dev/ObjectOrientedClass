.SUFFIXES: .cpp .o .h

OBJECTS = test.o smart_obj.o shared_ref.o human.o student.o weak_pointer.o
CPP = test.cpp smart_obj.cpp shared_ref.cpp human.cpp student.cpp weak_pointer.cpp

CXX = g++
CPPFLAGS = -c

TARGET = test

$(TARGET) : $(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS)

clean :
	rm -rf $(OBJECTS) $(TARGET)

test.o : test.cpp
smart_obj.o : smart_obj.cpp
human.o : human.cpp
student.o : student.cpp
shared_ref.o : shared_ref.cpp
weak_pointer.o : weak_pointer.cpp
