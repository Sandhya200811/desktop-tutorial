#include <stdio.h>
#include <string.h>
#include <conio.h>

struct Student
{
    int rollno;
    char name[50];
    char course[30];
    float totalfee;
    float paidfee;
    float pendingfee;
};

int main()
{
    struct Student s[100];

    int choice, n = 0, i, search, found;
    int attempts = 3, login = 0;
    float amount;

    char username[30], password[30];
    char ch;

    printf("\n====================================\n");
    printf("   STUDENT FEE MANAGEMENT SYSTEM\n");
    printf("              LOGIN PAGE\n");
    printf("====================================\n");

    while (attempts > 0)
    {
        printf("\nEnter Username: ");
        scanf("%29s", username);

        printf("Enter Password: ");

        i = 0;

        while (1)
        {
            ch = getch();

            if (ch == '\r')
            {
                break;
            }
            else if (ch == '\b')
            {
                if (i > 0)
                {
                    i--;
                    printf("\b \b");
                }
            }
            else if (ch >= 32 && ch <= 126 && i < 29)
            {
                password[i] = ch;
                i++;
                printf("*");
            }
        }

        password[i] = '\0';
        printf("\n");

        if (strcmp(username, "admin") == 0 &&
            strcmp(password, "1234") == 0)
        {
            login = 1;

            printf("\nLogin Successful!\n");
            printf("Welcome to Student Fee Management System.\n");

            break;
        }
        else
        {
            attempts--;

            printf("\nInvalid Username or Password!\n");

            if (attempts > 0)
            {
                printf("Attempts remaining: %d\n", attempts);
                printf("Please try again.\n");
            }
            else
            {
                printf("Maximum attempts reached!\n");
                printf("Login Failed. Exiting System.\n");

                return 0;
            }
        }
    }

    do
    {
        printf("\n====================================\n");
        printf("   STUDENT FEE MANAGEMENT SYSTEM\n");
        printf("====================================\n");
        printf("1. Add Student Details\n");
        printf("2. Display All Students\n");
        printf("3. Pay Student Fee\n");
        printf("4. Search Student\n");
        printf("5. Logout\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (n >= 100)
                {
                    printf("Student limit reached!\n");
                    break;
                }

                printf("Enter Roll Number: ");
                scanf("%d", &s[n].rollno);

                printf("Enter Student Name: ");
                scanf(" %49[^\n]", s[n].name);

                printf("Enter Course: ");
                scanf(" %29[^\n]", s[n].course);

                printf("Enter Total Fee: ");
                scanf("%f", &s[n].totalfee);

                if (s[n].totalfee < 0)
                {
                    printf("Fee cannot be negative!\n");
                    break;
                }

                s[n].paidfee = 0;
                s[n].pendingfee = s[n].totalfee;

                n++;

                printf("Student details added successfully!\n");
                break;

            case 2:
                if (n == 0)
                {
                    printf("No student records available.\n");
                }
                else
                {
                    printf("\n===== STUDENT FEE DETAILS =====\n");

                    for (i = 0; i < n; i++)
                    {
                        printf("\nRoll Number : %d\n", s[i].rollno);
                        printf("Name        : %s\n", s[i].name);
                        printf("Course      : %s\n", s[i].course);
                        printf("Total Fee   : %.2f\n", s[i].totalfee);
                        printf("Paid Fee    : %.2f\n", s[i].paidfee);
                        printf("Pending Fee : %.2f\n", s[i].pendingfee);
                    }
                }
                break;

            case 3:
                if (n == 0)
                {
                    printf("No student records available.\n");
                    break;
                }

                printf("Enter Roll Number: ");
                scanf("%d", &search);

                found = 0;

                for (i = 0; i < n; i++)
                {
                    if (s[i].rollno == search)
                    {
                        found = 1;

                        printf("Student Name: %s\n", s[i].name);
                        printf("Pending Fee: %.2f\n", s[i].pendingfee);

                        if (s[i].pendingfee <= 0)
                        {
                            printf("All fees are already paid.\n");
                        }
                        else
                        {
                            printf("Enter Amount to Pay: ");
                            scanf("%f", &amount);

                            if (amount <= 0)
                            {
                                printf("Enter a valid positive amount.\n");
                            }
                            else if (amount > s[i].pendingfee)
                            {
                                printf("Amount exceeds pending fee!\n");
                            }
                            else
                            {
                                s[i].paidfee += amount;

                                s[i].pendingfee =s[i].totalfee - s[i].paidfee;

                                printf("Fee payment successful!\n");
                                printf("Total Paid: %.2f\n", s[i].paidfee);
                                printf("Remaining Fee: %.2f\n",s[i].pendingfee);
                            }
                        }

                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Student not found!\n");
                }
                break;

            case 4:
                if (n == 0)
                {
                    printf("No student records available.\n");
                    break;
                }

                printf("Enter Roll Number to Search: ");
                scanf("%d", &search);

                found = 0;

                for (i = 0; i < n; i++)
                {
                    if (s[i].rollno == search)
                    {
                        found = 1;

                        printf("\n===== STUDENT DETAILS =====\n");
                        printf("Roll Number : %d\n", s[i].rollno);
                        printf("Name        : %s\n", s[i].name);
                        printf("Course      : %s\n", s[i].course);
                        printf("Total Fee   : %.2f\n", s[i].totalfee);
                        printf("Paid Fee    : %.2f\n", s[i].paidfee);
                        printf("Pending Fee : %.2f\n", s[i].pendingfee);

                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Student not found!\n");
                }
                break;

            case 5:
                printf("\n====================================\n");
                printf("              LOGOUT PAGE\n");
                printf("====================================\n");
                printf("You have logged out successfully.\n");
                printf("Thank you for using our system.\n");
                printf("Goodbye!\n");
                printf("====================================\n");

                login = 0;
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (login == 1);

    return 0;
}
