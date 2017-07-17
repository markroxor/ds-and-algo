#include<stdio.h>
using namespace std;

class Stack
{
    int capacity;
    int cur;
    char *array;
public:
    Stack(int n);
    char pop();
    bool isEmpty();
    void push(char c);
    char peek();
};

Stack::Stack(int cap)
{
    capacity = cap;
    array = new char[cap];
    cur=0;
};

char Stack::pop()
{
    return array[--cur];
};

char Stack::peek()
{
    return array[cur-1];
}
void Stack::push(char c)
{
    array[cur++]=c;
}

bool Stack::isEmpty()
{
    return not cur;
}

bool isOperand(char c)
{
    return ('z'>=c and c>='a') or ('Z'>=c and c>='A');        
}


int prec(char c)
{
    switch (c)
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

void infixToPostfix(char *exp)
{
    int len;
    for(len=0;exp[len]!='\0';len++);

    Stack stack(len);
    int i,k;

    for(i=0,k=0;i<len;i++)
    {
        if (isOperand(exp[i]))
            exp[k++]=exp[i];
        else if (exp[i]=='(')
        {
            stack.push('(');
        }
        else if (exp[i]==')')
        {
            while(!stack.isEmpty() and stack.peek()!='(')
            {
                exp[k++]=stack.pop();
            }
            stack.pop();
        }
        else
        {
            while(!stack.isEmpty() and prec(exp[i])<=prec(stack.peek()))
                exp[k++] = stack.pop();
            stack.push(exp[i]);
        }
    }

    while(!stack.isEmpty())
        exp[k++] = stack.pop();
    
    exp[k]='\0';
    printf("%s\n",exp);
}

int isDigit(char exp)
{
    return ('9'>=exp and exp>='0');
}

int evalPostfix(char *exp)
{
    int len;
    for(len = 0; exp[len]!='\0'; len++);
    Stack dstack(len);
    
    for(int i=0;i<len;i++)
    {
        if(isDigit(exp[i]))
            dstack.push(exp[i]-'0');

        else
        {
            char last = dstack.pop();
            char slast = dstack.pop();
            switch(exp[i])
            {
                case '+':
                    dstack.push(slast+last);
                    break;
                case '-':
                    dstack.push(slast-last);
                    break;
                case '*':
                    dstack.push(slast*last);
                    break;
                case '/':
                    dstack.push(slast/last);
                    break;
            }
        }
        //printf("%d\n",dstack.peek());
    }
    return dstack.pop();

}

main()
{
    char exp[] = "231*+9-";
    printf ("Value of %s is %d\n", exp, evalPostfix(exp));
    return 0;
    
    char exp1[] = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp1);
   
    return 0;
    Stack stack(5);
    stack.push('q');
    stack.push('w');
    stack.push('e');
    stack.push('r');
    stack.push('t');
    stack.push('y');

    printf("%c\n",stack.pop());
    printf("%c\n",stack.peek());
    while(!stack.isEmpty())
        printf("%c ",stack.pop());
    return 0;
}
