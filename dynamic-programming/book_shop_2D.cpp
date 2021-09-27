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
const ll inf = 0x3f3f3f3f;

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

struct fraction {
  ll numerator, denominator;
  bool operator<(const fraction& f) const {
    return numerator*f.denominator < f.numerator*denominator;
  }
};

int main(){
		ll n,m;cin >> m >> n;
		vector<ll> S(m),P(m);
		for(ll i=0;i<m;i++) cin >> S[i];
		for(ll i=0;i<m;i++) cin >> P[i];
		vector<vector<ll>> table(m+1 ,vector<ll> (n+1));
		
		for(ll i=0;i<m+1;i++){
			for(ll j=0;j<n+1;j++){
				if(i==0||j==0) table[i][j] = 0;
				else if (S[i-1] <= j)
					table[i][j] = max(table[i-1][j],table[i-1][j-S[i-1]] + P[i-1]);
				else table[i][j] = table[i-1][j];
			}
		}
		cout << table[m][n] << endl;
}