#include "matrix_reader.hpp"
#include <stdlib.h>

Eigen::MatrixXd MatrixReader::read() {
  // Use STL to read numbers from file into a vector
  std::vector<std::string> header;
  std::vector<double> data;

  if (in_ ) {
    // First line is header
    std::string s;
    std::getline(in_, s);
    std::istringstream is(s);
    std::string n;
    while (std::getline( is, n, delimiter_))
      header.push_back(n);

    while ( getline(in_, s)) {
      std::istringstream is(s);
      while (std::getline( is, n, delimiter_))
        data.push_back( atof( n.c_str() ) );
    }
  }

  Eigen::MatrixXd m( data.size(), 1);

  for (std::vector<double>::size_type i=0;  i<data.size(); ++i ) {
    m(i,0) = data[i];
  }

  m.resize(header.size(), data.size()/header.size());
  
  m.transposeInPlace();

  return m;
}

