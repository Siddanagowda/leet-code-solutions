class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int> res(n,0);
        if(k==0) return res;

        if(k>0){
            for(int i=0;i<n;i++){
                int tot=0;
                for(int j=1;j<=k;j++){
                    tot+=code[(i+j)%n];
                }
                res[i]=tot;
            }
        }
        if(k<0){
            for(int i=0;i<n;i++){
                int tot=0;
                for(int j=1;j<=-k;j++){
                    tot+=code[(i-j+n)%n];
                }
                res[i]=tot;
            }
        }
        return res;
    }
};