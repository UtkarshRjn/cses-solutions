#include <iostream>
using namespace std;

// Header files, namespaces,
// macros as defined above
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

typedef long long ll;

void solve() {

    ll n,k; cin >> n >> k;
    ordered_set v;
    for (int i = 1; i <= n; i++) {
        v.insert(i);
    }

    ll i = 0;
    vector<ll> ans;
    auto itr = v.begin();
    while (!v.empty()) {
        i=(i+k)%(int)v.size();
		cout<<*(v.find_by_order(i))<<' ';
		v.erase(*(v.find_by_order(i)));
		if(v.size()) i%=(int)v.size();
    }
    cout << endl;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}