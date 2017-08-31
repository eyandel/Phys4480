#include <vector>
#include <math.h>
#include<iostream>
#include<fstream>
#include "nr3.h"
#include "ludcmp.h"
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
  
  MatDoub a(2,2);
  a[0][0]=0.7073725;
  a[0][1]=0.5204556;
  a[1][0]=0.8158208;
  a[1][1]=0.6002474;
  std::cout<<a[0][1]<<std::endl;
  
  VecDoub x1(2);
  x1[0] = 0.9999999;
  x1[1] = -1.0000001;
  
  VecDoub x2(2);
  x2[0] = 0.4073666;
  x2[1] = -0.1945277;

  VecDoub r1(2);
  r1[0] = b[0]-(a[0][0]*x1[0]+a[0][1]*x1[1]);
  r1[1] = b[1]-(a[1][0]*x1[0]+a[1][1]*x1[1]);
  double r1norm=sqrt(r1[0]+r1[1]);
  std::cout<<r1norm<<std::endl;
  ofstream myfile;
  myfile.open ("phys4480hw1_1.txt");
  myfile << "r1="+r1norm+"\n";
  myfile.close();
  
  VecDoub r2(2);
  r2[0] = b[0]-(a[0][0]*x2[0]+a[0][1]*x2[1]);
  r2[1] = b[1]-(a[1][0]*x2[0]+a[1][1]*x2[1]);
  double r2norm=sqrt(r2[0]^2+r2[1]^2);
  std::cout<<r2norm<<std::endl;
  myfile.open ("phys4480hw1_1.txt");
  myfile << "r2="+r2norm+"\n";
  myfile.close();
  
  VecDoub xlu(2);
  LUdcmp alu(a);
  alu.solve(b,xlu);
  errorlu=sqrt(
  std::cout<<xlu[0]+xlu[1]::endl;
  myfile.open ("phys4480hw1_1.txt");
  myfile << "xlu="+xlu[0]+xlu[1]+"\n";
  myfile.close();
}
