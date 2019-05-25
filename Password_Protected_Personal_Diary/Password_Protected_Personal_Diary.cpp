#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include <ctime>
#include <string>
#include <iomanip>
#include <windows.h>
#include<bits/stdc++.h>

using namespace std;

int password();

void addrecord();

void viewrecord();

void editrecord();

void editpassword();

void deleterecord();


struct record

{

    char time[6];

    char name[30];

    char place[25];

    char duration[10];

    char note[500];

} ;

int checkwin();
void brd();
int board[10] = {2,2,2,2,2,2,2,2,2,2};
int turn = 1,flag = 0;
int player,comp;

void menu();
void go(int n);
void start_game();
void check_draw();
void draw_board();
void player_first();
void put_X_O(char ch,int pos);
COORD coord= {0,0};

char square[10] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};

int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3] && square[1]!=' ')

        return 1;
    else if (square[4] == square[5] && square[5] == square[6] && square[4]!=' ')

        return 1;
    else if (square[7] == square[8] && square[8] == square[9] && square[7]!=' ')

        return 1;
    else if (square[1] == square[4] && square[4] == square[7] && square[1]!=' ')

        return 1;
    else if (square[2] == square[5] && square[5] == square[8] && square[2]!=' ')

        return 1;
    else if (square[3] == square[6] && square[6] == square[9] && square[3]!=' ')

        return 1;
    else if (square[1] == square[5] && square[5] == square[9] && square[1]!=' ')

        return 1;
    else if (square[3] == square[5] && square[5] == square[7] && square[7]!=' ')

        return 1;
    else if (square[1] != ' ' && square[2] != ' ' && square[3] != ' '
             && square[4] != ' ' && square[5] != ' ' && square[6] != ' '
             && square[7] != ' ' && square[8] != ' ' && square[9] != ' ')

        return 0;
    else
        return -1;
}

void brd()
{
    system("cls");
    cout << "\n\n\t\tTic Tac Toe\n\n";

    cout << "\tPlayer 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    cout << "\t     |     |     " << endl;
    cout << "\t  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << "\t_____|_____|_____" << endl;
    cout << "\t     |     |     " << endl;

    cout << "\t  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

    cout << "\t_____|_____|_____" << endl;
    cout << "\t     |     |     " << endl;

    cout << "\t  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

    cout << "\t     |     |     " << endl << endl;
}
void tictac()
{
    int player = 1,i,choice;

    char mark;
    do
    {
        brd();
        player=(player%2)?1:2;

        cout << "\tPlayer " << player << ", enter a number:  ";
        cin >> choice;

        mark=(player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == ' ')

            square[1] = mark;
        else if (choice == 2 && square[2] == ' ')

            square[2] = mark;
        else if (choice == 3 && square[3] == ' ')

            square[3] = mark;
        else if (choice == 4 && square[4] == ' ')

            square[4] = mark;
        else if (choice == 5 && square[5] == ' ')

            square[5] = mark;
        else if (choice == 6 && square[6] == ' ')

            square[6] = mark;
        else if (choice == 7 && square[7] == ' ')

            square[7] = mark;
        else if (choice == 8 && square[8] == ' ')

            square[8] = mark;
        else if (choice == 9 && square[9] == ' ')

            square[9] = mark;
        else
        {
            cout<<"Invalid move ";

            player--;
            cin.ignore();
            cin.get();
        }
        i=checkwin();

        player++;
    }
    while(i==-1);
    brd();
    if(i==1)

        cout<<"\n\t======>\aPLAYER "<<--player<<" WIN ";
    else
        cout<<"\n\t======>\aGAME DRAW";

    cin.ignore();
    cin.get();
}

void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int tic()
{
    system("cls");
    menu();
    _getch();
}

void menu()
{
    int choice;
    system("cls");
    printf("\n                            ========MENU========");
    printf("\n                            1 : Play with X");
    printf("\n                            2 : Play with O");
    printf("\n                            3 : Exit");
    printf("\n                            ====================\n");
    printf("\n                            Enter your choice:>");
    scanf("%d",&choice);
    turn = 1;
    switch (choice)
    {
    case 1:
        player = 1;
        comp = 0;
        player_first();
        break;
    case 2:
        player = 0;
        comp = 1;
        start_game();
        break;
    case 3:
        exit(1);
    default:
        menu();
    }
}

