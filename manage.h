#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef struct Airplane
{
    char Name[50];
    int flight_id;
    int capacity;
    struct arrival
    {
        int hh;
        int mm;
    } arrive;
    struct departure
    {
        int hh;
        int mm;
    } depart;
    char Class[50];
    char status[50];
    struct delay
    {
        int hh;
        int mm;
    } delay_time;
    char tm[50];
} flight;

void manage();

char *Timer()
{
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    return asctime(timeinfo);
}

void Up_date(int id, int hh, int mm, int data)
{
    flight fg;
    FILE *f1, *f2;
    if (data == 1)
    {
        f1 = fopen("data.txt", "rb");
        f2 = fopen("temp.txt", "wb");
    }
    else
    {
        f1 = fopen("data1.txt", "rb");
        f2 = fopen("temp.txt", "wb");
    }
    while (fread(&fg, sizeof(flight), 1, f1))
    {
        if (fg.flight_id == id && fg.arrive.hh == hh && fg.arrive.mm == mm)
        {
            printf("Enter the new capacity : ");
            scanf("%d", &fg.capacity);
            printf("Enter the new class (VIP/VVIP/PUBLIC) : ");
            while (1)
            {
                char ch[5];
                scanf("%s", ch);
                if (!strcmp(ch, "VIP") || !strcmp(ch, "VVIP") || !strcmp(ch, "PUBLIC"))
                {
                    strcpy(fg.Class, ch);
                    break;
                }
                else
                {
                    printf("Enter correctly \n");
                }
            }
            char *t = Timer();
            strcpy(fg.tm, t);
        }
        fwrite(&fg, sizeof(flight), 1, f2);
    }
    fclose(f1);
    fclose(f2);
    if (data == 1)
    {
        f1 = fopen("data.txt", "wb");
        f2 = fopen("temp.txt", "rb");
    }
    else
    {
        f1 = fopen("data1.txt", "wb");
        f2 = fopen("temp.txt", "rb");
    }
    while (fread(&fg, sizeof(flight), 1, f2))
    {
        fwrite(&fg, sizeof(flight), 1, f1);
    }
    fclose(f1);
    fclose(f2);
    printf("Updated successfully ..");
    getch();
    manage();
}

void Insert()
{
    FILE *fp, *fp1;
    int data;
    int choice;
    while (1)
    {
        printf("Enter the number 1 or 2 for insertion/updation in list 1 or list 2 : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            fp = fopen("data.txt", "ab");
            data = 1;
            break;
        }
        else if (choice == 2)
        {
            fp = fopen("data1.txt", "ab");
            data = 2;
            break;
        }
        else
        {
            printf("Please enter 1 or 2 only..");
        }
    }

    if (fp == NULL)
    {
        printf("Data cannot be saved.");
        return;
    }
    flight fl;
    flight f;

    fl.delay_time.hh = 0;
    fl.delay_time.mm = 0;
    strcpy(fl.status, "NULL");
    char *t = Timer();
    strcpy(fl.tm, t);

    printf("Enter the arrival time(24 hr format) in HH MM format : ");
    while (1)
    {
        int hh, mm;
        scanf("%d %d", &hh, &mm);
        if (hh <= 24 && mm <= 60 && hh >= 0 && mm >= 0)
        {
            fl.arrive.hh = hh;
            fl.arrive.mm = mm;
            break;
        }
        else
        {
            printf("Enter Correctly...");
        }
    }

    while (1)
    {
        int id;
        printf("Enter the flight id(can be 1-100) : ");
        scanf("%d", &id);
        if (id > 0 && id < 101)
        {
            fl.flight_id = id;
            printf("Checking the data..\n");
            break;
        }
        else
        {
            printf("PLease choose the number between 1 to 100 (inclusive)..");
        }
    }

    if (choice == 1)
        fp1 = fopen("data.txt", "rb");
    else if (choice == 2)
        fp1 = fopen("data1.txt", "rb");
    while (fread(&f, sizeof(flight), 1, fp1))
    {
        if (f.flight_id == fl.flight_id && f.arrive.hh == fl.arrive.hh && f.arrive.mm == fl.arrive.mm)
        {
            fclose(fp);
            fclose(fp1);
            int ch;
            printf("Given flight is already in the list.. Enter 1 for updation or 2 for exit : ");
            scanf("%d", &ch);
            if (ch == 1)
            {
                Up_date(f.flight_id, f.arrive.hh, f.arrive.mm, data);
            }
            else if (ch == 2)
            {
                printf("Exiting ..");
                return;
            }
            else
            {
                printf("Please choose either 1 or 2 number..");
            }
        }
    }

    printf("Enter the flight name : ");
    fflush(stdin);
    gets(fl.Name);
    for (int i = 0; fl.Name[i] != '\0'; i++)
    {
        if (fl.Name[i] >= 'a' && fl.Name[i] <= 'z')
        {
            fl.Name[i] = fl.Name[i] - 32;
        }
    }

    printf("Enter the capacity of flight : ");
    scanf("%d", &fl.capacity);

    printf("Enter the departure time(24 hr format) in HH MM format : ");
    while (1)
    {
        int hh, mm;
        scanf("%d %d", &hh, &mm);
        if (hh <= 24 && mm <= 60 && hh >= 0 && mm >= 0)
        {
            fl.depart.hh = hh;
            fl.depart.mm = mm;
            break;
        }
        else
        {
            printf("Enter Correctly...");
        }
    }

    printf("Enter the class (VIP/VVIP/PUBLIC) : ");
    while (1)
    {
        char ch[5];
        scanf("%s", ch);
        if (!strcmp(ch, "VIP") || !strcmp(ch, "VVIP") || !strcmp(ch, "PUBLIC"))
        {
            strcpy(fl.Class, ch);
            break;
        }
        else
        {
            printf("Enter correctly \n");
        }
    }
    if (fwrite(&fl, sizeof(flight), 1, fp))
    {
        printf("Data inserted successfully ... Thankyou");
    }
    else
    {
        printf("Data not inserted. Please try agin.");
    }

    fclose(fp);
    fclose(fp1);
}

