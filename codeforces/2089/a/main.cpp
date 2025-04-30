#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100005;

vector<bool> primes(MAX,true);

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);

	primes[0] = false;
	primes[1] = false;

	for(int i = 2; i*i < MAX + 5 ; i++) {
		if (!primes[i]) continue;

		int j = 2*i;
		while (j < MAX) { 
			primes[j] = false;
			j += i;
		}
	}

	int t; cin >> t;

	while(t--) {
		int n; cin >> n;
		
		int half = n/2;
		int half_up = half + 1;

		int start;

		while (true) {
			if (primes[half]) {
				start = half;
				break;
			} else if (primes[half_up]) {
				start = half_up;
				break;
				
			} else{
				half -= 1;
				half_up += 1;
			}
		}

		int start_down = start - 1;

		while (true) {
			if (start <= n) {
				cout << start << " ";
				start++;
			} else {
				break;
			}

			if (start_down >= 1) {
				cout << start_down << " ";
				start_down--;
			} else {
				break;
			}
		}

		while (start_down >= 1) {
			cout << start_down << " ";
			start_down--;
		}

		while (start <= n) {
			cout << start << " ";
			start++;
		}
	}

}


