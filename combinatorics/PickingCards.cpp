/*
There are N cards on the table and each has a number between 0 and N. Let us denote the number on the ith card by ci. You want to pick up all the cards. The ith card can be picked up only if at least ci cards have been picked up before it. (As an example, if a card has a value of 3 on it, you can't pick that card up unless you've already picked up 3 cards previously) In how many ways can all the cards be picked up?

Input Format
The first line contains the number of test cases T. T test cases follow. Each case contains an integer N on the first line, followed by integers c1,..ci,...,cN on the second line.

Output Format
Output T lines one corresponding to each test case containing the required answer for the corresponding test case. As the answers can be very big, output them modulo 1000000007.

Constraints:
1 <= T <= 10
1 <= N <= 50000
0 <= ci <= N

Sample Input:

3
3
0 0 0
3
0 0 1
3
0 3 3
Sample Output:

6
4
0
Sample Explanations:

For the first case, the cards can be picked in any order, so there are 3! = 6 ways.
For the second case, the cards can be picked in 4 ways: {1,2,3}, {2,1,3}, {1,3,2}, {2,3,1}.
For the third case, no cards can be picked up after the first one, so there are 0 ways to pick up all cards.
*/

int solve(vector<int> c) {
    //sort(c.begin(), c.end());
    int size = c.size();
    int* dp = new int[size];
    map<int, int> mp;
    for(int i = 0; i < c.size(); i++){
        mp[c[i]]++;
    }
    dp[0] = mp[0];
    for(int i = 1; i< size; i++){
        dp[i] = dp[i-1] - 1 + mp[i] ;
    }
    long result = 1;
    int mod = 1000000000+7;
    for(int i = 0; i < size; i++){
        result = ((result % mod) * (dp[i] % mod)) % mod;
    }
    return result;
}
