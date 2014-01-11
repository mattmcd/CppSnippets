#ifndef MATRIX_READER_HPP
#define MATRIX_READER_HPP

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iterator>
#include <Eigen/Dense>

class MatrixReader {
  public: 
    MatrixReader( std::string fname ) : in_(fname) {};
    std::vector<double> read();
  private:
    std::ifstream in_;
};

#endif
