#include <bits/stdtr1c++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
typedef long long ll;

#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>

#define ordered_set_rev tree<ll, null_type, greater_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>

using namespace std;

void solve() {

    ll n, k; cin >> n >> k;
    vector<pair<ll,pair<ll,ll>>> v;

    for(int i=0;i<n;i++){
        ll a,b; cin >> a >> b;
        v.push_back({i+1, {a,b}});
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}