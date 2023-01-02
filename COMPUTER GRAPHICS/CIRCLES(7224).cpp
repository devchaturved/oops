#include<bits/stdc++.h>
#include<GL/glut.h>
using namespace std;

int initial=0;
class circle
{
public:
	int Ax=50,Ay=50,r=100,count;
	void drawCircle(int,int,int,int);
	void Bresenham(int,int,int);
	void DDA(int,int,int);
	 void midPointCircleDraw(int x_centre, int y_centre, int r)
{
    int x = r, y = 0;
    cout << "(" << x + x_centre << ", " << y + y_centre << ") ";
    if (r > 0)
    {
        cout << "(" << x + x_centre << ", " << -y + y_centre << ") ";
        cout << "(" << y + x_centre << ", " << x + y_centre << ") ";
        cout << "(" << -y + x_centre << ", " << x + y_centre << ")\n";
    }
    int P = 1 - r;
    while (x > y)
    {
        y++;
        if (P <= 0)
            P = P + 2*y + 1;
        else
        {
            x--;
            P = P + 2*y - 2*x + 1;
        }
        if (x < y)
            break;
        cout << "(" << x + x_centre << ", " << y + y_centre << ") ";
        cout << "(" << -x + x_centre << ", " << y + y_centre << ") ";
        cout << "(" << x + x_centre << ", " << -y + y_centre << ") ";
        cout << "(" << -x + x_centre << ", " << -y + y_centre << ")\n";

        if (x != y)
        {
            cout << "(" << y + x_centre << ", " << x + y_centre << ") ";
            cout << "(" << -y + x_centre << ", " << x + y_centre << ") ";
            cout << "(" << y + x_centre << ", " << -x + y_centre << ") ";
            cout << "(" << -y + x_centre << ", " << -x + y_centre << ")\n";
        }
    }
}
}l;
void circle::drawCircle(int x,int y,int Ax,int Ay){
    glColor3f(0,1,0);
    glVerteX2i(Ax+x,Ay+y);
    glVerteX2i(Ax+x,Ay-y);
    glVerteX2i(Ax-x,Ay+y);
    glVerteX2i(Ax-x,Ay-y);
    glVerteX2i(Ax+y,Ay+x);
    glVerteX2i(Ax+y,Ay-x);
    glVerteX2i(Ax-y,Ay+x);
    glVerteX2i(Ax-y,Ay-x);
}


void circle::Bresenham(int Ax,int Ay,int r){
    int x=0,y=r,d;
    d=3-2*r;
    while(x<=y){
        if(d>0){x++;y--;d+=4*x-4*y+10;
        }
        else{x++;d+=4*x+6;
        }
        drawCircle(x,y,Ax,Ay);
    }
    Ax=Ay=r=initial=0;
}

void circle::DDA(int xini,int yini ,int rad)
{
	float X1,Y1,initX,initY,X2,Y2;X1=rad;Y1=0;initX=X1;initY=Y1;int val;int i=0;
	do
	{
		val=pow(2,i);
		i++;
	}while(val<rad);

	float e=1/pow(2,i);
	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(10.0,0.0,0.0);
	glBegin(GL_POINTS);
	do
	{X2=X1+Y1*e;Y2=Y1-e*X2;glVerteX2f(xini+X2,yini+Y2);X1=X2;Y1=Y2;
	}while((Y1-initY)<e||(initX-X1)>e);
  glEnd();
  glFlush();
}

void display()
{

if(l.count==-1){
	glBegin(GL_POINTS);
		l.Bresenham(l.Ax,l.Ay,l.r);
    glEnd();
}
if(l.count==1){
	glBegin(GL_POINTS);
		l.DDA(l.Ax,l.Ay,l.r);
    glEnd();
}
	glFlush();
}

void Init()
{
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,640,480,0);
}


void options(int id)
{
    switch(id)
    {
    case 1:
        l.count=1;
        break;
    case 2:
        l.count=-1;
        break;
    case 3:
    	glClear(GL_COLOR_BUFFER_BIT);
    	glFlush();
    	break;
    }
}

int main(int argc,char* argv[])
{
	glutInit(&argc,argv);
	glutInitWindowSize(600,500);
	glutInitWindowPosition(150,150);
	glutCreateWindow("MIDPOINT,BRESENHAM,DDA");

	Init();

	glutDisplayFunc(display);

	glutCreateMenu(options);
		glutAddMenuEntry("-----DDA-----",1);
		glutAddMenuEntry("--Bresenham--",2);
		glutAddMenuEntry("--MIDPOINT--",3);
		glutAddMenuEntry("--Clear--",4);
	    glutAttachMenu(GLUT_RIGHT_BUTTON);
        
	glutMainLoop();
	return 0;
}
