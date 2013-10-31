#include <iostream>
#include <string>

int main( int argc, char* argv[])
{
  int n_max = 20;
  auto make_filter = [](int n, std::string w){
    return [n,w](int k){ return k % n == 0 ? w : ""; }; };

  auto fizz = make_filter(3, "fizz");
  auto buzz = make_filter(5, "buzz");

  auto fizzbuzz = [&fizz,&buzz](int n){
    std::string s = fizz(n) + buzz(n);
    if ( s.size() > 0 ) {
      std::cout << s;
    } else {
      std::cout << n;
    }
  };

  for( int i=1; i<n_max; i++) {
    fizzbuzz( i);
    std::cout << " ";
  }
  return 0;
}