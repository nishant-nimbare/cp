#include <bits/stdc++.h>

#define DEBUG true

#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

using namespace std;

/*** 
 * infix to postfix
  
1. Scan the infix expression from left to right.
2. If the scanned character is an operand, output it.
3. Else,
…..3.1 If the precedence of the scanned operator is greater than the precedence of the operator in the stack(or the stack is empty or the stack contains a ‘(‘ ), push it.
…..3.2 Else, Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator. After doing that Push the scanned operator to the stack. (If you encounter parenthesis while popping then stop there and push the scanned operator in the stack.)
4. If the scanned character is an ‘(‘, push it to the stack.
5. If the scanned character is an ‘)’, pop the stack and and output it until a ‘(‘ is encountered, and discard both the parenthesis.
6. Repeat steps 2-6 until infix expression is scanned.
7. Print the output
8. Pop and output from the stack until it is not empty.

***/


/***
 * INFIX to PREFIX
 * 
 *  Reverse the infix expression i.e A+B*C will become C*B+A. Note while reversing each ‘(‘ will become ‘)’ and each ‘)’ becomes ‘(‘.
 *  Obtain the postfix expression of the modified expression i.e CB*A+.
 *  Reverse the postfix expression. Hence in our example prefix is +A*BC.
 * 
 * **/

int precedence(char op){

    if(op=='+' || op=='-') return 1;

    if(op=='*' || op=='/') return 2;

    if(op=='^' ) return 3;

    if( op=='(') return 4;

    if (op==')' ) return 5;
    
    return 0;
}

char rev(char c){
    if(c == '(') return ')';
    if(c == ')') return '(';
    
    return c;
}

string infixToPostfix(string infix){

    stringstream postfix;

    vector<char> stac;

    for(int i=0; i<infix.size(); i++){

        dout<<"currrent "<<infix[i]<<"\n";

        int pred = precedence(infix[i]);

        if(pred == 4){
            stac.push_back(infix[i]);
        }
        else if (pred == 5){
            while(stac.size() && stac.back()!='('){
                postfix<<stac.back();
                stac.pop_back();
            }

            if(stac.back()=='(') stac.pop_back();

        }
        else if(pred>0){

            while(stac.size() && stac.back()!='(' && pred <= precedence(stac.back()) ){
                postfix<<stac.back();
                stac.pop_back();
            }

            stac.push_back(infix[i]);

        }else{
            //operand 
            postfix<<infix[i];
        }
    }

    // add whatever is remaining in stac
    while(stac.size()){
        postfix<<stac.back();
        stac.pop_back();
    }

    return postfix.str();
}



string infixtoPrefix(string infix){

    int l = 0, r=infix.size()-1;

    while(l<r){
        infix[l] = rev(infix[l]);
        infix[r] = rev(infix[r]);
         
        swap( infix[l++] , infix[r--] );
        
    }

    dout<<" after reversing "<<infix<<"\n";

    string res = infixToPostfix(infix);

    reverse(res.begin(), res.end());

    return res;
}

int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    getline(cin, str);

    cout<<infixtoPrefix(str)<<"\n";
    
    return 0;
}