class Solution {
public:
    string defangIPaddr(string address) {
        string from = ".";
        string to = "[.]";
        size_t pos = 0;
        while ((pos = address.find(from, pos)) != string::npos) {
            address.replace(pos, from.length(), to);
            pos += to.length();  // Move past the replaced part
        }
        return address;
    }
};