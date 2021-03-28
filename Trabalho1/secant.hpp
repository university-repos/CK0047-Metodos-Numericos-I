#include <cmath>
#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>

const double eulerConstant = std::exp(1.0);

vector<vector<double>> secant_method(double amplitude, double precision, double initialDisplacement, int maxIterations);

void callSecant_method(double amplitude, double precision, int maxIterations, double chute){

  vector<vector<double>> res = secant_method(amplitude, precision, chute, maxIterations );

  vector<string> header = {"d", "F(d)"};

  table(res, header);
}

double amplitude, displacement;

template<typename T>
T
calculate_function(T amplitude, T displacement)
{
  // f(d) = a*(e^d) - 4*(d^2)
  return (amplitude * (std::pow(eulerConstant, displacement)) -
          4 * (std::pow(displacement, 2.0)));
}

double
calculate_next_root(double previousRoot, double currentRoot, double amplitude)
{
  double nextRoot =
    currentRoot - (calculate_function<double>(amplitude, currentRoot)) /
                    ((calculate_function<double>(amplitude, currentRoot) -
                      calculate_function<double>(amplitude, previousRoot)) /
                     (currentRoot - previousRoot));

  return nextRoot;
}

vector<vector<double>> 
secant_method(double amplitude, double precision, double initialDisplacement, int maxIterations)
{

  vector<vector<double>> QuadroResposta;
  vector<double> Linha = {};


  double previousRoot = initialDisplacement, currentRoot = previousRoot + 2.0;
  
  if(abs(calculate_function(amplitude, previousRoot)) < precision ){
    QuadroResposta.push_back(Linha);
    QuadroResposta[0].push_back(0);
    QuadroResposta[0].push_back(previousRoot);
    QuadroResposta[0].push_back(calculate_function(amplitude, previousRoot));

    return QuadroResposta;
  }

  if(abs(calculate_function(amplitude, currentRoot)) < precision || abs(currentRoot - previousRoot) < precision ){
    QuadroResposta.push_back(Linha);
    QuadroResposta[0].push_back(0);
    QuadroResposta[0].push_back(currentRoot);
    QuadroResposta[0].push_back(calculate_function(amplitude, currentRoot));

    return QuadroResposta;
  }

  for (int i = 0; i < maxIterations; ++i) {

    double nextRoot = calculate_next_root(previousRoot, currentRoot, amplitude);

    QuadroResposta.push_back(Linha);
    QuadroResposta[i].push_back(i);
    QuadroResposta[i].push_back(currentRoot);
    QuadroResposta[i].push_back(calculate_function(amplitude, currentRoot));

    if(abs(nextRoot) < precision || abs(nextRoot - currentRoot) < precision){
      return QuadroResposta;
    }

    previousRoot = currentRoot;
    currentRoot = nextRoot;

  }

  cout << "\n" << "O calculo não convergiu!" << "\n";
  return QuadroResposta;
}