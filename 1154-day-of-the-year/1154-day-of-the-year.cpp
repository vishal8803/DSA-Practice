class Solution {
public:
    bool isLeap(int y) {
        return ((y % 400 == 0) || ((y % 100 != 0) && (y % 4 == 0)));
    }
    
    int dayOfYear(string date) {
        int year = stoi(date.substr(0, 4));
        int month = (date[5]-'0')*10 + (date[6] - '0');
        month--;
        int day = (date[8] - '0')*10 + (date[9] - '0');
        vector<int> months = {31};
        if(isLeap(year)) {
            months.push_back(29);
        } else {
            months.push_back(28);
        }
        
        months.push_back(31);
        months.push_back(30);
        months.push_back(31);
        months.push_back(30);
        months.push_back(31);
        months.push_back(31);
        months.push_back(30);
        months.push_back(31);
        months.push_back(30);
        months.push_back(31);
        
        int cnt = 0;
        for(int i = 0; i < month; i++) {
            cnt += months[i];
        }
        cnt += day;
        return cnt;
    }
};