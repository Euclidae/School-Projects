#include <iostream>
using namespace std;

int main(){
  int a;
  cout << "Input number for its factorial: ";
  cin >> a;
  int i = 1;
  int list[a] = {0};
  int j = 1;

  for (int b: list){
    i *= j;
    j++;
    cout << i << endl;
  }





  return 0;
}
