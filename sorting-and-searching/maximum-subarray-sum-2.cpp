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

    ll n, a, b; cin >> n >> a >> b;
    vector<pair<ll,ll>> v;

    ll sum = 0;
    for(ll i=0;i<n;i++){
        ll x; cin >> x;
        sum += x;
        v.push_back({x,i});
    }

    sort(v.begin(),v.end());

    ll i=0;
    ll j=n-1;

    while(true){

        if(v[j].second - v[i].second > a && v[j].second - v[i].second < b){
            cout << v[j].first - v[j].second << endl;
            return;
        }

        if(j==0){
            i++;
            continue;
        }else if(i==n-1){
            j--;
            continue;
        }else if(i==n-1 && j==0){
            // cout << 
        }

        if(v[j-1].first - v[i].first > v[j].first - v[i-1].first) j--;
        else i++;

    }


    

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}