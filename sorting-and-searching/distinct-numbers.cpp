#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e6+10;
const double eps = 1e-9;
const double pi = acos( -1 );
const int inf = 0x3f3f3f3f;

int main(){
	ll n;cin >> n;
	ll a[200001];
	for(ll i=0;i<n;i++) cin >> a[i];
	sort(a,a+n);
	ll sum =1;
	for(ll i=1;i<n;i++){
		if(a[i] != a[i-1]) sum++;
	}
	cout << sum << endl;

}