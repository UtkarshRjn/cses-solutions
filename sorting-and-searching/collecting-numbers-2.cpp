#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int N = 2e6+10;
const double eps = 1e-9;
const double pi = acos( -1 );
const int inf = 0x3f3f3f3f;
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

const ll SZ = 2e5 + 5;

void solve(){
	
    ll n,m; cin >> n >> m;
    ll v[n];
    
    set<ll> s; // markers
    ll index[SZ] = {0};
    int i=0;
    for(auto &x: v) {
        cin >> x;
        index[x] = i;
        if(s.find(x-1) == s.end()){
            s.insert(x);
        }else{
            s.erase(x-1);
            s.insert(x);
        }
        i++;
    }

    while(m--){
        ll i,j; cin >> i >> j;

        if(i == j){
            cout << s.size() << endl;
            continue;
        }
        
        if(i > j) swap(i,j);

        ll a = v[i-1], b = v[j-1];
        index[a] = j-1;
        index[b] = i-1;
        swap(v[i-1],v[j-1]);

        ll ha = *s.lower_bound(a); // log(n)
        ll hb = *s.lower_bound(b);  // log(n)

        // remove a,b
        if(a == ha)  s.erase(ha);
        if(a != 1 && a != b+1) s.insert(a-1);

        if(b == hb) s.erase(hb);
        if(b != 1 && b != a+1) s.insert(b-1);

        // Insert a,b
        if(b > 1 && index[b-1] < i-1)   s.erase(b-1);
        if(index[b+1] <= i-1) s.insert(b);

        if(a > 1 && index[a-1] < j-1)   s.erase(a-1);
        if(index[a+1] <= j-1) s.insert(a);

        cout << s.size() << endl;

    }

}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
 
}