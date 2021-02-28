#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


double newtonModified(double coeficient, double x0Value, double precision, int maxIteration, double x0);
double genericFunction(double coeficient, double xValue);
double genericFunctionDerivate(double coeficient, double xValue);

int callNewtonModified( double valueA, double precision, int maxIterations ){

  double chute = 2.0;

  newtonModified(valueA, chute, precision, maxIterations, chute);

  

  return 0;
}


double newtonModified(double coeficient, double x0Value, double precision, int maxIteration, double x0){

  double fx = genericFunction(coeficient, x0Value);
  int k = 0;

  if(abs(fx) < precision){
    return x0Value;
  }

  while(k < maxIteration){

    double x1 = x0Value - genericFunction(coeficient, x0Value)/genericFunctionDerivate(coeficient, x0);

    cout << "\n" << "X1:" << x1; 
    cout << "\n" << "x0Value:" << x0Value; 
    cout << "\n" << "genericFunction(coeficient, x1):" << genericFunction(coeficient, x1); 
    cout << "\n" << "X1:" << x1; 

    if(abs(genericFunction(coeficient, x1)) < precision || abs(x1-x0Value) < precision){

      return x1;
    }

    x0Value = x1;
    k++;

  }

  return 1.0;
};

double genericFunction(double coeficient, double xValue){
    
    return (coeficient * exp(xValue)) - (4 * xValue * xValue);
}

double genericFunctionDerivate(double coeficient, double xValue){
    
    return (coeficient * exp(xValue)) - (8 * xValue);
}