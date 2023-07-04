class Solution {
  public:
     vector <int> bottomView(Node *root) {
       
 //The logic is simple we are taking the root at 0th level and towards root's left we are decreasing the 
//  level by 1 ,  and towards right we are increasing by 1 
 
       vector<int>ans;
       if(root == NULL) return ans;
       
 // We are using map  to store the level or line and the data at that level 
 // and the data remains sorted in a map 
 // In case two nodes are on the same line then we will take the right one
 
       map<int,int>mp;
       queue<pair<Node * , int>>q;
       
 // A queue to store the root and line 
 
       q.push({root , 0});
       
       while(!q.empty()) {
           auto it = q.front() ;
           q.pop();
           
           Node*node = it.first;
           int line = it.second;
           
 //  we will update every time even if there is the value stored on that line 
 // just like i said that that we will take the right one if two nodes are colliding on the same line 
 // so this will update that because left will be inserted first and then right one 
 
 // You can see the second picture in the question where 3 and 4 are in the line that is 0th 
 // so we will take 4 
 
           mp[line] = node->data;
           
           if(node->left != NULL) {
               q.push({node->left , line-1});
           }
           if(node->right != NULL) {
               q.push({node->right , line+1});
           }
       }
       for(auto i : mp) {
           ans.push_back(i.second);
       }
       return ans;
    }
};