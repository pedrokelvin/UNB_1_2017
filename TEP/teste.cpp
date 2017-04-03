#include <iostream>

using namespace std;

int main(){

  string nome1 = "Pedro";
  auto nome2 = nome1;

  if(&nome1 == &nome2)
    cout << "Sei la" << endl;
    
  return 0;
}
