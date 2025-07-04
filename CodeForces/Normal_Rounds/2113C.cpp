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

int n, m;
bool ins(int x, int y){
    if(x >= 0 && x < n && y >= 0 && y < m) return true;
    return false;
}

void solve(){
    int k;
    cin >> n >> m >> k;
    vector<string> mine(n);
    int all_gold = 0;
    for(int i = 0; i < n; i++){
        cin >> mine[i];
        for(int j = 0; j < m; j++){
            if(mine[i][j] == 'g') all_gold++;
        }
    }

    vector<vector<int>> exp_cost(n, vector<int>(m,0));
    for(int i = 0; i < min(n, k); i++){
        for(int j = 0; j < min(m,k); j++){
            if(mine[i][j] == 'g') exp_cost[0][0]++;
        }
    }
    int col;
    for(int j = 1; j < m; j++){
        exp_cost[0][j] = exp_cost[0][j - 1];
        col = j - k;
        if(col >= 0){
            for(int i = 0; i < min(n, k); i++){
                if(mine[i][col] == 'g')
                    exp_cost[0][j]--;
            }
        }
        col = j + k - 1;
        if(col < m){
            for(int i = 0; i < min(n, k); i++){
                if(mine[i][col] == 'g')
                    exp_cost[0][j]++;
            }
        }
    }
    int row;
    for(int i = 1; i < n; i++){
        exp_cost[i][0] = exp_cost[i - 1][0];
        row = i - k;
        if(row >= 0){
            for(int j = 0; j < min(m, k); j++){
                if(mine[row][j] == 'g')
                    exp_cost[i][0]--;
            }
        }
        row = i + k - 1;
        if(row < n){
            for(int j = 0; j < min(m, k); j++){
                if(mine[row][j] == 'g')
                    exp_cost[i][0]++;
            }
        }
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            exp_cost[i][j] = exp_cost[i][j - 1];
            col = j - k;
            if(col >= 0){
                for(row = max(0, i - k + 1); row < min(n, i + k); row++){
                    if(ins(row, col) && mine[row][col] == 'g')
                        exp_cost[i][j]--;
                }
            }
            col = j + k - 1;
            if(col < m){
                // for(int i = 0; i < min(n, k); i++){
                //     if(mine[i][col] == 'g')
                //         exp_cost[0][j]++;
                // }
                for(row = max(0, i - k + 1); row < min(n, i + k); row++){
                    if(ins(row, col) && mine[row][col] == 'g')
                        exp_cost[i][j]++;
                }
            }
        }
    }
    int min_cost = all_gold;
    // for(int i = 0; i < n; i++){
    //     cout << mine[i] << "\n";
    // }
    // for(int i = 0; i < n; i++){
    //     cout << exp_cost[i] << "\n";
    // }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mine[i][j] == '.')
                min_cost = min(min_cost, exp_cost[i][j]);
        }
    }
    cout << all_gold - min_cost << "\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
