#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool criterioSassenfeld(vector<vector<double>> matrixA){

  vector<double> matrixB (matrixA.size());

  //valor do B1
  for (int i = 1; i < matrixA[0].size(); i++){
    matrixB[0] += matrixA[0][i] / matrixA[0][0];
  }
  
  for (int i = 0; i < matrixA.size(); i++){
    double soma = 0;
    for (int j = 0; j < matrixA[0].size(); j++){

      if( j != i){
        if( j < i ){
          soma += abs(matrixA[i][j]) * matrixB[j] / matrixA[i][i];
        } else {
          soma += abs(matrixA[i][j]) / matrixA[i][i];
        }
      }

    }
    matrixB[i] = soma;
  }

  double maxElemento = *max_element(matrixB.begin(), matrixB.end());
  
  if( maxElemento < 1){
    cout << "\n" << "A convergencia é garantida pelo metodo Sassenfeld" << "\n";
    return true;
    
  } else {
    cout << "\n" << "A convergencia NÃO é garantida pelo metodo Sassenfeld" << "\n";
    return false;
  }
}

bool criterioLinhas(vector<vector<double>> matrixA) {
  
  for (int i = 0; i < matrixA.size(); i++){
    double valuaA = abs(matrixA[i][i]);
    double soma = 0;
    for (int j = 0; j < matrixA[i].size(); j++){
      soma += abs(matrixA[i][j]);
    }
    if( valuaA <= soma ) {
      cout << "\n" << "A convergencia NÃO é garantida pelo metodo das Linhas" << "\n";
      return false;
    }
  }
  
  cout << "\n" << "A convergencia é garantida pelo metodo Sassenfeld" << "\n";

  return true;
}