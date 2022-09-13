/*
+ - - - + - + - -
+ - + - + copyright by Vladimir Baranov (Kvazikot)  <br>
+ - + - + email: vsbaranov83@gmail.com  <br>
+ - + - + github: https:/images//github.com/Kvazikot/UsefulMacro/  <br>
```
                          )            (
                         /(   (\___/)  )\
                        ( #)  \ ('')| ( #
                         ||___c\  > '__||
                         ||**** ),_/ **'|
                   .__   |'* ___| |___*'|
                    \_\  |' (    ~   ,)'|
                     ((  |' /(.  '  .)\ |
                      \\_|_/ <_ _____> \______________
                       /   '-, \   / ,-'      ______  \
              b'ger   /      (//   \\)     __/     /   \
                                          './_____/
```
*/

// Algorithm 1: evaluted by a stack of numbers
// From Berkeley UC lecture readed by Johatahn Shewchuk
//------------------------------------------------------------------
// * Read expression left to right
//   * Number: push it onto stack
//   * Operator: pop top 2 numbers off stack
//    Perform operation (first number popped is 2 operand)
//  Push Result on stack
//------------------------------------------------------------------
// Algorithm 2:
// Convert infix to posix
//------------------------------------------------------------------
// Read expr. left to right
//  * Number: print it out
//  * Operator: put it on stack
//    until an operator with lower or equal precedence appears
//    where upon pip it and print
// String Ends: pip and print each item on stack

#include "../log/logger.h"
#include <stack>
#include "./interpreter/expression_calculator.h"

using namespace std;

ExpressionCalculator::ExpressionCalculator(QObject *parent)
    : QObject{parent}
{

}

int precedence(char op)
{
    switch(op)
    {
       case '^':
       return 3;
       case '*':
       case '/':
       return 2;
       case '+':
       case '-':
        return 1;
    default:
        return 0;
    }
}

void operate(stack<QVariant>& numStack, char Operator, QString& result)
{
    numStack.pop();
    QVariant& operand2 = numStack.top();
    numStack.pop();
    QVariant& operand1 = numStack.top();
    result+=Operator + " ";
    switch(Operator)
    {
        case '+':
           numStack.push(operand1.toInt() + operand2.toInt());
        break;
        case '-':
            numStack.push(operand1.toInt() - operand2.toInt());
        break;
        case '*':
            numStack.push(operand1.toInt() * operand2.toInt());
        break;
        case '^':
        int res = 1;
        for(int i = 0; i < operand2.toInt(); i++)
            res = res * operand1.toInt();
        numStack.push(res);
    }

}


inline bool isDigit(char c)
{
    QString cc(c);
    bool ok;
    cc.toDouble(&ok);
    return ok;
}

int ExpressionCalculator::compute(QString expression, QString& result)
{
    stack<QVariant> numStack;
    stack<QVariant> opStack;
    for(int i=0; i < expression.size(); i++)
    {
        char c = expression[i].toLatin1();
        if( isDigit(c) )
        {
            result+=QString(c) + " ";
            numStack.push(QVariant(c));
        }
        else if( (c == '+') || (c == '-') || (c == '*') || (c == '^') )
        {
            while( !opStack.empty() && (c!='^') &&
                   precedence(opStack.top().toChar().toLatin1()) >= precedence(c))
            {
                opStack.pop();
                char op = opStack.top().toChar().toLatin1();
                operate(numStack, op, result);
            }
            opStack.push(c);
        }
    }
    while(!numStack.empty())
    {
        result+=numStack.top().toString();
        numStack.pop();
    }

    Log(result);

    return 1;
}
