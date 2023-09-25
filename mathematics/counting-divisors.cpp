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

ll numDiv(ll n){

    ll ans = 0;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            ans+=2;
            if(i*i == n) ans--;
        }
    }

    return ans;

}

void solve() {

    ll n; cin >> n;
    cout << numDiv(n) << endl;

}

int main(){
	int T;
    T = 1;
    cin >> T;
	while(T--){
		solve();
	}
}