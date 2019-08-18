#include<stdio.h>
#include<stdlib.h>
#include<fstream.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include<math.h>

int matrixfuncl(int f,int b[10][10][10],int p[10],int q[10]);
int matrixfunc2(int q,int p,int b[10][10]);
int matrixfunc3(int q,int p,int b[10][10]);
int matrixfunc4_1(int q,int p,int b[10][10]);
int matrixfunc4_2(int q,int p,int b[10][10]);
int fac(int a);
float cbr(float x);
float root(float b,float c);

int a[3][3],t,y,game=1,win=0,lose=0,tie=0,twin,tlose,ttie;
char name[30],str[500];

class ttt{
   public:
   	int st();
      int store();
      int loadval();
      int showdt();
      int ifexist();
      int delrec();
   private:
      void print();
      int check();
      void pin();
      int defend(int c, int p, int b);
      int attack();
      void ai(int b);
};

void ttt::print()
{
    clrscr();
    int i,j;
    cout<<"\n";
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(a[i][j]==0)
                cout<<"  .\t";
            else if(a[i][j]==1)
                cout<<"  X\t";
            else
                cout<<"  O\t";
        }
        cout<<endl;
    }
    gotoxy(1,6);
}

int ttt::check()
{
    for(int i=0;i<3;i++)
        if((a[i][0]!=0&&a[i][0]==a[i][1]
        &&a[i][1]==a[i][2])||(a[0][i]!=0&&a[0][i]==a[1][i]&&a[1][i]==a[2][i]))
            return 1;
    if(a[0][0]!=0&&a[0][0]==a[1][1]&&a[1][1]==a[2][2])
        return 1;
    else if(a[0][2]!=0&&a[0][2]==a[1][1]&&a[1][1]==a[2][0])
        return 1;
    else
        return 0;
}

void ttt::pin()
{
    int r=0,c=0;
    cout<<"  Enter row: ";
    cin>>r;
    cout<<"  Enter column: ";
    cin>>c;
    r--;
    c--;
    if(r>2||c>2||r<0||c<0)
    {
        cout<<"  enter correct value"<<endl;
        pin();
    }
    else if(a[r][c]!=0)
    {
        cout<<"  It is already filled.\n";
        pin();
    }
    else
        a[r][c]=t;
}

