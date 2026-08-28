class Solution:
    def climbStairs(self, n: int) -> int:
        a,b = 1 ,1
        while(n > 1):
            c = a + b
            a = b
            b = c
            n -= 1
        return b
        
        