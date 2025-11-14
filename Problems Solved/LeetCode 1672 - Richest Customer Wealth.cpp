//Question link: https://leetcode.com/problems/richest-customer-wealth/description

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int greatestWealth = 0, temp = 0;

        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 0; j < accounts[i].size(); j++) {
                temp += accounts[i][j];
            }

            if (temp > greatestWealth) {
                greatestWealth = temp;
            }

            temp = 0;
        }

        return greatestWealth;
    }
};