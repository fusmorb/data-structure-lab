#include <stdio.h>

int insertElement(int L[], int n, int x) {
		int i, k = 0, move = 0; 
		for (i = 0; i < n; i++) {
			if (L[i] <= x && x <= L[i + 1]) {
				k = i + 1;
				break;
			}
		}
		if (i == n) k = n; 
		for (i = n; i > k; i--) {
			L[i] = L[i - 1];
			move++;
		}

		L[k] = x;
		return move;
	}
int deleteElement(int L[], int n, int x) {
	int i, k = n, move = 0;
	for (i = 0; i < n; i++) {
		if (L[i] == x) {
			k = i;
			break;
		}
	}
	if (i == n) move = n;
	
	for (i = k; i < n - 1; i++) {
		L[i] = L[i + 1];
		move++;
	}
	return move;
}


int main(void) {
	int list[10] = { 10, 20, 30, 40, 50, 60 };
	int i, move, size = 6;
	printf ( "\n삽입전 선형 리스트 : ");
	for (i = 0; i < size; i++) printf ("%3d ", list[i]);
	printf("\n원소의 갯수 : % d\n", size);
	
	move = insertElement(list, size, 30);
	
	printf("\n삽입후 선형 리스트 : ");
	for(i = 0; i <= size; i++) printf("%3d ", list[i]);
	printf("\n원소의 갯수 : % d ", ++size);
	printf("\n자리 이동 횟수 : % d\n", move);

	move = deleteElement(list, size, 30);
	if (move == size) printf("\n선형 리스트에 원소가 없어서 삭제할수 없습니다.\n");
	else{
		printf("\n삭제후 선형 리스트 : ");
		for(i = 0; i < size- 1; i++) printf("%3d ", list[i]);
		printf("\n원소의 갯수 : % d ", --size);
		printf("\n자리 이동 횟수 : % d\n", move);
	}

	getchar(); return 0;
}
