#include <bits/stdc++.h>

using namespace std;

#define ll long long

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	ll total = 0;
	ll n; cin >> n;
	for(int i = 0; i < n; i++) {
		char c;
		ll a, b;
		 cin >> a >> c >> b;
		 total += a*100 + b;
	}

	ll a,b; char c;
	cin >> a >> c >> b;

	ll money = a*100 + b;

	
	// cout << "Total price: $" << (total / 100) << "." << format("{:02}",total % 100) << "\n";

	cout << "Total price: $" << (total / 100) << "." << (((total % 100) / 10) ? "" : "0") << total%100<< "\n";

	if (total%10 <= 4) total -= total % 10;
	else total += 10 - (total % 10);

	cout << "Rounded price: $" << (total / 100) << "." << (((total % 100) / 10) ? "" : "0") << total%100<< "\n";

	ll change = money - total;

	cout << "Change: $" << (change / 100) << "." << (((change % 100) / 10) ? "" : "0") << change%100<< "\n";
}