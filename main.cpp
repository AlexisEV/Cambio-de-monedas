#include <iostream>
#include <vector>
#include <cmath>
void DevolverCambio(int& P, std::vector<int>& C, std::vector<int>& X){
  int actual = 0;
  int j = C.size()-1;
  while(actual != P){
    while(C[j]>(P-actual) && (j>=0)){
      j = j-1;
    }
    if(j<0){
      throw std::runtime_error("No hay solución");
    }
    X[j] = std::floor((P-actual)/C[j]);
    actual = actual + C[j]*X[j];
  }
}

int main() {
  std::vector<int> c = {1,2,5,10,20,50,100,200};
  std::vector<int> x(c.size(),0);
  int p = 389;
  DevolverCambio(p, c, x);
  
  float p_f = p/100.0;
  std::cout<<"Para devolver " << p_f << " euros se necesitan:\n\n";
  for(int i = c.size()-1; i>=0;i--){
    float moneda = c[i]/100.0;
    std::cout<<x[i]<<" monedas de " <<moneda<< " euros\n"; 
  }
}