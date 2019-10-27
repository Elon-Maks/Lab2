#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void formfile()
{
    FILE *f;
    f=fopen("file.bin","w");
    srand(time(0));
    int n=rand()%10+5;
    for (int i=1;i<=n;i++)
    {
        int k=rand()%10+1;
        for (int j=1;j<=k;j++)
        {
            char c=rand()%26+97;
            fwrite(&c,sizeof(c),1,f);
        }
        char c=10;
        fwrite(&c,sizeof(c),1,f);
    }
    fclose(f);
}

void readfile()
{
    FILE *f;
    f=fopen("file.bin","r");
    char c;
    while (fread(&c,sizeof(c),1,f))
        printf("%c",c);
    fclose(f);
}

void sortfile()
{
   
}

int main()
{
    formfile();
    readfile();
    sortfile();
    printf("\n");
    readfile();
    return 0;
}
