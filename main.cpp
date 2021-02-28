#include <iostream>
#include <vector>
#include <cmath>

#include "newton_modified.hpp"

using namespace std;

// Metodo Newton modificado
int callNewtonModified( double valueA, double precision, int maxIterations );


int main(){

  std::vector<double> coeficienteMyFunctions;

  int numberN;
  int maxIteration;
  double precision;

  cout << "Digite o numero maximo de iterações:" << "\n";
  cin >> maxIteration;

  cout << "Digite a precisão aceitável:" << "\n";
  cin >> precision;

  cout << "Digite um numero:" << "\n";
  cin >> numberN;

  for (int i = 0; i < numberN; i++)
  {
    double valueA;
    cout << "Digite o valor do " << i << " a" << "\n";
    cin >> valueA;

    coeficienteMyFunctions.push_back(valueA);

  }

  for (int i = 0; i < coeficienteMyFunctions.size(); i++)
  {
    callNewtonModified(coeficienteMyFunctions[i], precision, maxIteration);

  }
  
  

  return 0;
}