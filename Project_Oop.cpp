#include <iostream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<fstream>
#include <string>
#include <ctime>
#include<time.h>
#include <stdio.h>
#include <Windows.h>
using namespace std;

/*ADMIN PASSWORD: pak123 */

class Voting;

class SystemDisplay       
{
	public:
		char choose;
		void select();
		
		void text_animation(char a[200])       //Text sliding 
{
	int i;
	long double k;
	for(i=0;a[i]!='\0';i++){
		
		
		for(k=0;k<7000000;k++);
		cout<<a[i];
	}
}
	    
friend class Voting;          // using concept of Friend Classes
friend class Admin;
   
};

class Voting
{
	private:
		string cnicnum;
     	string result;
        static int PTI,PMLN,PPP,MQM;                          //vote count for different parties
        static int total;
        static float ptiprcnt;
        static float pmlnprcnt;
        static float pppprcnt;
        static float mqmprcnt;
        int districtcode,sampleN,sampleS,sampleE,sampleW;       //for different districts
        char district;
        string name;
        int age;

	
	public:
		int i;
		char opt;
        Voting(int p,char q):i(p),opt(q)
		{
		}
		
		Voting()
		{}
    
void delay(int a)
{
	int i,j;
	for (i=0; i<a;i++)
		j=i;
}
    
friend class SystemDisplay;
SystemDisplay s1;
 
void cniccheck()                                     /*checks if cnic entered is present in 
                                                     registered voter cnic */ 
{
	ofstream cnicinput;
	cnicinput.open("cnic input.txt",ios::app);
	cnicinput<<" ";
	cnicinput<<cnicnum;
		
	cnicinput.close();	
		
	ifstream cnic;
    cnic.open("cnicoop.txt");
 	if(cnic.is_open())
 	{
 		while(getline(cnic,result))
 		{
 			if(result.find(cnicnum)!=string::npos)
 			{
 				cout<<"\n\n\t\tCNIC NUMBER MATCHED FROM RECORDS.\n\t\tREDIRECTING TO VOTING PAGE";
				for (i = 0; i <=2; i++)
				{
					delay(1000000000);
					cout<<".";
				}
				votingpage();
			}
			
			else
			{
				cout<<"\n\n\t\tYOUR CNIC NUMBER DOES NOT MATCH THE RECORDS\a\a";
		        cout<<"\n\t\tREDIRECTING TO MAIN PAGE";
		        for (i = 0; i <=2; i++)
		        {
		        	delay(1000000000);
		        	cout<<".";
		        }
		        s1.select();	
			}
		}
	}
}

void cnic()                                         /* input of Cnic and checking if vote has already 
                                                    been casted or not */ 
{
	cout<<"\n\t\tEnter your CNIC Number: \t";
	getchar();
	cin>>cnicnum;
	
	ifstream cnicinput;
	cnicinput.open("cnic input.txt");
		
	if(cnicinput.is_open())
	{
		while(getline(cnicinput,result))
		{
			if(result.find(cnicnum)==string::npos)
			{
				cout<<"\n\n\t\tNO VOTE CASTED FOUND ON THIS CNIC";
				cout<<endl<<"\n\t\tCHECKING IF YOUR CNIC IS PRESENT IN REGISTERED VOTERS";
				for (i = 0; i <=2; i++)
				{
					delay(1000000000);
					cout<<".";
		        }
					cniccheck();
			}
			else
			{
				cout<<"\n\n\t\tVOTE HAS ALREADY BEEN CASTED ON THIS CNIC NUMBER.\a\a";
				cout<<"\n\t\tREDIRECTING TO MAIN PAGE";
				
				for (i = 0; i <=2; i++)
				{
					delay(1000000000);
					cout<<".";
				}
		        s1.select();
	        }
        } 
	
    }
}
		
void District()                                 /*Checking the input district and code is valid 
                                                or not */
    {
	cout<<"\n\n\t\tYour District: ";
	cin>>district;
	
	switch(district)
	{
		case 'N':
			cout<<"\n\n\t\tEnter your District code: \t";
			cin>>districtcode;
		    sampleN=42101;
		 	
			if(sampleN==districtcode)
		 	{
		 		cnic();
		 	}
	
		    else
		    {
		    	cout<<"\n\n\t\tYou do not belong to this district";
		    	District(); 
		    }
		break; 
		 
        case 'S':
        	cout<<"\n\n\t\tEnter your District code: \t";
        	cin>>districtcode;
		    sampleS=42102;
		
		    if(sampleS==districtcode)
		    {
		    	cnic();
		    }
		    
		    else
		    {
		    	cout<<"\n\n\t\tYou do not belong to this district";
			    District(); 
		    }
		break;
		
		case 'W':
			cout<<"\n\t\tEnter your District code: \t";
			cin>>districtcode;
			sampleW=42103;
			
			if(sampleW==districtcode)
			{
				cnic();
			}
			
		    else
		    {
		    	cout<<"\n\n\t\tYou do not belong to this district";
			    District(); 
		    }
		break;
		
		case 'E':
			cout<<"\n\n\t\tEnter your District code: \t";
		    cin>>districtcode;
		    sampleE=42104;
		
		    if(sampleE==districtcode)
		    {
		    	cnic();
		    }
		    
		    else
		    {
		    	cout<<"\n\n\t\tYou do not belong to this district";
		    	District(); 
		    }
		break;
		
		case '0':
			system("cls");
	        s1.select();
		break;	
		
		default:
			cout<<"\n\n\t\tWrong Input Detected. Directing to Display page";
			for (i = 0; i <=2; i++)
			{
				delay(1000000000);
				cout<<"";
			}
		    system("cls");
		    s1.select();
		break;
		
	}
}
		
		
void voter()                                      //input information and checking of age
{
	system("cls");
	cout<<"\t\t************************************************";
	cout<<"\n\t\t|                                             |\n";
	cout<<"\n\t\t|                VOTING PAGE                  |\n";
	cout<<"\n\t\t|                                             |\n";
	cout<<"\t\t************************************************";
   
    cout<<"\n\n\n\t\tEnter your Name: \t";
	getchar();
	getline(cin,name);
    
    cout<<"\n\t\tEnter your Age: \t";
    cin>>age;
	
	if(age>=18)
	{
		cout<<"\n\t\tSelect your District";
		cout<<"\n\n\t\tNorth : N\n\t\tSouth : S\n\t\tWest :  W\n\t\tEast :  E\n\n\t\tPress 0 to go back to Main Page";
		District();
	}
	else
	{
		cout<<"\n\n\t\tYou are not Eligible to vote\n\n";
		cout<<"--------------------------------------------------------------------------------";
		cout<<"\n\n\t\tRedirecting to Main Page";
		for (i = 0; i <=2; i++)
		{
			delay(1000000000);
			cout<<".";
		}
		system("cls");
		s1.select();
		
	}

}
	
void votingpage()                 //Casting vote and Calculation of Votes through Filing
{
	char vote[10];
	ofstream individualvotes;
	individualvotes.open("Vote Count.txt",ios::out);
	system("cls");
	cout<<"\n\n\tWelcome to the Online Voting Page of Pakistan\n\n\n";
	cout<<"\t\tAvailable Parties to vote\n\n";
	cout<<"\t\tPakistan Tehreek e Insaaf\n\t\t\t(PTI)\n\t\tPakistan Muslim League Noon\n\t\t\t(PMLN)\n\t\tPakistan Peoples Party\n\t\t\t(PPP)\n\t\tMuttaihada Qaumi Movement\n\t\t\t(MQM)\n\n\n";
	
	cout<<"\tEnter your Choice from the following mentioned above: \t";
	cin>>vote;

    if(strcmp(vote,"PTI")==0)
    {
    	PTI=PTI+1;
    }
    else if(strcmp(vote,"PMLN")==0)
    {
    	PMLN=PMLN+1;
    }
    else if(strcmp(vote,"PPP")==0)
    {
    	PPP=PPP+1;
    }
    else if(strcmp(vote,"MQM")==0)
    {
    	MQM=MQM+1;
    }

    else
    {
    	cout<<"\n\t\tWrong Input Detected.\n\t\t\tReloading the Page.";
    	votingpage();
    }

    total=PTI+PMLN+PPP+MQM;                         //calculating total votes
	                                            
    ptiprcnt= (100*PTI)/total;                       //calculating percentage of votes
    pmlnprcnt= (100*PMLN)/total;
    pppprcnt= (100*PPP)/total;
    mqmprcnt= (100*MQM)/total;
    
    individualvotes<<endl<<"Total votes which has been casted till now is: "<<total;
    individualvotes<<endl<<"Total votes of PTI are: "<<PTI;
    individualvotes<<endl<<"Total votes of PMLN are: "<<PMLN;
    individualvotes<<endl<<"Total votes of PPP are: "<<PPP;
    individualvotes<<endl<<"Total votes of MQM are: "<<MQM;
    
    if((PTI>PMLN)&&(PTI>PPP)&&(PTI>MQM))                    //comparing whose party is leading
    {
    	individualvotes<<endl<<"\n PTI LEADS with "<<PTI<<" votes";
    }
    else if((PMLN>PTI)&&(PMLN>PPP)&&(PMLN>MQM))
    {
    	individualvotes<<endl<<"\n PMLN LEADS with "<<PMLN<<" votes";
    }
    
    else if((PPP>PTI)&&(PPP>PMLN)&&(PPP>MQM))
    {
    	individualvotes<<endl<<"\n PPP LEADS with "<<PPP<<" votes";
    }
    else if((MQM>PTI)&&(MQM>PMLN)&&(MQM>PPP))
    {
	individualvotes<<endl<<"\n MQM LEADS with "<<MQM<<" votes";
    }
    individualvotes.close();

    ofstream percentagevotes;
    percentagevotes.open("Percentage Votes.txt",ios::out);
    percentagevotes<<"\nPercentage of votes gained by PTI: \t"<<ptiprcnt<<"%";
    percentagevotes<<"\nPercentage of votes gained by PMLN: \t"<<pmlnprcnt<<"%";
    percentagevotes<<"\nPercentage of votes gained by PPP: \t"<<pppprcnt<<"%";
    percentagevotes<<"\nPercentage of votes gained by MQM: \t"<<mqmprcnt<<"%";
    
    percentagevotes.close();
    
	time_t t;                            //printing current time
    time(&t);
    cout<<"\n\n\tYour Vote has been recorded Successfully at "<<ctime(&t)<<"\n\tNext voter to vote now.";
		
	for (i = 0; i <2; i++)
	{
		delay(1000000000);
		cout<<".";
	}
	s1.select();
}
   
};

