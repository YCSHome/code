#include <iostream>
#include <fstream>

using namespace  std;

int main() {
  string a, b, c;
  cin >> a >> b >> c;
  system(string("g++ " + a + ".cpp -o a").c_str());
  system(string("g++ " + b + ".cpp -o b").c_str());
  system(string("g++ " + c + ".cpp -o random").c_str());
  while (1) {
    system("./random > input");
    system("./a < input > output1");
    system("./b < input > output2");
    string a, b;
    ifstream fina("output1"), finb("output2");
    fina >> a;
    finb >> b;
    if (a != b) {
      cout << "WRONG!" << endl;
      return -1;
    }
    cout << "TRUE " << a << endl;
  }
  return 0;
}
