#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>

class Point {
  public:
    Point();
    Point(std::istream& in);
    std::istream& read(std::istream&);
    void print( std::ostream& );

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
  
  // Non-STL version:
  //Point p;
  //while( p.read(in) ) {
  //  data.push_back(p);
  //}

  std::copy( std::istream_iterator<Point>(in), 
    std::istream_iterator<Point>(), std::back_inserter(data));

  for( auto d : data){
    d.print( std::cout );
  }
  std::cout << std::endl;

  return 0;
}
