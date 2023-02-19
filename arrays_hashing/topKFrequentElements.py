
class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        kMap = {}

        for val in nums:
            kMap[val] = kMap.get(val, 0) + 1

        kList = list(kMap.items())

        kList.sort(key=lambda a : a[1], reverse=True )      

        return [kList[i][0] for i in range(k)] 
    
def main():
    s = Solution()
    print(s.topKFrequent([1,1,1,2,2,3], 2))
    print(s.topKFrequent([1], 1))

if __name__ == "__main__":
    main()
    