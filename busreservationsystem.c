//Bus Reservation System
//Darsan Karthic
//06/11/2024 Wednesday

//Headers
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure to store bus informations
struct Bus
{
	int bus_number;
	char source[50];
	char destination[50];
	int total_seats;
	int available_seats;
	float fare;
};

//Structure to store user login information
struct User
{
	char username[50];
	char password[50];
};

//Login Menu Function
void displaymainmenu()
{
	printf("\n===MAIN MENU===\n");
	printf("1.) Login\n");
	printf("2.) Exit\n");
	printf("Enter your choice____\n");
}

//User Menu Function
void displayusermenu()
{
	printf("\n===USER MENU===\n");
	printf("1.) Book a Ticket\n");
	printf("2.) Cancel a Ticket\n");
	printf("3.) Check Bus Status\n");
	printf("4.) Logout\n");
	printf("Enter your Choice____\n");
}

//User login Function
int loginuser(struct User users[], int num_of_users, char entered_username[], char entered_password[])
{
	//traverses all the users separately
	int i;
	for (i=0;i<num_of_users;i++)
	{
		//if actual username and entered username is same, strcmp returns 0
		//if both condition in if statement results 0, then user is loggedin
		if ((strcmp(users[i].username, entered_username) == 0) && (strcmp(users[i].password, entered_password) == 0))
		{
			return i; //returns the index of the user loggedin since username and password is matched
		}
	}
	return -1; //if username or password is not matched, so loggedin users count is none
}

//Display the bus details function
void displaybusinfos(struct Bus businfos[], int num_of_buses)
{
	int i;
	for (i=0;i<num_of_buses;i++)
	{
		printf("Bus Number : %d\n",businfos[i].bus_number);
		printf("%s to %s\n",businfos[i].source, businfos[i].destination);
		printf("Total Seats : %d\n",businfos[i].total_seats);
		printf("Available Seats : %d\n", businfos[i].available_seats);
		printf("Travel Fare : Rs. %.2f\n\n",businfos[i].fare);
	}
}

//Ticket booking function
void bookTickets(struct Bus businfos[], int num_of_buses)
{
	int enter_busnumber;
	printf("Enter the Bus Number\n");
	scanf("%d",&enter_busnumber);
	int busindex = -1; //bus index, indicates whether bus found or not, if yes, stores the bus index
	int i;
	for (i=0;i<num_of_buses;i++)
	{
		if (businfos[i].bus_number == enter_busnumber)
		{
			busindex = i; //if bus number found, stores the index value of bus i.e i
			printf("Bus with Bus Number %d is available\n",enter_busnumber);
			break;
		}
	}
	if (busindex == -1) // It means, Bus with that bus number is not found
	{
		printf("Bus with Bus Number %d not found\n",enter_busnumber);
	}
	else //bus with bus number found and proceeding to seats booking
	{
		int seats_to_book;
		printf("Enter the number of seats to book : \n");
		scanf("%d",&seats_to_book);
		
		if (businfos[busindex].available_seats < seats_to_book) //check whether enough seats are available
		{
			printf("Sorry ): Only %d Seats are available\n",businfos[busindex].available_seats);
		}
		else
		{
			// seats are booked, and booked seats are reduced from the total seats
			businfos[busindex].available_seats = businfos[busindex].available_seats - seats_to_book;
			printf("Success ! %d tickets are booked in the Bus %d\n",seats_to_book, businfos[busindex].bus_number);
		}
	}
}

//Function to cancel booked tickets
void cancelTickets(struct Bus businfos[], int num_of_buses)
{
	int busnumber;
	printf("Enter the Bus Number : \n");
	scanf("%d",&busnumber);
	int busindex = -1; // stores bus index
	int i;
	for (i=0;i<num_of_buses;i++)
	{
		if (businfos[i].bus_number == busnumber) //checking if bus number available with the entered bus number
		{
			busindex = i; // if yes, stores the bus index
			break;
		}
	}
	if (busindex == -1) //if bus number is not matched with entered bus number
	{
		printf("Bus with Bus number %d is not found\n",busnumber);
	}
	else // bus with entered bus number is found
	{
		int seats_to_cancel;
		printf("Enter the number of seats to cancel : \n");
		scanf("%d",&seats_to_cancel);
		//Stores the remaining available seats
		int remaining_seats = businfos[busindex].total_seats - businfos[busindex].available_seats;
		if (seats_to_cancel > remaining_seats)
		{
			printf("Number of seats to cancel is more than booked seats |:\n");
		}
		else
		{
			// Adding the cancelled tickets to total number of seats in the bus
			businfos[busindex].available_seats = businfos[busindex].available_seats + seats_to_cancel;
			printf("%d Tickets were cancelled from Bus %d\n",seats_to_cancel,busnumber);
		}
	}
}

