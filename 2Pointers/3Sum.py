

class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        nums.sort()
        out = []

        p1 = 0
        p2 = 1
        p3 = len(nums) - 1 
        vals = set()

        for i,p1 in enumerate(nums):
            p2 = i + 1
            p3 = len(nums) - 1 
            
            if i >=1 and p1 == nums[i-1]:
                continue
        
            
            while(p2 < p3):
                if(p1 + nums[p2] + nums[p3] == 0):
                    out.append([p1,nums[p2], nums[p3]])
                    
                    #move to next non-duplicate
                    p3 -=1
                    while(nums[p2] == nums[p2-1] and p2 < p3):
                        p2 +=1
                    if p3 < len(nums) - 1:
                        while(nums[p3] == nums[p3+1] and p3 > p2):
                            p3 -=1

                if (p1 + nums[p2] + nums[p3] > 0):
                    p3 -=1
                if (p1 + nums[p2] + nums[p3] < 0):
                    p2 +=1

        return out
            
                
            
            


def main():
    nums  = [-1,0,1,2,-1,-4]
    num2 = [-2,0,1,1,2]

    s = Solution()
    # print(s.threeSum(nums))
    print(s.threeSum(num2))
if __name__ == "__main__":
    main()