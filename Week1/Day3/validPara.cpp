// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    stack<int>st;
    for(char ch:s){
        if(ch=='['||ch=='{'||ch=='(')st.push(ch);
        else{
            if(st.empty()){
              cout<<"Invalid";
              return 0;
            }else{
                char top = st.top();st.pop();
                if(ch==')'&&top!='('||ch==']'&&top!='['||ch=='}'&&top!='{'){
                    cout<<"Invalid";
                    return 0;
                }
            }
            
        }
    }
    if(!st.empty()){
        cout<<"Invalid";
    }else{
        cout<<"Valid";
    }
    return 0;
}