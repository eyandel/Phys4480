#include <vector>
using namespace std;

void hw1(){
  vector<double> x(2);
  x.at(0) = 1;
  x.at(1) = -1;
  std::cout<<x[0]<<std::endl;
  vector<double> b(2);
  b.at(0) = 0.1869169;
  b.at(1) = 0.2155734;
  std::cout<<b[1]<<std::endl;
}
