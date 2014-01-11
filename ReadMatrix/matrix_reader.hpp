#ifndef MATRIX_READER_HPP
#define MATRIX_READER_HPP

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <Eigen/Dense>

class MatrixReader {
  public: 
    MatrixReader( std::string fname, char delimiter = ' ' ) 
      : in_(fname), delimiter_(delimiter) {};
    Eigen::MatrixXd read();
  private:
    std::ifstream in_;
    char delimiter_;
};

#endif
