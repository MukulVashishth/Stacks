int prec(char c)
{
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}
 
string infixToPostfix(string s)
{
    stack<char> stk;
    stk.push('N');
    
    int l = s.length();
    
    string ns;
    
    for(int i = 0; i < l; i++)
    {
        if((s[i] >= 'a' && s[i] <= 'z')||
                (s[i] >= 'A' && s[i] <= 'Z'))
            ns+=s[i];
 
        else if(s[i] == '(')
        
        stk.push('(');
        
        else if(s[i] == ')')
        {
            while(stk.top() != 'N' && stk.top() != '(')
            {
                char c = stk.top();
                stk.pop();
                
                ns += c;
            }
            if(stk.top() == '(')
            {
                char c = stk.top();
                stk.pop();
            }
        }
     
        else{
            while(stk.top() != 'N' && prec(s[i]) <= prec(stk.top()))
            {
                char c = stk.top();
                stk.pop();
                ns += c;
            }
            
            stk.push(s[i]);
        }
    }
    
    while(stk.top() != 'N')
    {
        char c = stk.top();
        stk.pop();
        ns += c;
    }
    
    return ns;
}