void Display(int choice)
{
    flight fl;
    FILE *fp;
    if (choice == 1)
    {
        fp = fopen("data.txt", "rb");
    }
    else if (choice == 2)
    {
        fp = fopen("data1.txt", "rb");
    }
    else if (choice == 3)
    {
        fp = fopen("temp.txt", "rb");
    }
    printf("ID   NAME           ARRIVAL Departure CLASS   CAPACITY  STATUS  DELAY    TIME OF INSERTION/UPDATION\n\n");
    while (fread(&fl, sizeof(flight), 1, fp))
    {
        printf("%-5d%-15s", fl.flight_id, fl.Name);
        printf("%2d:%-5d", fl.arrive.hh, fl.arrive.mm);
        printf("%2d:%-7d", fl.depart.hh, fl.depart.mm);
        printf("%-8s%-10d%-8s", fl.Class, fl.capacity, fl.status);
        printf("%d:%-7d%s", fl.delay_time.hh, fl.delay_time.mm, fl.tm);
        printf("\n");
    }
    fclose(fp);
}

void Delete(int choice, int id)
{
    flight fl;
    FILE *fp, *fp1;
    int found = 0;

    if (choice == 1)
    {
        fp = fopen("data.txt", "rb");
        fp1 = fopen("temp.txt", "wb");
    }
    else if (choice == 2)
    {
        fp = fopen("data1.txt", "rb");
        fp1 = fopen("temp.txt", "wb");
    }

    if (fp == NULL || fp1 == NULL)
    {
        printf("Data cannot be deleted at this moment. Please try again..");
        return;
    }

    while (fread(&fl, sizeof(flight), 1, fp))
    {
        if (fl.flight_id == id)
        {
            found = 1;
        }
        else
        {
            fwrite(&fl, sizeof(flight), 1, fp1);
        }
    }
    fclose(fp);
    fclose(fp1);
    if (found)
    {
        if (choice == 1)
        {
            fp = fopen("data.txt", "wb");
            fp1 = fopen("temp.txt", "rb");
        }
        else
        {
            fp = fopen("data1.txt", "wb");
            fp1 = fopen("temp.txt", "rb");
        }

        while (fread(&fl, sizeof(flight), 1, fp1))
        {
            fwrite(&fl, sizeof(flight), 1, fp);
        }

        printf("Data has been successfully deleted..");
    }
    else
    {
        printf("The given id is not found..");
    }
    fclose(fp);
    fclose(fp1);
}

void getNumFlights(int choice)
{
    flight fl;
    FILE *fp;
    if (choice == 1)
    {
        fp = fopen("data.txt", "rb");
    }
    else if (choice == 2)
    {
        fp = fopen("data1.txt", "rb");
    }
    fseek(fp, 0, SEEK_END);
    int n = ftell(fp) / sizeof(flight);
    printf("No. of flights available are : %d", n);
    fclose(fp);
}

