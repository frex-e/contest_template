#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n,m; cin >> n >> m;

	vector<int> key_in_chest(m);
	vector<vector<int>> key_to_chests(n);
	vector<set<int>> required_keys(m);

	set<int> unused_keys;

	rep(i,0,n) unused_keys.insert(i);

	rep(i,0,m) {
		int key; cin >> key;

		key--;
		unused_keys.erase(key);
		key_in_chest[i] = key;

		int n_keys; cin >> n_keys;

		rep(j,0,n_keys) {
			int rkey; cin >> rkey;
			rkey--;
			key_to_chests[rkey].push_back(i);
			required_keys[i].insert(rkey);
		}
	}


	queue<int> q;

	auto req_keys2 = required_keys;

	if (unused_keys.find(n - 1) != unused_keys.end()) {
		cout << '0'; return 0;
	}

	for(auto key : unused_keys) {
		for(auto chest : key_to_chests[key]) {
			if (required_keys[chest].size() == 0) continue;
			required_keys[chest].erase(key);
			if (required_keys[chest].size() == 0) q.push(chest);
		}
	}

	vector<bool> vis_keys(n, false);
	vector<int> order;
	while(!q.empty()) {
		int cur_chest = q.front();
		q.pop();
		int cur_key = key_in_chest[cur_chest];
		if (vis_keys[cur_key]) continue;
		// cout << cur_chest << " " << cur_key << endl;
		vis_keys[cur_key] = true;
		order.push_back(cur_chest);
		if (cur_key == n - 1) break;
		for(auto nxt_chest : key_to_chests[cur_key]) {
			if (required_keys[nxt_chest].size() == 0) continue;
			required_keys[nxt_chest].erase(cur_key);
			if (required_keys[nxt_chest].size() == 0) q.push(nxt_chest);
		}
	}

	if (!vis_keys[n - 1]) {
		cout << "-1";
		return 0;
	}

	// for(auto a : order) cout << a << " ";
	// cout << endl;

	int k = order.size();

	set<int> need_keys = {n - 1};
	vector<int> ans;

	rep(i,0,k) {
		int cur_chest = order[k - i - 1];
		int cur_key = key_in_chest[cur_chest];
		bool found_key = false;

		if (need_keys.find(cur_key) == need_keys.end()) continue;
		for(auto needed_key : req_keys2[cur_chest]) need_keys.insert(needed_key);
		ans.push_back(cur_chest);
	}

	cout << ans.size() << '\n';
	rep(i,0,ans.size()) cout << ans[ans.size() - i - 1] + 1 << " ";
}
