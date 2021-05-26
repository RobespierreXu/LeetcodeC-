using namespace std;

#include <vector>
#include <iostream>

/* 
Power of Three
Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.

 

Example 1:

Input: n = 27
Output: true
Example 2:

Input: n = 0
Output: false
Example 3:

Input: n = 9
Output: true
Example 4:

Input: n = 45
Output: false
 

Constraints:

-231 <= n <= 231 - 1
 

Follow up: Could you solve it without loops/recursion?
*/


class Solution {
public:

    bool isPowerOfThree(int n) {
        if (n < 1) return false;
        int remainder = 1162261467 % n;
        if(remainder != 0) {
            return false;
        }
        return true;
    }

    bool isPowerOfThreeOld(int n) {
        int remainder = 0;
        int quotient = n;
        if(n <= 0) return false;
        while (quotient != 1) {
            remainder = quotient % 3;
            if(remainder != 0) return false;
            quotient = int(quotient / 3);
        }
        return true;
    }


};


int main()
{
    /*int number1 = 0;
    int number2 = 0;
    int number1 = 342;
    int number2 = 465; 
    vector<vector<int>> wall = 
    {
        {1,2,2,1},
        {3,1,2},
        {1,3,2},
        {2,4},
        {3,1,2},
        {1,3,1,1}
    };


    vector<vector<int>> wall = 
    {
        {6},
        {6},
        {6},
        {6},
        {6},
        {1,3,1,1}
    }; */
    //vector<vector<int>> test_triangle = {{{-10}}};
    /*
    vector<vector<int>> wall = 
    {
        {100000000},
        {100000000},
        {100000000}
    }; */
    Solution m_solution;
    bool result;

//    result = m_solution.isPowerOfThree(27);
    cout << result << endl;
    result = m_solution.isPowerOfThree(45);
    cout << result << endl;
    result = m_solution.isPowerOfThree(0);
    cout << result << endl;
    result = m_solution.isPowerOfThree(361);
    cout << result << endl;
    result = m_solution.isPowerOfThree(1);
    cout << result << endl;
    result = m_solution.isPowerOfThree(81);
    cout << result << endl;
    result = m_solution.isPowerOfThree(61);
    cout << result << endl;

    return 0;
}