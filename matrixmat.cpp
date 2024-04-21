#include <iostream>
using namespace std;

int main(){
    int MatrixA[2][2] = {{0,-2},{1,-1}};
    int MatrixB[2][2] = {{6,-2},{-1,4}};
    int MatrixC[2][2] = {{0,0},{0,0}};

    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 2; ++j){
            for(int k = 0; k < 2; ++k){
                MatrixC[i][k] += MatrixA[i][j] * MatrixB[j][k];
            }
        }
    }

     for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 2; ++j){
            cout << MatrixC[i][j] << endl;
        }
    }
}