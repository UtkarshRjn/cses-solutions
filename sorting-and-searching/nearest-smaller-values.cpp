#include<bits/stdc++.h>
using namespace std;
	
typedef long long ll;
const int N = 2e5+1;
const double eps = 1e-9;
const double pi = acos( -1 );
const int inf = 0x3f3f3f3f;

void solve(){

	ll n; cin >> n;
    stack<pair<ll,ll>> st;

    for(int i=0;i<n;i++){
        ll x; cin>> x;

        while(!st.empty() && st.top().first >= x) st.pop();
        
        cout << ((st.empty()) ? 0 : st.top().second ) << " ";
        st.push({x,i+1});
    }
    cout << endl;

}

int main(){
	
	ll t;
	t = 1;
	while(t--) solve();
	
}