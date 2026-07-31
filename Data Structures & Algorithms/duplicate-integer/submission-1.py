class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        if nums == []: return False
        nums.sort()
        last_n = nums[0]
        for n in nums[1:]:
            if last_n == n:
                return True
            last_n = n
        return False