int ttt::defend(int c, int p, int b)
{
    if(b<3)
        return 0;
    else if(a[0][0]+a[1][1]+a[2][2]==2*c&&a[0][0]!=p&&a[1][1]!=p&&a[2][2]!=p)
    {
        for(int i=0;i<3;i++)
        {
            if(a[i][i]==0)
            {
                a[i][i]=y;
                return 1;
            }
        }
    }
    else if(a[0][2]+a[1][1]+a[2][0]==2*c&&a[0][2]!=p&&a[1][1]!=p&&a[2][0]!=p)
    {
        for(int i=0;i<3;i++)
        {
            if(a[i][2-i]==0)
            {
                a[i][2-i]=y;
                return 1;
            }
        }
    }
    else
    {
        int i,j;
        for(i=0;i<3;i++)
        {
            if(a[i][0]+a[i][1]+a[i][2]==2*c&&a[i][0]!=p&&a[i][1]!=p&&a[i][2]!=p)
            {
                for(j=0;j<3;j++)
                {
                    if(a[i][j]==0)
                    {
                        a[i][j]=y;
                        return 1;
                    }
                }
            }
            else
            if(a[0][i]+a[1][i]+a[2][i]==2*c&&a[0][i]!=p&&a[1][i]!=p&&a[2][i]!=p)
            {
                for(j=0;j<3;j++)
                {
                    if(a[j][i]==0)
                    {
                        a[j][i]=y;
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int ttt::attack()
{
    int i,j;
    if(a[0][0]+a[0][2]+a[2][0]+a[2][2]==t||a[0][0]+a[0][2]+a[2][0]+a[2][2]==2*t)
    {
        for(i=0;i<3;i++)
        {
            if(a[i][0]+a[i][1]+a[i][2]==y&&(a[i][0]==y||a[i][1]==y||a[i][2]==y))
            {
                if(i==1)
                {
                    for(j=0;j<3;j++)
                    {
                        if(a[i][j]==0)
                        {
                            a[i][j]=y;
                            return 1;
                        }
                    }
                }
                else
                {
                    for(j=2;j>=0;j--)
                    {
                        if(a[i][j]==0)
                        {
                            a[i][j]=y;
                            return 1;
                        }
                    }
                }
            }
            if(a[0][i]+a[1][i]+a[2][i]==y&&(a[0][i]==y||a[1][i]==y||a[2][i]==y))
            {
                if(i==1)
                {
                    for(j=0;j<3;j++)
                    {
                        if(a[j][i]==0)
                        {
                            a[j][i]=y;
                            return 1;
                        }
                    }
                }
                else
                {
                    for(j=2;j>=0;j--)
                    {
                        if(a[j][i]==0)
                        {
                            a[j][i]=y;
                            return 1;
                        }
                    }
                }

            }
        }

        if(a[0][0]+a[1][1]+a[2][2]==y && (a[0][0]==y||a[1][1]==y||a[2][2]==y))
        {
            for(i=2;i>=0;i--)
            {
                if((a[i][i]==0)&&((a[i][0]+a[i][1]+a[i][2]==y&&
                (a[i][0]==y||a[i][1]==y||a[i][2]==y))||
                ((a[0][i]+a[1][i]+a[2][i]==y)&&
                (a[0][i]==y||a[1][i]==y||a[2][i]==y))))
                {
                    a[i][i]=y;
                    return 1;
                }
            }
            for(i=2;i>=0;i--)
            {
                if(a[i][i]==0)
                {
                    if((a[i][0]+a[i][1]+a[i][2]==t&&(a[i][0]==t||a[i][1]==t||
                    a[i][2]==t))&&(a[0][i]+a[1][i]+a[2][i]==t&&
                    (a[0][i]==t||a[1][i]==t||a[2][i]==t)))
                    {
                        a[i][i]=y;
                        return 1;
                    }
                }
            }
            for(i=2;i>=0;i--)
            {
                if(a[i][i]==0)
                {
                    a[i][i]=y;
                    return 1;
                }
            }
        }
        else
        if(a[0][2]+a[1][1]+a[2][0]==y&&(a[0][2]==y||a[1][1]==y||a[2][0]==y))
        {
            for(i=2;i>=0;i--)
            {
                if(a[i][2-i]==0&&((a[i][0]+a[i][1]+a[i][2]==y&&
                (a[i][0]==y||a[i][1]==y||a[i][2]==y))||
                ((a[0][2-i]+a[1][2-i]+a[2][2-i]==y)&&
                (a[0][2-i]==y||a[1][2-i]==y||a[2][2-i]==y))))
                {
                    a[i][2-i]=y;
                    return 1;
                }
            }
            for(i=2;i>=0;i--)
            {
                if(a[i][2-i]==0)
                {
                    if((a[i][0]+a[i][1]+a[i][2]==t&&
                    (a[i][0]==t||a[i][1]==t||a[i][2]==t))&&
                    (a[0][2-i]+a[1][2-i]+a[2][2-i]==t&&
                    (a[0][2-i]==t||a[1][2-i]==t||a[2][2-i]==t)))
                    {
                        a[i][2-i]=y;
                        return 1;
                    }
                }
            }
            for(i=2;i>=0;i--)
            {
                if(a[i][2-i]==0)
                {
                    a[i][2-i]=y;
                    return 1;
                }
            }
        }
    }
    else
    {
        if(a[0][0]+a[1][1]+a[2][2]==y && (a[0][0]==y||a[1][1]==y||a[2][2]==y))
        {
            for(i=2;i>=0;i--)
            {
                if((a[i][i]==0)&&((a[i][0]+a[i][1]+a[i][2]==y&&
                (a[i][0]==y||a[i][1]==y||a[i][2]==y))||
                ((a[0][i]+a[1][i]+a[2][i]==y)&&
                (a[0][i]==y||a[1][i]==y||a[2][i]==y))))
                {
                    a[i][i]=y;
                    return 1;
                }
            }
            for(i=2;i>=0;i--)
            {
                if(a[i][i]==0)
                {
                    if((a[i][0]+a[i][1]+a[i][2]==t&&(a[i][0]==t||a[i][1]==t||
                    a[i][2]==t))&&(a[0][i]+a[1][i]+a[2][i]==t&&
                    (a[0][i]==t||a[1][i]==t||a[2][i]==t)))
                    {
                        a[i][i]=y;
                        return 1;
                    }
                }
            }
            for(i=2;i>=0;i--)
            {
                if(a[i][i]==0)
                {
                    a[i][i]=y;
                    return 1;
                }
            }
        }

        else
        if(a[0][2]+a[1][1]+a[2][0]==y&&(a[0][2]==y||a[1][1]==y||a[2][0]==y))
        {
            for(i=2;i>=0;i--)
            {
                if(a[i][2-i]==0&&((a[i][0]+a[i][1]+a[i][2]==y&&(a[i][0]==y||
                a[i][1]==y||a[i][2]==y))||((a[0][2-i]+a[1][2-i]+a[2][2-i]==y)&&
                (a[0][2-i]==y||a[1][2-i]==y||a[2][2-i]==y))))
                {
                    a[i][2-i]=y;
                    return 1;
                }
            }
            for(i=2;i>=0;i--)
            {
                if(a[i][2-i]==0)
                {
                    if((a[i][0]+a[i][1]+a[i][2]==t&&(a[i][0]==t||a[i][1]==t||
                    a[i][2]==t))&&(a[0][2-i]+a[1][2-i]+a[2][2-i]==t&&
                    (a[0][2-i]==t||a[1][2-i]==t||a[2][2-i]==t)))
                    {
                        a[i][2-i]=y;
                        return 1;
                    }
                }
            }

            for(i=2;i>=0;i--)
            {
                if(a[i][2-i]==0)
                {
                    a[i][2-i]=y;
                    return 1;
                }
            }
        }

        else
        {
            for(i=0;i<3;i++)
            {
                if(a[i][0]+a[i][1]+a[i][2]==y&&
                (a[i][0]==y||a[i][1]==y||a[i][2]==y))
                {
                    if(i==1)
                    {
                        for(int j=0;j<3;j++)
                        {
                            if(a[i][j]==0)
                            {
                                a[i][j]=y;
                                return 1;
                            }
                        }
                    }
                    else{
                        for(j=2;j>=0;j--)
                        {
                            if(a[i][j]==0)
                            {
                                a[i][j]=y;
                                return 1;
                            }
                        }
                    }
                }
                else if(a[0][i]+a[1][i]+a[2][i]==y&&
                (a[0][i]==y||a[1][i]==y||a[2][i]==y))
                {
                    if(i==1)
                    {
                        for(j=0;j<3;j++)
                        {
                            if(a[j][i]==0)
                            {
                                a[j][i]=y;
                                return 1;
                            }
                        }
                    }
                    else
                    {
                        for(j=2;j>=0;j--)
                        {
                            if(a[j][i]==0)
                            {
                                a[j][i]=y;
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

void ttt::ai(int b)
{
    if(!defend(y,t,b))
    {
        if(!defend(t,y,b))
        {
            if((a[0][0]+a[0][2]+a[2][0]+a[2][2]==t+y||
            a[0][0]+a[0][2]+a[2][0]+a[2][2]==t+2*y)&&a[1][1]==0)
            {
                for(int i=0;i<3;i+=2)
                {
                    for(int j=0;j<3;j+=2)
                        if(a[i][j]==0)
                        {
                            a[i][j]=y;
                            goto end;
                        }
                }

            }
            else if(b==2&&a[1][1]==0)
            {
                a[1][1]=y;
                goto end;
            }
            if(!attack())
            {
                if(b==0)
                {
                    randomize();
                    a[(random(3)%2)*2][(random(3)%2)*2]=y;
                    goto end;
                }
                else
                if(a[1][1]==0)
                {
                    a[1][1]=y;
                    goto end;
                }
                else
                {
                    int i,j;
                    for(i=0;i<3;i++)
                    {
                        for(j=0;j<3;j++)
                        {
                            if(a[i][j]==0)
                            {
                                a[i][j]=y;
                                goto end;
                            }
                        }
                    }
                }
            }
        }
    }
end:
    cout<<endl;
}

int ttt::st()
{
start:
    int i,j;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            a[i][j]=0;
    if(game==1)
    {
        cout<<"\n  What is your good name? ";
        gets(name);
        cout<<"\n  Hi "<<name;
        cout<<"  wanna play tic tac toe?\n  Let's see who will win";
        cout<<"\n  "<<name<<" wanna go 1st or 2nd? : ";
    }
    else
    {
        cout<<"\n  Wanna go 1st or 2nd : ";
    }

input:
    cin>>t;
    switch(t)
    {
        case 1:
            y=2;
            cout<<"\n  So your symbol is X.\n  And mine is O.";
            cout<<"\n\n  Let's start the game.";
            getch();
            print();
            for(i=0;i<9;)
            {
                pin();
                print();
                i++;
                if(i>4)
                    if(check())
                    {
                        cout<<"  oh you won "<<name<<endl;
                        win += 1;
                        break;
                    }
                if(i>=8)
                    break;
                ai(i);
                print();
                i++;
                if(i>5)
                    if(check())
                    {
                        strcpy(str,"\n  It is impossible to beat me ");
                        strcat(str,name);
                        cout<<str<<endl;
                        lose += 1;
                        break;
                    }
            }
            break;

        case 2:
            y=1;
            cout<<"\n  So your symbol is O.\n  And mine is X.";
            cout<<"\n\n  Let's start the game.";
            getch();
            print();
            for(i=0;i<9;)
            {
                ai(i);
                print();
                i++;
                if(i>4)
                    if(check())
                    {
                        strcpy(str,"  It is impossible to beat me ");
                        strcat(str,name);
                        cout<<str<<endl;
                        lose += 1;
                        break;
                    }
                if(i>=8)
                    break;
                pin();
                print();
                i++;
                if(i>5)
                    if(check())
                    {
                        cout<<"  oh you won "<<name<<endl;
                        win += 1;
                        break;
                    }
            }
            break;
        default:
            strcpy(str,"  Hey, ");
            strcat(str,name);
            strcat(str," you need to enter either 1 or 2.");
            puts(str);
            cout<<"\n  Enter again: ";
            goto input;
    }
    if(!check())
    {
    	cout<<"  Well Played!\n  It is a tie.\n";
      tie += 1;
    }
    char c;
    cout<<"  do u wanna play again "<<name<<"(y/n) : ";
    cin>>c;
    if(c=='y'||c=='Y')
    {
        game++;
        clrscr();
        goto start;
    }
    else
         return 0;
}
int ttt::store(){
	ofstream ofs;
	ttie +=tie;
	twin +=win;
	tlose +=lose;
   ofs.open("savee.txt");
   ofs<<"LAST USER : "<<name<<endl;
   ofs<<"NO OF TIES IN TOTAL : "<<ttie<<endl;
   ofs<<"NO OF WINS IN TOTAL : "<<twin<<endl;
   ofs<<"NO OF LOSE IN TOTAL : "<<tlose<<endl;
   ofs.close();
   return 0;
}
int ttt::loadval(){
	ifstream ifs;
   int fgs=-1;
   char ch;
   bool vol;
   ifs.open("savee.txt");
   while(!ifs.eof())
   {
   	ifs.get(ch);
      if(isdigit(ch)){
      	fgs++;
         vol = 1;
      }
      else
      	vol = 0;
      if(fgs==0&&vol==1)
         ttie=atoi(&ch);
      else if(fgs==1&&vol==1)
         twin=atoi(&ch);
      else if(fgs==2&&vol==1)
         tlose=atoi(&ch);
   }
   return 0;
}
int ttt::showdt()
{
   char chx[100];
   int i = 4;
   ifstream fs;
	fs.open("savee.txt");
   cout<<"\n  Records : ";
   while(!fs.eof())
   {
   	fs.getline(chx,50);
      gotoxy(4,i);
      if(strcmp(chx,"000")==0){
      	cout<<"Empty";
         break;
      }
      else
      	cout<<(chx);
      i++;
   }
   fs.close();
   return 0;
}
int ttt::ifexist(){
	ofstream oofs;
   oofs.open("savee.txt");
   if(oofs.fail()){
   	for(int i = 0;i<3;i++){
      	oofs<<"0";
      }
   }
   oofs.close();
   return 0;
}
int ttt::delrec(){
	ofstream o1fs;
   o1fs.open("savee.txt");
   {
   	for(int i = 0;i<3;i++){
      	o1fs<<"0";
      }
   }
   o1fs.close();
   return 0;
}
void main()
{
   int p = 1;
   while(p)
   {
   	char sh;
      clrscr();
      gotoxy(8,2);
      cout<<"Project AIO";
   	gotoxy(7,3);
		cout<<" Main menu : "<<endl;
      cout<<endl;
   	cout<<"  1. Calculator"<<endl;
      cout<<"  2. Matrix calculator"<<endl;
   	cout<<"  3. Games"<<endl;
   	cout<<"  4. File reader"<<endl;
   	cout<<"  5. Notepad"<<endl;
   	cout<<"  6. Exit"<<endl;
   	sh = getch();
   	switch(sh)
   	{
      case '1':
      {
         int ch2=1;
         while(ch2)
         {
         double x,y,val,PI=3.14159265;
         val = PI / 180;
         char z;
         clrscr();
         gotoxy(16,4);
      	cout<<"Calculator : "<<endl;
         gotoxy(6,6);
         cout<<"1./"<<endl;
         gotoxy(16,6);
         cout<<"2.*"<<endl;
         gotoxy(26,6);
         cout<<"3.-"<<endl;
         gotoxy(36,6);
         cout<<"4.+"<<endl;
         gotoxy(6,8);
         cout<<"5.pow"<<endl;
         gotoxy(16,8);
         cout<<"6.log"<<endl;
      	gotoxy(26,8);
         cout<<"7.ln"<<endl;
         gotoxy(36,8);
         cout<<"8.sin"<<endl;
         gotoxy(6,10);
         cout<<"9.cos"<<endl;
         gotoxy(16,10);
         cout<<"0.tan"<<endl;
         gotoxy(26,10);
         cout<<"a.sqr"<<endl;
         gotoxy(36,10);
         cout<<"b.cbr"<<endl;
         gotoxy(6,12);
         cout<<"c.root"<<endl;
         gotoxy(16,12);
         cout<<"d.!"<<endl;
         gotoxy(26,12);
         cout<<"e.exp "<<endl;
         gotoxy(6,14);
         cout<<"enter any operator"<<endl;
         gotoxy(30,21);
         cout<<"x -> exit"<<endl;
         z=getch();
         if(z=='1')
         {
            gotoxy(6,15);
         	cout<<"enter no  :  ";
         	cin>>x;
            gotoxy(6,16);
         	cout<<"enter 2nd no  :  ";
            cin>>y;
            gotoxy(6,17);
            cout<<x<<" / "<<y<<"  =  "<<(x/y);
         }
         else
         if(z=='2')
         {
            gotoxy(6,15);
         	cout<<"enter no  :  ";
         	cin>>x;
         	gotoxy(6,16);
         	cout<<"enter 2nd no  :  ";
            cin>>y;
            gotoxy(6,17);
            cout<<x<<" * "<<y<<"  =  "<<(x*y);
         }
         else
         if(z=='3')
         {
            gotoxy(6,15);
         	cout<<"enter no  :  ";
         	cin>>x;
         	gotoxy(6,16);
         	cout<<"enter 2nd no  :  ";
            cin>>y;
            gotoxy(6,17);
            cout<<x<<" - "<<y<<"  =  "<<(x-y);
         }
         else
         if(z=='4')
         {
            gotoxy(6,15);
         	cout<<"enter no  :  ";
         	cin>>x;
         	gotoxy(6,16);
         	cout<<"enter 2nd no  :  ";
            cin>>y;
            gotoxy(6,17);
            cout<<x<<" + "<<y<<"  =  "<<(x+y);
         }
         else
         if(z=='5')
         {
            gotoxy(6,15);
         	cout<<"enter no  :  ";
         	cin>>x;
         	gotoxy(6,16);
         	cout<<"enter its power  :  ";
            cin>>y;
            gotoxy(6,17);
            cout<<x<<"^"<<y<<"  =  "<<pow(x,y);
         }
         else
         if(z=='6')
         {
            gotoxy(6,15);
         	cout<<"enter no  :  ";
         	cin>>x;
         	gotoxy(6,16);
            cout<<"log("<<x<<")"<<" = "<<log10(x);
         }
         else
         if(z=='7')
         {
            gotoxy(6,15);
         	cout<<"enter no  :  ";
         	cin>>x;
         	gotoxy(6,16);
            cout<<"Naturallog("<<x<<")"<<" = "<<log(x);
         }
         else
         if(z=='8')
         {
            gotoxy(6,15);
         	cout<<"enter in deg  :  ";
         	cin>>x;
         	gotoxy(6,16);
            if(x==0)
            	cout<<"sin(0) = 0"<<endl;
            else
            	cout<<"sin("<<x<<")"<<" = "<<sin(x*val);
         }
         else
         if(z=='9')
         {
            gotoxy(6,15);
         	cout<<"enter in deg  :  ";
         	cin>>x;
         	gotoxy(6,16);
            if(x==90)
            	cout<<"cos(90) = 0"<<endl;
            else
            	cout<<"cos("<<x<<")"<<" = "<<cos(x*val);
         }
         else
         if(z=='0')
         {
            gotoxy(6,15);
            cout<<"enter in deg  :  ";
         	cin>>x;
         	gotoxy(6,16);
            if(x==90){
            	char p=236;
            	cout<<"tan(90) = "<<p;
            }
            else
            	cout<<"tan("<<x<<") = "<<tan(x*val);
         }
         else
         if(z=='a')
         {
            gotoxy(6,15);
         	cout<<"enter no  :  ";
         	cin>>x;
         	gotoxy(6,16);
            cout<<"root of "<<x<<" = "<<pow(x,0.5);
         }
         else
         if(z=='d')
         {
            gotoxy(6,15);
         	cout<<"enter no  :  ";
         	cin>>x;
         	gotoxy(6,16);
            cout<<x<<"! = "<<fac(x);
         }
         else
         if(z=='c')
         {
            gotoxy(6,15);
         	cout<<"enter no  :  ";
         	cin>>x;
         	gotoxy(6,16);
         	cout<<"enter its root number  :  ";
            cin>>y;
            gotoxy(6,17);
            cout<<y<<" root "<<x<<" = "<<root(x,y);
         }
         else
         if(z=='b')
         {
            gotoxy(6,15);
         	cout<<"enter no  :  ";
         	cin>>x;
         	gotoxy(6,16);
            cout<<"cube root of "<<x<<" = "<<cbr(x);
         }
         else
         if(z=='e')
         {
         	gotoxy(6,15);
         	cout<<"enter no  :  ";
         	cin>>x;
         	gotoxy(6,16);
            if(x > 709){
            	char pp=236;
            	cout<<"exp("<<x<<") = "<<pp;
            }
            else
            	cout<<"exp("<<x<<") = "<<exp(x);
         }
         else
         if(z=='x')
         {
         	ch2 = 0;
            break;
         }
         else
         {
         	gotoxy(6,15);
         	cout<<"invalid option";
         }
         cout<<endl;
         gotoxy(5,18);
         getch();
         }
         break;
     	 	}
         case '2':
      	{
         int coe = 1;
         while(coe)
         {
      	clrscr();
			int x;
         gotoxy(7,3);
         cout<<"Matrix calculator : "<<endl;
         cout<<endl;
   		cout<<"  1. add matrix"<<endl;
   		cout<<"  2. sum of row`s and sum of column's"<<endl;
   		cout<<"  3. addition of above diagonal and bellow diagnal"<<endl;
   		cout<<"  4. sum of diagonal"<<endl;
         cout<<"  5. exit"<<endl;
   		x=getch();
   		switch(x)
         {
   			case '1':
      		{
            	char mx;
               do
               {
               char gx;
               clrscr();
   				int f,n[10],m[10],a[10][10][10],i,j,k;
         		cout<<"the numbers of matrix : ";
         		cin>>f;
         		for(k=0;k<f;k++)
         		{
         			cout<<"enter the no of row's for "<<(k+1)<<" matrix : ";
            		cin>>n[k];
         		}
         		for(k=0;k<f;k++)
         		{
         			cout<<"enter the no of column's for "<<(k+1)<<" matrix : ";
            		cin>>m[k];
         		}
         		for(k=0;k<f;k++)
         		{
            		cout<<"enter value for matrix "<<(k+1)<<endl;
         			for(i=0;i<n[k];i++)
            		{
            			for(j=0;j<m[k];j++)
               		{
               			cin>>a[k][i][j];
               		}
            		}
         		}
         		matrixfuncl(f,a,n,m);
               cout<<"y to continue again e to exit"<<endl;
               gx=getch();
               if(gx == 'y')
               {
               	mx='y';
               }
               else if(gx == 'e')
               {
               	mx='n';
               }
         		}
               while(mx=='y');
               break;
      		}
      		case '2':
      		{
               char mx;
               do
               {
               char gx;
               clrscr();
      			int a[10][10],i,j,m,n;
					cout<<"enter no of row's for matrix : ";
         		cin>>m;
         		cout<<"enter no of column's for matrix : ";
         		cin>>n;
         		cout<<"enter values for matrix : "<<endl;
         		for(i=0;i<m;i++)
         		{
         			for(j=0;j<n;j++)
            		{
            			cin>>a[i][j];
            		}
         		}
         		matrixfunc2(m,n,a);
               cout<<"y to continue again e to exit"<<endl;
               gx=getch();
               if(gx == 'y')
               {
               	mx='y';
               }
               else if(gx == 'e')
               {
               	mx='n';
               }
         		}
               while(mx=='y');
         		break;
            }
      		case '3':
      		{
               char mx;
               do
               {
               char gx;
      			clrscr();
               int a[10][10],i,j,m,n;
					cout<<"enter no of row's for matrix : ";
         		cin>>m;
         		cout<<"enter no of column's for matrix : ";
         		cin>>n;
               cout<<"enter values for matrix : "<<endl;
         		for(i=0;i<m;i++)
         		{
         			for(j=0;j<n;j++)
            		{
            			cin>>a[i][j];
            		}
               }
         		matrixfunc3(m,n,a);
         		cout<<"y to continue again e to exit"<<endl;
               gx=getch();
               if(gx == 'y')
               {
               	mx='y';
               }
               else if(gx == 'e')
               {
               	mx='n';
               }
         		}
               while(mx=='y');
         		break;
      		}
      		case '4':
      		{
               int jio = 1;
               while(jio)
               {
         		clrscr();
      			int w;
               gotoxy(7,3);
               cout<<"Matrix calculator : "<<endl;
               cout<<endl;
         		cout<<"  1.Sum of left diagonal"<<endl;
         		cout<<"  2.Sum of right diagonal"<<endl;
               cout<<"  3.Exit"<<endl;
         		w=getch();
         		switch(w)
         		{
         			case '1':
            		{
                     char mx;
               		do
               		{
               		char gx;
                     clrscr();
            			int a[10][10],i,j,m,n;
							cout<<"enter no of row's for matrix : ";
         				cin>>m;
         				cout<<"enter no of column's for matrix : ";
         				cin>>n;
         				cout<<"enter values for matrix : "<<endl;
         				for(i=0;i<m;i++)
                  	{
         					for(j=0;j<n;j++)
                     	{
            					cin>>a[i][j];
                     	}
         				}
         				matrixfunc4_1(m,n,a);
               		cout<<"y to continue again e to exit"<<endl;
                 		gx=getch();
               		if(gx == 'y')
               		{
               			mx='y';
               		}
               		else if(gx == 'e')
              	 		{
               			mx='n';
               		}
                     }
               		while(mx=='y');
							break;
                  }
                  case '2':
                  {
                     char mx;
               		do
               		{
               		char gx;
                     clrscr();
                  	int a[10][10],i,j,m,n;
							cout<<"enter no of row's for matrix : ";
         				cin>>m;
         				cout<<"enter no of column's for matrix : ";
         				cin>>n;
         				cout<<"enter values for matrix : "<<endl;
         				for(i=0;i<m;i++)
               		{
         					for(j=0;j<n;j++)
                  		{
            					cin>>a[i][j];
            				}
         				}
         				matrixfunc4_2(m,n,a);
               		cout<<"y to continue again e to exit"<<endl;
                 		gx=getch();
               		if(gx == 'y')
               		{
               			mx='y';
               		}
               		else if(gx == 'e')
              	 		{
               			mx='n';
               		}
         				}
               		while(mx=='y');
							break;
            		}
                  case '3':
                  {
                  	jio = 0;
                     break;
                  }
                  default:
                  {
                  	cout<<"  Invalid option";
                     getch();
                     break;
                  }
               }
               }
               break;
            }
            case '5':
            {
            	coe = 0;
               break;
            }
      		default:
      		{
      			cout<<"  invalid option"<<endl;
               getch();
         		break;
      		}
            }
         }
         break;
         }
         case '3':{
            ttt t1;
            char swit;
				int vald = 1;
            while(vald){
            win = lose = tie = 0;
            game = 1;
            clrscr();
            gotoxy(7,3);
            cout<<"Games : "<<endl;
            cout<<endl;
            cout<<"  1. Play tic tac toe"<<endl;
            cout<<"  2. Show records"<<endl;
            cout<<"  3. Delete records"<<endl;
            cout<<"  4. Exit"<<endl;
            swit = getch();
            switch(swit){
            case '1':
            	clrscr();
               t1.ifexist();
               t1.st();
               cout<<"  No of wins in this match : "<<win<<endl;
    				cout<<"  No of lose in this match : "<<lose<<endl;
    				cout<<"  No of ties in this match : "<<tie<<endl;
               getch();
               t1.loadval();
               t1.store();
               break;
            case '2':
            	clrscr();
               t1.showdt();
               cout<<endl;
               getch();
               break;
            case '3':
            	cout<<"  Done"<<endl;
               t1.delrec();
               getch();
               break;
            case '4':
            	vald = 0;
               break;
            default:
            	cout<<"\nwrong option. Try again"<<endl;
               getch();
               break;
            }
            }
            break;
         }
         case '4':{
            int valid=1;
            char pico;
            while(valid){
         	int i = 7;
            system("cls");
            ifstream op;
            gotoxy(5,3);
            char cac[100];
            char filename[50];
            cout<<"explorer v1.0 :"<<endl;
            gotoxy(3,5);
            cout<<"enter the file name : ";
            gets(filename);
            op.open(filename);
            if(!op.fail()){
            	while(!op.eof()){
            		op.getline(cac,900);
                  gotoxy(3,i);
               	puts(cac);
                  i++;
            }
            }
            else
            	cout<<"  file does not exist"<<endl;
            op.close();
            getch();
            cout<<"  do you wanna see anything else(y/n) : ";
            pico = getch();
            	if(pico!='y')
               	valid = 0;
            }
           	break;
         }
         case '5':{
            int vali,cmo,rmo,nmo,i;
            char pio,pmh;
            vali = 1;
            while(vali){
            cmo = rmo = nmo = 1;
            i = 7;
            system("cls");
            ifstream opmm;
            ofstream opmm1;
            ofstream opmm2;
            ofstream opmm3;
            char line[100];
            char filenam[50];
            gotoxy(5,3);
            cout<<"notepad v1.0 : \t\t\t\t\t\t type /exit to exit"<<endl;
            gotoxy(3,5);
            cout<<"enter the filename : ";
            gets(filenam);
            opmm.open(filenam);
            if(!opmm.fail()){
            	cout<<"  file exist do you wanna overwrite(y/n) : ";
               cin>>pmh;
               if(pmh == 'y'){
                  opmm2.open(filenam);
                  while(cmo){
                  gotoxy(3,i);
                  gets(line);
                  if(strcmp(line,"/exit")==0)
                  	cmo = 0;
                  else
               		opmm2<<line<<endl;
                  i++;
                  }
                  opmm2.close();
               }
               else{
            		opmm1.open(filenam,ios::app);
                  while(rmo){
                  gotoxy(3,i);
                  gets(line);
                  if(strcmp(line,"/exit")==0)
                  	rmo = 0;
                  else
               		opmm1<<line<<endl;
                  i++;
                  }
                  opmm1.close();
               }
            }
            else if(opmm.fail()){
            	cout<<"  file doesn't exist creating new file : "<<endl;
               opmm3.open(filenam);
               while(nmo){
               	gotoxy(3,i);
                  gets(line);
                  if(strcmp(line,"/exit")==0)
                  	nmo = 0;
                  else
            			opmm3<<line<<endl;
                  i++;
               }
               opmm3.close();
            }
            opmm.close();
            getch();
            cout<<"  do you wanna write anything else(y/n) : ";
            pio = getch();
            	if(pio!='y')
               	vali = 0;
            }
            break;
         }
         case '6':
         	p=0;
            getch();
            break;
         default:
         	cout<<"invalid option. Try again";
            getch();
            break;
   	}
   }
}
int matrixfuncl(int f,int b[10][10][10],int p[10],int q[10])
{
   int s,l,m;
	for(s=0;s<f;s++)
   {
      cout<<"The matrix "<<(s+1)<<" is "<<endl;
      for(l=0;l<p[s];l++)
      {
         for(m=0;m<q[s];m++)
         {
            cout<<b[s][l][m]<<"\t";
         }
         cout<<endl;
      }
   }
   for(l=0;l<p[f-1];l++)
   {
      for(m=0;m<q[f-1];m++)
      {
         for(s=1;s<f;s++)
         {
         	b[0][l][m]=b[0][l][m]+b[s][l][m];
         }
      }
	}
   cout<<endl<<"the sum of matix is "<<endl;
   for(l=0;l<p[f-1];l++)
   {
   	for(m=0;m<q[f-1];m++)
      {
         cout<<b[0][l][m]<<"\t";
      }
      cout<<endl;
   }
   return 0;
}

int matrixfunc2(int q,int p,int b[10][10])
{
	int a,s,r[10],c[10];
   cout<<"The matrix is "<<endl;
   for(a=0;a<q;a++)
   {
   	for(s=0;s<p;s++)
      {
      	cout<<b[a][s]<<"\t";
      }
      cout<<endl;
   }
   for(a=0;a<q;a++)
   {
   	r[a]=0;
      for(s=0;s<p;s++)
      {
      	r[a]=r[a]+b[a][s];
      }
   }
   for(s=0;s<p;s++)
   {
   	c[s]=0;
      for(a=0;a<q;a++)
      {
      	c[s]=c[s]+b[a][s];
      }
   }
   for(a=0;a<q;a++)
   {
   	cout<<"The sum of row "<<(a+1)<<" is : "<<r[a]<<endl;
   }
   for(s=0;s<p;s++)
   {
   	cout<<"The sum of column "<<(s+1)<<" is : "<<c[s]<<endl;
   }
   return 0;
}

int matrixfunc3(int q,int p,int b[10][10])
{
   int a,s,sabove=0,sbelow=0;
	cout<<"The matrix is "<<endl;
   for(a=0;a<q;a++)
   {
   	for(s=0;s<p;s++)
      {
      	cout<<b[a][s]<<"\t";
      }
      cout<<endl;
   }
   for(a=0;a<q;a++)
   {
   	for(s=0;s<p;s++)
      {
      	if(a>s)
         	sbelow = sbelow + b[a][s];
         else
         	if(a<s)
         		sabove = sabove + b[a][s];
      }
   }
   cout<<"Sum of above diagonal is : "<<sabove<<endl;
   cout<<"Sum of below diagonal is : "<<sbelow<<endl;
   return 0;
}

int matrixfunc4_1(int q,int p,int b[10][10])
{
	int a,s,sdiog=0;
	cout<<"The matrix is "<<endl;
   for(a=0;a<q;a++)
   {
   	for(s=0;s<p;s++)
      {
      	cout<<b[a][s]<<"\t";
      }
      cout<<endl;
   }
   for(a=0;a<q;a++)
   {
   	for(s=0;s<p;s++)
      {
      	if(a==s)
         	sdiog += b[a][s];
      }
   }
   cout<<"The sum of diagonal is : ";
   cout<<sdiog<<endl;
   return 0;
}

int matrixfunc4_2(int q,int p,int b[10][10])
{
	int a,s,sdiog=0;
	cout<<"The matrix is "<<endl;
   for(a=0;a<q;a++)
   {
   	for(s=0;s<p;s++)
      {
      	cout<<b[a][s]<<"\t";
      }
      cout<<endl;
   }
   for(a=0;a<q;a++)
   {
   	for(s=0;s<p;s++)
      {
      	if((a+s)==q-1)
         {
         	sdiog = sdiog + b[a][s];
			}
      }
   }
   cout<<"The sum of diagonal is : "<<sdiog<<endl;
   return 0;
}
int fac(int a)
{
   int s,m=1;
   for(s=a;s>=1;s--)
   {
      m=m*s;
   }
   return m;
}
float cbr(float x)
{
   float m;
   m = pow(x,1.0/3);
   return m;
}
float root(float b,float c)
{
   float z,x;
   z=1/c;
   x=pow(b,z);
   return x;
}

