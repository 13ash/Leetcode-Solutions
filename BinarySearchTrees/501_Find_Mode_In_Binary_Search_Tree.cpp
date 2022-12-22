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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> modeMap;
        inOrder(root, modeMap);

        vector<int> out;
        int modeVal = modeMap.begin()->second;

        for (auto it = modeMap.begin(); it != modeMap.end(); it++) {
            if (it->second > modeVal) {
                modeVal = it->second;
            }
        }

        for (auto it = modeMap.begin(); it !=modeMap.end(); it++) {
            if (it->second == modeVal) {
                out.push_back(it->first);
            }
        }
        return out;
    }

    void inOrder(TreeNode* subTreePtr, unordered_map<int, int>&map) {
        if (subTreePtr == nullptr) {
            return;
        } else {
            inOrder(subTreePtr->left, map);

            if (map.find(subTreePtr->val) == map.end()) {
                map[subTreePtr->val] = 1;
            } else {
                map[subTreePtr->val] += 1;
            }
            inOrder(subTreePtr->right, map);
        }
    }
};
