class Solution {
public:
    string countOfAtoms(string formula) {
        unordered_map<string, int> freq;
        int n = formula.size();

        for(int i = 0; i < n; ) {
            
            // Case 1: Parenthesis group
            if (formula[i] == '(') {
                int start = i + 1;
                int cnt = 1;
                i++;
                
                // find matching ')'
                while (i < n && cnt) {
                    if (formula[i] == '(') cnt++;
                    else if (formula[i] == ')') cnt--;
                    i++;
                }
                
                string sub = formula.substr(start, i - start - 1);
                auto inner = countOfAtoms(sub); // recursive call
                
                // Extract multiplier after ')'
                int mul = 0;
                while (i < n && isdigit(formula[i])) {
                    mul = mul * 10 + (formula[i] - '0');
                    i++;
                }
                if (mul == 0) mul = 1;

                // Add inner result to main freq
                for (int j = 0; j < inner.size(); j++) {
                    // parse atom+count from inner result
                    int k = j+1;
                    while(k < inner.size() && islower(inner[k])) k++; // atom done
                    string atom = inner.substr(j, k-j);
                    
                    int num = 0;
                    while(k < inner.size() && isdigit(inner[k])) {
                        num = num*10 + (inner[k]-'0');
                        k++;
                    }
                    if(num == 0) num = 1;
                    
                    freq[atom] += num * mul;
                    j = k-1;
                }
            }

            // Case 2: Atom
            else if (isalpha(formula[i]) && isupper(formula[i])) {
                int start = i;
                i++;
                while (i < n && islower(formula[i])) i++; // atom name
                string atom = formula.substr(start, i - start);

                int mul = 0;
                while (i < n && isdigit(formula[i])) {
                    mul = mul * 10 + (formula[i] - '0');
                    i++;
                }
                if (mul == 0) mul = 1;

                freq[atom] += mul;
            }

            else {
                i++;
            }
        }

        // Sorting and building final result
        vector<pair<string,int>> arr(freq.begin(), freq.end());
        sort(arr.begin(), arr.end());

        string res;
        for (auto &p : arr) {
            res += p.first;
            if (p.second > 1) res += to_string(p.second);
        }
        return res;
    }
};
