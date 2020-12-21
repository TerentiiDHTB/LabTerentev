#include "Maze.h"
#include "MCell.h"
using namespace std;

const MCell& Maze::cell(int i, int j) const
{
	return *m_field;
}

bool Maze::hasConnection(int i1, int j1, int i2, int j2)
{
	auto idx1 = i1 * n + j1;
	auto idx2 = i2 * n + j2;
	if (idx1 < 0 || idx1 >m * n || idx2 < 0 || idx2 > m * n)
		return false;
	if (abs(idx1 - idx2) == 1)
		return m_field[min(idx1, idx2)].getRight();
	if (abs(idx1 - idx2) == n)
		return m_field[min(idx1, idx2)].getDown();

	return false;
}

bool Maze::makeConnection(int i1, int j1, int i2, int j2)
{
	changeConnection(i1 * n + j1, i2 * n + j2, true);

	return true;
}

bool Maze::removeConnection(int i1, int j1, int i2, int j2)
{
	changeConnection(i1 * n + j1, i2 * n + j2, false);

	return true;
}

void Maze::changeConnection(int idx1, int idx2, bool connectionType)
{
	if (abs(idx1 - idx2) == 1)
		m_field[min(idx1, idx2)].m_right = connectionType;
	if (abs(idx1 - idx2) == n)
		m_field[min(idx1, idx2)].m_down = connectionType;
}

void Maze::printMaze()
{
	for (auto i = 0; i < m; ++i)
	{
		for (auto j = 0; j < n; ++j)
		{
			auto up = hasConnection(i, j, i - 1, j);
			auto down = hasConnection(i, j, i + 1, j);
			auto left = hasConnection(i, j, i, j - 1);
			auto right = hasConnection(i, j, i, j + 1);

			if (left && up && right && down)
				cout << (char)197;
			else if (left && up && right)
				cout << (char)193;
			else if (left && up && down)
				cout << (char)180;
			else if (left && right && down)
				cout << (char)194;
			else if (up && right && down)
				cout << (char)195;
			else if (left && up)
				cout << (char)217;
			else if (up && right)
				cout << (char)192;
			else if (left && down)
				cout << (char)191;
			else if (right && down)
				cout << (char)218;
			else if (up && down)
				cout << (char)179;
			else if (left && right)
				cout << (char)196;
			else
				cout << '0';
		}
		cout << "\n";
	}
}

Maze::~Maze()
{
	delete[] m_field;
}
