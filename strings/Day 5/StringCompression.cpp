string Compression (const string &s) {
    int count = 1;
    int i = 1;
    string result;
    while (i < s.size()) {
        while (i < s.size() && s[i] == s[i - 1]) {
            i++;
            count++;
        }
        result += s[i - 1] + to_string(count);
        count = 1;
        i++;
    }
    return result;
}
