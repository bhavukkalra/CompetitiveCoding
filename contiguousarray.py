def findmax(list_of_counts):
    init_address = {}
    maxCheck = 0
    max_check_0 = 0
    for i in range(len(list_of_counts)):
        if(list_of_counts[i] not in init_address.keys()):
            init_address[list_of_counts[i]] = i
        if(list_of_counts[i] == 0):
            max_check_0 = i + 1
        maxCheck = max(maxCheck,i-init_address[list_of_counts[i]] + 1,max_check_0)
    return maxCheck        

class Solution:
    def findMaxLength(self, nums):
        self.check = []
        self.count = 0
        for i in nums:
            if(i == 1):
                self.count = self.count + 1
            else:
                self.count = self.count - 1
            self.check.append(self.count)
        print(self.check)    
        print(findmax(self.check))   
obj = Solution()
input = [0,1,0]
obj.findMaxLength(input)        
            
                
        