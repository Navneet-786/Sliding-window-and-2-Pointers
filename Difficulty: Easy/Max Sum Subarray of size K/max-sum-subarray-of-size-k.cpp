class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int ans = INT_MIN;
        int sum = 0;
        
        int i = 0,j = 0;
        while(j<arr.size()){
            //adjust the window of size k
            while(j-i+1 <=k){
                sum += arr[j];
                j++;
            }
            ans = max(ans, sum);
            
            sum -= arr[i];
            i++;
            
        }
        return ans;
       
        // for(int i = 0;i<=arr.size()-k;i++){
        //      int sum = 0;
        //     for(int j = i;j<i+k;j++){
        //         sum+=arr[j];
        //     }
        //     ans = max(ans, sum);
        // }
        // return ans;
    }
};