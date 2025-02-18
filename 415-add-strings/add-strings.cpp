class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string final = ""; 

        while (i >= 0 || j >= 0 || carry) {  
            int last1 = (i >= 0) ? num1[i] - '0' : 0; 
            int last2 = (j >= 0) ? num2[j] - '0' : 0;
            int s = last1 + last2 + carry;
            
            final += (s % 10) + '0';  
            carry = s / 10;          
            
            i--;
            j--;
        }

        reverse(final.begin(), final.end());  
        return final;
    }
};
