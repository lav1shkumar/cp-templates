vector<int> manacher(string s) {
    string t = "#";
    for (char c : s) t += c, t += "#";

    int n = t.size();
    vector<int> p(n, 0);
    int l = 0, r = -1;

    for (int i = 0; i < n; i++) {
        int k = (i > r) ? 1 : min(p[l + r - i], r - i + 1);
        while (i - k >= 0 && i + k < n && t[i - k] == t[i + k]) k++;
        p[i] = k--;
        if (i + k > r) l = i - k, r = i + k;
    }
    return p;  // palindrome radius
}
