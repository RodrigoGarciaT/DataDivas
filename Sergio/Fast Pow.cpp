// Cacula a^b % mod

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9+7;

int main() {
    ll a, b;
    cin >> a >> b;
    ll res = 1;
    while (b > 0) {
        if (b & 1){
           res =  res * a % mod;
        }
        
        a = a * a % mod;
        b >>= 1;
    }
    cout << res << endl;
}
