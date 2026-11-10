class Solution {
public:
    int minOperations(string s) {
        if(s.size() == 1){
            return 0;
        }
        if(s.size() == 2){
            char max = *max_element(s.begin(), s.end());
            char min = *min_element(s.begin(), s.end());
            if(max == s[1] && min == s[0]){
                return 0;
            }
            return -1;
        }
        
        char ending_char = s[s.size() - 1];
        string starting = s.substr(0, s.size() - 1);
        char starting_char = s[0];
        string ending = s.substr(1, s.size());
        string sorted = s;

        sort(starting.begin(), starting.end());
        sort(ending.begin(), ending.end());
        sort(sorted.begin(), sorted.end());

        if(s == sorted){
            return 0;
        }
        if((starting + string(1, ending_char)) == sorted){
            return 1;
        }
        if((string(1, starting_char) + ending) == sorted){
            return 1;
        }


        string first_ltr = starting + string(1, ending_char);
        string sub_first_ltr = first_ltr.substr(1, first_ltr.size());
        sort(sub_first_ltr.begin(), sub_first_ltr.end());
        string second_ltr = string(1, first_ltr[0]) + sub_first_ltr;


        string first_rtl = string(1, starting_char) + ending;
        string sub_first_rtl = first_rtl.substr(0, first_rtl.size() - 1);
        sort(sub_first_rtl.begin(), sub_first_rtl.end());
        string second_rtl = sub_first_rtl + string(1, first_rtl[first_rtl.size() - 1]);
        

        if(second_rtl == sorted || second_ltr == sorted){
            return 2;
        }

        return 3;
        
    }
};