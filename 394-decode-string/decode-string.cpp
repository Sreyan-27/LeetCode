class Solution {
public:
    string decodeString(string s) {
        stack<int> num;
        stack<string> st;

        string curr = "";
        int k = 0;

        for (char c : s) {

            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            }

            else if (c == '[') {
                num.push(k);
                st.push(curr);

                k = 0;
                curr = "";
            }

            else if (c == ']') {
                int repeat = num.top();
                num.pop();

                string prev = st.top();
                st.pop();

                for (int i = 0; i < repeat; i++) {
                    prev += curr;
                }

                curr = prev;
            }

            else {
                curr += c;
            }
        }

        return curr;
    }
};