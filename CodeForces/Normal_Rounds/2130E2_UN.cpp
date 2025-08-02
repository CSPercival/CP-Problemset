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

// string quest = "010020030040000121000";
// string quest = "010020030040000121000013100001410000212000023200002420000313000032300003430000343";
// string quest = "01002003004000012100002320000343000041400000012321000000234320000003414300000041214000000000000001234321";
// string quest = "01002003004000012100002320000343000041400000000000000023240000034310000041420000000000000000000000000000000000000000012431431243413241234123213241441141243132412431111214312331423";
string quest = "01002003004000012100002320000343000045400005150000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001243421435142351423314312435413254123412321525345355451424132455551255223323215532451441514124313241254311112143512555555331554253";
set<int> ans;
map<int,int> conv;
int check_reg(int l, int r, string &s){
    int bil = 0;
    for(int i = l ; i <= r; i++){
        if(s[i] == '('){
            bil++;
        } else {
            bil--;
        }
        if(bil < 0) return 0;
    }
    if(bil == 0) 
        return 1;
    return 0;
}

int numofreg(string &s){
    int ans = 0;
    for(int i = 0; i < s.size(); i++){
        for(int j = i + 1; j < s.size(); j += 2){
            ans += check_reg(i,j,s);
        }
    }
    return ans;
}

int check(int mask){
    string s = "";
    // string masks = "";
    
    for(int i = 0; i < quest.size(); i++){
        if(quest[i] == '0'){
            // s[i] = '(';
            s.push_back('(');
        } else {
            if(mask&(1 << (quest[i] - '1'))){
                // s[i] = '(';
                s.push_back('(');
            } else {
                // s[i] = ')';
                s.push_back(')');
            }
        }
    }
    int ans = numofreg(s); 
    
    conv[mask] = ans;
    return ans;
}

int solve(int n){
    // cin >> n;
    ans.clear();
    int pot = (1 << n);
    int tans;
    for(int i = 0; i < pot; i++){
        tans = check(i);
        // if(ans.count(tans)) cout << tans << "\n";
        ans.insert(tans);
    }
    // cout << "---------\n";
    cout << ans.size() << "\n";
    // cout << conv << "\n";
    // for(auto it = conv.begin(); it != conv.end(); it++){
    //     cout << (*it).st << " " << (*it).nd << "\n";
    // }
    if(ans.size() == pot){
        cout << "YES\n";
        return true;
    } else {
        cout << "NO\n";
        return false;
    }
}

int RA(int l, int r){
    return (rand() % (r - l + 1)) + l;
}

void find_quest(int d, int n){
    quest = "";
    for(int i = 0; i < d; i++){
        int x = RA(1, 3 * n);
        if(x > n){
            quest.push_back('0');
        } else {
            quest.push_back(x + '0');
        }
    }
}
 
int32_t main(){
    // BOOST;
 
    int q = 1; //cin >> q;
    int d = 700;
    int n; cin >> n;
    while(true){
        find_quest(d,n);
        if(solve(n)) break;
    }
    cout << quest << "\n";
    return 0;
}
