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

const int max_ans = 1e6 + 10;

int n, m; 
vector<pair<int,int>> pos[max_ans];
vector<int> vals;
// set<pair<int,int>> block;
bool alive[max_ans];

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.st != b.st) return a.st < b.st;
    return a.nd > b.nd;
}

bool nec(int mex){
    // deb cout << "ANALIZA MEX " << mex << "\n";
    if(pos[mex].size() == 0) return false;
    sort(all(pos[mex]), cmp);
    pos[mex].push_back({n, m});

    int last_row = -1;
    vector<pair<int,int>> block[2];

    block[1].push_back({1, m - 1});
    pair<int,int> nseg;

    // deb cout << pos[mex] << "\n";

    for(auto& [row,column] : pos[mex]){
        // deb cout << "ANALIZA : {" << row << ", " << column << "}    ===========================\n";
        // deb cout << "Przed\n";
        // deb cout << block[0] << "\n";
        // deb cout << block[1] << "\n";
        if(row == last_row){
            // deb cout << " stary row\n";
            nseg = {column, column};
            while(block[0].size() && block[0].back().st - 1 > column){
                block[0].pop_back();
            }
            if(block[0].size()){
                nseg.nd = max(nseg.nd, block[0].back().nd);
            }
            if(block[1].back().st <= nseg.nd + 1){
                nseg.nd = max(nseg.nd, block[1].back().nd);
                block[1].pop_back();
            }
            block[1].push_back(nseg);
        } else {
            // deb cout << " nowy row\n";
            while(block[0].size() > 1) block[0].pop_back();
            if(block[0].size()){
                if(block[0][0].st == 0){
                    nseg = block[0][0];
                    if(block[1].back().st <= nseg.nd + 1){
                        nseg.nd = max(nseg.nd, block[1].back().nd);
                        block[1].pop_back();
                    }
                    block[1].push_back(nseg);
                }
                block[0].pop_back();
            }
            while(block[1].size()){
                block[0].push_back(block[1].back());
                block[1].pop_back();
            }
            if(block[0].size() == 1 && block[0][0].st == 0 && block[0][0].nd == m - 1){
                return true;
            }

            //Zacznij nowy rzad
            // deb cout << "zaczynam nowy rzad\n";
            // deb cout << block[0] << "\n";
            // deb cout << block[1] << "\n";
            
            if(row != last_row + 1){
                while(block[0].size() > 1) block[0].pop_back();
                if(block[0][0].st != 0) block[0].pop_back();
            }
            nseg = {column, column};
            while(block[0].size() && block[0].back().st - 1 > column){
                block[0].pop_back();
            }
            if(block[0].size()){
                nseg.nd = max(nseg.nd, block[0].back().nd);
            }
            block[1].push_back(nseg);

            last_row = row;
        }
        // deb cout << "Po\n";
        // deb cout << block[0] << "\n";
        // deb cout << block[1] << "\n";
    }
    if(block[0].size() && block[0].back().nd == m - 1) return true;
    return false;
}

void solve(){
    // deb cout << "TEST CASE ---------------------------------------------------------------------\n";
    cin >> n >> m;
    vector<vector<int>> board(n,vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            // vals.push_back(board[i][j]);
            if(board[i][j] >= max_ans) continue;
            if(!alive[board[i][j]])
                vals.push_back(board[i][j]);
            
            pos[board[i][j]].push_back({i,j});
            alive[board[i][j]] = true;
        }
    }
    // for(int i : vals){
    //     sort(all(pos[i]));
    // }
    
    for(int mex = 0; mex < max_ans; mex++){
        if(!nec(mex)){
            cout << mex << "\n";
            break;
        }
    }

    // deb cout << vals << "   vals\n";
    for(int i : vals){
        alive[i] = false;
        pos[i].clear();
    }
    vals.clear();
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
