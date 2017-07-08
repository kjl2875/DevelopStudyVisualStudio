#pragma once


/*
	MineCraft Industrial Craft 2 - Miner machine management tool
*/

#include "Pos.h"
#include "node.h"
#include <stdio.h>
#include <string.h>

using namespace std;

class MiningTool
{
private:
	int drillRange; // �ݰ氪
	Pos cursor;
	char fpath[1024];
	struct NODE *drillAreaList;
public:
	MiningTool(void)
	{
		drillRange = 0;
		drillAreaList = NULL;
	}
	~MiningTool(void)
	{
		if (drillAreaList != NULL)
		{
			delNodeList(drillAreaList);
		}
	}

public:
	int fileSave(void)
	{
		struct NODE *iter = drillAreaList;
		FILE *fp = fopen(this->fpath, "wt");

		if (fp == NULL)
		{
			return 1;
		}

		fprintf(fp, "%d %d %d\n", cursor.getX(), cursor.getY(), drillRange);

		while (iter != NULL)
		{
			fprintf(fp, "%d %d %d\n", iter->x, iter->y, iter->range);
			iter = iter->backNode;
		}

		fclose(fp);

		return 0;
	}
	int fileOpen(void)
	{
		FILE *fp = fopen(this->fpath, "rt");
		int x, y, r;
		struct NODE *n;
		
		if (fp == NULL)
		{
			return 1;
		}

		fscanf(fp, "%d %d %d", &x, &y, &r);
		cursor.set(x, y);
		drillRange = r;

		if (drillAreaList != NULL)
		{
			delNodeList(drillAreaList);
		}
		
		while (!feof(fp))
		{
			fscanf(fp, "%d %d %d", &x, &y, &r);
			n = createNode(x, y, r);

			(drillAreaList != NULL) ? insertNodeBack(drillAreaList, n) : (drillAreaList = n);
		}

		fclose(fp);

		return 0;
	}
	void setFilepath(const char *fpath)
	{
		strcpy(this->fpath, fpath);
	}

	void addDrillArea(void)
	{
		struct NODE *e = createNode(cursor.getX(), cursor.getY(), drillRange);

		if (drillAreaList == NULL)
		{
			drillAreaList = e;
		}
		else
		{
			insertNodeBack(drillAreaList, e);
		}
	}
	bool delDrillArea(void)
	{
		if (drillAreaList == NULL)
		{
			return false;
		}

		struct NODE *i = drillAreaList;

		while (i != NULL)
		{
			if ((i->x == cursor.getX()) && (i->y == cursor.getY()))
			{
				if (i != drillAreaList)
				{
					delNode(i);
				}
				else
				{
					delNode(i);
					drillAreaList = NULL;
				}
				return true;
			}
		}

		return false;
	}
	bool drillAreaClearCheck(void)
	{
		if (drillAreaList == NULL)
		{
			return true;
		}

		struct NODE *i = drillAreaList;
		bool flagX, flagY;
		
		do
		{
			// check x

			flagX = false;

			if (i->x < cursor.getX())
			{
				//printf("%d >= %d\n",(i->x + i->range), (cursor.getX() - drillRange));
				if ((i->x + i->range) >= (cursor.getX() - drillRange))
				{
					flagX = true;
				}
			}
			else
			{
				if ((i->x - i->range) <= (cursor.getX() + drillRange))
				{
					flagX = true;
				}
			}

			// check y

			flagY = false;

			if (i->y < cursor.getY())
			{
				if ((i->y + i->range) >= (cursor.getY() - drillRange))
				{
					flagY = true;
				}
			}
			else
			{
				//printf("%d <= %d\n", (i->y - i->range), (cursor.getY() + drillRange));
				if ((i->y - i->range) <= (cursor.getY() + drillRange))
				{
					flagY = true;
				}
			}

			// check & next

			if( flagX && flagY )
			{
				return false;
			}
			
			i = i->backNode;
		} while (i != NULL);

		return true;
	}
	void setDrillRange(int &range)
	{
		this->drillRange = range;
	}
	void set(int &x, int &y)
	{
		cursor.set(x, y);
	}
	void getCursor(char *s)
	{
		cursor.get(s);
	}
	void move(int flag)
	{
		switch (flag) // up,down,left,right = 224 -> 72 80 75 77
		{
		case 72: // UP
			cursor.plus(0, -1);
			break;
		case 80: // DOWN
			cursor.plus(0, 1);
			break;
		case 75: // LEFT
			cursor.plus(-1, 0);
			break;
		case 77: // RIGHT
			cursor.plus(1, 0);
			break;
		}
	}
};



