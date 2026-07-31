class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t): return False
        alpha = [0] * 26
        for i in range(len(s)):
            alpha[ord(s[i]) - ord('a')] += 1
            alpha[ord(t[i]) - ord('a')] -= 1
        return all([a == 0 for a in alpha])