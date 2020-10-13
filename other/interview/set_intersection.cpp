/*
 * author: cyclexit
 * start from: 2020-10-13 12:52
 */
#include <bits/stdc++.h>

using namespace std;

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(const char* cstr) {
  return (string) cstr;
}

string to_string(string str) {
  return str;
}

template<typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template<typename T>
string to_string(const T& v) {
  string res = "[";
  bool first = true;
  for (const auto& x : v) {
    if (!first) res += ", ";
    first = false;
    res += to_string(x);
  }
  res += "]";
  return res;
}

void debug() {cerr << endl;}

template<typename Head, typename... Tail>
void debug(Head H, Tail... T) {
  cerr << to_string(H) << " ";
  debug(T...);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> v1(n);
  for (int i = 0; i < n; ++i) {
    cin >> v1[i];
  }
  vector<int> v2(m);
  for (int i = 0; i < m; ++i) {
    cin >> v2[i];
  }
  sort(v1.begin(), v1.end());
  debug(v1);
  sort(v2.begin(), v2.end());
  debug(v2);
  vector<int> intersection;
  for (int i = 0, j = 0; i < v1.size() && j < v2.size(); ) {
    if (v1[i] == v2[j]) {
      intersection.push_back(v1[i]);
      ++i;
      ++j;
    } else if (v1[i] > v2[j]) {
      ++j;
    } else if (v1[i] < v2[j]) {
      ++i;
    }
  }
  for (int x : intersection) {
    cout << x << ' ';
  }
  cout << '\n';
  return 0;
}