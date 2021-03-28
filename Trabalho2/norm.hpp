#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


double norma(int tamanhoMatrix, vector<double> matrixX, vector<double> matrixV){
  double norma;

  double normaNum = 0;
  double normaDen = 0;

  for (int i = 0; i < tamanhoMatrix; i++){
    double t = abs(matrixV[i] - matrixX[i]);

    if( t > normaNum ){
      normaNum = t;
    }

    if( abs(matrixV[i]) > normaDen){
      normaDen = abs(matrixV[i]);
    }

    matrixX[i] = matrixV[i];
  }

  norma = normaNum/normaDen;

  return norma;
}