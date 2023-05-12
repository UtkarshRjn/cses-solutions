#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2e6+10;
const double eps = 1e-9;
const double pi = acos( -1 );
const int inf = 0x3f3f3f3f;

ll n, a, b;
vector<pair<ll,ll>> v;

void solve(){
	
    cin >> n;
    while(n--){
        cin >> a >> b;
        v.push_back({b,a});
    }

    sort(v.begin(), v.end());

    ll curr = v[0].first;
    ll cnt = 1;
    for(ll i=1;i<v.size();i++){
        if(v[i].second>=curr){
            // take this
            curr=v[i].first;
            cnt++;
        }
    }

    cout << cnt << endl;

}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;

}