int is_Empty(int choice)
{
    flight fl;
    FILE *fp;
    if (choice == 1)
    {
        fp = fopen("data.txt", "rb");
    }
    else if (choice == 2)
    {
        fp = fopen("data1.txt", "rb");
    }
    fseek(fp, 0, SEEK_END);
    int n = ftell(fp) / sizeof(flight);
    fclose(fp);
    if (n == 0)
    {
        return 1;
    }
    return 0;
}

int isFull(int choice)
{
    flight fl;
    FILE *fp;
    if (choice == 1)
    {
        fp = fopen("data.txt", "rb");
    }
    else if (choice == 2)
    {
        fp = fopen("data1.txt", "rb");
    }
    fseek(fp, 0, SEEK_END);
    int n = ftell(fp) / sizeof(flight);
    fclose(fp);
    if (n == 10)
    {
        return 1;
    }
    return 0;
}

void updateFlightStatus(int data)
{
    flight fg;
    FILE *f1, *f2;
    if (data == 1)
    {
        f1 = fopen("data.txt", "rb");
        f2 = fopen("temp.txt", "wb");
    }
    else
    {
        f1 = fopen("data1.txt", "rb");
        f2 = fopen("temp.txt", "wb");
    }
    int id, hh, mm;
    printf("Enter the id of flight : ");
    scanf("%d", &id);
    printf("Enter the arrival time(24 hr format) in HH MM format : ");
    while (1)
    {
        scanf("%d %d", &hh, &mm);
        if (hh <= 24 && mm <= 60 && hh >= 0 && mm >= 0)
        {
            break;
        }
        else
        {
            printf("Enter Correctly...");
        }
    }
    int found = 0;
    while (fread(&fg, sizeof(flight), 1, f1))
    {
        if (fg.flight_id == id && fg.arrive.hh == hh && fg.arrive.mm == mm)
        {
            found = 1;
            printf("Enter the delay time in HH MM format : ");
            scanf("%d %d", &fg.delay_time.hh, &fg.delay_time.mm);
            printf("Enter the status (On time/Delay/Cancelled) : ");
            while (1)
            {
                char ch[10];
                fflush(stdin);
                gets(ch);
                if (!strcmp(ch, "On time") || !strcmp(ch, "Delay") || !strcmp(ch, "Cancelled"))
                {
                    strcpy(fg.status, ch);
                    break;
                }
                else
                {
                    printf("Enter correctly \n");
                }
            }
            char *t = Timer();
            strcpy(fg.tm, t);
        }
        fwrite(&fg, sizeof(flight), 1, f2);
    }
    fclose(f1);
    fclose(f2);
    if (data == 1)
    {
        f1 = fopen("data.txt", "wb");
        f2 = fopen("temp.txt", "rb");
    }
    else
    {
        f1 = fopen("data1.txt", "wb");
        f2 = fopen("temp.txt", "rb");
    }
    while (fread(&fg, sizeof(flight), 1, f2))
    {
        fwrite(&fg, sizeof(flight), 1, f1);
    }
    fclose(f1);
    fclose(f2);
    if (found == 0)
    {
        printf("DATA not found..");
        return;
    }
    printf("Updated successfully ..");
}

void getLongestStay(int choice)
{
    flight *fl1, fl;
    FILE *fp1;
    if (choice == 1)
        fp1 = fopen("data.txt", "rb");
    else if (choice == 2)
        fp1 = fopen("data1.txt", "rb");
    fseek(fp1, 0, SEEK_END);
    int n1 = ftell(fp1) / sizeof(flight);
    fl1 = (flight *)calloc(n1, sizeof(flight));
    rewind(fp1);

    for (int i = 0; i < n1; i++)
    {
        fread(&fl1[i], sizeof(flight), 1, fp1);
    }
    int max = INT_MIN;
    for (int i = 0; i < n1; i++)
    {
        if (max < abs(fl1[i].arrive.hh * 60 + fl1[i].arrive.mm - fl1[i].depart.hh * 60 - fl1[i].depart.mm))
        {
            max = abs(fl1[i].arrive.hh * 60 + fl1[i].arrive.mm - fl1[i].depart.hh * 60 - fl1[i].depart.mm);
            fl = fl1[i];
        }
    }
    printf("\nThe flight with longest stay in the above list is : \n");
    printf("ID   NAME      ARRIVAL Departure CLASS   CAPACITY  STATUS  DELAY    TIME OF INSERTION/UPDATION\n\n");
    printf("%-5d%-10s", fl.flight_id, fl.Name);
    printf("%2d:%-5d", fl.arrive.hh, fl.arrive.mm);
    printf("%2d:%-7d", fl.depart.hh, fl.depart.mm);
    printf("%-8s%-10d%-8s", fl.Class, fl.capacity, fl.status);
    printf("%d:%-7d%s", fl.delay_time.hh, fl.delay_time.mm, fl.tm);
    printf("\n");

    free(fl1);
    fclose(fp1);
}

