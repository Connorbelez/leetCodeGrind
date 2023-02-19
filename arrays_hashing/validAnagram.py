class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        sMap = {}
        tMap = {}
        sLen = len(s)
        tLen = len(t)
        if sLen != tLen:
            return False
        
        for i in range(sLen):
            sChar = s[i]
            tChar = t[i]

            if sChar not in sMap: sMap[sChar] = 1
            else: sMap[sChar] +=1

            if tChar not in tMap: tMap[tChar] = 1
            else: tMap[tChar] +=1
        
        for key,val in sMap.items():
            if key not in tMap or tMap[key] != val:
                return False

        return True
    

def main():
    s = Solution()
    print(s.isAnagram("anagram", "nagaram"))
    print(s.isAnagram("rat", "car"))

if __name__ == "__main__":
    main()