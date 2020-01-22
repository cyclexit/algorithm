/* 
 * author: cyclexit
 * start from: 2020-01-21 20:48:53
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  // index: 0 to n - 1
  vector<vector<int>> man(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> man[i][j];
    }
  }
  vector<vector<int>> woman(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> woman[i][j];
    }
  }
  vector<int> man_res(n, -1);
  vector<int> woman_res(n, -1);
  queue<int> q; // men are not matched
  for (int i = 0; i < n; ++i) {
    q.push(i);
  }
  vector<int> man_choice(n, 0); // man's choice index
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    int w = man[cur][man_choice[cur]];
    if (woman_res[w] == -1) {
      man_res[cur] = w;
      woman_res[w] = cur;
    } else {
      int other = woman_res[w];
      int index_cur = -1, index_other = -1;
      for (int i = 0; i < n; ++i) {
        if (woman[w][i] == cur) index_cur = i;
        if (woman[w][i] == other) index_other = i;
      }
      if (index_other < index_cur) {
        q.push(cur);
        ++man_choice[cur];
      } else {
        man_res[cur] = w;
        woman_res[w] = cur;
        ++man_choice[other];
        q.push(other);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << "man: " << i << " " << "woman: " << man_res[i] << '\n';
  }
  return 0;
}