class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string aug = "1" + s + "1";

        int active = 0;
        for (char c : s)
            active += (c == '1');

        int ans = active;

        int leftZero = -1;
        int oneBlock = 0;
        int rightZero = 0;

        int i = 0;
        while (i < aug.size()) {

            if (aug[i] == '0') {
                int len = 0;
                while (i < aug.size() && aug[i] == '0') {
                    len++;
                    i++;
                }

                if (leftZero == -1)
                    leftZero = len;
                else
                    rightZero = len;
            }
            else { 
                int len = 0;
                while (i < aug.size() && aug[i] == '1') {
                    len++;
                    i++;
                }

                if (leftZero != -1 && oneBlock > 0 && rightZero > 0) {
                    ans = max(ans, active + leftZero + rightZero);

                    leftZero = rightZero;
                    rightZero = 0;
                }

                oneBlock = len;
            }
        }

        return ans;
    }
};