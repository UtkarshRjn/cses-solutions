#include<bits/stdc++.h>
using namespace std;

void permutation(string a,int l, int r, set<string> &arr){
    if(l==r) arr.insert(a);
    for(int i=l;i<=r;i++){
        swap(a[i],a[l]);
        permutation(a,l+1,r,arr);
        swap(a[i],a[l]);
    }
}

int main(){
    string s;cin >> s;
    set<string> arr;
    permutation(s,0,s.size()-1,arr);
    cout << arr.size() << endl;
    for(auto it:arr) cout << it << endl;
}