int make2()
{
    if(board[5] == 2)
        return 5;
    if(board[2] == 2)
        return 2;
    if(board[4] == 2)
        return 4;
    if(board[6] == 2)
        return 6;
    if(board[8] == 2)
        return 8;
    return 0;
}

int make4()
{
    if(board[1] == 2)
        return 1;
    if(board[3] == 2)
        return 3;
    if(board[7] == 2)
        return 7;
    if(board[9] == 2)
        return 9;
    return 0;
}

int posswin(int p)
{
    int i;
    int check_val,pos;

    if(p == 1)
        check_val = 18;
    else
        check_val = 50;

    i = 1;
    while(i<=9)
    {
        if(board[i] * board[i+1] * board[i+2] == check_val)
        {
            if(board[i] == 2)
                return i;
            if(board[i+1] == 2)
                return i+1;
            if(board[i+2] == 2)
                return i+2;
        }
        i+=3;
    }

    i = 1;
    while(i<=3)
    {
        if(board[i] * board[i+3] * board[i+6] == check_val)
        {
            if(board[i] == 2)
                return i;
            if(board[i+3] == 2)
                return i+3;
            if(board[i+6] == 2)
                return i+6;
        }
        i++;
    }

    if(board[1] * board[5] * board[9] == check_val)
    {
        if(board[1] == 2)
            return 1;
        if(board[5] == 2)
            return 5;
        if(board[9] == 2)
            return 9;
    }

    if(board[3] * board[5] * board[7] == check_val)
    {
        if(board[3] == 2)
            return 3;
        if(board[5] == 2)
            return 5;
        if(board[7] == 2)
            return 7;
    }
    return 0;
}

void go(int n)
{
    if(turn % 2)
        board[n] = 3;
    else
        board[n] = 5;
    turn++;
}

void player_first()
{
    int pos;

    check_draw();
    draw_board();
    gotoxy(30,18);
    printf("Your Turn :> ");
    scanf("%d",&pos);

    if(board[pos] != 2)
        player_first();

    if(pos == posswin(player))
    {
        go(pos);
        draw_board();
        gotoxy(30,20);
        printf("Player Wins");
        _getch();
        exit(0);
    }

    go(pos);
    draw_board();
    start_game();
}

void start_game()
{
    if(posswin(comp))
    {
        go(posswin(comp));
        flag = 1;
    }
    else if(posswin(player))
        go(posswin(player));
    else if(make2())
        go(make2());
    else
        go(make4());
    draw_board();

    if(flag)
    {
        gotoxy(30,20);
        printf("Computer wins");
        _getch();
    }
    else
        player_first();
}

void check_draw()
{
    if(turn > 9)
    {
        gotoxy(30,20);
        printf("Game Draw");
        _getch();
        exit(0);
    }
}

void draw_board()
{
    int j;

    for(j=9; j<17; j++)
    {
        gotoxy(35,j);
        printf("!       !");
    }
    gotoxy(28,11);
    printf("-----------------------");
    gotoxy(28,14);
    printf("-----------------------");

    for(j=1; j<10; j++)
    {
        if(board[j] == 3)
            put_X_O('X',j);
        else if(board[j] == 5)
            put_X_O('O',j);
    }
}

void put_X_O(char ch,int pos)
{
    int m;
    int x = 31, y = 10;

    m = pos;

    if(m > 3)
    {
        while(m > 3)
        {
            y += 3;
            m -= 3;
        }
    }
    if(pos % 3 == 0)
        x += 16;
    else
    {
        pos %= 3;
        pos--;
        while(pos)
        {
            x+=8;
            pos--;
        }
    }
    gotoxy(x,y);
    printf("%c",ch);
}

const int GRIDSIZE = 10;
enum direction {EXPAND_ROW, EXPAND_COL};

int GetPlayers();
void SetComputerBoats(char [GRIDSIZE][GRIDSIZE]);
void PrintBoard(char [GRIDSIZE][GRIDSIZE]);
string GetRank(int);
int PlaySingleMode(char [GRIDSIZE][GRIDSIZE]);
void SetParticularBoat(char [GRIDSIZE][GRIDSIZE], int, char);


