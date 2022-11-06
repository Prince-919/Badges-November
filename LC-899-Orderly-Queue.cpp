
// 899. Orderly Queue
class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k==1){
            string ans = s;
            s+=s;
            for(int i=1; i<size(ans); i++){
                ans = min(ans, s.substr(i,size(ans)));
            }
            return ans;
        }    
        sort(s.begin(),s.end());
        return s;
    }
};