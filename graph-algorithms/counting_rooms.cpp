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

bool isP(int ni, int nj, int n ,int m){

	if(ni<0 || nj <0 || ni>=n || nj>=m) return false;
	else return true;

}

void dfs(vector<vector<char>> &arr,vector<vector<bool>> &vis,int i ,int j,bool &b, int count, vector<char> route){

	vector<pair<int,int>> move{
		{1,0},{0,1},{-1,0},{0,-1}
	};

	if(vis[i][j]) return;

	vis[i][j] = true;

	if(arr[i][j] == '.'){
		for(auto m:move){
			int ni = i + m.first;
			int nj = j + m.second;
			if(isP(ni,nj, vis.size(),vis[0].size())){
				if(!vis[ni][nj]){
					if(m == {1,0}) route.push_back('R');
					if(m == {0,1}) route.push_back('U');
					if(m == {-1,0}) route.push_back('L');
					if(m == {0,-1}) route.push_back('D');
					count++;
					dfs(arr, vis, ni, nj, b, count, route);						
				}

			}
			
		}
	}else if(arr[i][j] == 'B'){
		b = true;
		return;
	}

}

void solve(){
	ll n,m;
	cin >> n >> m;
	vector<vector<char>> arr(n,std::vector<char> (m));
	vector<vector<bool>> vis(n,std::vector<bool> (m));

	vector<pair<int,int>> move{
		{1,0},{0,1},{-1,0},{0,-1}
	};


	for(ll i=0;i<n;i++){
		for(ll j=0;j<m;j++){
			cin >> arr[i][j];
		}
	}

	vector<char> route;
	int count = 0;
	bool b = false;
	for(ll i=0;i<n && !b;i++){
		for(ll j=0;j<m;j++){
			if(arr[i][j] == 'A') dfs(arr,vis,i,j,b, count, route);
			if(b == true) {
				break;
			}
		}
	}

	if(b) {
		cout << "YES" << endl;
		cout << count << endl;
		for(int i=0;i<route.size();i++){
			cout << route[i];
		}
		cout << endl;
	}else cout << "NO" << endl;




}

int main(){
	solve();
}