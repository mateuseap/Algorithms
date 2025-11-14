//Question link: https://leetcode.com/problems/reverse-degree-of-a-string/description

class Solution {
public:
    int reverseDegree(string s) {
        map<char, int> degrees;
        int currentDegree = 26, result = 0;
        
        for (char i = 'a'; i <= 'z'; i++) {
            degrees[i] = currentDegree;
            currentDegree -= 1;
        }

        for (int i = 0; i < s.size(); i++) {
            result += degrees[s[i]] * (i + 1);
        }

        return result;
    }
};