#include <stdio.h>
#include <string.h>
int main()
{
    char getInstruction[110];
    int i_th_position[110];
    int i,t,total_instruction,final_position=0,other;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&total_instruction);
        getchar();
        for(i=0; i<total_instruction; i++)
        {
            scanf("%s",getInstruction);
            if(getInstruction[0]=='L')
                i_th_position[i] = -1;
            else if(getInstruction[0] == 'R')
                i_th_position[i] = 1;
            else
            {
                scanf("%s %d",getInstruction,&other);
                i_th_position[i] = i_th_position[other-1];
            }
        }
        for(i=0; i<total_instruction; i++)
        {
            final_position += i_th_position[i];
        }
        printf("%d\n",final_position);
        final_position = 0;
        if(t==0)
            break;
    }
    return 0;
}
