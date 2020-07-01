#include<bits/stdc++.h>
using namespace std;
#define MAX 501

int getId(int M[MAX][MAX],int n);

int main()
{
    int T;
    cin>>T;
    int M[MAX][MAX];
    while(T--)
    {
        int N;
        cin>>N;
        memset(M,0,sizeof M);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>M[i][j];
            }
        }
        cout<<getId(M,N)<<endl;

    }
}

bool knows(int a , int b)
{
    return 
}

int getId(int M[MAX][MAX], int n)
{
    // //          NAIVE APPROACH
    // int celeb = -1;
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)                   // if every ith person knows j but j doesen't know anyone
    //     {
    //         if(M[i][j]==1 && M[j][i]==0)
    //                 celeb = j;
    //     }
    // }
    // return celeb;

    // //              Using stacks
    // stack<int>stk;
    // int celeb;

    // for(int i=0;i<n;i++)
    //     stk.push(i);
    // int p1 = stk.top();
    // stk.pop();
    // int p2 = stk.top();
    // stk.pop();

    // while(stk.size()>1)
    // {
    //     if(M[p1][p2])
    //     {
    //         p1 = stk.top();
    //         stk.pop();
    //     }
    //     else
    //     {
    //         p2 = stk.top();
    //         stk.pop();
    //     }
    // }

    // celeb = stk.top();
    // stk.pop();

    // if(M[celeb][p2])
    //     celeb = p2;
    
    // if(M[celeb][p1])
    //     celeb = p1;

    // for(int i=0;i<n;i++)
    // {
    //     if((i!=celeb) && (M[celeb][i] || !M[i][celeb]))
    //         return -1;
    // }

    // return celeb;

    //      Two pointer
}