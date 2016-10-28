#include <iostream>
#include <fstream>

void openFile(std::fstream &file) {
	file.open("test.txt",std::fstream::trunc | std::fstream::app);
}
	
void writeToFile(std::fstream &file) {
	file << "hola" << std::endl;
}

void closeFile(std::fstream &file) {
	file.close();
}


int main() {
	std::fstream file;
	openFile(file);
	file.open("test.txt",std::fstream::out | std::fstream::app);
	writeToFile(file);
	closeFile(file);
}