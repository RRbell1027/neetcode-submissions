class Solution {
public:

    int spend(vector<int>& piles, int eat) {
        int res = 0;
        for (int i = 0; i < piles.size(); ++i) {
            res += (piles[i] + eat - 1) / eat;
        }
        return res;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        
        int maxpile = 0;
        for (int i = 0; i < n; ++i) {
            maxpile = max(maxpile, piles[i]);
        }

        int left = 1, right = maxpile, mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (spend(piles, mid) > h)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};
