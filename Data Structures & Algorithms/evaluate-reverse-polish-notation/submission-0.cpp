class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(string s : tokens) {
            if(s!="+" && s!="-" && s!="*" && s!="/") {
                st.push(stoi(s));
            }
            else if(s=="+") {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(first+second);
            }
            else if(s=="-") {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(second-first);
            }
            else if(s=="*") {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(first*second);
            }
            else if(s=="/") {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(second/first);
            }
        }
        return st.top();
    }
};
