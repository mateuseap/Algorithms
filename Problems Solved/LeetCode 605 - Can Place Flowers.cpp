//Question link: https://leetcode.com/problems/can-place-flowers/description/

class Solution {
public:
    bool checkAdjacentPlots(int prev, int current, int next) {
        if ((prev == 0 || prev == -1) && current == 0 && (next == 0 || next == -1)) 
            return true;
        return false;
    }

    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int unplacedFlowers = n;
        int size = flowerbed.size();
        for (int i = 0; i < size; i++) {
            if (flowerbed[i] == 1) continue;

            int prev = (i == 0) ? -1 : flowerbed[i - 1];
            int next = (i == size - 1) ? -1 : flowerbed[i + 1];

            if (checkAdjacentPlots(prev, flowerbed[i], next)) {
                unplacedFlowers--;
                flowerbed[i] = 1;
            }
        }

        return unplacedFlowers <= 0;
    }
};
