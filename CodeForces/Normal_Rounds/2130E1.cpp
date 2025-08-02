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

string quest = "121131111232";

int ask(int i1, int i2, int opi){
    cout << "? " << quest.size() << " ";
    for(int i = 0; i < quest.size(); i++){
        if(quest[i] == '1') cout << opi << " ";
        if(quest[i] == '2') cout << i1 << " ";
        if(quest[i] == '3') cout << i2 << " ";
    }
    cout << "\n";
    cout << flush;
    int ans;
    cin >> ans;
    return ans;
}

int ask2(int l, int r, int idx){
    cout << "? " << (r - l + 1) * 2 + 1 << " ";
    for(int i = l; i <= r; i++){
        cout << idx << " " << i << " ";
    }
    cout << idx << "\n";
    cout << flush;
    int ans; cin >> ans;
    return ans;
}

int ask3(int idx1, int idx2){
    cout << "? " << 2 << " " << idx1 << " " << idx2 << "\n";
    cout << flush;
    int ans; cin >> ans;
    return ans;
}


int find_opi(int n){
    int l = 1, r = n, sr;
    int idx1 = 1;
    int idx2;
    while(l + 1 < r){
        sr = (l + r)/2;
        if(ask2(l + 1, sr, idx1)){
            r = sr;
        } else {
            l = sr;
        }
    }
    idx2 = r;
    if(ask3(idx1, idx2)){
        return idx1;
    } else {
        return idx2;
    }
}

void solve(){
    int n; 
    cin >> n;
    int opi = find_opi(n);
    vector<char> s(n + 1,'#');
    int ans = 0;
    int i1, i2;
    s[opi] = '(';
    for(int i = 1; i <= n; i += 2){
        if(i == opi){
            i--;
            continue;
        }
        i1 = i;
        i2 = i + 1;
        if(i2 > n || i2 == opi) 
            i2 = i1;
            
        ans = ask(i1, i2, opi);
        switch(ans){
            case 0:
                s[i1] = '(';
                s[i2] = '(';
                break;
            case 2:
                s[i1] = '(';
                s[i2] = ')';
                break;
            case 4:
                s[i1] = ')';
                s[i2] = '(';
                break;
            case 5:
                s[i1] = ')';
                s[i2] = ')';
                break;
            default:
                assert(false);
                break;
        }
    }
    cout << "! ";
    for(int i = 1; i <= n; i++){
        cout << s[i];
    }
    cout << "\n";
    cout << flush;
}

 
int32_t main(){
    // BOOST;
 
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}
