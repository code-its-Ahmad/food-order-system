#include<iostream>
#include<windows.h>
using namespace std;
struct Node
{

	char food_name[50];
	int quantity;
	float price;
	int data;
	Node *next;

};
Node *head=NULL;
Node *list=NULL;
int chose_memu()
{
	
		cout<<"\n[Choice 1] click on food list";
    	cout<<"\n[Choice 2] click on admin Panel";
	    cout<<"\n[Choice 3] click on Exit"<<" ";
}

void insertfirst(int d, char f[25], int q, float p)
{
	Node *newNode=new Node;
	newNode->data = d ;
	newNode->price = p;
	strcpy(newNode->food_name,f);
	newNode-> quantity = q;
	newNode->next = head;
	head = newNode;
	list = head ;
}
void insert_last(int d, char f[25],int q, float p)
{
	Node *newNode=new Node;
	newNode->data = d;
	newNode->price = p;
	newNode-> quantity = q;
	strcpy(newNode->food_name,f);
	newNode->next = NULL;
	if(head==NULL){
		head = newNode;
		list = head;
	}
	else
	{
		while(head->next != NULL)
		{
			head = head->next;
		}
		head->next = newNode;
	}
}
void insert_mid(int pos, int d, char f[25], int q, float p)
{

	Node *newNode=newNode;
	newNode->data =d;
	newNode->price = p;
	newNode-> quantity = q;
    strcpy(newNode->food_name,f);
	while(head->next->data!=pos)
	{
		head = head->next ;
	}
	newNode->next = head->next;
	head->next = newNode ;
}
void deletefood(int serial)
{

	Node *temp=temp;
	temp = list;
	if(temp->data != serial)
	{
		while(temp->next->data != serial)
		{
			temp = temp->next;
		}
		if(temp->next->data == serial)
		{
			temp->next = temp->next->next;
			cout<<"\n\n\n\n\t\t\tdelete"<<serial<<" .";
			cout<<"\n\n\n\n\t\t\tDeleted Successfylly \n";
		}
		else
		{
			cout<<"\n\n\n\n\t\t\tFood Item Not Found\n";
		}
		head = temp;
	}
	else
	{
		temp = temp->next;
		cout<<"\n\n\n\n\t\t\tDeleting"<<serial<<".";
		cout<<"\n\n\n\n\t\t\tDeleted Successfylly \n";
		head = temp ;
		list=head;
	}
}
void updatefood(int udata, int uquantity)
{
	Node *temp;
	temp = list;
	while(temp->data!=udata)
	{
		temp = temp->next;
	}
	if(temp->data == udata)
	{
		temp->quantity = uquantity;
	}
}

void foodlist()
{	
    cout<<"\n\t\t";
	cout<<"______________________________________________________ ";
	cout<<"\n\t\t";
	cout<<"|  Food No.  |   FooD Name   |  Price  |   In Stock   |";
	cout<<"\n\t\t";
	cout<<"-------------------------------------------------------";
	Node *temp;
	temp = list;
	while(temp!= NULL)
	{
		cout<<"\n\t\t";
		printf("|     %d      |    %s  |    %0.2f   |    %d    |",temp->data,temp->food_name, temp->price, temp->quantity);
		cout<<"\n\t\t";
		cout<<"-------------------------------------------------------";
		temp = temp->next;
	}
}
void order_view(int order, int quantity, int or_no)
{
	Node *temp;
	temp = list;
	while(temp->data != order)
	{
		temp = temp->next;
	}
	if(temp->data == order)
	{
		cout<<"\n\t\t";
		printf("|     %d      |    %s  |     %d     |     %d     |",or_no,temp->food_name,quantity,temp->quantity);
		cout<<"\n\t\t";
		cout<<"-------------------------------------------------------";
	}
}

