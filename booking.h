#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>

#include<string.h>
#include<time.h>

struct Passanger
{
    char Fname[50];
    char Lname[50];
    char Number[20];
    char Address[150];
    char Date_of_departure[50];
    int Type_destination;
    char n_class[20];
    int Number_of_seat;
    int Type_by_food;
    int Origin;
    int destination;
    int price;
    int class;
    char food[50];
    int confirm;
};

void booking()
{

    struct Passanger Suyog;

    printf("Enter Your First Name : ");
    scanf("%s/n/n",&Suyog.Fname);

    printf("Enter Your Last Name : ");
    scanf("%s/n/n",&Suyog.Lname);

    printf("Enter Your Mobile Number : ");
    scanf("%s/n/n",&Suyog.Number);

    printf("Enter Your Address(like: dumas_road_surat_gujrat) : ");
    scanf("%s/n/n",&Suyog.Address);


    printf("Enter Date Of Departure In DD/MM/YYYY format : ");
    scanf("%s",&Suyog.Date_of_departure);

    printf("Choose Destination : \n");
    printf("Enter 1 For Local Destination and 2 For International Destination : ");
    scanf("%d",&Suyog.Type_destination);

    if(Suyog.Type_destination==1)
    {
        printf("Enter Number For Your Origin : \n\n");
        printf("1. Mumbai \n");
        printf("2. Delhi \n");
        printf("3. Hydrabad \n");
        printf("4. Chennai \n");
        printf("5. Bengaluru \n");
        printf("\n");
        scanf("%d",&Suyog.Origin);
        printf("\n");

        if (Suyog.Origin==1)
        {
            printf("Enter Number For Your Destination : \n\n");
            printf("2. Delhi \n");
            printf("3. Hydrabad \n");
            printf("4. Chennai \n");
            printf("5. Bengaluru \n");
            printf("\n");

            scanf("%d",&Suyog.destination);
            printf("\n");
        }
        else if (Suyog.Origin==2)
        {
            printf("Enter Number For Your Destination : \n\n");
            printf("1. Mumbai \n");
            printf("3. Hydrabad \n");
            printf("4. Chennai \n");
            printf("5. Bengaluru \n");
            printf("\n");

            scanf("%d",&Suyog.destination);
            printf("\n");
        }
        else if (Suyog.Origin==3)
        {
            printf("Enter Number For Your Destination : \n\n");
            printf("1. Mumbai \n");
            printf("2. Delhi \n");
            printf("4. Chennai \n");
            printf("5. Bengaluru \n\n");

            scanf("%d",&Suyog.destination);
            printf("\n");
        }
        else if(Suyog.Origin==4)
        {
            printf("Enter Number For Your Destination : \n\n");
            printf("1. Mumbai \n");
            printf("2. Delhi \n");
            printf("3. Hydrabad \n");
            printf("5. Bengaluru \n\n");

            scanf("%d",&Suyog.destination);
            printf("\n");
        }
        else
        {
            printf("Enter Number For Your Destination : \n\n");
            printf("1. Mumbai \n");
            printf("2. Delhi \n");
            printf("3. Hydrabad \n");
            printf("4. Chennai \n\n");

            scanf("%d",&Suyog.destination);
            printf("\n");
        }

        printf("\n\n");

        if (Suyog.Origin==1 && Suyog.destination==2)
        {
            Suyog.price=4942;
        }
        else if (Suyog.Origin==1 && Suyog.destination==3)
        {
            Suyog.price=2500;
        }
        else if (Suyog.Origin==1 && Suyog.destination==4)
        {
            Suyog.price=3000;
        }
        else if (Suyog.Origin==1 && Suyog.destination==5)
        {
            Suyog.price=1850;
        }
        else if (Suyog.Origin==2 && Suyog.destination==1)
        {
            Suyog.price=4942;
        }
        else if (Suyog.Origin==2 && Suyog.destination==3)
        {
            Suyog.price=5500;
        }
        else if (Suyog.Origin==2 && Suyog.destination==4)
        {
            Suyog.price=6500;
        }
        else if (Suyog.Origin==2 && Suyog.destination==5)
        {
            Suyog.price=4942;
        }
        else if (Suyog.Origin==3 && Suyog.destination==1)
        {
            Suyog.price=2500;
        }
        else if (Suyog.Origin==3 && Suyog.destination==2)
        {
            Suyog.price=5500;
        }
        else if (Suyog.Origin==3 && Suyog.destination==4)
        {
            Suyog.price=1600;
        }
        else if (Suyog.Origin==3 && Suyog.destination==5)
        {
            Suyog.price=1550;
        }
        else if (Suyog.Origin==4 && Suyog.destination==1)
        {
            Suyog.price=3000;
        }
        else if (Suyog.Origin==4 && Suyog.destination==2)
        {
            Suyog.price=6500;
        }
        else if (Suyog.Origin==4 && Suyog.destination==3)
        {
            Suyog.price=1600;
        }
        else if (Suyog.Origin==4 && Suyog.destination==5)
        {
            Suyog.price=1750;
        }
        else if (Suyog.Origin==5 && Suyog.destination==1)
        {
            Suyog.price=1850;
        }
        else if (Suyog.Origin==5 && Suyog.destination==2)
        {
            Suyog.price=4942;
        }
        else if (Suyog.Origin==5 && Suyog.destination==3)
        {
            Suyog.price=1550;
        }
        else
        {
            Suyog.price=1750;
        }

        printf("Price = %d/seat",Suyog.price);
    }

    else
    {
        printf("Enter Number For Your Origin : \n\n");
        printf("1. Mumbai \n");
        printf("2. Delhi \n");
        printf("3. Hydrabad \n");
        printf("4. Chennai \n");
        printf("5. Bengaluru \n");

        scanf("%d",&Suyog.Origin);
        printf("\n");

        printf("Enter Number For Your International Destination : \n\n");
        printf("1.london \n");
        printf("2.paris \n");
        printf("3.san-fransico \n");
        printf("4.tokyo \n");
        printf("5.berlin \n");

        scanf("%d",&Suyog.destination);
        printf("\n");

        if (Suyog.Origin==1 && Suyog.destination==1)
        {
            Suyog.price=53000;
        }
        else if (Suyog.Origin==1 && Suyog.destination==2)
        {
            Suyog.price=62000;
        }
        else if (Suyog.Origin==1 && Suyog.destination==3)
        {
            Suyog.price=92000;
        }
        else if (Suyog.Origin==1 && Suyog.destination==4)
        {
            Suyog.price=84000;
        }
        else if (Suyog.Origin==1 && Suyog.destination==5)
        {
            Suyog.price=85000;
        }

        else if (Suyog.Origin==2 && Suyog.destination==1)
        {
            Suyog.price=53000;
        }
        else if (Suyog.Origin==2 && Suyog.destination==2)
        {
            Suyog.price=62000;
        }
        else if (Suyog.Origin==2 && Suyog.destination==3)
        {
            Suyog.price=92000;
        }
        else if (Suyog.Origin==2 && Suyog.destination==4)
        {
            Suyog.price=84000;
        }
        else if (Suyog.Origin==2 && Suyog.destination==5)
        {
            Suyog.price=85000;
        }

        else if (Suyog.Origin==3 && Suyog.destination==1)
        {
            Suyog.price=53000;
        }
        else if (Suyog.Origin==3 && Suyog.destination==2)
        {
            Suyog.price=62000;
        }
        else if (Suyog.Origin==3 && Suyog.destination==3)
        {
            Suyog.price=92000;
        }
        else if (Suyog.Origin==3 && Suyog.destination==4)
        {
            Suyog.price=84000;
        }
        else if (Suyog.Origin==3 && Suyog.destination==5)
        {
            Suyog.price=85000;
        }

        else if (Suyog.Origin==4 && Suyog.destination==1)
        {
            Suyog.price=53000;
        }
        else if (Suyog.Origin==4 && Suyog.destination==2)
        {
            Suyog.price=62000;
        }
        else if (Suyog.Origin==4 && Suyog.destination==3)
        {
            Suyog.price=92000;
        }
        else if (Suyog.Origin==4 && Suyog.destination==4)
        {
            Suyog.price=84000;
        }
        else if (Suyog.Origin==4 && Suyog.destination==5)
        {
            Suyog.price=85000;
        }

        else if (Suyog.Origin==5 && Suyog.destination==1)
        {
            Suyog.price=53000;
        }
        else if (Suyog.Origin==5 && Suyog.destination==2)
        {
            Suyog.price=62000;
        }
        else if (Suyog.Origin==5 && Suyog.destination==3)
        {
            Suyog.price=92000;
        }
        else if (Suyog.Origin==5 && Suyog.destination==4)
        {
            Suyog.price=84000;
        }
        else if (Suyog.Origin==5 && Suyog.destination==5)
        {
            Suyog.price=85000;
        }

        printf("Price = %d/seat",Suyog.price);
    }
    printf("\n\n");
    //class of flight

    printf("Flight class available are:\n");
    printf("1.Business class flight.\n");
    printf("2.Economy class flight.\n");
    printf("\n");
    printf("in which class do you want to take flight?");
    printf("\n");
    printf("press 1 for Business and press 2 for economy class:\n");

    scanf("%d",&Suyog.class);






    printf("\n\n");

    //Number of seats
    printf("enter the number of seats:\n");
    scanf("%d",&Suyog.Number_of_seat);

    printf("\n\n\n");
    printf("the food choices available are:\n");
    printf("1.vegetarian\n2.Non-vegetarian");
    printf("\n\n");
    printf("press 1 for vegetarian food press 2 for Non-vegetarian food:\n");
    scanf("%d",&Suyog.Type_by_food);
    
    char yes;

    printf("Do You want to confirm your seat?:\npress:\n1.yes\n2.no\n");
    scanf(" %d",&Suyog.confirm);
    
    printf("\n\n\n");


    if(Suyog.confirm==1){
        printf("Name:-%s %s\n",Suyog.Fname,Suyog.Lname);
            printf("\n");

        printf("Address:-%s\n",Suyog.Address);
            printf("\n");

        printf("Contact-number:%s\n",Suyog.Number);
            printf("\n");

        printf("Date:-%s\n",Suyog.Date_of_departure);
            printf("\n");

        //Origin
        if(Suyog.Type_destination==1){
            if(Suyog.Origin==1){
                printf("Origin_city: Mumbai\n");
            }
            else if(Suyog.Origin==2){
                printf("Origin_city: Delhi\n");
            }
            else if(Suyog.Origin==3){
                printf("Origin_city: Hydrabad\n");
            }
            else if(Suyog.Origin==4){
                printf("Origin_city: Chennai\n");
            }
            else if(Suyog.Origin==5){
                printf("Origin_city: Bengaluru\n");
            }
        }
        else{
            if(Suyog.Origin==1){
                printf("Origin_city: Mumbai\n");
            }
            else if(Suyog.Origin==2){
                printf("Origin_city: Delhi\n");
            }
            else if(Suyog.Origin==3){
                printf("Origin_city: Hydrabad\n");
            }
            else if(Suyog.Origin==4){
                printf("Origin_city: Chennai\n");
            }
            else if(Suyog.Origin==5){
                printf("Origin_city: Bengaluru\n");
            }
        }
        printf("\n");
        //destination-city
        if(Suyog.Type_destination==1){
            if(Suyog.destination==1){
                printf("destination_city: Mumbai\n");
            }
            else if(Suyog.destination==2){
                printf("destination_city: Delhi\n");
            }
            else if(Suyog.destination==3){
                printf("destination_city: Hydrabad\n");
            }
            else if(Suyog.destination==4){
                printf("destination_city: Chennai\n");
            }
            else if(Suyog.destination==5){
                printf("destination_city: Bengaluru\n");
            }
        }
        else{
                if(Suyog.destination==1){
                printf("destination_city: london\n");
            }
            else if(Suyog.destination==2){
                printf("destination_city: paris\n");
            }
            else if(Suyog.destination==3){
                printf("destination_city: san-fransico\n");
            }
            else if(Suyog.destination==4){
                printf("destination_city: tokyo\n");
            }
            else if(Suyog.destination==5){
                printf("destination_city: berlin\n");
            }

        }

        printf("\n");

        if(Suyog.class==1){
        printf("class of flight:-Business\n");}
        else{
            printf("class of flight:-Economy\n");
        }
        printf("\n");

        printf("number of seats:-%d\n",Suyog.Number_of_seat);
            printf("\n");

        if(Suyog.Type_by_food==1){
        printf("food: Vegetarian\n");
        }
        else{
            printf("food: Non-vegetarian\n");
        }
        printf("\n");

        printf("Total ticket price (%d*%d):- Rs%d",Suyog.Number_of_seat,Suyog.price,Suyog.Number_of_seat*Suyog.price);


        printf("\n\n\n\n");

        printf("YOUR SEAT IS CONFIRMED!!\n");
        printf("__________________THANK YOU!!_______________\n");
        printf("__________________VISIT AGAIN :) _____________\n");

    }
    else{
        printf("your seat is not confirmed try again later :)");
    }
    getch();
    system("cls");
}
