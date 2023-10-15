#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> ppll;

void solve() {

    ll n; cin >> n;
    multiset<pll> m;
    vector<ll> ans(n);
    ll Max = LLONG_MIN;

    vector<ppll> input;
    for(ll i=0;i<n;i++){
        ll x,y;cin >> x >> y;
        input.push_back(make_pair(make_pair(x,y),i));
    }

    sort(input.begin(),input.end());

    m.insert(make_pair(input[0].first.second,1));
    ans[input[0].second] = 1;
    for(ll i=1;i<n;i++){
        ll x = input[i].first.first;
        ll y = input[i].first.second;
        ll idx = input[i].second;
        auto itr = *m.begin();
        if(x <= itr.first) {
            m.insert(make_pair(y, (ll)m.size() + 1ll));
            ans[idx] = m.size();
        }else{
            ll id = itr.second;
            ans[idx] = id;
            m.erase(itr); // o(logn)
            m.insert(make_pair(y,id)); // o(logn)
        }

        Max = max(Max, (ll)m.size());
    }

    cout << Max << endl;
    for(auto e: ans) cout << e << " ";
    cout << endl;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}