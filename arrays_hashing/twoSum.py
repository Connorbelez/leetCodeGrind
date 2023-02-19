class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        numMap = {}
        for i,val in enumerate(nums):
            remainder = target - val
            if remainder in numMap:
                indexOfRemainder = numMap[remainder]
                return [indexOfRemainder, i]

            if val not in numMap:
                numMap[val] = i
                

def main():
    s = Solution()
    print(s.twoSum([2,7,11,15], 9))
    print(s.twoSum([3,2,4], 6))
    print(s.twoSum([3,3], 6))

if __name__ == "__main__":
    main()