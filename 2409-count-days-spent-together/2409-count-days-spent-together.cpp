class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int sda = (arriveAlice[3]-'0')*10 + (arriveAlice[4]-'0');
        int sma = (arriveAlice[0]-'0')*10 + (arriveAlice[1]-'0');
        
        int eda = (leaveAlice[3]-'0')*10 + (leaveAlice[4]-'0');
        int ema = (leaveAlice[0]-'0')*10 + (leaveAlice[1]-'0');
        
        int sdb = (arriveBob[3]-'0')*10 + (arriveBob[4]-'0');
        int smb = (arriveBob[0]-'0')*10 + (arriveBob[1]-'0');
        
        int edb = (leaveBob[3]-'0')*10 + (leaveBob[4]-'0');
        int emb = (leaveBob[0]-'0')*10 + (leaveBob[1]-'0');
        
        if(ema < smb || emb < sma) return 0;
        
        // cout<<sma<<" "<<emb<<endl;
        // cout<<edb<<" "<<eda<<endl;
        if(sma == emb && edb < sda) return 0;
        if(ema == smb && eda < sdb) return 0;
        
        vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        int f1;
        int f2;
        
        int m1;
        int m2;
        if(smb > sma){
            f1 = smb;
            f2 = sdb;
        } else if(smb==sma) {
            f1 = smb;
            if(sdb > sda) {
                f2 = sdb;
            } else {
                f2 =sda;
            }
        } else if(sma > smb) {
            f1 = sma;
            f2 = sda;
        }
        
        if(ema < emb) {
            m1 = ema;
            m2 = eda;
        } else if(ema == emb) {
            m1 = ema;
            if(eda < edb) {
                m2 = eda;
            } else {
                m2 = edb;
            }
        } else if(emb < ema) {
            m1 = emb;
            m2 = edb;
        }
        // cout<<f1<<" "<<f2<<endl;
        // cout<<m1<<" "<<m2<<endl;
        if(f1==m1) {
            
            return abs(m2-f2) + 1;
        } else {
            int count = 0;
            if(f1 > m1) {
                if(m1==2) {
                    count += 28 - m2;
                    count += f2;
                    for(int i = m1 + 1; i < f1; i++) {
                        count += months[i-1];
                    }
                } else {
                    count += months[m1-1] - m2 + 1;
                    count += f2;
                    for(int i = m1 + 1; i < f1; i++) {
                        count += months[i-1];
                    }
                }
            } else {
                if(f1==2) {
                    count += 28 - f2 + 1;
                    count += m2;
                    for(int i = f1 + 1; i < m1; i++) {
                        count += months[i-1];
                    }
                } else {
                    count += months[f1-1] - f2 +  1;
                    count += m2;
                    for(int i = f1 + 1; i < m1; i++) {
                        count += months[i-1];
                    }
                }
            }
            return count;
        }
    }
};