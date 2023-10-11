#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define PATH_LEN 48

vector<ll> theirs;
bool vis[9][9];
int dx[4];
int dy[4];
static int ans = 0;

void dfs(ll idx,ll d, ll i, ll j){
    
    // optimization 1
    if(i == 7 && j == 1 ) {
        if(idx == PATH_LEN) ans++;
        return;
    }

    if(idx == PATH_LEN) return;

    vis[i][j] = true;

    // The optimization 2 & 3
    if(idx > 1){

        ll n = (d+1)%4;
        ll p = (d+3)%4;
        if(vis[i+dx[d]][j+dy[d]] && (!vis[i+dx[p]][j+dy[p]] && !vis[i+dx[n]][j+dy[n]])){
            vis[i][j] = false;
            return;
        }
    }

    if(theirs[idx] == 4){

        for(int d=0;d<4;d++){

            int x = i + dx[d];
            int y = j + dy[d];

            if(!vis[x][y]){
                dfs(idx+1,d,x,y);
            }
        }

    }else{
        int x = i + dx[theirs[idx]];
        int y = j + dy[theirs[idx]];
        if(!vis[x][y]){
            dfs(idx+1,theirs[idx],x,y);
        }
    }

    vis[i][j] = false;

}

void solve(){
     
    memset(vis,false,sizeof(vis));

    dx[0] = 0;
    dx[1] = -1;
    dx[2] = 0;
    dx[3] = 1;

    dy[0] = -1;
    dy[1] = 0;
    dy[2] = 1;
    dy[3] = 0;

    for(int i=0;i<9;i++){
        vis[i][0] = true;
        vis[0][i] = true;
        vis[i][8] = true;
        vis[8][i] = true;
    }

    string s; cin >> s;

    for(auto c: s){
        if(c == 'L') theirs.push_back(0);
        else if(c == 'U') theirs.push_back(1);
        else if(c == 'R') theirs.push_back(2);
        else if(c == 'D') theirs.push_back(3);
        else theirs.push_back(4);
    }

    dfs(0ll, 2, 1ll,1ll);

    cout << ans << endl;

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;

}