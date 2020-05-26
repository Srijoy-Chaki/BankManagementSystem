//A mini bank management program.

#include <stdio.h>

struct customer
{
    int account_no;
    char name[80];
    int balance;
};
void accept(struct customer[], int);
void display(struct customer[], int);
int search(struct customer[], int, int);
void deposit(struct customer[], int, int, int);
void withdraw(struct customer[], int, int, int);
int main()
{
    struct customer data[20];
    int n, choice, account_no, amount, index;
    printf("Banking System\n\n");
    printf("Number of customer records you want to enter : ");
    scanf("%d", &n);
    accept(data, n);
    do
    {
        printf("\nBanking System Menu :\n");
        printf("Press 1 to display all records.\n");
        printf("Press 2 to search a record.\n");
        printf("Press 3 to deposit amount.\n");
        printf("Press 4 to withdraw amount.\n");
        printf("Press 0 to exit\n");
        printf("\nEnter choose between 0-4 : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:                                      //enter 1 to view the details of the customer
                display(data, n);
                break;
        case 2:                                      //enter 2 to search a record
                printf("Enter account number to search : ");
                scanf("%d", &account_no);
                index = search(data, n, account_no);
                if (index ==  - 1)
                {
                    printf("Record not found : ");
                }
                else
                {
                    printf("A/c Number: %d\nName: %s\nBalance: %d\n",
                        data[index].account_no, data[index].name,
                        data[index].balance);
                }
                break;
        case 3:                                       //enter 3 to deposit
                printf("Enter account number : ");
                scanf("%d", &account_no);
                printf("Enter amount to deposit : ");
                scanf("%d", &amount);
                deposit(data, n, account_no, amount);
                break;
        case 4:                                       //enter 4 to withdraw
                printf("Enter account number : ");
                scanf("%d", &account_no);
                printf("Enter amount to withdraw : ");
                scanf("%d", &amount);
                withdraw(data, n, account_no, amount);
        }
        
    }
while (choice != 0);                                  //enter 0 to end the program.

    return 0;
}
void accept(struct customer list[50], int s)
{
    int j;
    for (j = 0; j < s; j++)
    {
        printf("\nEnter data for Record #%d", j + 1);

        printf("\nEnter account no : ");
        scanf("%d", &list[j].account_no);
        fflush(stdin);
        printf("Enter name : ");
        gets(list[j].name);
        list[j].balance = 0;
    }
}
void display(struct customer list[50], int s)
{
    int j;

    printf("\n\nA/c No\tName\tBalance\n");
    for (j = 0; j < s; j++)
    {
        printf("%d\t%s\t%d\n", list[j].account_no, list[j].name,
            list[j].balance);
    }
}
int search(struct customer list[50], int s, int num)
{
    int j;

    for (j = 0; j < s; j++)
    {
        if (list[i].account_no == num)
        {
            return j;
        }
    }
    return  - 1;
}
void deposit(struct customer list[50], int s, int num, int amt)
{
    int j = search(list, s, num);
    if (j ==  - 1)
    {
        printf("Record not found");
    }
    else
    {
        list[j].balance +=amt;
    }
}
void withdraw(struct customer list[50], int s, int num, int amt)
{
    int j = search(list, s, num);
    if (j ==  - 1)
    {
        printf("Record not found\n");
    }
    else if (list[j].balance < amt)
    {
        printf("Insufficient balance\n");
    }
    else
    {
        list[j].balance -= amt;
    }
}

