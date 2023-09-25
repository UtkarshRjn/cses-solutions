#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5+1;
const double eps = 1e-9;
const double pi = acos( -1 );
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;

struct TrieNode{

    unordered_map<char,TrieNode*> children;
    bool isEndofWord;

    TrieNode(){
        isEndofWord = false;
    }

};

class Trie{

    public:
        TrieNode* root;

        Trie(){
            root = new TrieNode();
        }

        void insert(string s){
            //
            TrieNode* curr = root;
            for(auto c: s){
                if(curr->children.find(c) == curr->children.end()){
                    curr->children[c] = new TrieNode();
                }

                curr = curr->children[c];
            }

            curr->isEndofWord = true;
        }

};

int main(){

	string s; cin >> s;
    ll k; cin >> k;
    Trie trie;

    ll n = s.size();

    while(k--){
        string word; cin >> word;
        trie.insert(word);
    }

    vector<ll> dp(n+1,0);

    dp[n] = 1;
    for(int i=n-1;i>=0;i--){ // O(n)
        TrieNode* curr = trie.root;
        for(int j=i;j<n;j++){ // O(n)
            if(curr->children.find(s[j]) == curr->children.end()){
                break;
            }

            curr = curr->children[s[j]];
            if(curr->isEndofWord){ // O(n)
                dp[i] = (dp[i]%mod + dp[j+1]%mod)%mod;
            }
        }
    }

    cout << dp[0] << endl;

}
