#include <iostream>
#include <functional>

void f(int x, std::function<void(int)> const& cb) {
  x = x*2;
  // Call callback
  cb(x);
}

void print(int x) {
  std::cout << x << std::endl;
}

int main(int argc, char* argv[])
{
  f(2, print);

  int x=5;
  auto update = [&x](int c) { x += c; };
  f(3, update);
  std::cout << x << std::endl;

  return 0;
}