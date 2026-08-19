class Solution {
public:

    void dfs(
        string word,
        string beginWord,
        unordered_map<string, vector<string>>& parent,
        vector<string>& path,
        vector<vector<string>>& ans
    ) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for (string p : parent[word]) {
            path.push_back(p);
            dfs(p, beginWord, parent, path, ans);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList
    ) {
        unordered_set<string> st(wordList.begin(), wordList.end());

        vector<vector<string>> ans;

        if (st.find(endWord) == st.end())
            return ans;

        st.erase(beginWord);

        unordered_map<string, vector<string>> parent;

        queue<string> q;
        q.push(beginWord);

        bool found = false;

        while (!q.empty() && !found) {

            int n = q.size();

            unordered_set<string> usedThisLevel;

            while (n--) {

                string word = q.front();
                q.pop();

                string originalWord = word;

                for (int i = 0; i < word.size(); i++) {

                    char originalChar = word[i];

                    for (char ch = 'a'; ch <= 'z'; ch++) {

                        if (ch == originalChar)
                            continue;

                        word[i] = ch;

                        if (st.find(word) != st.end()) {

                            // First time seeing this word
                            if (usedThisLevel.find(word) == usedThisLevel.end()) {
                                q.push(word);
                                usedThisLevel.insert(word);
                            }

                            // Store the current word as a parent
                            parent[word].push_back(originalWord);

                            if (word == endWord)
                                found = true;
                        }
                    }

                    word[i] = originalChar;
                }
            }

            for (auto& word : usedThisLevel) {
                st.erase(word);
            }
        }

        // No path exists
        if (parent.find(endWord) == parent.end())
            return ans;

        vector<string> path;
        path.push_back(endWord);

        dfs(endWord, beginWord, parent, path, ans);

        return ans;
    }
};