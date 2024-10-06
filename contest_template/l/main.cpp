#include <bits/stdc++.h>
#define int long long

using namespace std;

#define READ(...)                                                              \
  __VA_ARGS__;                                                                 \
  reader(__VA_ARGS__)

#define WRITE(...) writer(__VA_ARGS__)

using namespace std;

template <typename... Args>
void reader(Args&&... args) {
	(cin >> ... >> args);
}

template <typename... Args>
void writer(Args... args) {
	((cout << args << ' '), ...) << "\n";
}

signed main() {
	cin.tie(NULL)->sync_with_stdio(false);
}


