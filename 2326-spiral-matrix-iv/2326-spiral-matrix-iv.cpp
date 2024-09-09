/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        ListNode *temp = head;
        
        int topRow=0,bottomRow=m-1;
        int leftCol=0,rightCol=n-1;

    
        
        while(topRow<=bottomRow && leftCol<=rightCol){
            
            for(int j=leftCol;j<=rightCol;j++){
                if(temp){
                    ans[topRow][j] = temp->val;
                    temp = temp->next;
                }
            }
            topRow++;
            
            
            for(int i=topRow;i<=bottomRow;i++){
                if(temp){
                    ans[i][rightCol] = temp->val;
                    temp = temp->next;
                }
            }
            rightCol--;
            
            if(topRow<=bottomRow){
                for(int j=rightCol;j>=leftCol;j--){
                    if(temp){
                        ans[bottomRow][j] = temp->val;
                        temp = temp->next;
                    }
                }
                bottomRow--;
            }
            
            if(leftCol<=rightCol){
                for(int i=bottomRow;i>=topRow;i--){
                    if(temp){
                        ans[i][leftCol] = temp->val;
                        temp = temp->next;
                    }
                }
                leftCol++;
            }
        }
        return ans;
    }
};