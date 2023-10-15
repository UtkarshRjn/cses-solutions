#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int N = 2e6+10;
const double eps = 1e-9;
const double pi = acos( -1 );
const int inf = 0x3f3f3f3f;
 
ll n, x;
vector<ll> v;
map<ll,ll> mymap;

void solve(){
	
    ll n;cin >> n;
    vector<ll> v(n);

    for(auto &x: v) cin >> x;

    sort(v.begin(),v.end());

    ll CanForTill = 0;
    for(int i=0;i<n;i++){
        if(v[i] <= CanForTill+1) CanForTill += v[i];
        else{
            cout << CanForTill+1 << endl;
            return;
        }
    }

    cout << CanForTill + 1 << endl;

}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
 
}