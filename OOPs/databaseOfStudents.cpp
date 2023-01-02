#include<iostream>
#include<string>
using namespace std;

int n;
int key;
int flag;

class student {

protected:
	static int count;                         // Static Variable
	int roll_no;
	// char name[10];
	// char Class[10];
	// char division;
	string name, Class, division;
	string DOB;
	// char blood_group[5];
	string blood_group;
	string address;
	string mobile_number;
	//char driving_license_number[20];
	string driving_license_number;

public:
	student()
	{								// default constructor
		roll_no = 0;
	}
	student(int temp)
	{						// Parameter Constructor
		this -> roll_no = temp;
	}
	student(student &temp)
	{					// Copy Constructor
		this -> roll_no = temp.roll_no;
	}
	~student()	
	{
		roll_no = -1;
	}
	int get_roll();
	void getdata();
	void putdata();
	static void showcount()
	{                    // static function
		count = 5;
		cout << student::count << endl;
	}

	friend class lib;
};


class lib {											// Friend class

public:
	void display(student &o){
		cout << o.roll_no << endl;
	}
};

int student::count;


void student::getdata(){
	cout << "Enter roll no.: " << endl;
	cin >> roll_no;

	cout << "Enter Name: " << endl;
	cin >> name;

	cout << "Enter the class: " << endl;
	cin >> Class;

	cout << "Enter division: " << endl;
	cin >> division;

	cout << "Enter date of birth: " << endl;
	cin >> DOB;

	cout << "Enter blood group: " << endl;
	cin >> blood_group;

	cout << "Enter mobile number: " << endl;
	cin >> mobile_number;

	cout << "Enter driving license number: " << endl;
	cin >> driving_license_number;
	cin.ignore();

	cout << "Enter address: " << endl;
	getline(cin, address);
	cin.ignore();
}

inline void student::putdata() {

	cout << "Roll no, name, DOB is " << roll_no << " " << name << " " << DOB << endl;
	cout << "Class, division, blood group is " << Class << " " << division << " " << blood_group << endl;
	cout << "Mobile number, driving license number is " << mobile_number << " " << driving_license_number << endl;
	cout << "Address is " << address << endl;
}

void search(student s[], int n){
	flag = 0;

	cout << "Enter the roll no of student to search " << endl;
	cin >> key;

	for(int i = 0; i < n; i++){
		if(s[i].get_roll() == key){
			cout << "Details of searched student are: " << endl;
			s[i].putdata();
			flag = 1;
		}
	}

	if(flag == 0)
		cout << "Roll no not found" << endl;
}

int student::get_roll(){
	return roll_no;
}

int main()
{
	lib l;
	student s[10];
	cout << "Enter n: " << endl;						// Number of students
	cin >> n;

	for(int i = 0; i < n; i++)
		s[i].getdata();
	cout << endl;

	if(n > 0){
		cout << "Student details are " << endl;
	}

	for(int i = 0; i < n; i++){
		s[i].putdata();
		cout << endl;
	}

	search(s, n);
	cout << endl;
	student x(15);									// Call for parameter constructor
	student t(x);									// Call for copy constructor

	if(n > 0){
		l.display(s[0]);
	}
	s[0].showcount();
	return 0;
}







