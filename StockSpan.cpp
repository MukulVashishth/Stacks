#include<bits/stdc++.h>
using namespace std;

vector <int> calculateSpan(int price[], int n)
{
    vector <int> vec(n,0);

    vec[0]=1;

    stack<int> stk;
    stk.push(0);

    for(int i=1;i<n;i++)
    {
        //finding the element which is smalller tha the current i and then popping until
        //there are smaller elements than current i and stopping when a greater element is found
        //storing i-indexofgreaterelemnt(stk.top())
        while(!stk.empty() && price[stk.top()] <= price[i]) 
            stk.pop();
        vec[i] = (stk.empty() ? (i+1) : (i-stk.top()));
        stk.push(i);
    }

    return vec;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		
		vector <int> s = calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}