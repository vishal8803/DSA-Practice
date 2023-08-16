class Solution {
    public String reorderSpaces(String text) {
        int words = 0;
        int spaces = 0;
        ArrayList<String> list = new ArrayList<>();
        
        int i = 0;
        while(i < text.length()) {
            if(text.charAt(i) == ' ') {spaces++; i++;}
            else {
                String temp = "";
                while(i < text.length() && text.charAt(i) != ' ') {
                    temp += text.charAt(i);
                    i++;
                }
                list.add(temp);
                words++;
            }
        }
        int put = 0;
        int extra = 0;
        if(words > 1) {
            put = spaces/(words - 1);
        }
        
        extra = spaces - put*(words - 1);
        
        String ans = list.get(0);
        for(i = 1; i < list.size(); i++) {
            int r = put;
            while(r > 0) {
                ans += " ";
                r--;
            }
            ans += list.get(i);
        }
        
        while(extra > 0) {
            ans += " ";
            extra--;
        }
        return ans;
    }
}