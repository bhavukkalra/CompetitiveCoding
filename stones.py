class Solution:
    def greatest_on_last(self,stones,covered):
        for i in range(2):
            for j in range(covered -1):
                if(stones[j] > stones[j+1]):
                    stones[j],stones[j+1] = stones[j+1],stones[j]
    
    def lastStoneWeight(self, stones) -> int:
        self.covered = len(stones)
        while(True):
            
            if(self.covered == 0):
                return 0
            if(self.covered == 1):
                return stones[0]    
            self.greatest_on_last(stones,self.covered)
            final1 = self.covered - len(stones) - 1
            final2 = self.covered - len(stones) - 2
            if(stones[final1] == stones[final2]):
                self.covered = self.covered - 2
            if(stones[final1] != stones[final2]):
                print(final1,final2,self.covered)
                stones[final2] = stones[final1] - stones[final2]
                self.covered = self.covered - 1
list1 = [3,7,8]
obj = Solution()  
obj.lastStoneWeight(list1)             
                
               