#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>

int main( int argc, char* argv[])
{
  const std::string sentence("This is a test sentence");

  std::istringstream is(sentence);
  std::vector<std::string> words;
  
  std::copy( std::istream_iterator<std::string>(is),
    std::istream_iterator<std::string>(),
    std::back_inserter(words));

  int count = 1;
  for( auto word : words ) {
    std::cout << count++ << ": " << word << std::endl;
  }

  return 0;
}
