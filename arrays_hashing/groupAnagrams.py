class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        anaMap = {}
        anaList = []
        for i,val in enumerate(strs):
            sortedWord = list(val)
            sortedWord.sort()
            sortedWord = "".join(sortedWord)


            if sortedWord not in anaMap:
                anaMap[sortedWord] = [i]
            else:
                anaMap[sortedWord].append(i)
        
        for key,valList in anaMap.items():
            row = [strs[i] for i in valList]
            anaList.append(row)

        return anaList
    
def main():
    s = Solution()
    print(s.groupAnagrams(["eat","tea","tan","ate","nat","bat"]))
    print(s.groupAnagrams([""]))
    print(s.groupAnagrams(["a"]))

if __name__ == "__main__":
    main()