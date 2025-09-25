#include <bits/stdc++.h>

using namespace std;

const int MAXN = 4000005;

string s;
int n;

struct Node {
    int l, r, par, link;
    map<char,int> next;

    Node (int l=0, int r=0, int par=-1)
        : l(l), r(r), par(par), link(-1) {}
    int len()  {  return r - l;  }
    int &get (char c) {
        if (!next.count(c))  next[c] = -1;
        return next[c];
    }
};
Node t[MAXN];
int sz;

struct State {
    int v, pos;
    State (int v, int pos) : v(v), pos(pos)  {}
};
State ptr (0, 0);

State go (State st, int l, int r) {
    while (l < r)
        if (st.pos == t[st.v].len()) {
            st = State (t[st.v].get( s[l] ), 0);
            if (st.v == -1)  return st;
        }
        else {
            if (s[ t[st.v].l + st.pos ] != s[l])
                return State (-1, -1);
            if (r-l < t[st.v].len() - st.pos)
                return State (st.v, st.pos + r-l);
            l += t[st.v].len() - st.pos;
            st.pos = t[st.v].len();
        }
    return st;
}

int split (State st) {
    if (st.pos == t[st.v].len())
        return st.v;
    if (st.pos == 0)
        return t[st.v].par;
    Node v = t[st.v];
    int id = sz++;
    t[id] = Node (v.l, v.l+st.pos, v.par);
    t[v.par].get( s[v.l] ) = id;
    t[id].get( s[v.l+st.pos] ) = st.v;
    t[st.v].par = id;
    t[st.v].l += st.pos;
    return id;
}

int get_link (int v) {
    if (t[v].link != -1)  return t[v].link;
    if (t[v].par == -1)  return 0;
    int to = get_link (t[v].par);
    return t[v].link = split (go (State(to,t[to].len()), t[v].l + (t[v].par==0), t[v].r));
}

void tree_extend (int pos) {
    for(;;) {
        State nptr = go (ptr, pos, pos+1);
        if (nptr.v != -1) {
            ptr = nptr;
            return;
        }

        int mid = split (ptr);
        int leaf = sz++;
        t[leaf] = Node (pos, n, mid);
        t[mid].get( s[pos] ) = leaf;

        ptr.v = get_link (mid);
        ptr.pos = t[ptr.v].len();
        if (!mid)  break;
    }
}

void build_tree() {
    sz = 1;
    for (int i=0; i<n; ++i)
        tree_extend (i);
}

long long get_memory_usage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return usage.ru_maxrss; // Maximum resident set size (in kilobytes on Linux, bytes on macOS)
}

int n_words;
int par[6000005];
int uf_size[6000005];

int get_set(int u) {
	// cout << "GET " << u << endl;
	if (par[u] == u) return u;
	return par[u] = get_set(par[u]);
}

bool join(int u, int v)  {
	// cout << "JOINING " << u << " " << v << endl;

	u = get_set(u);
	v = get_set(v);

	if (u == v) return false;

	if (uf_size[v] > uf_size[u]) swap(u,v);
	par[v] = u;
	uf_size[u] += uf_size[v];

	return true;
}

int get_indx(int u) {return u + n_words;}
vector<int> index_to_word;
vector<int> distance_to_dollar;
vector<tuple<int,int,int>> stuff;
vector<tuple<int,int,int,bool>> stck;

void dfs() {
	while (!stck.empty()) {
		auto [cur, depth_to_dollar, depth, hit_dollar] = stck.back();
		stck.pop_back();
		// cout << "A" << endl;
		Node &cur_node = t[cur];
		depth += cur_node.r - cur_node.l;

		if (!hit_dollar) {
			if (index_to_word[cur_node.l] != index_to_word[cur_node.r]) {
				hit_dollar = true;
				depth_to_dollar += distance_to_dollar[cur_node.l];
			} else {
				depth_to_dollar = depth;
			}
		}
		// cout << "C" << endl;

		if (cur_node.next.empty()) {
			// cout << "JOINING " << index_to_word[s.size() - depth] << " " << get_indx(cur) << endl;
			// cout << s[s.size() - depth] << endl;
			// cout << "B" << endl;
			join(index_to_word[s.size() - depth], get_indx(cur));
		} else {
			stuff.push_back({-depth_to_dollar, -depth, cur});
			// cout << "D" << endl;
			for(auto const& [a,b] : cur_node.next) {
				// cout << "E" << endl;
				// cout << b << " " << depth_to_dollar << " " << depth << " " << hit_dollar << endl;
				stck.push_back({b,depth_to_dollar,depth,hit_dollar});
			}
		}
	}
}

const int nnn = 2000000/4;
const int words = 2;

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	n_words = words;

	for(int i = 0; i < 6000005; i++) {
		par[i] = i;
	}

	for(int i = 0; i < n_words; i++) {
		string s_in;
		for(int j = 0; j < nnn/words; j++) {
			s_in.push_back('a');
		}
		for(int j = 0; j < s_in.size(); j++) {
			index_to_word.push_back(i);
			distance_to_dollar.push_back(s_in.size() - j);
		}
		distance_to_dollar.push_back(0);
		index_to_word.push_back(-1);
		s.append(s_in);
        s.push_back('$');
	}
	distance_to_dollar.push_back(0);
	index_to_word.push_back(-2);
    s.push_back('$');

	if (n_words == 1) {
		cout << "0";
		return 0;
	}

	// cout << s << endl;;

	n = s.size();
	// cout << n << endl;

	build_tree();

	for(auto const& [a,b] : t[0].next) if (a != '$') {
		stck.push_back({b,0,0,false});
		dfs();
	}

	// cout << "DDD" << endl;

	sort(stuff.begin(),stuff.end());
	// cout << stuff.size() << "\n";

	int to_join = n_words - 1;
	long long ans = 0;

	for(auto const& [depth_to_dollar,_,node] : stuff) {
		// cout << depth_to_dollar << "\n";
		to_join += 1;
		ans += depth_to_dollar;

		for(auto const& [_,nxt] : t[node].next) {
			bool joined = join(get_indx(nxt), get_indx(node));
			to_join -= joined;
			ans -= depth_to_dollar*joined;
		}

		if (to_join == 0) break;
	}

	cout << ans << "\n";

	cout << get_memory_usage()/(1024 * 1024) << endl;
}


