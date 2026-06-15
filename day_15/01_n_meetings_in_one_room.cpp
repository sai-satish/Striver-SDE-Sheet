#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<pair<int, int>> meetings(n);
        for (int i = 0; i < n; i++) {
            meetings[i] = {end[i], i + 1};
        }
        sort(meetings.begin(), meetings.end());

        vector<int> ans;
        int lastEndTime = -1;
        for (const auto& meeting : meetings) {
            if (start[meeting.second - 1] > lastEndTime) {
                ans.push_back(meeting.second);
                lastEndTime = meeting.first;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end   = {2, 4, 6, 7, 9, 9};

    Solution sol;
    vector<int> res = sol.maxMeetings(start, end);

    for (int idx : res) cout << idx << " ";
    return 0;
}
