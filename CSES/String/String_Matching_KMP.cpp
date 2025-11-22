#include<bits/stdc++.h>
using namespace std;

int compute_pi(string text, int pat_len){
    int n = text.size();
    vector<int> p(n, 0);
    int pidx = 0;
    int ans = 0;
    for(int i = 1; i < n; i++){
        pidx = p[i - 1];
        while(pidx > 0 && text[i] != text[pidx])
            pidx = p[pidx - 1];
        if(text[i] == text[pidx]) pidx++;
        p[i] = pidx;
        if(p[i] == pat_len) ans++;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string text, pattern; cin >> text >> pattern;
    cout << compute_pi(pattern + "#" + text, pattern.size()) << "\n";
}