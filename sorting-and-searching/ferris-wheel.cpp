#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5+10;
const double eps = 1e-9;
const double pi = acos( -1 );
const int inf = 0x3f3f3f3f;

int main(){
	ll n,x;cin >> n >> x;
	ll arr[N];
	for(ll i=0;i<n;i++) cin >> arr[i];
	sort(arr,arr+n);
	ll i=0,j=n-1,sum=0;
	while(i<j){
		if(arr[i]+arr[j] <= x){
			sum++;
			i++;
			j--;
		}
		else if(arr[i]+arr[j] > x){
			sum++;
			j--;
		}
	}
	if(i==j) sum++;
	cout << sum << endl;
}