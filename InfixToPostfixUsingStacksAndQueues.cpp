#include<bits/stdc++.h>
using namespace std;
#define SIZE 50
char s[SIZE];
int top=-1; 

void push(char elem)
{                       
    s[++top]=elem;
}
 
char pop()
{                      
    return(s[top--]);
}
 
int pr(char elem)
{                 
    switch(elem)
    {
    case '#': return 0;
    case '(': return 1;
    case '+':
    case '-': return 2;
    case '*':
    case '/': return 3;
    }
}
 int main()
{                        
    char infx[50],pofx[50],ch,elem;
    int front=0,rear=0;
    int i=0,k=0;
    cout << "Enter The Infix Expression"<< endl;
    cin >> infx;
    push('#');
    while( (ch=infx[i++]) != '\0')
    {
    if( ch == '(') push(ch);
    else
    if(isalnum(ch)){
     pofx[rear++]=ch;
    }
      else
    if( ch == ')')
    {
        while( s[top] != '(')
      pofx[rear++]=pop();
        elem=pop(); 
    }
    else
    {       
        while( pr(s[top]) >= pr(ch) )
      pofx[rear++]=pop();
        push(ch);
    }
    }
    while( s[top] != '#')     
  pofx[rear++]=pop();
    pofx[rear]='\0';          
    cout << "Postfix Expression:";
    for (i = front; i < rear; i++) { 
            cout << pofx[i]; 
        } 
}