/**
 * Author: JeanBonbeur
 * Date: 27 brumaire an 234
 * License: CC0
 * Source: own work
 * Description: Self-explanatory methods for string hashing.
 * Status: tkt
 */
#pragma once

typedef Hash <998244353> rolling_hash;

template <ll MOD> struct Compact_Hash {
    vector <ll> h, p;
    
    Compact_Hash(string s, ll P) : h(sz(s) + 1), p(sz(s) + 1, 1) {
        rep(i, 0, sz(s)) {
            h[i + 1] = (h[i] * P + s[i]) % MOD;
            p[i + 1] = p[i] * P % MOD;
        }
    }
    
    ll hash_range(int l, int r) { //  returns hash of [l, r[
        return (h[r] - h[l] * p[r - l] % MOD + MOD) % MOD;
    }
    
    bool are_equal(int l1, int r1, int l2, int r2) {    // compares [l1, r1[ and [l2, r2[
        return hash_range(l1, r1) == hash_range(l2, r2);
    }
};
typedef Compact_Hash <998244353> compact_rolling_hash;