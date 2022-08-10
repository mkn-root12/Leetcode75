Given the root of an n-ary tree, return the preorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)

 

Example 1:



Input: root = [1,null,3,2,4,null,5,6]
Output: [1,3,5,6,2,4]
Example 2:



Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
0 <= Node.val <= 104
The height of the n-ary tree is less than or equal to 1000.
 

Follow up: Recursive solution is trivial, could you do it iteratively?

/**
Given an n-ary tree, return the preorder traversal of its nodes' values.
For example, given a 3-ary tree:
Return its preorder traversal as: [1,3,5,6,2,4].
Note:
Recursive solution is trivial, could you do it iteratively?
**/

//recursive
//Your runtime beats 46.00 % of cpp submissions.
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> ans;
    vector<int> preorder(Node* root) {
        if(root!=NULL){
            ans.push_back(root->val);
            for(Node* child : root->children){
                preorder(child);
            }
        }
        return ans;
    }
};

//iterative
//Your runtime beats 15.94 % of cpp submissions.
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    
    vector<int> preorder(Node* root) {
        vector<int> ans;
        stack<Node*> stk;
        
        stk.push(root);
        while(!stk.empty()){
            Node* node = stk.top();
            stk.pop();
            
            if(node!=NULL){
                ans.push_back(node->val);
                //put the children into stack in reverse order
                for(vector<Node*>::reverse_iterator it=node->children.rbegin(); it!=node->children.rend();it++){
                    stk.push(*it);
                }
            }
            
        }
        return ans;
    }
};

/**
Complexity Analysis
Time complexity : we visit each node exactly once, and for each visit, 
the complexity of the operation (i.e. appending the child nodes) is proportional to the number of child nodes n (n-ary tree). 
Therefore the overall time complexity is O(N), where N is the number of nodes, i.e. the size of tree.
Space complexity : depending on the tree structure, we could keep up to the entire tree, therefore, 
the space complexity is O(N).
**/
