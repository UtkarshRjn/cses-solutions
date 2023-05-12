#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2e6+10;
const double eps = 1e-9;
const double pi = acos( -1 );
const int inf = 0x3f3f3f3f;

ll n, x, a;
vector<ll> v;
map<ll,ll> mymap;

void solve(){
	
    cin >> n >> x;
    vector<ll> pos;
    for(int i=0;i<n;i++){
        cin >> a;
        v.push_back(a);
        if(x%2 == 0 && a == x/2){
            pos.push_back(i);
        }
        mymap[a] = i;
    }

    if(pos.size() > 1) {
        cout << pos[0]+1 << ' ' << pos[1]+1 << endl;
        return;
    }

    for(int i=0;i<n;i++){
        if(mymap.find(x-v[i]) != mymap.end() && i != mymap[x-v[i]]){
            cout << i+1 << ' ' << mymap[x-v[i]]+1 << endl;
            return;
        }
    }
    
    cout << "IMPOSSIBLE" << endl;


}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;

}