class Admin: public Voting                   // INHERITANCE 
{
	private:
		friend class SystemDisplay;
		SystemDisplay s2;
	
	public:
		Admin(int p,char q):Voting(p,q)      //parameterized constructor
		{
		}
		
		Admin()
		{}
		
	    void adminstats()                 //admin selecting the desired option
	    {
	    	system("cls");
	    	cout<<"\t\t***********************************************";
	    	cout<<"\n\t\t|                                             |\n";
	    	cout<<"\n\t\t|             ADMINISTRATIVE PAGE             |\n";
	    	cout<<"\n\t\t|                                             |\n";
	    	cout<<"\t\t***********************************************";
	    	cout<<" \n\n\t\t 1. Vote Counts \n\n\t\t 2. Percentage of Votes \n\n\t\t 3. End Voting and Display Results ";
	    	cout<<"\n\n\t Enter the Option You want to Select";
	    	cout<<endl<<"\t Enter any other Character to Redirect to Main page: ";
            cin>>opt;
 
        switch(opt)
        { 
        	case '1':                                         
        		cout<<"\n\n\t LOADING THE TOTAL VOTES PAGE"; 
        		for (i = 0; i <=2; i++)
        		{
        			delay(1000000000);
        			cout<<".";
        		}
 	        votingpage();
 	        break;
 	        
 	        case '2':                                            
 	        	cout<<"\n\n\t LOADING THE TOTAL VOTING PERCENTAGE PAGE";
 	        	for (i = 0; i <=2; i++)
 	        	{
 	        		delay(1000000000);
 	        		cout<<".";
 	        	}
 	            percentagecount();
 	            break;
 	
 	        case '3':
 	        	system("cls");                    
 	        	cout<<endl<<endl<<endl<<"\tAre you Sure you want to End the Voting and Display Results?"<<endl;
 	        	cout<<endl<<endl<<endl<<"\t\tPress 1 to Acknowledge Yes"<<endl;
 	        	cout<<endl<<"\t\tPress 2 to Go Back"<<endl;
 	        	cout<<endl<<endl<<endl<<"\t\t\tYour Choice: ";
 	        	cin>>opt;
 	
 	    switch(opt)
 	    {
 	    	case '1':
 	    		cout<<"\n\tDISPLAYING RESULTS AND ENDING THE VOTING PAGE";
 	    		for (i = 0; i <=2; i++)
 	    		{
 	    			delay(1000000000);
 	    			cout<<".";
 	    		}
		        displayresults();
		        exit(1);
		        break;
		        
		        case '2':
		        	cout<<"\n\t\tRedirecting to Admin Page";
		        	for (i = 0; i <=2; i++)
		        	{
		        		delay(1000000000);
		        		cout<<".";
		        	}
			        system("cls");
			        adminstats();
		            break;
		            
		        default:
		        	cout<<"\n\n\t\tRedirecting to Admin Page";
		        	for (i = 0; i <=2; i++)
		        	{
		        		delay(1000000000);
		        		cout<<".";
		        	}
		        	system("cls");
		        	adminstats();
					break;
	    }
 			
 	 	 	
 	        default:
 	        	system("cls");
 	        	s2.select();
 	        	break;
 		
        }
	
}


void votingpage()                          //Polymorphism (Function OverRiding)
{
	system("cls");
	cout<<"\t\t***********************************************";
	cout<<"\n\t\t|                                             |\n";
	cout<<"\n\t\t|             VOTING RESULTS                  |\n";
	cout<<"\n\t\t|                                             |\n";
	cout<<"\t\t***********************************************";
	
	cout<<endl<<endl;
	ifstream individualvotes;
	individualvotes.open("Vote Count.txt",ios::in);
	char ch;
	ch=individualvotes.get();
	
	while(!individualvotes.eof())
	{
		cout<<ch;
		ch=individualvotes.get();
	}
	individualvotes.close();
    cout<<"\n\nEnter '1' to Go back to the Admin Page\n\nEnter '2' to logout and Go back to the Main page \n\n";
	cin>>opt;
		
	switch(opt)
	{
		case '1':
			{
				system("cls");
				adminstats();
			}
				break;
			
			case '2':
				{
					system("cls");
					s2.select();
				}
    }
} 
 
void percentagecount()                           //displaying percentage of votes casted
{
	system("cls");
	cout<<"\t\t***********************************************";
	cout<<"\n\t\t|                                             |\n";
	cout<<"\n\t\t|             VOTING RESULTS                  |\n";
	cout<<"\n\t\t|                                             |\n";
	cout<<"\t\t***********************************************";
	
	cout<<endl<<endl;
	
	ifstream percentagevotes;
	percentagevotes.open("Percentage votes.txt",ios::in);
	char ch2;
	ch2=percentagevotes.get();
	
	while(!percentagevotes.eof())
	{
		cout<<ch2;
		ch2=percentagevotes.get();
	}
	
    percentagevotes.close();
    cout<<"\n\nEnter '1' to Go back to the Admin Page\n\nEnter '2' to Logout and go back to the Main page \n\n";
	cin>>opt;
		
	switch(opt)
	{
		case '1':
			{
				system("cls");
				adminstats();
			}
			break;
			
		case '2':
			{
				system("cls");
				s2.select();
		    }
	}
}

void displayresults()                             //displaying results through Filing and end voting
{
	system("cls");
	cout<<"\t\t***********************************************";
	cout<<"\n\t\t|                                             |\n";
	cout<<"\n\t\t|             VOTING RESULTS                  |\n";
	cout<<"\n\t\t|                                             |\n";
	cout<<"\t\t***********************************************";
	
	cout<<endl<<endl;

    ifstream individualvotes;
    individualvotes.open("Vote Count.txt",ios::in);
    char ch;
    ch=individualvotes.get();
	
	while(!individualvotes.eof())
	{
		cout<<ch;
		ch=individualvotes.get();
	}
	
	cout<<endl;
    ifstream percentagevotes;
	percentagevotes.open("Percentage votes.txt",ios::in);
	char ch2;
	ch2=percentagevotes.get();
	
	while(!percentagevotes.eof())
	{
		cout<<ch2;
		ch2=percentagevotes.get();
	}
	
	time_t t;    
    time(&t);
    cout<<"\n\n\t VOTING HAS BEEN ENDED AT: "<<ctime(&t);
}
};	

