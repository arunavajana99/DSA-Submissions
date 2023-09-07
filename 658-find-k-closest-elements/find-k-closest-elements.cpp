class Solution {
public:
    int lowerBound(vector<int>& arr, int x){
        int start = 0;
        int end = arr.size()-1;
        int ans = end;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(arr[mid] >= x){
                ans = mid;
                end = mid-1;
            }
            else if(arr[mid] > x){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }

    vector<int> binarySearchApproach(vector<int>& arr, int k, int x){
        int h = lowerBound(arr, x);
        int l = h-1;
        while(k--){
            if(h > arr.size()-1){
                l--;
            }
            else if(l < 0){
                h++;
            }
            else if((x-arr[l]) > (arr[h]-x)){
                h++;
            }
            else{
                l--;
            }
        }
        return vector<int>(arr.begin()+l+1, arr.begin()+h);
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        return binarySearchApproach(arr, k, x);
    }
};