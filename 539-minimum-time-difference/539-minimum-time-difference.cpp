class Solution {
public:
    int getTimeDifferenceBetweenTwo(string time1, string time2){
        int hour1, hour2, minute1, minute2;
        
        hour1 = (time1[0]-'0')*10 + (time1[1]-'0');
        hour2 = (time2[0]-'0')*10 + (time2[1]-'0');
        minute1 = (time1[3]-'0')*10 + (time1[4]-'0');
        minute2 = (time2[3]-'0')*10 + (time2[4]-'0');
        
        
        if(hour1==hour2 && minute1==minute2) return 0;
        
        if(hour1==hour2) return abs(minute1-minute2);
        
        int diff1 , diff2;
        
        if(hour1 > hour2){
            if(minute1 >= minute2){
                diff1 = (hour1-hour2)*60 + minute1-minute2;
            }else{
                diff1 = (hour1-hour2-1)*60 + minute1 + 60 - minute2;
            }
        }else{
            if(minute2 >= minute1){
                diff1 = (hour2-hour1)*60 + minute2-minute1;
            }else{
                diff1 = (hour2-hour1-1)*60 + minute2 + 60 - minute1;
            }
        }
        
        if(hour1 > hour2){
            diff2 = hour2*60 + minute2 + (23-hour1)*60 + (60-minute1);
        }else{
            diff2 = hour1*60 + minute1 + (23-hour2)*60 + (60-minute2);
        }
        
        return min(diff1,diff2);
    }
    
    int findMinDifference(vector<string>& timePoints) {
        int minTimeDiff = INT_MAX;
        
        int totalTimePoints = timePoints.size();
        sort(timePoints.begin(),timePoints.end());
        
        for(int i = 0; i < totalTimePoints - 1; i++){
            
            int timeDiff = getTimeDifferenceBetweenTwo(timePoints[i], timePoints[i+1]);
            if(minTimeDiff > timeDiff){
                minTimeDiff = timeDiff;
            }
        }
        minTimeDiff = min(minTimeDiff, getTimeDifferenceBetweenTwo(timePoints[0],timePoints[totalTimePoints-1]));
        
        return minTimeDiff;
    }
};