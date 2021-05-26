using namespace std;

#include <vector>
#include <iostream>

/* 
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/601/week-4-may-22nd-may-28th/3754/
To Lower Case
Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.

 

Example 1:

Input: s = "Hello"
Output: "hello"
Example 2:

Input: s = "here"
Output: "here"
Example 3:

Input: s = "LOVELY"
Output: "lovely"
 

Constraints:

1 <= s.length <= 100
s consists of printable ASCII characters.
*/


class Solution {
public:
    string toLowerCase(string s) {
        string ret;
        for(string::iterator s_iter = s.begin(); s_iter < s.end(); s_iter++){
            if ((*s_iter >= 'A') && (*s_iter <= 'Z')){
                ret.push_back(*s_iter-'A'+'a');
            }
            else
            {
                ret.push_back(*s_iter);
            }
        }
        return ret;    
    }
};


int main()
{
    string s = "HelioKinddom123Halo";
    string result;
    Solution m_solution;

    result = m_solution.toLowerCase(s);
    cout << result << endl;

    return 0;
}