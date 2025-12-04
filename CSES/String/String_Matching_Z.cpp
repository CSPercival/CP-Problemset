#include<bits/stdc++.h>
#define BOOST cin.tie(0); ios_base::sync_with_stdio(0)
using namespace std;

void calcZ(string &s, vector<int> *z){
    (*z).assign(s.size(), 0);
    int rend = 0, lend = 0;
    int shift;
    for(int i = 1; i < (int)s.size(); i++){
        shift = 0;
        if(i < rend){
            shift = min(rend - i,(*z)[i - lend]);
        }
        while(i + shift >= rend && s[shift] == s[i + shift]) shift++;

        (*z)[i] = shift;
        if(shift != 0) shift--;
        if(i + shift > rend){
            rend = i + shift;
            lend = i;
        }
    }
}

int main(){
    BOOST;
    string p, t;
    cin >> t >> p;
    string s = p + "#" + t;

    vector<int> z;
    calcZ(s, &z);

    int ans = 0;
    for(int i = (int)p.size() + 1; i < (int)s.size(); i++){
        if(z[i] == (int)p.size()) ans++;
    }
    cout << ans << "\n";
}