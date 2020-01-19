//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<fstream.h>
#include<iomanip.h>
#include<string.h>
#include<ctype.h>
struct order
	{
 int bookid1;
 char name1[50];
 char pub1[50];
 int qty1;
 float price1,dis1;
 }o1[50];
 int orderk=0;
void copyfile(int bok1,order o11[],int &c1,int qt2);
void copyme(int k,order order1[],int q1,int &c2);
void intromain();
int getrollno();
void display_all();
void book_tabular();
void modify_record(int n);
void delete_record(int n);
void againopenandclose();
int search(int p);
void changeqty(int pr1,int q11);
//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************

class books
{
 int bookid;
 char name[50];
 char pub[50];
 int qty;
 float price,dis;
 public:
 books()
 {
 qty=0;
 price=0;
 dis=0;
 }
	
 void modifydata(int n1,char snm[15],char pubnm[15],int q);
 //*****************************************************************************
void showdatamulti()
{
  gotoxy(5,7);
  cout<<"======================================================================";
  gotoxy(10,8);
  cout<<"BOOK NO:";
  gotoxy(30,8);
  cout<<bookid;
  gotoxy(40,8);
  cout<<"TITLE OF BOOK:";
  gotoxy(60,8);
  cout<<name;
  gotoxy(10,9);
  cout<<"PUBLISHER:";
  gotoxy(30,9);
  cout<<pub;
  gotoxy(40,9);
  cout<<"BOOK PRICE:";
  gotoxy(60,9);
  cout<<price;
  gotoxy(10,10);
  cout<<"QUANTITY:";
  gotoxy(30,10);
  cout<<qty;
  gotoxy(40,10);
  cout<<"DISCOUNT";
  gotoxy(60,10);
  cout<<dis;
  gotoxy(5,11);
  cout<<"=====================================================================";

}
 //*****************************************************************************

	void create_book(int rn1)
	{
	 //**********************************************
  gotoxy(5,7);
  cout<<"======================================================================";
  gotoxy(10,8);
  cout<<"BOOK ID:";
  bookid=rn1;
  gotoxy(24,8);
  cout<<bookid;
  gotoxy(35,8);
  cout<<"TITLE NAME:";
  gotoxy(54,8);
  cin>>name;
  gotoxy(10,9);
  cout<<"PUBLISHER:";
  gotoxy(22,9);
  cin>>pub;
  gotoxy(35,9);
  cout<<"QUANTITY";
  gotoxy(54,9);
  cin>>qty;
  gotoxy(10,11);
  cout<<"PRICE";
  gotoxy(25,11);
  cin>>price;
  gotoxy(35,11);
  cout<<"DISCOUNT";
  gotoxy(45,11);
  cin>>dis;
  gotoxy(5,12);
  cout<<"=====================================================================";
}
	void show_book()
	{
	  //********************************
  gotoxy(5,7);
  cout<<"======================================================================";
  gotoxy(10,8);
  cout<<"BOOK ID:";
  //rollno=rn1;
  gotoxy(25,8);
  cout<<bookid;
  gotoxy(35,8);
  cout<<"TITLE OF BOOK:";
  gotoxy(54,8);
  cout<<name;
  gotoxy(10,9);
  cout<<"PUBLISHER:";
  gotoxy(25,9);
  cout<<pub;
  gotoxy(35,9);
  cout<<"PRICE OF PRODUCT:";
  gotoxy(54,9);
  cout<<price;
  gotoxy(10,10);
  cout<<"DISCOUNT:";
  gotoxy(25,10);
  cout<<dis<<"%";
  gotoxy(35,10);
  cout<<"QUANTITY:";
  gotoxy(54,10);
  cout<<qty;
  gotoxy(5,11);

  cout<<"=====================================================================";

	 }
 //-----------------------show data tabular form----------------------
	void showall(int c)
	{
	 gotoxy(1,c);
	 cout<<bookid<<setw(17)<<name<<setw(11)<<pub<<setw(10)<<"Rs."<<price<<setw(15)<<qty<<setw(12)<<dis<<"%";
	}

 //-----------------------ends here------------------------------------
  int  retpno()
  {return bookid;}

  float retprice()
  {return price;}
	char* getpub()
	{ return pub;}
  char* getname()
  {return name;}
	int getqty()
	{ return qty;}
  float retdis()
  {return dis;}
  void setqty(int q21)
  {
  qty=q21;
  }
};         //class ends here
//***************************************************************
//    	global declaration for stream object, object
//****************************************************************


 //*************************modify book
