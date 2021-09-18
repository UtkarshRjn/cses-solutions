#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5+10;
const double eps = 1e-9;
const double pi = acos( -1 );
const int inf = 0x3f3f3f3f;

void Print(vector<string> v)
{
    for (auto i : v)
        cout << i << endl;
}

bool lexo_inc(string a, string b) {
	return a < b;
}

bool lexo_dec(string a, string b){
	return a > b;
}

ll binarySearch(ll arr[], ll l, ll r, ll x)
{
    if (r >= l) {
        ll mid = l + (r - l) / 2;
  
        if (arr[mid] == x)
            return mid;
  
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
  
        return binarySearch(arr, mid + 1, r, x);
    }

  return -1;
}

int main(){
	ll n,x;cin >> n >> x;
	vector<ll> v(n);
	for(ll i=0;i < n;i++) cin >> v[i];
	sort(v.begin(),v.end(),greater<ll>());
	ll ans = 0;
	for(ll i=0;i<n;i++){
		ans += x/v[i];
		x = x%v[i];
		if(x==0) break;
	}
	cout << ans << endl;
}