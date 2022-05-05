class Solution {
public:
    string decodeString(string s) {
        s.push_back('#');                   //结束符
        stack<string> st;
        string ret;
        int i = 0, j, n = s.size();
        while(i < n){
            if(islower(s[i])){
                for(j = i; j < n && islower(s[j]); ++j);
                st.push(s.substr(i, j - i));
            }else if(isdigit(s[i])){
                for(j = i; j < n && isdigit(s[j]); ++j);
                st.push(s.substr(i, j - i));
            }else if(s[i] == '['){
                j = i + 1;
                st.push("[");
            }else if(s[i] == ']'){
                j = i + 1;
                string tmp, dec;
                while(st.top() != "["){
                    tmp = st.top() + tmp;
                    st.pop();
                }
                st.pop();
                int times = stoi(st.top());
                st.pop();
                for(int t = 0; t < times; ++t)
                    dec += tmp;
                st.push(dec);
            }else{                          //结束符
                while(!st.empty()){
                    ret = st.top() + ret;
                    st.pop();
                }
                break;  
            }
            i = j;
        }
        return ret;
    }
};