#pragma once
#include<bits/stdc++.h>
using namespace std;

typedef __int128 i128;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef pair<ull, ull> PUU;

const int mod = 1e9 + 7;
const int MM = 1e9 + 7;

ll pw(ll p, ll q) {
    p %= MM;
    ll ret = 1;
    for (; q; q >>= 1) {
        if (q & 1) ret = ret * p % MM;
        p = p * p % MM;
    }
    return ret;
}

double pw(double p, ll q) {
    double ret = 1;
    for (; q; q >>= 1) {
        if (q & 1) ret = ret * p;
        p = p * p;
    }
    return ret;
}

ll pw(ll p, ll q, ll mod) {
    p %= mod;
    ll ret = 1;
    for (; q; q >>= 1) {
        if (q & 1) ret = ret * p % mod;
        p = p * p % mod;
    }
    return ret;
}

ll pow_large(__int128 p, ll q, ll mod) {
    p %= mod;
    __int128 ret = 1;
    for (; q; q >>= 1) {
        if (q & 1) ret = ret * p % mod;
        p = p * p % mod;
    }
    return (ll)ret;
}

ll mul_large(ll p, ll q, ll mod) {
	return (__int128)p * q % mod;
}

template <typename T>
void maxi(T& x, T y) {
    x = max(x, y);
}

template <typename T>
void mini(T& x, T y) {
    x = min(x, y);
}

template <typename T>
T gcd(T p, T q) {
    return q ? gcd(q, p % q) : p;
}

ll euler_phi(ll n) {
    ll ret = n;
    for (ll i = 2; i * i <= n; ++i) 
        if (n % i == 0) {
            ret = ret / i * (i - 1);
            while (n % i == 0) 
                n /= i;
        }
    if (n > 1) 
        ret = ret / n * (n - 1);
    return ret;
}

template <typename T>
T sqr(T x) {
    return x * x;
}

ll get_rand(ll n) {
	// TODO
	return rand() % n;
}