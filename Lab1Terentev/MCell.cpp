#include "MCell.h"

bool MCell::getRight()
{
	return m_right;
}

bool MCell::getDown()
{
	return m_down;
}

MCell::MCell()
{
	m_down = false;
	m_right = false;
}
