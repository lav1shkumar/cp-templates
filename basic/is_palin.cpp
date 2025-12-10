bool isPalindrome(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}


bool isPalindrome(int x) {
    if (x < 0) return false;

    int original = x;
    long long rev = 0;

    while (x > 0) {
        rev = rev * 10 + (x % 10);
        x /= 10;
    }
    return rev == original;
}
