/* 
 * Eval.cpp
 *
 * Description: Evaluation of infix expressions using two Stacks.
 *
 * Author:
 * Date:
 */

#include <iostream>
#include <cmath>
#include "Scanner.h"
#include "Stack.h"  // GENERIC STACK

using std::cout;
using std::endl;
using std::cin;

int calculate (int firstNum, int secondNum, TokenType operation);
void popAndCalc (Stack<Token>& numstack, Stack<Token>& opstack );

int main () {
    Scanner S(cin);
    Token t;

    Stack<Token> numstack;  // 2x Stacks of type Token
    Stack<Token> opstack;

    t = S.getnext();

    // Pretty printer coding demo.  Please remove before coding
    while (t.tt != eof) {
        /*if T is a number:
        push T to the number stack; get the next token */
        if (t.tt == integer){
            //cout <<"pushing " << t << " into number stack"<< endl;
            numstack.push(t);
            //t = S.getnext();
            //continue;
            
        } 
        /*else if T is a left parenthesis:
        push T to the operator stack; get the next token*/
        else if ( t.tt == lptok){
            //"( is lptok" 
            //cout <<"pushing " << t << " into number stack"<< endl;
            opstack.push(t);
            
        } 
        /*else if T is a right parenthesis:*/
        else if(t.tt == rptok) {
            //") is rptoke"
            /*if the top of the operator stack is a left parenthesis:
            pop it from the operator stack; get the next token:*/
            if (opstack.peek().tt == lptok ){
                opstack.pop();
                
            }
                   /*else:
            pop the top two numbers and the top operator
            perform the operation
            push the result to the number stack*/
            else {
                popAndCalc(numstack, opstack);
                opstack.pop();
            }
        } 
        /*else if T is +, - or EOF:*/
        else if (t.tt == pltok ||t.tt == mitok ){
           
            //"+ is pltok" and "- is mitok"
            //if the operator stack is nonempty and the top is one of +, -, *, /:
            Token last;
            
            if (!opstack.isEmpty()){
                
                last = opstack.peek();
                //cout <<"peeking at opstack, value = "<< last << endl;
                
                if (last.tt == pltok || last.tt == mitok || t.tt == asttok || t.tt == slashtok ){
                    /*pop the top two numbers and the top operator
                    perform the operation
                    push the result to the number stack*/
                    
                    popAndCalc(numstack, opstack);
                    //cout << "here" << endl;
                    opstack.push(t);
                    //cout <<"pushing " << t << " into operation stack"<< endl;
                }
            }
            //else:push T to the operator stack; get the next token*/
            else {
                //cout <<"pushing " << t << " into operation stack"<< endl;
                opstack.push(t);
                
            }
        }  
         //else if T is * or /:
        else if ( t.tt == asttok || t.tt == slashtok) {
            //"* is asttok" and "/ is slashtok"
            //if the operator stack is nonempty and the top is one of *, /:
            if (!numstack.isEmpty()){
            if ( t.tt == asttok || t.tt == slashtok){
                /*pop the top two numbers and the top operator
                perform the operation
                push the result to the number stack*/
                popAndCalc(numstack, opstack);
                opstack.push(t);
                //cout <<"pushing " << t << " into operation stack"<< endl;
            }  
            //else: push T to the operator stack; get the next token
            else {
                opstack.push(t);
                //cout <<"pushing " << t << " into operation stack"<< endl;
                
            }
            }
        }

            t = S.getnext();
            //cout << " next token is " << t << endl;
            //continue;
        } // end of while loop
        if (!opstack.isEmpty()){
                Token last; 
                last = opstack.peek();
                popAndCalc(numstack,opstack);
        }
        //cout << numstack.peek().val<< endl;

        // Pretty printer coding demo.  Please remove before coding
        /* while (t.tt != eof) {
        if (t.tt == integer || t.tt == lptok || t.tt == rptok) {
            cout << t;
        } else if (t.tt == pltok || t.tt == mitok || 
                   t.tt == asttok || t.tt == slashtok) {
            cout << ' ' << t << ' ';
        }

        t = S.getnext();
    }

    cout << endl;*/
    // End pretty printer coding demo.

    return 0;
}
void popAndCalc (Stack<Token>& numstack, Stack<Token>& opstack ){
        int firstNum = 0;
        int secondNum = 0;
        TokenType operations; 
        int result ;
    //cout << "grabbing values ..." << endl;  
    //cout << "peeking at numstack, second num = "<< numstack.peek().val << endl;
        secondNum = numstack.peek().val;
        numstack.pop();

    //cout << "peeking at numstack, first num = "<< numstack.peek().val << endl;           
        firstNum = numstack.peek().val;
        numstack.pop();
        
    Token op = opstack.peek();
    //cout <<"peeking at opstack, operation = "<< op << endl;
        operations = opstack.peek().tt;
        opstack.pop();
        
        result = calculate(firstNum,secondNum,operations);
        //cout << firstNum << op << secondNum << "="<< result << endl;
        Token tokenResult ;
        tokenResult.val = result;
        //cout <<"pushing " << tokenResult.val << " into number stack"<< endl;
        numstack.push(tokenResult);
        //cout << "peeking at numstack, value = "<< numstack.peek().val << endl;


} 

int calculate (int firstNum, int secondNum, TokenType operation){
int result = 0; 
//cout << "calculating ..." << endl;
if (operation == pltok){
    result = firstNum + secondNum;
} else if (operation == mitok) {
    result = firstNum - secondNum;
} else if (operation == asttok){
    result = firstNum * secondNum;
} else if (operation == slashtok){
    result = firstNum / secondNum;
}
return result;

} 