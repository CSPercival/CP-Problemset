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
    int n,k ; 
    cin >> n >> k;
    vector<int> a(n);
    vector<vector<int>> pos(n + 1);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    int sum = 0;
    int max_num = 0;
    for(int i = 1; i <= n; i++){
        sum += pos[i].size();
        if(sum >= k - 1){
            max_num = i;
            break;
        }
    }
    int to_del = sum - (k - 1);
    int to_add = pos[max_num].size() - to_del;
    vector<int> b;
    vector<int> hmx;
    hmx.push_back(0);
    for(int i = 0; i < n; i++){
        if(a[i] < max_num){
            b.push_back(a[i]);
            hmx.push_back(0);
        }
        if(a[i] == max_num){
            hmx.back() += 1;
        }
    }
    // cout << hmx << "\n";
    // cout << b << "\n";
    // cout << max_num << " max  to_add " << to_add << "\n" ;
    for(int i = 0, ir = (int)b.size() - 1; i < b.size(); i++, ir--){
        if(b[i] != b[ir]){
            cout << "NO\n";
            return;
        }
    }

    if(b.size() % 2 == 0){
        // cout << "git parzyste\n";
        int can_add = 0;
        if(to_add < pos[max_num].size()){
            can_add = 1;
        }

        int il = b.size() /2;
        int ir = il + 1;

        if(to_add&1){
            // to_add--;
            if(hmx[il]){
                hmx[il]--;
                to_add--;
            } else {
                if(!can_add){
                    cout << "NO\n";
                    return;
                } else {
                    to_add++;
                }
            }
        } 

        while(hmx[il] >= 2 && to_add >= 2){
            hmx[il] -= 2;
            to_add -= 2;
        }

        il--;
         
        while(to_add >= 2 && il >= 0){
            if(hmx[il] && hmx[ir]){
                hmx[il]--;
                hmx[ir]--;
                to_add -= 2;
            } else {
                il--;
                ir++;
            }
        }

        // cout << "git parzyste 3\n";
        // il = b.size()/2;
        
        // if(to_add == 0){
        //     cout << "YES\n";
        //     return;
        // }

        
        // cout << "git parzyste 2\n";



        if(to_add == 0){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return;
    } else {
        int il = b.size() /2;
        int ir = il + 1; 
        if(to_add&1){
            if(to_add == pos[max_num].size()){
                cout << "NO\n";
                return;
            } else {
                to_add++;
            }
        }
        while(to_add >= 2 && il >= 0){
            if(hmx[il] && hmx[ir]){
                hmx[il]--;
                hmx[ir]--;
                to_add -= 2;
            } else {
                il--;
                ir++;
            }
        }
        if(to_add == 0){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return;
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
