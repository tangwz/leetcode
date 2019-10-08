/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
class Trie {
private:
    bool is_word = false;
    Trie* next[26] = { nullptr };    
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* root = this;
        for (const auto& w : word) {
            if (root->next[w-'a'] == nullptr) {
                root->next[w-'a'] = new Trie();
            }
            root = root->next[w-'a'];
        }
        root->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* root = this;
        for (const auto& w : word) {
            if (root->next[w-'a']) root = root->next[w-'a'];
            else return false;
        }
        return root->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* root = this;
        for (const auto& w : prefix) {
            if (root->next[w-'a']) root = root->next[w-'a'];
            else return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

