#include<iostream>
#include<vector>
#include <windows.h> 
#include <conio.h>
#include<cstdlib>
#include<ctime>
#define N 9
using namespace std;
bool isSafe(vector<vector<int>>& v, int row,int col, int num)
{
    for (int x = 0; x <= 8; x++)
        if (v[row][x] == num)
            return false;

    for (int x = 0; x <= 8; x++)
        if (v[x][col] == num)
            return false;

    int startRow = row - row % 3,startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (v[i + startRow][j +startCol] == num)
                return false;

    return true;
}
bool sudokuSolver(vector<vector<int>>& v,int row,int col){

    if(row==v.size()-1 && col==v.size()){
        return true;
    }

    if(col==v.size()){
        row++;
        col=0;
    }

    if(v[row][col] > 0 )
        return sudokuSolver(v,row,col+1);
    
    for(int i=1;i<=9;i++){
        if(isSafe(v,row,col,i)){
            v[row][col]=i;

            if(sudokuSolver(v,row,col+1)){
                return true;
            }
        }
        v[row][col]=0;
    }

    return false;
}
void print(vector<vector<int>> v){
    
    cout<<"\t\t\t\t_____________________________________\n";
    for(int i=0;i<v.size();i++){
        //cout<<"\t\t|   |   |   |   |   |   |   |   |   |\n";
        cout<<"\t\t\t\t| ";
        for(int j=0;j<v[0].size();j++){
            if(v[i][j]==0){
                cout<<" "<<" | ";
            }
            else{
                cout<<v[i][j]<<" | ";
            }
        }
        cout<<"\n\t\t\t\t|___|___|___|___|___|___|___|___|___|\n";
    }
}
bool check(vector<vector<int>> s){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;i++){
            if(s[i][j]==0){
                return false;
            }
        }
    }
    return true;
}
int main(){
    vector<vector<int>> v1 = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    vector<vector<int>> v2 = {{0, 0, 0, 2, 6, 0, 7, 0, 1},
                      {6, 8, 0, 0, 7, 0, 0, 9, 0},
                      {1, 9, 0, 0, 0, 4, 5, 0, 0},
                      {8, 2, 0, 1, 0, 0, 0, 4, 0},
                      {0, 0, 4, 6, 0, 2, 9, 0, 0},
                      {0, 5, 0, 0, 0, 3, 0, 2, 8},
                      {0, 0, 9, 3, 0, 0, 0, 7, 4},
                      {0, 4, 0, 0, 5, 0, 0, 3, 6},
                      {7, 0, 3, 0, 1, 8, 0, 0, 0}};

    vector<vector<int>> v3 = {{0, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 6, 0, 0, 0, 0, 3},
                      {0, 7, 4, 0, 8, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 3, 0, 0, 2},
                      {0, 8, 0, 0, 4, 0, 0, 1, 0},
                      {6, 0, 0, 5, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 1, 0, 7, 8, 0},
                      {5, 0, 0, 0, 0, 9, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 4, 0}};

    vector<vector<int>> v4 = {{3, 9, 0,   0, 5, 0,   0, 0, 0},
                        {0, 0, 0,   2, 0, 0,   0, 0, 5},
                        {0, 0, 0,   7, 1, 9,   0, 8, 0},
                        {0, 5, 0,   0, 6, 8,   0, 0, 0},
                        {2, 0, 6,   0, 0, 3,   0, 0, 0},
                        {0, 0, 0,   0, 0, 0,   0, 0, 4},
                        {5, 0, 0,   0, 0, 0,   0, 0, 0},
                        {6, 7, 0,   1, 0, 5,   0, 4, 0},
                        {1, 0, 9,   0, 0, 0,   2, 0, 0}};
    
    srand (time(NULL));
    int random=rand()%4;
    vector<vector<int>> s;
    vector<vector<int>> p;
    vector<vector<int>> v;
    bool flag;
    switch(random){
        case 0: s=v1;
                p=v1;
                v=v1;
                if(sudokuSolver(v,0,0)){
                    flag=true;
                }
                break;
        case 1: s=v2;
                p=v2;
                v=v2;
                if(sudokuSolver(v,0,0)){
                    flag=true;
                }
                break;
        case 2: s=v3;
                p=v3;
                v=v3;
                if(sudokuSolver(v,0,0)){
                    flag=true;
                }
                break;
        case 3: s=v4;
                p=v4;
                v=v4;
                if(sudokuSolver(v,0,0)){
                    flag=true;
                }
                break;
    }
    if(flag){
    
        while(1){
            int x=0,y=0,n=0,c=0;
            char a;
            system("cls");
            system("color 07");
            cout<<"\n\n\n\t\t\t\t=============Sudoku Solver============";
            cout<<"\n\t\t\tIf your guess is correct the color will be Blue else it will be Red";
            //cout<<"\n\n\t\t\t===================Can You Solve it!===================";
            cout<<"\n\n\t\t\t\t=========Solve the Sudoku==========\n\n";
            print(s);
            cout<<"\n\t\t\t\tEnter the x-axis position:: ";
            cin>>x;
            cout<<"\n\t\t\t\tEnter the y-axis position:: ";
            cin>>y;
            cout<<"\n\t\t\t\tEnter the number do you want to insert(range 1 - 9):: ";
            cin>>n;
            if(p[x-1][y-1] != 0){
                cout<<"\n\n\t\t\t\tEnter Valid Position";
            }
            else{
                s[x-1][y-1]=n;
                if(s[x-1][y-1]==v[x-1][y-1]){
                    system("color 17");
                }
                else{
                    system("color 47");
                }
            }
            cout<<"\n\n\t\t\t\tDo you want to continue[Yes(1) or No(0)]:: ";
            cin>>c;
            
            system("cls");
            cout<<"\n\n\t\t\t\tWant to see answer!!\n\t\t\t\tPress q for answer otherwise press any key(except enter):: ";
            cin>>a;

            if(a=='q'){
                system("cls");
                system("color 64");
                cout<<"\n\n\t\t\t\t========Showing the answer=======\n\n";
                print(v);
                getch();
                cin.ignore();
                continue;
            } 

            if(check(s)){
                if(s==v){
                    system("cls");
                    system("color 64");
                    print(s);
                    cout<<"\n\n\n\n\t\t\t\tCongo you Won";
                    return 0;
                }
                else{
                    system("cls");
                    system("color 64");
                    print(s);
                    cout<<"\n\n\n\n\t\t\t\tOhh you Loses the game!!!";
                }
            }

            
            if(c==0){
                system("cls");
                cout<<"\n\n\t\t\t\tThanks for playing\n\n\t\t\t\tIts solution is\n\n";
                print(v);
                break;
            }

            getch();
            cin.ignore();
        }
    }
}
