#include<iostream>
using namespace std;

struct Node
{
    int col;
    int data;
    Node*next=0;
};
void Delete(int ** A,int r,int c)
{
    for(int i=0;i<r;i++)
        delete A[i];
    delete A;
}
int main()
{
    int r,c;
    cout<<"Enter no of rows and columns: ";
    cin>>r>>c;
    cout<<"Matrix 1-\n";
    int **A=new int*[r];
    for(int i=0;i<r;i++)
        A[i]=new int [c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            cin>>A[i][j];
    }

     cout<<"Matrix 2-\n";
    int **B=new int*[r];
    for(int i=0;i<r;i++)
        B[i]=new int [c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            cin>>B[i][j];
    }



    /////Storing matrix 1
    Node**a=new Node*[r]{0};

    for(int i=0;i<r;i++)
    {Node*p;
        for(int j=0;j<c;j++)
        {
            if(A[i][j]!=0)
            {
             if(!a[i])
             {
                 a[i]=new Node;
                 a[i]->col=j;
                 a[i]->data=A[i][j];
                 p=a[i];
             }
             else
             {
                 p->next=new Node;
                 p=p->next;
                 p->col=j;
                 p->data=A[i][j];
             }
            }

        }
    }

     /////Storing matrix 2
    Node**b=new Node*[r]{0};

    for(int i=0;i<r;i++)
    {Node*p;
        for(int j=0;j<c;j++)
        {
            if(B[i][j]!=0)
            {
             if(!b[i])
             {
                 b[i]=new Node;
                 b[i]->col=j;
                 b[i]->data=B[i][j];
                 p=b[i];

             }
             else
             {
                 p->next=new Node;
                 p=p->next;
                 p->col=j;
                 p->data=B[i][j];

             }
            }

        }
    }

Delete(A,r,c);
Delete(B,r,c);
cout<<"Both Matrices are deleted\n";
    ///displaying:
    cout<<"Matrix 1:\n";
    for(int i=0;i<r;i++)
    {
        Node*p=a[i];
        for(int j=0;j<c;j++)
        {
            if(p)
            {
                if(j==p->col)
                {
                    cout<<p->data<<" ";
                    p=p->next;
                }
                else cout<<"0 ";

            }

            else cout<<"0 ";

        }
        cout<<endl;
    }

    cout<<"Matrix 2:\n";
    for(int i=0;i<r;i++)
    {
       Node* p=b[i];
        for(int j=0;j<c;j++)
        {
            if(p){
                if(j==p->col)
                    {
                        cout<<p->data<<" ";
                        p=p->next;
                    }
                else cout<<"0 ";
            }
            else cout<<"0 ";
        }
        cout<<endl;
    }
    Node**ca=new Node*[r]{0};

    cout<<"Adding two matrices:\n";
    for(int i=0;i<r;i++)
    {
       Node*p{a[i]},*q{b[i]},*s{ca[i]};
       Node sample;
       while(p&&q)
       {
           if(p->col>q->col)
           {
            sample=*q;
            q=q->next;

           }

           else if(p->col<q->col)
           {
               sample=*p;
               p=p->next;
           }

           else if(p->col==q->col)
           {
              sample=*p;
              sample.data=p->data+q->data;
              q=q->next;
              p=p->next;
           }
           if(!ca[i])
           {
               ca[i]=new Node;
               s=ca[i];
               s->data=sample.data;
               s->col=sample.col;
           }

           else
           {
               s->next=new Node;
               s=s->next;
               s->data=sample.data;
               s->col=sample.col;
           }
       }
       while(p)
       {sample=*p;
        if(!ca[i])
           {
               ca[i]=new Node;
               s=ca[i];
               s->data=sample.data;
               s->col=sample.col;
           }

           else
           {
               s->next=new Node;
               s=s->next;
               s->data=sample.data;
               s->col=sample.col;
           }
           p=p->next;
       }
       while(q)
       { sample=*q;
           if(!ca[i])
           {
               ca[i]=new Node;
               s=ca[i];
               s->data=sample.data;
               s->col=sample.col;
           }

           else
           {
               s->next=new Node;
               s=s->next;
               s->data=sample.data;
               s->col=sample.col;
           }
           q=q->next;

       }
    }


    for(int i=0;i<r;i++)
    {
       Node* p=ca[i];
        for(int j=0;j<c;j++)
        {
            if(p){
                if(j==p->col)
                    {
                        cout<<p->data<<" ";
                        p=p->next;
                    }
                else cout<<"0 ";
            }
            else cout<<"0 ";
        }
        cout<<endl;
    }
}