void listUnique(int choice)
{
    flight *fl1, *fl3, fl;
    FILE *fp1, *fp2;
    if (choice == 1)
        fp1 = fopen("data.txt", "rb");
    else if (choice == 2)
        fp1 = fopen("data1.txt", "rb");
    fseek(fp1, 0, SEEK_END);
    int n1 = ftell(fp1) / sizeof(flight);
    fl1 = (flight *)calloc(n1, sizeof(flight));
    fl3 = (flight *)calloc(n1, sizeof(flight));
    rewind(fp1);
    int freq[n1];
    for (int i = 0; i < n1; i++)
    {
        fread(&fl1[i], sizeof(flight), 1, fp1);
        freq[i] = -1;
    }
    for (int i = 0; i < n1; i++)
    {
        for (int j = i + 1; j < n1; j++)
        {
            if (fl1[i].flight_id == fl1[j].flight_id && strcmp(fl1[i].Name, fl1[j].Name) == 0 && ((fl1[i].delay_time.hh - fl1[j].delay_time.hh) < 0 || ((fl1[i].delay_time.hh - fl1[j].delay_time.hh) == 0 && (fl1[i].delay_time.mm - fl1[j].delay_time.mm) < 0)))
            {
                fl = fl1[i];
                fl1[i] = fl1[j];
                fl1[j] = fl;
            }
        }
    }
    int count;
    /* Find frequency of each element */
    for (int i = 0; i < n1; i++)
    {
        count = 1;
        for (int j = i + 1; j < n1; j++)
        {
            if (fl1[i].flight_id == fl1[j].flight_id && strcmp(fl1[i].Name, fl1[j].Name) == 0)
            {
                count++;
                freq[j] = 0;
            }
        }
        freq[i] = count;
    }

    int k = 0;
    for (int i = 0; i < n1; i++)
    {
        if (freq[i] == 1)
        {
            fl3[k++] = fl1[i];
        }
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = i + 1; j < k; j++)
        {
            if (fl3[i].flight_id > fl3[j].flight_id)
            {
                fl = fl3[i];
                fl3[i] = fl3[j];
                fl3[j] = fl;
            }
            else if (fl3[i].flight_id == fl3[j].flight_id && strcmp(fl3[i].Name, fl3[j].Name) > 0)
            {
                fl = fl3[i];
                fl3[i] = fl3[j];
                fl3[j] = fl;
            }
        }
    }
    fclose(fp1);
    if (choice == 1)
        fp1 = fopen("data.txt", "wb");
    else if (choice == 2)
        fp1 = fopen("data1.txt", "wb");
    for (int i = 0; i < k; i++)
    {
        fwrite(&fl3[i], sizeof(flight), 1, fp1);
    }
    printf("\nThe above list is changed to unique list and it is : \n");
    printf("ID   NAME      ARRIVAL Departure CLASS   CAPACITY  STATUS  DELAY    TIME OF INSERTION/UPDATION\n\n");
    for (int i = 0; i < k; i++)
    {
        printf("%-5d%-10s", fl3[i].flight_id, fl3[i].Name);
        printf("%2d:%-5d", fl3[i].arrive.hh, fl3[i].arrive.mm);
        printf("%2d:%-7d", fl3[i].depart.hh, fl3[i].depart.mm);
        printf("%-8s%-10d%-8s", fl3[i].Class, fl3[i].capacity, fl3[i].status);
        printf("%d:%-7d%s", fl3[i].delay_time.hh, fl3[i].delay_time.mm, fl3[i].tm);
        printf("\n");
    }

    free(fl1);
    free(fl3);
    fclose(fp1);
}

