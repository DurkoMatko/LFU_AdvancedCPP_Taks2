# <center>  Proseminar 2  </center> 
## <center>  Advanced C++ </center>  

####Task1
Given code throws runtime error and allocated objects are never deleted from the heap

```C++
int main() {
	allocate();
	throw std::runtime_error(" :) ");
	deallocate();
}
```

Solution is to wrap code with try-catch block and execute deallocation in catch part. 

```C++
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
```

To make sure the potential leak is fixed, I ran command 
```shell
valgrind --leak-check=yes ./Task2_1
```

####Task 2 + 3 
The description of the task says that program finishes without reaching the end. In my case, my program finished without any error. Just the file is not created. I believe the problem is in opening file with flags which actually stand in contradiction with each other:

```C++
file.open("test.txt",std::fstream::trunc | std::fstream::app);
```

This line says to append new text to the previous one and delete the previous text at the same time. Also, one would think that <b>std::fstream::app</b> implies <b>std::fstream::out</b> but it does not. Since I'm allowed to change nothing but main function, there's just one way how to correct the program which is <b>open the file once again in main - with correct flags </b>. Another solution would be define trunc as out in preprocessor, but I'm allowed to change only main function.

```C++
int main() {
	std::fstream file;
	openFile(file);
	file.open("test.txt",std::fstream::out | std::fstream::app);
	writeToFile(file);
	closeFile(file);
}
```
<br>

####Task 4
I needed 3 classes - Vertex, Edge and Graph itself.

<b>Vertex </b> - has name and vector of edges
<b> Edge </b> - references 2 vertexes (cannot exist without 2 existing vertexes) and contains distance value
<b>Graph</b> - contains vector of vertexes

There was circular dependency between Vertex and Edge class so I forward declarated vertex in Edge class.

My implementation of graph is directed graph (one-way edges).

To make sure my solution is secure, I checked my executable file with valgrind again 
```shell
valgrind --leak-check=yes ./GraphImplementation
```

<i>Folder "zaloha" contains solution where Vertexes in Edge class are implemented as pointers instead of references - it works but it's a bad design.