#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll m = 1e9+7;

// Calculates inverse mod of any number. 
// If you need to divide with mod, take inverse and mutiply
ll inv(ll i) {
  return i <= 1 ? i : m - (long long)(m/i) * inv(m % i) % m;
}

int main() {
  // b / a is...
  ll a = 36271;
  ll res = inv(a);
  cout << res % m << endl;
    
}
