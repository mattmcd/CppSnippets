#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <Eigen/Dense>

class Point {
  public:
    Point();
    Point(std::istream& in);
    std::istream& read(std::istream&);
    void print( std::ostream& );
    double getX() const { return x; };
    double getY() const { return y; };

  private:
    double x;
    double y;
    std::string name;
};

Point::Point() : x(0), y(0) {}

Point::Point(std::istream& in){
  read( in );
}

std::istream& Point::read( std::istream& in){
  in >> name >> x >> y;
  return in;
}

void Point::print( std::ostream& out ) {
  out << name << " " << x << " " << y << std::endl;
}

std::istream& operator>>(std::istream& in, Point& p){
  p.read(in);
  return in;
}

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
  std::vector<Point> data;
  
  std::copy( std::istream_iterator<Point>(in), 
    std::istream_iterator<Point>(), std::back_inserter(data));

  // Transform data
  std::vector<double> x;
  std::transform( data.begin(), data.end(), std::back_inserter(x),
    [](Point p){ return p.getX(); });
  
  std::vector<double> y;
  std::transform( data.begin(), data.end(), std::back_inserter(y),
    [](Point p){ return p.getY(); });

  Eigen::Map<Eigen::VectorXd> X(x.data(),x.size());
  Eigen::Map<Eigen::VectorXd> Y(y.data(),y.size());

  // Store x and y coordinates as 2 x N matrix [x1, x2, ...; y1, y2, ...]
  Eigen::MatrixXd m( 2, x.size());
  m.row(0) = X;
  m.row(1) = Y;
  std::cout << m << std::endl;

  // Shear transformation
  Eigen::Matrix2d A;
  A << 1, 2, 0, 1;
  m = A*m;
  std::cout << m << std::endl;
  X = m.row(0);

  for( auto d : data){
    d.print( std::cout );
  }
  std::cout << std::endl;

  for( auto xv : x){
    std::cout << xv << std::endl;
  }

  return 0;
}
