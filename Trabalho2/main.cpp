#include <iostream>
#include <vector>
#include "tentadenovo.cpp"


int main() {
    Matrix matrix = {{5, 3, 1}, {5, 6, 1}, {1, 6, 7}};
    Matrix vector = {{1}, {0}, {0}};
    Vector newvector = {1, 0, 0};
    // sayHello(false);
    // sayHello(false);
    // Matrix result = jacobiMethod(matrix, vector);
    // printMatrix(result);
    Vector result = jacobiMethod(matrix, newvector);
    printVector(result);
}