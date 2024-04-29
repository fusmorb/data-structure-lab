#include "Location2D.h"
#include <queue>

using namespace std;

#define MAZE_SIZE 6

char map[MAZE_SIZE][MAZE_SIZE] = {
    {'1', '1', '1', '1', '1', '1'},
    {'e', '0', '1', '0', '0', '1'},
    {'1', '0', '0', '0', '1', '1'},
    {'1', '0', '1', '0', '1', '1'},
    {'1', '0', '1', '0', '0', 'x'},
    {'1', '1', '1', '1', '1', '1'},
};

bool isValidLoc(int r, int c)
{
    if (r < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE)
        return false;
    else
        return map[r][c] == '0' || map[r][c] == 'x';
}

int main()
{
    deque<Location2D> locdeque;
    Location2D entry(1, 0);
    locdeque.push_front(entry);

    while (locdeque.empty() == false) {
        Location2D here = locdeque.front();
        locdeque.pop_front();

        int r = here.row;
        int c = here.col;

        printf("현재 위치 = (%d,%d) ", r, c);
        if (map[r][c] == 'x') {
            printf(" 출구 도착 \n");
            return true;
        }
        else {
            map[r][c] = '.';
            if (isValidLoc(r - 1, c)) locdeque.push_front(Location2D(r - 1, c));
            if (isValidLoc(r + 1, c)) locdeque.push_front(Location2D(r + 1, c));
            if (isValidLoc(r, c - 1)) locdeque.push_front(Location2D(r, c - 1));
            if (isValidLoc(r, c + 1)) locdeque.push_front(Location2D(r, c + 1));
        }
    }
    printf("미로 탐색 종료\n");
}