#include "matrix_reader.hpp"

std::vector<double> MatrixReader::read() {
  // Use STL to read numbers from file into a vector
  std::vector<double> data;
  
  if (in_ ) {
    std::copy( std::istream_iterator<double>(in_), 
      std::istream_iterator<double>(), std::back_inserter(data));
  }

  return data;
}