void listUnion()
{
    flight *fl1, *fl2, *fl3, fl;
    FILE *fp1, *fp2;
    fp1 = fopen("data.txt", "rb");
    fp2 = fopen("data1.txt", "rb");
    fseek(fp1, 0, SEEK_END);
    fseek(fp2, 0, SEEK_END);
    int n1 = ftell(fp1) / sizeof(flight);
    int n2 = ftell(fp2) / sizeof(flight);
    fl1 = (flight *)calloc(n1, sizeof(flight));
    fl2 = (flight *)calloc(n2, sizeof(flight));
    fl3 = (flight *)calloc(n1 + n2, sizeof(flight));
    rewind(fp1);
    rewind(fp2);

    for (int i = 0; i < n1; i++)
    {
        fread(&fl1[i], sizeof(flight), 1, fp1);
    }
    for (int i = 0; i < n2; i++)
    {
        fread(&fl2[i], sizeof(flight), 1, fp2);
    }
    int k = 0;
    for (int i = 0; i < n1; i++)
    {
        fl3[k++] = fl1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        int found = 0;
        for (int j = 0; j < n1; j++)
        {
            if (strcmp(fl2[i].Name, fl1[j].Name) == 0 && fl2[i].flight_id == fl1[j].flight_id)
            {
                found = 1;
            }
        }
        if (found == 0)
        {
            fl3[k++] = fl2[i];
        }
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = i + 1; j < k; j++)
        {
            if (fl3[i].flight_id > fl3[j].flight_id)
            {
                fl = fl3[i];
                fl3[i] = fl3[j];
                fl3[j] = fl;
            }
            else if (fl3[i].flight_id == fl3[j].flight_id && strcmp(fl3[i].Name, fl3[j].Name) > 0)
            {
                fl = fl3[i];
                fl3[i] = fl3[j];
                fl3[j] = fl;
            }
        }
    }
    printf("\nThe above two lists union is : \n");
    printf("ID   NAME      ARRIVAL Departure CLASS   CAPACITY  STATUS  DELAY    TIME OF INSERTION/UPDATION\n\n");
    for (int i = 0; i < k; i++)
    {
        printf("%-5d%-10s", fl3[i].flight_id, fl3[i].Name);
        printf("%2d:%-5d", fl3[i].arrive.hh, fl3[i].arrive.mm);
        printf("%2d:%-7d", fl3[i].depart.hh, fl3[i].depart.mm);
        printf("%-8s%-10d%-8s", fl3[i].Class, fl3[i].capacity, fl3[i].status);
        printf("%d:%-7d%s", fl3[i].delay_time.hh, fl3[i].delay_time.mm, fl3[i].tm);
        printf("\n");
    }

    free(fl1);
    free(fl2);
    free(fl3);
    fclose(fp1);
    fclose(fp2);
}

void listIntersection()
{
    flight *fl1, *fl2, *fl3, fl;
    FILE *fp1, *fp2;
    fp1 = fopen("data.txt", "rb");
    fp2 = fopen("data1.txt", "rb");
    fseek(fp1, 0, SEEK_END);
    fseek(fp2, 0, SEEK_END);
    int n1 = ftell(fp1) / sizeof(flight);
    int n2 = ftell(fp2) / sizeof(flight);
    fl1 = (flight *)calloc(n1, sizeof(flight));
    fl2 = (flight *)calloc(n2, sizeof(flight));
    fl3 = (flight *)calloc(n1 + n2, sizeof(flight));
    rewind(fp1);
    rewind(fp2);

    for (int i = 0; i < n1; i++)
    {
        fread(&fl1[i], sizeof(flight), 1, fp1);
    }
    for (int i = 0; i < n2; i++)
    {
        fread(&fl2[i], sizeof(flight), 1, fp2);
    }
    int k = 0;
    for (int i = 0; i < n1; i++)
    {
        int found = 0;
        int data = -1;
        for (int j = 0; j < n2; j++)
        {
            if (strcmp(fl1[i].Name, fl2[j].Name) == 0 && fl1[i].flight_id == fl2[j].flight_id)
            {
                found = 1;
                data = j;
            }
        }
        if (found == 1)
        {
            if ((fl1[i].delay_time.hh - fl2[data].delay_time.hh) >= 0 && (fl1[i].delay_time.mm - fl2[data].delay_time.mm) > 0)
                fl3[k++] = fl2[data];
            else
                fl3[k++] = fl1[i];
        }
    }
    //Sorting
    for (int i = 0; i < k; i++)
    {
        for (int j = i + 1; j < k; j++)
        {
            if (fl3[i].flight_id > fl3[j].flight_id)
            {
                fl = fl3[i];
                fl3[i] = fl3[j];
                fl3[j] = fl;
            }
            else if (fl3[i].flight_id == fl3[j].flight_id && strcmp(fl3[i].Name, fl3[j].Name) > 0)
            {
                fl = fl3[i];
                fl3[i] = fl3[j];
                fl3[j] = fl;
            }
        }
    }
    printf("\nThe above two lists intersection is : \n");
    printf("ID   NAME      ARRIVAL Departure CLASS   CAPACITY  STATUS  DELAY    TIME OF INSERTION/UPDATION\n\n");
    for (int i = 0; i < k; i++)
    {
        printf("%-5d%-10s", fl3[i].flight_id, fl3[i].Name);
        printf("%2d:%-5d", fl3[i].arrive.hh, fl3[i].arrive.mm);
        printf("%2d:%-7d", fl3[i].depart.hh, fl3[i].depart.mm);
        printf("%-8s%-10d%-8s", fl3[i].Class, fl3[i].capacity, fl3[i].status);
        printf("%d:%-7d%s", fl3[i].delay_time.hh, fl3[i].delay_time.mm, fl3[i].tm);
        printf("\n");
    }

    free(fl1);
    free(fl2);
    free(fl3);
    fclose(fp1);
    fclose(fp2);
}

