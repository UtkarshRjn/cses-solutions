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

ll minCoins(vector<ll> S, ll m, ll V){

	ll table[V+1];

	table[0] = 0;

	for(ll i=1;i<=V;i++)
		table[i] = INT_MAX;

	for(ll i=1; i<=V;i++){
		for(ll j=0;j<m;j++)
			if(S[j]<=i){
				ll sub_res = table[i-S[j]];
				if( sub_res != INT_MAX && sub_res + 1 < table[i])
					table[i] = sub_res + 1;
			}
	}
	if(table[V]==INT_MAX)
		return -1;
	return table[V];

}


int main(){
	ll m,n;cin >> m >> n;
	vector<ll> S(m);
	for(ll i=0;i<m;i++) cin >> S[i];

	cout << minCoins(S, m, n) << endl;
}