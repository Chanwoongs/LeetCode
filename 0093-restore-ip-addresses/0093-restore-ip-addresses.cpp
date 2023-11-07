class Solution {
public:
    bool isValid(const string& ip) {
        // 0으로 시작하는 세그먼트는 유효하지 않음
        if (ip.size() > 1 && ip[0] == '0') {
            return false;
        }
        // 0부터 255 사이의 값인지 확인
        int num = stoi(ip);
        return num >= 0 && num <= 255;
    }

    void go(string temp, int idx, int segments, string s, vector<string>& res) {
        if (segments == 4) {
            // 4개의 세그먼트가 만들어진 경우 추가
            if (idx == s.size()) {
                res.emplace_back(temp);
            }
            return;
        }

        for (int i = 1; i <= 3; i++) {
            if (idx + i > s.size()) {
                break;  // 문자열 길이를 벗어나면 중단
            }
            string ip = s.substr(idx, i);
            if (isValid(ip)) {
                string separator = (segments == 3) ? "" : ".";
                go(temp + ip + separator, idx + i, segments + 1, s, res);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        // 입력 문자열의 길이가 4에서 12 사이인 경우에만 처리
        if (s.size() >= 4 && s.size() <= 12) {
            go("", 0, 0, s, res);
        }
        return res;
    }
};