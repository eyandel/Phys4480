#include <cmath>
#include <vector>
#include <math.h>
#include<iostream>
#include<fstream>
#include "nr3.h"
#include "ludcmp.h"
#include "svd.h"
#include "gaussj.h"
using namespace std;

void hw1(){
  cout<< setprecision(8);

//Problem 1
  VecDoub x(2);
  x[0] = 1;
  x[1] = -1;
  std::cout<<x[0]<<std::endl;
  //instantiate x

  VecDoub b(2);
  b[0] = 0.1869169;
  b[1] = 0.2155734;
  std::cout<<b[1]<<std::endl;
  //instantiate b

  MatDoub a(2,2);
  a[0][0]=0.7073725;
  a[0][1]=0.5204556;
  a[1][0]=0.8158208;
  a[1][1]=0.6002474;
  std::cout<<a[0][1]<<std::endl;
  //instantiate A

  VecDoub x1(2);
  x1[0] = 0.9999999;
  x1[1] = -1.0000001;

  VecDoub x2(2);
  x2[0] = 0.4073666;
  x2[1] = -0.1945277;

//part a
  VecDoub r1(2);
  r1[0] = b[0]-(a[0][0]*x1[0]+a[0][1]*x1[1]);
  r1[1] = b[1]-(a[1][0]*x1[0]+a[1][1]*x1[1]);
  double r1norm=sqrt(pow(r1[0],2)+pow(r1[1],2));
  std::cout<<r1norm<<std::endl;
  ofstream myfile;
  myfile.open("phys4480hw1_1.txt");
  myfile << "1a.\n";
  myfile << "r1=" << r1norm <<'\n';
  //calculate residual for x1 and print to file

  VecDoub r2(2);
  r2[0] = b[0]-(a[0][0]*x2[0]+a[0][1]*x2[1]);
  r2[1] = b[1]-(a[1][0]*x2[0]+a[1][1]*x2[1]);
  double r2norm=sqrt(pow(r2[0],2)+pow(r2[1],2));
  std::cout<<r2norm<<std::endl;
  myfile << "r2=" << r2norm << '\n';
  //calculate residual for x2 and print to file

//part b
  VecDoub xlu(2);
  LUdcmp alu(a);
  alu.solve(b,xlu);
  //sove for x with lu decomp
  double errorlu=sqrt(pow(xlu[0]-x[0],2)+pow(xlu[1]-x[1],2));
  //calculate error=xlu-x
  VecDoub rlu(2);
  rlu[0] = b[0]-(a[0][0]*xlu[0]+a[0][1]*xlu[1]);
  rlu[1] = b[1]-(a[1][0]*xlu[0]+a[1][1]*xlu[1]);
  double rlunorm=sqrt(pow(rlu[0],2)+pow(rlu[1],2));
  //calculate residual for xlu
  std::cout<<xlu[0]+xlu[1]<<std::endl;
  myfile << "1b.\n" << "xlu=" << xlu[0] << ", " << xlu[1] << "\n" << "LU decomp error=" << errorlu << "\n";
  myfile << "residual for LU Decomp=" << rlunorm << '\n';

//part c
  SVD asvd(a);
  double conda=1/asvd.inv_condition();
  myfile << "1c.\n" << "Cond(a)=" << conda << '\n';
  //calculate and print condition number of A

//Problem 2

  int i,j;
  MatDoub A1600(1600,1600);
  ifstream inputA("A.txt");
  for (i = 0; i < 1600; i++) {
    for (j = 0; j < 1600; j++) {
      inputA >> A1600[j][i];
    }
  }
  inputA.close();
  std::cout<<A1600[0][1]<<std::endl;

  VecDoub b1600(1600);
  ifstream inputb("b.txt");
  for (i = 0; i < 1600; i++) {
    inputb >> b1600[i];
  }
  inputb.close();
  std::cout<<b1600[0]<<std::endl;

  VecDoub c1600(1600);
  ifstream inputc("c.txt");
  for (i = 0; i < 1600; i++) {
    inputc >> c1600[i];
  }
  inputb.close();

  //part a
  MatDoub Ainv = A1600;
  gaussj(Ainv);
  std::cout<<Ainv[0][1]<<std::endl;

  VecDoub x1600(1600);
  for (i = 0; i < 1600; i++) {
    for (j = 0; j < 1600; j++) {
      x1600[i]+=A1600[i][j]*b1600[j];
    }
  }
  double r = 0;
  for (j=0; j<1600; j++){
    r+=abs(x1600[j]-c1600[j]);
  }
  myfile << "2a.\n" << "r=" << r << '\n';
  //compute error

  //part b
  VecDoub xlu1600(1600);
  LUdcmp Alu1600(A1600);
  Alu1600.solve(b1600,xlu1600);
  //sove for x with lu decomp
  double rlu1600 = 0;
  for (j=0; j<1600; j++){
    rlu1600+=abs(xlu1600[j]-c1600[j]);
  }
  myfile << "2b.\n" << "r=" << rlu1600 << '\n';
  //compute error

  //part c
  std::cout<<xlu1600[0]<<std::endl;
  Alu1600.mprove(b1600,xlu1600);
  std::cout<<xlu1600[0]<<std::endl;
  //use iterative improvement to improve solution to x
  double rimprove = 0;
  for (j=0; j<1600; j++){
    rimprove+=abs(xlu1600[j]-c1600[j]);
  }
  myfile << "2c.\n" << "r=" << rimprove << '\n';
  //compute error

  //part d
    SVD A1600svd(A1600);
    double condA1600=1/A1600svd.inv_condition();
    myfile << "2d.\n" << "Cond(A)=" << condA1600 << '\n';
    //calculate and print condition number of A


  myfile.close();
}
