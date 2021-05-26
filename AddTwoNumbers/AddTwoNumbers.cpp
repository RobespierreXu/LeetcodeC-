using namespace std;

#include <vector>
#include <iostream>

/* 
Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 

Example 1:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    ListNode(int length, int number) {
        int temp, value;
        ListNode *ptr = this;
        next = NULL;
        temp = number;
        val = temp % 10;
        for(temp = number / 10; temp != 0; temp = temp / 10) {
            ptr->next =  new ListNode(temp % 10);
            ptr = ptr->next;
        }
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* IterNode = new ListNode(); 
        ListNode* SumNode = IterNode;
        int sumIndex = 0;
        ListNode* IterL1 = l1; 
        ListNode* IterL2 = l2;
        int carry = 0;
        int num1 = IterL1->val;
        int num2 = IterL2->val;
        int numSum;

        do {
            //num2 = l2[index2].val;
            numSum = num1 + num2 + carry;
            carry = numSum / 10;
            numSum = numSum % 10;

            IterNode->val = numSum;
            IterNode->next = new ListNode();

            if(IterL1 != NULL){
            
                if(IterL1->next != NULL){
                    IterL1 = IterL1->next;
                    num1 = IterL1->val;
                }else{
                    num1 = 0;
                    IterL1 = NULL;
                }
            }

            if(IterL2 != NULL){
                if(IterL2->next != NULL){
                    IterL2 = IterL2->next;
                    num2 = IterL2->val;
                }else{
                    num2 = 0;
                    IterL2 = NULL;
                }
            }

            if ((IterL1 == NULL) && (IterL2 == NULL)&&(carry == 0)){
                delete IterNode->next;
                IterNode->next = NULL;
                break;

            }                
            IterNode = IterNode->next;
        } while (1);


        return SumNode;

    }
};

int main()
{
    /*int number1 = 0;
    int number2 = 0;
    int number1 = 342;
    int number2 = 465;  */
    int number1 = 9999999;
    int number2 = 9999; 
    ListNode *l1 = new ListNode(1, number1);
    ListNode *l2 = new ListNode(2, number2);

    //vector<vector<int>> test_triangle = {{{-10}}};

    Solution m_solution;
    ListNode* sum = m_solution.addTwoNumbers(l1, l2);

    for(ListNode *ptr = sum; ptr != NULL; ptr = ptr->next)
        cout << ptr->val << " ";

    //cin >> sum;
    return 0;
}
//};