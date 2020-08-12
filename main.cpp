#include<iostream>
#include<cmath>
using namespace std;

//we will use a Node to represent each term of the polynomial
//Each term can be represented only by storing its coefficient and power
struct Node
{
    int coeff;
    int power;
    Node*next=0;
};

class Polynomial
{
    Node*head{};
public:
    Polynomial(int n);
    ~Polynomial();
    void display();

    friend Polynomial operator +(Polynomial,Polynomial);

};

Polynomial::Polynomial(int n=0)
{
    if(n==0)
    {
        head=0;
        return;
    }
    Node*p;
    cout<<"Enter coefficient and power of each term-\n";
    for(int i=1;i<=n;i++)
    {
        int coeff,power;
        cout<<"Term "<<i<<"-";
        cin>>coeff>>power;
        if(!head)
        {
            head=new Node;
            p=head;
            p->coeff=coeff;
            p->power=power;
        }
        else
        {
            p->next=new Node;
            p=p->next;
            p->coeff=coeff;
            p->power=power;

        }
    }
}

Polynomial::~Polynomial()
{
    Node*p{head},*q{0};
    while(p)
    {
        q=p;
        p=p->next;
        delete q;
    }
}

void Polynomial::display()
{
    if(head==0)
{
    cout<<"()\n";
    return;
}

    Node*p=head;
    while(p)
    {
        cout<<"("<<p->coeff<<"x^"<<p->power<<")+ ";
        p=p->next;
    }
    cout<<"\b\b  \n";

}

Polynomial operator +(Polynomial a,Polynomial b)
{
    Polynomial c;
    Node*p{a.head},*q{b.head},*r,sample;
    while(p&&q)
    {
        if(p->power>q->power)
        {
            sample=*p;
            p=p->next;
        }
        else if(p->power<q->power)
        {
            sample=*q;
            q=q->next;
        }
        else
        {
            sample=*p;
            sample.coeff=p->coeff+q->coeff;
            p=p->next;
            q=q->next;
        }
        if(!c.head)
        {
            c.head=new Node;
            r=c.head;
            *r=sample;
        }
        else
        {
            r->next=new Node;
            r=r->next;
            *r=sample;
        }

}

while(p)
{
    sample=*p;
    p=p->next;

    if(!c.head)
        {
            c.head=new Node;
            r=c.head;

            *r=sample;
        }
        else
        {
            r->next=new Node;
            r=r->next;
            *r=sample;
        }
}

while(q)
{
    sample=*q;
    q=q->next;

    if(!c.head)
        {
            c.head=new Node{sample};
            r=c.head;
        }
        else
        {
            r->next=new Node{sample};
            r=r->next;
        }
}


return c;
}
int main()
{
    cout<<"Enter no of terms in polynomial 1-";
    int n;
    cin>>n;
    Polynomial p(n);
    p.display();

    cout<<"Enter no of terms in polynomial 2-";
    cin>>n;
    Polynomial q(n);
    q.display();

    Polynomial r;
    r=p+q;
    r.display();
}
