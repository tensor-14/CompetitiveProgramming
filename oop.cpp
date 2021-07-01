#include<bits/stdc++.h>
using namespace std;

class Gamer{
    public:
        Gamer(int g){
            cout<<"I am a Gamer."<<g<<endl;
        }
        void experience(){
            cout<<"I am a good Gamer."<<endl;
        }
};

class Coder{
    public:
        Coder(int c){
            cout<<"I am a Competitive Programmer."<<c<<endl;
        }
        void experience(){
            cout<<"I am a beginner in CP."<<endl;
        }
};

class Me: public Coder, public Gamer{
    public:
        Me(int c, int g): Coder(c), Gamer(g){
            cout<<"I am carrying out an exp."<<endl;
        }
};

int main(){
    Me m(1, 2);

    m.Coder::experience();
    m.Gamer::experience();

    Coder c=m; //slicing
    Gamer g=m;
    c.experience();
    g.experience();

    static_cast<Coder>(m).experience();
    static_cast<Gamer>(m).experience();

    return 0;
}

/*
class Base{
    private:
        int pri=1;
    protected:
        int prot=2;
    public:
        int pub=3;
        void change(){
            pri=4;
        }
};

class Derived : public Base{
    public:
        void print(){
            prot=5;
            cout<<"Public:"<<pub<<endl;
            cout<<"Protected:"<<prot<<endl;
            //cout<<"Private:"<<pri<<endl;
        }
};

void fun();

int main(){
    Base b;
    Derived d;
    d.print();
    b.change();

    //fun();
}

void fun(){
    cout<<"Fun"<<endl;
    main();
}

*/