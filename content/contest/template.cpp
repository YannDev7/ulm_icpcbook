#include <bits/stdc++.h>
#define int long long
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define rep(i, a, b) for (int i = a; i < b; i ++)
using namespace std;

string to_string(string s) { return s; }
string to_string(bool b) { return b ? "YES" : "NO"; }
string to_string(char c) { return (string)"" + c; }
template <typename T> string to_string(T v);

template <typename T, typename Q> string to_string(pair <T, Q> v) {
    return "(" + to_string(v.first) + ", " + to_string(v.second) + ")";
}

template <typename T, typename Q> string to_string(pair <T*, Q> v) {
    string s = "[";
    for (int f = 0, i = 0; i < v.second; i ++)
        s += (f ++ ? ", " : "") + to_string(v.first[i]);
    return s + "]";
}

template <typename T> string to_string(T v) {
    string s = "[";
    for (int f = 0; const auto &x : v)
        s += (f ++ ? ", " : "") + to_string(x);
    return s + "]";
}

void dbg_out() { cout << endl; }
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
    cout << to_string(H) << ' ';
    dbg_out(T...);
}

#ifdef DEBUG
// #define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#define dbg(...) dbg_out((string)"(" + #__VA_ARGS__ + "):", __VA_ARGS__)
#else
#define dbg(...)
#endif

//  Premier Empire

//  <|._.|>

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}