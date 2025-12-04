#include<bits/stdc++.h>
using namespace std;

void Manacher(string &s, vector<int> &pal){
    int n = s.size();
    pal.assign(n, 1);
    int best_idx = 0;
    for(int i = 1; i < n; i++){
        if(i < best_idx + pal[best_idx]){
            pal[i] = min(best_idx + pal[best_idx] - i, pal[best_idx * 2 - i]);
        }
        while(0 <= i - pal[i] && i + pal[i] < n){
            if(s[i - pal[i]] == s[i + pal[i]]) pal[i]++;
            else break;
        }
        if(best_idx + pal[best_idx] < i + pal[i]) best_idx = i;
    }
}

string preprocess(string &s){
    string ans = "#";
    for(int i = 0; i < s.size(); i++){
        ans.push_back(s[i]);
        ans.push_back('#');
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string text; cin >> text;
    vector<int> pal;
    string pptext = preprocess(text);
    Manacher(pptext, pal);
    int best_idx = 0;
    int best_pal = -1;
    for(int i = 1; i < pptext.size(); i++){
        if(pal[i] - 1 > best_pal){
            best_pal = pal[i] - 1;
            best_idx = i;
        }
    }
    string ans = "";
    for(int i = best_idx - best_pal; i < best_idx + best_pal; i++){
        if(pptext[i] == '#') continue;
        ans.push_back(pptext[i]);
    }
    cout << ans << "\n";
    return 0;
}
