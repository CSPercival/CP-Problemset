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

string board[1010];
int vis[1010][1010];

int dx[200];
int dy[200];

void init_dir(){
    dx['U'] = -1;
    dx['D'] = 1;
    dx['L'] = 0;
    dx['R'] = 0;

    dy['U'] = 0;
    dy['D'] = 0;
    dy['L'] = -1;
    dy['R'] = 1;
}

int ans = 0;

void dfs(int x, int y){
    vis[x][y] = 3;
    char d = board[x][y];
    if(d == '?'){
        ans += 1;
        vis[x][y] = 1;
        return;
    }
    if(d == '#'){
        vis[x][y] = 2;
        return;
    }
    int ver;
    if(!vis[x + dx[d]][y + dy[d]]){
        dfs(x + dx[d],y + dy[d]);
    }
    vis[x][y] = vis[x + dx[d]][y + dy[d]];
    if(vis[x][y] == 3) vis[x][y] = 1;
    if(vis[x][y] == 1){
        ans += 1;
    }
}

string dirs= "UDRL";
string oppdirs= "DULR";

void solve(){
    int n,m; cin >> n >> m;
    string tmp;
    string wall = "";
    for(int i = 0; i <= m + 1; i++){
        wall.push_back('#');
    }
    for(int i = 0; i <= n + 1; i++){
        for(int j = 0; j <= m + 1; j++){
            vis[i][j] = 0;
        }
        board[i] = wall;
        if(i == 0 || i == n + 1) continue;
        cin >> tmp;
        tmp = "#" + tmp + "#";
        board[i] = tmp;
    }
    // for(int i = 0; i <= n + 1; i++){
    //     cout << board[i] << "\n";
    // }
    ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!vis[i][j]){
                if(board[i][j] == '?'){
                    // for(int ii = 0; ii < 4; ii++){
                    //     if(board[i + dx[dirs[ii]]][j + dy[dirs[ii]]] == oppdirs[ii] || board[i + dx[dirs[ii]]][j + dy[dirs[ii]]] == '?'){
                    //         vis[i][j] = 1;
                    //         ans++;
                    //         break;
                    //     }
                    // }
                } else {
                    dfs(i,j);
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!vis[i][j]){
                assert(board[i][j] == '?');
                vis[i][j] = 2;
                for(int ii = 0; ii < 4; ii++){
                    if(vis[i + dx[dirs[ii]]][j + dy[dirs[ii]]] == 1 || board[i + dx[dirs[ii]]][j + dy[dirs[ii]]] == '?'){
                        vis[i][j] = 1;
                        ans++;
                        break;
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}

 
int32_t main(){
    BOOST;
    init_dir();
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
