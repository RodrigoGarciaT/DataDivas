#include <bits/stdc++.h>
using namespace std;
#define ll long long

// primera implentacion coeficientes binomiales
int C(int n, int k) {
    int res = 1;
    for (int i = n - k + 1; i <= n; ++i)
        res *= i;
    for (int i = 2; i <= k; ++i)
        res /= i;
    return res;
}
//mejorada
int C(int n, int k) {
    double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (int)(res + 0.01);
}

//calcular coeficiente binomial precomputando los factoriales
const long long     MAXN = 100000, m =1e9+7;
ll factorial[MAXN+1];
//funcion inverse
int inv(int i) {
  return i <= 1 ? i : m - (long long)(m/i) * inv(m % i) % m;
}

void factoriales(){
    factorial[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        factorial[i] = factorial[i - 1] * i % m;
    }
}

long long binomial_coefficient(int n, int k) {
    return factorial[n] * inv(factorial[k] * factorial[n - k] % m) % m;
}

// se pueden sacar en o(1) si precomputamos los inversos
long long binomial_coefficient(int n, int k) {
    return factorial[n] * inverse_factorial[k] % m * inverse_factorial[n - k] % m;
}
int main() {
    // pascals triangle
    const int maxn = ...;
    int C[maxn + 1][maxn + 1];
    C[0][0] = 1;
    for (int n = 1; n <= maxn; ++n) {
        C[n][0] = C[n][n] = 1;
        for (int k = 1; k < n; ++k)
            C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
    }


}
