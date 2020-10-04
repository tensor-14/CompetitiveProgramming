#include<iostream>
#include<typeinfo>
using namespace std;

int main() {

  cout << "Noice" << '\n';
  int a{2}, b{3};
  auto c{a+b};
  for (int i=0; i!=10; ++i)
    cout << static_cast<char>('0'+i)<<endl;
  //cout<<typeid(c).name()<<endl;
  //c = a+b;
  cout << c << '\n';
  /* code */
  return 0;
}