//Function to check the bus status
void checkBusStatus(struct Bus businfos[], int num_of_buses)
{
	int enter_busnumber;
	printf("Enter the Bus Number to check the status\n");
	scanf("%d",&enter_busnumber);
	int busindex = -1; //stores bus index
	int i;
	for (i=0;i<num_of_buses;i++)
	{
		if (businfos[i].bus_number == enter_busnumber) // check whether the bus with bus number available or not
		{
			busindex = i; //bus found, and bus index value is stored
			break;
		}
	}
	if (busindex == -1) // if bus with bus number is not found
	{
		printf("Bus with Bus Number %d is not found....\n",enter_busnumber);
	}
	else
	{
		// if bus with the bus number is found
		printf("Bus Number %d Status : \n",enter_busnumber);
		printf("Bus Number : %d\n",businfos[busindex].bus_number);
		printf("From %s to %s\n",businfos[busindex].source, businfos[busindex].destination);
		printf("Total Seats : %d\n",businfos[busindex].total_seats);
		printf("Available Seats : %d\n",businfos[busindex].available_seats);
		printf("Travel Fare : %.2f\n",businfos[busindex].fare);
	}
}

//Main Function
int main()
{
	//Number of users;
	int num_of_users = 5;
	
	//Login details of all the users
	struct User users[5] = {
		//Username = Darsan and Password = darsan2018
		{"Darsan", "darsan2018"},
		{"User2", "User2pass"},
		{"User3", "User3pass"},
		{"User4", "User4pass"},
		{"User5", "User5pass"}
	};
	
	//Number of Buses
	int num_of_buses = 3;
	
	//Bus details
	struct Bus businfos[3] = {
		{2525, "Coimbatore", "Chennai", 50, 50, 800.00},
		{3535, "Coimbatore", "Salem", 40, 40, 500.00},
		{6565, "Coimbatore", "Banglore", 60, 60, 1500.00}
	};
	
	//Number of users currently logged in
	int loggedin_usersid = -1;
	
	while(1)
	{
		//if currently none is logged in
		if (loggedin_usersid == -1)
		{
			//Displays all the available options
			displaymainmenu();
			int choice;
			scanf("%d",&choice);
			if(choice == 1)
			{
				char entered_username[50];
				char entered_password[50];
				printf("Enter UserName : \n");
				scanf("%s",entered_username);
				printf("Enter Password : \n");
				scanf(" %s",entered_password);
				
				//Stores the index of the current user if login is successful
				loggedin_usersid = loginuser(users, num_of_users, entered_username, entered_password);
				if (loggedin_usersid == -1) //username or password is not matched, so it remained as -1
				{
					printf("Login Failed ): Please check your UserName and Password\n");
				}
				else // if login successful, the loggedin_usersid contains the index value of the user loggedin
				{
					printf("Login Successful!\nWelcome %s\n\n",entered_username);
				}
			}
			else if (choice == 2)
			{
				printf("Exiting the Program.....\n");
				break;
			}
			else
			{
				printf("Invalid Choice |: Try Again!\n");
			}
		}
		//if already user is logged in
		else
		{
			displayusermenu();
			int userchoice;
			scanf("%d",&userchoice);
			
			//Executing the selected option from User Menu
			switch(userchoice)
			{
				case 1:
					//Function that displays All Bus details
					displaybusinfos(businfos, num_of_buses);
					bookTickets(businfos, num_of_buses);
					break;
				case 2:
					cancelTickets(businfos, num_of_buses);
					break;
				case 3:
					checkBusStatus(businfos, num_of_buses);
					break;
				case 4:
					printf("Logging Out....\n");
					loggedin_usersid = -1; //Removing the loggedin user and back to no current users
					break;
				default:
					printf("Invalid Choice |: Try Again....\n");
			}
			
		}
	}
	return 0;
}
