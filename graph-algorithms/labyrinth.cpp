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

bool isP(int ni, int nj, ll n ,ll m){

	if(ni<0 || nj <0 || ni>=n || nj>=m) return false;
	else return true;

}

void solve(){
	ll n,m;
	cin >> n >> m;
	vector<vector<char>> arr(n,std::vector<char> (m));
	vector<vector<bool>> vis(n,std::vector<bool> (m));

	vector<pair<int,int>> move{
		{1,0},{0,1},{-1,0},{0,-1}
	};

	int sx,sy,dx,dy;
	for(ll i=0;i<n;i++){
		for(ll j=0;j<m;j++){
			cin >> arr[i][j];
			if(arr[i][j] == 'A'){
				sx = i;
				sy = j;
			}else if(arr[i][j] == 'B'){
				dx = i;
				dy = j;
			}
		}
	}

	queue<pair<pair<int,int>,string>> q;
	q.push({{sx,sy},""});
	vis[sx][sy] = true;
	bool reached = false;
	string final_route;
	while(!q.empty() && !reached){
		auto p = q.front();
		q.pop();

		for(auto me:move){
			int i = me.first + p.first.first;
			int j = me.second + p.first.second;
			string route = p.second;
			if(me.first == 1 && me.second == 0) route = route + "D";
			if(me.first == 0 && me.second == 1) route = route + "R";
			if(me.first == -1 && me.second == 0) route = route + "U";
			if(me.first == 0 && me.second == -1) route = route + "L";

			if(i==dx && j==dy){
				reached = true;
				final_route = route;
				break;
			}

			if(isP(i,j,n,m)){
				if(!vis[i][j] && arr[i][j] == '.'){
					q.push({{i,j},route});
					vis[i][j] = true;
				}
			}
		}
	}

	if(reached){
		cout << "YES" << endl;
		cout << final_route.length() << endl;
		cout << final_route << endl;
	}else{
		cout << "NO" << endl;
	}
	



}

int main(){
	solve();
}