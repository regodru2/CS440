// MP1 - CS440 Pathfinding
// Rafael Rego Drumond

typedef struct dung{

	int		sizex;
	int		sizey;
	int		startx;
	int		starty;
	int		numGoals;
	int *	goalx;
	int *	goaly;
	char *	map;

}Dungeon;


int    lineDun          (int x, int y, void * dungeon);
void   CreateDungeon	(char* map, int tiles, Dungeon * dungeon);
void   printDungeon		(Dungeon * dungeon, int posx, int posy);
int    move				(Dungeon * dungeon, int posx, int posy, int direction);
