# https://www.hackerrank.com/challenges/a-chessboard-game-1
# checkout - https://www.hackerrank.com/challenges/a-chessboard-game-1/forum/comments/208350
# checkout jawad_cs's comment in discussions
# checkout peterekras's comment in discussions 
# here, the key concept is if a player is surrounded by other's victory then he loses

x = [[]]
def checkAllMoves(x, y):
    if x<1 or y<1 or x>15 or y>15:
        return 1
    if store[x-1][y-1] != -1:
        return store[x-1][y-1]
    if (checkAllMoves(x-2, y+1) and checkAllMoves(x-2, y-1) and checkAllMoves(x+1, y-2) and checkAllMoves(x-1, y-2)):
        store[x-1][y-1] = 0
        return 0
    else:
        store[x-1][y-1] = 1
        return 1
poses = [[5, 2], [5, 3], [8, 8]]
for pos in poses:
    x, y = pos[0], pos[1]
    store = [[-1 for x in range(15)] for y in range(15)]
    outcome = checkAllMoves(x, y)
    if outcome == 1:
        print("First")
    else:
        print("Second")