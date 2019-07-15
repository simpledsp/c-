#define SIMPLEDSP
#include "cheader.h"
//do not use define or include any header file

void helper(TreeNode* node, int&dep, int&n, map<TreeNode*, pair<int,int>>& mp){
        if(!node->left && !node->right){
            dep=0; 
            n=1;
            mp[node]={0,0};
            return;
        }
        
        int depth=0, num=0;
        if(node->left){
            helper(node->left, depth, num, mp);
        }
        
        int depth2=0, num2=0;
        if(node->right){
            helper(node->right, depth2, num2, mp);
        }
        
        if(depth>depth2){
            dep=depth; n=num;
        }
        else if(depth<depth2){
            dep=depth2; n=num2;
        }
        else{
            dep=depth; n=num+num2;
        }
        ++dep;
        mp[node]={dep, n};
        
    }
    
    TreeNode* helper(TreeNode* root, map<TreeNode*, pair<int,int>>& mp) {
        auto prRoot=mp[root];
        
        if(root->left){
            auto pr=mp[root->left];
            if(prRoot.second==pr.second)
                return helper(root->left, mp);
        }
        
        if(root->right){
            auto pr=mp[root->right];
            if(prRoot.second==pr.second)
                return helper(root->right, mp);
        }
        
        return root;
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root)
            return root;
        int depth=0, num=0;
        map<TreeNode*, pair<int,int>> mp;
        helper(root, depth, num, mp);
        //amap(mp, TreeNode*, pair<int,int>)
        //dsp
        return helper(root, mp);
        
    }

//main function, do not change function name
int main(int argc, char* argv[])
{
    //call your function here
    TreeNode* root=intVecToTree({1,2,3,4});
    TreeNode* ret = lcaDeepestLeaves(root);
    //ahd(root)
    //a(ret)
    //dsp
    return 0;
}            
