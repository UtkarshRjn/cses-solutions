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
const ll fac = 1e9+7;

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
	ll m,n;cin >> m >> n;
	vector<ll> S(m);
	for(ll i=0;i<m;i++) cin >> S[i];
	vector<ll> table(n+1,0);
	table[0] = 1;

	for (int i = 1; i <= n; i++) {
    	for (int j = 0; j < m; j++) {
      		if (S[j] <= i) {
        		table[i] = (table[i] + table[i - S[j]]) % fac;
      		}
    	}
  	}
	cout << table[n] << endl;
}