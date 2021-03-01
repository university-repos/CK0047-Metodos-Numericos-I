#include <iostream>
#include <vector>
#include <cmath>

#include "table.hpp"
#include "newton_modified.hpp"
#include "newton_raphson.hpp"
#include "secant.hpp"

using namespace std;


// Tabela
void table(vector<vector<double>> tabela, vector<string> header);

// Metodo Newton modificado
int callNewtonModified( double valueA, double precision, int maxIterations, double chute);

// Metodo Newton Raphson
int callNewtonRaphson( double valueA, double precision, int maxIterations, double chute);

// Metodo Secante
void callSecant_method(double amplitude, double initialDisplacement, int maxIterations);

int main(){

  std::vector<double> coeficienteMyFunctions;

  int numberN;
  int maxIteration;
  double precision;
  double chute;

  cout << "Digite o numero maximo de iterações:" << "\n";
  cin >> maxIteration;

  cout << "Digite a precisão aceitável:" << "\n";
  cin >> precision;

  cout << "Digite o valor do chute:" << "\n";
  cin >> chute;

  cout << "Digite o numero N de amplitudes:" << "\n";
  cin >> numberN;

  for (int i = 0; i < numberN; i++)
  {
    double valueA;
    cout << "Digite o valor da amplitude" << i <<  ":\n";
    cin >> valueA;

    coeficienteMyFunctions.push_back(valueA);

  }

  for (unsigned int i = 0; i < coeficienteMyFunctions.size(); i++)
  {

    cout << "\n" << "============NEWTON MODIFICADO===========";
    // cout << " NEWTON MODIFICADO " << "\n";
    cout << "\n" << "Valores para amplitude " << i+ 1 << " : " << coeficienteMyFunctions[i] << "\n";
    cout << "F(d) = " << coeficienteMyFunctions[i] << "*e^d - 4d^2";  
    callNewtonModified(coeficienteMyFunctions[i], precision, maxIteration, chute);
    // cout << "\n" << "========================================";
    
    cout << "\n" << "=============NEWTON RAPHSON=============";
    // cout << " NEWTON RAPHSON " << "\n";
    cout << "\n" << "Valores para amplitude " << i+ 1 << " : " << coeficienteMyFunctions[i] << "\n";
    cout << "F(d) = " << coeficienteMyFunctions[i] << "*e^d - 4d^2";  
    callNewtonRaphson(coeficienteMyFunctions[i], precision, maxIteration, chute);
    // cout << "\n" << "========================================";

    cout << "\n" << "================SECANTE=================";
    // cout << " SECANTE " << "\n";
    cout << "\n" << "Valores para amplitude " << i+ 1 << " : " << coeficienteMyFunctions[i] << "\n";
    cout << "F(d) = " << coeficienteMyFunctions[i] << "*e^d - 4d^2";  
    callSecant_method(coeficienteMyFunctions[i], precision, maxIteration, chute);
    // cout << "\n" << "========================================";
  }
  
  return 0;
}