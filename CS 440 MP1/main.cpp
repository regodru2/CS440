// MP1 - 440 Pathfinding
// Rafael Rego Drumond

#include "master.h"




int main(int argc, char * argv[])
{
    // READ THE FILE--------------------------
    int mazesize;
    FILE * filelab;
    char * mazestring;
    char filename [25];
    printf("Type the name of the file:  ");
    scanf("\n%s", &filename);
    filelab = fopen(filename, "r");

    int charindex=0;
    char c;

    while (!filelab)
    {
        printf("Type the name of the file (correctly):  ");
        scanf("\n%s", &filename);
        filelab = fopen(filename, "r");
    }

    fseek(filelab, 0L, SEEK_END);
    mazesize = ftell(filelab);
    fseek(filelab, 0L, SEEK_SET);

    mazestring =(char*) malloc ((mazesize+1)*sizeof(char));

    c = getc(filelab) ;
    while (c!= EOF)
    {
   		mazestring[charindex]=c;
		c = getc(filelab);
		charindex++;
    }
    mazestring[charindex]='\0';
    fclose(filelab);

    //CREATE THE DUNGEON---------------

    Dungeon * dungeon;
    dungeon = (Dungeon*) malloc (sizeof(Dungeon));
    CreateDungeon(mazestring,mazesize,dungeon);


    printDungeon(dungeon,dungeon->startx,dungeon->starty);



	return 0;
}

