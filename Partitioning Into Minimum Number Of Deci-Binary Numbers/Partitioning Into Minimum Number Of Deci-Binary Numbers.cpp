using namespace std;

#include <vector>
#include <list>
#include <map>
#include <iostream>
#include <string>

/* 
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/601/week-4-may-22nd-may-28th/3756/

Partitioning Into Minimum Number Of Deci-Binary Numbers
A decimal number is called deci-binary if each of its digits is either 0 or 1 without any leading zeros. For example, 101 and 1100 are deci-binary, while 112 and 3001 are not.

Given a string n that represents a positive decimal integer, return the minimum number of positive deci-binary numbers needed so that they sum up to n.

 

Example 1:

Input: n = "32"
Output: 3
Explanation: 10 + 11 + 11 = 32
Example 2:

Input: n = "82734"
Output: 8
Example 3:

Input: n = "27346209830709182346"
Output: 9
 

Constraints:

1 <= n.length <= 105
n consists of only digits.
n does not contain any leading zeros and represents a positive integer.
*/

class Solution {
public:
    int minPartitions(string n) {
        int max_num=0;
        int now_num;
        for(int i=0; i<n.length(); i++)
        {
            now_num = n[i] - '0';
            max_num = max_num < now_num ? now_num: max_num;
        }
        return max_num;
    }
};

int main()
{
    string n = "32";

    Solution m_solution;
    int result;

    result = m_solution.minPartitions(n);

    cout << result;

    return 0;
}
