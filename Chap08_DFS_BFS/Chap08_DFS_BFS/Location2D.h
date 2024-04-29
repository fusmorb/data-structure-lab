#pragma once

struct  Location2D {
	int row;
	int col;

	//structure 생성자, row와 col 0으로 초기화
	Location2D(int r = 0, int c = 0) {
		row = r;
		col = c;
	}
	//위치 p가 자신의 이웃인지 검사
	bool isNeighbor(Location2D& p) {
		return((row == p.row && (col == p.col - 1 || col == p.col + 1))
			|| (col == p.col && (row == p.row - 1 || row == p.row + 1)));
	}
	// p가 자신과 같은 위치인지를 검사
	bool operator==(Location2D& p) {
		return row == p.row && col == p.col;
	}
};

