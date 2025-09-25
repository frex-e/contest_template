#include <bits/stdc++.h>

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)

signed main() {

	string s; cin >> s;

	int n; cin >> n;

	// word, waiting_for_index
	vector<vector<pair<int,int>>> q(26);
	vector<string> words(n);
	REP(i,0,n) 
	{
		cin >> words[i];
		q[words[i][0]-'a'].push_back({i,0});
	}

	// cout << "A" << endl;

	int ans = 0;
	for(char c : s) {
		auto cur = q[c - 'a'];
		q[c - 'a'].clear();

		// cout << c << endl;

		for(auto [word, ind] : cur) {
			if (words[word].size() == ind + 1) ans++;
			else {
				q[words[word][ind + 1] - 'a'].push_back({word, ind + 1});
			}
		}
		// cout << "END" << endl;
	}
	cout << ans;
}