int battleship()
{
	system("color 02");
	int numOfPlayers, moves=99;
	char player2Boats[GRIDSIZE][GRIDSIZE];

	cout << "						 B A T T L E S H I P\n";
	srand( (unsigned int) time(NULL) );
	numOfPlayers = GetPlayers();

	if(numOfPlayers == 2)
	{
		cout << "Player 1... get ready to place your ships...\n";
		system("pause");

		cout << "Player 2... get ready to place your ships...\n";
		system("pause");

	}
	else
	{
		SetComputerBoats(player2Boats);
	}

	if(numOfPlayers == 1)
	{
		moves = PlaySingleMode(player2Boats);
		system("cls");
		cout << "						 B A T T L E S H I P\n\n\n";
		PrintBoard(player2Boats);
		cout << "\n\nDestroying boats within " << moves
			 << " moves earns you the rank of "<< GetRank(moves) << ".\n";
	}
}

int GetPlayers()
{
	int n;
	cout << endl << "For 1 or 2 players? ";
	cin >> n;

	while(!cin || (n != 1 && n != 2))
	{
		if(!cin)
		{
			cin.clear();
			cin.ignore(INT_MAX,'\n');
		}
		cout << "For 1 or 2 players? ";
		cin >> n;
	}

	if(n == 2)
		cout << "Sorry, multiplayer mode not yet implemented."
			 << " Starting single-player mode.\n";
	return(1);
}
void SetComputerBoats(char p[GRIDSIZE][GRIDSIZE])
{

	for(int i=0; i<GRIDSIZE; i++)
		for(int j=0; j<GRIDSIZE; j++)
			p[i][j] = '-';

	SetParticularBoat(p, 5, 'A');
	SetParticularBoat(p, 4, 'B');
	SetParticularBoat(p, 3, 'C');
	SetParticularBoat(p, 3, 'S');
	SetParticularBoat(p, 2, 'D');


}
void PrintBoard(char p[GRIDSIZE][GRIDSIZE])
{
	cout << "						1  2  3  4  5  6  7  8  9 10\n";
	cout << "					  ------------------------------\n";
	for(int i=0; i<GRIDSIZE; i++)
	{
		cout << "					" << char('A' + i) << " |";
		for(int j=0; j<GRIDSIZE; j++)
			cout << ' ' << p[i][j] << ' ';
		cout << endl;
	}
}
string GetRank(int m)
{
	if(m <= 25)
		return("Admiral");
	else if(m <= 35)
		return("Captain");
	else if(m <= 45)
		return("Commander");
	else if(m <= 60)
		return("Lieutenant");
	else
		return("Ensign");
}
int PlaySingleMode(char p[GRIDSIZE][GRIDSIZE])
{
	int col=0, moves=0;
	char row = 'A';
	char grid[GRIDSIZE][GRIDSIZE];
	int carrierHits=0, battleshipHits=0, cruiserHits=0, submarineHits=0,
		destroyerHits=0;
	bool carrierSunk = false, battleshipSunk = false, cruiserSunk = false,
		submarineSunk = false, destroyerSunk = false;

	for(int i=0; i<GRIDSIZE; i++)
		for(int j=0; j<GRIDSIZE; j++)
			grid[i][j] = '-';

	PrintBoard(grid);

	while(!carrierSunk||!battleshipSunk||!cruiserSunk||!submarineSunk||
		!destroyerSunk)
	{
		cout << "\n\nPlease enter your coordinates: ";
		cin >> row;
		row = toupper(row);
		cin >> col;

	system("cls");
	cout << "						 B A T T L E S H I P\n\n";
	cout << "ENEMY  :  Aircraft Carrier   Battleship   Cruiser";
	cout << "   Submarine   Destroyer" << endl;
	cout << setw(7) << "	   ----------------------------------------------";
	cout << "-----------------------" << endl;
	cout << "STATUS :\n\n";

	if (p[int(row-'A')][col-1] == 'A')
	{
		grid[int(row-'A')][col-1] = 'A';
		carrierHits++;
	}

	if(p[int(row-'A')][col-1] == 'B')
	{
		grid[int(row-'A')][col-1] = 'B';
		battleshipHits++;
	}

	if(p[int(row-'A')][col-1] == 'S')
	{
		grid[int(row-'A')][col-1] = 'S';
		submarineHits++;
	}
	if(p[int(row-'A')][col-1] == 'C')
	{
		grid[int(row-'A')][col-1] = 'C';
		cruiserHits++;
	}

	if(p[int(row-'A')][col-1] == 'D')
	{
		grid[int(row-'A')][col-1] = 'D';
		destroyerHits++;
	}

	if(p[int(row-'A')][col-1] == '-')
	{
		grid[int(row-'A')][col-1] = 'M';
		cout << "\n Target missed...Try Another Location!\n\n";
	}
	else if(p[int(row-'A')][col-1] == '-')
	{
		grid[int(row-'A')][col-1] = '*';
		cout << "\n Target Hit!...Great Shot!\n\n";
	}
	if(carrierHits == 5)
	{
		carrierSunk = true;
		cout << "...You Sank My Aircraft Carrier!";
	}
	if(battleshipHits == 4)
	{
		battleshipSunk = true;
		cout << "...You Sank My Battleship!";
	}
	if(cruiserHits == 3)
	{
		cruiserSunk = true;
		cout << "...You Sank My Cruiser!";
	}
	if(submarineHits == 3)
	{
		submarineSunk = true;
		cout << "...You Sank My Submarine!";
	}
	if(destroyerHits == 2)
	{
		destroyerSunk = true;
		cout << "...You Sank My Destroyer!";
	}

	PrintBoard(grid);

	moves++;
	cout << "\nCurrent Move: " << moves;



	}

	return (moves);


}
void SetParticularBoat(char g[GRIDSIZE][GRIDSIZE], int ship_size, char boat)
{
	bool placementFailure = true;
	char startingRow = 'A';
	int startingCol = 0;
	direction d;

	while(placementFailure)
	{
		startingRow = rand()%GRIDSIZE;
		if(startingRow > GRIDSIZE-ship_size)
		{
			d = EXPAND_ROW;
			startingCol = rand()%(GRIDSIZE-ship_size);
		}
		else
		{
			startingCol= rand()%GRIDSIZE;
			if(startingCol > GRIDSIZE-ship_size)
				d = EXPAND_COL;
			else
				d = (rand()%2)==0?EXPAND_ROW:EXPAND_COL;
		}
		placementFailure = false;

		for(int i=0; i<ship_size; i++)
		{
			if(d==EXPAND_ROW && g[startingRow][startingCol+i] != '-')
				placementFailure = true;
			else if(d==EXPAND_COL && g[startingRow+i][startingCol] != '-')
				placementFailure = true;
		}
		if(!placementFailure)
		{
			for(int i=0; i<ship_size; i++)
			{
				if(d==EXPAND_ROW)
					g[startingRow][startingCol+i] = boat;
				else
					g[startingRow+i][startingCol] = boat;
			}
		}
	}
}

