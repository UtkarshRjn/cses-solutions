#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2e6+10;
const double eps = 1e-9;
const double pi = acos( -1 );
const int inf = 0x3f3f3f3f;

ll n, a, b;
map<ll,ll> freq;
vector<ll> v;

void solve(){
	
    cin >> n;
    v.resize(n);
    ll cnt = 0;
    ll max_cnt = LLONG_MIN;
    ll j = 0;
    ll i = 0;
    for(auto &x:v){
        cin >> x;
        if(freq.find(x) == freq.end() || freq[x]==0){
            freq[x] = 1;
            cnt++;
        }else{
            while(v[j] != x){
                freq[v[j]] = 0;
                j++;
            }
            cnt = i - j;
            j++;
        }
        i++;
        max_cnt = max(max_cnt, cnt);
    }

    cout << max_cnt << endl;


}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;

}