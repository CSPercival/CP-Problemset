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

int ca = 0, ba = 0,cb = 0, bc = 0, bca = 0, cba = 0;
int uca = 0, uba = 0, ucb = 0, ubc = 0, ubca = 0, ucba = 0, gcb = 0;

char tryb(){
    if(ba){
        ba--;
        uba++;
        return 'a';
    }
    if(cba){
        cba--;
        ucba++;
        gcb++;
        return 'a';
    }
    if(bca){
        bca--;
        ubca++;
        return 'a';
    }
    // if(ucba - gcb > 0){
    //     if(bca){
    //         bca--;
    //         ubca++;
    //         gcb++;
    //     }
    // }

    return 'b';
}

char tryc(){
    if(ca){
        ca--;
        uca++;
        return 'a';
    }
    if(bca){
        bca--;
        ubca++;
        return 'a';
    }
    if(cba){
        cba--;
        ucba++;
        return 'a';
    }


    if(cb){
        cb--;
        ucb++;
        return 'b';
    }
    if(gcb){
        gcb--;
        return 'b';
    }


    return 'c';
}

void solve(){
    int n, q; cin >> n >> q;
    string s; cin >> s;
    ca = 0; ba = 0;cb = 0; bc = 0; bca = 0; cba = 0;
    uca = 0; uba = 0; ucb = 0; ubc = 0; ubca = 0; ucba = 0; gcb = 0;
    char c1,c2;
    while(q--){
        cin >> c1 >> c2;
        if(c1 == 'b'){
            if(c2 == 'a'){
                if(cb){
                    cb--;
                    cba++;
                } else {
                    ba++;
                }
            }
            if(c2 == 'c'){
                bc++;
            }
        }
        if(c1 == 'c'){
            if(c2 == 'a'){
                if(bc){
                    bc--;
                    bca++;
                } else {
                    ca++;
                }
            }
            if(c2 == 'b'){
                cb++;
            }
        }
    }
    // cout << ba << " " << ca << " " << cb << " " << bca << "\n";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'a') continue;
        if(s[i] == 'b'){
            s[i] = tryb();
            continue;
        }
        if(s[i] == 'c'){
            s[i] = tryc();
            continue;
        }
    }
    cout << s << "\n";
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
