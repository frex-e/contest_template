#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define fr first
#define sc second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{

	default_random_engine engine((unsigned)2);

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;
		vector<int> vals;
		rep(i, 0, n) vals.pb(i + 1);
		shuffle(all(vals), engine);

		vector<int> stuff;
		rep(i, 0, 2 * n - 1) stuff.pb(i + 1);
		shuffle(all(vals), engine);

		vector<int> cur;
		int cnt = 0;

		for (auto val : vals)
		{
			cnt++;
			if (cnt == n)
			{
				cout << "! " << val << endl;
				break;
			}

			cur = stuff;
			while (sz(cur) > 1)
			{
				int n_cur = sz(cur);
				if (true)
				{

					vector<int> halfa, halfb;

					rep(i, 0, n_cur)
					{
						if (i < n_cur / 2)
							halfa.pb(cur[i]);
						else
							halfb.pb(cur[i]);
					}

					// First query
					cout << "? " << val << " " << sz(halfa) << " ";
					for (auto a : halfa)
						cout << a << " ";
					cout << endl;

					int in;
					cin >> in;
					if (in == -1)
						return 0;
					else if (in == 0)
					{
						cur = halfb;
						continue;
					}

					// second query
					cout << "? " << val << " " << sz(halfb) << " ";
					for (auto a : halfb)
						cout << a << " ";
					cout << endl;
					cin >> in;

					if (in == -1)
						return 0;
					else if (in == 0)
					{
						cur = halfa;
						continue;
					}
					else
					{
						cur.clear();
					}
				} else {
					vector<int> halfa, halfb, halfc;

					rep(i, 0, n_cur)
					{
						if (i % 3 == 1)
							halfa.pb(cur[i]);
						else if (i % 3 == 2)
							halfb.pb(cur[i]);
						else {
							halfc.pb(cur[i]);
						}
					}

					// First query
					cout << "? " << val << " " << sz(halfa) << " ";
					for (auto a : halfa)
						cout << a << " ";
					cout << endl;

					int in1;
					cin >> in1;

					if (in1 == -1)
						return 0;

					// second query
					cout << "? " << val << " " << sz(halfb) << " ";
					for (auto a : halfb)
						cout << a << " ";
					cout << endl;

					int in2;
					cin >> in2;

					if (in2 == -1)
						return 0;

					if (in1 == 0 and in2 == 0) { cur = halfc; continue; }
					if (in1 == 1 and in2 == 1) {cur.clear(); break; }

					// third query
					cout << "? " << val << " " << sz(halfc) << " ";
					for (auto a : halfc)
						cout << a << " ";
					cout << endl;

					int in3;
					cin >> in3;

					if (in3 == -1)
						return 0;
					if (in3) {cur.clear(); break; }
					if (in1) cur = halfa;
					else cur = halfb;
				}
			}
			if (sz(cur) == 1)
			{
				cout << "! " << val << endl;
				break;
			}
		}
	}
}