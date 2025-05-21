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

struct TrieNode{
    char c;
    int dep;
    // set<int> words;
    int nei[256];
    int binjumps[30];
};


struct ANSStruct{
    int n;
    int sn;
    int non;
    vector<int> idx2trie;
    vector<TrieNode> t;
    ANSStruct(int in_n){
        sn = 0;
        non = 1;
        n = in_n;
        t.resize(n + 1);
        idx2trie.resize(n + 1, 0);
        idx2trie[1] = sn;
        t[sn].c = '#';
        t[sn].dep = 0;
        // t[sn].words.insert(1);
    }

    void create_node(int par, char c){
        t[non].c = c;
        t[non].dep = t[par].dep + 1;
        t[non].binjumps[0] = par;
        for(int i = 1; i < 30; i++){
            t[non].binjumps[i] = t[t[non].binjumps[i - 1]].binjumps[i - 1];
        }
        non++;
    }

    int get_next(int idx, char letter){
        if(t[idx].nei[letter] == '0') return -1;
        return t[idx].nei[letter];
    }

    void add_word(int iow, int inw){
        int tiow = idx2trie[iow];
        idx2trie[inw] = tiow;
        // t[tiow].words.insert(inw);
    }

    void add_letter(int iw, char cw){
        int tiw = idx2trie[iw];
        if(t[tiw].nei[cw] == 0){
            t[tiw].nei[cw] = non;
            create_node(tiw, cw);
        }
        int ntiw = t[tiw].nei[cw];
        idx2trie[iw] = ntiw;
    }

    char create_ans(int ab, int inv){
        if(ab ^ inv){
            return '<';
        } else {
            return '>';
        }
    }

    char query(int iwa, int iwb){
        iwa = idx2trie[iwa];
        iwb = idx2trie[iwb];
        // cout << iwa << " - " << iwb << "\n";
        if(iwa == iwb) return '=';
        int inv = 0;
        if(t[iwa].dep > t[iwb].dep){
            inv = 1;
            swap(iwa,iwb);
        }
        for(int i = 29; i >= 0; i --){
            if(t[t[iwb].binjumps[i]].dep >= t[iwa].dep){
                iwb = t[iwb].binjumps[i];
            }
        }
        // cout << iwb << "\n";
        if(iwb == iwa){
            return create_ans(1, inv);
        }
        for(int i = 29; i >= 0; i --){
            if(t[iwb].binjumps[i] != t[iwa].binjumps[i]){
                iwb = t[iwb].binjumps[i];
                iwa = t[iwa].binjumps[i];
            }
        }
        return create_ans(t[iwa].c < t[iwb].c, inv);
    }

    void print_trie(){
        for(int i = 0; i <= non; i++){
            cout << i << ": " << idx2trie[i] << "\n";
        }
        for(int i = 0; i <= non; i++){
            cout << i << ": \n";
            cout << t[i].dep << " " << t[i].c << "\n";
            for(int j = 0; j < 30 ; j++){
                cout << t[i].binjumps[j] << " ";
            }
            cout << "\n";
        }
    }

};

int32_t main(){
    BOOST;

    int n; cin >> n;
    ANSStruct ds(n);
    int wc = 1;
    int op, a, b;
    char c;
    for(int i = 0; i < n; i++){
        cin >> op;
        if(op == 1){
            cin >> a >> c;
            ds.add_letter(a, c);
        }
        if(op == 2){
            cin >> a;
            ds.add_word(a, ++wc);
        }
        if(op == 3){
            cin >> a >> b;
            cout << ds.query(a, b) << "\n";
        }
    }
    // ds.print_trie();
    return 0;
}
