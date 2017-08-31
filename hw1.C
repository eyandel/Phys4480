#include <vector>
#include "nr3.h"
using namespace std;

void hw1(){
  cout<< setprecision(8);
  VecDoub x(2);
  x[0] = 1;
  x[1] = -1;
  std::cout<<x[0]<<std::endl;
  VecDoub b(2);
  b[0] = 0.1869169;
  b[1] = 0.2155734;
  std::cout<<b[1]<<std::endl;
}
