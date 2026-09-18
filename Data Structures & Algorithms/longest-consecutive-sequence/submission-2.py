class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        num_set = set()
        for num in nums:
            num_set.add(num)
        
        max_len = 0
        while num_set:
            # check up
            pivot = num_set.pop()
            curr_len = 1
            i = 1
            while num_set and pivot + i in num_set:
                num_set.remove(pivot + i)
                curr_len += 1
                i += 1
            
            # check downwards
            i = 1
            while num_set and pivot - i in num_set:
                num_set.remove(pivot - i)
                curr_len += 1
                i += 1
            
            max_len = max(max_len, curr_len)
        
        return max_len
            
                    
        
