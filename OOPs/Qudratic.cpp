//Program for Quadratic Equation Operation using Operator Overloading Concept.
#include<iostream>
#include<math.h> //used for sqrt function
using namespace std;
class Quadratic 
{
	private :
		int a,b,c,x;
	public:
		Quadratic() { a=b=c=0; }
		Quadratic(int a,int b,int c) 
		{
			this->a=a;
			this->b=b;
			this->c=c;
		}
		//overloaded insertion (<<) opertor
		friend ostream &operator<<(ostream &out, Quadratic &q) 
		{
			out<<"\nQuadratic equation is\t";
			out <<q.a<<" X * X + "<<q.b<<" X +"<<q.c ;
			return out;
		}
		//overloaded extraction (>>) opertor
		friend istream &operator>>(istream &in, Quadratic &q) 
		{
			cout<<"\nEnter values of a,b,c of quadratic equation:\n";
			in>>q.a>>q.b>>q.c;
			return in;
		}
		Quadratic operator +(Quadratic);
		void eval();
		void findRoots();
};
void Quadratic::eval() 
{
	cout<<"\nEnter value of x\n";
	cin>>x;
	int result=(a*x*x)+(b*x)+c;
	cout<<"\nFor x= "<<x<<" Answer is : "<<result<<endl;
}
void Quadratic::findRoots() 
{
	int temp=(b*b)-(4*a*c);
	if(temp>0) 
	{
		float r1=(-b+sqrt(temp))/(2.0*a);
		float r2=(-b-sqrt(temp))/(2.0*a);
		cout<<"\nRoots are real and different";
		cout<<"\nRoot1= "<<r1;
		cout<<"\nRoot2= "<<r2;
	}
	else if(temp==0) 
	{
		cout<<"\nRoots are real and equal";
		float r=(-b+sqrt(temp))/(2.0*a);
		cout<<"\nEqual Roots are"<<r;
	}
	else 
	{
		cout << "\nRoots are complex and different." << endl;
		float real = -b/(2*a);
		float imaginary =sqrt(-temp)/(2*a);
		cout << "Root1 = " << real << "+" << imaginary << "i" << endl;
		cout << "Root2 = " << real << "-" << imaginary << "i" << endl;
	}
}
Quadratic Quadratic::operator +(Quadratic q) 
{
	Quadratic temp;
	temp.a=this->a+q.a;
	temp.b=this->b+q.b;
	temp.c=this->c+q.c;
	return temp;
}
int main()
{
	Quadratic q1,q2,q3;
	cin>>q1;
	cin>>q2;
	q3=q1+q2;
	cout<<"\nQuadratic equation 1, its roots and result\n";
	cout<<q1;
	q1.findRoots();
	q1.eval();
	cout<<"\nQuadratic equation 2, its roots and result\n";
	cout<<q2;
	q2.findRoots();
	q2.eval();
	cout<<"\nQuadratic equation 3, its roots and result\n";
	q3.findRoots();
	q3.eval();
	return 0;
}
