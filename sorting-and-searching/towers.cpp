#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int N = 2e6+10;
const double eps = 1e-9;
const double pi = acos( -1 );
const int inf = 0x3f3f3f3f;
 
ll n, x;
vector<pair<ll,ll>> at;
multiset<ll> myml;
 
void solve(){
	
    cin >> n;
    while(n--){
        cin >> x;
        if(myml.upper_bound(x) != myml.end()){
            myml.erase(myml.upper_bound(x));
            myml.insert(x);
        }else{
            myml.insert(x);
        }
    }
 
    cout << myml.size() << endl;
}
 
int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
 
}