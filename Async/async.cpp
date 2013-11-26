#include <iostream>
#include <future>

// Example from http://solarianprogrammer.com/2012/10/17/cpp-11-async-tutorial/

void called_from_async() {
  std::cout << "Called from async" << std::endl;
}

int main(int argc, char* argv[])
{
  std::future<void> result( std::async( called_from_async ) );

  std::cout << "Message from main" << std::endl;

  result.get();

  return 0;
}