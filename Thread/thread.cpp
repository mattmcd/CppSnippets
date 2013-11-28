#include <iostream>
#include <thread>


void called_from_thread() {
  std::cout << "Called from spawned thread" << std::endl;
}

int main(int argc, char* argv[])
{
  std::thread t( &called_from_thread );
  t.detach();

  std::cout << "Message from main" << std::endl;

  return 0;
}
