#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

FILE *fp;

typedef struct COMPLAINT
{
    int sno;
    char CoMpLaInT[500];
} Complain;

int sn = 0;

void complaint_user();
void edit();
void update();
void deletecom();
void deleteall();
void display();
int isempty();

void complain()
{
    int choice;

    do
    {
        fp = fopen("complaint.txt", "r");
        fseek(fp, 0, SEEK_END);
        sn = ftell(fp) / sizeof(Complain);
        fclose(fp);

        printf("\nChoose the category of your complain:\n");
        printf("\n1. Airport Handling\n");
        printf("\n2. Baggage Delivery\n");
        printf("\n3. Booking and Ticketing\n");
        printf("\n4. Other\n");
        printf("\n5. I want to edit an old complaint.\n");
        printf("\n6. Display all the old complaints.\n");
        printf("\n7. I want to delete an old complaint.\n");
        printf("\n8. Delete all complaints.\n");
        printf("\n9. Go Back.\n");
        printf("\nEnter your choice from 1 to 9: ");

        scanf("%d", &choice);
        system("cls");
        switch (choice)
        {
        case 1:
            printf("\nPlease Enter your complaint here:\n\n");
            complaint_user();
            break;
        case 2:
            printf("\nPlease Enter your complaint here:\n\n");
            complaint_user();
            break;
        case 3:
            printf("\nPlease Enter your complaint here:\n\n");
            complaint_user();
            break;
        case 4:
            printf("\nPlease Enter your complaint here:\n\n");
            complaint_user();
            break;
        case 5:
            update();
            break;
        case 6:
            display();
            break;
        case 7:
            deletecom();
            break;
        case 8:
            deleteall();
            break;
        case 9:
            printf("\nExited.\n");
            getch();
            system("cls");
            return;
        default:
            printf("\nPlease Enter a valid choice.\n");
        }
    } while (choice != 9);
    return;
}

void complaint_user()
{
    Complain c1;
    fp = fopen("complaint.txt", "a");
    c1.sno = sn + 1;
    printf("%d. \t", c1.sno);
    fflush(stdin);
    gets(c1.CoMpLaInT);
    fwrite(&c1, sizeof(Complain), 1, fp);
    fclose(fp);
    printf("\nDo you wish to edit your complaint?\n\nPlease enter \"Y\" if yes and \"N\" if no: ");
    edit();
    return;
}

void edit()
{
    int found = 0, choose = 0, chose = 0;
    Complain c1, c2;
    FILE *fp1;
    char yn = '\0', x;
    scanf("%s", &yn);
    if (yn == 'y' || yn == 'Y')
    {
        system("cls");
        printf("\nThe previous complaint:\n\n");
        printf("S No.\t\tComplaint\n\n");
        fp = fopen("complaint.txt", "r");

        x = sn + 1;

        while (fread(&c1, sizeof(Complain), 1, fp))
        {
            if (c1.sno == x)
            {
                found = 1;
                printf("%d.", c1.sno);
                printf("%23s", c1.CoMpLaInT);
                printf("\n\n");
            }
        }
        if (found == 0)
        {
            printf("%d, %d record not found.", x, c1.sno);
        }
        fclose(fp);

        printf("Please Enter the edited complaint here:\n\n%d.\t", x);

        fp = fopen("complaint.txt", "r");
        fp1 = fopen("temp.txt", "w");
        while (fread(&c2, sizeof(Complain), 1, fp))
        {
            if (c2.sno == x)
            {
                c1.sno = x;
                fflush(stdin);
                gets(c1.CoMpLaInT);
                fwrite(&c1, sizeof(Complain), 1, fp1);
            }
            else
            {
                fwrite(&c2, sizeof(Complain), 1, fp1);
            }
        }
        fclose(fp1);
        fclose(fp);

        fp = fopen("complaint.txt", "w");
        fp1 = fopen("temp.txt", "r");

        while (fread(&c2, sizeof(Complain), 1, fp1))
        {
            fwrite(&c2, sizeof(Complain), 1, fp);
        }
        fclose(fp1);
        fclose(fp);
        printf("\nComplaint successfully edited.\n");
        printf("\nPress 1 to display all complaints or Press 0 to go back: ");
        scanf("%d", &choose);
        if (choose)
        {
            system("cls");
            printf("\nAll Complaints: \n\n");
            printf("S No.\t\tComplaint\n\n");
            fp = fopen("complaint.txt", "r");
            while (fread(&c1, sizeof(Complain), 1, fp))
            {
                printf("%d.", c1.sno);
                printf("%23s", c1.CoMpLaInT);
                printf("\n\n");
            }
            fclose(fp);
        }
        printf("Enter 3 to go back\n");
        scanf("%d", &choose);
        if (choose)
        {
            system("cls");
        }
    }

    else if (yn == 'n' || yn == 'N')
    {
        system("cls");
        return;
    }

    else
    {
        printf("\n-------> Please enter a valid choice.\n");
        printf("\nDo you wish to edit your complaint?\n\nPlease enter \"Y\" if yes and \"N\" if no: ");
        edit();
    }
}

