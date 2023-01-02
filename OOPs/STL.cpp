//Program using STL for Sorting and searching with user-defined records: item record (item code, item name, quantity and cost)
#include <iostream>
#include <set>
#include<iomanip>
using namespace std;
class Item 
{
	public:
	string iname;
	int icode,qty;
	float icost;
	Item(int i,string n,int q,float ic) : iname(n),icode(i),qty(q),icost(ic){};
	bool operator< (const Item& b) const 
	{
		return icode < b.icode;
	}
};
int main() 
{
	int ch;
	char cho;
	string ina;
	int code,qt;
	float cost;
	set<Item> data;
	do
	{
		cout<<"\n\t     Person Database Using Set";
		cout<<"\n\t 1. Insert & Sort Item";
		cout<<"\n\t 2. Search Person By Item Name";
		cout<<"\n\t 3. Search Person By Item code";
		cout<<"\n\t 4. Search Person By Item Cost";
		cout<<"\n\t 5. Display All Items";
		cout<<"\n\t Enter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"\n\t Enter Item:";
					cout<<"\n\t Code:";
					cin>>code;
					cout<<"\n\t Name:";
					cin>>ina;
					cout<<"\n\t Quantity:";
					cin>>qt;
					cout<<"\n\t Cost:";
					cin>>cost;
					data.insert(Item(code,ina,qt,cost));
					break;
			case 2: cout<<"\n\t Enter Item Name for Searching:\n\t";
					cin>>ina;
					for (std::set<Item>::const_iterator it = data.begin();it!=data.end();it++) 
					{				
						if(it->iname==ina)
					        std::cout << it->icode<<", "<<it->iname << ", " << it->qty << "\t"<<it->icost<<endl;
 						else 
					        continue;
					}
					break;
			case 3: cout<<"\n\t Enter Item Code for Searching:\n\t";
					cin>>code;
					for (std::set<Item>::const_iterator it = data.begin();it!=data.end();it++) 
					{				
						if(it->icode==code)
					        std::cout << it->icode<<", "<<it->iname << ", " << it->qty << "\t"<<it->icost<<endl;
 						else 
					        continue;
					}
					break;
			case 4: cout<<"\n\t Enter Item code for Searching:\n\t";
					cin>>cost;
					for (std::set<Item>::const_iterator it = data.begin();it!=data.end();it++) 
					{				
						if(it->icost==cost)
					        std::cout << it->icode<<", "<<it->iname << ", " << it->qty << "\t"<<it->icost<<endl;
 						else 
					        continue;
					}
					break;		
			case 5: cout<<"\t\t List of Items\n";
					cout<<"\t"<<left<<setw(5)<<"CODE"<<left<<setw(15)<<"NAME"<<left<<setw(10)<<"QUANTITY"<<left<<setw(10)<<"COST"<<endl;
					for (std::set<Item>::const_iterator it = data.begin();it!=data.end();it++)
						cout<<"\t" <<left<<setw(5)<<it->icode <<left<<setw(15)<<it->iname<<left<<setw(10)<<it->qty<<left<<setw(10)<<it->icost<<endl;
					break;
			default:cout<<"\n\t Wrong Choice!";
					break;
		}
		cout<<"\n\t Do you want to Continue(Y/N):";
		cin>>cho;
	}while(cho=='y'||cho=='Y');
	return 0;
}