void books::modifydata(int n1,char snm[15],char pubnm[15],int q)
{
char tmpnm[40],tmpnm2[40];
gotoxy(5,14);
  cout<<"===================WANT TO MODIFY ===============================";
  gotoxy(10,15);
  cout<<"BOOK ID:";
  bookid=n1;
  gotoxy(25,15);
  cout<<bookid;
  gotoxy(40,15);
  strcpy(name,snm);
  cout<<"TITLE OF BOOK:";
  gotoxy(60,15);
  cout<<name;
  gotoxy(10,17);
  cout<<"Want to change the name of book";
  gotoxy(50,17);
  int flag=0;
  while(1)
  {
	  gets(tmpnm);
	  if(strlen(tmpnm)!=0)
	  {
				flag=1;
			break;
		}
	  if(strlen(tmpnm)==0)
		 { flag=0;
		  break;
		}
  }
  if(flag==1)
  { strcpy(name,tmpnm);
  }
  else
  {

  }
  gotoxy(1,18);
  strcpy(pub,pubnm);
  //****************PUBLISHER NAME TO BE MODIFY
  cout<<"PUBLISHERS NAME:";
  gotoxy(20,18);
  cout<<pub;
  gotoxy(35,18);
  cout<<"Want to change the PUBLISHER";
  gotoxy(65,18);
  flag=0;
  while(1)
  {
	  gets(tmpnm2);
	  if(strlen(tmpnm2)!=0)
	  {
				flag=1;
			break;
		}
	  if(strlen(tmpnm2)==0)
		 { flag=0;
		  break;
		}
  }
  if(flag==1)
  { strcpy(pub,tmpnm2);
  }
  
  //*****************PUBLISHER NAME TO BE MODIFIED ENDS HERE
  gotoxy(5,19);

  cout<<"********MODIFY**PRODUCT PRICE - QUANTITY - DISCOUNT ***********";


	//****************************************************
	gotoxy(5,20);
	cout<<"PRICE:";
	gotoxy(15,20);
    float tmppr=0;
	flag=-1;
	while(1)
  {
		cin>>tmppr;
	  if(tmppr!=0)
	  {
				flag=1;
			break;
		}else
		{ flag=0;
		  break;
		}
  }
  if(flag==1)
  { price=tmppr;
  }
  else
  {

  }
	//****************************************************


	//****************************************************
	gotoxy(22,20);
	cout<<"INCREASE QUANTITY:";
	gotoxy(45,20);
   int tmpqty=0;
		cin>>tmpqty;
		qty=q;
		qty=qty+tmpqty;
	//***************************************************


  //***************************************************

	gotoxy(50,20);

	cout<<"DISCOUNT:";
	gotoxy(63,20);
   float tmpdis=0;
	cin>>tmpdis;
	dis=tmpdis;

	//*****************************************

 gotoxy(5,22);
  cout<<"=====================================================================";
}
//**************************class function outside
 fstream fp;
 books pr;
//***************************************************************
//    	function to write in file
//****************************************************************
void write_book()
	{
	 fp.open("book.dat",ios::out|ios::app);
	 clrscr();
	 intromain();
	 int rnn=getrollno();
	 if(rnn>100)
	 {
	 rnn=1;
	 }
	 pr.create_book(rnn);
	 fp.write((char*)&pr,sizeof(books));
	 fp.close();
	 gotoxy(10,20);
	 cout<<"***************The BOOKS RECORD ENTERED******************* ";
	 cin.ignore();
	 getch();
	}
//********************check the book number already given or not******
int getrollno()
{
 ifstream objiff;
 books st;
 int count=0;
 objiff.open("book.dat",ios::binary);
 objiff.seekg(0,ios::beg);
	if(!objiff)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
	}
//**************temporary hiding these lines
 while(objiff.read((char *) &st, sizeof(books)))
	{
	  count++;
	}
