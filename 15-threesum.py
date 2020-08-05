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

    # timeout
    def twoSum(self, nums):
        self.two_map = {}
        self.two_num_map = {}
        
        # print(nums)
        for i, ni in enumerate(nums):
            for j, nj in enumerate(nums[i + 1:]):
                sum_two = ni + nj
                if sum_two not in self.two_map:
                    self.two_map[sum_two] = []
                if sum_two not in self.two_num_map:
                    self.two_num_map[sum_two] = []
                    
                if ni <= nj and [ni, nj] not in self.two_num_map[sum_two]:
                    self.two_map[sum_two].append([i, j + i + 1])
                    self.two_num_map[sum_two].append([ni, nj])
                    
                if ni > nj and [nj, ni] not in self.two_num_map[sum_two]:
                    self.two_map[sum_two].append([j + i + 1, i])
                    self.two_num_map[sum_two].append([nj, ni])
                    
    # timeout            
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        self.twoSum(nums)

        result_map = {}
        result = []
        
        
        for i, n in enumerate(nums):
            diff = 0 - n
            if not diff in self.two_map:
                continue
                
            for r in self.two_map[diff]:
                
                if i in r:
                    continue

                if n < nums[r[0]]:
                    temp = [n, nums[r[0]], nums[r[1]]]
                elif n > nums[r[1]]:
                    temp = [nums[r[0]], nums[r[1]], n]
                else:
                    temp = [nums[r[0]], n, nums[r[1]]]
                    
                result.append(temp)
                    
            
        return set(result)