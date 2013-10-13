#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>

void parse_args(int argc , char* argv[], std::string &fname)
{
  if ( 1 == argc ) {
    fname = "data.txt";
  } else {
    fname = argv[1];
  }
}

int main(int argc, char* argv[])
{
  std::string fname;

  parse_args(argc, argv, fname);

  std::ifstream in(fname);
  if (!in) {
    std::cout << "File not found " << fname << std::endl;
    return 1;
  }
  
  // Use STL to read numbers from file into a vector
  std::vector<double> data;

  std::copy( std::istream_iterator<double>(in), 
    std::istream_iterator<double>(), std::back_inserter(data));

  for( auto d : data){
    std::cout << d << " ";
  }
  std::cout << std::endl;

  return 0;
}
