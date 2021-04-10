#include <iostream>
#include <string>
#include <vector>
//===============
class Term   
{
    int a,k; //a*x^k
    public:
    Term(int ta,int tk)
    {
        a=ta;
        k=tk;
    }
};
//========
class Polynomial
{
private:
    //Term *head,*tail;
    Term* next;
public:
    Polynomial(Term t)
    {
       
    }
    void add(Polynomial p){

    }
};

int main()
{
    Polynomial p(Term(-10,0));
    p.add(Polynomial(Term(-1,1)));
    p.add(Polynomial(Term(-1,1)));
    p.add(Polynomial(Term(-1,1)));
    return 0;
}
