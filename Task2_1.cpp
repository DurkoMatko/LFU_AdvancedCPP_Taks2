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
	std::set_terminate(deallocate);		//set function to be called on terminate
	allocate();
	throw std::runtime_error(" :) ");
	deallocate();						//in imaginary case exception is not thrown, I can't forget to deallocate memory here as well
}