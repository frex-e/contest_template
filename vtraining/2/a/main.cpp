#include <bits/stdc++.h>

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)
#define ALL(x) begin(x), end(x)
#define SZ(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;

signed main() {
	// cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		char trump; cin >> trump;

		map<char,vector<int>> all_cards;

		REP(i,0,2*n) {
			int a; cin >> a;
			char suit; cin >> suit;
			all_cards[suit].push_back(a);
		}

		for(auto &[suit, cards] : all_cards) {
			// cout << suit << " " << cards.size() << endl;
			sort(cards.begin(), cards.end());
		}


		int odd_offsuit = 0;
		vector<pair<char,int>> off_suits;
		for(auto &[suit, cards] : all_cards) {
			if (suit == trump) continue;
			if (cards.size() % 2 == 1) {
				odd_offsuit += 1;
				int card = cards.back();
				cards.pop_back();
				off_suits.push_back({suit,card});
			}
		}

		// cout << odd_offsuit << " " << all_cards[trump].size() << endl;

		if (all_cards[trump].size() >= odd_offsuit and (all_cards[trump].size() - odd_offsuit) % 2 == 0) {
			for(auto& card : off_suits) {
				int other = all_cards[trump].back();
				all_cards[trump].pop_back();
				cout << card.second << card.first << " " << other << trump << "\n";
			}

			for(auto &[suit, cards] : all_cards) {
				for(int i = 0; i < cards.size(); i += 2) {
					cout  << cards[i] << suit << " " << cards[i + 1] << suit << "\n";
				}
			}
		} else {
			cout << "IMPOSSIBLE\n";
		}
	}
}