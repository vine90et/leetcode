/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& arr){
        if(root == nullptr) return;

        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

    void recover(TreeNode* root, vector<int>& arr, int& i){
        if(root == nullptr) {
            return;
        }
        recover(root->left, arr, i);

        if(arr[i] != root->val){
            root->val = arr[i];
        }
        i++;

        recover(root->right, arr, i);
    }

    void recoverTree(TreeNode* root) {
        vector<int> arr;
        inorder(root, arr);

        sort(arr.begin(), arr.end());
        int i = 0;
        recover(root, arr, i);
    }
};