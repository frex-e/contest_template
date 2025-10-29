#include <bits/stdc++.h>

#define rep(i,a,b) for(int i = a; i < (b); i++)
typedef long long ll;

using namespace std;


signed main() {
  cin.tie(0)->sync_with_stdio(0);

  // int n; cin >> n;
  
  vector<pair<int, string>> friends;
  map<string,int> mp;

  // string cur_name; cin >> cur_name;
  // cur_name.pop_back();
  // mp[cur_name];

  int k =0;
      string line;

      getline(cin, line);

  while(    getline(cin, line)
) {
    // cout << line << endl;
    string name;
    int i = 0;
    while(line[i] != ':') {
      name.push_back(line[i++]);
    }
    i++;
    int cnt = 0;
    while(i + 2 < line.size()) {
      if (line[i] == 'A' and line[i + 1] == 'd' and line[i + 2] == 'a') cnt++;
      i++;
    }
    mp[name] += cnt;
    k++;
  }
  for(auto [cur_name, cnt] : mp) {
      friends.push_back({-cnt, cur_name});
    // cout << cur_name << " " << cnt << endl;
  }

  sort(friends.begin(), friends.end());
  for(auto [_, name] : friends) cout << name << "\n";
}