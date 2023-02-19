
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        numSet = set(nums)


        largestBucket = 0
        for val in numSet:
	        #determine if theres a left neighbhour 
            if (val-1) not in numSet:
                length = 1
                while True:
	                # while there is a right neighbour 
                    if val+length in numSet:
                        length +=1
                    else:
                        break
                largestBucket = max(length,largestBucket)

        return largestBucket