void listDifference(int choice)
{
    flight *fl1, *fl2, *fl3, fl;
    FILE *fp1, *fp2;
    if (choice == 1)
    {
        fp1 = fopen("data.txt", "rb");
        fp2 = fopen("data1.txt", "rb");
    }
    else
    {
        fp2 = fopen("data.txt", "rb");
        fp1 = fopen("data1.txt", "rb");
    }
    fseek(fp1, 0, SEEK_END);
    fseek(fp2, 0, SEEK_END);
    int n1 = ftell(fp1) / sizeof(flight);
    int n2 = ftell(fp2) / sizeof(flight);
    fl1 = (flight *)calloc(n1, sizeof(flight));
    fl2 = (flight *)calloc(n2, sizeof(flight));
    fl3 = (flight *)calloc(n1 + n2, sizeof(flight));
    rewind(fp1);
    rewind(fp2);

    for (int i = 0; i < n1; i++)
    {
        fread(&fl1[i], sizeof(flight), 1, fp1);
    }
    for (int i = 0; i < n2; i++)
    {
        fread(&fl2[i], sizeof(flight), 1, fp2);
    }
    int k = 0;
    for (int i = 0; i < n1; i++)
    {
        int found = 0;
        for (int j = 0; j < n2; j++)
        {
            if (strcmp(fl1[i].Name, fl2[j].Name) == 0 && fl1[i].flight_id == fl2[j].flight_id)
            {
                found = 1;
            }
        }
        if (found == 0)
        {
            fl3[k++] = fl1[i];
        }
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = i + 1; j < k; j++)
        {
            if (fl3[i].flight_id > fl3[j].flight_id)
            {
                fl = fl3[i];
                fl3[i] = fl3[j];
                fl3[j] = fl;
            }
            else if (fl3[i].flight_id == fl3[j].flight_id && strcmp(fl3[i].Name, fl3[j].Name) > 0)
            {
                fl = fl3[i];
                fl3[i] = fl3[j];
                fl3[j] = fl;
            }
        }
    }
    if (choice == 1)
        printf("\nList1 - List2 is : \n");
    else if (choice == 2)
        printf("\nList2 - List1 is : \n");
    printf("ID   NAME      ARRIVAL Departure CLASS   CAPACITY  STATUS  DELAY    TIME OF INSERTION/UPDATION\n\n");
    for (int i = 0; i < k; i++)
    {
        printf("%-5d%-10s", fl3[i].flight_id, fl3[i].Name);
        printf("%2d:%-5d", fl3[i].arrive.hh, fl3[i].arrive.mm);
        printf("%2d:%-7d", fl3[i].depart.hh, fl3[i].depart.mm);
        printf("%-8s%-10d%-8s", fl3[i].Class, fl3[i].capacity, fl3[i].status);
        printf("%d:%-7d%s", fl3[i].delay_time.hh, fl3[i].delay_time.mm, fl3[i].tm);
        printf("\n");
    }
    free(fl1);
    free(fl2);
    free(fl3);
    fclose(fp1);
    fclose(fp2);
}

