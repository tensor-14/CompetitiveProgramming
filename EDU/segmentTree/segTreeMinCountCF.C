#include<bits/stdc++.h>
using namespace std;

struct item{
    int m, c;
};

struct segtree{
    int size;
    vector<item> values;

    item NEUTRAL_ELEMENT = {INT_MAX, 0};

    item merge(item a, item b){
        if(a.m < b.m)
            return a;
        if(a.m >b.m)
            return b;
        return {a.m, a.c+b.c};
    }

    void init(int n){
        size=1;
        while(size<n)
            size*=2;
        values.resize(2*size);
    }

    void build(vector<int> &a, int x, int lx, int rx){
        if(rx-lx==1){
            if(lx<(int)a.size()){
                values[x]= {a[lx], 1};
            }
            return;
        }
        int m=(lx+rx)/2;
        build(a, 2*x+1, lx, m);
        build(a, 2*x+2, m, rx);
        values[x]=merge(values[2*x+1], values[2*x+2]);
    }

    void build(vector<int> &a){
        build(a, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx){
        if(rx-lx==1){
            values[x]= {v, 1};
            return;
        }
        int m=(lx+rx)/2;
        if(i<m){
            set(i, v, 2*x+1, lx, m);
        }
        else{
            set(i, v, 2*x+2, m, rx);
        }
        values[x]=merge(values[2*x+1], values[2*x+2]);
    }

    void set(int i, int v){
        set(i, v, 0, 0, size);
    }

    item minCount(int l, int r, int x, int lx, int rx){
        if(lx>=r || l>=rx)
            return NEUTRAL_ELEMENT;
        if(lx>=l && r>=rx)
            return values[x];
        
        int m=(lx+rx)/2;
        item m1=minCount(l, r, 2*x+1, lx, m);
        item m2=minCount(l, r, 2*x+2, m, rx);
        return merge(m1, m2);
    }

    item minCount(int l, int r){
        return minCount(l, r, 0, 0, size);
    }
};


int main(){
    ios::sync_with_stdio(false);

    int n, m;
    cin>>n>>m;

    segtree st;
    st.init(n);
    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin>>a[i];
    
    st.build(a);
    /*
    for(int i=0; i<n; i++){
        int v;
        cin>>v;
        st.set(i, v);
    }
    */
    while(m--){
        int op;
        cin>>op;
        if(op==1){
            int i, v;
            cin>>i>>v;
            st.set(i, v);
        }
        else{
            int l, r;
            cin>>l>>r;
            auto res=st.minCount(l, r);
            cout<<res.m<<" "<<res.c<<"\n";
        }
    }
    return 0;
}