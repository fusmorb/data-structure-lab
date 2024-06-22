input = [[4, 3, 2, 1],
         [0, 0, 0, 0],
         [0, 0, 9, 0],
         [1, 2, 3, 4]]
N = 4

forest = []

def problem3(input):
    bear_size = 2
    honeycomb_count = 0
    time = 0
    bear_x, bear_y = 0, 0

    forest = [row[:] for row in input]
    
    for i in range(N):
        for j in range(N):
            if forest[i][j] == 9:
                bear_x, bear_y = i, j
                forest[i][j] = 0

    result = 0  

    while True:
        prey = bfs((bear_x, bear_y), bear_size, forest)
        if not prey:
            break
        dist, prey_x, prey_y = prey
        time += dist
        bear_x, bear_y = prey_x, prey_y
        forest[prey_x][prey_y] = 0
        honeycomb_count += 1
        if honeycomb_count == bear_size:
            bear_size += 1
            honeycomb_count = 0

    result = time  
    return result

from collections import deque

def bfs(start, size, forest):
    N = len(forest)
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    queue = deque([start])
    visited = [[False] * N for _ in range(N)]
    visited[start[0]][start[1]] = True
    distance = [[0] * N for _ in range(N)]
    possible_prey = []

    while queue:
        x, y = queue.popleft()
        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if 0 <= nx < N and 0 <= ny < N and not visited[nx][ny]:
                if forest[nx][ny] <= size:
                    queue.append((nx, ny))
                    visited[nx][ny] = True
                    distance[nx][ny] = distance[x][y] + 1
                    if 0 < forest[nx][ny] < size:
                        possible_prey.append((distance[nx][ny], nx, ny))
    
    if possible_prey:
        possible_prey.sort()
        return possible_prey[0]
    return None

result = problem3(input)

assert result == 14
print("정답입니다.")