void listSymmetricDifference()
{
    flight *fl1, *fl2, *fl3, fl;
    FILE *fp1, *fp2;
    fp1 = fopen("data.txt", "rb");
    fp2 = fopen("data1.txt", "rb");
    fseek(fp1, 0, SEEK_END);
    fseek(fp2, 0, SEEK_END);
    int n1 = ftell(fp1) / sizeof(flight);
    int n2 = ftell(fp2) / sizeof(flight);
    fl1 = (flight *)calloc(n1, sizeof(flight));
    fl2 = (flight *)calloc(n2, sizeof(flight));
    fl3 = (flight *)calloc(n1 + n2, sizeof(flight));
    rewind(fp1);
    rewind(fp2);

    for (int i = 0; i < n1; i++)
    {
        fread(&fl1[i], sizeof(flight), 1, fp1);
    }
    for (int i = 0; i < n2; i++)
    {
        fread(&fl2[i], sizeof(flight), 1, fp2);
    }
    int k = 0;
    for (int i = 0; i < n1; i++)
    {
        int found = 0;
        for (int j = 0; j < n2; j++)
        {
            if (strcmp(fl1[i].Name, fl2[j].Name) == 0 && fl1[i].flight_id == fl2[j].flight_id)
            {
                found = 1;
            }
        }
        if (found == 0)
        {
            fl3[k++] = fl1[i];
        }
    }
    for (int i = 0; i < n2; i++)
    {
        int found = 0;
        for (int j = 0; j < n1; j++)
        {
            if (strcmp(fl1[i].Name, fl2[j].Name) == 0 && fl1[i].flight_id == fl2[j].flight_id)
            {
                found = 1;
            }
        }
        if (found == 0)
        {
            fl3[k++] = fl2[i];
        }
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = i + 1; j < k; j++)
        {
            if (fl3[i].flight_id > fl3[j].flight_id)
            {
                fl = fl3[i];
                fl3[i] = fl3[j];
                fl3[j] = fl;
            }
            else if (fl3[i].flight_id == fl3[j].flight_id && strcmp(fl3[i].Name, fl3[j].Name) > 0)
            {
                fl = fl3[i];
                fl3[i] = fl3[j];
                fl3[j] = fl;
            }
        }
    }
    printf("\nThe above two lists symmetric difference is : \n");
    printf("ID   NAME      ARRIVAL Departure CLASS   CAPACITY  STATUS  DELAY    TIME OF INSERTION/UPDATION\n\n");
    for (int i = 0; i < k; i++)
    {
        printf("%-5d%-10s", fl3[i].flight_id, fl3[i].Name);
        printf("%2d:%-5d", fl3[i].arrive.hh, fl3[i].arrive.mm);
        printf("%2d:%-7d", fl3[i].depart.hh, fl3[i].depart.mm);
        printf("%-8s%-10d%-8s", fl3[i].Class, fl3[i].capacity, fl3[i].status);
        printf("%d:%-7d%s", fl3[i].delay_time.hh, fl3[i].delay_time.mm, fl3[i].tm);
        printf("\n");
    }
    free(fl1);
    free(fl2);
    free(fl3);
    fclose(fp1);
    fclose(fp2);
}

