#include "stdio.h"
#include "string.h"

int main(void)
{
    char readbuf[32], writebuf[60][62]={0};
    FILE *fd2;
    FILE *fd1;
    short int bit=0, compose, l, m, rol;

    fd1 = fopen("finale.ext","r" );
    if(fd1 == NULL)
        return 0;
    fd2 = fopen("finale.picross","w" );

     /* 1st 1/16 */ 
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
        }
    }

     /* 2nd 1/16 */
    fread(readbuf, 1, 32, fd1);
    for(int j=0; j < (readbuf[31]*2); j+=2)
    {
        m=j/2;
        memcpy(&compose, &readbuf[j], 2);
        for(int k =15; k < 30;k++)
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

     /* 3rd 1/16 */
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
        }
    }

     /* 4th 1/16 */
    fread(readbuf, 1, 32, fd1);
    for(int j=0; j < (readbuf[31]*2); j+=2)
    {
        m=j/2+15;
        memcpy(&compose, &readbuf[j], 2);
        for(int k =15; k < 30;k++)
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

     /* 5th 1/16 */
    fread(readbuf, 1, 32, fd1);
    for(int j=0; j < (readbuf[31]*2); j+=2)
    {
        m=j/2;
        memcpy(&compose, &readbuf[j], 2);
        for(int k =30; k < 45;k++)
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

     /* 6th 1/16 */
    fread(readbuf, 1, 32, fd1);
    for(int j=0; j < (readbuf[31]*2); j+=2)
    {
        m=j/2;
        memcpy(&compose, &readbuf[j], 2);
        for(int k =45; k < 60;k++)
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

     /* 7th 1/16 */
    fread(readbuf, 1, 32, fd1);
    for(int j=0; j < (readbuf[31]*2); j+=2)
    {
        m=j/2+15;
        memcpy(&compose, &readbuf[j], 2);
        for(int k =30; k < 45;k++)
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

     /* 8th 1/16 */
    fread(readbuf, 1, 32, fd1);
    for(int j=0; j < (readbuf[31]*2); j+=2)
    {
        m=j/2+15;
        memcpy(&compose, &readbuf[j], 2);
        for(int k =45; k < 60;k++)
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

     /* 9th 1/16 */
    fread(readbuf, 1, 32, fd1);
    for(int j=0; j < (readbuf[31]*2); j+=2)
    {
        m=j/2+30;
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
        }
    }

     /* 10th 1/16 */
    fread(readbuf, 1, 32, fd1);
    for(int j=0; j < (readbuf[31]*2); j+=2)
    {
        m=j/2+30;
        memcpy(&compose, &readbuf[j], 2);
        for(int k =15; k < 30;k++)
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

     /* 11th 1/16 */
    fread(readbuf, 1, 32, fd1);
    for(int j=0; j < (readbuf[31]*2); j+=2)
    {
        m=j/2+45;
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
        }
    }

     /* 12th 1/16 */
    fread(readbuf, 1, 32, fd1);
    for(int j=0; j < (readbuf[31]*2); j+=2)
    {
        m=j/2+45;
        memcpy(&compose, &readbuf[j], 2);
        for(int k =15; k < 30;k++)
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

     /* 13th 1/16 */
    fread(readbuf, 1, 32, fd1);
    for(int j=0; j < (readbuf[31]*2); j+=2)
    {
        m=j/2+30;
        memcpy(&compose, &readbuf[j], 2);
        for(int k =30; k < 45;k++)
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

     /* 14th 1/16 */
    fread(readbuf, 1, 32, fd1);
    for(int j=0; j < (readbuf[31]*2); j+=2)
    {
        m=j/2+30;
        memcpy(&compose, &readbuf[j], 2);
        for(int k =45; k < 60;k++)
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

     /* 15th 1/16 */
    fread(readbuf, 1, 32, fd1);
    for(int j=0; j < (readbuf[31]*2); j+=2)
    {
        m=j/2+45;
        memcpy(&compose, &readbuf[j], 2);
        for(int k =30; k < 45;k++)
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

     /* 16th 1/16 */
    fread(readbuf, 1, 32, fd1);
    for(int j=0; j < (readbuf[31]*2); j+=2)
    {
        m=j/2+45;
        memcpy(&compose, &readbuf[j], 2);
        for(int k =45; k < 60;k++)
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

    for(int i=0; i<60;i++)
    {
         fputs(writebuf[i], fd2);
    }
    fclose(fd1);
    fclose(fd2);
}
