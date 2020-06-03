#include "stdio.h"
#include "string.h"

void split15(FILE *fd1, int puzzles, int start);

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
            split15(fd1, 257, 1);
            break;

        case 2:
            printf("This game not yet supported.\n");
            break;

        default: // default to chunking the entire file into standard 15x15 size (good for extracted data)
            rewind(fd1);
            printf("Could not determine game, assuming extracted level data block.\n");
            split15(fd1, 0, 1);
    }
    fclose(fd1);
}

void split15(FILE *fd1, int puzzles, int start)
{
    char buf[128], filename[12];
    FILE *fd2;
    puzzles+=start;
    for(int i=start; i!=puzzles; i++)
    {
        if(fread(buf, 1, 32, fd1) < 30)
            return;
        sprintf(filename, "splits/%d", i);
        fd2 = fopen(filename,"w" );
        fwrite(buf, 1, 128, fd2);
        fclose(fd2);
        memset(buf, 0, 128);
        memset(filename, 0, 12);
    }
}
