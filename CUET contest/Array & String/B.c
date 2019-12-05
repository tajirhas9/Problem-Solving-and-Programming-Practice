#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char c[80];
    float n[80][2],x,mass=0;
    int i,t,j=1,l;
    for(i = 0; i < 80; i++)
    {
        c[i] = '?';
    }
    scanf("%d",&t);
    getchar();
    while(j <= t)
    {
        scanf("%s",c);
        l = strlen(c);
        if(l > 0 && l < 80 )
        {
            for(i = 0; i < l; i++)
            {
                /*if(c[0] != 'C' && c[0] != 'H' && c[0] != 'O' && c[0] != 'N')
                {
                    return 0;
                }*/
                if(c[i] == 'C' || c[i] == 'H' || c[i] == 'O' || c[i] == 'N' || (c[i] >= '0' && c[i] <= '9'))
                {
                    if(c[i] == 'C')
                    {
                        if((c[i+1] >= '0' && c[i+1] <= '9') && ((c[i+2] >= '0' && c[i+2] <= '9')))
                        {
                            n[i][0] = 12.01;
                            n[i][1] = 10*(c[i+1] - '0');
                            n[i][2] = c[i+2] - '0';
                            if((n[i][1]+n[i][2]) < 2 || (n[i][1]+n[i][2]) > 99)
                            {
                                return 0;
                            }
                            mass += n[i][0]*(n[i][1]+n[i][2]);
                            i += 2;
                        }
                        else if((c[i+1] >= '2' && c[i+1] <= '9') && ((c[i+2] < '0' || c[i+2] > '9')))
                        {
                            n[i][0] = 12.01;
                            n[i][1] = c[i+1] - '0';
                            mass += n[i][0]*n[i][1];
                            i += 1;
                        }
                        else
                        {
                            n[i][0] = 12.01;
                            mass += n[i][0];
                        }
                    }
                    else if(c[i] == 'H')
                    {
                        n[i][0] = 1.008;
                        if((c[i+1] >= '0' && c[i+1] <= '9') && ((c[i+2] >= '0' && c[i+2] <= '9')))
                        {
                            n[i][0] = 1.008;
                            n[i][1] = 10*(c[i+1] - '0');
                            n[i][2] = c[i+2] - '0';
                            if((n[i][1]+n[i][2]) < 2 || (n[i][1]+n[i][2]) > 99)
                            {
                                return 0;
                            }
                            mass += n[i][0]*(n[i][1]+n[i][2]);
                            i += 2;
                        }
                        else if((c[i+1] >= '2' && c[i+1] <= '9') && ((c[i+2] < '0' || c[i+2] > '9')))
                        {
                            n[i][0] = 1.008;
                            n[i][1] = c[i+1] - '0';
                            mass += n[i][0]*n[i][1];
                            i += 1;
                        }
                        else
                        {
                            mass += n[i][0];
                        }
                    }
                    else if(c[i] == 'O')
                    {
                        n[i][0] = 16.00;
                        if((c[i+1] >= '0' && c[i+1] <= '9') && ((c[i+2] >= '0' && c[i+2] <= '9')))
                        {
                            n[i][0] = 16.00;
                            n[i][1] = 10*(c[i+1] - '0');
                            n[i][2] = c[i+2] - '0';
                            if((n[i][1]+n[i][2]) < 2 || (n[i][1]+n[i][2]) > 99)
                            {
                                return 0;
                            }
                            mass += n[i][0]*(n[i][1]+n[i][2]);
                            i += 2;
                        }
                        else if((c[i+1] >= '2' && c[i+1] <= '9') && ((c[i+2] < '0' || c[i+2] > '9')))
                        {
                            n[i][0] = 16.00;
                            n[i][1] = c[i+1] - '0';
                            mass += n[i][0]*n[i][1];
                            i += 1;
                        }
                        else
                        {
                            mass += n[i][0];
                        }
                    }
                    else if(c[i] == 'N')
                    {
                        n[i][0] = 14.01;
                        if((c[i+1] >= '0' && c[i+1] <= '9') && ((c[i+2] >= '0' && c[i+2] <= '9')))
                        {
                            n[i][0] = 14.01;
                            n[i][1] = 10*(c[i+1] - '0');
                            n[i][2] = c[i+2] - '0';
                            if((n[i][1]+n[i][2]) < 2 || (n[i][1]+n[i][2]) > 99)
                            {
                                return 0;
                            }
                            mass += n[i][0]*(n[i][1]+n[i][2]);
                            i += 2;
                        }
                        else if((c[i+1] >= '2' && c[i+1] <= '9') && ((c[i+2] < '0' || c[i+2] > '9')))
                        {
                            n[i][0] = 14.01;
                            n[i][1] = c[i+1] - '0';
                            mass += n[i][0]*n[i][1];
                            i += 1;
                        }
                        else
                        {
                            mass += n[i][0];
                        }
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
                {
                    return 0;
                }
            }
            printf("%.3f\n",mass);
            mass = 0;
            j++;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}
