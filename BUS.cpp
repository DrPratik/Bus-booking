//*****************************************
/*MINIPROJECT
           BUS BOOKING SYSTEM
 VIPUL BHAGWAT     SECOC306
 PRATIK DHORE      SECOC313
 AAYUSH GATTAWAR   SECOC318
 AMOL MARATHE      SECOC339
 © All rights are reserved
*/
//***************************************** 

#include <iostream>
#include<cstdlib>
using namespace std;

struct node
{
    int bit;
    string name;
    long int pin;
    int seat_number;
    node *next;
    node *prev;
};



class bus
{
    int x;
    node *nn;
     int h=1;
public:
    node *header[10];
    bus()
    {
        nn=0;
        for(x=0;x<10;x++)
        {header[x]=NULL;}
    }
    void bus_display(int q,int w);
    void booking();
	void bus1(int q,int w);
	void cancel();
};

//for creating linkedlist
void bus::bus1(int q,int w)
{    
	int i,j;
    for(i=0;i<q;i++)
    {
        for(j=0;j<w;j++)
        {
            nn=new node;
            nn->bit=0;
            nn->name="";
            nn->seat_number=(i+1)*10+j+1;;
            nn->next=nn->prev=NULL;
            if(header[i]==NULL)
            {
                header[i]=nn;
                nn->next=header[i];
                nn->prev=header[i];
            }
            else
            {
                node *cn;
                cn=header[i];
                while(cn->next!=header[i])
                {
                    cn=cn->next;
                }
                nn->next=cn->next;
                cn->next=nn;
                nn->prev=cn;
                header[i]->prev=nn;
            }
        }
    }
}

//for displaying linked list
void bus::bus_display(int q,int w)
{    int i=0;
    cout<<"\n";
    for(i=0;i<q;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<"------";
            if(j==1)
                cout<<"\t";
        }
        cout<<endl;
        int n=0;
        node *cn;
        cn=header[i];
        do
        {
            if(cn->bit==0)
            {
                cout<<"\033[36;40m"<<"| "<<cn->seat_number<<" |"<<"\033[0m";
            }
            else if(cn->bit==1)
                cout<<"\033[35;40m"<<"| ## |"<<"\033[0m";
            n++;
            if(n==2)
                cout<<"\t";
            cn=cn->next;
        }while(cn!=header[i]);
        cout<<"\n";
        
    }
    for(int j=0;j<5;j++)
    {
        cout<<"------";
        if(j==1)
            cout<<"\t";
    }
    cout<<endl;
    cout<<"##=not available\n";
}
//for booking seat
void bus::booking()
{
    int n;

    cout<<"enter the seat number you want to book";
    cin>>n;
    //h++;
    h=rand()%10000;
    {
    	node *cn;
        cn=header[(n/10)-1];
        for(int i=1;i<n%10;i++)
        {
            cn=cn->next;
        }
        if(cn->bit==1)
        {
            cout<<"\n SORRY THIS SEAT IS ALREADY BOOKED \n";
        }
        else
        {
            cout<<"enter name:";
            cin>>cn->name;
            cn->bit=1;
		cn->pin=h;
		cout<<"*****pin is"<<cn->pin<<"*****\n";
		cout<<"save this pin as it is required at the time of cancelation!!!\n";
        }
    }
}

//for cancelling the booking
void bus::cancel()
{
	int n;
	cout<<"enter the seat number for which you want to cancel booking";
	cin>>n;
	{
		node *cn;
		cn=header[(n/10)-1];
		for(int i=1;i<n%10;i++)
		{
			cn=cn->next;
		}
		if(cn->bit==0)
		{
		cout<<"SORRY THIS SEAT IS NOT BOOKED";
		}
		else if(cn->bit==1)
		{
			int flag1=0;
			int f;
			do
			{
				cout<<"enter pin";
				cin>>f;
				if(f==cn->pin)
				{
				cn->bit=0;
				cn->name="";
				}
				else
				{
				cout<<"wrong pin\n";
				flag1++;
				cout<<5-flag1<<"chances are remaining\n";
				}
			}
			while(f!=cn->pin && flag1<5);
			if(flag1==5)
			{			
			cout<<"5 chances are done try again after sometime!\n";
			}
			else
			{
				cout<<"Seat is successfully cancelled!!\n";
			}
		}
	
	}

}


int main()
{
    bus b;
    int con;
	b.bus1(10,5);
    int ch;
		cout<<"\t\t\t"<<"\033[21;44m"<<"BUS BOOKING SYSTEM"<<"\033[0m"<<endl;
		cout<<"-------------------------------------------------------------\n";
    do
    {
        cout<<"1.Display\n2.Booking\n3.cancel booking\n";
        cout<<"enter the choice: \n";
        cin>>ch;
        switch(ch)
        {
            case 1:cout<<"\n \t\t\t*****Bus categories*****\n1.minibus\n2.luxerybus\n3.sleeperbus\nenter choice number:";
			int s;
			cin>>s;
			switch(s)
			{
				case 1:cout<<"\t\t\t"<<"\033[20;44m"<<"MINIBUS"<<"\033[0m"<<endl;b.bus_display(5,4);break;
				case 2:cout<<"\t\t\t"<<"\033[20;44m"<<"LUXERYBUS"<<"\033[0m"<<endl;b.bus_display(10,5);break;
				case 3:cout<<"\t\t\t"<<"\033[20;44m"<<"SLEEPERBUS"<<"\033[0m"<<endl;b.bus_display(4,5);break;
				default:cout<<"Error Found wrong key pressed!!!\n";break;
			}
			break;
            case 2:cout<<"\n \t\t\t*****Bus categories*****\n1.minibus\n2.luxerybus\n3.sleeperbus\nenter choice number:";
			cin>>s;switch(s)
			{
				case 1:cout<<"\t\t\t"<<"\033[20;44m"<<"MINIBUS"<<"\033[0m"<<endl;b.bus_display(5,4);break;
				case 2:cout<<"\t\t\t"<<"\033[20;44m"<<"LUXERYBUS"<<"\033[0m"<<endl;b.bus_display(10,5);break;
				case 3:cout<<"\t\t\t"<<"\033[20;44m"<<"SLEEPERBUS"<<"\033[0m"<<endl;b.bus_display(4,5);break;
				default:cout<<"Error Found wrong key pressed!!!\n";break;
			}
			b.booking();break;
            case 3:cout<<"\n \t\t\t*****Bus categories*****\n1.minibus\n2.luxerybus\n3.sleeperbus\nenter choice number:";
			cin>>s;switch(s)
			{
				case 1:b.bus_display(5,4);break;
				case 2:b.bus_display(10,5);break;
				case 3:b.bus_display(4,5);break;
				default:cout<<"Error Found wrong key pressed!!!\n";break;
			}b.cancel();break;
		default: cout<<"Wrong input\n";break;
        }
        cout<<"do you want to continue";
        cin>>con;
    }while(con==1);
}
