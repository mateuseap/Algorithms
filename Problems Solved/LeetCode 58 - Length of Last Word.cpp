//Question link: https://leetcode.com/problems/length-of-last-word/description

class Solution {
public:
    int lengthOfLastWord(string s) {
        int start = 0;
        int end = s.length();
        string lastWord, temp;

        while (start < end) {
            for (int i = start; i < end; i++) {
                if (s[i] == ' ') {
                    break;
                } else {
                    temp += s[i];
                }
            }

            if (temp.length() == 0) {
                start++;
            } else { 
                start += temp.length();
                lastWord = temp;
            }

            temp.clear();
        }
        
        return lastWord.length();
    }
};
