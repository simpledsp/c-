#define SIMPLEDSP
#include "cheader.h"
//do not use define or include any header file

//add your functions here
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> st;
        for(int v:to_delete){
            st.insert(v);
        }
        //achd(root)
        //ac(st)
        vector<TreeNode*> ret;        
        queue<pair<TreeNode*, bool>> qu;
        qu.push({root, true});        
        
        map<TreeNode*, TreeNode*> mp;
        //acmap(mp,TreeNode*, TreeNode*)
        //ac(qu)
        //achd(ret)
        mp[root]=NULL;
        
        while(qu.size()>0){
            auto pr=qu.front(); qu.pop();
            //a(pr)
            if(!pr.first)
                continue;
            mp[pr.first->left]=pr.first;
            mp[pr.first->right]=pr.first;
            
            if(st.count(pr.first->val)==0){
                if(pr.second){
                    ret.push_back(pr.first);
                }
                qu.push({pr.first->left, false});
                qu.push({pr.first->right, false});
            }
            else{
                TreeNode* parent =mp[pr.first];
                if(parent){
                if(parent->left==pr.first)
                    parent->left=NULL;
                else
                    parent->right=NULL;
                }
                
                qu.push({pr.first->left, true});
                qu.push({pr.first->right, true});
            }
            //dsp
        }
        
        return ret;
    }

//main function, do not change function name
int main(int argc, char* argv[])
{
    //call your function here
    TreeNode* root =intVecToTree({1,2,3,4,5,6,7}); vector<int> to_delete = {3,5};
    vector<TreeNode*> vec = delNodes(root, to_delete);
    //ahd(vec)
    //dsp
    return 0;
}            
