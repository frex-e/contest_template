#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define fr first
#define sc second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define int long long

struct Project {
	int student;
	ll time;
	ll priority;
	int req_mask = 0;

	bool operator<(const Project &other) const {
		return priority < other.priority;
	};
};

priority_queue<Project> qs[8];

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n; cin >> n;
	int a,b,c; cin >> a >> b >> c;

	vector<int> n_projects(n);
	rep(student, 0, n) cin >> n_projects[student];

	vector<deque<Project>> unavailable(n);

	rep(student,0,n) {
		rep(proj, 0, n_projects[student]) {
			ll time, priority; cin >> time >> priority;
			int req_mask = 0;
			if (!cin.eof()) cin >> ws;
			while(!cin.eof() and cin.peek() == 'C') {
				string req; cin >> req;
				if (req == "Camera") req_mask |= 1;
				else if (req == "Camcorder") req_mask |= 2;
				else req_mask |= 4;
			if (!cin.eof()) cin >> ws;
			}
			unavailable[student].pb({student, time, priority, req_mask});
		}
	}

	// for(auto &student : unavailable) {
	// 	for (auto project : student) {
	// 		cout << "( " << project.time << ", " << project.priority << ", " << bitset<3>(project.req_mask) << " ) ";
	// 	}
	// 	cout << endl;
	// }

	rep(student,0,n) {
		auto proj = unavailable[student].front();
		unavailable[student].pop_front();
		qs[proj.req_mask].push(proj);
	}
	vector<int> ans(n);

	// -Finishing time, student, mask
	priority_queue<tuple<ll,int,int>> finishing;
	ll cur_time = 0;
	for(;;) {
		// Start projects
		for(;;) {
			// prio, queue
			pair<ll,int> nxt = {-1,-1};
			int mask = 0;

			if (a > 0) mask |= 1;
			if (b > 0) mask |= 2;
			if (c > 0) mask |= 4;

			rep(i,0,8) {
				if (qs[i].empty() || ((~mask) & i) != 0) continue;
				nxt = max(nxt, {qs[i].top().priority, i});
			}
			if (nxt.fr == -1) break;
			auto &nxt_proj = qs[nxt.sc].top();

			if (nxt_proj.req_mask & 1) a--;
			if (nxt_proj.req_mask & 2) b--;
			if (nxt_proj.req_mask & 4) c--;

			finishing.push({-(cur_time + nxt_proj.time), nxt_proj.student, nxt_proj.req_mask});
			qs[nxt.sc].pop();
		}

		if (finishing.empty()) break;

		// Next finished projects.
		int nxt_time = -get<0>(finishing.top());
		while (!finishing.empty() and -get<0>(finishing.top()) == nxt_time) {
			auto [_, student, mask] = finishing.top();
			finishing.pop();

			if (mask & 1) a++;
			if (mask & 2) b++;
			if (mask & 4) c++;

			if (unavailable[student].empty()) ans[student] = nxt_time;
			else {
				auto proj = unavailable[student].front();
				unavailable[student].pop_front();
				qs[proj.req_mask].push(proj);
			}
		};
		
		cur_time = nxt_time;
	} 

	for(auto x : ans) cout << x << " ";
}