all: thread

thread: thread.cpp
	$(CXX) -std=c++0x -o thread thread.cpp -pthread

test: thread
	./thread
