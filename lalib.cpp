#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef vector<vl> mat;

mat createMat(int n, int m) {
    mat matrix(n, vl(m));
    for(auto i = 0; i<n; i++) 
        for(auto j = 0; j<m; j++) {
            matrix[i][j] = rand()%100;
            if(rand()%2 == 0) matrix[i][j]*=-1;
        }
    return matrix;
}

vl multMatVec(mat matrix, vl vec) {
    vl product(matrix.size());
    for(auto i = 0; i<matrix.size(); i++) 
        for(auto j = 0; j<matrix[i].size();j++) 
             product[i] += (matrix[i][j] * vec[j]);
    return product;
}

ll multVecVec(vl vec1, vl vec2) {
    ll product = 0;
    for(int i = 0; i < vec1.size(); i++) 
        product += vec1[i]*vec2[i];
    return product;
}

vl getColumn(mat matrix, int col) {
    vl mat_col(matrix.size()); 
    for(int i = 0; i < matrix.size(); i++)
        mat_col[i] = (matrix[i][col]);
    return mat_col;
}

mat multMatMat(mat matrix1, mat matrix2) {
    mat product(matrix1.size(), vl(matrix2[0].size()));
    for(int i = 0; i < product.size(); i++) {
        for(int j = 0; j < product[i].size(); j++) {
            vl col = getColumn(matrix2, j);
            product[i][j] = multVecVec(matrix1[i], col);
        }
    }
    return product;
}

void printMatrix(mat matrix) {
    for(auto i = 0; i<matrix.size(); i++){
        for(auto j = 0; j<matrix[i].size(); j++) 
            cout << matrix[i][j] << " ";
        cout << "\n";    
    }
}
int main() {
    mat matrix = createMat(2, 3);
    printMatrix(matrix);
    cout << endl;
    mat matrix2 = createMat(3,2);
    printMatrix(matrix2);
    cout << endl;
    mat product = multMatMat(matrix, matrix2);
    printMatrix(product);
    return 0; 
}
