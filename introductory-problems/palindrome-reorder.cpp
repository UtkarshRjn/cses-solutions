#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void print(ll* arr){
    string t;
    for(int i=0;i<26;i++)
        for(int j=0;j<arr[i]/2 && arr[i]%2 == 0;j++) 
            t += i + 'A';
    cout << t;
    for(int i=0;i<26;i++)
        if(arr[i]%2 == 1) 
            for(int j=0;j<arr[i];j++)
                cout << char(i + 'A');
    reverse(t.begin(),t.end());
    cout << t;
}

int main(){
    string s;cin >> s;
    ll fre[26] = {0},j = 0;
    for(char c : s) fre[c-'A']++;
    for(int i=0;i<26;i++) j += fre[i]%2;
    if(j>1) cout << "NO SOLUTION" << endl;
    else print(fre);
}