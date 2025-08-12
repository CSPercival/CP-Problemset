#include <bits/stdc++.h>
#define st first
#define nd second

// #define int long long
typedef long long ll;
using namespace std;

vector<string> extc = {".c",".cc",".cpp",".cxx",".c++"};
vector<string> exto = {".java",".py",".kt"};

bool checkext(string *s, string &ext){
    if(ext.size() > s->size()) return false;
    for(int i = 0; i < ext.size(); i++){
        if((*s)[s->size() - i - 1] != ext[ext.size() - i - 1]) return false;
    }
    for(int i = 0; i < ext.size(); i++){
        s->pop_back();
    }
    return true;
}

int corrext(string *s){
    for(int i = 0; i < extc.size(); i++){
        if(checkext(s, extc[i])){
            return 1;
        }
    }
    for(int i = 0; i < exto.size(); i++){
        if(checkext(s, exto[i])){
            return i + 2;
        }
    }
    return 0;
}

int calctime(double x){
    if(x <= 1.0) return 1;
    return ((int)(x - 0.0001)) + 1;
}

int calctime2(map<int,double> &m){
    double quick = 2000,quick2 = 2000;
    for(auto i : m){
        if(i.nd < quick){
            quick2 = quick;
            quick = i.nd;
        } else {
            if(i.nd < quick2){
                quick2 = i.nd;
            }
        }
    }
    return calctime(quick2);
}

void solve() {
    int n; cin >> n;
    string task;
    double ttime;
    int ide;
    map<string,map<int, double>> tasks;
    for(int i = 0; i < n; i++){
        cin >> task >> ttime;
        ide = corrext(&task);
        if(ide){
            if(tasks[task].find(ide) == tasks[task].end()){
                tasks[task][ide] = 2000;
            }
            tasks[task][ide] = min(tasks[task][ide], ttime);
            // tasks[task].nd = max(tasks[task].nd, ttime);
        }
    }
    // vector<pair<string, int>> ans;
    for(auto t : tasks){
        if(t.nd.size() > 1){
            cout << t.st << " " << calctime2(t.nd) << "\n";
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; 
    // cin >> t;
    while (t--) {
        solve();
    }
    
}