//***********jump to the last line
objiff.seekg(count-sizeof(st),ios::beg);
objiff.read((char *) &st, sizeof(books));
count=st.retpno();
count++;
objiff.close();
	return count;
}
//***************************************************************
//    	function to read specific record from file
//****************************************************************
void display_sp(int n)
{
	 int flag=0;
	 fp.open("book.dat",ios::in);
	 if(!fp)
	{
		cout<<"File could not be open !! Press any Key...";

		getch();
		return;
	}
	 while(fp.read((char*)&pr,sizeof(books)))
	{
	 if(pr.retpno()==n)
		{
		 clrscr();
		 intromain();
		 pr.show_book();
		 flag=1;
		}
	}
	 fp.close();
if(flag==0)
 cout<<"\n\nrecord not exist";
 getch();
}
//***************************************************************
//    	function to place order and generating bill for BOOKS PURCHASED
//****************************************************************


	void place_order()
	{
	 order o1[50];
	 int  c=0,pr1=0;
	 float amt=0,damt=0,total=0,ttaxt=0;
	 int k=0,q1;
	 char ch='Y';
	 clrscr();
	 book_tabular();
	 clrscr();
	 intromain();
	 gotoxy(30,4);
	 cout<<"============================";
	 gotoxy(30,5);
	 cout<<"    PLACE YOUR ORDER";
	 gotoxy(30,6);
	 cout<<"============================";

do
{
	 clrscr();
	 gotoxy(5,10);
	 cout<<"Enter The BOOK No: ";
	 gotoxy(55,10);
	 cin>>pr1;
	 k=search(pr1);
	 if(k>0)
	 {
		gotoxy(5,12);
		cout<<"Enter the Quantity:";
      gotoxy(28,12);
		cin>>q1;
		changeqty(pr1,q1);
		copyme(k,o1,q1,c);
	 }else
	 {
		cout<<"BOOK not found";
	 }
	clrscr();
	gotoxy(10,20);
	cout<<"Do you want purchase more (Yes[ y or Y ] or NO [n or N])";
	gotoxy(10,21);
	cin>>ch;
} while(ch=='y' || ch=='Y');
		//***************while ends by these lines



	clrscr();
	  gotoxy(20,20);
	  cout<<"Thank You For Placing The Order..........";
	  getch();
	  clrscr();
	  intromain();
	  gotoxy(13,5);
	  cout<<"*************************INVOICE************************";
	  gotoxy(1,6);
	  cout<<"BK.No."<<setw(12)<<"TITLE"<<setw(10)<<"Qty"<<setw(15)<<"Price"<<setw(13)<<"Amount"<<setw(23)<<"Amount- discount";
	  gotoxy(3,7);
	  cout<<"----------------------------------------------------------------------------";
	  int yy=8;
	for(int x=0;x<c;x++)
	{
	  gotoxy(1,yy);
	  cout<<o1[x].bookid1;
	  gotoxy(10,yy);
	  cout<<o1[x].name1;
	  gotoxy(27,yy);
	  cout<<o1[x].qty1;
	  gotoxy(40,yy);
	  cout<<"Rs."<<o1[x].price1;
	  gotoxy(50,yy);
	  amt=o1[x].qty1*o1[x].price1;
	  cout<<"Rs."<<amt;
	  damt=amt-o1[x].dis1;
	  gotoxy(65,yy);
	  cout<<"Rs."<<damt;
	  total+=damt;
	  //ttaxt+=o1[x].tax1;
	yy++;
	 }
	 ttaxt=5;
	 gotoxy(3,yy);
	 cout<<"----------------------------------------------------------------------------";
	 yy++;
	 gotoxy(25,yy);
	 cout<<"TOTAL:";
	 gotoxy(35,yy);
	 cout<<total;
	 yy++;
	 gotoxy(25,yy);
	 cout<<"TAX%:";
	 gotoxy(36,yy);
	 cout<<"+"<<ttaxt;
	 yy++;
	 gotoxy(25,yy);
	 cout<<"----------------------------";
	 yy++;
	 gotoxy(25,yy);
	 cout<<"NET TOTAL:";
	 gotoxy(35,yy);
	 cout<<(total+((ttaxt*total)/100));
	 yy++;
	 gotoxy(3,yy);
	 cout<<"----------------------------------------------------------------------------";

	//*****************change at the above
	 getch();
 }
//********************fuction to copy all record to a structure

