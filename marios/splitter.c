#include "stdio.h"
#include "string.h"

int main(int argc, char *argv[])
{
    char buf[128], filename[5];
    FILE *fd2;
    FILE *fd1 = fopen(argv[1], "r");
    for(int i=1; i<301; i++)
    {
        if(fread(buf, 1, 128, fd1) < 20)
            return 0;
        sprintf(filename, "%d", i);
        fd2 = fopen(filename,"w" );
        fwrite(buf, 1, 128, fd2);
        fclose(fd2);
        memset(buf, 0, 128);
        memset(filename, 0, 5);
    }
}
