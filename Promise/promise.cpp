#include <iostream>
#include <functional>
#include <future>

std::future<int> f(int x) {
	return std::async(std::launch::async, [](int x) {return 2*x;}, x);
}

void print(int x) {
  std::cout << x << std::endl;
}

int main(int argc, char* argv[])
{
  auto p = f(2);
  print( p );

  int x=5;
  auto update = [&x](int c) { x += c; };
  auto p2 = f(3);
  update( p2 );
  std::cout << x << std::endl;

  return 0;
}