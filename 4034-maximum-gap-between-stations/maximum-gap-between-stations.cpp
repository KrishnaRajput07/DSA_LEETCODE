class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size();
        int m = station.size();
        if(n==1) return 0;

        vector<int> left(n);
        vector<int> right(n);
        int j=0;
        for(int i=0; i<n; i++){
            while (station[j] != skill[i]) {
                j++;
            }
            left[i] = j;//first occurence
            j++;
        }

        j=m-1;
        for(int i=n-1; i>=0; i--){
            while (station[j] != skill[i]) {
                j--;
            }
            right[i] = j;//last occurence
            j--;
        }

        vector<int> ans;
        for(int i=1; i<n; i++){
            int index=right[i]-left[i-1]; //always right>left as consecutive distribution
            ans.push_back(index);
        }
        return *max_element(ans.begin(), ans.end());
    }
};