#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

bool adj[9][9];

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n = 9;
	map<string,int> mp;
	vector<string> words;

	rep(i,0,n) {
		string a; cin >> a;
		mp[a] = i;
		words.push_back(a);
	}


	int m; cin >> m;

	rep(i,0,m) {
		string a,b; cin >> a >> b;
		int u = mp[a], v = mp[b];
		adj[u][v] = true;
		adj[v][u] = true;
	}

	// rep(i,0,9) {
	// 	rep(j,0,9) {
	// 		cout << adj[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	vector<int> arr(9);
	rep(i,0,9) arr[i] = i;

	// cout << "A" << endl;

	vector<pair<int,int>> related_pairs = {{0,1},{1,2},{2,0},{3,4},{4,5},{5,3},{6,7},{7,8},{8,6}};

	int i = 0;
	do {
		bool valid = true;
		for(auto [i,j] : related_pairs) if (!adj[arr[i]][arr[j]]) valid = false;

		if (valid) {
			cout << "POSSIBLE\n";
			cout << words[arr[0]] << " " << words[arr[1]] <<" " << words[arr[2]] << "\n";
			cout << words[arr[3]] << " " << words[arr[4]] <<" " << words[arr[5]] << "\n";
			cout << words[arr[6]] << " " << words[arr[7]] <<" " << words[arr[8]] << "\n";
			return 0;
		}

	} while (next_permutation(arr.begin(), arr.end()));
	cout << "IMPOSSIBLE";
	return 0;
}