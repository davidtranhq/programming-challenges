/* scratch:

[0, 1, 3, 6, 6, 8, 10, 12]
 8  7  6  5  4  3  2   1
 
citations[i] = x:
    (n - i) papers have >= x citations

for i = n - 1 to 0:
    if (n - i) >= citations[i]:
        return n - i
return n
        


[x_0, x_1, ..., x_n]
   n  n-1         1
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int start = 0, end = n - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            int x = citations[mid];
            if (x == n - mid) {
                return x;
            }
            else if (x > n - mid) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return n - (end + 1);
    }
};