void manage()
{
    system("COLOR 4f");
    int opt, e = 0, f = 0;
    int emp, del, full, num, delid, disp, ld, ls, data, lu;
    do
    {
        printf("\n\n\t\t\t\t ************************************************************************");
        printf("\n\t\t\t\t                   Welcome to FLYHIGH's airline system                   ");
        printf("\n\t\t\t\t   *******************************************************************");
        printf("\n\n\t\t\t\t   ************************* MENU ************************************");
        printf("\n\t\t\t\t Please enter your choice from below (1-13):");
        printf("\n\n\t\t\t\t 0. Display the records");
        printf("\n\n\t\t\t\t 1. Insert a record");
        printf("\n\n\t\t\t\t 2. Delete a record");
        printf("\n\n\t\t\t\t 3. Get the number of flights");
        printf("\n\n\t\t\t\t 4. Check whether list is empty");
        printf("\n\n\t\t\t\t 5. Check whether list is full");
        printf("\n\n\t\t\t\t 6. Update flight status");
        printf("\n\n\t\t\t\t 7. Get the longest stay in all flights");
        printf("\n\n\t\t\t\t 8. Remove duplicates(Make list unique)");
        printf("\n\n\t\t\t\t 9. Make union list");
        printf("\n\n\t\t\t\t 10. Make intersection list");
        printf("\n\n\t\t\t\t 11. Get difference between lists");
        printf("\n\n\t\t\t\t 12. Get Symmetric difference between lists");
        printf("\n\n\t\t\t\t 13. EXIT");
        printf("\n\n\t\t\t\t ********************************************************************");
        printf("\n\n\t\t\t\t Feel free to contact on 7721827790");
        printf("\n\n\t\t\t\t Enter your choice : ");

        scanf("%d", &opt);
        system("cls");

        switch (opt)
        {
        case 0:
            while (1)
            {
                printf("Enter the number 1 or 2 or 3 for display of list 1 or list 2 or temp : ");
                scanf("%d", &disp);
                if (disp == 1)
                {
                    break;
                }
                else if (disp == 2)
                {
                    break;
                }
                else if (disp == 3)
                {
                    break;
                }
                else
                {
                    printf("Please enter 1 or 2 or 3 only..");
                }
            }
            Display(disp);
            break;
        case 1:
            Insert();
            break;
        case 2:
            while (1)
            {
                printf("Enter the number 1 or 2 for deletion in list 1 or list 2 : ");
                scanf("%d", &del);
                if (del == 1)
                {
                    break;
                }
                else if (del == 2)
                {
                    break;
                }
                else
                {
                    printf("Please enter 1 or 2 only..");
                }
            }
            if (del == 1)
                Display(1);
            else if (del == 2)
                Display(2);
            printf("Enter the id of the flight to be deleted : ");
            scanf("%d", &delid);
            Delete(del, delid);
            break;
        case 3:
            while (1)
            {
                printf("Enter the number 1 or 2 for knowing about list 1 or list 2 : ");
                scanf("%d", &num);
                if (num == 1)
                {
                    break;
                }
                else if (num == 2)
                {
                    break;
                }
                else
                {
                    printf("Please enter 1 or 2 only..");
                }
            }
            getNumFlights(num);
            break;
        case 4:
            while (1)
            {
                printf("Enter the number 1 or 2 for knowing about list 1 or list 2 : ");
                scanf("%d", &emp);
                if (emp == 1)
                {
                    break;
                }
                else if (emp == 2)
                {
                    break;
                }
                else
                {
                    printf("Please enter 1 or 2 only..");
                }
            }
            e = is_Empty(emp);
            if (e)
            {
                printf("The list is empty..");
            }
            else
            {
                printf("The list is non empty..");
            }
            break;
        case 5:
            while (1)
            {
                printf("Enter the number 1 or 2 for knowing about list 1 or list 2 : ");
                scanf("%d", &full);
                if (full == 1)
                {
                    break;
                }
                else if (full == 2)
                {
                    break;
                }
                else
                {
                    printf("Please enter 1 or 2 only..");
                }
            }
            f = isFull(full);
            if (e)
            {
                printf("The list is full..");
            }
            else
            {
                printf("The list is not full..");
            }
            break;
        case 6:
            while (1)
            {
                printf("Enter the number 1 or 2 for updating status of aeroplane in list 1 or list 2 : ");
                scanf("%d", &data);
                if (data == 1)
                {
                    break;
                }
                else if (data == 2)
                {
                    break;
                }
                else
                {
                    printf("Please enter 1 or 2 only..");
                }
            }
            if (data == 1)
                Display(1);
            else if (data == 2)
                Display(2);
            updateFlightStatus(data);
            break;
        case 7:
            while (1)
            {
                printf("Enter the number 1 or 2 for getting longest stay in list 1 or list 2 : ");
                scanf("%d", &ls);
                if (ls == 1)
                {
                    break;
                }
                else if (ls == 2)
                {
                    break;
                }
                else
                {
                    printf("Please enter 1 or 2 only..");
                }
            }
            if (ls == 1)
                Display(1);
            else if (ls == 2)
                Display(2);
            getLongestStay(ls);
            break;
        case 8:
            while (1)
            {
                printf("Enter the number 1 or 2 for making unique of list 1 or list 2 : ");
                scanf("%d", &lu);
                if (lu == 1)
                {
                    break;
                }
                else if (lu == 2)
                {
                    break;
                }
                else
                {
                    printf("Please enter 1 or 2 only..");
                }
            }
            if (lu == 1)
                Display(1);
            else if (lu == 2)
                Display(2);
            listUnique(lu);
            break;
        case 9:
            printf("LIST 1\n");
            Display(1);
            printf("\nLIST 2\n");
            Display(2);
            listUnion();
            break;
        case 10:
            printf("LIST 1\n");
            Display(1);
            printf("\nLIST 2\n");
            Display(2);
            listIntersection();
            break;
        case 11:
            while (1)
            {
                printf("Enter the number 1 or 2 for (list 1-list 2) or (list2-list1) : ");
                scanf("%d", &ld);
                if (ld == 1)
                {
                    break;
                }
                else if (ld == 2)
                {
                    break;
                }
                else
                {
                    printf("Please enter 1 or 2 only..");
                }
            }
            printf("LIST 1\n");
            Display(1);
            printf("\nLIST 2\n");
            Display(2);
            listDifference(ld);
            break;
        case 12:
            printf("LIST 1\n");
            Display(1);
            printf("\nLIST 2\n");
            Display(2);
            listSymmetricDifference();
            break;
        case 13:
            printf("Exiting...");
            break;
        default:
            printf("\n\n\t SORRY INVALID CHOICE!");
            printf("\n\n\t PLEASE CHOOSE FROM 1-13");
            printf("\n\n\t Do not forget to chose from 1-13");
        }
        getch();
        system("cls");
    } while (opt != 13);
}
