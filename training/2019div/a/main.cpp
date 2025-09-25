#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	string s;

	map<char, map<int,int>> mp;

	while(getline(cin,s)) {
		char a = s[0];
		string index;
		int i = 2;

		while(s[i] != '.') {
			index.push_back(s[i++]);
		}

		while(s[i] != '=') i++;
		i += 2;

		string num;
		while(i < s.size()) {
			num.push_back(s[i++]);
		}
		mp[a][stoi(index)] += stoi(num);
	}
	for(auto &[a,b] : mp) {
		cout << a << "\n";
		for(auto &[c,d] : b) {
			if (d != 0) cout << d << "\n";
		}
	}
}