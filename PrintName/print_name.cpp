#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

void parse_args( int argc, char* argv[], std::string &name) 
{
  if (argc < 2) {
    name = "Matt";
  } else {
    name = argv[1];
  }
}

int main(int argc, char* argv[])
{
  std::string name;
  parse_args(argc, argv, name);

  const std::string greeting = "Hello " + name;  
  const auto n_greet = greeting.size();

  const std::string border( n_greet + 4, '*');
  const std::string pad = "*" + std::string( n_greet + 2, ' ') + "*";

  std::vector<std::string> output;
 
  auto add = [&](std::string s){ output.push_back(s); };
  
  add(border);
  add(pad);
  add("* " + greeting + " *" );
  add(pad);
  add(border);

  std::for_each( output.begin(), output.end(), 
    [](std::string s) { std::cout << s << std::endl; });

  return 0;
}
