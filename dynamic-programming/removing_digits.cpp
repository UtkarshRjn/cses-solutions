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

const ll fac = 1e9 + 6;

int main(){
	ll n;cin >> n;
	std::vector<ll> v(n+1);

	v[0] = 0;
	for(int i=1;i<=9 && i<=n;i++){
		v[i] = 1;
	}

	for(int i=10;i<=n;i++){
		ll  Min = INT_MAX;
		int x = i;
		while(x){
			int l = x%10;
			if(l != 0 ) 
				Min = min(Min,v[i-l] + 1);
			x = x/10;
		}
		v[i] = Min;
	}

	cout << v[n] << endl;

}