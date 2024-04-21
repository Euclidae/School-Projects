#include <iostream>
using namespace std;
int main(){
    int fibonachi[10] = {1,1};

    for(int i = 2; i < 10; ++i){
      if(i == 2){
        cout << 1 << '\n' << 1 << endl;
      }
        fibonachi[i] = fibonachi[i-2] + fibonachi[i-1];
        cout << fibonachi[i] << endl;
        fibonachi[i-2] = fibonachi[i-1];
    }
}
