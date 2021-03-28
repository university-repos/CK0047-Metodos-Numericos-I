#include <cmath>
#include <iostream>
#include <vector>

typedef std::vector<double> Vector;

typedef std::vector<std::vector<double>> Matrix;
void printVector(Vector vector);
void printCurrentIteration(int iteration, Vector iter_vector, double norm);
void printMatrix(Matrix matrix);

double calculateNorm(Vector current, Vector next) {
    double norm_num = 0;
    double norm_den = 0;
    for (unsigned int i = 0; i < current.size(); ++i) {
        double temp_num = abs(next[i] - current[i]);
        double temp_den = abs(next[i]);
        if (temp_num > norm_num) norm_num = temp_num;
        if (temp_den > norm_den) norm_den = temp_den;
        current[i] = next[i];
    }
    double norm = norm_num / norm_den;
    return norm;
}

void sayHello(bool newline) {
    std::cout << "hello" << (newline ? '\n' : ' ');
}

Vector jacobiMethod(Matrix matrix, Vector identity) {
    // Construction of the matrix and iteration vector x0
    Vector iter_vector(identity.size());
    // printVector(iter_vector);
    for (unsigned int i = 0; i < matrix.size(); ++i) {
        double x_coefficient = 1 / matrix[i][i];
        for (unsigned int j = 0; j < matrix.size(); ++j) {
            if (i != j) {
                matrix[i][j] =  matrix[i][j] * x_coefficient;
            }
        }
        identity[i] =  identity[i] * x_coefficient;  // b[i] *= r
        iter_vector[i] = identity[i];  // x[i] = b[i]
    }
    printVector(iter_vector);
    Vector next_iter_vector(identity.size());
    std::cout << "Matrix size: " << matrix.size() << '\n';
    // std::cout << "Identity size: " << identity.size() << '\n';
    std::cout << "Iter vector size: " << iter_vector.size() << '\n';
    // std::cout << "Next Iter vector size: " << next_iter_vector.size() << '\n';
    int currentIter = 0;
    do {
        ++currentIter;
        for (unsigned int i = 0; i < iter_vector.size(); ++i) {
            double sum = 0;
            for (unsigned int j = 0; j < iter_vector.size(); ++j) {
                if (i != j) {
                    sum += (matrix[i][j] * iter_vector[j]);
                    std::cout << "Doing sum -> Matrix[" << i << "][" << j << "]: " << matrix[i][j] <<  "||" << "Iter_vector[" << j << "]: " << iter_vector[j] << " - "; 
                    std::cout<<"sum: " << sum << ' ' << '\n';
                }
            }
            std::cout << '\n';
            std::cout << "Identity: " << identity[i] << "\n";
            std::cout << "Iter Vector: " << iter_vector[i] << "\n";
            std::cout << "Sum: " << sum << "\n";
            next_iter_vector[i] = identity[i] - sum;
            
            // std::cout << "for loop: " << next_iter_vector[i] << '\n';
        }
        // printVector(iter_vector);
        // printVector(next_iter_vector);
        double norm = calculateNorm(iter_vector, next_iter_vector);
        printCurrentIteration(currentIter, iter_vector, norm);
        // iter_vector.assign(next_iter_vector.begin(), next_iter_vector.end());

        // for (unsigned int i = 0; i < iter_vector.size(); ++i) {
        //     iter_vector[i] = next_iter_vector[i];
        // }
    } while (currentIter < 10 /*norm > precision || currentIter < maxIter*/);
    return iter_vector;
}

void printCurrentIteration(int iteration, Vector iter_vector, double norm) {
    std::cout << "|Iteration: " << iteration;
    std::cout << "|Values: ";
    printVector(iter_vector);
    std::cout << "|Norm: " << norm << '\n';
}

void printVector(Vector vector) {
    for (Vector::const_iterator i = vector.begin(); i != vector.end(); ++i) {
        std::cout << *i << ' ';
    }
}

void printMatrix(Matrix matrix) {
    for (unsigned int i = 0; i < matrix.size(); ++i) {
        for (unsigned int j = 0; i < matrix.size(); ++i) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
}