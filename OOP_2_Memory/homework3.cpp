#include <iostream>

int main() {
	char target[] = "Ahn SeongJin";		// 13byte ( + null )
	long b[20];							// 160 byte
	int a = 17;							// 4byte
	int i = 196;						// 4byte
	int *c = new int[602];				// Heap Memory ( Stack x )
	char * copy = "is no no";			// 9byte
	char name = 'a';					// 2byte ( + null )
	
	std::cout << &name+i << std::endl;

	return 0;
}

