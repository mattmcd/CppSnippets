#include <iostream>
#include <string>

int main( int argc, char* argv[])
{
  int n_max = 20;
  auto make_filter = [](int n, std::string w){
    return [n,w](int k){ return k % n == 0 ? w : ""; }; };

  auto fizz = make_filter(3, "fizz");
  auto buzz = make_filter(5, "buzz");

  std::streambuf *buf;

  //  Get stream buffer from output stream - could use to output to file also
  buf = std::cout.rdbuf();
  
  std::ostream out( buf );

  auto fizzbuzz = [&fizz,&buzz, &out](int n){
    std::string s = fizz(n) + buzz(n);
    if ( s.size() > 0 ) {
      out << s;
    } else {
      out << n;
    }
  };

  for( int i=1; i<n_max; i++) {
    fizzbuzz( i);
    std::cout << " ";
  }
  return 0;
}