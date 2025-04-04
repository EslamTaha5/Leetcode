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
    int cnt_dep = 0, mx_dep = -1;
    int freq[1002], sz[1002];
    vector<int> nodes;
    int solve(TreeNode* root, int dep){
        if(!root) return 0;
        sz[root->val] = 1;
        nodes.push_back(root->val);
        if(dep > mx_dep){
            mx_dep = dep;
            memset(freq, 0, sizeof freq);
            cnt_dep = 0;
        }
        if(dep == mx_dep){
            cnt_dep++;
            for(auto& it: nodes){
                freq[it]++;
            }
        }
        sz[root->val] += solve(root->left, dep + 1);
        sz[root->val] += solve(root->right, dep + 1);
        nodes.pop_back();
        return sz[root->val];
    }

    TreeNode *ans = nullptr;
    void get_node(TreeNode* root){
        if(!root) return;
        
        get_node(root->left);
        get_node(root->right);
        if(ans) return;

        if(freq[root->val] == cnt_dep) {
            ans = root;
            return;
        }
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        solve(root, 0);
        get_node(root);
        return ans;
    }
};