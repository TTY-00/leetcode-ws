class Solution(object):

    # timeout
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        map = {}
        result = []
        
        for i in range(0, len(nums)):
            for j in range(i + 1, len(nums)):
                for k in range(j + 1, len(nums)):
                    if (nums[i] + nums[j] + nums[k]) == 0:
                        
                        temp = [nums[i], nums[j], nums[k]]
                        temp.sort()
                        if temp not in result:
                            result.append(temp)
                            
        return result