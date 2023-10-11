#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(const vector<ll>& v,const set<pair<ll,ll> >& st){

    for(int i=0;i<8;i++){
        if(st.find({i,v[i]}) != st.end())  return false;
    }

    for(int i=0;i<8;i++){
        for(int j=i+1;j<8;j++){
            int x1 = i, y1 = v[i];
            int x2 = j, y2 = v[j];
            if(x1 == x2 || y1 == y2 || x1+y1 == x2+y2 || x1-y1 == x2-y2) return false;
        }
    }

    return true;

}

void solve(){
     
    vector<vector<char> > board(8,vector<char>(8));

    ll n = 8;
    char ch = '*';
    set<pair<ll,ll> > block;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c; cin >> c;
            board[i][j] = c;
            if(c == '*') block.insert({i,j});
        }
    }

    vector<ll> v;
    for(int i=0;i<8;i++) v.push_back(i);
    vector<ll> rev = v;

    reverse(rev.begin(),rev.end());

    ll count = 0;
    do{
        count += check(v,block);
        next_permutation(v.begin(),v.end());
    }
    while(v != rev);

    cout << count << endl;

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;

}