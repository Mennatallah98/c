/*
 color function and corresponding colors:
 Gray->(0,8)        Red->(0,12)
 Blue->(0,9)        Pink->(0,13)
 Green->(0,10)      Yellow->(0,14)
 Milky->(0,11)      White->(0,15)

//********************************************************************************************************
pixels limit
x-> 4-40
y-> 0-160


*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include "mouse_handler.h"


//Main functions
void Menu();
void Free_paint();
void Geometrical_figures();
void Exit();
//********************************************************************************************************

//Auxiliary functions
int pth (int i,int j)
{
    return sqrt (pow(i,2)+pow(j,2));
}


int main()
{
    //change console color and size
    system("color 0f");
    system("mode con cols=160 lines=57");


    Menu();

    return 0;
}

void Menu()
{
    int n;
    printf("....................<Welcome to painting on console>.......................");
    printf("\nChoose one of the following options\n");
    printf("1-Free paint\n2-Geometrical figures\n3-Exit\n");
    printf("Write the number of the desired option: ");
    scanf(" %d",&n);
    if(n==1)
    {
        printf("--------------------------------------------------------------------\n");
        Free_paint();

    }
    else if(n==2)
    {
        printf("--------------------------------------------------------------------\n");
        system("cls");
        G_layout();
        Geometrical_figures();
    }
    else if(n==3)
    {
        printf("--------------------------------------------------------------------\n");
        Exit();
    }
    else
    {
        printf("\n->Please choose one of the mentioned options");
        Menu();
    }
}
//************************************************************************************************************************

void Free_paint()
{
    system("cls");
    F_layout();

    while(1)
    {

        //Sensing the mouse
        static DMOUSE m;
        mouse(&m);
        int x = m.coordinates.X;        // the position of mouse click
        int y = m.coordinates.Y;
//******************************************************************
        //change color
        if((x>=146 && x<149) && y==12)                       //change color //RED
        {
            color(0,12);
        }
        else if((x>=146 && x<149) && y==14)                   //change color //PINK
        {
            color(0,13);
        }
        else if((x>=151 && x<154) && y==12)                   //change color  //YELLOW
        {
            color(0,14);
        }
        else if((x>=151 && x<154) && y==14)                   //change color  //GREEN
        {
            color(0,10);
        }
        else if((x>=148 && x<151) && y==16)                   //change color  //BLUE
        {
            color(0,9);
        }

//******************************************************************
        //Drawing
        if((x>=0 && x<140) && (y>4 && y<49) )
        {
            gotoxy(x,y);
            printf(" ");
        }
        //**************************************
        //Eraser
        if((x>=145 && x<155) && y==20)
        {
            color(0,0);
        }
        //************************************

        //Home
        if((x>40)&&(x<50)&&(y==2))
        {

            system("cls");
            color(15,0);
            Menu();
        }
        //****************************
        //Clear
        else if((x>120)&&(x<130)&&(y==2))
        {
            color(0,0);
            system("cls");
            Free_paint();
        }
        //***********************************
    }

//******************************************************************
}
//********************************************************************************************************************************
void Draw_Delete(int mode,char shape,int l,int w,int r,int c,int x,int y)
{

    int check=0;
    while(check==0)
    {
        if(shape=='l')
        {
            check=1;
            w=1;
        }
        else if(shape=='s')
        {
            check=1;
            w=l;
        }
        else if(shape=='r')
        {
            check=1;
        }
        else if(shape=='c')
        {
            check=1;
            l=r;
            w=1.5*r;

        }
        else if(shape=='t')
        {
            check=1;
            w=l;
        }
        else
        {
            clear_text();
            gotoxy(0,41);
            printf(">please enter one of the mentioned shapes: \n");
            check=0;
        }
    }
    //******************************************************************************************

    //choosing the color
    int colour;

    check=0;
    while (check==0)
    {
        if(c==1)
        {
            colour=12;
            check=1;
        }

        else if(c==2)
        {
            colour=13;
            check=1;
        }
        else if(c==3)
        {
            colour=14;
            check=1;
        }
        else if(c==4)
        {
            colour=10;
            check=1;
        }
        else if(c==5)
        {
            colour=9;
            check=1;
        }
        else
        {
            clear_text();
            gotoxy(0,41);
            printf("->please enter one of the mentioned colors: ");
            check=0;
        }
    }
    //printf("--------------------------------------------------------\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),colour);
    //****************************************************************************************************

    if(mode==1)
    {
        //Drawing the shape
        int i,j;
        //gotoxy(x,y);
        if (shape=='l'||shape=='s'||shape=='r')
        {
            for(j=0; j<w; j++)
            {
                printf("\n");
                for(i=0; i<l; i++)
                {
                    if(j==0||j==(w-1))
                    {
                        printf("* ");
                    }
                    else
                    {
                        if(i==0||i==(l-1))
                        {
                            printf("* ");
                        }
                        else
                        {
                            printf("  ");
                        }
                    }
                }
            }
        }

        else if(shape=='c')
        {
            for (j=l; j>= -l; j-=2)
            {
                printf("\n");
                for (i=-w; i <= w; i++)
                {

                    if ((int) pth(i,j)==l)
                    {
                        printf("*");
                    }

                    else
                    {
                        printf(" ");
                    }
                }
            }
        }

        if(shape=='t')
        {
            int i, j, k=0;
            for(i=1; i<=l; ++i, k=0)
            {
                printf("\n");
                for(j=1; j<=l-i; ++j)
                {
                    printf("  ");
                }
                while(k != 2*i-1)
                {
                    if(i==l)
                    {
                        printf("* ");
                    }
                    else
                    {
                        if(k==2*i-2)
                        {
                            printf("* ");
                        }
                        else if(k==0)
                        {
                            printf("* ");
                        }
                        else
                        {
                            printf("  ");
                        }
                    }
                    ++k;
                }
                printf("\n");
            }
        }
    }
    else if(mode==0)
    {
        color(0,0);
        //Drawing the shape
        int i,j;
        // gotoxy(x,y);
        if (shape=='l'||shape=='s'||shape=='r')
        {
            for(j=0; j<w; j++)
            {
                printf("\n");
                for(i=0; i<l; i++)
                {
                    if(j==0||j==(w-1))
                    {
                        printf("  ");
                    }
                    else
                    {
                        if(i==0||i==(l-1))
                        {
                            printf("  ");
                        }
                        else
                        {
                            printf("  ");
                        }
                    }
                }
            }
        }

        else if(shape=='c')
        {
            for (j=l; j>= -l; j-=2)
            {
                printf("\n");
                for (i=-w; i <= w; i++)
                {

                    if ((int) pth(i,j)==l)
                    {
                        printf(" ");
                    }

                    else
                    {
                        printf(" ");
                    }
                }
            }
        }

        if(shape=='t')
        {
            int i, j, k=0;
            for(i=1; i<=l; ++i, k=0)
            {
                printf("\n");
                for(j=1; j<=l-i; ++j)
                {
                    printf("  ");
                }
                while(k != 2*i-1)
                {
                    if(i==l)
                    {
                        printf("  ");
                    }
                    else
                    {
                        if(k==2*i-2)
                        {
                            printf("  ");
                        }
                        else if(k==0)
                        {
                            printf("  ");
                        }
                        else
                        {
                            printf("  ");
                        }
                    }
                    ++k;
                }
                printf("\n");
            }
        }
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    //************************************************************************************************************
}
//********************************************************************************************************************************

void Geometrical_figures()
{
    //clearing the screen
    clear_text();
    gotoxy(0,41);
    int check=0;
    //************************************************************************************************
    char shape;
    int l,w;
    int r;
    while(check==0)
    {
        //choosing the shape
        printf("Choose the shape you want to be drawn\n");
        printf("(l)line\n(s)square\n(r)rectangle\n(c)circle\n(t)triangle\n");
        printf("Enter the corresponding letter to the desired shape: ");
        scanf(" %c",&shape);
        printf("--------------------------------------------------------");
        //******************************************************************************************************

        //Determining its dimensions
        clear_text();
        gotoxy(0,41);
        if(shape=='l')
        {
            check=1;
            printf("please enter the dimensions of the shape: \n");
            w=1;
            printf("length: ");
            scanf("%d",&l);
            printf("--------------------------------------------------------");
        }
        else if(shape=='s')
        {
            check=1;
            printf("please enter the dimensions of the shape: \n");
            printf("side: ");
            scanf("%d",&l);
            w=l;
            printf("--------------------------------------------------------");
        }
        else if(shape=='r')
        {
            check=1;
            printf("please enter the dimensions of the shape: \n");
            printf("width: ");
            scanf("%d",&l);
            printf("length: ");
            scanf("%d",&w);
            printf("--------------------------------------------------------");
        }
        else if(shape=='c')
        {
            check=1;

            printf("please enter the dimensions of the shape: \n");
            printf("radius: ");
            scanf("%d",&r);
            l=r;
            w=1.5*r;
            printf("--------------------------------------------------------");
        }
        else if(shape=='t')
        {
            check=1;
            printf("please enter the dimensions of the shape: \n");
            printf("side: ");
            scanf("%d",&l);
            w=l;
            printf("--------------------------------------------------------");
        }
        else
        {
            clear_text();
            gotoxy(0,41);
            printf(">please enter one of the mentioned shapes: \n");
            check=0;
        }
    }
    //******************************************************************************************

    //choosing the color
    int colour,c;
    clear_text();
    gotoxy(0,41);
    check=0;
    while (check==0)
    {
        printf("Choose a color from the colors mentioned below: ");
        printf("\n1-Red\n2-Pink\n3-Yellow\n4-Green\n5-Blue\n");
        printf("Enter the corresponding number to the desired color: ");
        scanf("%d",&c);
        if(c==1)
        {
            colour=12;
            check=1;
        }

        else if(c==2)
        {
            colour=13;
            check=1;
        }
        else if(c==3)
        {
            colour=14;
            check=1;
        }
        else if(c==4)
        {
            colour=10;
            check=1;
        }
        else if(c==5)
        {
            colour=9;
            check=1;
        }
        else
        {

            clear_text();
            gotoxy(0,41);
            printf("->please enter one of the mentioned colors: ");
            check=0;
        }
    }
    printf("--------------------------------------------------------\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),colour);
    //****************************************************************************************************

    //Drawing the shape
    int i,j;
    gotoxy(0,4);
    if (shape=='l'||shape=='s'||shape=='r')
    {
        for(j=0; j<w; j++)
        {
            printf("\n");
            for(i=0; i<l; i++)
            {
                if(j==0||j==(w-1))
                {
                    printf("* ");
                }
                else
                {
                    if(i==0||i==(l-1))
                    {
                        printf("* ");
                    }
                    else
                    {
                        printf("  ");
                    }
                }
            }
        }
    }

    else if(shape=='c')
    {
        for (j=l; j>= -l; j-=2)
        {
            printf("\n");
            for (i=-w; i <= w; i++)
            {

                if ((int) pth(i,j)==l)
                {
                    printf("*");
                }

                else
                {
                    printf(" ");
                }
            }
        }
    }

    if(shape=='t')
    {
        int i, j, k=0;
        for(i=1; i<=l; ++i, k=0)
        {
            printf("\n");
            for(j=1; j<=l-i; ++j)
            {
                printf("  ");
            }
            while(k != 2*i-1)
            {
                if(i==l)
                {
                    printf("* ");
                }
                else
                {
                    if(k==2*i-2)
                    {
                        printf("* ");
                    }
                    else if(k==0)
                    {
                        printf("* ");
                    }
                    else
                    {
                        printf("  ");
                    }
                }
                ++k;
            }
            printf("\n");
        }
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    //************************************************************************************************************

    //Changing color, moving and starting new shape
    clear_text();
    gotoxy(0,41);
    int check1=0;
    char jump,u;
    int x=1;
    int y=4;
    while(check1==0)
    {
bad:
        clear_text();
        gotoxy(0,41);
        color(15,0);
        printf("->change shape color. (c)\n->move shape. (m)\n->Add new shape. (n)\n->Activate the buttons. (b)\n");
        scanf(" %c",&jump);
        if(jump=='m')
        {

            clear_text();
            gotoxy(0,41);
            printf("press arrow to move ,ESC to exit\n");
            char prev = 0;
            char a;
            while(1)
            {

                a=getch();
                //for detect the function\arrow keys
                //we must call the getch() again
                //testing if a is '0' or '0xE0'
                if (a==0 || a==0xE0) a=getch();

                if (a==27)                                 //ESC for exit the 'while'
                    break;
                else if (a==72)         //up
                {
                    //moving
                    gotoxy(x,y);
                    Draw_Delete(0,shape,l,w,r,c,x,y);
                    y--;
                    if(y<=4) y=4;
                    gotoxy(x,y);
                    Draw_Delete(1,shape,l,w,r,c,x,y);
                    /*clear_text();
                    gotoxy(0,41);
                    printf("UP");*/
                }
                else if (a==80)         //down
                {
                    gotoxy(x,y);
                    Draw_Delete(0,shape,l,w,r,c,x,y);
                    y++;
                    if((y+l)>=38) (y)=38-l;
                    gotoxy(x,y);
                    Draw_Delete(1,shape,l,w,r,c,x,y);
                    /*clear_text();
                    gotoxy(0,41);
                    printf("DOWN");*/
                }
                else if (a==75)         //left
                {
                    gotoxy(x,y);
                    Draw_Delete(0,shape,l,w,r,c,x,y);
                   // printf("l");
                    x--;
                    printf("%d",x);
                    if(x<=0) x=0;
                    gotoxy(x,y);
                    Draw_Delete(1,shape,l,w,r,c,x,y);
                    /*clear_text();
                    gotoxy(0,41);
                    printf("LEFT");*/
                }
                else if (a==77)         //right
                {
                    gotoxy(x,y);
                    Draw_Delete(0,shape,l,w,r,c,x,y);
                    //printf("r");
                    x++;
                    printf("%d",x);
                    if((x+w)>=160) (x)=160-w;
                    gotoxy(x,y);
                    Draw_Delete(1,shape,l,w,r,c,x,y);
                    /* clear_text();
                     gotoxy(0,41);
                     printf("RIGHT");*/
                }
                /* else{
                     clear_text();
                     gotoxy(0,41);
                     printf("%d",(int) a);
                 }*/
            }

            //*********************************************************************
        }
        else if (jump=='n')
        {
            Geometrical_figures();
        }
         else if(jump == 'b')
            {
                check=1;
                clear_text();
                gotoxy(0,40);
                printf("\n\n\n\n.............The buttons are now active..............");
                //Activating clear and home
                static DMOUSE m;
                mouse(&m);
                int m_x = m.coordinates.X;        // the position of mouse click
                int m_y = m.coordinates.Y;
                while(1)
                {
                     int m_x = m.coordinates.X;        // the position of mouse click
                int m_y = m.coordinates.Y;
                if((m_x>40)&&(m_x<50)&&(m_y==2))
                {
                    color(15,0);
                    system("cls");
                    Menu();
                }
                else if((m_x>120)&&(m_x<130)&&(m_y==2))
                {
                    color(15,0);
                    clear_drawing();
                    break;
                }
                }
                //******************************************************************
            }
        else if (jump=='c')
        {
            //changing the color
            int colour,c;
            clear_text();
            gotoxy(0,41);
            check=0;
            while (check==0)
            {
                printf("Choose a color from the colors mentioned below: ");
                printf("\n1-Red\n2-Pink\n3-Yellow\n4-Green\n5-Blue\n");
                printf("Enter the corresponding number to the desired color: ");
                scanf("%d",&c);
                if(c==1)
                {
                    colour=12;
                    check=1;
                }

                else if(c==2)
                {
                    colour=13;
                    check=1;
                }
                else if(c==3)
                {
                    colour=14;
                    check=1;
                }
                else if(c==4)
                {
                    colour=10;
                    check=1;
                }
                else if(c==5)
                {
                    colour=9;
                    check=1;
                }
                else
                {
                    clear_text();
                    gotoxy(0,41);
                    printf("->please enter one of the mentioned colors: ");
                    check=0;
                }
            }
            printf("--------------------------------------------------------\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),colour);
            //****************************************************************************************************

            //Drawing the shape
            int i,j;
            gotoxy(x,y);
            if (shape=='l'||shape=='s'||shape=='r')
            {
                for(j=0; j<w; j++)
                {
                    printf("\n");
                    for(i=0; i<l; i++)
                    {
                        if(j==0||j==(w-1))
                        {
                            printf("* ");
                        }
                        else
                        {
                            if(i==0||i==(l-1))
                            {
                                printf("* ");
                            }
                            else
                            {
                                printf("  ");
                            }
                        }
                    }
                }
            }

            else if(shape=='c')
            {
                for (j=l; j>= -l; j-=2)
                {
                    printf("\n");
                    for (i=-w; i <= w; i++)
                    {

                        if ((int) pth(i,j)==l)
                        {
                            printf("*");
                        }

                        else
                        {
                            printf(" ");
                        }
                    }
                }
            }

            if(shape=='t')
            {
                int i, j, k=0;
                for(i=1; i<=l; ++i, k=0)
                {
                    printf("\n");
                    for(j=1; j<=l-i; ++j)
                    {
                        printf("  ");
                    }
                    while(k != 2*i-1)
                    {
                        if(i==l)
                        {
                            printf("* ");
                        }
                        else
                        {
                            if(k==2*i-2)
                            {
                                printf("* ");
                            }
                            else if(k==0)
                            {
                                printf("* ");
                            }
                            else
                            {
                                printf("  ");
                            }
                        }
                        ++k;
                    }
                    printf("\n");
                }

            }

            else
            {
                clear_text();
                gotoxy(0,41);
                printf("enter n,c ,m or b:");
                goto bad;
            }
        }

        //*************************************************************************************************************

    }
}
//*****************************************************************************************************************************
void gotoxy(int x, int y)
{
    HANDLE hConsoleOutput;
    COORD dwCursorPosition;
    //cout.flush();
    dwCursorPosition.X = x;
    dwCursorPosition.Y = y;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}
