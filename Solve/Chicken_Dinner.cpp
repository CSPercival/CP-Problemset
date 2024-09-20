#include<bits/stdc++.h>
#define st first
#define nd second
#define all(x) x.begin(), x.end()
#define BOOST cin.tie(NULL); ios_base::sync_with_stdio(false);
 
// #define int ll
typedef long long ll;
typedef long double ld;

using namespace std;
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }

ld EPS = 1e-6;
ld EPS2 = 1e-12;

struct Point{
    ld x,y;
    Point operator+(const Point& a){ return {x + a.x, y + a.y}; }
    Point operator-(const Point& a){ return {x - a.x, y - a.y}; }
    Point operator*(const ld d){ return {x * d, y * d}; }
    Point operator/(const ld d){ return {x / d, y / d}; }
    bool operator==(const Point& a){ return ((x == a.x) && (y == a.y));}
    bool operator!=(const Point& a){ return ((x != a.x) || (y != a.y));}

    void print(){cout << "[Point: " << x << " " << y << "]\n";}
};

struct Line{
    ld A,B,C;
    Line(ld a,ld b,ld c){A = a; B = b; C = c;}
    Line(Point p1, Point p2){
        A = p1.y - p2.y;
        B = p2.x - p1.x;
        C = ((-1) * A * p1.x) - (B * p1.y);
    }
    void move(Point v){ C -= (v.x * A) + (v.y * B); }
    void print(){cout << "[Line: " << A << " " << B << " " << C << "]\n";}
};

struct Circle{
    Point c;
    ld r;
    void print(){cout << "[Circle: " << c.x << " " << c.y << " " << r << "]\n";}
};

struct BGeo{

    ld dot(Point a, Point b){ return (a.x * b.x) + (a.y * b.y); }
    ld cross(Point a, Point b){ return (a.x * b.y) - (a.y * b.x); }
    ld len(Point a){ return sqrtl((a.x * a.x) + (a.y * a.y)); }
    ld dist2(Point a, Point b){ return len(a - b); }
    ld norm(Point a){ return dot(a,a); }
    bool clockwise(Point a, Point b, Point c){ return (cross(b - a, c - b) < 0);}

    Point projection(Point A, Circle C){ return projection(C,A);}
    Point projection(Circle C, Point A){
        Point tA = A - C.c;
        return (tA * C.r) / len(tA) + C.c;
    }

    pair<Point,Point> intersection(Circle C, Line L){ return intersection(L,C);}
    pair<Point,Point> intersection(Line L, Circle C){
        Line tL = L; tL.move(C.c * -1);

        Point v1 = {tL.B * (-1), tL.A};
        v1 = v1 / len(v1);

        Point proj = {((-1)* tL.C * tL.A) / ((tL.A * tL.A) + (tL.B * tL.B)), ((-1) * tL.C * tL.B) / ((tL.A * tL.A) + (tL.B * tL.B))};
        ld h = sqrtl((C.r * C.r) - dot(proj,proj));
        return {proj + (v1 * h) + C.c, proj - (v1 * h) + C.c};
    }

    pair<Point,Point> intersection(Circle C1, Circle C2){
        Circle tC1 = {0,0,C1.r};
        Circle tC2 = {C2.c - C1.c, C2.r};
        Line l1((-2) * tC2.c.x, (-2) * tC2.c.y, (tC2.c.x * tC2.c.x) + (tC2.c.y * tC2.c.y) + (tC1.r * tC1.r) - (tC2.r * tC2.r));
        pair<Point,Point> ans = intersection(tC1,l1);
        return {ans.st + C1.c, ans.nd + C1.c};
    }

    Point arc_mid(Circle C, Point A, Point B){
        assert(abs(dist2(A,B) - (2 * C.r)) > EPS);
        return projection(C, (B + A)/2.0);
    }

    Point arc_near_third(Circle C, Point A, Point B){
        Point mid = arc_mid(C,A,B);
        return arc_mid(C,arc_mid(C,A,mid),mid);
    }
};

struct CTS{
    // ld EPS = 1e-7;
    Point A,B;
    Circle C;
    function<ld(Point)> costf;
    BGeo calc;
    int mode;   // mode 0 -> /-\, mode 1 -> \_/

    CTS(Point p1, Point p2, Circle c1, function<ld(Point)> in_costf, int in_mode){
        A = p1; B = p2; C = c1; costf = in_costf; mode = in_mode;
    }

    Point go_ts(Point l, Point r){
        Point lmid, rmid;
        while(calc.norm(l - r) > EPS2){
            lmid = calc.arc_near_third(C,l,r);
            rmid = calc.arc_near_third(C,r,l);
            if((((int)(costf(lmid) < costf(rmid))) ^ mode)){
                l = lmid;
            } else {
                r = rmid;
            }
        }
        return calc.arc_mid(C,l,r);
    }

    Point find_best(int k){ // divide arc into k parts
        Point ans = (costf(A) < costf(B) ? A : B);
        Point shift = (B - A) / (ld)k;

        Point l = A, r = A + shift;
        Point tmpp, tmpl, tmpr;
        for(int i = 0; i < k; i++, l = r, r = r + shift){
            tmpl = calc.projection(C,l);
            tmpr = calc.projection(C,r);
            ans = (costf(ans) < costf(tmpr) ? ans : tmpr);
            tmpp = go_ts(tmpl, tmpr);
            ans = (costf(ans) < costf(tmpp) ? ans : tmpp);
        }
        return ans;
    }

};

void print_ans(ld ans){
    cout << fixed << setprecision(8) << ans << "\n";
}


void solve(){
    ld x1,y1,r1,d1,t,x2,y2,r2,d2; cin >> x1 >> y1 >> r1 >> d1 >> t >> x2 >> y2 >> r2 >> d2;
    Circle big = {x1,y1,r1}, small = {x2,y2,r2};
    Point start = {0,0};
    BGeo calc;

    if(calc.dist2(start,small.c) <= small.r){
        print_ans(0);
        return;
    }
    if(calc.dist2(start,big.c) <= big.r){
        ld h2 = calc.dist2(start,small.c) - small.r;
        if(h2 <= t){
            print_ans(0);
        } else {
            print_ans((h2 - t) * d2);
        }
        return;
    }
    if(calc.dist2(start,big.c) - big.r >= t){
        ld total = calc.dist2(start,small.c) - small.r;
        print_ans((t * d1) + ((total - t) * d2));
        return;
    }

    auto cost_function = [&calc,small,t,d1,d2](Point x){
        ld h1 = calc.len(x);
        ld h2 = calc.dist2(x,small.c) - small.r;
        if(h1 >= t) return (t * d1) + ((h1 + h2 - t) * d2);
        if((h1 + h2) <= t) return h1 * d1;
        return (h1 * d1) + ((h1 + h2 - t) * d2);
    };

    Point bestp, l, r;
    ld ans;

    Line l1(start, big.c);
    Line l2(start, small.c);
    pair<Point, Point> tmpp1, tmpp2;
    Point p1, p2;
    tmpp1 = calc.intersection(big, l1);
    tmpp2 = calc.intersection(big, l2);
    p1 = (calc.len(tmpp1.st) < calc.len(tmpp1.nd) ? tmpp1.st : tmpp1.nd);
    p2 = (calc.len(tmpp2.st) < calc.len(tmpp2.nd) ? tmpp2.st : tmpp2.nd);

    CTS algo(p1,p2,big,cost_function,1);
    bestp = algo.find_best(7);
    print_ans(cost_function(bestp));
}

 
int32_t main(){
    BOOST;
    
    int q = 1; cin >> q;
    while(q--){
        solve();
    }
    return 0;
}