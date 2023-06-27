#include<stdlib.h>
#include "main.h"
#include <string.h>

char *numtobi(int num)
{  
int n, i, x, c, p;
char *bi, *rev;

p = num;
num = num < 0 ? num * -1 : num;
c = num;
n = 0;

for(x=0;c>0;x++)    
{        
c = c / 2;    
} 

bi = malloc(sizeof(char) * (x+1));
rev = malloc(sizeof(char) * (x+1));

for(i = 0; num > 0;i++)    
{    
rev[i] = (num % 2) + '0';    
num = num / 2;
}
for(i = i - 1;i >= 0; i--)    
{    
bi[n] = rev[i]; 
n++;   
}  
free(rev); 
bi[x + 1] = '\0';
if (p < 0)
        {
                char *bi2;

                bi2 = malloc(sizeof(char) * (x + 2));
                bi2[0] = '-';
                strcat(bi2, bi);
                free(bi);
                return (bi2);
        }
        else
        {
                return (bi);
        }
}

