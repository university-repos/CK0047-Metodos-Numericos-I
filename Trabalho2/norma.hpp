#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


double norma(int tamanhoMatrix, vector<vector<double>> matrixX, vector<vector<double>> matrixV){
  double norma;

  double normaNum = 0;
  double normaDen = 0;

  for (int i = 0; i < tamanhoMatrix; i++){
    double t = abs(matrixV[i][0] - matrixX[i][0]);

    if( t > normaNum ){
      normaNum = t;
    }

    if( abs(matrixV[i][0]) > normaDen){
      normaDen = abs(matrixV[i][0]);
    }

    matrixX[i][0] = matrixV[i][0];
  }

  norma = normaNum/normaDen;

  return norma;
}