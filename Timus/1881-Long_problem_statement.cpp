#include<bits/stdc++.h>
#define BOOST cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)

using namespace std;

int main(){
    BOOST;
    int h, w, n; cin >> h >> w >> n;
    int ans = 1;

    string word;
    int s, th = h, tw = w;
    for(int i = 0; i < n; i++){
        cin >> word;
        s = word.size();
        if(tw >= s){
            tw -= s + 1;
            continue;
        }
        tw = w - s - 1;
        if(th == 1){
            ans++;
            th = h;
            continue;
        }
        th--;
    }
    cout << ans << "\n";
    return 0;
}