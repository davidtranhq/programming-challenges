class Solution {
public:
    string toHex(int num) {
        if (num == 0)
            return "0";
        array<char, 16> chars = {
            '0', '1', '2', '3',
            '4', '5', '6', '7',
            '8', '9', 'a', 'b',
            'c', 'd', 'e', 'f'
        };
        unsigned x = static_cast<unsigned>(num);
        string s;
        while (x > 0) {
            s += chars[x & 0xf];
            x >>= 4;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};