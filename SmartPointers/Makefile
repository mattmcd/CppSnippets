all: smart_pointers

smart_pointers: smart_pointers.cpp
	$(CXX) -std=c++0x -o smart_pointers smart_pointers.cpp -pthread

test: smart_pointers
	./smart_pointers
