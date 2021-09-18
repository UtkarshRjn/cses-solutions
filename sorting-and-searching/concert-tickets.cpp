#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5+10;
const double eps = 1e-9;
const double pi = acos( -1 );
const int inf = 0x3f3f3f3f;

ll binarySearch(vector<ll> arr, ll l, ll r, ll x, vector<ll> arr_copy)
{

	if (r >= l) {

		ll mid = l + (r - l) / 2;

		if (arr[mid] == x){
			while(arr_copy[mid]==0 && mid >=0) mid--;
			return mid;
			}

		if (arr[mid] > x){
			return binarySearch(arr, l, mid - 1, x, arr_copy);
		}

		return binarySearch(arr, mid + 1, r, x ,arr_copy);
	}

	return r;
}

int main(){
	ll n,m;cin >> n >> m;
	vector<ll> a(n,0), b(n,0), a_copy(n); 
	for(ll i=0;i<n;i++) cin >> a[i];
	sort(a.begin(),a.end());
	
}