int main()
{
	int c=0;	
	int card_no[100];
	float card_money[100];
	float total_amount = 0;
	int total_order[100];
	int order_quantity[100];
	int order=0;
	int uquantity;

	head = NULL;
	insertfirst(1,"Burger   ",23,350.34);
	insert_last(2,"Pizza    ",13,550.67);
	insert_last(3,"Coffie   ",46,60.23);
	insert_last(4,"Ice-Cream",46,100.23);
	insert_last(5,"Cold Drinks",73,20.13);
	string fullname;
	cout<<"\t\t\t|-------------------------------------------------------|\n";
	cout<<"\t\t\t|              >>>>food order management system<<<      |\n";
	cout<<"\t\t\t|              >>>>semater project of data structure<<  |\n";
	cout<<"\t\t\t|              >>>>NAEME: Ahmad nawaz<<<<<<<            |\n";
	cout<<"\t\t\t|-------------------------------------------------------|\n\n";
	cout<<"Please Enter Your Name: ";
	cin>>fullname;
	mainmenu:
		cout<<"\n\nWhat would you like to order?\n\n";
		cout<<"\t\t\t|-------------------------------------------------------|\n";
		cout<<"\t\t\t|        >>>>>welcome to food order system<<<<          |\n";                
    	cout<<"\t\t\t|                 >>>selected  Menu<<                   |\n";
	    cout<<"\t\t\t|-------------------------------------------------------|\n\n";
	chose_memu();
	int selection;
	 cin>>selection;
	if((selection>=1&&selection<=3))
	{
		if(selection==1)
		{
			foodlist:	
			cout<<"open the Main Menu ";
			foodlist();
		}
		else if(selection==2)
		{
			adminpanel:
			int panel_choice;
			cout<<"1. Main Menu\n\n\t";
			cout<<"Enter correct Password or ( press 1 back Main Menu ) : ";
			cin>>panel_choice;
			if(panel_choice==1122)
			{
				Node *temp;
				temp = list;
				adminchoise:
				cout<<"show to  Admin Pannel\n\n"<<endl;
				cout<<" 1. Total Cash \n\n";
				cout<<" 2. View Card Pay \n\n";
				cout<<" 3. Add Food \n\n";
				cout<<" 4. Delete Food \n\n";
				cout<<" 5. Food List \n\n";
				cout<<" 6. Order Preview\n\n";
				cout<<" 0. back to menu \n\n";
				cout<<"Enter Your From 1-0: ";

				int adminchoise;
				cin>>adminchoise;
				if(adminchoise==1)
				{
                    printf("Total Cash : %0.2f  \n",total_amount);
					return adminchoise;
				}
				else if(adminchoise==2)
				{
					if(c!=0)
					{
						cout<< " ____________________________\n";
						printf("|   Card NO.   |   Money $   |\n");
						cout<<"------------------------------\n";
						for(int i=1; i<=c;i++)
						{
							printf("|  %d           | %0.2f |\n",card_no[i],card_money[i]);
							cout<<"------------------------------\n";
						}
					}
					if(c==0)
					{   
					printf("No Card History\n");
					}
					return adminchoise;
				}
				else if(adminchoise==3)
				{
					foodadd:
					char foodname[25];
					int quantity;
					int data;
					float price;
					int pos;
					cout<<" Enter Food Name :  ";
					cin>>foodname;
					quantity:
					cout<<" Enter Food Quantity :  ";
					cin>>quantity;
                    foodserial:
					cout<<" Enter Food Serial :  ";
                    cin>>data;
                    Node *temp;
                    temp= list;
                    while(temp->data!=data)
					{
                    if(temp->next==NULL)
					{
                        break;
                    }
                    temp=temp->next;
                    }
                    if(temp->data==data)
					{    
					cout<<" Food Serial Already Exist, Please Re-Enter  ";
                    goto foodserial;
                    }
                    price:
					cout<<" Enter Food Price :  ";
					cin>>price;
					cout<<"Submiting your data";
					insert_last(data,foodname,quantity,price);
					cout<<"Adding Food  Successfull....\n";
					goto adminchoise;
				    }
				    	else if(adminchoise==4)
					{
					cout<<"Enter Serial No of the Food To Delete : ";
					fdelete:
					int fdelete;
					cin>>fdelete;
					Node *temp;
					temp=list;
					while(temp->data != fdelete)
					{
						temp = temp->next;
					}
					if(temp->data==fdelete)
					{
						deletefood(fdelete);
					}
					else
					{
						cout<<"Please Enter Correct Number :  ";
						goto fdelete;
					}
					goto adminchoise;
				}
				else if(adminchoise==5)
				{
					    foodlist();
					  cout<<"1. <-- back  \n\n";
				   	goto adminchoise;
				}
				else if(adminchoise==6)
				{	
					cout<<"\n\t\t";
					cout<<"______________________________________________________ ";
					cout<<"\n\t\t";
					printf("|  Order No.  |   FooD Name   |  Quantity |  In Stock |");
					cout<<"\n\t\t";
					cout<<"------------------------------------------------------";
					for(int i=1;i<=order;i++)
					{
						order_view(total_order[i],order_quantity[i],i);
					}
					cout<<"1. <-- back  \n\n";
					goto adminchoise;
				}
				else if(adminchoise==0){

					goto mainmenu;
				}

				else
				{
					 cout<<"Please Select From List :  "; Sleep(500);
					goto adminchoise;
				}
			}
			else if(panel_choice==1)
			{
				goto mainmenu;
			}
			else
			{
				  cout<<"Please Enter Correct Choice";
				goto adminpanel;
			}
		}
		else if(selection==3)
		{	
			cout<<"Thank You For Using Our System \n\n\n\n\n\n\n";
			exit(1);
		}
	else
	{
		cout<<"Please Enter Correct Choice";
		goto mainmenu;
	}
	int get_food_choice;
	cout<<"\n Place Your Order: "<<" ";
	cin>>get_food_choice;
	if(get_food_choice==0)
	{
		goto mainmenu;
	}
	Node *temp;
	temp = list ;
	while(temp->data != get_food_choice)
	{
		temp = temp->next;
		if(temp==NULL)
		{
			cout<<"Please Choice From List: ";
			goto foodlist;
		}
	}
	if(get_food_choice == temp->data)
	{
		fcquantity:
		cout<<"Enter Food Quantity : ";
		int fcquantity;
		cin>>fcquantity; 

		if(fcquantity==0)
		{
			  printf("Quantity Can not be Zero ");
			goto foodlist;
		}
		else if(fcquantity>temp->quantity)
		{
			cout<<"Out of Stock ! ";
			goto foodlist;
		}
		printf("Choice food %s  its price is %0.2f \n\n",temp->food_name,temp->price*fcquantity);
		cout<<"1. Confirm to buy this \n\n";
		cout<<"2. Food List \n\n";
		cout<<"Press 1 to confirm and 2 to back to list :";
		confirm:
		int confirm;
		cin>>confirm;
		if(confirm == 1 )
		{	
			cout<<" 1. Cash ";	
            cout<<" 2. Credit\n";
            cout<<"Select Method Of payment 1-2: ";
			payment:
			int payment;
			cin>>payment;
			if(payment==1)
			{
				total_amount+= temp->price*fcquantity;
				order++;
				total_order[order]=get_food_choice;
				order_quantity[order]=fcquantity;
				uquantity = temp->quantity - fcquantity;
				updatefood(get_food_choice,uquantity);

				  cout<<"===>THANK YOU<===";
				  cout<<"Food Ordered Successfully ...";
				  cout<<"1. Wanna Buy Another Delicious ? ";
				  cout<<"2. Main Menu \n";
				  cout<<"Select: ";
				  psmenu:
				int ps_menu;
				cin>>ps_menu;
				if(ps_menu==1)
				{
				goto foodlist;
				}
				else if(ps_menu==2)
				{
				goto mainmenu;
				}
				else
				{
				cout<<"Please Choice from list : ";goto psmenu;
				}
			}
			///Credit Card Option
			else if(payment==2)
			{
				int card_number[100];
				c++;
				cout<<"Enter Your Card No : ";
                 cin>>card_number[c];
				card_no[c] = card_number[c];
				int pin;
				cout<<"Enter Your Card Pin [we never save your pin]  : ";
			    cin>>pin;
				card_money[c] = temp->price*fcquantity;
				total_amount+= temp->price*fcquantity;
				order++;
				total_order[order]=get_food_choice;
				order_quantity[order]=fcquantity;
				uquantity = temp->quantity - fcquantity;
				updatefood(get_food_choice,uquantity);
				
				  cout<<"Payment Success...";
				   cout<<"1. Wanna Buy Another Delicious ? ";
				    cout<<"2. Main Menu \n";
				   cout<<"select: ";
				   
				   psmenu2:
				int ps_menu2;
				cin>>ps_menu2;
				if(ps_menu2==1)
				{
				goto foodlist;
				}
				else if(ps_menu2==2)
				{
				goto mainmenu;
				}
				else
				{
				   cout<<"Please Choice from list : "; goto psmenu2;
				}
			}
			else
			{
			   cout<<"Enter Choice from List : ";
				goto payment;
			}
		}   
		else if(confirm == 2)
		{
			goto foodlist;
		}
		else
		{
			cout<<"Enter Choise from List : ";
			goto confirm;
		}  
	}
	else
	{
		cout<<"Please Choice From List ";
		goto foodlist;
	}  
}
}
