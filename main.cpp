#include <iostream>
#include <vector>
#include <cmath>

#include "newton_modified.hpp"

using namespace std;


// Metodo Newton modificado
int callNewtonModified( double valueA, double precision, int maxIterations, double chute);


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
    cout << "Digite o valor do " << i << " a" << "\n";
    cin >> valueA;

    coeficienteMyFunctions.push_back(valueA);

  }

  for (int i = 0; i < coeficienteMyFunctions.size(); i++)
  {

    cout << "\n" << "Valores para amplitude " << i+ 1 << " : " << coeficienteMyFunctions[i] << "\n";
    cout << "F(d) = " << coeficienteMyFunctions[i] << "*e^d - 4d^2";  
    callNewtonModified(coeficienteMyFunctions[i], precision, maxIteration, chute);

  }
  
  return 0;
}