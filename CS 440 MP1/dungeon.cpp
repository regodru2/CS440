// MP1 - CS440 Pathfinding
// Rafael Rego Drumond

#include "master.h"

//These functions are only for using, coding and transforming the dungeon into data for the algorithms, none of this code matters for the purposes of the MP


void  CreateDungeon	(char* map, int tiles, Dungeon * dung)
{
    Dungeon * dungeon = dung;
	dungeon->sizex	 = 0;
	dungeon->sizey	 = 0;
	dungeon->numGoals = 0;
	dungeon->startx   =-1;
	dungeon->starty   =-1;
	int x			 =-1;
	int y			 = 0;
	int counter		 = 0;
	int counter2	 = 0;
	int linecount    = 1;
    dungeon->map      = map;
	int z = -1;
	while (counter < tiles)
	{
		if (map[counter]=='\n' || map[counter]=='/0')
		{
		    if (map[counter]=='\n') linecount++;
			if ((z!=-1) && (z!=counter2))
			{
				printf("INCONSISTENT DUNGEON! PLEASE MAKE SURE THAT EVERY LINE HAS THE SAME AMOUNT OF CHARACTERS!\n");
				exit (-1);
			}else
			{
				z = counter2;
				counter++;
				counter2=0;
			}

		}
        if (map[counter]=='.')
		{
			dungeon->numGoals++;
		}


		counter++;
		counter2++;
	}

    dungeon->goalx = (int*) malloc ((sizeof(int)) * dungeon->numGoals);
    dungeon->goaly = (int*) malloc ((sizeof(int)) * dungeon->numGoals);


	dungeon->sizex = z;
	dungeon->sizey = linecount;


    printf("\nCREATING THE MAZE...");


	for (int i=0;i<tiles;i++)
	{


	    x++;
		if (map[i]=='\n')
		{
			y++;
			x=-1;
		}
		if (map[i]=='.')
		{
			dungeon->goalx[dungeon->numGoals-1]=x;
			dungeon->goaly[dungeon->numGoals-1]=y-1;



		}
		if (map[i]=='P')
		{
			if ((dungeon->startx != -1) && (dungeon->starty != -1))
			{
				printf("ERROR! TWO STARTING POINTS ON THE DUNGEON FILE");
				exit (-1);
			}
			dungeon->startx = x;
			dungeon->starty = y-1;
		}

	}
    printf("\nMAZE COMPLETE\n\n");


}

int lineDun (int x, int y, Dungeon * dungeon)
{
    return (y*(dungeon->sizex+1)+x);
}


void  printDungeon		(Dungeon * dungeon, int posx, int posy)
{
    char c;
	for (int i = 0; i<dungeon->sizey;i++)
	{

		for (int j = 0; j<dungeon->sizex; j++)
		{
			printf("%c", dungeon->map[i*(dungeon->sizex+1)+j]);
		}
		printf("\n");
	}
}

int    move				(Dungeon * dungeon, int posx, int posy, int direction)
{
	switch (direction)
	{
		case UP   :
			if (posy == 0) return 0;
			if (dungeon->map[lineDun(posx,posy-1,dungeon)] == WALL)  return 0;
			return 1;
			break;

		case DOWN :
			if (posy == dungeon->sizey-1) return 0;
			if (dungeon->map[lineDun(posx,posy+1,dungeon)] == WALL)  return 0;
			return 1;
			break;

		case LEFT :
			if (posx == 0) return 0;
			if (dungeon->map[lineDun(posx-1,posy,dungeon)] == WALL)  return 0;
			return 1;
			break;

		case RIGHT:
			if (posx == dungeon->sizex) return 0;
			if (dungeon->map[lineDun(posx+1,posy,dungeon)] == WALL)  return 0;
			return 1;
			break;
	}

}
