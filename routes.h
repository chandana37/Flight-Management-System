#include<stdio.h>

void routes(){
    int flag;
    char Local_destination[][20] = {"Mumbai","delhi","hyderabad","chennai","bengaluru"};
    char Internation_destination[][20]={"london","paris","san-fransico","tokyo","berlin"};

    printf("******** Following are the local flights available ********\n\n");
    for(int i=0;i<5;i++){
        printf("\n\n\n");
        for(int k=1;k<5;k++){
            printf("Flight from %s to %s \n",Local_destination[i],Local_destination[k]);
        }
    }

    printf("******** Following are the international flights available ********\n\n");
    for(int o=0;o<5;o++){
      printf("\n\n\n");
      for(int p=1;p<5;p++){
        printf("Flight from %s to %s \n",Local_destination[o],Internation_destination[p]);
        }
    }

   printf("\n\n\n");
   getch();
   system("cls");

}



