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
ll mod = 1e9 + 7;
 
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

#define SZ 200005

const int MOD = 1e9 + 7;
const int TWO_MOD_INV = 500000004;

long long total_sum(long long start, long long end) {
	return ((((end - start + 1) % MOD) * ((start + end) % MOD) % MOD) *
	        TWO_MOD_INV % MOD);
}

ll sigma(ll n){

    long long total = 0;
	long long at = 1;
	while (at <= n) {
		long long add_amt = n / at;  // Our divisor to process
		// The largest number that still has the same value of q
		long long last_same = n / add_amt;

		total = (total + add_amt * total_sum(at, last_same)) % MOD;
		at = last_same + 1;
	}

	return total;

}

void solve() {

    ll n; cin >> n;
    cout << sigma(n) << endl;

}

int main(){
	int T;
    T = 1;
	while(T--){
		solve();
	}
}