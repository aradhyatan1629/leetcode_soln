class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> ballColor;
        unordered_map<int,int> colorFreq;
        
        vector<int> ans;
        for(int i=0;i<queries.size();i++)
        {
            int ball = queries[i][0];
            int color = queries[i][1];
            if(ballColor.find(ball)!=ballColor.end())
            {
                if(color == ballColor[ball])
                    ans.push_back(colorFreq.size());
                else
                {
                    colorFreq[ballColor[ball]]--;
                    if(colorFreq[ballColor[ball]] == 0)
                        colorFreq.erase(ballColor[ball]);
                    
                    ballColor[ball] = color;
                    colorFreq[color]++;
                    ans.push_back(colorFreq.size());
                }
            }
            else
            {
                ballColor[ball] = color;
                colorFreq[color]++;
                ans.push_back(colorFreq.size());
            }
        }
        return ans;
    }
};