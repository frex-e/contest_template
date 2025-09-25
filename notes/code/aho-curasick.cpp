
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define REP(i, a, b) for (int i = a; i < (b); ++i)
#define ALL(x) begin(x), end(x)
#define SZ(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Node {
	int par;
	char c;
	map<char, int> next;
	int link = -1;
	bool terminal = false;

	Node(int par, char c) : par(par), c(c) {}
};

vector<Node> nodes;

int new_node(int par, char c) {
	Node node = Node(par, c);
	nodes.push_back(node);
	return nodes.size() - 1;
}

int aho_curasick(const vector<string>& words) {
	// Root
	new_node(-1, '!');

	// Trie construction
	for (const auto& word : words) {
		int cur = 0;
		REP(i, 0, word.size()) {
			char c = word[i];
			if (nodes[cur].next.find(c) == nodes[cur].next.end()) {
				int nw = new_node(cur, c);
				nodes[cur].next[c] = nw;
			}
			cur = nodes[cur].next[c];
		}
		nodes[cur].terminal = true;
	}

	// Initialize root.
	deque<int> q;
	nodes[0].link = 0;
	for (char c = 'a'; c <= 'z'; c++) {
		if (nodes[0].next.find(c) == nodes[0].next.end()) {
			nodes[0].next[c] = 0;
		} else {
			q.push_back(nodes[0].next[c]);
		}
	}

	// BFS - initialise suffix links and failiure states.
	while (!q.empty()) {
		int i = q.front();
		q.pop_front();

		if (nodes[i].par == 0) {
			nodes[i].link = 0;
		} else {
			nodes[i].link = nodes[nodes[nodes[i].par].link].next[nodes[i].c];
		}

		for (char c = 'a'; c <= 'z'; c++) {
			if (nodes[i].next.find(c) == nodes[i].next.end()) {
				nodes[i].next[c] = nodes[nodes[i].link].next[c];
			} else {
				q.push_back(nodes[i].next[c]);
			}
		}
	}

	return 0;
}

signed main() {
	vector<string> words = {"a", "ab", "bc", "bca", "c", "caa"};

	aho_curasick(words);
	int i = 0;
	for(const auto& node : nodes) {
		cout << "NODE " << i << endl;
		cout << "LINK " << node.link << endl;
		for(const auto& [a,b] : node.next) {
			if (b != 0) {
				cout << a << " - " << b << endl;
			}
		}

		i++;
	}
}