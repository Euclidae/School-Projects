#include <iostream>
using namespace std;

int main(){
  int userInput;
  cin >> userInput;


  for (int i = 1, c = 1; i <= userInput; i++){
    c *= i;
    cout << c << endl;
  }

  return 0;
}
