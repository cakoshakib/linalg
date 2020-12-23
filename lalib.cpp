#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef vector<vl> mat;

mat createMat(int n, int m) {
    mat matrix(n, vl(m));
    for(auto i = 0; i<n; i++) {
        for(auto j = 0; j<m; j++) {
            matrix[i][j] = rand()%100;
            if(rand()%2 == 0) matrix[i][j]*=-1;
        }
    }
    return matrix;
}

vl multMatrix(mat matrix, vl vec) {
    vl product(2);
    for(auto i = 0; i<matrix.size(); i++) {
        for(auto j = 0; j<matrix[i].size();j++) {
             product[i] += (matrix[i][j] * vec[j]);
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
    mat matrix = createMat(2, 2);
    printMatrix(matrix);
    vl vec = {1, 2}; 
    vl product = multMatrix(matrix, vec);
    for(auto x : product) cout << x << " "; 
    return 0; 
}
