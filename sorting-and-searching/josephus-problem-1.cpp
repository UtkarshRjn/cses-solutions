#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int N = 2e6+10;
const double eps = 1e-9;
const double pi = acos(-1);
const int inf = 0x3f3f3f3f;
 
ll n, x;
set<ll> v;
 
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        v.insert(i);
    }
 
    ll i = 0;
    vector<ll> ans;
    auto itr = v.begin();  // Initialize itr outside the loop
    while (!v.empty()) {
        if (i) cout << *itr << " ", itr = v.erase(itr);
        else ++itr;
 
        if (itr == v.end()) {
            itr = v.begin();
        }
 
        i = 1 - i;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}