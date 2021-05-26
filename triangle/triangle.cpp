using namespace std;

#include <vector>
#include <iostream>


/* 
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
 

Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104
 

Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?
*/


class Solution {
public:
    int smallerindex(int a, int b)
    {
        return (a > b) ? 0 : -1;
    }
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int row = 0, column = 0, index;
        int sum;

        for (row = 1; row < triangle.size(); row++) {
            triangle[row][0] = triangle[row-1][0] + triangle[row][0];
            for (column = 1; column < triangle[row].size()-1; column++){
                index = smallerindex(triangle[row-1][column-1], triangle[row-1][column]);
                triangle[row][column] += triangle[row-1][column+index];
            }
            triangle[row][row] = triangle[row][row] + triangle[row-1][row-1]; 
        }

        row--;
        sum = triangle[row][0];
        for (column = 1; column < triangle[row].size(); column++)
        {
            sum = sum < triangle[row][column] ? sum :  triangle[row][column];
        }

        return sum;
    }
};

int main()
{
    vector<vector<int>> test_triangle = {{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}}};
    //vector<vector<int>> test_triangle = {{{-10}}};

    Solution m_solution;

    int bb = test_triangle.size();
    cout << endl;
    cout << bb<< endl;


    int sum = m_solution.minimumTotal(test_triangle);
    cout << sum;
    //cin >> sum;
    return 0;
}
//};