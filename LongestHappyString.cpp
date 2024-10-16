class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a>0) pq.push({a,'a'});
        if(b>0) pq.push({b,'b'});
        if(c>0) pq.push({c,'c'});
        string st="";

        while(!pq.empty()){
            auto [n1,x1]=pq.top();
            pq.pop();

            if(st.size()<2 || st[st.size()-1]!=x1 || st[st.size()-2]!=x1){
                st+=x1;
                n1--;
                if(n1>0)
                    pq.push({n1,x1});
            }
            else{
                if(pq.empty()) break;
                auto [n2,x2]=pq.top();
                pq.pop();
                st+=x2;
                n2--;
                if(n2>0) pq.push({n2,x2});
                pq.push({n1,x1});
            }
        }
        return st;
    }
};