
vector<int> zFunction(string s) {
    int l = 0, r = 0, idx = 1, sz = s.size();
    vector<int> maxLen(sz);
    while (idx < sz) {
        if (idx < r) {
            maxLen[idx] = min(r - idx, maxLen[idx - l]);
        }
        while (idx + maxLen[idx] < sz and s[idx + maxLen[idx]] == s[maxLen[idx]]) {
            maxLen[idx]++;
        }
        if (idx + maxLen[idx] > r) {
            l = idx;
            r = idx + maxLen[idx];
        }
        idx++;
    }
    return maxLen;
}
// maxLen[i] = lungimea celui mai lung prefix pentru sirul s care incepe pe pozitia i