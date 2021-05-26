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
    int leastBricks(vector<vector<int>>& wall) {
        int width = 0;
        int brick_sum;
        int min_line_sum = wall.size();
        int now_line_sum = wall.size();

        //int line_sum;
        int new_short_row_num = 0;
        long new_shortest_line_sum =  0;
        int now_short_row_num = 0;
        long now_shortest_line_sum =  0;
        vector<int> line_index(min_line_sum);
        vector<int> line_sum(min_line_sum);

        for (int k = 0; k<wall[0].size(); k++){
            width += wall[0][k];
        }

        if (width <= 1){
            return min_line_sum;
        }
        new_shortest_line_sum = width;

        // Initialization; index = 0; line sum = first vector node
        for (int row_num = 0; row_num < wall.size(); ++row_num) {
            line_index[row_num] = 0;
            line_sum[row_num] = wall[row_num][0];
            if (new_shortest_line_sum > wall[row_num][0]) {
                new_shortest_line_sum   = now_shortest_line_sum = wall[row_num][0];
                new_short_row_num       = now_short_row_num     = row_num;
            }
        }

        while (now_shortest_line_sum < width) {
            now_line_sum = wall.size();
            new_shortest_line_sum = now_shortest_line_sum + wall[now_short_row_num][line_index[now_short_row_num]];
            for (int row_num = 0; row_num < wall.size(); ++row_num) {
                if (line_sum[row_num] == now_shortest_line_sum) {
                    now_line_sum--;
                    line_index[row_num]++;
                    line_sum[row_num] += wall[row_num][line_index[row_num]];
                }
                if (new_shortest_line_sum > line_sum[row_num]) {
                    new_shortest_line_sum = line_sum[row_num];
                    new_short_row_num = row_num;
                }
            }
            now_short_row_num = new_short_row_num;
            now_shortest_line_sum = new_shortest_line_sum;
            if(now_line_sum < min_line_sum) {
                min_line_sum = now_line_sum;
            }            
        }

        return min_line_sum;
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
    
    vector<vector<int>> wall = 
    {
        {100000000},
        {100000000},
        {100000000}
    }; 
    Solution m_solution;
    bool result;

    result = m_solution.leastBricks(wall);
    cout << result << endl;

    return 0;
}
//};