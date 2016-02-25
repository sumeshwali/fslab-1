#include <iostream>
#include<string>
using namespace std;
class student {\
	string name;
	string usn;
	string branch;
	string semester;
public:
	void readStudentFromConsole() {
		cin.clear();
		cin.ignore(255,'\n');
		cout<<"enter the name";
		getline(cin,name);
		cout<<"enter the usn";
		cin>>usn;
		cout<<"enter the branch";
		cin>>branch;
		cout<<"enter the semester";
		cin>>semester;
	}
		int pack()
		{
			string temp,buffer;
			int lenght;
			temp=name+'|'+usn+'|'+branch+'|'+semester;
			lenght=temp.size();
			buffer=temp;
			for(int i=lenght-1;i<100;i++)
			{
				buffer+='$';
			}
			cout<<buffer;
			return 0;
		}
		int unpack()
		{
			int i=0;
			while(buffer[i]!='|')
				usn+=buffer[i++];
			i++;
			while(buffer[i]!='|')
				name+
		}
};
int main() {
	int a;
	student s;
	//while(1){
		cout<<"enter your choice";
		cin>>a;
		switch(a)
		{
		case 1: s.readStudentFromConsole();
		s.pack();
		break;
		}
}

