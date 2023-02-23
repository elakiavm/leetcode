int longestSubstring(char *s, int k) {
    int n = strlen(s);
    int max_len = 0;
    
    for (int unique_chars = 1; unique_chars <= 26; unique_chars++) {
        int freq[26] = {0};
        int left = 0, right = 0;
        int num_unique_chars = 0, num_no_less_than_k = 0;
        
        while (right < n) {
            if (num_unique_chars <= unique_chars) {
                int idx = s[right] - 'a';
                if (freq[idx] == 0) {
                    num_unique_chars++;
                }
                freq[idx]++;
                if (freq[idx] == k) {
                    num_no_less_than_k++;
                }
                right++;
            } else {
                int idx = s[left] - 'a';
                if (freq[idx] == k) {
                    num_no_less_than_k--;
                }
                freq[idx]--;
                if (freq[idx] == 0) {
                    num_unique_chars--;
                }
                left++;
            }
            
            if (num_unique_chars == num_no_less_than_k && num_unique_chars == unique_chars) {
                max_len = fmax(max_len, right - left);
            }
        }
    }
    
    return max_len;
}
