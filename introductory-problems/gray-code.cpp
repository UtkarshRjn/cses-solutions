#include<bits/stdc++.h>
using namespace std;

vector<string> arr{"0","1"};

vector<string> grc(int x){
    if(x==1) return arr;
    vector<string> s,f = grc(x-1);
    for(string str: f) s.push_back(str + "0");
    reverse(f.begin(),f.end());
    for(string str: f) s.push_back(str + "1");
    return s;
}

int main(){
    int n;cin >> n;
    for(string str : grc(n)) cout << str << endl;
}