void update()
{
    Complain c1, c2;
    int x, i, choose, found;
    FILE *fp1;
    system("cls");

    x = isempty();
    if (x == 1)
    {
        printf("\nThere are no old complaints to edit.\n\nEnter 3 to go back.\n");
        scanf("%d", &choose);
        if (choose == 3)
        {
            system("cls");
            return;
        }
        else
        {
            system("cls");
            return;
        }
    }

    printf("\nAll the previous Complaints: \n\n");
    printf("S No.\t\tComplaint\n\n");
    fp = fopen("complaint.txt", "r");
    while (fread(&c1, sizeof(Complain), 1, fp))
    {
        printf("%d.", c1.sno);
        printf("%23s", c1.CoMpLaInT);
        printf("\n\n");
    }
    fclose(fp);

    fp = fopen("complaint.txt", "r");
    printf("\nEnter the serial number of the complaint that you want to edit: ");
    scanf("%d", &x);

    i = x;
    while (fread(&c1, sizeof(Complain), 1, fp))
    {
        if (c1.sno == x)
        {
            found = 1;
        }
    }
    fclose(fp);

    fp = fopen("complaint.txt", "r");
    fp1 = fopen("temp.txt", "w");
    if (found == 1)
    {
        printf("\nPlease Enter the updated complaint here:\n\n%d.\t", x);

        while (fread(&c2, sizeof(Complain), 1, fp))
        {
            if (c2.sno == x)
            {
                c1.sno = x;
                fflush(stdin);
                gets(c1.CoMpLaInT);
                fwrite(&c1, sizeof(Complain), 1, fp1);
            }
            else
            {
                fwrite(&c2, sizeof(Complain), 1, fp1);
            }
        }
        fclose(fp1);
        fclose(fp);

        fp = fopen("complaint.txt", "w");
        fp1 = fopen("temp.txt", "r");

        while (fread(&c2, sizeof(Complain), 1, fp1))
        {
            fwrite(&c2, sizeof(Complain), 1, fp);
        }
        fclose(fp1);
        fclose(fp);

        printf("\nComplaint successfully updated.\n");
        printf("\nPress 1 to display all complaints or Press 0 to go back: ");
        scanf("%d", &choose);
        if (choose)
        {
            system("cls");
            printf("\nAll Complaints: \n\n");
            printf("S No.\t\tComplaint\n\n");
            fp = fopen("complaint.txt", "r");
            while (fread(&c1, sizeof(Complain), 1, fp))
            {
                printf("%d.", c1.sno);
                printf("%23s", c1.CoMpLaInT);
                printf("\n\n");
            }
            fclose(fp);
        }
        else
        {
            system("cls");
            return;
        }

        printf("Enter 3 to go back\n");
        scanf("%d", &choose);
        if (choose)
        {
            system("cls");
        }
    }

    else
    {
        printf("\nCouldn't find the complaint you wish to edit.\n\nPress 1 to enter a valid Serial number or Press 0 to go back: ");
        scanf("%d", &choose);

        if (choose)
        {
            system("cls");
            update();
        }
        else
        {
            system("cls");
            return;
        }
    }
}

