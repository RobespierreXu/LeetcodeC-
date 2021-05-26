using namespace std;

#include <vector>
#include <list>
#include <map>
#include <iostream>
#include <string>

/* 
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/601/week-4-may-22nd-may-28th/3755/
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.

 

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
 

Constraints:

1 <= tokens.length <= 104
tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //vector<string> opts = {"+","-","*","/"};
        map<int, char> opt_calc;

        int i;
        // preprocess find the operators         
        for(i = 2; i < tokens.size(); i++){
            if (tokens[i] == "+")
            {
                opt_calc.insert({i, '+'});
            }
            else if (tokens[i] == "-")
            {
                opt_calc.insert({i, '-'});
            }            
            else if (tokens[i] == "*")
            {
                opt_calc.insert({i, '*'});
            }            
            else if (tokens[i] == "/")
            {
                opt_calc.insert({i, '/'});
            }
        }                       
        
        int round = 0;

        for (map<int, char>::iterator oper_iter= opt_calc.begin(); oper_iter != opt_calc.end(); oper_iter++)
        {
            /* calculate the result */
            int pos;
            char opt;
            pos = oper_iter->first - round*2;
            opt = oper_iter->second;
            int oprand1 = stoi(tokens[pos-2]);
            int oprand2 = stoi(tokens[pos-1]);
            switch (opt)
            {
                case '+' :  
                    tokens[pos] = to_string(oprand1 + oprand2);
                    break;
                case '-' :  
                    tokens[pos] = to_string(oprand1 - oprand2);
                    break;
                case '*' :  
                    tokens[pos] = to_string(oprand1 * oprand2);
                    break;
                case '/' :  
                    tokens[pos] = to_string(oprand1 / oprand2);
                    break;
                default:
                    continue;
            }
            tokens.erase(tokens.begin()+pos-1);
            tokens.erase(tokens.begin()+pos-2);
            round++;
        }

        return stoi(tokens[tokens.size()-1]);

    }
};


int main()
{
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int result;
    Solution m_solution;

    result = m_solution.evalRPN(tokens);
    cout << result << endl;

    return 0;
}