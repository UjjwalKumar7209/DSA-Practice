/*
Problem: Lemonade Change (LeetCode #860)
Link: https://leetcode.com/problems/lemonade-change/
Approach: Track count of $5 and $10 bills; give change greedily prioritizing higher denominations when needed.
Time: O(n), Space: O(1)
Date: June 29, 2025
*/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                five++;
            } else if(bills[i] == 10) {
                if (five) {
                    five--;
                    ten++;
                } else return false;
            }
            else {
                if (five && ten) {
                    five--;
                    ten--;
                } else if(five >= 3) {
                    five -= 3;
                } else return false;
            }
        }
        return true;
    }
};
