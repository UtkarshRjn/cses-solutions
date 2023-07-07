#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <climits>
#include <iomanip>
#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <list>
#include <bitset>
#include <cassert>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

typedef long long ll;
const int N = 2e5+10;
const double eps = 1e-9;
const int mod = 1e9+7;
const double pi = acos( -1 );
const int inf = 0x3f3f3f3f;

namespace __gnu_pbds{
          typedef tree<int,
                       null_type,
                       less_equal<int>,
                       rb_tree_tag,
                       tree_order_statistics_node_update> ordered_set;
}
using namespace __gnu_pbds;
#define deb(x) cout << #x << " " << x << endl;

template<typename... T>
void read(T&... args){
	((cin >> args), ...);
}

bool lexo_inc(string a, string b) {
	return a < b;
}

bool lexo_dec(string a, string b){
	return a > b;
}

bool isP(int ni, int nj, ll n ,ll m){

	if(ni<0 || nj <0 || ni>=n || nj>=m) return false;
	else return true;

}

void solve(){

    ll n; cin >> n;
    vector<ll> v(n);
    map<ll,ll> m;

    ll Max = 0;
    for(int i=0;i<n;i++){
        cin >> v[i];
        if(m.lower_bound(v[i]) == m.end()){
            Max++;
            m[v[i]] = Max;
        }else{
            auto it = m.lower_bound(v[i]);
            auto t = *it;
            if(t.first > v[i]){
                m[v[i]] = t.second;
                m.erase(t.first);
            }
        }
    }

    cout << Max << endl;

}

int main(){
	solve();
}