void game()
{
    system("cls");
    printf("\n\tPLAY TIC TAC TOE\t[1]");
    printf("\n\tPLAY BATTLESHIP \t[2]");
    printf("\n\tBACK \t\t\t[3]");
    printf("\n\n\tENTER YOUR CHOICE:");
    int n;
    scanf("%d",&n);
    system("cls");
    if(n==1)
    {
        system("cls");
        printf("\n\tSINGEL PLAYER\t[1]");
        printf("\n\tMULTIPLAYER\t[2]");
        printf("\n\tBACK \t\t[3]");
        printf("\n\n\tENTER YOUR CHOICE:");
        int x;
        cin >> x;
        system("cls");
        if(x==2) tictac();
        else if(x==1) tic();
        else game();
    }
    else if(n==2)battleship();
    else return;
}


int main()

{

    int ch;

    printf("\n\n\t***********************************\n");

    printf("\t*PASSWORD PROTECTED PERSONAL DIARY*\n");

    printf("\t***********************************");


    while(1)


    {

        printf("\n\n\t\tMAIN MENU:");

        printf("\n\n\tADD RECORD\t[1]");

        printf("\n\tVIEW RECORD\t[2]");

        printf("\n\tEDIT RECORD\t[3]");

        printf("\n\tDELETE RECORD\t[4]");

        printf("\n\tEDIT PASSWORD\t[5]");

        printf("\n\tPLAY GAME\t[6]");

        printf("\n\tEXIT\t\t[7]");

        printf("\n\n\tENTER YOUR CHOICE:");

        scanf("%d",&ch);


        switch(ch)

        {

        case 1:

            addrecord();

            break;


        case 2:

            viewrecord();

            break;


        case 3:

            editrecord();

            break;


        case 4:

            deleterecord();

            break;


        case 5:

            editpassword();

            break;

        case 6:

            game();

            break;

        case 7:

            printf("\n\n\t\tTHANK YOU FOR USING THE SOFTWARE BY:\n\n\tHIMEL\n\n\tGAZI\n\n\tROKON...");

            _getch();

            exit(0);


        default:

            printf("\nYOU ENTERED WRONG CHOICE..");

            printf("\nPRESS ANY KEY TO TRY AGAIN");

            _getch();

            break;

        }

        system("cls");

    }

    return 0;

}

