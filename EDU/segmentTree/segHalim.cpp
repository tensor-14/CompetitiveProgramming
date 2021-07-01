#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
private:
    vector<int> st, A;
    int n;
    int left(int p){
        return p<<1;
    }
    int right(int p){
        return (p<<1)+1;
    }

    void build(int p, int L, int R){
        if(L==R)
            st[p]=L;
        else{
            //Creating the whole tree before feeding the minimum value indices to the nodes
            build(left(p), L, (L+R)/2);
            build(right(p), (L+R)/2+1, R);

            //Inserting all the min val indices through proper comparisons after creating all the segments
            int p1=st[left(p)], p2=st[right(p)];
            st[p]=(A[p1]<=A[p2])?p1:p2;
        }
    }

    void update(int p, int val){}


    int rmq(int p, int L, int R, int i, int j){
        if(i>R || j<L)
            return -1;
        if(L>=i && R<=j)
            return st[p];

        int p1=rmq(left(p), L, (R+L)/2, i, j);
        int p2=rmq(right(p), (L+R)/2+1, R, i, j);

        if(p1==-1)
            return p2;
        if(p2==-1)
            return p1;
        return (A[p1]<=A[p2])?p1:p2;
    }

public:
    SegmentTree(const vector<int> &_A){
        A=_A;
        n=(int)A.size();
        st.assign(4*n, 0);
        build(1, 0, n-1);
    }
    int rmq(int i, int j){
        return rmq(1, 0, n-1, i, j);
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto& x:a)
        cin>>x;
    
    SegmentTree st(a);

    for(auto x:a)
        cout<<x<<" ";
    cout<<endl;
    cout<<"RMQ(2, 5): "<<st.rmq(2, 5)<<endl;
    cout<<"RMQ(0, 6): "<<st.rmq(0, 6)<<endl;
    return 0;
}