void deletecom()
{
    Complain c1, c2;
    int x, i, found = 0, choose;
    FILE *fp1;
    system("cls");

    x = isempty();
    if (x == 1)
    {
        printf("\nThere are no old complaints to delete.\n\nEnter 3 to go back.\n");
        scanf("%d", &choose);
        if (choose == 3)
        {
            system("cls");
            return;
        }
        else
        {
            system("cls");
            return;
        }
    }

    if (sn >= 1)
    {
        printf("\nAll the previous Complaints: \n\n");
        printf("S No.\t\tComplaint\n\n");
        fp = fopen("complaint.txt", "r");
        while (fread(&c1, sizeof(Complain), 1, fp))
        {
            printf("%d.", c1.sno);
            printf("%23s", c1.CoMpLaInT);
            printf("\n\n");
        }
        fclose(fp);
        fp = fopen("complaint.txt", "r");
        printf("\nEnter the serial number of the complaint that you want to delete: ");
        scanf("%d", &x);

        i = x;
        while (fread(&c1, sizeof(Complain), 1, fp))
        {
            if (c1.sno == x)
            {
                found = 1;
            }
        }
        fclose(fp);

        fp = fopen("complaint.txt", "r");
        fp1 = fopen("temp.txt", "w");
        if (found == 1)
        {
            while (fread(&c1, sizeof(Complain), 1, fp))
            {
                if (c1.sno == x)
                {
                    found = 2;
                }
                else if (c1.sno == i + 1)
                {
                    c1.sno = i;
                    fwrite(&c1, sizeof(Complain), 1, fp1);
                    i++;
                }
                else if (c1.sno < x)
                {
                    fwrite(&c1, sizeof(Complain), 1, fp1);
                }
                else if (x == 0)
                {
                    system("cls");
                    return;
                }
            }
            fclose(fp1);
            fclose(fp);

            if (found == 2)
            {
                fp = fopen("complaint.txt", "w");
                fp1 = fopen("temp.txt", "r");

                while (fread(&c1, sizeof(Complain), 1, fp1))
                {
                    fwrite(&c1, sizeof(Complain), 1, fp);
                }

                fclose(fp);
                fclose(fp1);
            }

            printf("\nComplaint successfully deleted.\n");
            printf("\nPress 1 to display all complaints or Press 0 to go back: ");
            scanf("%d", &choose);
            if (choose)
            {
                system("cls");
                printf("\nAll Complaints: \n\n");
                printf("S No.\t\tComplaint\n\n");
                fp = fopen("complaint.txt", "r");
                while (fread(&c1, sizeof(Complain), 1, fp))
                {
                    printf("%d.", c1.sno);
                    printf("%23s", c1.CoMpLaInT);
                    printf("\n\n");
                }
                fclose(fp);
            }
            else
            {
                system("cls");
                return;
            }
            printf("Enter 3 to go back\n");
            scanf("%d", &choose);
            if (choose)
            {
                system("cls");
            }
        }

        else
        {
            printf("\nCouldn't find the complaint you wish to delete.\n\nPress 1 to enter a valid Serial number or Press 0 to go back: ");
            scanf("%d", &choose);

            if (choose)
            {
                system("cls");
                deletecom();
            }
            else
            {
                system("cls");
                return;
            }
        }
    }
}

void display()
{
    Complain c1;
    int choose, x = 0;
    system("cls");

    x = isempty();
    if (x == 1)
    {
        printf("\nThere are no old complaints to display.\n\nEnter 3 to go back.\n");
        scanf("%d", &choose);
        if (choose == 3)
        {
            system("cls");
            return;
        }
        else
        {
            system("cls");
            return;
        }
    }

    fp = fopen("complaint.txt", "r");
    printf("\nAll the previous Complaints: \n\n");
    printf("S No.\tComplaint\n\n");
    while (fread(&c1, sizeof(Complain), 1, fp))
    {
        printf("%-8d", c1.sno);
        printf("%s", c1.CoMpLaInT);
        printf("\n\n");
    }
    fclose(fp);
    printf("Enter 3 to go back\n");
    scanf("%d", &choose);
    if (choose)
    {
        system("cls");
        return;
    }
}

void deleteall()
{
    Complain c1, c2;
    int choose = 0, i = 0, x;
    char chose;
    system("cls");

    x = isempty();
    if (x == 1)
    {
        printf("\nThere are no old complaints to delete.\n\nEnter 3 to go back.\n");
        scanf("%d", &choose);
        if (choose == 3)
        {
            system("cls");
            return;
        }
        else
        {
            system("cls");
            return;
        }
    }

    else
    {
        printf("\nAll the previous Complaints: \n\n");
        printf("S No.\t\tComplaint\n\n");
        fp = fopen("complaint.txt", "r");
        while (fread(&c1, sizeof(Complain), 1, fp))
        {
            printf("%d.", c1.sno);
            printf("%23s", c1.CoMpLaInT);
            printf("\n\n");
        }
        fclose(fp);

        printf("\nAre you sure you want to delete All The Complaints?\n\nPlease enter \"Y\" if yes and \"N\" if no: ");
        scanf("%s", &chose);

        if (chose == 'Y' || chose == 'y')
        {
            fp = fopen("complaint.txt", "w");
            fwrite(NULL, sizeof(Complain), 1, fp);
            fclose(fp);

            printf("\nAll Complaints Cleared.\n");
            printf("\nEnter 3 to go back\n");
            scanf("%d", &i);
            if (i)
            {
                system("cls");
                return;
            }
        }

        else if (chose == 'N' || chose == 'n')
        {
            system("cls");
            return;
        }

        else
        {
            system("cls");
            printf("\n-------> Please enter a valid choice.\n");
            printf("\nEnter 3 to go back\n");
            scanf("%d", &choose);
            if (choose)
            {
                system("cls");
                deleteall();
            }
        }
    }
}

int isempty()
{
    int a;
    Complain c1;
    fp = fopen("complaint.txt", "rb");
    fseek(fp, 0, SEEK_END);
    a = ftell(fp) / sizeof(Complain);
    fclose(fp);
    if (a == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
