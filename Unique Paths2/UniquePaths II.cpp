using namespace std;

#include <vector>
#include <list>
#include <stack>
#include <iostream>

/* 
  Unique Paths II

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and space is marked as 1 and 0 respectively in the grid.

 

Example 1:


Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
Example 2:


Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
 

Constraints:

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.
*/


class Solution {
public:
    Link reachableBlockLinkTable(vector<vector<int>>& obstacleGrid) {
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
    }
};


int main()
{
    /*int number1 = 0;
    int number2 = 0;
    int number1 = 342;
    int number2 = 465; */
    vector<vector<int>> obstacleGrid = 
    {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };

    /*vector<vector<int>> wall = 
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

/*    result = m_solution.isPowerOfThree(27);
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
*/
    return 0;
}