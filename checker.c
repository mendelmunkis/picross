#include <stdio.h>

int main (int argc, char * argv[])
{
    int x=0, fixed=0;;
    char a,b;
    FILE * fp1, *fp2;
    // file 1 = solution, file 2 = save;
    if((fp1 = fopen (argv[1], "r"))==NULL)
        printf("error opening file\n");
    if((fp2 = fopen (argv[2], "r+"))==NULL)
        printf("error opening file\n");
    while((a=fgetc(fp2)) != '\n');
    while((a=fgetc(fp1)) != EOF)
    {
        x++;
        if((b=fgetc(fp2))!='.')
//            if(a!=b)
            if(((b=='*') &&(a!='*')) ||((b=='x') &&(a!='.')))
            {
                fseek(fp2, -1, SEEK_CUR);
                fputc('.', fp2);
                fixed++;
            }
    }
    printf("Cleared cells: %d\n", fixed);
}
