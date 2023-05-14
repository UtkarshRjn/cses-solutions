#include <iostream>
#include <set>
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2e6+10;
const double eps = 1e-9;
const double pi = acos(-1);
const int inf = 0x3f3f3f3f;

ll x, n, p;
multiset<ll> diff;
multiset<ll> v;

void solve() {
    cin >> x >> n;
    v.insert(0);
    v.insert(x);
    diff.insert(x);

    while (n--) {
        cin >> p;
        auto itr = v.lower_bound(p);
        ll p2 = *itr;
        ll p1 = *(--itr);
        diff.erase(diff.find(p2 - p1));
        diff.insert(p2 - p);
        diff.insert(p - p1);
        v.insert(p);

        ll max_diff = *diff.rbegin();
        cout << max_diff << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
