#include <iostream>


int data = 15;
static int bss;
static const int rodata = 5;

int code(){
	return 0;
}

int main(){
	int a;
	int* heap = new int[a];
	int* stack = &a;
	
	std::cout << "Code\t" << (int*) code << std::endl;
	std::cout << "Rodata\t" << &rodata << std::endl;
	std::cout << "Data\t" << &data << std::endl;
	std::cout << "BSS\t" << &bss << std::endl;
	std::cout << "Heap\t" << heap << std::endl;
	std::cout << "stack\t" << &stack << std::endl;

	return 0;
}

