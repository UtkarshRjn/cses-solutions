#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2e6+10;
const double eps = 1e-9;
const double pi = acos( -1 );
const int inf = 0x3f3f3f3f;

ll n, a, b;
vector<pair<ll,ll>> at;

void solve(){
	
    cin >> n;
    while(n--){
        cin >> a >> b;
        at.push_back({a,0});
        at.push_back({b,1});
    }

    sort(at.begin(), at.end());
    ll count = 0;
    ll max_count = INT_MIN;
    for(int i=0;i<at.size();i++){
        count -= 2*at[i].second-1;
        max_count = max(max_count , count);
    }

    cout << max_count << endl;

}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;

}