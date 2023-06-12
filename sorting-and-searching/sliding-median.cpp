#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2e6+10;
const double eps = 1e-9;
const double pi = acos( -1 );
const int inf = 0x3f3f3f3f;

void solve(){
	
    ll n, k; cin >> n >> k;
    vector<ll> v(n);

    for(auto& x: v) cin >> x;

    if(n < k) return;

    multiset<ll> low, high;
    multiset<ll> window;
    ll t = (k+1)/2;

    for(ll i=0;i<n;i++){
        if(i<k-1)  window.insert(v[i]);
        else if(i == (k-1)){
            window.insert(v[i]);

            ll j = 0;
            for(auto elem: window) {
                if(j < t) low.insert(elem);
                else high.insert(elem);
                j++;
            }

            cout << *(--low.end()) << " ";
        }else{

            if(v[i] > *(--low.end())) high.insert(v[i]);
            else low.insert(v[i]);

            if(v[i-k] > *(--low.end())) high.erase(high.find(v[i-k]));
            else low.erase(low.find(v[i-k]));


            while(low.size()!=t && high.size()!=k-t){
                if(low.size() < t){
                    low.insert(*high.begin());
                    high.erase(high.begin());
                }else{
                    high.insert(*(--low.end()));
                    low.erase((--low.end()));
                }
            }

            cout << *(--low.end()) << " ";

        }
    }

    cout << endl;

}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;

}