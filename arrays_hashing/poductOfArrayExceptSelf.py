class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        res = [1] * len(nums)
        pre = 1
        for i in range(1,len(nums)):
            res[i] = pre*nums[i-1]
            pre = res[i]
        res[0] = 1 
        #index at i represents the product of all the numbers to the left of i in the nums array
        post = 1 
        for j in range(len(nums)-2,-1,-1):
            #post represents the product of all the numbers to the right of i in the nums array, 
            #we keep track of this by multiplying it by the number to the right of j
            post = post*nums[j+1] 
            #res[j] is the product of nums left of j, post is the product of nums right of j
            res[j] = res[j]*post 
        
        return res
    
def main():
    s = Solution()
    print(s.productExceptSelf([1,2,3,4]))
    print(s.productExceptSelf([-1,1,0,-3,3]))
    print(s.productExceptSelf([0,0]))
    print(s.productExceptSelf([1,0]))
    
if __name__ == "__main__":
    main()