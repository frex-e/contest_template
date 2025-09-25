#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	vector<vector<int>> arr(10, vector<int>(10));

	rep(i,0,10) {
		rep(j,0,10) {
			cin >> arr[i][j];
		}
	}

	reverse(arr.begin(),arr.end());

	for(int i = 1; i < 10; i += 2) {
		reverse(arr[i].begin(),arr[i].end());
	}

	vector<int> line(100);
	rep(i,0,10) {
		rep(j,0,10) {
			line[i * 10 + j] = arr[i][j];
		}
	}

	// for(auto i  : line) {
	// 	cout << i << " ";
	// }
	// cout << endl;

	int n_cards; cin >> n_cards;
	vector<int> cards(n_cards);

	rep(i,0,n_cards) {
		cin >> cards[i];
	}

	int cur_player = 0;
	int positions[4] = {};
	bool skips[4] = {};
	int winners = 0;

	for(auto card : cards) {
		if (winners == 4) break;
		while(skips[cur_player] || positions[cur_player] >= 100) {
			skips[cur_player] = false;
			cur_player = (cur_player + 1) % 4;
		}

		positions[cur_player] += card;

		if (positions[cur_player] >= 100) {
			winners++;
			cur_player = (cur_player + 1) % 4;
			continue;
		};

		int effect = line[positions[cur_player]];
		if (effect == -1) skips[cur_player] = true;
		else if (effect > 0) positions[cur_player] = effect - 1;
		cur_player = (cur_player + 1) % 4;
	}

	rep(i,0,4) {
		cout << min(positions[i] + 1, 101) << " ";
	}
}