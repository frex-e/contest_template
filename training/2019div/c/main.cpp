#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	vector<string> words;
	set<string> sorted_words;
	map<string, int> word_to_i;

	REP(i,0,16) {
		string s; cin >> s;
		words.push_back(s);
		sorted_words.insert(s);
	}

	int i = 0;
	for(auto s : sorted_words) {
		// cout << s << endl;
		word_to_i[s] = i++;
	}

	int assasin = 0;
	int blue_mask = 0;
	int red_mask = 0;

	REP(i,0,16) {
		char a; cin >> a;
		int index = word_to_i[words[i]];
		if (a == 'A') assasin = index;
		else if (a == 'B') blue_mask |= 1 << index;
		else if(a == 'R') red_mask |= 1 << index;
	}

	int hints; cin >> hints;
	vector<int> hint_masks;

	REP(i,0,hints) {
		int hint_mask = 0;
		string _; cin >> _;
		int n; cin >> n;

		REP(j,0,n) {
			string word; cin >> word;
			hint_mask |= 1 << word_to_i[word];
		}

		hint_masks.push_back(hint_mask);
	}

	vector<bool> dp((1 << 17) + 5);

	for(int i = 0; i < (1 << 17); i++) {
		bool turn = i & 1;
		int unflipped_mask = i >> 1;
		if (~unflipped_mask & (1 << assasin)) continue;
		if ((unflipped_mask & blue_mask) == 0) continue;
		if ((unflipped_mask & red_mask) == 0) continue;

		int goal_mask;
		int not_goal;

		if (turn) {
			goal_mask = blue_mask;
			not_goal = red_mask;
		} else {
			goal_mask = red_mask;
			not_goal = blue_mask;
		}

		bool winner = false;

		for(auto hint : hint_masks) {
			if ((hint & unflipped_mask) == 0) continue;

			if (~goal_mask & hint & unflipped_mask) {
				hint &= (1 << (__builtin_ctz(~goal_mask & hint & unflipped_mask) + 1)) - 1;
			}

			int flipped = hint & unflipped_mask;
			int nw_unflipped = flipped ^ unflipped_mask;

			if ((nw_unflipped & goal_mask) == 0) {
				winner = true;
				continue;
			}

			if (flipped & (1 << assasin)) continue;
			if ((nw_unflipped & not_goal) == 0) continue;
			winner |= (dp[(nw_unflipped << 1) + !turn] == turn);
		}

		dp[i] = (winner == turn);
		// cout << dp[i] << " " << bitset<17>(i) << endl;
	}

	if (dp[(1 << 17) - 1]) {
		cout << "Alice";
	} else {
		cout << "Bob";
	}
}

// unflipped
// 110011
// to_flip
// 010101
