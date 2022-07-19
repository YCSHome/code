#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> wCode;
string a, b;

int system(string str) {
#ifdef __linux__
  return system(str.c_str());
#else
  return system(str.c_str());
#endif
}

void copy(string a, string b) {
  string temp;
  ifstream fin(a);
  ofstream fout(b);
  getline(fin, temp, char(EOF));
  fout << temp;
}

int main() {
  string std, check, random;
  int l, r;
  cout << "输入数量:l - r" << endl;
  cin >> l >> r;
  cout << "输入 std 和 random(不需要.cpp)"  << endl;
  cin >> std >> random;
  cout << "不断输入错误代码用于检查数据可行性(不需要.cpp)" << endl;
  {
    string str;
    while (cin >> str) {
      wCode.push_back(str);
    }
  }
  {
    cout << "开始编译代码" << endl;
    if (system("g++ " + random + ".cpp -o random")||
        system("g++ " + std + ".cpp -o std")) {
      cout << "编译错误" << endl;
      return -1;
    }
    for (string& i : wCode) {
      if (system("g++ " + i + ".cpp -o " + i)) {
        cout << "编译错误" << endl;
        return -1;
      }
    }
  }
  {
    // 生成样例
    for (int i = l; i <= r; i++) {
      cout << "生成数据" << i << endl;
      string command;
      if (system("./random " + to_string(i) + " > input")) {
        cout << "RE...!!";
        return -1;
      }
      cout << "  生成完毕，获得正确答案" << endl;
      if (system("./std < input > answer")) {
        cout << "RE...!!" << endl;
        return -1;
      }
      string answer;
      ifstream fin("answer");
      getline(fin, answer, char(EOF));
      cout << "  现在正在获取错误代码的答案……" << endl;
      int tot = 0;
      for (string & str : wCode) {
        if(system("./" + str + " < input > output")) {
          cout << "RE...!!" << endl;
          i--;
          goto End;
        }
        ifstream fin("output");
        getline(fin, a, char(EOF));
        if (a == answer) {
          cout << "  在" + str + "中错误代码答案正确了！答案不予通过" << endl;
          i--;
          goto End;
        }
      }
      cout << "  完美数据!" << endl;
      copy("input", to_string(i) + ".in");
      copy("answer", to_string(i) + ".out");
End:
      cout << "";
    }
  }
  return 0;
}
