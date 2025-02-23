//Rating 1900
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

struct Expression{
    vector<ll> v;
    ll sum = 0;
};

ll parse_number(string &s, int start_idx){
    ll minus = 1;
    ll val = 0;
    if(s[start_idx] == '-') minus = -1;
    start_idx++;
    if(s[start_idx] == '+' || s[start_idx] == '=' || s[start_idx] == '-') return 1e13;

    if(s[start_idx] == '0' && '0' <= s[start_idx + 1] && '9' >= s[start_idx + 1]) return 1e15;

    for(int i = start_idx; i < s.size() && s[i] != '-' && s[i] != '+' && s[i] != '='; i++){
        val *= 10;
        val += s[i] - '0';
    }
    if(abs(val) >= 1e10) return 1e16;
    return val * minus;
}

void parse_expression(string &s, Expression &e, int start_idx, int end_idx){
    for(int i = start_idx; i < end_idx; i++){
        if(s[i] == '+' || s[i] == '-'){
            e.v.push_back(parse_number(s, i));
            e.sum += e.v.back();
        }
    }
}

void parse(string &s, Expression &e1, Expression &e2, int idxeq){
    e1.v.clear();
    e1.sum = 0;
    e2.v.clear();
    e2.sum = 0;
    parse_expression(s, e1, 0, idxeq);
    parse_expression(s, e2, idxeq + 1, s.size());
}

bool check(string s, Expression &e1, Expression &e2, int er, int ins, int idxeq){
    char tc = s[er];
    s.erase(s.begin() + er);
    if(s[ins] == '=') return false;

    s.insert(s.begin() + ins + 1, tc);

    for(int i = idxeq - 1; i <= idxeq + 1; i++){
        if(s[i] == '='){
            idxeq = i;
            break;
        }
    }
    parse(s,e1,e2,idxeq);
    if(e1.sum == e2.sum){
        s.erase(s.begin() + idxeq + 1);
        s.erase(s.begin());
        cout << s << "\n";
        return true;
    }
    return false;
}

void solve(){
    string s; cin >> s;
    s = "+" + s;
    int idxeq = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '='){
            s.insert(s.begin() + i + 1, '+');
            idxeq = i;
            break;
        }
    }
    // cout << s << "\n";
    Expression e1, e2;
    parse(s, e1, e2, idxeq);
    // for(int i = 0; i < e1.v.size(); i++){
    //     cout << e1.v[i] << " ";
    // }
    // cout << "\n";
    // for(int i = 0; i < e2.v.size(); i++){
    //     cout << e2.v[i] << " ";
    // }
    // cout << "\n";

    if(e1.sum == e2.sum){
        cout << "Correct\n";
        return;
    }
    string cs;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '+' || s[i] == '-' || s[i] == '=') continue;
        for(int j = 0; j < s.size() - 1; j++){
            if(check(s, e1, e2, i, j, idxeq)){
                return;
            }
        }
    }
    cout << "Impossible\n";
    return;
    
}

 
int32_t main(){
    BOOST;
 
    int q = 1; //cin >> q;
    while(q--){
        solve();
    }
    return 0;
}