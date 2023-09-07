class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int total_element = rows*cols;

        int startingRow = 0;
        int startingCol = 0;
        int endingRow = rows-1;
        int endingCol = cols-1;

        vector<int>ans;

        int count = 0;
        
        while(count < total_element){
            // printing starting row
            for(int i=startingCol; i<=endingCol && count < total_element; i++){
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;

            // printing ending col
            for(int i=startingRow; i<=endingRow && count < total_element; i++){
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;

            // printing ending row
            for(int i=endingCol; i>=startingCol && count < total_element; i--){
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;

            // printing starting col
            for(int i=endingRow; i>=startingRow && count < total_element; i--){
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;
        }
        return ans;
    }
};