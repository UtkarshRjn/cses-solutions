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

const ll fac = 1e9 + 7;

int main(){
	
	ll a, b; cin >> a >> b;
    vector<vector<ll>> v(a+1,vector<ll>(b+1));

    for(ll i=1;i<=a;i++){
        for(ll j=1;j<=b;j++){
            if(i==j) v[i][j] = 0;
            else{
                ll Min = INT_MAX;
                for(ll k=1;k<=i-1;k++)
                    Min = min(v[i-k][j] + v[k][j] + 1, Min);

                for(ll k=1;k<=j-1;k++)
                    Min = min(v[i][j-k] + v[i][k] + 1, Min);

                v[i][j] = Min;
            }
            
        }
    }

    cout << v[a][b] << endl;

}