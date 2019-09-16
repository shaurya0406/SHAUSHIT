//
//  main.cpp
//  movie_management
//
//  Created by Shaurya Chandra on 16/09/19.
//  Copyright © 2019 Shaurya Chandra. All rights reserved.
//

#include<conio.h>
#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<ctype.h>
#include<iomanip.h>
int currentitem = 0;
class Menu
{
public:
    int pageid;
    int itemnumber;
    int left_allign = 0;
    int centre_allign = 1;
    int right_allign = 2;
    char items[10][50];
    Menu(int p,int i,char a[10][50])
    {
        pageid = p;
        itemnumber = i;
        for(int j = 0;j<i;j++)
            strcpy(a[i],items[i]);
    }
    void Drawbox(int l,int b,int x ,int y,char text[]);
    void Highlight(int l, int b,int x , int y , char a);
    void drawvertical(int allign);
    void drawhorizontal(int x,int y,int size);
    void scroll(int c);
    void select(int c);
};

void Menu::Drawbox(int l,int b,int x ,int y,char text[])
{
    textcolor(YELLOW);
    int n = y;
    int a = l-1;
    gotoxy(x,y);
    char w[70] = " ";
    char h[25] = " ";
    h[0] = char(179)    ;
    for(int i = 0;i<l;i++)
    {
        w[i]=char(196);
        h[i+1] = ' ';
    }
    h[a] = char(179);
    cprintf(w);
    n++;
    for(int j = 0 ;j<b;j++)
    {
        gotoxy(x,n);
        cprintf(h);
        n++;
    }
    gotoxy(x,n);
    cprintf(w);
    gotoxy(x+2,y+(b%2));
    textcolor(WHITE);
    cprintf(text);
}

void Menu::Highlight(int l, int b,int x , int y , char a)
{
    int m = x,n=y;
    char w[70] = " ";
    for(int i = 0;i<l;i++)
        w[i] = a;
    textcolor(RED);
    gotoxy(m,n+b+1);
    cprintf(w);
    textcolor(WHITE);
}

void Menu::drawvertical(int allign)()
{
    if(allign==1){
        for(int i=0;i<itemnumber;i++)
            Drawbox(20, 1, 30, 5+(3*i), items[i]);
    }
    if(allign==0){
        for(int j=0;j<itemnumber;j++)
            Drawbox(20, 1, 0, 5+(3*j), items[j]);
    }
    if(allign==2){
        for(int k=0;k<itemnumber;k++)
            Drawbox(20, 1, 50, 5+(3*k), items[k]);
    }
}

void Menu::drawhorizontal(int x,int y,int size)
{
    for(int i=0;i<itemnumber;i++)
    {
//        int l = strlen(items[i]);
        Drawbox(20, 1,0+(size*i),5,items[i]);
        }
}
void Menu::scroll(int c)
{
    
    clrscr();
    drawvertical(1);
    switch(c)
    {
        case 0:
            Highlight(20,1,30,5,'*');
            break;
        case 1:
            Highlight(20,1,30,8,'*');
            break;
        case 2:
            Highlight(20,1,30,11,'*');
            break;
        case 3:
            Highlight(20,1,30,14,'*');
            break;
        case 4:
            Highlight(20,1,30,17,'*');
            break;
        case 5:
            Highlight(20,1,30,20,'*');
            break;
        default:
            return;
    }
}

void Menu::select(int c)
{
    switch(c)
    {
        case 0:
            //tictactoe();
            break;
        case 1:
            //dinosaur();
            break;
        case 2:
            //snake();
            break;
        case 3:
            //word();
            break;
        case 4:
            //minesweeper();
            break;
        case 5:
            //about();
            break;
        default:
            return;
    }
}

int main()
{
    clrscr();
    _setcursortype(_NOCURSOR);
    char a,b;
    char start[10][20]={"ADMIN","Customer","QUIT(x)"};
    Menu start(0,2,start);
    start.drawvertical(1);
    int totalitems = start.itemnumber;
    start.scroll(currentitem);
    do{
        a=getch();
        switch(tolower(a))
        {
            case 0:
            {
                b = getch();
                switch(b)
                {
                    case 80:
                    {
                        if(currentitem<totalitems)
                        {
                            currentitem++;
                            start.scroll(currentitem);
                        }
                        else if(currentitem ==totalitems)
                        {
                            currentitem = 0;
                            start.scroll(currentitem);
                        }
                    }
                        break;
                    case 72:
                    {
                        if(currentitem>0)
                        {
                            currentitem--;
                            start.scroll(currentitem);
                        }
                        else if(currentitem == 0)
                        {
                            currentitem = totalitems;
                            start.scroll(currentitem);
                        }
                    }
                        break;
                    case 13:
                        start.select(currentitem);
                        break;
                }
            }
                break;
            case 13:
                start.select(currentitem);
                break;
            case 'x':
                return;
        }
    }while(a!='x');
}

