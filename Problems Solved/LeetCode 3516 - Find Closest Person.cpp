//Question link: https://leetcode.com/problems/find-closest-person/description

class Solution {
public:
    int findClosest(int x, int y, int z) {
        int distanceXZ = abs(z - x);
        int distanceYZ = abs(z - y);
        
        if (distanceXZ == distanceYZ) {
            return 0;
        } else if (distanceXZ < distanceYZ) {
            return 1;
        } else {
            return 2;
        }
    }
};