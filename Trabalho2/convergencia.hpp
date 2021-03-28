#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool CriterioSassenfeld(vector<vector<double>> matrixA){

  vector<double> matrixB (matrixA.size());

  for (int i = 0; i < matrixA.size(); i++){
    double soma = 0;
    for (int j = 1; j < matrixA[0].size(); j++){
      soma += matrixA[i][j] / matrixA[i][i];
    }
    matrixB[i] = soma;
  }

  double maxElemento = *max_element(matrixB.begin(), matrixB.end());
  
  if( maxElemento < 1){
    cout << "\n" << "A convergencia é garantida pelo metodo Sassenfeld" << "\n";
    cout << "Valor: " << maxElemento;
    return true;
    
  } else {
    cout << "\n" << "A convergencia NÃO é garantida pelo metodo Sassenfeld" << "\n";
    return false;
  }

}