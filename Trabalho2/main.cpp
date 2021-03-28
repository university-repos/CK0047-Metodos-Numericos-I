#include <iostream>
#include <vector>
#include <cmath>
#include "table.hpp"
#include "gauss-seidel.hpp"
using namespace std;

void printMatriz(vector<vector<double>> matrizA);
vector<vector<double>> montarMatriz( vector<vector<double>> matriz, vector<vector<double>> addMatriz, int index );
vector<vector<double>> multiplicarMatriz(vector<vector<double>> matrixA, vector<vector<double>> matrixB);
vector<double> montarVetor(vector<vector<double>> matriz);

int main() {

  // Variaveis
  int grauA;
  double valueMatriz;
  
  // Matriz A
  cout << "Qual o grau da Matriz A: ";
  cin >> grauA; 
  
  // Cria as matrizes
  // vector<vector<double>> matrizA (grauA, vector<double>(grauA)), matrizInversa (grauA, vector<double>(grauA)) ;
  // vector<vector<double>> matrizB (grauA, vector<double>(1));
  
  vector<vector<double>> matrizA = {{5, 3, 1}, {5, 6, 1}, {1, 6, 7}},  matrizInversa (grauA, vector<double>(grauA)) ;
  vector<vector<double>> matrizB = {{1}, {2}, {3}};


  // // Popular Matriz
  // for(int i=0; i<grauA; i++){
  //   for(int j=0; j<grauA; j++){
  //     cout << "Entre o valor de a" << i+1 << j+1 << ": ";
  //     cin >> matrizA[i][j];
  //   }
  // }

  // // Popular Matriz b
  // cout << "Entre os valores da Matriz b" << endl;
  // for(int i=0; i<grauA; i++){
  //   cout << "Entre o valor de b" << i+1 << ": ";
  //   cin >> valueMatriz;
  //   matrizB[i][0] = valueMatriz;
  // }

  // --------------
  // GAUSS SEIDEL - INICIO
  // --------------

  // Monta a inversa utilizando GAUSS SEIDEL
  for (int i=0; i<grauA; i++){
    vector<vector<double>> identidade (grauA, vector<double>(1));

    // Gera a identidade
    identidade[i][0] = 1;

    vector<vector<double>> colunaInversa = gaussSeidel(matrizA, identidade);

    matrizInversa = montarMatriz(matrizInversa, colunaInversa, i);
  }

  // Apresenta matrix inversa
  //table(matrizInversa);


  cout << "++++++++++++++++++++++++++++++";
  cout << "\n" << "GAUSS SEIDEL" << "\n";
  cout << "++++++++++++++++++++++++++++++" << "\n";

  cout << "==============================" << "\n";
  cout << "\n" << "Valores da Matriz A: " << "\n";
  table(matrizA);
  cout << "==============================" << "\n";
  
  cout << "==============================" << "\n";
  cout << "\n" << "Valores da Matriz B: " << "\n";
  vector<double> vetorBSeidel = montarVetor(matrizB);
  unionTable(vetorBSeidel);
  cout << "==============================" << "\n";
  
  cout << "==============================" << "\n";
  vector<double> matrixDSeidel = montarVetor(multiplicarMatriz(matrizInversa, matrizB));
  cout << "\n" << "Valores da Matriz D: " << "\n";
  unionTable(matrixDSeidel);
  cout << "==============================" << "\n";
  
  // --------------
  // GAUSS SEIDEL - FIM
  // --------------

  return 0;

}

// Apresenta a Matriz
void printMatriz(vector<vector<double>> matriz) {
  for(int i=0; i<matriz.size(); i++){
    for(int j=0; j<matriz[0].size(); j++){
      cout << matriz[i][j] << " ";
    }
    cout << "\n";
  }
}

// Adiciona valores a uma deterninada coluna de um determidada matriz
vector<vector<double>> montarMatriz( vector<vector<double>> matriz, vector<vector<double>> addMatriz, int index ){

  vector<vector<double>> newMatriz = matriz;
  // Per
  for(int i=0; i<addMatriz.size(); i++){
    for(int j=0; j<addMatriz[0].size(); j++){
      newMatriz[i][index] = addMatriz[i][j];
    }
  }

  return newMatriz;
}

vector<double> montarVetor(vector<vector<double>> matriz){
  vector<double> newVector;

  for(int i=0; i<matriz.size(); i++){
    for(int j=0; j<matriz[i].size(); j++){
      newVector.push_back(matriz[i][j]);
    }
  }

  return newVector;
}

// Mutiplica MatrizA pela MatrizB
vector<vector<double>> multiplicarMatriz(vector<vector<double>> matrixA, vector<vector<double>> matrixB) {
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