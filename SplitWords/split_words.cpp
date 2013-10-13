#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cctype>

int main( int argc, char* argv[])
{
  const std::string sentence("This is a test sentence");

  std::vector<std::string> words;
  
  auto space = [](char c){ return isspace(c); };
  auto not_space = [&](char c){ return !space(c);};
  
  typedef std::string::const_iterator iter;
  iter it = sentence.begin();
  
  while ( it != sentence.end() ) {
    it = std::find_if(it, sentence.end(), not_space);
    iter it_end = std::find_if(it, sentence.end(), space);
    if ( it != sentence.end()) {
      words.push_back(std::string(it, it_end));
    }
    it = it_end;
  }

  int count = 1;
  for( auto word : words ) {
    std::cout << count++ << ": " << word << std::endl;
  }

  return 0;
}
