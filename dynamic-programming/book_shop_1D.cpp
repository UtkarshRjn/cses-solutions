#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <climits>
#include <iomanip>
#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <list>
#include <bitset>
#include <cassert>
using namespace std;

typedef long long ll;
const int N = 2e5+10;
const double eps = 1e-9;
const double pi = acos( -1 );
const int inf = 0x3f3f3f3f;

#define deb(x) cout << #x << " " << x << endl;

template<typename... T>
void read(T&... args){
	((cin >> args), ...);
}

bool lexo_inc(string a, string b) {
	return a < b;
}

bool lexo_dec(string a, string b){
	return a > b;
}

int main(){
	ll n,m;cin >> m >> n;
	vector<ll> S(m),P(m);
	for(ll i=0;i<m;i++) cin >> S[i];
	for(ll i=0;i<m;i++) cin >> P[i];
	vector<ll> table(n+1);
	
	for(ll i=0;i<m;i++){
		for(ll j=n;j>=0;j--){
			if(S[i] <= j){
				table[j] = max(table[j], table[j-S[i]] + P[i]);
			}
		}
	}
	cout << table[n] << endl;
}