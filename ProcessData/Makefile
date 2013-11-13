all: process_data

process_data: process_data.cpp
	$(CXX) -std=c++0x -I /usr/include/eigen3 -o process_data process_data.cpp

test: process_data
	./process_data

debug: process_data.cpp
	$(CXX) -g -std=c++0x -I /usr/include/eigen3 -o process_data process_data.cpp
