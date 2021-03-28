#include <cmath>
#include <iostream>
#include <vector>

typedef std::vector<double> Vector;

typedef std::vector<std::vector<double>> Matrix;

void printCurrentIteration(int iteration, Matrix iteration_vector, double norm);
void printMatrix(Matrix matrix);

double calculateNorm(Matrix current, Matrix next) {
    double norm_num = 0;
    double norm_den = 0;
    for (unsigned int i = 0; i < current.size(); ++i) {
        double temp_num = abs(next[i][0] - current[i][0]);
        double temp_den = abs(next[i][0]);
        if (temp_num > norm_num) norm_num = temp_num;
        if (temp_den > norm_den) norm_den = temp_den;
    }
    double norm = norm_num / norm_den;
    return norm;
}

void sayHello(bool newline) {
    std::cout << "hello" << (newline ? '\n' : ' ');
}

Matrix jacobiMethod(Matrix matrix, Matrix identity_vector) {
    // Construction of the matrix and iteration vector x0
    Matrix iteration_vector(matrix.size(), Vector(1));
    for (unsigned int i = 0; i < matrix.size(); ++i) {
        double x_coefficient = 1 / matrix[i][i];
        for (unsigned int j = 0; j < matrix.size(); ++j) {
            if (i != j) {
                matrix[i][j] *= x_coefficient;
            }
        }
        identity_vector[i][0] *= x_coefficient;          // b[i] *= r
        iteration_vector[i][0] = identity_vector[i][0];  // x[i] = b[i]
    }
    printMatrix(iteration_vector);
    // return iteration_vector;
    int currentIter = 0;
    Matrix next_iteration_vector(matrix.size(), Vector(1));
    do {
        currentIter++;
        for (unsigned int i = 0; i < matrix.size(); ++i) {
            int sum = 0;
            for (unsigned int j = 0; j < matrix.size(); ++j) {
                sum += (matrix[i][j] * iteration_vector[j][0]);
            }
            next_iteration_vector[i][0] = identity_vector[i][0] - sum;
        }
        double norm = calculateNorm(iteration_vector, next_iteration_vector);
        printCurrentIteration(currentIter, iteration_vector, norm);
        for (unsigned int i = 0; i < iteration_vector.size(); ++i) {
            iteration_vector[i][0] = next_iteration_vector[i][0];
        }
    } while (currentIter < 10 /*norm > precision || currentIter < maxIter*/);
    return next_iteration_vector;
}

void printCurrentIteration(int iteration, Matrix iteration_vector, double norm) {
    std::cout << "|Iteration: " << iteration;
    std::cout << "|Values: ";
    printMatrix(iteration_vector);
    std::cout << "|Norm: " << norm;
}

void printMatrix(Matrix matrix) {
    for (unsigned int i = 0; i < matrix.size(); ++i) {
        for (unsigned int j = 0; i < matrix.size(); ++i) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
}