.SUFFIXES: .cpp	.o

OBJECTS	= homework1.o homework2.o homework3.o

CXX = g++
CPPFLAGS = -c

TARGET = homework1 homework2 homework3

$(TARGET) : $(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS)

clean :
	rm -rf $(OBJECTS) $(TARGET)

homework1.o : homework1.cpp
homework2.o : homework2.cpp
homework3.o : homework3.cpp