void copyme(int k2,order order1[50],int q1,int &c2)
{
  ifstream objiff2("book.dat",ios::binary);
  books bk1;
  objiff2.seekg(k2-sizeof(books));
  objiff2.read((char*)&bk1,sizeof(books));
  strcpy(order1[c2].name1,bk1.getname());
  strcpy(order1[c2].pub1,bk1.getpub());
		order1[c2].dis1=bk1.retdis();
		order1[c2].price1=bk1.retprice();

	  //*********************copy record***********************
	  order1[c2].qty1=q1;
	  c2++;
	  objiff2.close();
}
//***************************************************************
//    	INTRODUCTION FUNCTION
//****************************************************************
void intro()
{
 gotoxy(4,2);
 cout<<"****************************BOOK SHOP**********************************";
 gotoxy(12,4);
 cout<<"===========================================================";
 gotoxy(5,5);
 cout<<"****************************S=Y=S=T=E=M********************************";
 gotoxy(15,10);
 cout<<"PROJECT:";
 gotoxy(15,12);
 cout<<"MADE BY : cmcodes";
 gotoxy(10,14);
 cout<<"---------------SCHOOL : DOON PUBLIC SCHOOL--------------------";
 getch();
}
//***************************************************************
//    	ADMINSTRATOR MENU FUNCTION
//****************************************************************
void admin_menu()
{
  clrscr();
  char ch2;
	int num;
  //************************************************************
	 clrscr();
		intromain();
		gotoxy(20,6);
		cout<<"=================ADMIN MENU====================";
		gotoxy(22,7);
	cout<<"1.CREATE BOOKS";
	gotoxy(22,8);
	cout<<"2.DISPLAY ALL BOOKS AVAILABEL";
	gotoxy(22,9);
	cout<<"3.SEARCH RECORD(QUERY) ";
	gotoxy(22,10);
	cout<<"4.MODIFY BOOKS";
	gotoxy(22,11);
	cout<<"5.DELETE BOOK";
	gotoxy(22,12);
	cout<<"6.BACK TO MAIN MENU";
	gotoxy(18,13);
	cout<<"Please Enter Your Choice (1-6) ";
	gotoxy(55,13);
  //**********************************************************
  ch2=getche();
  switch(ch2)
  {
	 case '1': clrscr();
			write_book();
			break;
	 case '2': book_tabular();//display_all();
	 break;
	 case '3':
	 //********************
	clrscr();
	intromain();
	gotoxy(10,8);
	cout<<"*****ENTER THE BOOK ID TO BE SEARCHED:";
	gotoxy(55,9);
	cin>>num;
	display_sp(num);
			 break;
		case '4':
	clrscr();
	intromain();
	gotoxy(10,8);
	cout<<"*****ENTER THE BOOK ID TO BE SEARCHED AND MODIFY:";
	gotoxy(55,9);
	cin>>num;
	modify_record(num);
		 break;
		case '5':

		clrscr();
	intromain();
	gotoxy(10,8);
	cout<<"*****ENTER THE BOOK ID TO BE SEARCHED AND TO DELETE:";
	gotoxy(55,9);
	cin>>num;

	delete_record(num);
	break;
		case '6': break;
		default:cout<<"\a";admin_menu();
	}
}
//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************
void main()
{
  char ch;
  intro();
  do
	 {
	  //****************TEMPORARY***********************
			 clrscr();
		intromain();
		gotoxy(20,6);
		cout<<"=================MAIN MENU====================";
		gotoxy(28,7);
		cout<<"01. BOOKS SELLING";
		gotoxy(28,8);
		cout<<"02. ADMINISTRATOR";
		gotoxy(28,9);
		cout<<"03. EXIT";
		gotoxy(20,10);
		cout<<"==============================================";
		gotoxy(25,12);
		cout<<"Please Select Your Option (1-3) ";
		gotoxy(30,14);
		ch=getche();
	  switch(ch)
	  {
		 case '1': clrscr();
				orderk=0;
				place_order();
				getch();
				break;
		  case '2': admin_menu();
				 break;
		  case '3':exit(0);
		  default :cout<<"\a";
	}
	 }while(ch!='3');
}

