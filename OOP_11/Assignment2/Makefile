.SUFFIXES: .cpp .o


OBJECTS = test.o Integer.o Float.o Complex.o
CPP = test.cpp Integer.cpp Float.cpp Complex.cpp

CXX = g++
CPPFLAGS = -c

TARGET = test

$(TARGET) : $(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS)

clean :
		rm -rf $(OBJECTS)

test.o : test.cpp
Integer.o : Integer.cpp
Float.o : Float.cpp
Complex.o : Complex.cpp
