#ifndef REGRESSION_HPP
#define REGRESSION_HPP
#include <vector>

struct Result {
  double A;
  double B;
};

class Regression {
   struct Point {
    double x;
    double y;
     bool operator==(Point const& other) const
  {
    return x==other.x && y==other.y;
  }
  };

  std::vector<Point> points_{};

  bool remove(double x, double y)
{
  Regression::Point p_rm{x,y};
  for (auto p_it = points_.begin(), p_end = points_.end(); p_it != p_end; ++p_it) {
    if ((*p_it) == p_rm) {
      points_.erase(p_it);
      return true;
    }
  }
  return false;
}


 public:
  int size() const;
  void add(double x, double y);
  Result fit() const;
};

Result fit(Regression const &reg);



#endif