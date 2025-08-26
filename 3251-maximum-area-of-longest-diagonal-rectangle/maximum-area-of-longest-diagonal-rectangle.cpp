class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int a = 0;
        double dl = 0;
        for(int i = 0; i < dimensions.size(); i++){
            double new_dl = sqrt((dimensions[i][0] * dimensions[i][0]) + (dimensions[i][1] * dimensions[i][1]));
            int new_a = dimensions[i][0] * dimensions[i][1];
            if(new_dl > dl){
                dl = new_dl;
                a = new_a;
            }
            else if(new_dl == dl && new_a > a){
                a = new_a;
            }
        }
        return a;
    }
};