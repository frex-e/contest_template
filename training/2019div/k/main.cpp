#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

struct Node {
	vector<tuple<int,int,Node*>> nxt;

	Node* get_nxt(int i) {
		auto it = find_if(nxt.begin(), nxt.end(), [&](const tuple<int,int,Node*>& a){return get<0>(a) == i;});
		if (it != nxt.end()) { 
			get<1>(*it)++; 
			return get<2>(*it);
		}
		else {
			nxt.push_back({i,1,new Node()});
			return get<2>(nxt.back());
		}
	}

	pair<int,Node*> max(int i) {
		auto [a,b,c] = *max_element(nxt.begin(),nxt.end(), [&](tuple<int,int,Node*> a, tuple<int,int,Node*> b){
			if (get<0>(a) == i & get<1>(a) == 1) return true;
			if (get<0>(b) == i & get<1>(b) == 1) return false;

			return (get<0>(a) + i) % 10 < (get<0>(b) + i) % 10;
		});
		return {a,c};
	}
};

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n; cin >> n;

	Node* root = new Node();

	vector<string> arr;
	rep(i,0,n) {
		string s; cin >> s;
		// cout << s << endl;
		reverse(s.begin(), s.end());
		while(s.size() < 19) {
			s.push_back('0');
		}
		reverse(s.begin(), s.end());
		arr.push_back(s);
		auto cur = root;

		for(auto c : s) {
			cur = cur->get_nxt(c - '0');
		}
	}


	ll best = 0;
	for(auto& s : arr) {
		ll cur_num = 0;
		auto cur = root;

		for(auto c : s) {
			auto [digit, nxt] = cur->max(c - '0');
			// cout << digit << endl;
			cur_num *= 10;
			cur_num += (digit + (c - '0')) % 10;
			cur = nxt;
		}

		best = max(best,cur_num);
	}
	cout << best;
}