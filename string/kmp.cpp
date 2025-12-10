vector<int> lps_function(const string &s) {
    int n = s.size();
    vector<int> lps(n, 0);

    for (int i = 1, len = 0; i < n; ) {
        if (s[i] == s[len]) {
            lps[i++] = ++len;
        } else if (len) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }
    return lps;
}


vector<int> kmp_search(string text, string pattern) {
    vector<int> res;
    vector<int> lps = lps_function(pattern);

    for (int i = 0, j = 0; i < text.size(); ) {
        if (text[i] == pattern[j]) {
            i++; j++;
        }
        if (j == pattern.size()) {
            res.push_back(i - j); // match index
            j = lps[j - 1];
        } else if (i < text.size() && text[i] != pattern[j]) {
            j ? j = lps[j - 1] : i++;
        }
    }
    return res;
}
