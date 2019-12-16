.SUFFIXES: .o .cpp .h

CXX = g++
CPPFLAGS = -c
TARGET = test
OBJECTS = main.o array_2d.o block.o big_block.o color_block.o fold_block.o tree_block.o cross_block.o
CPP = main.cpp array_2d.cpp block.cpp big_block.cpp color_block.cpp fold_block.cpp tree_block.cpp cross_block.cpp


$(TARGET):	$(OBJECTS)
		$(CXX) -o $(TARGET) $(OBJECTS)
clean	:
		rm -rf *.o test

main.o : main.cpp
array_2d.o : array_2d.cpp
block.o : block.cpp
big_block.o : big_block.cpp
color_block.o : color_block.cpp
fold_block.o : fold_block.cpp
tree_block.o : tree_block.cpp
cross_block.o : cross_block.cpp
