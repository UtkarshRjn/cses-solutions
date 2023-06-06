#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Header files, namespaces,
// macros as defined above
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

typedef long long ll;

void solve() {

    ll n; cin >> n;
    multiset<pair<ll,ll>> m;
    vector<ll> ans;
    ll Max = LLONG_MIN;

    vector<pair<ll,ll>> input;
    for(int i=0;i<n;i++){
        ll x,y;cin >> x >> y;
        input.push_back({x,y});
    }

    sort(input.begin(),input.end());

    m.insert({input[0].second,1});
    ans.push_back(1);
    for(ll i=1;i<n;i++){
        ll x = input[i].first;
        ll y = input[i].second;
        auto itr = *m.begin();
        if(x <= itr.first) {
            m.insert({y, m.size() + 1});
            ans.push_back(m.size());
        }else{
            ll id = itr.second;
            ans.push_back(id);
            m.erase(itr); // o(logn)
            m.insert({y,id}); // o(logn)
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