#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int a, b;
    cin >> a >> b;
    int og_a = a, og_b = b;
    while (b && a) {
        if (b > a && a != 0){
            b = b%a;
        }
        swap(a, b);
    }
    int gcd = max(a, b);
    ll lcm = (ll)og_a / gcd * (ll)og_b;
    cout << gcd << " " << lcm << endl;
}