void addrecord( )

{

    system("cls");

    FILE *fp ;

    char another = 'Y',time[10];

    struct record e ;

    char filename[15];

    int choice;

    printf("\n\n\t\t***************************\n");

    printf("\t\t* WELCOME TO THE ADD MENU *");

    printf("\n\t\t***************************\n\n");

    printf("\n\n\tENTER DATE OF YOUR RECORD:[yyyy-mm-dd]:");

    fflush(stdin);

    gets(filename);

    fp = fopen (filename, "ab+" ) ;

    if ( fp == NULL )

    {

        fp=fopen(filename,"wb+");

        if(fp==NULL)

        {

            printf("\nSYSTEM ERROR...");

            printf("\nPRESS ANY KEY TO EXIT");

            _getch();

            return ;

        }

    }



    while ( another == 'Y'|| another=='y' )

    {

        choice=0;

        fflush(stdin);

        printf ( "\n\tENTER TIME:[hh:mm]:");

        scanf("%s",time);

        rewind(fp);

        while(fread(&e,sizeof(e),1,fp)==1)

        {

            if(strcmp(e.time,time)==0)

            {

                printf("\n\tTHE RECORD ALREADY EXISTS.\n");

                choice=1;

            }

        }

        if(choice==0)

        {

            strcpy(e.time,time);

            printf("\tENTER NAME:");

            fflush(stdin);

            gets(e.name);

            fflush(stdin);

            printf("\tENTER PLACE:");

            gets(e.place);

            fflush(stdin);

            printf("\tENTER DURATION:");

            gets(e.duration);

            fflush(stdin);

            printf("\tNOTE:");

            gets(e.note);

            fwrite ( &e, sizeof ( e ), 1, fp ) ;

            printf("\nYOUR RECORD IS ADDED...\n");

        }

        printf ( "\n\tADD ANOTHER RECORD...(Y/N) " ) ;

        fflush ( stdin ) ;

        another = getchar( ) ;

    }


    fclose ( fp ) ;

    printf("\n\n\tPRESS ANY KEY TO EXIT...");

    _getch();

}


void viewrecord( )

{

    FILE *fpte ;

    system("cls");

    struct record customer ;

    char time[6],choice,filename[14];

    int ch;

    printf("\n\n\t\t*******************************\n");

    printf("\t\t* HERE IS THE VIEWING MENU *");

    printf("\n\t\t*******************************\n\n");

    choice=password();

    if(choice!=0)

    {

        return ;

    }

    do

    {

        printf("\n\tENTER THE DATE OF RECORD TO BE VIEWED:[yyyy-mm-dd]:");

        fflush(stdin);

        gets(filename);


        fpte = fopen ( filename, "rb" ) ;

        if ( fpte == NULL )

        {

            puts ( "\nTHE RECORD DOES NOT EXIST...\n" ) ;

            printf("PRESS ANY KEY TO EXIT...");

            _getch();

            return ;

        }

        system("cls");

        printf("\n\tHOW WOULD YOU LIKE TO VIEW:\n");

        printf("\n\t1.WHOLE RECORD OF THE DAY.");

        printf("\n\t2.RECORD OF FIX TIME.");

        printf("\n\t\tENTER YOUR CHOICE:");

        scanf("%d",&ch);

        switch(ch)

        {

        case 1:

            printf("\nTHE WHOLE RECORD FOR %s IS:",filename);

            while ( fread ( &customer, sizeof ( customer ), 1, fpte ) == 1 )

            {

                printf("\n");

                printf("\nTIME: %s",customer.time);

                printf("\nMEETING WITH: %s",customer.name);

                printf("\nMEETING AT: %s",customer.place);

                printf("\nDURATION: %s",customer.duration);

                printf("\nNOTE: %s",customer.note);

                printf("\n");

            }

            break;


        case 2:

            fflush(stdin);

            printf("\nENTER TIME:[hh:mm]:");

            gets(time);

            while ( fread ( &customer, sizeof ( customer ), 1, fpte ) == 1 )


            {

                if(strcmp(customer.time,time)==0)

                {

                    printf("\nYOUR RECORD IS:");

                    printf("\nTIME: %s",customer.time);

                    printf("\nMEETING WITH: %s",customer.name);

                    printf("\nMEETING AT: %s",customer.place);

                    printf("\nDUARATION: %s",customer.duration);

                    printf("\nNOTE: %s",customer.note);

                }

            }

            break;


        default:
            printf("\nYOU TYPED SOMETHING ELSE...\n");

            break;

        }


        printf("\n\nWOULD YOU LIKE TO CONTINUE VIEWING...(Y/N):");

        fflush(stdin);

        scanf("%c",&choice);

    }
    while(choice=='Y'||choice=='y');

    fclose ( fpte ) ;

    return ;

}

