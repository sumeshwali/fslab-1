#include <iostream>
#include<fstream>
#include<sstream>
#include<string.h>
#define MAX 100
using namespace std;

class student{
    string usn,name,sem,branch,buffer;
public:
        void read();
        void write();
        void pack();
        int search(string);
        int dele(string);
        void unpack();
        void modify(string);
};
student s;
void student::read()
{
    cout<<"enter your usn"<<endl;
    cin>>usn;
    cout<<"enter your name"<<endl;
    cin>>name;
    cout<<"enter the branch"<<endl;
    cin>>branch;
    cout<<"enter the sem"<<endl;
    cin>>sem;
}
void student::pack()
{
    string temp;
    fstream f1;
    temp+=usn+'|'+name+'|'+branch+'|'+sem+'$';
    buffer=temp;
    buffer.resize(100,'$');
    f1.open("data.txt",ios::out|ios::app);
    f1<<buffer<<endl;
    f1.close();
}
int student::search(string key)
{
    fstream f1;
    int flag,pos;
    f1.open("data.txt",ios::in);
    while(!f1.eof())
    {
    getline(f1,buffer);
    pos=f1.tellp();
    unpack();
        /*while(buffer[i]!='|')
        {
            name+=buffer[i++];
            i++;
        }
        while(buffer[i]!='|')
        {
            branch+=buffer[i++];
            i++;
        }
        while(buffer[i]!='|')
        {
            sem+=buffer[i++];
            i++;
        }*/
    if(usn==key)
    {
    	flag=1;
     break;
    }

    else
    	flag=0;
    }
    if(flag==1)
    cout<<"found \n";
    else
    	cout<<"not found\n";
  return pos;


}
void student::unpack()
{
    int i=0;
    usn.erase();
        while(buffer[i]!='|')
            usn+=buffer[i++];
            i++;
            while(buffer[i]!='|')
                name+=buffer[i++];
                   i++;
                        while(buffer[i]!='|')
                             branch+=buffer[i++];
                                    i++;
                                    while(buffer[i]!='$')
                                        sem+=buffer[i++];
                                           i++;
}
void student::modify(string key)
{
	int ch,pos;
	string temp;
	fstream f1;
	pos=search(key);
	pos=pos-101;
	cout<<"enter the feild to be modified";
	cout<<"1.usn\n2.name\n3.branch\n4.sem\n";
	cin>>ch;
	switch(ch)
	{
	case 1:
		cout<<"enter the usn to be modified\n";
		cin>>usn;
		break;
	case 2:
			cout<<"enter the name to be modified\n";
			cin>>name;
			break;
	case 3:
			cout<<"enter the branch to be modified\n";
			cin>>branch;
			break;
	case 4:
			cout<<"enter the sem to be modified\n";
			cin>>sem;
			break;
	}
	temp.erase();
	f1.open("data.txt");
    temp+=usn+'|'+name+'|'+branch+'|'+sem;
	 temp.resize(100,'$');
	  f1<<temp<<endl;
	  f1.close();
}

int main() {
    int choice,h;
    string key;
    while(1)
    {
            cout<<"1.INSERT 2.SEARCH 3.MODIFY";
            cout<<"enter your choice";
            cin>>choice;
            switch(choice)
            {
            case 1:s.read();
                    s.pack();
                    break;
            case 2:cout<<"enter key";
                    cin>>key;
                    h=s.search(key);
                   cout<<h;
                    break;
            case 3:cout<<"enter the key";
                   cin>>key;
                   s.modify(key);
                   break;
            }
    }

    return 0;
}

