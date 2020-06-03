#include "stdio.h"
#include "string.h"

char readbuf[32], writebuf[60][61]={0};

void convert  (int line, int col);

int main(void)
{
    char filename1[12], filename2[40];
    FILE *fd2;
    FILE *fd1;
    int lines, size;

    for(int i=1; 1; i++)
    {
        sprintf(filename1, "splits/%d", i);
        sprintf(filename2, "out/%03d.picross", i);
        fd1 = fopen(filename1,"r" );
        if(fd1 == NULL)
            return 0;
        fseek(fd1, 0, SEEK_END);
        if((size=ftell(fd1))%32)
        {
            printf("%s is not a valid nintendo picross puzzle", filename1);
            return 0;
        }
        rewind(fd1);
        lines=0;
        fd2 = fopen(filename2,"w" );
        switch(size/32)
        {
            case 16:
                fread(readbuf, 1, 32, fd1);
                convert(0,0);
                fread(readbuf, 1, 32, fd1);
                convert(0,15);
                fread(readbuf, 1, 32, fd1);
                convert(15,15);
                fread(readbuf, 1, 32, fd1);
                convert(15,0);

                fread(readbuf, 1, 32, fd1);
                convert(0,30);
                fread(readbuf, 1, 32, fd1);
                convert(0,45);
                fread(readbuf, 1, 32, fd1);
                convert(15,45);
                fread(readbuf, 1, 32, fd1);
                convert(15,30);

                fread(readbuf, 1, 32, fd1);
                convert(30,0);
                fread(readbuf, 1, 32, fd1);
                convert(30,15);
                fread(readbuf, 1, 32, fd1);
                convert(45,15);
                fread(readbuf, 1, 32, fd1);
                convert(45,0);

                fread(readbuf, 1, 32, fd1);
                convert(30,30);
                fread(readbuf, 1, 32, fd1);
                convert(30,45);
                fread(readbuf, 1, 32, fd1);
                convert(45,45);
                fread(readbuf, 1, 32, fd1);
                convert(45,30);

                lines=60;
                break;

            case 4:
                fread(readbuf, 1, 32, fd1);
                convert(0,0);
                fread(readbuf, 1, 32, fd1);
                convert(0,15);
                fread(readbuf, 1, 32, fd1);
                convert(15,15);
                fread(readbuf, 1, 32, fd1);
                convert(15,0);
                lines=30;
                break;

            case 1:
                fread(readbuf, 1, 32, fd1);
                convert(0,0);
                lines=readbuf[31];
                break;

            default:
                printf("Error nonstandard grid size (grid nummber %d)\n", i);
        }
        for(int i=0; i<= lines;i++)
        {
            fputs(writebuf[i], fd2);
            fputs("\n", fd2);
        }
        fclose(fd1);
        fclose(fd2);
        memset(filename1, 0, 12);
        memset(filename2, 0, 40);
        memset(writebuf, 0, 3660);

    }
}


void convert  (int line, int col)
{
    short int compose, m, rol;
    for(int j=0; j < (readbuf[31]*2); j+=2)
    {
        m=(j/2)+line;
        memcpy(&compose, &readbuf[j], 2);
        for(int k =col; k < readbuf[31]+col;k++)
        {
            if(compose & 128)
                writebuf[m][k]='*';
            else
                writebuf[m][k]='.';
            rol = compose & 32768;
            compose<<=1;
            if(rol)
                compose++;
        }
    }
}
