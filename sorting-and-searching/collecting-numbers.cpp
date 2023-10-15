#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int N = 2e6+10;
const double eps = 1e-9;
const double pi = acos( -1 );
const int inf = 0x3f3f3f3f;
 
void solve(){
	
    ll n; cin >> n;
    vector<ll> v(n);
    
    set<ll> s;
    for(auto &x: v) {
        cin >> x;
        if(s.find(x) == s.end()){
            s.insert(x+1);
        }else{
            s.erase(x);
            s.insert(x+1);
        }
    }

    cout << s.size() << endl;

}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
 
}