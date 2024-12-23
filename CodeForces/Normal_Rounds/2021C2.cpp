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

int infi = 1e9;

void solve(){
    int n, m ,q; cin >> n >> m >> q;
    vector<int> kolej(n + 1);
    vector<int> gkto(n + 1);
    vector<int> bi(m + 1);
    vector<int> start(n + 1);
    vector<set<int>> slid(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> kolej[i];
        gkto[kolej[i]] = i;
    }
    for(int i = 1; i <= m; i++){
        cin >> bi[i];
        slid[bi[i]].insert(i);
    }
    for(int i = 1; i <= n; i++){
        slid[i].insert(infi);
    }
    vector<int> bugs;

    int last_idx = 0, curr_idx;
    for(int i = 1; i <= n; i++){
        // cout << slid[kolej[i]] << "\n";
        curr_idx = (*(slid[kolej[i]].begin()));
        start[i] = curr_idx;
        if(last_idx > curr_idx){
            bugs.push_back(i);
        }
        last_idx = curr_idx; 
    }

    // cout << gkto << "\n";
    // cout << start << "\n";
    // cout << bugs << "\n";

    if(bugs.empty()){
        cout << "YA\n";
    } else {
        cout << "TIDAK\n";
    }

    int si,tin;
    int tio;
    int tbug;
    while(q--){
        cin >> si >> tin;
        tio = bi[si];
        bi[si] = tin;
        slid[tio].erase(si);
        slid[tin].insert(si);
        start[gkto[tio]] = (*(slid[tio].begin()));
        start[gkto[tin]] = (*(slid[tin].begin()));

        tio = gkto[tio];
        tin = gkto[tin];

        // cout << tio << " - " << tin << "\n";
        // cout << start << "\n";

        if(start[tio - 1] > start[tio]){
            bugs.push_back(tio);
        }
        if(tio + 1 <= n && start[tio] > start[tio + 1]) bugs.push_back(tio + 1);

        if(start[tin - 1] > start[tin]){
            bugs.push_back(tin);
        }
        if(tin + 1 <= n && start[tin] > start[tin + 1]) bugs.push_back(tin + 1);

        // cout << bugs << "\n";

        while(!bugs.empty()){
            tbug = bugs.back();
            // cout << tbug << " ---\n";
            if(start[tbug - 1] <= start[tbug]) bugs.pop_back();
            else break;
        }
        if(bugs.empty()){
            cout << "YA\n";
        } else {
            cout << "TIDAK\n";
        }
    }
}
 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
