#include <iostream>
#include <vector>
#include "convergencia.hpp"
#include "norma.hpp"

using namespace std;

// Adiciona valores a uma deterninada coluna de um determidada matriz
vector<vector<double>> gaussSeidel( vector<vector<double>> matrix, vector<vector<double>> colunaIdenttidade){

  vector<vector<double>> newtMatrix = matrix; // A
  vector<vector<double>> newColunaIdentidade = colunaIdenttidade; // b
  
  vector<vector<double>> resultadoX (colunaIdenttidade.size(), vector<double>(1)); // x
  vector<vector<double>> auxMatrixV (colunaIdenttidade.size(), vector<double>(1)); // v

  double erro = 0.0001;
  int max = 10;
  double r;

  // Teste de Convergencia
  bool teste = CriterioSassenfeld(matrix);

  int grauMatrix = matrix.size();

  // Contrucao da matriz e do vetor de iteracoes
  for(int i=0; i<grauMatrix; i++ ){
    r = 1 / matrix[i][i];

    for(int j=0; j<grauMatrix; j++){
      if ( i != j){
        newtMatrix[i][j] = newtMatrix[i][j] * r;
      }
    }

    newColunaIdentidade[i][0] = newColunaIdentidade[i][0] * r;
    resultadoX[i][0] = newColunaIdentidade[i][0] * r;

  }

  int k = 0;
  double normaValue;

  while (k <= max){
    k += 1;
    for (int i = 0; i < grauMatrix; i++){
      double soma = 0;
      
      for (int j = 0; j < grauMatrix; j++){
        if(i != j){
          soma += newtMatrix[i][j] * resultadoX[j][0];
        }
      }
      auxMatrixV[i][0] = resultadoX[i][0];
      resultadoX[i][0] = newColunaIdentidade[i][0] - soma;

    }
    normaValue = norma(grauMatrix, resultadoX, auxMatrixV);

    if( normaValue <= erro){
      return resultadoX;
    }
  }

  return resultadoX;
}