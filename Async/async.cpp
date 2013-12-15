#include <iostream>
#include <future>
#include <thread>
#include <chrono>
#include <string>

// Example from http://solarianprogrammer.com/2012/10/17/cpp-11-async-tutorial/

void called_from_async() {
  std::cout << "Called from async" << std::endl;
}

// Example from
// http://www.justsoftwaresolutions.co.uk/threading/multithreading-in-c++0x-part-2-function-objects-and-arguments.html

class SayHello {
  public:
    void operator()() const {
      std::cout << "Hello from function object " << this << std::endl;
    }
    void greeting() const {
      std::cout << "Hello from a method on " << this << std::endl;
    }
};

int main(int argc, char* argv[])
{
  std::future<void> result( std::async( std::launch::async, called_from_async ) );
  std::thread t{ SayHello() };
  std::thread t2{ [](){ std::cout << "Hello from lambda!" << std::endl; } };
  std::thread t3{ [](const std::string name){ 
                    std::cout << "Hello " << name << " from lambda!" << std::endl; }, 
                    "Matt" };

  std::this_thread::sleep_for( std::chrono::seconds( 1 ));
  std::cout << std::endl; 

  SayHello x;
  x.greeting();
  std::thread t4{ &SayHello::greeting, &x };
  std::thread t5{ x };
  std::thread t6{ std::ref(x) };

  std::this_thread::sleep_for( std::chrono::seconds( 1 ));
  std::cout << std::endl; 

  std::cout << "Message from main" << std::endl;

  result.get();

  t.join();
  t2.join();
  t3.join();
  t4.join();
  t5.join();
  t6.join();

  return 0;
}
