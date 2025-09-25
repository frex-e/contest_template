#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	ll hid, mih; cin >> hid >> mih;

	ll he,me; cin >> he >> me;

	ll first_contact_earth = he*60 + me;

	ll ht, mt; cin >> ht >> mt;
	ll first_contact_tat = ht * mih + mt;

	ll d,m,h; cin >> d >> h >> m;

	ll tat_minutes = (((24 * d) + h)*60 + m) - first_contact_earth + first_contact_tat;

	ll mid = hid * mih;
	cout << tat_minutes / mid << " ";
	tat_minutes %= mid;

	cout << tat_minutes / mih << " ";
	tat_minutes %= mih;

	cout << tat_minutes;
}