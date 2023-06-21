#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

ll gcd(ll a, ll b) {
    return b ? gcd (b, a % b) : a;
}

ll gcd (ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll lcm (ll a, ll b) {
    return a / gcd(a, b) * b;
}

//binary gcd ya no usa modulos, es mas rapido
ll gcd(ll a, ll b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}

int main() {
	// built-in gcd
    int a,b;
    cin>>a>>b;
	__gcd(a,b);
}
