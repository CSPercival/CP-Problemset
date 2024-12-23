#include<bits/stdc++.h>
#define BOOST cin.tie(0);ios_base::sync_with_stdio(false)
#define st first
#define nd second

using namespace std;

void solve(){
    int n; cin >> n;
    if(!(n & 1)){
        cout << "-1\n";
        return;
    }
    vector<int> ans(n);
    int ctr = 1;
    for(int i = n / 2; i < n; i++){
        ans[i] = ctr;
        ctr += 2;
    }
    ctr = 2;
    for(int i = n / 2 - 1; i >= 0; i--){
        ans[i] = ctr;
        ctr += 2;
    }
    for(int i : ans){
        cout << i << " ";
    }
    cout << "\n";
}

int main(){
    BOOST;
    int qq = 1; cin >> qq;
    while(qq--){
        solve();
    }
}