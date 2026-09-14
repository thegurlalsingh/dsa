class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        vector<int> new_pos, new_speed;
        new_pos.push_back(position[0]);
        new_speed.push_back(speed[0]);
        for(int i = 1; i < position.size(); i++){
            if(position[i] - new_pos.back() <= distance){
                new_pos.pop_back();
                new_speed.pop_back();
                new_pos.push_back(position[i]);
                new_speed.push_back(speed[i]);
            }
            else {
                new_pos.push_back(position[i]);
                new_speed.push_back(speed[i]);
            }
        }

        int groups = 0;
        stack<pair<int, int>> st;
        for(int i = 0; i < new_pos.size(); i++){
            st.push({new_pos[i], new_speed[i]});
        }

        // int prev_pos = new_pos[0]; int prev_speed = new_speed[0];
        // for(int i = 1; i < new_pos.size(); i++){
        //     if(new_speed[i] >= prev_speed){
        //         groups++;
        //     }
        //     prev_pos = new_pos[i]; prev_speed = new_speed[i];
        // }


        while(!st.empty()){
            auto [p, s] = st.top(); st.pop();
            while(!st.empty() && s < st.top().second){
                st.pop();
            }
            groups++;
        }


        return groups;
    }
};