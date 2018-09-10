class Solution {
private:
    void help(vector<int> nums,int i,int j,vector<vector<int>>& res)
    {
        if(i==j-1)   //每次i走到最后说明结束，return到原本的位置，k++即可
        {
            res.push_back(nums);
            return;
        }
        
        for(int k=i;k<j;k++)
        {
            if(i!=k && nums[i]==nums[k])   //为了去重
                continue;
            swap(nums[i],nums[k]);
            help(nums,i+1,j,res);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());  //为了去重
        vector<vector<int>> res;
        int n=nums.size();
        if(n==0)
            return res;
        
        help(nums,0,n,res);
        
        return res;

    }
};
