#pragma once
#include <iostream>
class MCell
{
	bool m_down;
	bool m_right;
	MCell();
public:
	bool getRight();
	bool getDown();

	friend class Maze;
};

