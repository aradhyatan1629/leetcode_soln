class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        int height = log2(label);
        ans.push_back(label);
        
        while(height!=0)
        {
            int start = pow(2,height);
            int end = (pow(2,height) * 2) - 1;
            int x = (start + end) - label;
            int parent = x/2;
            ans.push_back(parent);
            height--;label=parent;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

/*
Say if we were given a normal infinite binary tree with any zigzag property
then in that tree we can easily calculate its parent by doing node/2
eg - node = 14, then in that tree its parent is - 14/2 = 7 for 7 its parent is 7/2 = 3
Using this we can reach the path. Draw a normal infinite tree and observe this property urself.

But in this ques the tree has the zigzag property so here we cannot use the 
property of node/2 to get its parent.

To solve this question we will have to find the node that is there in position of 
our given label in a normal infinite tree (withou zigzag property)
For eg - for node 13 in zigzag tree we have 10 in normal, for 12 we have 11 etc

now for any node in our zigzag tree its parent will be the same as the node 
corresponding to it in the normal tree, like for node 14 in normal tree we have node 10
in its place so for node 10 its parent is - 10/2=5 hence for 14 its parent is also 5.

-----       -----------------------------       -------

for any node in given tree we follow these steps - 
say given node = 14
calculate the height from root = log2(14) = 3
now while(height!=0) calculate - 
start = 2^h and end = (2^h*2) - 1 
x = (start + end) - label
parent = x/2
label = parent

*/
