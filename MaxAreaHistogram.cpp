#include <bits/stdc++.h>
using namespace std;

long getMaxArea(long long arr[], int n)
{
                        //NSL
    int sudo =-1;
    vector<long long>left;
    stack<pair<long long,long long>>stk;

    for(auto i=0;i<n;i++)
    {
        if(stk.size() == 0)
            left.push_back(sudo);
        else if(stk.size()>0 && stk.top().first < arr[i])
            left.push_back(stk.top().second);
        else if(stk.size()>0 && stk.top().first >= arr[i])
        {
            while(stk.size()>0 && stk.top().first >=arr[i])
                stk.pop();
            if(stk.size()==0)
                left.push_back(-1);
            else
                left.push_back(stk.top().second);
        }
        stk.push({arr[i],i});
    }    

    
                        //NSR
    vector<long long>right;
    stack<pair<long long,long long>>stk1;
    long long sudo1 = n;

    for(auto i=n-1;i>=0;i--)
    {
        if(stk1.size()==0)
            right.push_back(sudo1);
        else if(stk1.size()>0 && stk1.top().first < arr[i])
            right.push_back(stk1.top().second);
        else if(stk1.size()>0 && stk1.top().first >= arr[i])
        {
            while(stk1.size()>0 && stk1.top().first >=arr[i])
                stk1.pop();
            if(stk1.size()==0)
                right.push_back(sudo1);
            else
                right.push_back(stk1.top().second);
        }
        stk1.push({arr[i],i});
    }
    reverse(right.begin() , right.end());

    vector<long long> width(n,0);
    for(auto i=0;i<n;i++)
        width[i]=right[i]-left[i]-1;

    vector<long long>area(n,0);
    for(auto i=0;i<n;i++)
        area[i]=arr[i]*width[i];
    
    long mxm = *max_element(area.begin() , area.end());
    return mxm;
}

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        cout << getMaxArea(arr, n) << endl;
    
    }
	return 0;
}