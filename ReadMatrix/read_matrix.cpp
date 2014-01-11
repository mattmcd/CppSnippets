#include <string>
#include "matrix_reader.hpp"

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

  MatrixReader reader(fname);
  auto data = reader.read();

  for( auto d : data){
    std::cout << d << " ";
  }
  std::cout << std::endl;

  return 0;
}
