#include <iostream>

int main(int argc, char* argv[])
{
  // Closure capturing by value
  auto adder = [](int x){
    return [x](int y){ return x + y;};};

  auto add2 = adder(2);

  std::cout << add2(1) << std::endl; // 3
  std::cout << adder(2)(3) << std::endl; // 5

  // Closure capturing by reference
  int x = 5;
  auto add_x = [&x](int y){ return x + y;};
  
  std::cout <<	add_x(3) << std::endl; // 8
  
  x = 10; // Change x in the environment
  std::cout <<	add_x(3) << std::endl; // 13
  
  // Immediate application of lambda
  std::cout <<  [&x](int y){ return x + y;}(15) << std::endl;

  return 0;
}
