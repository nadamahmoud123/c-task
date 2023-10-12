#include <stdio.h>
#include <string.h>
#define MAX_USERS 10
#define MAX_USERNAME_LENGTH 15
#define MAX_PASSWORD_LENGTH 15

struct User
{
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct User users[MAX_USERS];
int numUsers = 0;
int registerUser()
{
    if (numUsers >= MAX_USERS)
    {
        printf("Maximum number of users reached.\n");
        return 0;
    }

    struct User newUser;
    printf("Enter a username (up to %d characters): ", MAX_USERNAME_LENGTH - 1);
    scanf("%s", newUser.username);
    printf("Enter a password (up to %d characters): ", MAX_PASSWORD_LENGTH - 1);
    scanf("%s", newUser.password);

    users[numUsers] = newUser;
    numUsers++;

    printf("Registration successful.\n");

    return 1;
}

int loginUser()
{
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    for (int i = 0; i < numUsers; i++)
    {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0)
        {
            printf("Login successful.\n");
            return 1;
        }
    }

    printf("Invalid username or password.\n");
    return 0;
}

int main()
{
    int choice;

    do
    {
        printf("1- Register\n");
        printf("2- Login\n");
        printf("3- Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            registerUser();
            break;
        case 2:
            loginUser();
            break;
        case 3:
            printf("Quitting the program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    } while (choice != 3);

    return 0;
}