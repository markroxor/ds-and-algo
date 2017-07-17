#include<stdio.h>
#include<string.h>
using namespace std;

class Stack
{
public:
    int N;
    int top;
    char *array;
    Stack(int N);
    void push(char e);
    char pop();
    char peek();
    int isEmpty();
};

Stack::Stack(int n)
{
    this->top = 0;
    this->N = n;
    this->array = new char[n];
};

void Stack::push(char e)
{
    this->array[this->top++]=e;
}
char Stack::pop()
{
    return this->array[--top];
};

char Stack::peek()
{
    return this->array[top-1];
};

int Stack::isEmpty()
{
    return not this->top;
}

int prec(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

int isOperand(char e)
{
    return (e>='a' and e<='z') or (e>='A' and e<='Z');
}

int infix2Postfix(char *exp)
{
    Stack stack(strlen(exp));
    int i,k;
    for(i=0,k=0;i<strlen(exp);i++)
    {

       if(isOperand(exp[i]))
       {
            exp[k++]=exp[i];
       }
       else if(exp[i]!='(' and exp[i]!=')')
        {
            while(not stack.isEmpty() and prec(exp[i])<=prec(stack.peek()))
                exp[k++] = stack.pop();
            stack.push(exp[i]);
        }
       else if(exp[i]=='(')
           stack.push(exp[i]);

       else if(exp[i]==')')
       {
           while(!stack.isEmpty() and stack.peek()!='(')
           {
            exp[k++] = stack.pop();
           }

           stack.pop();
       }
       
    }    
     
    while(!stack.isEmpty())
        exp[k++]=stack.pop();

    exp[k++]='\0'; 
    printf("Final expression - %s",exp);
}

int main()
{
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    infix2Postfix(exp);
   
    return 0;
}
