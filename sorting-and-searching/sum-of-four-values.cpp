#include<bits/stdc++.h>
using namespace std;
	
typedef long long ll;
const int N = 2e5+1;
const double eps = 1e-9;
const double pi = acos( -1 );
const int inf = 0x3f3f3f3f;
	
void solve(){

	ll n, x; cin >> n >> x;
	vector<pair<ll,ll>> a(n);

	for(int i=0;i<n;i++){
		ll e; cin >> e;
		a[i] = {e,i+1};
	}
	map<ll,set<pair<ll,ll>>> m;

	sort(a.begin(),a.end());

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(m.find(x - a[i].first - a[j].first) != m.end()){
				
				
				auto st = m[x-a[i].first-a[j].first];
				for(auto p: st){
					if(i!=p.first && j!=p.first && i != p.second && j!= p.second){
						cout << a[p.first].second << " " << a[p.second].second << " " << a[i].second << " " << a[j].second  << endl;
						return;
					}
				}
				
				m[a[i].first+a[j].first].insert(make_pair(i,j));
			}else {
				m[a[i].first + a[j].first] = {make_pair(i,j)};
			}
		}
	}

	cout << "IMPOSSIBLE" << endl;

}

int main(){
	
	ll t;
	t = 1;
	while(t--) solve();
	
}