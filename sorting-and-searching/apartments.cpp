#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5+1;
const double eps = 1e-9;
const double pi = acos( -1 );
const int inf = 0x3f3f3f3f;

int main(){

	ll n,m,k,sum=0; cin >> n >> m >> k;
	vector<ll> people(n,0),app(m,0);
	for(ll i=0;i<n;i++) cin >> people[i];
	for(ll i=0;i<m;i++) cin >> app[i];
	sort(people.begin(),people.end());
	sort(app.begin(),app.end());
	ll i=0,j=0;
	while(i < n && j < m){
		if(people[i] <= app[j] + k && people[i] >= app[j] - k){
			i++;
			j++;
			sum++;
		}
		else if(people[i] > app[j] + k) j++;
		else i++;
	}
	cout << sum << endl;
}