void SystemDisplay:: select()               //Selection for Voting and Admin Modules
{
	
   	
   	system("cls");
   	Voting V1(0,'0');
   	Admin A1(0,'0');
   	string password= "pak123";
   	
   	text_animation("\t\t------------------------------------------------");
	cout<<"\n\t\t!!                                             !!\n";
	cout<<"\n\t\t!!                                             !!\n";
	cout<<"\n\t\t!!            ONLINE VOTING SYSTEM             !!\n";
  	cout<<"\n\t\t!!                                             !!\n";
  	cout<<"\n\t\t!!                                             !!\n";
	text_animation("\t\t------------------------------------------------");
	
	cout<<"\n\n\t\t\t   1.Login as Voter ";
	cout<<"\n\t\t\t   2.Login as Administrator";
	
	cout<<"\n\n\t\t\t   Enter your choice: \t ";
	cin>>choose;
    switch(choose)
    {
    	case '1':
    		system("cls");
    		V1.voter();
    	break;
    	
    	case '2':
    		system("cls");
    	    char inputpass[7];
	        char correct;
	        int i;
    
    
    
    cout<<"\n\n\n\n\n\n\n\n\n\n\t\t ENTER THE PASSWORD TO LOGIN:";
   
	for (i=0;i<6;i++)
	{
		char ch;
		ch = getch();
		inputpass[i] = ch;
		cout<<"*";
	}
	
	
	for(i=0;i<7;i++)
	{
		if(inputpass[i]==password[i])
		{
		correct='1';
	    }
	    else
	    {
	    	correct='0';
	    	break;
		}
	
	}
	if(correct=='1')
	{
		cout<<"\n\n\t\t Correct Password \n\t\t Redirecting to Administrative Page";
		
		for (i = 0; i <=2; i++)
		{
			A1.delay(1000000000);
			cout<<".";
		}
		A1.adminstats();	
	
	}
    else
	{
		cout<<"\n\n\t    INCORRECT PASSWORD!!\a\a\a";

		cout<<"\n\nEnter any key to GO BACK to Main Page: \t";
		getch();
		system("cls");
		select();
    }
        break;
        
        default:
    	system("cls");
    	select();
  
    }
     
}	
//initialization of static variables

int Voting::PTI=0;                       
int Voting::PMLN=0;
int Voting::PPP=0;
int Voting::MQM=0;
int Voting::total=0;
float Voting::ptiprcnt=0;
float Voting::pmlnprcnt=0;
float Voting::pppprcnt=0;
float Voting::mqmprcnt=0;

void main()
{
	system("cls");
	system("color 73");
	SystemDisplay s;               // calling of SystemDisplay Class
	s.select();
}
