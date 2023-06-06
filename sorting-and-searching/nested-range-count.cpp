#include <bits/stdtr1c++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
typedef long long ll;
// typedef tree<ll, null_type, 
//              less_equal<ll>, rb_tree_tag, 
//              tree_order_statistics_node_update> 
//     ordered_set;

#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>

#define ordered_set_rev tree<ll, null_type, greater_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>

using namespace std;

bool customCompare(const pair<ll,ll>& a, const pair<ll,ll>& b){

    if(a.first != b.first){
        return a.first < b.first;
    }else{
        return a.second > b.second;
    }

}

void solve() {

    ll n; cin >> n;
    vector<pair<ll,ll>> v;
    map<pair<ll,ll>,ll> m;

    for(int i=0;i<n;i++){
        ll a,b; cin >> a >> b;
        v.push_back({a,b});
        m[{a,b}] = i;
    }

    sort(v.begin(),v.end(), customCompare);

    vector<ll> in(n,0), out(n,0);

    ordered_set_rev endTimes2;
    for(int i=n-1;i>=0;i--){ // O(n)
        ll cnt = endTimes2.size() - endTimes2.order_of_key(v[i].second); // O(log n)
        in[m[{v[i]}]] += cnt;
        endTimes2.insert(v[i].second);
    }

    ordered_set endTimes;
    for(int i=0;i<n;i++){ // O(n)
        ll cnt = endTimes.size() - endTimes.order_of_key(v[i].second); // O(log n)
        out[m[{v[i]}]] += cnt;
        endTimes.insert(v[i].second);
    }

    for(auto e:in) cout << e << " ";
    cout << endl;

    for(auto e:out) cout << e << " ";
    cout << endl;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}