void editrecord()

{

    system("cls");

    FILE *fpte ;

    struct record customer ;

    char time[6],choice,filename[14];

    int num,count=0;

    printf("\n\n\t\t*******************************\n");

    printf("\t\t* WELCOME TO THE EDITING MENU *");

    printf("\n\t\t*******************************\n\n");

    choice=password();

    if(choice!=0)

    {

        return ;

    }

    do

    {

        printf("\n\tENTER THE DATE OF RECORD TO BE EDITED:[yyyy-mm-dd]:");

        fflush(stdin);

        gets(filename);

        printf("\n\tENTER TIME:[hh:mm]:");

        gets(time);

        fpte = fopen ( filename, "rb+" ) ;

        if ( fpte == NULL )

        {

            printf( "\nRECORD DOES NOT EXISTS:" ) ;

            printf("\nPRESS ANY KEY TO GO BACK");

            _getch();

            return;

        }

        while ( fread ( &customer, sizeof ( customer ), 1, fpte ) == 1 )

        {

            if(strcmp(customer.time,time)==0)

            {

                printf("\nYOUR OLD RECORD WAS AS:");

                printf("\nTIME: %s",customer.time);

                printf("\nMEETING WITH: %s",customer.name);

                printf("\nMEETING AT: %s",customer.place);

                printf("\nDURATION: %s",customer.duration);

                printf("\nNOTE: %s",customer.note);


                printf("\n\n\t\tWHAT WOULD YOU LIKE TO EDIT..");

                printf("\n1.TIME.");

                printf("\n2.MEETING PERSON.");

                printf("\n3.MEETING PLACE.");

                printf("\n4.DURATION.");

                printf("\n5.NOTE.");

                printf("\n6.WHOLE RECORD.");

                printf("\n7.GO BACK TO MAIN MENU.");

                do

                {

                    printf("\n\tENTER YOUR CHOICE:");

                    fflush(stdin);

                    scanf("%d",&num);

                    fflush(stdin);

                    switch(num)

                    {

                    case 1:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nNEW TIME:[hh:mm]:");

                        gets(customer.time);

                        break;


                    case 2:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nNEW MEETING PERSON:");

                        gets(customer.name);

                        break;


                    case 3:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nNEW MEETING PLACE:");

                        gets(customer.place);

                        break;


                    case 4:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nDURATION:");

                        gets(customer.duration);

                        break;


                    case 5:
                        printf("ENTER THE NEW DATA:");

                        printf("\nNOTE:");

                        gets(customer.note);

                        break;


                    case 6:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nNEW TIME:[hh:mm]:");

                        gets(customer.time);

                        printf("\nNEW MEETING PERSON:");

                        gets(customer.name);

                        printf("\nNEW MEETING PLACE:");

                        gets(customer.place);

                        printf("\nDURATION:");

                        gets(customer.duration);

                        printf("\nNOTE:");

                        gets(customer.note);

                        break;


                    case 7:
                        printf("\nPRESS ANY KEY TO GO BACK...\n");

                        _getch();

                        return ;

                        break;


                    default:
                        printf("\nYOU TYPED SOMETHING ELSE...TRY AGAIN\n");

                        break;

                    }


                }
                while(num<1||num>8);

                fseek(fpte,-sizeof(customer),SEEK_CUR);

                fwrite(&customer,sizeof(customer),1,fpte);

                fseek(fpte,-sizeof(customer),SEEK_CUR);

                fread(&customer,sizeof(customer),1,fpte);

                choice=5;

                break;

            }

        }

        if(choice==5)

        {

            system("cls");

            printf("\n\t\tEDITING COMPLETED...\n");

            printf("--------------------\n");

            printf("THE NEW RECORD IS:\n");

            printf("--------------------\n");

            printf("\nTIME: %s",customer.time);

            printf("\nMEETING WITH: %s",customer.name);

            printf("\nMEETING AT: %s",customer.place);

            printf("\nDURATION: %s",customer.duration);

            printf("\nNOTE: %s",customer.note);

            fclose(fpte);

            printf("\n\n\tWOULD YOU LIKE TO EDIT ANOTHER RECORD.(Y/N)");

            scanf("%c",&choice);

            count++;

        }

        else

        {

            printf("\nTHE RECORD DOES NOT EXIST::\n");

            printf("\nWOULD YOU LIKE TO TRY AGAIN...(Y/N)");

            scanf("%c",&choice);

        }


    }
    while(choice=='Y'||choice=='y');

    fclose ( fpte ) ;


    if(count==1)

        printf("\n%d FILE IS EDITED...\n",count);

    else if(count>1)

        printf("\n%d FILES ARE EDITED..\n",count);

    else

        printf("\nNO FILES EDITED...\n");

    printf("\tPRESS ENTER TO EXIT EDITING MENU.");

    _getch();

}

