class Solution {
public:
    bool checkValidString(string s) {
        vector<int> star_index, open, closed;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '*'){
                star_index.push_back(i);
            }
            else if(s[i] == '('){
                open.push_back(i);
            }
            else{
                closed.push_back(i);
            }
        }

        for(int i = 0; i < closed.size(); i++){
            bool found = false;
            int t = closed[i];
            auto it = lower_bound(open.begin(), open.end(), t);
            if (it == open.begin()) {
                auto it_ = lower_bound(star_index.begin(), star_index.end(), t);
                if(it_ == star_index.begin()){
                    return false;
                }
                else{
                    it_--;
                    int idx = it_ - star_index.begin();
                    star_index.erase(star_index.begin() + idx);
                    found = true;
                }
            } 
            else {
                --it;
                int idx = it - open.begin();
                open.erase(open.begin() + idx);
                found = true;
            }

            if(found){
                closed.erase(closed.begin() + i);
                i--;
            }
        }




        for(int i = 0; i < open.size(); i++){
            bool found = false;
            int t = open[i];
            auto it = upper_bound(closed.begin(), closed.end(), t);
            if (it == closed.end()) {
                auto it_ = upper_bound(star_index.begin(), star_index.end(), t);
                if(it_ == star_index.end()){
                    return false;
                }
                else{
                    int idx = it_ - star_index.begin();
                    star_index.erase(star_index.begin() + idx);
                    found = true;
                }
            } 
            else {
                int idx = it - closed.begin();
                closed.erase(closed.begin() + idx);
                found = true;
            }

            if(found){
                open.erase(open.begin() + i);
                i--;
            }
        }



        return closed.empty() && open.empty();
    }
};