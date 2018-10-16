#include <iostream>
#include <bitset>
#include <string>
#include <vector>
using namespace std;

vector<long> convert(string msg) {
  vector<long> result(0);
  string temp;
  for(unsigned int i = 0; i < msg.length(); i++) {
    if(i % 2 == 0) {
      temp = msg.substr(i, 2);
      result.push_back(stol(temp, NULL, 16));
    }
    else {}
  }
  return result;
}

vector<long> x_or(vector<long> m1, vector<long> m2) {
  vector<long> result(0);
  for(unsigned int i = 0; i < m1.size(); i++) {
    result.push_back((m1[i]^m2[i]));
  }
  return result;
}

void guessing(vector<long> g, vector<long> x) {
  for(unsigned int i = 0; i < x.size(); i++) {
    for(unsigned int j = 0; j < g.size(); j++) {
      if((i+j) < x.size()) {
        cout << (char)(x[i+j]^g[j]);
      }
    }
    cout << endl;
  }
  return;
}

int main() {
  string msg1 = "22bb58e06b30dddaea111e3cb9895ca4d76f2090a07c3796560101e2d53d9ce9a22151773d88b52faef54afb68776c8dd682cbe407420990107e3ef15de972f19f57bbd6ff977ca26be095e9ba474f3bcff266ef826968a10e77b6fca7f184b56b58c97d69f478c98f6af8d31acc0e6103ed7b4941e53bcab6669927349e39a402b4477bc662c118981d0fd7942f773a043913e4303e4d652935";
  string msg2 = "22bb58e06b30ddddf21d1e33b99056b5da212092ef7821d053050ae2d23a91f1e76e463801aeb52faef54afb68776c818689cbf34b500d8f507e28fc18ef33eb9b47ff9cb0ae33b73fb288adb25a4e2a82bc7ba0832169e40d60abe8aeb49da96b5bc23921ec74d7ca6ab99d10987c7d0ee17f4956b119c8b334862a";
  string guess = "54686520736563726574206973";
  vector<long> m1 = convert(msg1);
  vector<long> m2 = convert(msg2);
  vector<long> g = convert(guess);
  vector<long> x = x_or(m1, m2);
  guessing(g, x);
  return 0;
}