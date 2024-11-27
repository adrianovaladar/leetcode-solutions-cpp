/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int begin {1};
        int end {n};
        int middle;
        while(1) {
            middle = begin + (end - begin) / 2;
            int attempt = guess(middle);
            if (attempt > 0) {
                begin = middle + 1;
                continue;
            }
            else if (attempt < 0) {
                end = middle - 1;
                continue;
            }
            return middle;
        }
        return 0;
    }
};
