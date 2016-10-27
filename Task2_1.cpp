#include <iostream>
#include <exception>
#include <stdexcept>


int *a, *b, *c;

void allocate() {
	a = new int(1);
	b= new int(2);
	c= new int(3);
}

void deallocate() {
	std::cout << "Deallocating objects" << std::endl;
	delete a;
	delete b;
	delete c;
}

int main() {
	try{
		allocate();
		throw std::runtime_error(" :) ");
		deallocate();
	}
	catch(std::runtime_error e){		//catch exception and make sure heap objects are deallocated
		deallocate();				
	}
	
}