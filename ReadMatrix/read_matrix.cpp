#include <string>
#include "matrix_reader.hpp"

void parse_args(int argc , char* argv[], std::string &fname, char &delimiter)
{
  if ( 2 > argc ) {
    fname = "data.txt";
  } else {
    fname = argv[1];
  }

  if ( 3 > argc ) {
    delimiter = ' ';
  } else {
    std::string delArg( argv[2] );
    if ( delArg == "space" ) {
      delimiter = ' ';
    } 
    if ( delArg == "tab" ) {
      delimiter = '\t';
    } 
    if ( delArg == "comma" ) {
      delimiter = ',';
    } 
  }
}

int main(int argc, char* argv[])
{
  std::string fname;
  char delimiter;
  parse_args(argc, argv, fname, delimiter);

  MatrixReader reader(fname, delimiter);
  auto data = reader.read();

  // for( auto d : data){
    std::cout << data << " ";
  // }
  std::cout << std::endl;

  return 0;
}
