#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void linha( int tamanho, int Max);
double maxValue(vector<vector<double>> A, int tamanho);
double minValue(vector<vector<double>> A, int tamanho);
void printValor(int Max, double valor);
void unionTable(vector<double> A);

// Tabela de uma matrtiz NxN
void table(vector<vector<double>> A){
    int tamMax = A.size();

    double compMax;
    double comp1 =  maxValue(A, tamMax);
    double comp2 =  minValue(A, tamMax);
    if(comp2  < 0){
        compMax = comp2;
    }else{
        compMax = comp1;
    }
    linha(tamMax, to_string(compMax).length() );

    for(int i=0; i< tamMax; i++){
        cout << "| ";
        for(int j=0; j< tamMax; j++){
            printValor(to_string(compMax).length() ,A[i][j]);
            cout << " | ";
        }
        cout << endl;
        linha(tamMax, to_string(compMax).length() );
    }
    return;
}

// Tabela de uma matrix Nx1
void unionTable(vector<double> A){
    int tamMax = A.size();

    double compMax;
    double comp1 =  *max_element(A.begin(), A.end());
    double comp2 =  *min_element(A.begin(), A.end());

    if(comp2  < 0){
        compMax = comp2;
    }else{
        compMax = comp1;
    }

    for(int i=0; i<to_string(compMax).length() + 4; i++){
        cout << "-";
    }
    cout << endl;
    for(int j=0; j< tamMax; j++){

      cout << "| ";
      printValor(to_string(compMax).length() ,A[j]);
      cout << " | " << endl;
      for(int i=0; i<to_string(compMax).length() + 4; i++){
          cout << "-";
      }
      cout << endl;
        
    }
    return;
}

void linha( int tamanho, int Max) {
    for(int i=0; i< (tamanho*Max) + 10; i++){
        cout << "-";
    }
    cout << endl;
}

void printValor(int Max, double valor){
    cout << to_string(valor);
    for(int i=to_string(valor).length(); i<Max; i++){
        cout << " ";
    }
}

double maxValue(vector<vector<double>> A, int tamanho) {
    double result = 0;
    
    for(int i=0; i<tamanho; i++){
        if( result < *max_element(A[i].begin(), A[i].end())){
            result = *max_element(A[i].begin(), A[i].end());
        }
    }
    return result;
}

double minValue(vector<vector<double>> A, int tamanho) {
    double result = 0;
    
    for(int i=0; i<tamanho; i++){
        if( result > *min_element(A[i].begin(), A[i].end())){
            result = *min_element(A[i].begin(), A[i].end());
        }
    }
    return result;
}