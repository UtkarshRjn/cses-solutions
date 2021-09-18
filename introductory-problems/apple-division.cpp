#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void combination(vector<ll> arr, vector<ll> r, ll minimum, ll SUM, ll i, ll sum){

	for(auto itr : r) cout << itr << " ";
	cout << endl;

	if(abs(SUM-2*sum) > minimum) return;
	minimum = min(minimum,abs(SUM-2*sum));

	while(i < arr.size()){

		r.push_back(arr[i]);
		combination(arr, r, minimum, SUM, i, sum + arr[i]);
		i++;
		r.pop_back();
	}
}

int main()
{
	ll n,min = INT_MAX,sum = 0;cin >> n;
	vector<ll> arr,r;
	for(ll i=0;i<n;i++){
		ll x;cin >> x;
		sum += x;
		arr.push_back(x);
	}
	combination(arr,r,min,sum,0,0);
	cout << min << endl;

	return 0;
}