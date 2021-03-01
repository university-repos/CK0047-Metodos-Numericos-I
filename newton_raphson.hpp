#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>

using namespace std;

// Funcoes internas
vector<vector<double>> newtonRaphson(double coeficient, double x0Value, double precision, int maxIteration, double x0);

int callNewtonRaphson( double valueA, double precision, int maxIterations, double chute ){

  vector<vector<double>> res = newtonRaphson(valueA, chute, precision, maxIterations, chute);

  vector<string> header = {"d", "F(d)", "F'(d)"};

  table(res, header);

  return 0;
}


vector<vector<double>> newtonRaphson(double coeficient, double x0Value, double precision, int maxIteration, double x0){

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
    QuadroResposta[k].push_back(genericFunctionDerivate(coeficient, x0Value));

    double x1 = x0Value - genericFunction(coeficient, x0Value)/genericFunctionDerivate(coeficient, x0Value);

    if(abs(genericFunction(coeficient, x1)) < precision || abs(x1-x0Value) < precision){

      return QuadroResposta;
    }

    x0Value = x1;
    k++;
  }
  cout << "\n" << "O calculo não convergiu!" << "\n";
  return QuadroResposta;
};
