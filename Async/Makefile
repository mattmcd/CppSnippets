all: async

async: async.cpp
	$(CXX) -std=c++0x -o async async.cpp -pthread

test: async
	./async
