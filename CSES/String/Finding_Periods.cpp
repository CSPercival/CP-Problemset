#include<bits/stdc++.h>
using namespace std;

void compute_pi(string &text, vector<int> &pi){
    int n = text.size();
    int pidx;
    pi[0] = 0;
    for(int i = 1; i < n; i++){
        pidx = pi[i - 1];
        while(pidx > 0 && text[i] != text[pidx]) pidx = pi[pidx - 1];
        if(text[i] == text[pidx]) pidx++;
        pi[i] = pidx;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string text; cin >> text;
    vector<int> pi(text.size());
    compute_pi(text, pi);

    vector<int> ps;
    int x = text.size();
    while(x > 0){
        x = pi[x - 1];
        ps.push_back(text.size() - x);
    }
    for(int i = 0; i < (int)ps.size(); i++){
        cout << ps[i] << " ";
    }
    cout << "\n";
    return 0;
}