int password()

{

    char pass[15]= {0},check[15]= {0},ch;

    FILE *fpp;

    int i=0,j;

    printf("::FOR SECURITY PURPOSE::");

    printf("::ONLY THREE TRIALS ARE ALLOWED::");

    for(j=0; j<3; j++)

    {

        i=0;

        printf("\n\n\tENTER THE PASSWORD:");

        pass[0]=_getch();

        while(pass[i]!='\r')

        {

            if(pass[i]=='\b')

            {

                i--;

                printf("\b");

                printf(" ");

                printf("\b");

                pass[i]=_getch();

            }

            else

            {

                printf("*");

                i++;

                pass[i]=_getch();

            }

        }

        pass[i]='\0';

        fpp=fopen("SE","r");

        if (fpp==NULL)

        {

            printf("\nERROR WITH THE SYSTEM FILE...[FILE MISSING]\n");

            _getch();

            return 1;

        }

        else

            i=0;

        while(1)

        {

            ch=fgetc(fpp);

            if(ch==EOF)

            {

                check[i]='\0';

                break;

            }

            check[i]=ch-5;

            i++;

        }

        if(strcmp(pass,check)==0)

        {

            printf("\n\n\tACCESS GRANTED...\n");

            return 0;

        }

        else

        {

            printf("\n\n\tWRONG PASSWORD..\n\n\tACCESS DENIED...\n");

        }

    }

    printf("\n\n\t::YOU ENTERED WRONG PASSWORD::YOU ARE NOT ALLOWED TO ACCESS ANY FILE::\n\n\tPRESS ANY KEY TO GO BACK...");

    _getch();

    return 1;

}

void editpassword()

