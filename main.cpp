#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <windows.h>
#include <unistd.h>
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
int square[10];
string marks="-123456789XO";

int checkwin();
void board();
int alegere(int);
int plane(int);
void gotoXY(int x, int y, string text);
void gotoXY(int x, int y);
int rocket(int);

int main()
{
	int player = 1, rez=-1, choice;

	for( int i=1; i<=9; i++)
    square[i] = i;

	while(rez==-1)
    {
        board();
		player=(player%2)?1:2;
        choice=alegere(player);
        cout<<"alegerea facuta:"<<choice<<endl;
        square[choice] = 9+player;
		rez=checkwin();
		player++;
    }

	board();
    int counter=0;
	if(rez==1)
		{
            system("cls");

                cout<<"                             ==>\aJucatorul "<<player-1<<" a castigat."<<endl;
                if(player-1==1)
                plane(1);
                if (player-1==2)
                rocket(2);
                cout<<"                             ==>\aJucatorul "<<player-1<<" a castigat."<<endl;
                cout<<endl;
           }

	else

        {
            cout<<"==>\aRemiza"<<endl;
        }


	return 0;
}

/*********************************************

	Functia care determina finalul jocului
**********************************************/

int checkwin()
{
	if (square[1] == square[2] && square[2] == square[3])

		return 1;
	else if (square[4] == square[5] && square[5] == square[6])

		return 1;
	else if (square[7] == square[8] && square[8] == square[9])

		return 1;
	else if (square[1] == square[4] && square[4] == square[7])

		return 1;
	else if (square[2] == square[5] && square[5] == square[8])

		return 1;
	else if (square[3] == square[6] && square[6] == square[9])

		return 1;
	else if (square[1] == square[5] && square[5] == square[9])

		return 1;
	else if (square[3] == square[5] && square[5] == square[7])

		return 1;
	else if (square[1] != 1 && square[2] != 2 && square[3] != 3
                    && square[4] != 4 && square[5] != 5 && square[6] != 6
                  && square[7] != 7 && square[8] != 8 && square[9] != 9)

		return 0;

	else
		return -1;
}




/*******************************************************************
Functie care se ocupa cu citirea alegerii jucatorului curent
*******************************************************************/
int alegere (int player)
{
    int ok=1, alege;
    while (ok==1)
    {
        cout << "Jucator " << player << ", introdu un numar:  ";
        cin >> alege;

        if ((alege>=1) && (alege<=9) && (square[alege]!=10) && (square[alege]!=11))
            ok=0;
    if (ok==1)
            cout<<"Introdu o valoare valida"<<endl;
            ok=0;
        if(alege>11)
            cout<<"Dati un numar mai mic decat 10"<<endl;
        ok=0;
    }
    return alege;
}
/*******************************************************************
     Tabla de X&O
********************************************************************/
void board()
{
	system("cls");
	system("Color FC");
	cout << "\n\n\t\tX&O\n\n";

	cout << "\tJucator 1 (X)  -  Jucator 2 (O)" << endl << endl;
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << marks[square[1]] << "  |  " << marks[square[2]] << "  |  " << marks[square[3]] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << marks[square[4]] << "  |  " << marks[square[5]] << "  |  " << marks[square[6]] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << marks[square[7]] << "  |  " << marks[square[8]] << "  |  " << marks[square[9]] << endl;

	cout << "     |     |     " << endl << endl;



}

/*******************************************************************
     Win-Screen pentru X
********************************************************************/



int plane(int)
{
    string Plane[]=
	{"                    _                                      "
	,"                  -=\\`\\                                    "
	,"              |\\ ____\\_\\__                                 "
	,"            -=\\c`\"\"\X si O\"\" \"`)                            "
	,"               `~~~~~/ /~~`                                "
	,"                 -==/ /                                    "
	,"                   '-'                                     "};

	string cloud[]=
	{"                  _  _                                     "
	,"                 ( `   )_                                  "
	,"                (    )    `)                               "
	,"              (_   (_ .  _) _)                             "};


	char holder = ' ';

	int len, x, y;

	len = Plane[0].length();
	string border(len,'\xCD');
	string shadow(len+2,'\xB2');
	cout << "\t  \xC9" << border << "\xBB" << endl;
	for (x=0;x<11;x++)
		cout<<"\t  \xBA                                                           \xBA\xB2"<<endl;
	cout<<"\t  \xBA                                             _             \xBA\xB2"<<endl;
	cout<<"\t  \xBA                                           (   )           \xBA\xB2"<<endl;
	cout<<"\t  \xBA             _ .                         ( `  ) . )        \xBA\xB2"<<endl;
	cout<<"\t  \xBA           (  _ )_                      (_, _(  ,_)_)      \xBA\xB2"<<endl;
	cout<<"\t  \xBA         (_  _(_ ,)                                        \xBA\xB2"<<endl;
	cout << "\t  \xC8" << border << "\xBC\xB2" << endl;
	cout << "\t   " << shadow << endl;
	do{
		for (y=0;y<7;y++)
		{
			gotoXY(11,1+y,Plane[y]);
		}

		for (y=0;y<4;y++)
		{
			gotoXY(11,8+y,cloud[y]);
		}

		for (y=0;y<7;y++)
		{
			holder = Plane[y][len];
			for (x=len;x>0;x--)
			{
				Plane[y][x]=Plane[y][x-1];
			}
			Plane[y][0]=holder;
		}

		for (y=0;y<4;y++)
		{
			holder = cloud[y][0];
			for (x=0;x<len;x++)
			{
				cloud[y][x]=cloud[y][x+1];
			}
			cloud[y][len]=holder;
		}
Sleep(60);
	}while(true);
return 0;
}
/*******************************************************************
     Miscare avion+nor
********************************************************************/

void gotoXY(int x, int y, string text)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console,CursorPosition);
	cout << text;
}




/*******************************************************************
     Win-Screen pentru O
********************************************************************/

int rocket(int)
{
  const char rocket[] =
"           _\n\
          /^\\\n\
          |-|\n\
          | |\n\
          |X|\n\
          |s|\n\
          |i|\n\
          |O|\n\
         /| |\\\n\
        / | | \\\n\
       |  | |  |\n\
        `-\"\"\"-`\n\
";
for (int i = 0; i < 50; i ++) cout<<"\n";
    cout<<rocket;
    int j = 300000;
    for (int i = 0; i < 300; i ++)
        {
        usleep(j);
        j = (int)(j * 0.9);
        cout<<"\n";;
        }

}
/*******************************************************************
				Sfarsit
********************************************************************/

