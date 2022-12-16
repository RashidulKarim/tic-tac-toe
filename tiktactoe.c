#include<stdio.h>
#include <stdbool.h>

void printCell(int arr[][4], int n)
{
    for(int i = 1; i<=n; i++)
    {
        for(int j =1; j <= n; j++)
        {
            printf("\t");
            if(arr[i][j] == 1) printf("X");
            if(arr[i][j] == 2) printf("O");
            if(j != 3) printf("\t|");
        }
        if(i != 3) printf("\n-----------------------------------------------");
        printf("\n");
    }
}

int whoWin(int arr[][4], int n)
{
    for(int i = 1; i <=n ; i++)
    {
        if(arr[i][1] == arr[i][2] && arr[i][2] == arr[i][3] && arr[i][1] != -1)
        {
            return arr[i][1];
        }
    }
    for(int j = 1; j <=n ; j++)
    {
        if(arr[1][j] == arr[2][j] && arr[2][j] == arr[3][j] && arr[1][j] != -1)
        {
            return arr[1][j];
        }
    }
    if(arr[1][1] == arr[2][2] && arr[2][2] == arr [3][3] && arr[1][1] != -1)
    {
        return arr[1][1];
    }
    if(arr[1][3] == arr[2][2] && arr[2][2] == arr [3][1] && arr[1][3] != -1)
    {
        return arr[1][3];
    }
    return 0;
}

int main()
{
    int n = 3, count = 0;
    int arr[4][4];
    for(int i = 1; i <= n; i++)
    {
        for(int j =1; j <= n; j++)
        {
            arr[i][j] = -1;
        }
    }
    bool player1 =true;
    bool player2 =false;
    while(1)
    {
        printCell(arr, n);
        if (whoWin(arr, n) == 1)
        {
            printf("Player 1 win.\n");
            break;
        }
        if (whoWin(arr, n) == 2)
        {
            printf("Player 2 win.\n");
            break;
        }
        if(count == 9)
        {
            printf("No winner found");
            break;
        }
        if(player1)
        {
            int r, c;
            flag:
            printf("Player1 please input the row and column number: ");
            scanf("%d %d", &r, &c);
            if(arr[r][c] != -1)
            {
                printf("Invalid Input\n");
                goto flag;
            }
            arr[r][c] = 1;
            player1 = false;
            player2 = true;
            count++;
        }
        else {
            int r, c;
            flag1:
            printf("Player2 please input the row and column number: ");
            scanf("%d %d", &r, &c);
            if(arr[r][c] != -1)
            {
                printf("Invalid Input\n");
                goto flag1;
            }
            arr[r][c] = 2;
            player1 = true;
            player2 = false;
            count++;
        }
    }



    return 0;
}
