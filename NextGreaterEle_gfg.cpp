#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int ans[n];
    arr[0] = 1211;
    for(int i=1;i<=n;i++)
        cin >> arr[i];
    stack<pair<int,int>> stk;
    for(int i=n;i>=1;i--)
    {
        while(!stk.empty() && arr[i]>=stk.top().first)
            stk.pop();
        ans[i] = stk.empty() ? 0 : ((stk.top().second) - i);
        stk.push({arr[i],i});
    }

    for(int i=1;i<=n;i++)
        cout << ans[i] << " ";
    
    cout << endl;
}   