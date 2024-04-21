#include <iostream>
using namespace std;

int main(){
  int fibo1 = 0, fibo2 = 1, fiboN = fibo1 + fibo2;
  for (int i = 0; i < 10; ++i ){
    if (i==0){
      cout << 0 << endl << 1 << endl;
    }
    cout << fiboN << endl;
    fibo1 = fibo2;
    fibo2 = fiboN;
    fiboN = fibo1 + fibo2;

  }

  return 0;
}
