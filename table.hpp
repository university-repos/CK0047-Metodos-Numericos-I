#include <iostream>
#include <vector>
#include<cmath>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;
void alinhar(string nome, double max);
void bonito(double nome, int max);
void alinharPasso(string nome, double max);
void linha(double max);
void mountComparativeTable(vector<double> tabelaPoly, vector<double> tabelaNewton, vector<double> tabelaScante);

void table(vector<vector<double>> tabela){
// valor do X  //// valor Px //// valor da derivada
  double valorK = tabela[tabela.size()-1][0];
  int max;
  int pontilhado = to_string(tabela[0][1]).size() + to_string(tabela[0][2]).size() + to_string(tabela[0][3]).size() + 8 + to_string(valorK).size();
  linha(pontilhado);
  alinharPasso("K", valorK);
  cout << " |";
  alinhar("d", tabela[0][1]);
  alinhar("F(d)", tabela[0][2]);
  alinhar("F'(d)", tabela[0][3]);  
  for(int i=0; i < tabela.size(); i++){
    linha(pontilhado);
    for(int l=0; l < tabela[i].size(); l++){
      if (l==0){
        alinharPasso(to_string((int)round(tabela[i][l])), valorK);
      }
      else{
        max = to_string(tabela[0][l]).size() + 1;
        bonito(tabela[i][l], max);
      }
      cout << " | ";
    }
  }
  linha(pontilhado);
}

void bonito(double nome, int max){
  string novo = to_string(nome);
  int tam = novo.size();
  while(tam<max){
    novo = novo + " ";
    tam += 1;
  }
  cout << novo;
}

void alinharPasso(string nome, double max){
  int tam = nome.size();
  string novo;
  while(novo.size()+tam<to_string(max).size()-7){
    novo = novo + " ";
  }
  cout << nome << novo << "|";
}
void alinhar(string nome, double max){
  int tam = nome.size();
  string novo;
  while(novo.size()+tam<to_string(max).size()+2){
    novo = novo + " ";
  }

  cout << " " << nome << novo << "|";
}

void linha(double max){
  cout << "\n";
  for(int i=0; i<max; i++){
    cout <<"-";
  }
  cout << "\n";
}

//Tabela Comparativa, recebe como parâmetro a útlima linha do vetor matriz de cada método
void mountComparativeTable(vector<double> tabelaPoly, vector<double> tabelaNewton, vector<double> tabelaScante){
    /*
      Elementos dos vetores: [1] guarda a última raiz encontrda,[2] guada o f(c)
      dessa raiz, [0] guarda o numero da ultima iteração
      "bonito(string, int)" ajusta a largura de uma célula a partir de um valor condizente
      com a coluna
    
    */
    string linha = "------------------------------------------------------------------------------------------";
    cout << linha << endl;
    cout << "Método                 || Qtd encontrada (c)  | f(c)          | Total de iterações" << endl;
    cout << linha << endl;

    cout << "Newton para polinômios || ";
    bonito(tabelaPoly[1], 20);
    cout << "| ";
    bonito(tabelaPoly[2], 14);
    cout << "| ";
    cout << " " << to_string((int)round(tabelaPoly[0])) << endl;
    cout << linha << endl;

    cout << "Newton-Rapson          || ";
    bonito(tabelaNewton[1], 20);
    cout << "| ";
    bonito(tabelaNewton[2], 14);
    cout << "| ";
    cout << " " << to_string((int)round(tabelaNewton[0])) << endl;
    cout << linha << endl;

    cout << "Secante                || ";
    bonito(tabelaScante[1], 20);
    cout << "| ";
    bonito(tabelaScante[2], 14);
    cout << "| ";
    cout << " " << to_string((int)round(tabelaScante[0])) << endl;
    cout << linha << endl;

}