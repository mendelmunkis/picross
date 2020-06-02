#include "stdio.h"
#include "string.h"

int main(void)
{
    char readbuf[32], writebuf[30][32]={0}, filename1[5], filename2[40];
    FILE *fd2;
    FILE *fd1;
    short int bit=0, compose, l, m, rol;
    for(int i=1; i<300; i++)
    {
        sprintf(filename1, "split/%d", i);
        sprintf(filename2, "out/%03d.picross", i);
        fd1 = fopen(filename1,"r" );
        if(fd1 == NULL)
            return 0;
        fd2 = fopen(filename2,"w" );
        fread(readbuf, 1, 32, fd1);
        for(int j=0; j < (readbuf[31]*2); j+=2)
        {
            m=j/2;
            memcpy(&compose, &readbuf[j], 2);
            for(int k =0; k < readbuf[31];k++)
            {
                if(compose & 128)
                    writebuf[m][k]='*';
                else
                    writebuf[m][k]='.';
                rol = compose & 32768;
                compose<<=1;
                if(rol)
                    compose++;
                l = k;
            }
        }
        fread(readbuf, 1, 32, fd1);
        for(int j=0; j < (readbuf[31]*2); j+=2)
        {
            m=j/2;
            memcpy(&compose, &readbuf[j], 2);
            for(int k =15; k < readbuf[31]*2;k++)
            {
                if(compose & 128)
                    writebuf[m][k]='*';
                else
                    writebuf[m][k]='.';
                rol = compose & 32768;
                compose<<=1;
                if(rol)
                    compose++;
                l = k+1;
            }
            writebuf[m][l]='\n';
        }
        
        fread(readbuf, 1, 32, fd1);
        for(int j=0; j < (readbuf[31]*2); j+=2)
        {
            m=j/2+15;
            memcpy(&compose, &readbuf[j], 2);
            for(int k =15; k < readbuf[31]*2;k++)
            {
                if(compose & 128)
                    writebuf[m][k]='*';
                else
                    writebuf[m][k]='.';
                rol = compose & 32768;
                compose<<=1;
                if(rol)
                    compose++;
                l = k+1;
            }
            writebuf[m][l]='\n';
        }
        fread(readbuf, 1, 32, fd1);
        for(int j=0; j < (readbuf[31]*2); j+=2)
        {
            m=j/2+15;
            memcpy(&compose, &readbuf[j], 2);
            for(int k =0; k < readbuf[31];k++)
            {
                if(compose & 128)
                    writebuf[m][k]='*';
                else
                    writebuf[m][k]='.';
                rol = compose & 32768;
                compose<<=1;
                if(rol)
                    compose++;
                l = k;
            }
        }


        for(int i=0; i<30;i++)
        {
            fputs(writebuf[i], fd2);
        }
        fclose(fd1);
        fclose(fd2);
        memset(filename1, 0, 5);
        memset(filename2, 0, 40);

    }
}
