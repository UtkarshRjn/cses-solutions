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
	
	string A,B; cin >> A >> B;
	int n = A.length();
    int m = B.length();
    
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    
   
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0) 
            {
                dp[i][j] = j;
            }else if(j == 0)
            {
                dp[i][j] = i;
            }else if(A[i-1] == B[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }else
            {
                dp[i][j] = 1+min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
            }
        }
    }
    
    cout << dp[n][m] << endl;

}