//***************main intro
void intromain()
{  clrscr();
	gotoxy(1,2);
	cout<<"*************************BOOKS********SHOP******PROJECT************************";
	gotoxy(1,3);
	cout<<"******************************************************************************";
}
//******************************************************************************
//			DISPLAY ALL THE PRODUCT TABULAR FORM
//******************************************************************************
void book_tabular()
{
  int r=0,col=10;
	books st;
	ifstream inFile;
	inFile.open("book.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";

		getch();
		return;
	}
	display_all();
	while(inFile.read((char *) &st, sizeof(books)))
	{
		  if(r<=12)
		  {
		  r++;
		  st.showall(col);
		  col++;
		  }else
		  {
		  gotoxy(20,30);
		  cout<<"--------------press any key------------------------";
		  getch();
		  clrscr();
		  display_all();
		  col=10;
		  r=0;
		}
	}
	inFile.close();
	getch();
}
//**************************tabular forms ends**********************************
//*******************tabulars forms headings************************************
//function to display all the records of book
//**********************************************************************
void display_all()
{
clrscr();
intromain();
gotoxy(1,5);
cout<<"     **********************BOOKS  DETAILS***************************";
gotoxy(1,6);
cout<<"================================================================================";
gotoxy(1,7);
cout<<"PROD.NO"<<setw(10)<<"TITLE"<<setw(15)<<"PUBLISHER"<<setw(15)<<"PRICE"<<setw(15)<<"QUANTITY"<<setw(10)<<"DISCOUNT";
gotoxy(1,8);
cout<<"================================================================================";
}
//************************************************************
//		MODIFY RECORD
//**********************************************************
void modify_record(int n)
{
	books st,temp;
	char tmpnm[50],tmppub[50];
	ifstream inFile;
	int fpos=-1;
	inFile.open("book.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";

		getch();
		return;
	}
	int flag=0;
	while(inFile.read((char *) &st, sizeof(books)))
	{
		if(st.retpno()==n)
		{   clrscr();
			 intromain();
			 st.showdatamulti();
			 flag=1;
		}
	}
	inFile.close();

	if(flag==0)
		cout<<"\n\nrecord not exist";
	else
	{
	//*******modifying the records starts here
	fstream File;
	File.open("book.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}
	while(File.read((char *) &st, sizeof(books)))
	{
		if(st.retpno()==n)
		{   fpos=(int)File.tellg();
			 break;
		}
	 }
	File.seekp(fpos-sizeof(books),ios::beg);
	strcpy(tmpnm,st.getname());
	strcpy(tmppub,st.getpub());
	int q1=st.getqty();
	gotoxy(1,12);
	cout<<"*****************************************************************************";
	gotoxy(1,13);
	cout<<"================ENTER NEW VALUES FOR THE RECORDS GIVEN ABOVE=================";
	temp.modifydata(n,tmpnm,tmppub,q1);
	File.write((char *) &temp, sizeof(books));
	File.close();
  }
}
//*****************************************************************************
//					DELETE THE RECORD OF THE BOOKS NOT AVAILABLE
//****************************************************************************
void delete_record(int n)
{
  books st;
	ifstream inFile;
	inFile.open("book.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}
	int flag=0;
	while(inFile.read((char *) &st, sizeof(books)))
	{
		if(st.retpno()==n)
		{   clrscr();
			 intromain();
			 st.showdatamulti();
			 flag=1;
		}
	}
	inFile.close();
	char ch;
	if(flag==0)
		cout<<"\n\nrecord not exist";
	else
	{
	//*******deletion of the records starts from here
	gotoxy(1,15);
	cout<<"*****************************************************************************";
	gotoxy(5,16);
	cout<<"======DO YOU WANT TO DELETE THE RECORDS GIVEN ABOVE[YES(Y) OR NO (N)========";
	gotoxy(2,17);
	cin>>ch;
	 if (toupper(ch)=='Y')
	 {
		 ofstream outFile;
		 outFile.open("Temp1.dat",ios::binary);
		 ifstream objiff("book.dat",ios::binary);
		 objiff.seekg(0,ios::beg);
		 while(objiff.read((char *) &st, sizeof(books)))
			{
			 if(st.retpno()!=n)
			 {
				 outFile.write((char *) &st, sizeof(books));
			 }
			}

	outFile.close();
	objiff.close();
	remove("book.dat");
	rename("Temp2.dat","book.dat");
	againopenandclose();
	gotoxy(30,20);
	cout<<"----------------------------Record Deleted----------------------------------";
	}
	}
	getch();
}
//***********************delete record ends************************************
void againopenandclose()
{
  ifstream inFile;
	 books st;
	inFile.open("book.dat",ios::binary);
	if(!inFile)
	{
		getch();
		return;
	}
	while(inFile.read((char *) &st, sizeof(books)))
	{
	}
	inFile.close();
}
//***********************search the book***********************
int search(int p)
{
 books st;
 int tmprt=0;
ifstream inFile;
	inFile.open("book.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return -1;
	}
	int flag=0;
	while(inFile.read((char *) &st, sizeof(books)))
	{
		if(st.retpno()==p)
		{   clrscr();
			 intromain();
			 st.showdatamulti();
			 flag=1;
			 tmprt=(int)inFile.tellg();
          break;
		}
	}
	inFile.close();
	if(flag==0)
		return 1;
		//cout<<"\n\nrecord not exist";
	else
	{
		return tmprt;
	}
}
//********************change quantity*************************
void changeqty(int pr1,int q11)
{
	books st;
	int fpos=-1;
	fstream File;
	File.open("book.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}
	while(File.read((char *) &st, sizeof(books)))
	{
		if(st.retpno()==pr1)
		{   fpos=(int)File.tellg();
			 break;
		}
	 }
	File.seekp(fpos-sizeof(books),ios::beg);
	int q1=st.getqty();
	q1=q1-q11;
	st.setqty(q1);
	File.write((char *) &st, sizeof(books));
	File.close();
}
//***************************************************************
//    			END OF PROJECT
//
