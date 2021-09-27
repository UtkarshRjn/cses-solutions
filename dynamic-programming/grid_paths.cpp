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
const ll fac = 1e9 + 7;

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

ll path_search(vector<vector<char>> grid, ll i, ll j){

	if(grid[i][j] == '*') return 0;

	if(j==0) return grid[i-1][j];
	else if(i==0) return grid[i][j-1];

	return grid[i-1][j] + grid[i][j-1];
}

void solve(){

	ll n;cin >> n;
	vector<vector<char>> grid(n,vector<char> (n));
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			cin >> grid[i][j];
		}
	}

	vector<vector<ll>> table(n,vector<ll> (n));
	
	if(grid[0][0] == '*') {
		cout << 0 << endl;
		return;
	}
	table[0][0] = 1;

	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			if(i==0 && j==0) continue;
			
			if(grid[i][j] == '*') table[i][j] = 0;
			else{
				if(j==0) table[i][j] = table[i-1][j];
				else if(i==0) table[i][j] = table[i][j-1];
				else table[i][j] = (table[i-1][j] + table[i][j-1])%fac;			
			}
		}
	}
	cout << table[n-1][n-1] << endl;
	return;

}


int main(){
	solve();
}