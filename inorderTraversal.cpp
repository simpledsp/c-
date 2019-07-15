#define SIMPLEDSP
#include "cheader.h"
//do not use define or include any header file

vector<int> inorderTraversal(TreeNode* root) {
        //ahd(root)        
        vector<int> ret;
        if(!root)
            return ret;
        
        stack<TreeNode*> stk; //a(stk)       
        stk.push(root);
        
        while(root->left){
            stk.push(root->left);
            root=root->left;
        }
        
        while(stk.size()>0){
            TreeNode* cur=stk.top(); stk.pop();
            ret.push_back(cur->val);
            //a(cur)
            //lk("root",cur)
            //dsp
            
            if(cur->right){
                stk.push(cur->right);            
                TreeNode* r=cur->right;
                while(r->left){
                    stk.push(r->left);
                    r=r->left;
                }
            }
        }
        return ret;
    }

//main function, do not change function name
int main(int argc, char* argv[])
{
    //call your function here
    TreeNode* root=intVecToTree({1,-1,2,-1,-1,3}); 
    vector<int> ret = inorderTraversal(root);
    
    return 0;
}            
