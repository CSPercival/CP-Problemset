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

void dfs(int idx, int parent, vector<vector<int>> &g, vector<int> &par){
    par[idx] = parent;
    for(int i : g[idx]){
        if(i == parent) continue;
        dfs(i, idx, g, par);
    }
}

// int deepest(int idx, int omit,vector<vector<int>> &g, vector<int> &par){
//     int ans = 0;
//     for(int i : g[idx]){
//         if(i == omit || i == par[idx]) continue;
//         ans = max(ans, deepest(i, omit, g, par));
//     }
//     return ans + 1;
// }

int deepest2(int idx,vector<vector<int>> &g, vector<int> &parA, vector<int> &parB){
    int ans = 0;
    for(int i : g[idx]){
        if(i == parA[idx] || i == parB[idx]) continue;
        ans = max(ans, deepest2(i, g, parA, parB));
    }
    return ans + 1;
}

void solve(){
    int n; cin >> n;
    int a,b;
    vector<vector<int>> g(n + 1);
    for(int i = 1; i < n; i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int rootA = 1, rootB;
    cin >> rootB >> rootB;
    
    // vector<int> visA(n + 1);
    // vector<int> visB(n + 1);
    vector<int> parA(n + 1);
    vector<int> parB(n + 1);

    dfs(rootA, 0, g, parA);
    dfs(rootB, 0, g, parB);

    int dist = 0;
    int tmp = rootB;
    while(tmp != rootA){
        dist++;
        tmp = parA[tmp];
    }

    int middle = rootA;
    for(int i = 0; i < dist/2; i++){
        middle = parB[middle];
    }

    // int b0A = deepest(rootA,rootB,g,parA) - 1;
    // int b0B = deepest(rootB,rootA,g,parB) - 1;

    vector<int> sindeep(n + 1);
    for(int i = rootB; i != 0; i = parA[i]){
        sindeep[i] = deepest2(i,g,parA,parB) - 1;
    }

    if(parA[rootB] == rootA){
        if(sindeep[rootA] > sindeep[rootB]){
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
        return;
    }

    vector<int> alldeepA(n + 1), alldeepB(n + 1);
    int ctr = 2;
    alldeepB[parB[middle]] = sindeep[parB[middle]];
    for(int i = parB[parB[middle]], j = middle; i != 0; i = parB[i], ctr += 2, j = parA[j]){
        alldeepB[i] = max({alldeepB[parA[i]] + 1, sindeep[i], sindeep[j] + ctr});
    }

    ctr = 2;
    alldeepA[middle] = sindeep[middle];
    for(int i = parA[middle], j = parB[middle]; i != 0; i = parA[i], ctr += 2, j = parB[j]){
        alldeepA[i] = max({alldeepA[parB[i]] + 1, sindeep[i], sindeep[j] + ctr});
    }

    // cout << parA << "\n";
    // cout << parB << "\n";
    // cout << sindeep << "\n";
    // cout << alldeepA << "\n";
    // cout << alldeepB << "\n";


    int turnA = 1;
    bool koniec = false;
    while(parA[rootB] != rootA){
        if(sindeep[rootA] > alldeepB[rootB]){
            cout << "Alice\n";
            return;
        }
        rootA = parB[rootA];
        turnA ^= 1;
        if(parA[rootB] == rootA) break;
        
        if(sindeep[rootB] > alldeepA[rootA]){
            cout << "Bob\n";
            return;
        }
        turnA ^= 1;
        rootB = parA[rootB];
    }

    if(turnA){
        if(sindeep[rootA] > sindeep[rootB]){
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
    } else {
        if(sindeep[rootA] < sindeep[rootB]){
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
        }
    }

    // vector<int> 
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
