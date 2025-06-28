void failure_function(string s, vector<int> &len) {
    int j = 0, i = 1, sz = s.size();
    while (i < sz) {
        if (s[i] == s[j]) {
            len[i++] = ++j;
        } else if (j == 0) {
            len[i++] = 0;
        } else {
            j = len[j - 1];
        }
    }
}
// len[i] - the length of the longest proper prefix that is also suffix for s[0, i]
