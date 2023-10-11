#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int N = 2e6+10;
const double eps = 1e-9;
const double pi = acos( -1 );
const int inf = 0x3f3f3f3f;
 
ll n, x;
vector<ll> v;
map<ll,ll> mymap;
 
void solve(){
	
    cin >> n;
    while (n--)
    {
        cin >> x;
        v.push_back(x);
    }
 
    ll max_so_far = INT_MIN;
    ll max_ending_here = 0;
 
    for (int i = 0; i < v.size(); i++) {
        max_ending_here = max_ending_here + v[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
 
    cout << max_so_far << endl;
 
}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
 
}