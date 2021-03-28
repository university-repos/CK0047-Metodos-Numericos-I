#include <iostream>
#include <vector>
#include <cmath>
#include "table.hpp"
#include "gauss-seidel.hpp"
#include "convergencia.hpp"
#include "gauss-jacobi.hpp"

using namespace std;

vector<vector<double>> montarMatrix( vector<vector<double>> matrix, vector<vector<double>> addMatrix, int index );
vector<vector<double>> multiplicarMatrix(vector<vector<double>> matrixA, vector<vector<double>> matrixB);
vector<double> montarVetor(vector<vector<double>> matrix);

int main() {

  // Variaveis
  int grauA;
  double valueMatrix, valorError, maxIteracoes;
  
  // Matrix A
  cout << "Qual o grau da Matrix A: ";
  cin >> grauA;

  // Error
  cout << "Qual o error: ";
  cin >> valorError;

  // MaxIterations
  cout << "Qual o maximo de iterações: ";
  cin >> maxIteracoes; 
  
  // Cria as matrixes
  vector<vector<double>> matrixA (grauA, vector<double>(grauA)), matrixInversaSeidel (grauA, vector<double>(grauA)), matrixInversaJacobi (grauA, vector<double>(grauA)) ;
  vector<vector<double>> matrixB (grauA, vector<double>(1));
  
  // Exemplo que Nao converge
  //vector<vector<double>> matrixA = {{2, 1, 3}, {0, -1, 1}, {1, 0, 3}},  matrixInversaSeidel (grauA, vector<double>(grauA)) ;
  
  // Exemplo que converge
  //vector<vector<double>> matrixA = {{5, 3, 1}, {5, 6, 1}, {1, 6, 7}},  matrixInversaSeidel (grauA, vector<double>(grauA)) ;

  //vector<vector<double>> matrixB = {{1}, {2}, {3}};


  // Popular Matrix A
  for(int i=0; i<grauA; i++){
    for(int j=0; j<grauA; j++){
      cout << "Entre o valor de a" << i+1 << j+1 << ": ";
      cin >> matrixA[i][j];
    }
  }

  // Popular Matrix b
  cout << "Entre os valores da Matrix b" << endl;
  for(int i=0; i<grauA; i++){
    cout << "Entre o valor de b" << i+1 << ": ";
    cin >> valueMatrix;
    matrixB[i][0] = valueMatrix;
  }

  // --------------
  // GAUSS SEIDEL - INICIO
  // --------------
  
  cout << "++++++++++++++++++++++++++++++";
  cout << "\n" << "GAUSS SEIDEL" << "\n";
  cout << "++++++++++++++++++++++++++++++" << "\n";

  // Criterios de convergencia
  criterioSassenfeld(matrixA);
  criterioLinhas(matrixA);

  // Monta a inversa utilizando GAUSS SEIDEL
  for (int i=0; i<grauA; i++){
    vector<vector<double>> identidade (grauA, vector<double>(1));

    // Gera a identidade
    identidade[i][0] = 1;

    // Gera a inversa da Coluna i
    vector<vector<double>> colunaInversa = gaussSeidel(matrixA, identidade, valorError, maxIteracoes);

    // Adiciona a coluna na nova matriz
    matrixInversaSeidel = montarMatrix(matrixInversaSeidel, colunaInversa, i);
  }

  // Apresenta matrix inversa
  //table(matrixInversaSeidel);

  cout << "==============================" << "\n";
  cout << "\n" << "Valores da Matrix A: " << "\n";
  table(matrixA);
  cout << "==============================" << "\n";
  
  cout << "==============================" << "\n";
  cout << "\n" << "Valores da Matrix B: " << "\n";
  vector<double> vetorBSeidel = montarVetor(matrixB);
  unionTable(vetorBSeidel);
  cout << "==============================" << "\n";
  
  cout << "==============================" << "\n";
  vector<double> matrixDSeidel = montarVetor(multiplicarMatrix(matrixInversaSeidel, matrixB));
  cout << "\n" << "Valores da Matrix D: " << "\n";
  unionTable(matrixDSeidel);
  cout << "==============================" << "\n";
  
  // --------------
  // GAUSS SEIDEL - FIM
  // --------------

  // --------------
  // GAUSS Jacobi - INICIO
  // --------------

  cout << "++++++++++++++++++++++++++++++";
  cout << "\n" << "GAUSS Jacobi" << "\n";
  cout << "++++++++++++++++++++++++++++++" << "\n";

  // Criterios de convergencia
  criterioLinhas(matrixA);

  // Monta a inversa utilizando GAUSS Jacobi
  for (int i=0; i<grauA; i++){
    vector<vector<double>> identidadeJacobi (grauA, vector<double>(1));

    // Gera a identidadeJacobi
    identidadeJacobi[i][0] = 1;

    // Gera a inversa da Coluna i
    vector<vector<double>> colunaInversaJacobi = jacobiMethod(matrixA, montarVetor(identidadeJacobi), valorError, maxIteracoes);

    // Adiciona a coluna na nova matriz
    matrixInversaJacobi = montarMatrix(matrixInversaJacobi, colunaInversaJacobi, i);
  }

  // Apresenta matrix inversa
  //table(matrixInversaJacobi);

  cout << "==============================" << "\n";
  cout << "\n" << "Valores da Matrix A: " << "\n";
  table(matrixA);
  cout << "==============================" << "\n";
  
  cout << "==============================" << "\n";
  cout << "\n" << "Valores da Matrix B: " << "\n";
  vector<double> vetorBJacobi = montarVetor(matrixB);
  unionTable(vetorBJacobi);
  cout << "==============================" << "\n";
  
  cout << "==============================" << "\n";
  vector<double> matrixDJacobi = montarVetor(multiplicarMatrix(matrixInversaJacobi, matrixB));
  cout << "\n" << "Valores da Matrix D: " << "\n";
  unionTable(matrixDJacobi);
  cout << "==============================" << "\n";
  
  // --------------
  // GAUSS Jacobi - FIM
  // --------------

  return 0;

}

// Adiciona valores a uma deterninada coluna de um determidada matrix
vector<vector<double>> montarMatrix( vector<vector<double>> matrix, vector<vector<double>> addMatrix, int index ){

  vector<vector<double>> newMatrix = matrix;
  // Per
  for(int i=0; i<addMatrix.size(); i++){
    for(int j=0; j<addMatrix[0].size(); j++){
      newMatrix[i][index] = addMatrix[i][j];
    }
  }

  return newMatrix;
}

vector<double> montarVetor(vector<vector<double>> matrix){
  vector<double> newVector;

  for(int i=0; i<matrix.size(); i++){
    for(int j=0; j<matrix[i].size(); j++){
      newVector.push_back(matrix[i][j]);
    }
  }

  return newVector;
}

// Mutiplica MatrixA pela MatrixB
vector<vector<double>> multiplicarMatrix(vector<vector<double>> matrixA, vector<vector<double>> matrixB) {
  vector<vector<double>> newMatrix (matrixA.size() ,vector<double> (matrixB[0].size()));  

  for(int i = 0; i < matrixA.size(); i++){
	  for(int j = 0; j < matrixB[0].size(); j++){ 
      for(int k = 0; k < matrixA[0].size(); k++){
        newMatrix[i][j] += matrixA[i][k]*matrixB[k][j];
      }
    }
  }

  return newMatrix;
}