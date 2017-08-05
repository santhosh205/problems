# https://www.hackerrank.com/challenges/coin-change
# checkout - http://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/

coins = [1, 2, 3]
n = 5
ways = [0 for k in range(n+1)]
ways[0] = 1
for i in range(0, len(coins)):
    for j in range(coins[i], n+1):
        ways[j] += ways[j-coins[i]]
print(ways[n])