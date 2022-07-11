#include <iostream>
#include <typeinfo>
#include <any>

using namespace std;

class Type {
private:
  string type = "NIL";
  any value;
public:
  template<class test>
    Type& operator=(const test& value_) {
      value = value_;
      if (typeid(value_) == typeid(int))                { type = "int";        }
      if (typeid(value_) == typeid(unsigned int))       { type = "uint";       }
      if (typeid(value_) == typeid(long long))          { type = "long long";  }
      if (typeid(value_) == typeid(unsigned long long)) { type = "ulong long"; }
      if (typeid(value_) == typeid(string))             { type = "string";     }
      if (typeid(value_) == typeid(double))             { type = "double";     }
      if (typeid(value_) == typeid(float))              { type = "float";      }
      return *this;
    }

  friend ostream& operator<<(ostream& out, Type& v) {
    if (v.type == "NIL")    { out << "NIL" << " "; }
    if (v.type == "long long")    { out << any_cast<long long>(v.value); }
    if (v.type == "unsigned long long")    { out << any_cast<unsigned long long>(v.value); }
    if (v.type == "float")    { out << any_cast<float>(v.value); }
    if (v.type == "string") { out << any_cast<string>(v.value); }
    if (v.type == "double")  { out << any_cast<double>(v.value); }
    return out;
  }
};

int main() {
  Type test;
  test = (unsigned long long)114514ull;
  cout << test << endl;
  test = "123321";
  cout << test << endl;
  test = 9182908901.19028901;
  cout << test << endl;
}