//*****************************************************************************************************************************
void color(int t,int f)   //f is the color of console, t is the color of test in case of typing text
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,f*16+t);
}
//*****************************************************************************************************************************
void G_layout()           //interface for geometry
{
    int i=0;
    gotoxy(40,2);
    color(0,15);
    printf(" H O M E ");
    gotoxy(120,2);
    printf(" C L E A R ");
    color(0,0);
    printf(" ");
    color(15,0);


    for(i=0; i<160; i++) //x line
    {
        gotoxy(i,4);
        printf("%c", 219);
    }
    for(i=0; i<160; i++) //x line
    {
        gotoxy(i,40);
        printf("%c", 219);
    }
}
//*****************************************************************************************************************************

void F_layout()
{
    int i=0;
    gotoxy(40,2);
    color(0,15);
    printf(" H O M E ");

    gotoxy(120,2);
    printf(" C L E A R ");


    color(0,0);
    printf(" ");
    color(15,0);
    gotoxy(144,8);
    printf(" C O L O R S");
    //Red
    gotoxy(146,12);
    color(0,12);
    printf("   ");
    color(15,0);
    //*****************
    //Pink
    gotoxy(146,14);
    color(0,13);
    printf("   ");
    color(15,0);
    //*********************
    //Yellow
    gotoxy(151,12);
    color(0,14);
    printf("   ");
    color(15,0);
    //******************
    //Green
    gotoxy(151,14);
    color(0,10);
    printf("   ");
    color(15,0);
    //******************
    //Blue
    gotoxy(148,16);
    color(0,9);
    printf("    ");
    color(15,0);
    //******************
    //eraser
    gotoxy(145,20);
    color(4,7);
    printf(" E R A S E R");
    //**********************
    color(15,0);

    for(i=0; i<160; i++) //x line
    {
        gotoxy(i,4);
        printf("%c", 219);
    }
    for(i=4; i<50; i++) //y line
    {
        gotoxy(140,i);
        printf("%c", 219);
    }

    for(i=0; i<160; i++) //x line
    {
        gotoxy(i,50);
        printf("%c", 219);
    }



}
//*****************************************************************************************************************

void clear_text()
{
    int i,j;
    for(j=41; j<=55; j++)
    {
        for(i=0; i<=160; i++)
        {
            gotoxy(i,j);
            printf(" \r");
        }
    }
}
//***********************************************************************************************************************

void clear_drawing()
{
   int i,j;
    for(j=5; j<=38; j++)
    {
        for(i=0; i<=160; i++)
        {
            gotoxy(i,j);
            printf(" \r");
        }
    }
}

void Exit()
{
    char c;
    system("cls");
    printf("Are you sure you want to exit?");
    //*************************************************************

    //creating button
    gotoxy(50,2);
    color(10,7);
    printf(" Y E S ");
    gotoxy(75,2);
    color(12,7);
    printf(" N O ");
    color(15,0);
    //*******************************************************************************************

    //sensing the click
    static DMOUSE m;
    mouse(&m);
    int x = m.coordinates.X;        // the position of mouse click
    int y = m.coordinates.Y;
    if((x>50)&&(x<60)&&(y==2))
    {
        return 0;
    }
    else if((x>75)&&(x<85)&&(y==2))
    {
        system("cls");
        Menu();
    }


}
//*******************************************************************************************************************************
