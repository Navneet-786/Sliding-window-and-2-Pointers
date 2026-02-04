// User function template for C++
class Solution {
  public:
 
    unordered_map<char, int>mpp;
    bool isAnangram(string &txt,int start, int end){
        for(auto it:mpp){
            if(it.second !=0)return false;
        }
        return true;
    }
    int search(string &pat, string &txt) {
      int k = pat.size(); //window size
      int n = txt.size();
      
      //fill the map
      for(int i = 0;i<pat.size();i++){
          mpp[pat[i]]++;
      }
      
      int count = 0;
      int i = 0,j = 0;
      
      //apply the sliding window
      while(j<n){
          if(mpp.count(txt[j])){
              mpp[txt[j]]--;
          }
          
          if(j-i+1< k)j++;
          else if(j-i+1 == k){
             if(isAnangram(txt, i,j)){
                 count++;
             } 
             
             j++;
             
             //before moveing i check if ith element is 
             //map part
             if(mpp.count(txt[i])){
                 //yes ->increase the freq and also i
                 mpp[txt[i]]++;
             }
             i++;
          }
      }
     return count;
      
    }
};