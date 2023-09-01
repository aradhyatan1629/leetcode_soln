//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

// } Driver Code Ends
/*
 A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
  public:
    
    void bfs(Node *root,vector<int> &ans)
    {
        queue<Node*> q;
        q.push(root);
        bool flag = true;       //true means right and false means left
        while(!q.empty())
        {
            vector<int> v;
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                Node *node = q.front();
                q.pop();
                v.push_back(node->data);
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            if(flag)
            {
                ans.push_back(v[v.size()-1]);
            }
            else
            {
                ans.push_back(v[0]);
            }
            flag=!flag;
        }
    }
    
    vector<int> ExtremeNodes(Node* root)
    {
        if(root==NULL)
        {
            return {};
        }
        vector<int> ans;
        bfs(root,ans);
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		Solution obj;
        vector<int> nodes =  obj.ExtremeNodes(root);
        for(int i = 0;i<nodes.size();i++){
            cout<<nodes[i]<<" ";
        }
   		cout<<endl;
  }
  return 0;
}

// } Driver Code Ends