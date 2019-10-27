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
    
}

void sortfile()
{
    FILE *f;
    f=fopen("file.bin","r+");
    char c,cmin,buff;
    int l=0,r=-1,imin;
    while (fread(&c,sizeof(c),1,f))
    {
        if (c==10)
        {
            l=r+1;
            r=ftell(f)-sizeof(c);
            for (int i=l;i<r-1;i++)
            {
                fseek(f,i*sizeof(c),SEEK_SET);
                fread(&cmin,sizeof(c),1,f);
                imin=i;
                for (int j=i+1;j<r-1;j++)
                {
                    fread(&buff,sizeof(c),1,f);
                    if (buff<cmin)
                    {
                        cmin=buff;
                        imin=j;
                    }
                }
                fseek(f,i*sizeof(c),SEEK_SET);
                fread(&buff,sizeof(c),1,f);
                fseek(f,i*sizeof(c),SEEK_SET);
                fwrite(&cmin,sizeof(c),1,f);
                fseek(f,imin*sizeof(c),SEEK_SET);
                fwrite(&buff,sizeof(c),1,f);
            }
            fseek(f,r*sizeof(c)+1,SEEK_SET);
        }
    }
    fclose(f);
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
