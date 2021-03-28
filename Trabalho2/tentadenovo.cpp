#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include "norm.hpp"
typedef std::vector<double> Vector;

typedef std::vector<std::vector<double>> Matrix;
void printVector(Vector vector);
void printCurrentIteration(int iteration, Vector x, double norm);
void printMatrix(Matrix matrixA);

double calculateNorm(Vector x, Vector v) {
    double normaNum = 0;
    double normaDen = 0;
    for (unsigned int i = 0; i < x.size(); ++i) {
        double temp = abs(v[i] - x[i]);

        if (temp > normaNum) {
            normaNum = temp;
        }

        if (abs(v[i]) > normaDen) {
            normaDen = abs(v[i]);
        }
    }
    double norm = normaNum / normaDen;
    return norm;
}

void sayHello(bool newline) {
    std::cout << "hello" << (newline ? '\n' : ' ');
}

Vector jacobiMethod(Matrix matrixA, Vector b) {
    // Construction of the matrixA and iteration vector x0
    Vector x(b.size());
    for (unsigned int i = 0; i < matrixA.size(); ++i) {
        double r = 1 / matrixA[i][i];
        for (unsigned int j = 0; j < matrixA.size(); ++j) {
            if (i != j) {
                matrixA[i][j] = matrixA[i][j] * r;
            }
        }
        b[i] = b[i] * r;
        // std::cout << "b[" << i <<"] : " << b[i];
        x[i] = b[i];      
    }
    Vector v(b.size());

    int k = 0;
    double norm = 0;
    do {
        ++k;
        for (unsigned int i = 0; i < x.size(); ++i) {
            double sum = 0;
            for (unsigned int j = 0; j < x.size(); ++j) {
                if (i != j) {
                    sum += (matrixA[i][j] * x[j]);
                }
            }
            v[i] = b[i] - sum;
            x[i] = v[i];
            // std::cout<<"v[i]: " << v[i] << '\n';
        }
        // double norm = norma(3, x, v);
        double norm = calculateNorm(x, v);
        printCurrentIteration(k, x, norm);
    } while (norm >= 0.0001 || k < 10);
    return x;
}

void printCurrentIteration(int iteration, Vector x, double norm) {
    std::cout << "|Iteration: " << iteration;
    std::cout << "|Values: ";
    printVector(x);
    std::cout << "|Norm: " << norm << '\n';
}

void printVector(Vector vector) {
    for (Vector::const_iterator i = vector.begin(); i != vector.end(); ++i) {
        std::cout << *i << ' ';
    }
}

void printMatrix(Matrix matrixA) {
    for (unsigned int i = 0; i < matrixA.size(); ++i) {
        for (unsigned int j = 0; i < matrixA.size(); ++i) {
            std::cout << matrixA[i][j] << ' ';
        }
        std::cout << '\n';
    }
}