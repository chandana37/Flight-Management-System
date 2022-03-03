#include <stdio.h>
#include "booking.h"
#include "complainmod.h"
#include "about.h"
#include "manage.h"
#include "routes.h"

int main()
{
    int opt;
    system("COLOR 4f");
    do
    {
        printf("\n\n\t\t\t\t ************************************************************************");
        printf("\n\t\t\t\t                   Welcome to FLYHIGH's airline system                   ");
        printf("\n\t\t\t\t   *******************************************************************");
        printf("\n\n\t\t\t\t   ************************* MENU ************************************");
        printf("\n\t\t\t\t Please enter your choice from below (1-13):");
        printf("\n\n\t\t\t\t 0. Booking");
        printf("\n\n\t\t\t\t 1. Routes");
        printf("\n\n\t\t\t\t 2. complain");
        printf("\n\n\t\t\t\t 3. About");
        printf("\n\n\t\t\t\t 4. Management");
        printf("\n\n\t\t\t\t 5. Exit");
        printf("\n\n\t\t\t\t ********************************************************************");
        printf("\n\n\t\t\t\t Feel free to contact on 7721827790");
        printf("\n\n\t\t\t\t Enter your choice : ");

        scanf("%d", &opt);
        system("cls");

        switch (opt)
        {
        case 0:
            booking();
            break;
        case 1:
            routes();
            break;
        case 2:
            complain();
            break;
        case 3:
            about();
            break;
        case 4:
            manage();
            break;
        case 5:
            printf("Exiting... Thankyou..");
            break;
        default:
            printf("\n\n\t SORRY INVALID CHOICE!");
            printf("\n\n\t PLEASE CHOOSE FROM 1-13");
            printf("\n\n\t Do not forget to chose from 1-13");
        }
    } while (opt != 5);

    return 0;
}
