class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        char target = '.';
        for (int i = 0; i < emails.size(); i++) {
            string s = emails[i];

            // Find position of '@'
            int atTheRate = -1;
            for (int j = 0; j < s.length(); j++) {
                if (s[j] == '@') {
                    atTheRate = j;
                    break;
                }
            }

            // Remove everything after '+' in local part
            for (int j = 0; j < atTheRate; j++) {
                if (s[j] == '+') {
                    s = s.substr(0, j) + s.substr(atTheRate);
                    atTheRate = j; // update local length
                    break;
                }
            }

            // Remove '.' in local part
            int write = 0;
            for (int read = 0; read < s.size(); read++) {
                if (read < atTheRate && s[read] == target) continue;
                s[write++] = s[read];
            }
            s.resize(write);

            emails[i] = s;
        }

        // Count unique emails
        set<string> unique(emails.begin(), emails.end());
        return unique.size();
    }
};
