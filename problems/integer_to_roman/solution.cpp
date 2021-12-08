/* scratch:

general: let 'u' be the character for the one (I, X, C), 'f' for five (V, L, D), 't' for ten (X, C, M)

pattern: u, uu, uuu, uf, f, fu, fuu, fuuu, ut, t

generate string one place value at a time, starting with the largest (thousands, hundreds, tens, ones)

thous = num / 1000 % 10
hunds = num / 100 % 10
tens = num / 10 % 10
ones = num % 10



*/

class Solution {
    
public:
    string dig(int num, char u, char f, char t) {
        vector<string> pat {
            string(),
            {u},
            {u, u},
            {u, u, u},
            {u, f},
            {f},
            {f, u},
            {f, u, u},
            {f, u, u, u},
            {u, t},
            {t},
        };
        return pat[num];
    }
    
    string intToRoman(int num) {
        int thous = num / 1000 % 10;
        int hunds = num / 100 % 10;
        int tens = num / 10 % 10;
        int ones = num % 10;
        return dig(thous, 'M', 'M', 'M')
            + dig(hunds, 'C', 'D', 'M')
            + dig(tens, 'X', 'L', 'C')
            + dig(ones, 'I', 'V', 'X');
    }
};