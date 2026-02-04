class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
       //create a vector to store first negative value
       vector<int>ans;
       
       int i = 0;
       int j = 0;
       
       //create a queueu to store and track which is 
       //the first -ve element till now in given window
       queue<int>q;
       
       while(j<arr.size()){
           //if elemnt is negative then push into queue
           if(arr[j] < 0)q.push(arr[j]);
           
           //if size is small then increase
           if(j-i+1 < k)j++;
           else if(j-i+1 == k){
               //first check is queue is empty
                // empty-> no -ve element in window
                if(q.empty()){
                    ans.push_back(0);
                }else{
                    ans.push_back(q.front());
                }
                
                
                j++;
                
                //before moveing i , enusure it 
                //that ith element is not negative
                //if negative then pop from queue also
                if(arr[i] < 0){
                    q.pop();
                }
                i++;
           }
       }
       return ans;
    }
};