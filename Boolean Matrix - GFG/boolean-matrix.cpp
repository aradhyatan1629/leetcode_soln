//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        bool flagRow0=false,flagCol0=false;
        int m=matrix.size(),n=matrix[0].size();
        for(int j=0;j<n;j++)
        {
            if(matrix[0][j]==1)
            {
                flagRow0=true;
            }
        }
        for(int i=0;i<m;i++)
        {
            if(matrix[i][0]==1)
            {
                flagCol0=true;
            }
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]==1)
                {
                    matrix[i][0] = matrix[0][j] = 1;
                }
            }
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][0]==1 or matrix[0][j]==1)
                {
                    matrix[i][j]=1;
                }
            }
        }
        if(flagRow0)
        {
            for(int j=0;j<n;j++)
            {
                matrix[0][j]=1;
            }
        }
        if(flagCol0)
        {
            for(int i=0;i<m;i++)
            {
                matrix[i][0]=1;
            }
        }
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}



// } Driver Code Ends