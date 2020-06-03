/* splitter.c (c) 2020 Moshe Piekarski     *
* tool to split level data from Nintendo   *
* picross games into individual puzzles    */


#include "stdio.h"
#include "string.h"

void split(FILE *fd1, int puzzles, int start, int grids);

int main(int argc, char *argv[])
{
    FILE *fd1 = fopen(argv[1], "r");
    char game[17];
    int style =0;
    fseek(fd1, 0x134, SEEK_SET);
    if(fread(game, 1, 16, fd1) < 16)
    {
        printf("Error reading game header.\n");
        style=-1;
    }
    if(strcmp(game, "MARIO'S PICROSS")==0)
        style=1;
    if(strcmp(game, "PICROSS 2")==0)
        style=2;
    switch(style) //how to split up the game
    {
        case 1:
            fseek(fd1,0x92b0,SEEK_SET);
            split(fd1, 257, 1, 1);
            break;

        case 2:
            fseek(fd1,0x1fb88,SEEK_SET);
            split(fd1, 10, 1, 1);
            fseek(fd1,0x1c000,SEEK_SET);
            split(fd1, 100, 11, 4);
            split(fd1, 1, 111, 16);
            fseek(fd1,0x54000,SEEK_SET);
            split(fd1, 100, 112, 4);
            split(fd1, 1, 212, 16);
            /*Can't find the quick picross puzzles*/
            break;

        default: // chunk the whole file to 15x15 (good for extracted data)
            rewind(fd1);
            printf("Could not determine game, "
                         "assuming extracted level data block.\n");
            split(fd1, -1, 1,1);
    }
    fclose(fd1);
}

void split(FILE *fd1, int puzzles, int start, int grids)
{
    char buf[grids*32], filename[12];
    FILE *fd2;
    puzzles+=start;
    for(int i=start; i!=puzzles; i++)
    {
        if(fread(buf, 32, grids, fd1) < 1)
            return;
        sprintf(filename, "splits/%d", i);
        fd2 = fopen(filename,"w" );
        fwrite(buf, 32, grids, fd2);
        fclose(fd2);
        memset(buf, 0, grids*32);
        memset(filename, 0, 12);
    }
}
