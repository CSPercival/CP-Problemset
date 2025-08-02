#include<bits/stdc++.h>
#define st first
#define nd second
#define all(x) x.begin(), x.end()
#define BOOST cin.tie(NULL); ios_base::sync_with_stdio(false);
 
// #define int ll
typedef long long ll;

using namespace std;
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }


void solve(){
    int n; 
    cin >> n;
    vector<int> mov(n);
    for(int i = 0; i < n; i++){
        cin >> mov[i];
    }
    int currh = 0;
    int currmax = 0;
    int noj = 0;
    queue<int> jumps;
    int li, ri;
    bool good = true;
    for(int i = 0; i < n; i++){
        cin >> li >> ri;
        if(!good) continue;
        if(mov[i] == 1){
            currh += 1;
        }
        if(mov[i] == -1){
            jumps.push(i);
        }
        while(currh < li && !jumps.empty()){
            mov[jumps.front()] = 1;
            currh++;
            jumps.pop();
        }
        if(currh < li || ri < currh){
            good = false;
        }
        while(jumps.size() > ri - currh){
            mov[jumps.front()] = 0;
            jumps.pop();
        }
    }
    if(!good){
        cout << "-1\n";
        return;
    }
    while(jumps.size()){
        mov[jumps.front()] = 0;
        jumps.pop();
    }
    for(int i = 0; i < n; i++){
        cout << mov[i] << " "; 
    }
    cout << "\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
        // cout << "SOLVED " << q << endl;
    }
    return 0;
}
