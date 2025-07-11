/*
Problem: Alien Dictionary  
Platform: GFG  
Link: https://www.geeksforgeeks.org/problems/alien-dictionary/1  
Approach:
- Given a sorted dictionary of alien words, infer the order of characters.
- Compare adjacent words and find the first different character.
- Add a directed edge from the first different char of word1 to word2.
- Construct an adjacency list and apply **Kahn's Algorithm** (BFS-based Topo Sort).
- The resulting topological sort gives the correct character order.
Time: O(N + K), Space: O(K)  
  where N = number of words, K = number of characters  
Date: July 11, 2025
*/

vector<int> topoSort(int k, vector<int> adj[]) {
    vector<int> indegree(k, 0);
    for (int i = 0; i < k; i++) {
        for (auto it: adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < k; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> topo;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto it: adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0) q.push(it);
        }
    }
    return topo;
}

string getAlienLanguage(vector<string> &dictionary, int k) {
    int N = dictionary.size();
    vector<int> adj[k];

    for (int i = 0; i < N - 1; i++) {
        string s1 = dictionary[i];
        string s2 = dictionary[i + 1];
        int len = min(s1.size(), s2.size());
        for (int j = 0; j < len; j++) {
            if (s1[j] != s2[j]) {
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                break;
            }
        }
    }

    vector<int> topo = topoSort(k, adj);
    string ans = "";
    for (int i : topo) {
        ans += char(i + 'a');
    }
    return ans;
}
