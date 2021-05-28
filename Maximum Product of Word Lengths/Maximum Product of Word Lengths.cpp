
using namespace std;

#include <vector>
#include <iostream>

/* 
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/601/week-4-may-22nd-may-28th/3757/
Maximum Product of Word Lengths
Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. If no such two words exist, return 0.

 

Example 1:

Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16
Explanation: The two words can be "abcw", "xtfn".
Example 2:

Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
Output: 4
Explanation: The two words can be "ab", "cd".
Example 3:

Input: words = ["a","aa","aaa","aaaa"]
Output: 0
Explanation: No such pair of words.
 

Constraints:

2 <= words.length <= 1000
1 <= words[i].length <= 1000
words[i] consists only of lowercase English letters.
*/


class Solution {
public:

    int maxProduct(vector<string>& words) {
        int max_length = 0;
        for(int i=0; i<words.size(); i++)
        {
            for(int j=i+1; j<words.size(); j++)
            {
                size_t pos = string::npos;
                for(int k=0; k<words[i].size(); k++)
                {
                    pos = words[j].find(words[i][k]);
                    if(pos != string::npos)
                    {
                        break;
                    }
                }
                if(pos == string::npos)
                {
                    int now_length = words[i].size() * words[j].size();
                    max_length = now_length > max_length? now_length: max_length;
                }
            }
        }
        return max_length;
    }

};


int main()
{
    vector<string> words = 
    {
        "a","aa","aaa","aaaa"
    };

    Solution m_solution;
    int result;

    result = m_solution.maxProduct(words);
    cout << result << endl;

    return 0;
}