#include <iostream>
#include <functional>
#include <future>

std::future<int> f(int x) {
	return std::async(std::launch::async, [](int y) {return 2*y;}, x);
}

void print(int x) {
  std::cout << x << std::endl;
}

int main(int argc, char* argv[])
{
  auto p = f(2);
  p.wait();
  print( p.get() );

  int x=5;
  auto update = [&x](int c) { x += c; };
  auto p2 = f(3);
  p2.wait();
  update( p2.get() );
  std::cout << x << std::endl;

  return 0;
}
