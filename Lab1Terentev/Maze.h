#pragma once
#include "MCell.h"
#include "algorithm"
#include <iostream>
using namespace std;
class Maze
{
	MCell* m_field;
	int n;
	int m;
public:
	const MCell& cell(int i, int j)const;
	bool hasConnection(int i1, int j1, int i2, int j2);
	bool makeConnection(int i1, int j1, int i2, int j2);
	bool removeConnection(int i1, int j1, int i2, int j2);
	void changeConnection(int idx1, int idx2, bool connectionType);
	void printMaze();
	
	Maze(int i, int j)
	{
		m_field = new MCell[i * j];
		n = i;
		m = j;
	}
	~Maze();
};

