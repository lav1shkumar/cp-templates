string toBinary(int n) {
    if (n == 0) return "0";

    string res = "";
    while (n > 0) {
        res.push_back((n & 1) + '0');
        n >>= 1;
    }
    reverse(res.begin(), res.end());
    return res;
}



string bin = bitset<32>(n).to_string();
// remove leading zeros
bin = bin.substr(bin.find('1'));