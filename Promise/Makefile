all: promise

promise: promise.cpp
	$(CXX) -std=c++0x -o promise promise.cpp -pthread

test: promise
	./promise
