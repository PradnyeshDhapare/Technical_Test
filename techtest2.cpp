#include<iostream>
#include <bits/stdc++.h>
using namespace std;
/* select precedence */
int precedence(char op){
    if(op == '+'||op == '-')
    return 1;
    if(op == '*'||op == '/')
    return 2;
    return 0;
}
 

int applyOp(int a, int b, char op){
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
}
 

int evaluate(string tokens){
    int i;
     
    stack <int> values;
     
    stack <char> ops;
     
    for(i = 0; i < tokens.length(); i++){
         
        /* If token is digit */

        if(isdigit(tokens[i])){
            int val = 0;

            while(i < tokens.length() &&
                        isdigit(tokens[i]))
            {
                val = (val*10) + (tokens[i]-'0');
                i++;
            }
             
            values.push(val);

              i--;
        }
         
        /* If token is operator */
        else
        {

            while(!ops.empty() && precedence(ops.top())
                                >= precedence(tokens[i])){
                int val2 = values.top();
                values.pop();
                 
                int val1 = values.top();
                values.pop();
                 
                char op = ops.top();
                ops.pop();
                 
                values.push(applyOp(val1, val2, op));
            }
             

            ops.push(tokens[i]);
        }
    }
     
 
    while(!ops.empty()){
        int val2 = values.top();
        values.pop();
                 
        int val1 = values.top();
        values.pop();
                 
        char op = ops.top();
        ops.pop();
                 
        values.push(applyOp(val1, val2, op));
    }
     
    return values.top();
}
int main()
{
    int a,b,c,d;
    char arr[]={'/','*','+','-'};
    cout<<"enter numbers"<<endl;
    cin>>a>>b>>c>>d;
    int count=0;
    for(int i=0;i<4;i++)
    {
        
        for(int j=0;j<4;j++)
        {
             
             for(int k=0;k<4;k++)
            {
               string  sExpression = std::to_string(a)+arr[i]+std::to_string(b)+arr[j]+std::to_string(c)+arr[k]+std::to_string(d);
                cout<<std::to_string(a)<<arr[i]<<std::to_string(b)<<arr[j]<<std::to_string(c)<<arr[k]<<std::to_string(d)<<" = "<<evaluate(sExpression)<<endl;
                count++;

                
            }
        }
    }
    cout<<count;
    return 0;
}
