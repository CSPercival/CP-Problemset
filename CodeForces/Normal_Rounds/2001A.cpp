#include<bits/stdc++.h>
#define BOOST cin.tie(0);ios_base::sync_with_stdio(false)
#define st first
#define nd second

using namespace std;

int ctr[110];

void solve(){
    int n; cin >> n;
    int ans = 0;
    for(int i = 0; i <= n; i++){
        ctr[i] = 0;
    }
    int tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        ans = max(ans, ++ctr[tmp]);
    }
    cout << n - ans << "\n";
    return;
}

int main(){
    BOOST;
    int qq = 1; cin >> qq;
    while(qq--){
        solve();
    }
}