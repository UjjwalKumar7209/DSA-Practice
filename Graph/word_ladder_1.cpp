/*
Problem: 127. Word Ladder  
Platform: LeetCode  
Link: https://leetcode.com/problems/word-ladder/  
Approach:
- Use BFS to find the shortest transformation sequence from beginWord to endWord.
- Push {beginWord, 1} into a queue, where 1 represents the current transformation step.
- Store all words in an unordered_set for O(1) lookup and deletion.
- For each word in the queue, try changing every character (a-z) one by one.
- If the transformed word exists in the set, push it to the queue and erase it to avoid revisiting.
- If we reach endWord, return the current step count.
- If BFS completes without finding endWord, return 0.
Time: O(N * M * 26), where N = wordList size, M = word length  
Space: O(N * M)  
Date: July 17, 2025
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(beginWord) != st.end()) {
            st.erase(beginWord);
        }

        while (!q.empty()) {
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            if (word == endWord) return step;
            for (int i = 0; i < word.size(); i++) {
                char orignal = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (st.find(word) != st.end()) {
                        q.push({word, step+1});
                        st.erase(word);
                    }
                }
                word[i] = orignal;
            }
        }
        return 0;
    }
};
