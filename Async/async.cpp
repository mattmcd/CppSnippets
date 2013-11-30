#include <iostream>
#include <future>
#include <thread>
#include <chrono>

// Example from http://solarianprogrammer.com/2012/10/17/cpp-11-async-tutorial/

void called_from_async() {
  std::cout << "Called from async" << std::endl;
}

int main(int argc, char* argv[])
{
  std::future<void> result( std::async( std::launch::async, called_from_async ) );

  std::this_thread::sleep_for( std::chrono::seconds( 1 ));

  std::cout << "Message from main" << std::endl;

  result.get();

  return 0;
}
