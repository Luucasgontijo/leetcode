// 392. Is Subsequence
// https://leetcode.com/problems/is-subsequence/

bool isSubsequence(char* s, char* t) {
    int j = 0, i = 0;
    while (t[i] != '\0' && s[j] != '\0'){
     if (s[j] == t[i]){
         j++;
     } 
     i++;
    }
    return s[j] == '\0'; 
}