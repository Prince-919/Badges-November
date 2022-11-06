class Solution {
public:
// 2131. Longest Palindrome by Concatenating Two Letter Words
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        for(string& str: words)
            mp[str]++;
        int ans = 0;
        bool taken = false;
        for(string word: words){
            string rev_word = word;
            reverse(rev_word.begin(), rev_word.end());
            
            if(mp[rev_word]>0 && mp[word]>0 && rev_word != word || (word[0] == word[1] && mp[rev_word] > 1)){
                mp[word]--;
                mp[rev_word]--;
                ans += 4;
            }else if(word[0] == word[1] && !taken && mp[rev_word]){
                ans += 2;
                taken = true;
                mp[rev_word]--;
            }
        }
        return ans;
    }
};