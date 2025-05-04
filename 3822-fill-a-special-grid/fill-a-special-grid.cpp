    class Solution {
    private:
        void fill(vector<vector<int>>& mat, int r, int c, int n, int start) {
        if (n == 1) {
            mat[r][c] = start;
            return;
        }

        int half = n / 2;
        int quad = (n * n) / 4;

        fill(mat, r, c, half, start + 3 * quad);            
        fill(mat, r + half, c, half, start + 2 * quad);      
        fill(mat, r + half, c + half, half, start + quad);   
        fill(mat, r, c + half, half, start);                 
}
public:
    vector<vector<int>> specialGrid(int N) {
        int dim = 1 << N; 
        vector<vector<int>> mat(dim, vector<int>(dim, -1));
        fill(mat, 0, 0, dim, 0);
        return mat;
    }
};