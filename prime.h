#pragma once
#include "basic.h"

namespace prime {
    ll PRM;
    vector<ll> pm, phi, mp;
    void init(int n) {
        PRM = n++;
        pm.clear();
        phi.assign(n, 1);
        mp.assign(n, 0);
        for (int i = 2; i < n; ++i) {
            if (!mp[i]) {
                pm.push_back(i);
                mp[i] = i, phi[i] = i - 1;
            }
            for (int j = 0; j < pm.size() && i * pm[j] < n; ++j) {
                int p = pm[j];
                mp[i * p] = p;
                phi[i * p] = phi[i] * (p - !!(i % p));
                if (i % p == 0) break;
            }
        }
    }
    vector<ll> factorize(ll n) {
        vector<ll> u;
        for (auto &x : pm) {
            if (x * x <= n) {
                while (n % x == 0) {
                    u.push_back(x);
                    n /= x;
                }
            }
            else break;
        }
        if (n > 1) u.push_back(n);
        return u;
    }
    vector<PLL> factorize_pair(ll n) {
        vector<PLL> u;
        for (auto &x : pm) {
            if (x * x <= n) {
                if (n % x == 0) {
                    ll cnt = 0;
                    while (n % x == 0) {
                        cnt++;
                        n /= x;
                    }
                    u.emplace_back(PLL(x, cnt));
                }
            }
            else break;
        }
        if (n > 1) u.emplace_back(PLL(n, 1ll));
        return u;
    }
    bool miller_rabin(ll x) {
        // TODO
    }
    // return a factor(less than n) of n, ~O(n^0.25)
    // return n if n is prime or 1
    ll pollard_rho(ll n){
        if (n <= 3 || miller_rabin(n)) 
            return n;
        while (1) {
            int i = 1, cnt = 2;
            ll x = get_rand(n), y = x, c = get_rand(n);
            if (!c || c == n - 2)
                c++;
            do {
                ll u = gcd<ll>(n - x + y, n);
                if (u > 1 && u < n) 
                    return u;
                if (++i == cnt) 
                    y = x, cnt *= 2;
                x = (c + mul_large(x, x, n)) % n;
            } while(x != y);
        }
        return n;
    }
}