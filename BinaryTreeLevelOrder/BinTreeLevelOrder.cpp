using namespace std;

#include <vector>
#include <queue>
#include <iostream>

/* https://leetcode.com/explore/featured/card/may-leetcoding-challenge-2021/600/week-3-may-15th-may-21st/3749/
Binary Tree Level Order Traversal
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:

Input: root = [1]
Output: [[1]]

Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
*/

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> retVector;
        queue<TreeNode*> toBeProcessQ;
        TreeNode* p = root;
        if (root == NULL){
            retVector.resize(0);
            return retVector;
        }

        //initialization
        toBeProcessQ.push(root);
        
        do {
            queue<TreeNode*> processingQ(toBeProcessQ);
            while(!toBeProcessQ.empty()){
                toBeProcessQ.pop();
            };
            vector<int> levelNum;
            do {
                p = processingQ.front();
                processingQ.pop(); 
                if(p->left != NULL){
                    toBeProcessQ.push(p->left);
                }               
                if(p->right != NULL){
                    toBeProcessQ.push(p->right);
                }

                levelNum.push_back(p->val);
            } while (processingQ.size() != 0);
            retVector.push_back(levelNum);

        } while(toBeProcessQ.size() != 0);

        return retVector;

    }
};

int main()
{

    /*vector<int> numbers = {
        3,9,20,-82,-1,15,7,-2000,-98,-2000,99,100,101,102,-2000
    }; */
    vector<int> numbers;
    int treeSize = 0;
    int level = 0;

    vector<TreeNode*> treeV;
    TreeNode* pTree = NULL;
    TreeNode* root = NULL;

    if(numbers.size() != 0) {
        pTree = new TreeNode(numbers[0]);
        root = pTree;
        treeV.push_back(root);
    }

    for(int i = 1; i< numbers.size(); i+=2) {
        int mother = (i-1) / 2;
        if(numbers[i] != -2000) {
            pTree = new TreeNode(numbers[i]);
            treeV[mother]->left = pTree;
            treeV.push_back(pTree);
        }
        if(numbers[i+1] != -2000) {
            pTree = new TreeNode(numbers[i+1]);
            treeV[mother]->right = pTree;
            treeV.push_back(pTree);
        }
    }

    Solution m_solution;
    vector<vector<int>> result;

    result = m_solution.levelOrder(root);

    for(int i = 0; i< result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
//};