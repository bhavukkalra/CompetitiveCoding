class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        final1 = ""
        final2 = ""
        len1 = 0
        len2 = 0
        l_given1 = len(S)
        l_given2 = len(T)

        for i in S:
            if(i == '#'):
                if(len1 != 0):
                    len1 = len1 - 1
                    final1[-1] = ""
            else:
                final1 = final1 + i
                len1 = len1 + 1
        for i in T:
            if(i == '#'):
                if(len2 != 0):
                    len2 = len2 - 1
                    final2 = final2[0:-1]
            else:
                final2 = final2 + i
                len2 = len2 + 1        
        if(final1 == final2):
            return True
        else:
            return False

        
        