all: read_matrix

read_matrix: read_matrix.cpp matrix_reader.hpp matrix_reader.cpp
	$(CXX) -std=c++0x -I /usr/include/eigen3 -o read_matrix read_matrix.cpp matrix_reader.cpp

test: read_matrix
	./read_matrix
