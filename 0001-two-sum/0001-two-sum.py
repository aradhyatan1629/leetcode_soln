class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                val_i = nums[i]
                val_j = nums[j]
                
                if val_i + val_j == target:
                    return [i,j]
                
            
        
        return [-1,-1]
                
                
                

        
        
