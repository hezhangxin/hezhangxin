/*
 * 2048.cpp
 *
 * Copyright 2018 hezha <hezha@LAPTOP-9BQ9D8G6>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */



#include <iostream>
#include <string>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
using namespace std;

#define m 4
class game{
	public:

	game(){
	count1=0;
	for(i=0;i<m;i++)
	 for(j=0;j<m;j++)
	  box[i][j]=0;
	srand((unsigned)time(NULL));
	x=rand()%m;
	y=rand()%m;
	if(count1==0||count1==1)
	  box[x][y]=2;
	else
	  box[x][y]=4;
	//showbox();

	}
	void showbox();
	void up();
	void down();
	void left();
	void right();
	void add(int count1);
	bool gameover();
	int getdirection();
	private:
	int box[m][m];
	int x,y,count1,count2=0;
	int i,j;
};

void game::add(int count1)
{

	do{
		srand((unsigned)time(NULL));
		x=rand()%m;
		y=rand()%m;
	}while(box[x][y]!=0);
	if(count1<2)
	box[x][y]=2;
	else
	box[x][y]=4;
	//showbox();
}
void game::down()
{
	int s;
	//count2=0;
	for(j=m-1;j>=0;j--)
	{
	  for(i=m-1;i>0;i--)
	  {
		  if(box[i][j]==box[i-1][j]||box[i][j]==0)
		  {
			//  count2++;
			  box[i][j]+=box[i-1][j];
			  for(s=i-1;s>0;s--)
			  {
				  box[s][j]=box[s-1][j];

			  }

			  box[0][j]=0;
			  break;
		  }

	  }

    }


}

void game::up()
{
	int s;
	//count2=0;
	for(j=0;j<m;j++)
	{
	  for(i=0;i<m-1;i++)
	  {
		  if(box[i][j]==box[i+1][j]||box[i][j]==0)
		  {
			//  count2++;
			  box[i][j]+=box[i+1][j];
			  for(s=i+1;s<m-1;s++)
			  {
				  box[s][j]=box[s+1][j];

			  }

			  box[m-1][j]=0;
			  break;
		  }

	  }

    }



}
void game::left()
{
	int s;
	//count2=0;
	for(j=0;j<m;j++)
	{
	  for(i=0;i<m-1;i++)
	  {
		  if(box[j][i]==box[j][i+1]||box[j][i]==0)
		  {
			//  count2++;
			  box[j][i]+=box[j][i+1];
			  for(s=i+1;s<m-1;s++)
			  {
				  box[j][s]=box[j][s+1];

			  }

			  box[j][m-1]=0;
			  break;
		  }

	  }

    }




}
void game::right()
{
	int s;
	//count2=0;
	for(j=0;j<m;j++)
	{
	  for(i=m-1;i>0;i--)
	  {
		  if(box[j][i]==box[j][i-1]||box[j][i]==0)
		  {
			//  count2++;
			  box[j][i]+=box[j][i-1];
			  for(s=i-1;s>0;s--)
			  {
				  box[j][s]=box[j][s-1];

			  }

			  box[j][0]=0;
			  break;
		  }

	  }

    }



}
int game::getdirection()
{
    char c1,c2;
    int ret = 0;
    c1=getch();
    if (!isascii(c1))
    {
        c2 = getch();
        switch(c2)
        {
        case 72: ret = 1;break;
        case 80: ret = 2;break;
        case 75: ret = 3;break;
        case 77: ret = 4;break;
        default: break;
        }
    }
    return ret;
}
void game::showbox()
{

	cout<<setw(38)<<"X2048"<<endl;
    cout<<setw(50)<<" |-----------------------|"<<endl;
	for(i=0;i<m;i++)
	{
	  cout<<setw(24)<<" ";
	  for(j=0;j<m;j++)
	  {
		if (box[i][j] == 0)
            {
                cout<<setw(2)<<"|"<<setw(4)<<"";
            }
            else
                cout<<setw(2)<<"|"<<setw(4)<<box[i][j];

            if(j==3)
            {
                cout<<setw(2)<<"|"<<endl;
                cout<<setw(50)<<" |-----------------------|"<<endl;
            }

      }


	}



}
bool game::gameover()
{
	int t=0;
	for(i=0;i<m;i++)
	  for(j=0;j<m;j++)
	  {
		  if(box[i][j]==0)
		  t++;
		  if(box[i][j]==2048)
		  {
			  cout<<"success"<<endl;
			  return false;
		  }
	  }
	if(t==0)
	{

	for(i=0;i<m;i++)
	  for(j=0;j<m-1;j++)
	  {
		  if(box[j][i]==box[j+1][i])
		  t++;
	  }
	for(i=0;i<m;i++)
	  for(j=0;j<m-1;j++)
	  {
		  if(box[i][j]==box[i][j+1])
		  t++;
	  }

    }
	if(t>0)
	return true;
	else
	return false;
}

int main(int argc, char **argv)
{
	int t,e;
	game a;
	a.showbox();
	//t=a.getdirection();
	//cout<<t<<endl;
	do
	{
		t=a.getdirection();
		switch(t)
		{
			case 1: a.up();break;
			case 2: a.down();break;
			case 3: a.left();break;
			case 4: a.right();break;
			default:break;
		}
	    srand((unsigned)time(NULL));
        e=rand()%m;
        a.add(e);
        system("cls");
        a.showbox();
    }while(a.gameover());

	return 0;
}

