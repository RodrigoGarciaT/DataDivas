#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define optimiza_io \
    cin.tie(0);     \
    ios_base::sync_with_stdio(0);


const ll MAXN = 1e6;
const ll m = 1e9+7;
ll factorial[MAXN+1];

ll inv(ll i) {
  return i <= 1 ? i : m - (long long)(m/i) * inv(m % i) % m;
}

ll binomial_coefficient(ll n, ll k) {
    return factorial[n] * inv(factorial[k] * factorial[n - k] % m) % m;
}

int main() {
	optimiza_io
	
	factorial[0] = 1;
	for (int i = 1; i <= MAXN; i++) {
		factorial[i] = factorial[i - 1] * i % m;
	}

	int t; cin >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;
		ll res = binomial_coefficient(n, k);
		cout << res << endl;
	}
}

/*
Fast but size is trouble sometimes
double res = 1;
for (int i = 1; i <= k; ++i)
	res = res * (n - k + i) / i;
return (int)(res + 0.01);



For any one in O(1) but has to be n < 10e5
// For any C[n][k] (n choose k)
const ll maxn = 1e4;
ll C[maxn + 1][maxn + 1];
C[0][0] = 1;
for (ll n = 1; n <= maxn; ++n) {
	C[n][0] = C[n][n] = 1;
	for (ll k = 1; k < n; ++k)
		C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
}
*/
