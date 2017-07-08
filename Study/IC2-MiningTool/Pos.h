#pragma once

class Pos
{
private:
	int x;
	int y;

public:
	Pos(void)
	{
		x = y = 0;
	}
	Pos(const int &x, const int &y)
	{
		this->set(x, y);
	}

public:
	void plus(const int x, const int y)
	{
		this->x += x;
		this->y += y;
	}
	void setX(const int &x)
	{
		this->x = x;
	}
	void setY(const int &y)
	{
		this->y = y;
	}
	void set(const int &x, const int &y)
	{
		this->setX(x);
		this->setY(y);
	}
	void get(char *s)
	{
		sprintf(s, "(%d,%d)", this->x, this->y);
	}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
};
