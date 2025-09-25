#include <bits/stdc++.h>
#define int long long

using namespace std;

// const int NODES = 100;
// const int clusters = 5;
// const int cluster_size = 20;

const int clusters = 33;
const int NODES = clusters * 3 + 1;
// const int cluster_size = 5;


// const int n = cluster_size + 3;
// const int m = (n+ 5);
// int cur_m = 5*m;

int graph[NODES][NODES] = {};
int edge_count = 0;

void add_edge(int u, int v, int w) {
	if (graph[u][v] || graph[v][u]) { 
		cout << "ERROR, EDGE ADDED TWICE!\n";
		cout << u << " " << v << " " << graph[u][v] << "\n";
	}
	edge_count++;

	graph[u][v] = w;
	graph[v][u] = w;
}

int sz = 0;
int gen_node() {return sz++;}

int cur = 1000000;

// Returns end.
int gen_cluster(int start) {
	int a = gen_node();
	int b = gen_node();
	int c = gen_node();

	add_edge(start,a,cur - 1);
	add_edge(start,b,1);
	add_edge(a,b,1);
	cur /= 2;
	cur = max(cur,2LL);
	add_edge(b,c,cur);
	cur -= 1;
	cur = max(cur,2LL);
	add_edge(a,c,1);
	return c;
};

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	int cur = gen_node();
	for(int i = 0; i < clusters; i++) {
		cur = gen_cluster(cur);
	}

	cout << sz << " " << edge_count << "\n";

	for(int i = 0; i < sz; i++) {
		for(int j = i; j < sz; j++) {
			if (graph[i][j]) cout << i + 1 << " " << j + 1 << " " << graph[i][j] << "\n";
		}
	}
}