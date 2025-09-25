#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)

const ll MAX = 10000000000000000LL;

ll md(ll n, ll k) {return ((n % k) + k) % k; }

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int t; cin >> t;
	while(t--) {
		ll n,k; cin >> n >> k;
		vector<ll> positions(n), delays(n);
		map<ll,set<ll>> clss[2];
		REP(i,0,n) cin >> positions[i];
		REP(i,0,n) cin >> delays[i];

		REP(i,0,n) {
			int rcls = (((delays[i] - positions[i]) % k) + k) % k;
			clss[true][rcls].insert(positions[i]);
			int lcls = (delays[i] - (MAX - positions[i])) % k;
			lcls = (lcls + k) % k;
			clss[false][lcls].insert(positions[i]);
		}
		
		// left = false, right = true
		// {dir, position, time % k} -> 1 = pending, 2 = free, 3 = stuck
		map<tuple<bool,ll,ll>,ll> cache;
		auto f = [&](const auto& self, bool dir, ll pos, ll time) {
			// cout << dir << " " << pos << " " << time << endl;
			// TODO try reference.
			ll& cur_state = cache[{dir,pos,time}];
			if (cur_state == 1) return (cur_state = 3);
			else if (cur_state != 0) return cur_state;
			cur_state = 1;

			// Right
			if(dir) {
				ll cls = md(time - pos, k);
				// cout << "RIGHT " << cls << endl;
				auto it = clss[dir][cls].upper_bound(pos);
				if (it == clss[dir][cls].end()) return cur_state = 2;
				ll nw_pos = *it;
				return cur_state = self(self, !dir, nw_pos, md(time + abs(nw_pos - pos), k));
			// left
			} else {
				ll cls = md(time - (MAX - pos),k);
				// cout << "LEFT " << cls << endl;
				auto it = clss[dir][cls].lower_bound(pos);
				if (it == clss[dir][cls].begin()) return cur_state = 2;
				it--;
				ll nw_pos = *it;
				return cur_state = self(self, !dir, nw_pos, md(time + abs(nw_pos - pos), k));
			}
		};

		ll q; cin >> q;
		REP(i,0,q) {
			ll a; cin >> a;
			cout << ((f(f, true, a - 1, k - 1) == 2) ? "YES" : "NO") << "\n";
		}
	}
}