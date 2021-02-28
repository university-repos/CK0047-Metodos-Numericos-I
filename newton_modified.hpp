#include <iostream>
#include <vector>
#include <math.h>
#include "table.hpp"

using namespace std;

// Funçoes externas
void table(vector<vector<double>> A);

void printLinha(vector<double> a);
// Funcoes internas
vector<vector<double>> newtonModified(double coeficient, double x0Value, double precision, int maxIteration, double x0);
double genericFunction(double coeficient, double xValue);
double genericFunctionDerivate(double coeficient, double xValue);

int callNewtonModified( double valueA, double precision, int maxIterations, double chute ){

  vector<vector<double>> res = newtonModified(valueA, chute, precision, maxIterations, chute);

  table(res);

  return 0;
}


vector<vector<double>> newtonModified(double coeficient, double x0Value, double precision, int maxIteration, double x0){

  vector<vector<double>> QuadroResposta;
  vector<double> Linha = {};

  double fx = genericFunction(coeficient, x0Value);
  int k = 0;

  if(abs(fx) < precision){
    QuadroResposta.push_back(Linha);
    QuadroResposta[k].push_back(0);
    QuadroResposta[k].push_back(x0Value);
    QuadroResposta[k].push_back(genericFunction(coeficient, x0Value));
    QuadroResposta[k].push_back(genericFunctionDerivate(coeficient, x0));

    return QuadroResposta;
  }

  while(k < maxIteration){
    QuadroResposta.push_back(Linha);
    QuadroResposta[k].push_back(k);
    QuadroResposta[k].push_back(x0Value);
    QuadroResposta[k].push_back(genericFunction(coeficient, x0Value));
    QuadroResposta[k].push_back(genericFunctionDerivate(coeficient, x0));

    double x1 = x0Value - genericFunction(coeficient, x0Value)/genericFunctionDerivate(coeficient, x0);

    if(abs(genericFunction(coeficient, x1)) < precision || abs(x1-x0Value) < precision){

      return QuadroResposta;
    }

    x0Value = x1;
    k++;
  }

  return QuadroResposta;
};

double genericFunction(double coeficient, double xValue){
    
    return (coeficient * exp(xValue)) - (4 * xValue * xValue);
}

double genericFunctionDerivate(double coeficient, double xValue){
    
    return (coeficient * exp(xValue)) - (8 * xValue);
}

void printLinha(vector<double> a){
  for (int i = 0; i < a.size(); i++)
  {
    cout << i << " valor: " << a[i] << "\n";
  }

}