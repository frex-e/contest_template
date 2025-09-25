#include <bits/stdc++.h>

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)
#define ALL(x) begin(x), end(x)
#define SZ(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD = 1000000007;

vector<int> z_function(const string& s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

struct Node {
	int par;
	char c;
	map<char, int> next;
	int link = -1;

	Node(int par, char c) : par(par), c(c) {}
};
vector<Node> nodes;

int new_node(int par, char c) {
	Node node = Node(par,c);
	nodes.push_back(node);
	// cout << nodes.size() << endl;
	return nodes.size() - 1;
}

vector<vector<int>> mul(const vector<vector<int>>&a, const vector<vector<int>>&b) {
	int n = a.size();
	vector<vector<int>> res(n, vector<int>(n,0));

	REP(i,0,n) REP(j,0,n) REP(k,0,n) {
		res[i][j] += (a[i][k]*b[k][j]) % MOD;
		res[i][j] %= MOD;
	}

	return res;
}

vector<vector<int>> binary_expo(const vector<vector<int>>&a, int n) {
	if (n == 1) {
		return a;
	}

	const auto& half = binary_expo(a, n/2);
	const auto& most = mul(half,half);
	if (n%2) {
		return mul(most,a);
	} else {
		return most;
	}
}

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int n,k; cin >> n >> k;

	new_node(0, 'c');
	nodes[0].link = 0;


	vector<string> words;
	REP(i,0,n) {
		string s; cin >> s;
		words.push_back(s);
	}

	vector<bool> keep(n, true);
	REP(i,0,n) {
		REP(j, 0, n) {
			string a = words[i];
			string b = words[j];
			if (i == j) continue;
			if (a.size() > b.size()) continue;
			if (a.size() == b.size()) {
				if (i > j) continue;
				if (a == b) 
				keep[j] = false;
				continue;
			}

			string s = a;
			s.append(b);
			auto z = z_function(s);
			REP(k,a.size(),s.size()) {
				if (z[k] >= a.size()) keep[j] = false;
			}
		}
	}

	vector<string> new_s;
	REP(i,0,n) {
		if (keep[i]) {
			new_s.push_back(words[i]);
		}
	}

	words = new_s;

	vector<pii> depths;

	for(const auto& word : words) {
		int cur = 0;
		REP(i,0,word.size() - 1) {
			char c = word[i];
			if (nodes[cur].next.find(c) == nodes[cur].next.end()) {
				int nw = new_node(cur,c);
				nodes[cur].next[c] = nw;
				depths.push_back({i, nw});
			}
			cur = nodes[cur].next[c];
		}

		nodes[cur].next[word.back()] = -1;
	}

	for(char c = 'a'; c <= 'z'; c++) {
		if (nodes[0].next.find(c) == nodes[0].next.end()) {
			nodes[0].next[c] = 0;
		}
	}

	sort(depths.begin(), depths.end());
	for(const auto& [_, i] : depths) {
		if (nodes[i].par == 0) {
			nodes[i].link = 0;
		} else {
			nodes[i].link = nodes[nodes[nodes[i].par].link].next[nodes[i].c];
		}

		for(char c = 'a'; c <= 'z'; c++) {
			if (nodes[i].next.find(c) == nodes[i].next.end()) {
				nodes[i].next[c] = nodes[nodes[i].link].next[c];
			}
		}
	}


	int m_size = nodes.size();
	vector<vector<int>> m(m_size, vector<int>(m_size,0));


	REP(i,0,m_size) {
		for(char c = 'a'; c <= 'z'; c++) {
			if (nodes[i].next[c] != 0) {
			}
			if (nodes[i].next[c] != -1) {
				m[i][nodes[i].next[c]]++;
			}
		}
	}

	const auto b = binary_expo(m,k);
	int ans = 0;
	REP(i,0,m_size) {
		ans += b[0][i];
		ans %= MOD;
	}
	cout << ans;
}