{

    system("cls");

    printf("\n");

    char pass[15]= {0},confirm[15]= {0},ch;

    int choice,i,check;

    FILE *fp;

    fp=fopen("SE","rb");

    if(fp==NULL)

    {

        fp=fopen("SE","wb");

        if(fp==NULL)

        {

            printf("SYSTEM ERROR...");

            _getch();

            return ;

        }

        fclose(fp);

        printf("\nSYSTEM RESTORED...\nYOUR PASSWORD IS 'ENTER'\n PRESS ENTER TO CHANGE PASSWORD\n\n");

        _getch();

    }

    fclose(fp);

    check=password();

    if(check==1)

    {

        return ;

    }

    do

    {

        if(check==0)

        {

            i=0;

            choice=0;

            printf("\n\n\tENTER THE NEW PASSWORD:");

            fflush(stdin);

            pass[0]=_getch();

            while(pass[i]!='\r')

            {

                if(pass[i]=='\b')

                {

                    i--;

                    printf("\b");

                    printf(" ");

                    printf("\b");

                    pass[i]=_getch();

                }

                else

                {

                    printf("*");

                    i++;

                    pass[i]=_getch();

                }

            }

            pass[i]='\0';

            i=0;

            printf("\n\tCONFIRM PASSWORD:");

            confirm[0]=_getch();

            while(confirm[i]!='\r')

            {

                if(confirm[i]=='\b')

                {

                    i--;

                    printf("\b");

                    printf(" ");

                    printf("\b");

                    confirm[i]=_getch();

                }

                else

                {

                    printf("*");

                    i++;

                    confirm[i]=_getch();

                }

            }

            confirm[i]='\0';

            if(strcmp(pass,confirm)==0)

            {

                fp=fopen("SE","wb");

                if(fp==NULL)

                {

                    printf("\n\t\tSYSTEM ERROR");

                    _getch();

                    return ;

                }

                i=0;

                while(pass[i]!='\0')

                {

                    ch=pass[i];

                    putc(ch+5,fp);

                    i++;

                }

                putc(EOF,fp);

                fclose(fp);

            }

            else

            {

                printf("\n\tTHE NEW PASSWORD DOES NOT MATCH.");

                choice=1;


            }


        }

    }
    while(choice==1);


    printf("\n\n\tPASSWORD CHANGED...\n\n\tPRESS ANY KEY TO GO BACK...");

    _getch();

}


void deleterecord( )

{

    system("cls");

    FILE *fp,*fptr ;

    struct record file ;

    char filename[15],another = 'Y',time[10];;

    int choice,check;

    printf("\n\n\t\t*************************\n");

    printf("\t\t* WELCOME TO DELETE MENU*");

    printf("\n\t\t*************************\n\n");

    check = password();

    if(check==1)

    {

        return ;

    }


    while ( another == 'Y' )

    {

        printf("\n\n\tHOW WOULD YOU LIKE TO DELETE.");

        printf("\n\n\t#DELETE WHOLE RECORD\t\t\t[1]");

        printf("\n\t#DELETE A PARTICULAR RECORD BY TIME\t[2]");


        do

        {

            printf("\n\t\tENTER YOU CHOICE:");

            scanf("%d",&choice);


            switch(choice)

            {

            case 1:

                printf("\n\tENTER THE DATE OF RECORD TO BE DELETED:[yyyy-mm-dd]:");

                fflush(stdin);

                gets(filename);

                fp = fopen (filename, "wb" ) ;

                if ( fp == NULL )

                {

                    printf("\nTHE FILE DOES NOT EXISTS");

                    printf("\nPRESS ANY KEY TO GO BACK.");

                    _getch();

                    return ;

                }

                fclose(fp);

                remove(filename);

                printf("\nDELETED SUCCESFULLY...");

                break;


            case 2:

                printf("\n\tENTER THE DATE OF RECORD:[yyyy-mm-dd]:");

                fflush(stdin);

                gets(filename);

                fp = fopen (filename, "rb" ) ;

                if ( fp == NULL )

                {

                    printf("\nTHE FILE DOES NOT EXISTS");

                    printf("\nPRESS ANY KEY TO GO BACK.");

                    _getch();

                    return ;

                }

                fptr=fopen("temp","wb");

                if(fptr==NULL)

                {

                    printf("\nSYSTEM ERROR");

                    printf("\nPRESS ANY KEY TO GO BACK");

                    _getch();

                    return ;

                }

                printf("\n\tENTER THE TIME OF RECORD TO BE DELETED:[hh:mm]:");

                fflush(stdin);

                gets(time);

                while(fread(&file,sizeof(file),1,fp)==1)

                {

                    if(strcmp(file.time,time)!=0)

                        fwrite(&file,sizeof(file),1,fptr);

                }


                fclose(fp);

                fclose(fptr);

                remove(filename);

                rename("temp",filename);

                printf("\nDELETED SUCCESFULLY...");

                break;


            default:

                printf("\n\tYOU ENTERED WRONG CHOICE");

                break;

            }

        }
        while(choice<1||choice>2);



        printf("\n\tDO YOU LIKE TO DELETE ANOTHER RECORD.(Y/N):");

        fflush(stdin);

        scanf("%c",&another);

    }

    printf("\n\n\tPRESS ANY KEY TO EXIT...");

    _getch();

}

