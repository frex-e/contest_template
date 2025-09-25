#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n; cin >> n;
	int players = 1 << n;

	int games = players - 1;

	set<int> cur_players;
	vector<set<int>> matchups(players);

	bool failed = false;

	rep(i,0,players) cur_players.insert(i);

	rep(i,0,games) {
		int a,b; cin >> a >> b;
		a--; b--;
		if (matchups[a].find(b) != matchups[a].end()) {
			failed = true;
		}
		if (matchups[b].find(a) != matchups[b].end()) {
			failed = true;
		}

		matchups[a].insert(b);
		matchups[b].insert(a);
	}


	while(!failed and cur_players.size() > 2) {
		set<int> to_die;
		set<int> vs_die;

		// {loser, winner}
		vector<pair<int,int>> current_matches;

		// Losing this round.
		for(auto player : cur_players) {
			if (matchups[player].size() == 1) {
				int opp = *matchups[player].begin();
				vs_die.insert(opp);
				to_die.insert(player);
				current_matches.push_back({player, opp});
			}
		}

		if (to_die.size() != vs_die.size() || to_die.size() + vs_die.size() != cur_players.size()) failed = true;

		for(auto [loser, winner] : current_matches) {
			cur_players.erase(loser);
			matchups[winner].erase(loser);
		}
	}

	if (cur_players.size() != 2) failed = true;

	if (failed){
		cout << "MISTAKE\n";
	} else {
		cout << "OK\n";
	}
}
