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

bool check(string &s, vector<int> &stos, int curri, char dig, int mod){
    int n = s.size();

    int add = 0;
    if(stos.back() == dig){
        stos.pop_back();
        add = 1;
    } else {
        if(dig != '0' || curri != 0)
            stos.push_back(dig);
    }

    int no9 = n - curri - stos.size();

    if(add){
        stos.push_back(dig);
    } else {
        if(dig != '0' || curri != 0)
            stos.pop_back();
    }

    if(no9 >= 0 && no9 % mod == 0) return true;
    return false;
}

void print_ans(string &s, int sidx, char snum, int m9){
    int n = s.size();
    vector<int> stos;
    stos.push_back('s');
    string ans = "";
    for(int i = 0; i < sidx; i++){
        ans.push_back(s[i]);
        if(stos.back() == s[i]){
            stos.pop_back();
        } else {
            stos.push_back(s[i]);
        }
    }
    if(sidx != 0 || snum != '0'){
        ans.push_back(snum);
        if(stos.back() == snum){
            stos.pop_back();
        } else {
            stos.push_back(snum);
        }
    }
    while(n - sidx - 2 >= (int)stos.size()){
        ans.push_back('9');
        ans.push_back('9');
        sidx += 2;
    }
    while(stos.size() > 1){
        ans.push_back(stos.back());
        stos.pop_back();
    }

    cout << ans << "\n";
}

void solve(){
    string s; cin >> s;
    int n = s.size();
    vector<int> stos;
    stos.push_back('s');
    int max_idx = -1;
    char smaller_num = -1;
    int add = 0;
    for(int i = 0; i < n; i++){
        for(char dig = '0'; dig < s[i]; dig++){
            if(check(s, stos, i, dig, 2)){
                max_idx = i;
                smaller_num = dig;
            }
        }
        if(stos.back() == s[i]){
            stos.pop_back();
        } else {
            stos.push_back(s[i]);
        }
    }
    if(stos.size() == 1){
        cout << s << "\n";
        return;
    }
    if(max_idx != -1){
        print_ans(s, max_idx, smaller_num, 2);
        return;
    }
    stos.clear();
    stos.push_back('s');
    for(int i = 0; i < n; i++){
        for(char dig = '0'; dig < s[i]; dig++){
            if(check(s, stos, i, dig, 1)){
                max_idx = i;
                smaller_num = dig;
            }
        }
        if(stos.back() == s[i]){
            stos.pop_back();
        } else {
            stos.push_back(s[i]);
        }
    }
    assert(max_idx != -1);
    print_ans(s, max_idx, smaller_num, 2);
}

 
int32_t main(){
    BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
