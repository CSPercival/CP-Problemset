#include<bits/stdc++.h>

using namespace std;

// int prio = 1;

struct Node{
    int k, p;
    int s;
    Node *l;
    Node *r;
    Node(int ik) : k(ik), p(rand()), s(1), l(NULL), r(NULL) {}

    void update(){
        s = 1;
        if(l) s += l->s;
        if(r) s += r->s;
    }
};


int siz(Node *t){
    return t ? t->s : 0;
}

Node* find(Node *t, int k){
    if(!t || t->k == k) return t;
    return find(k < t->k ? t->l : t->r, k);
}

void split(Node *t, Node *&lt, Node *&rt, int split_key){
    if(!t){
        lt = NULL;
        rt = NULL;
    } else if(t->k <= split_key){
        split(t->r, t->r, rt, split_key);
        lt = t;
        lt->update();
    } else {
        split(t->l, lt, t->l, split_key);
        rt = t;
        rt->update();
    }
}

void merge(Node *&t, Node *lt, Node *rt){
    if(!lt) {t = rt; return;}
    if(!rt) {t = lt; return;}
    if(lt->p > rt->p){
        merge(lt->r, lt->r, rt);
        t = lt;
    } else {
        merge(rt->l, lt, rt->l);
        t = rt;
    }
    t->update();
}

void insert(Node *&t, Node *item){
    Node *l; 
    Node *r;
    split(t, l, r, item->k);
    merge(l, l, item);
    merge(t, l, r);
}

void erase(Node *&t, int key){
    Node *l; 
    Node *r;
    split(t, l, r, key);
    split(l, l, t, key - 1);
    merge(t, l, r);
}

int kth(Node *t, int k){
    assert(t->s >= k);
    if(k <= siz(t->l)){
        return kth(t->l , k);
    }
    k -= siz(t->l);
    if(k == 1) return t->k;
    return kth(t->r, k - 1);
}

int count(Node *t, int k){
    if(!t) return 0;
    if(t->k <= k){
        return siz(t->l) + (t->k != k) + count(t->r, k);
    } else {
        return count(t->l, k);
    }
}

void print_node(Node *t, int shift){
    for(int i = 0; i < shift; i++){
        cout << "    ";
    }
    if(!t){ cout << "NULL\n"; return; }
    // printf("(%d, %d) - s: %d\n",t->k, t->p, t->s);
    cout << "( " << t->k << ", " << t->p << " ) - s: " << t->s << "\n";
}

void print_treap(Node *t, int shift){
    if(!t){
        print_node(t, shift);
        return;
    }
    print_treap(t->r, shift + 1);
    print_node(t, shift);
    print_treap(t->l, shift + 1);
}

int main(){
    srand(128);
    ios_base::sync_with_stdio(false);
    cin.tie();

    Node *t = NULL;
    Node *item;

    int q; cin >> q;
    char action;
    int x;
    
    while(q--){
        cin >> action;
        cin >> x;
        switch(action){
            case 'I':
                if(find(t, x)) break;
                item = new Node(x);
                insert(t, item);
                // print_treap(t, 0);
                // cout << "\n--------------------------------------------\n";
                break;
            case 'D':
                erase(t, x);
                // print_treap(t, 0);
                // cout << "\n--------------------------------------------\n";
                break;
            case 'K':
                if(!t || t->s < x){
                    cout << "invalid\n";
                    break;
                }
                cout << kth(t, x) << "\n";
                break;
            case 'C':
                cout << count(t, x) << "\n";
        }
        // print_treap(t, 0);
        // cout << "\n--------------------------------------------\n";
        
    }
}