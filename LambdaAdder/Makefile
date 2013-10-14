all: lambda_adder 

lambda_adder: lambda_adder.cpp
	g++ -std=c++0x -o lambda_adder lambda_adder.cpp

test: lambda_adder
	./lambda_adder
