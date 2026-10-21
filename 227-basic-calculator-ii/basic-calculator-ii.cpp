class Solution {
public:
    int evaluate(int a, int b, char c) {
        if (c == '+') {
            return a + b;
        } else if (c == '-') {
            return b - a;
        } else if (c == '*') {
            return a * b;
        }
        return b / a;
    }
    int calculate(string s) {
        unordered_map<char, int> mp = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
        string f;
        for (auto& c : s) {
            if (c != ' ') {
                f.push_back(c);
            }
        }
        stack<char> op;
        stack<int> num;
        for (int i = 0; i < f.length(); i++) {
            if (f[i] >= '0' && f[i] <= '9') {
                int n = 0;
                while (i < f.length() && isdigit(f[i])) {
                    n = n * 10 + (f[i] - '0');
                    i++;
                }
                num.push(n);
                i--;
            } else {
                while (!op.empty() && mp[op.top()] >= mp[f[i]]) {
                    int a = num.top();
                    num.pop();

                    int b = num.top();
                    num.pop();

                    char o = op.top();
                    op.pop();

                    int ans = evaluate(a, b, o);
                    num.push(ans);
                }

                op.push(f[i]);
            }
        }
        while (!op.empty()) {
            int a = num.top();
            num.pop();
            int b = num.top();
            num.pop();
            char o = op.top();
            op.pop();
            int ans = evaluate(a, b, o);
            num.push(ans);
        }
        return num.top();
    }
};