#include<bits/stdc++.h>
#define BOOST cin.tie(0);ios_base::sync_with_stdio(false)
#define st first
#define nd second

using namespace std;

int queries[1010][1010];
vector<int> graph[1010];

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            queries[i][j] = 0;
        }
    }
}

int main(){
    //BOOST;
    int qq = 1; cin >> qq;
    while(qq--){
        solve();
    }
}