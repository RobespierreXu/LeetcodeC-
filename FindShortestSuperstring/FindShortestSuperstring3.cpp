using namespace std;

#include <vector>
#include <queue>
#include <iostream>

/* https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/601/week-4-may-22nd-may-28th/3753/
 Find the Shortest Superstring
Given an array of strings words, return the smallest string that contains each string in words as a substring. If there are multiple valid strings of the smallest length, return any of them.

You may assume that no string in words is a substring of another string in words.

 
Example 1:

Input: words = ["alex","loves","leetcode"]
Output: "alexlovesleetcode"
Explanation: All permutations of "alex","loves","leetcode" would also be accepted.
Example 2:

Input: words = ["catg","ctaagt","gcta","ttca","atgcatc"]
Output: "gctaagttcatgcatc"
 

Constraints:

1 <= words.length <= 12
1 <= words[i].length <= 20
words[i] consists of lowercase English letters.
All the strings of words are unique.
*/

class Solution {
private:
    int calculatePrefix(string result_word, vector<string>& now_words, vector<string>::iterator& prefix_iter){
        int prefix_repeat_num = 0;
        prefix_iter = now_words.begin();
        for(vector<string>::iterator iter = now_words.begin(); iter != now_words.end(); iter++)
        {
            string cmp_str = *iter;
            for(int start_pos = 0; (start_pos < iter->size()) && (iter->size()-start_pos < prefix_repeat_num); start_pos++)
            {
                string::size_type position = result_word.find_first_of(cmp_str);
                if(position == string::npos)
                {
                    cmp_str = iter->substr(start_pos, iter->size()-1);
                }
                else 
                {
                    if(position == 0)
                    {
                        prefix_repeat_num = iter->size() - start_pos;
                        prefix_iter = iter;
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
        }
        return prefix_repeat_num;
    }

    int calculatePostfix(string result_word, vector<string>& now_words, vector<string>::iterator& postfix_iter)
    {
        int postfix_repeat_num = 0;
        postfix_iter = now_words.begin();
        for(vector<string>::iterator iter = now_words.begin(); iter != now_words.end(); iter++)
        {
            string cmp_str = *iter;
            for(int end_pos = iter->size()-1; (end_pos >= 0) && (end_pos < postfix_repeat_num); end_pos--)
            {
                string::size_type position = result_word.find_last_of(cmp_str);
                if(position == string::npos)
                {
                    cmp_str = iter->substr(0, end_pos);
                }
                else 
                {
                    if(position == result_word.size()-1-end_pos)
                    {
                        postfix_repeat_num = end_pos+1;
                        postfix_iter = iter;
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
        }
        return postfix_repeat_num;
    }

public:
    string shortestSuperstring(vector<string>& words) {
        string ret;
        int max_repeat_num = 0;
        int prefix_num, postfix_num = 0;
        vector<string>::iterator prefix_it, postfix_it;

        vector<string> now_words(words);

        int longest_index = 0;
        for(int k = 0; k < now_words.size(); k++)
        {
            if(ret.size() < now_words[k].size())
            {
                ret = now_words[k];
                longest_index = k;
            }
        }
        now_words.erase(now_words.begin() + longest_index);
        
        while(now_words.size() != 0){

            //calculate word prefix num
            prefix_num = calculatePrefix(ret, now_words, prefix_it);

            //calculate word postfix num
            postfix_num = calculatePostfix(ret, now_words, postfix_it);

            // compare and conjuction the max word
            if(prefix_num > postfix_num){
                ret = prefix_it->substr(0, prefix_num - 1) + ret;
                now_words.erase(prefix_it);
            } else {
                ret = ret + postfix_it->substr(postfix_num, postfix_it->size());
                now_words.erase(postfix_it);
            }

        }

        return ret;

    }
};

int main()
{

    vector<string> words = {
    //    "alex","loves","leetcode"
        "catg","ctaagt","gcta","ttca","atgcatc"
    }; 

    Solution m_solution;
    string result;

    result = m_solution.shortestSuperstring(words);

    cout << result;
    /*for(int i = 0; i< result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }*/

    return 0;
}
//};