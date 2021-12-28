#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void loginPage(char *username, char *password) {
    printf("Enter username:");
    scanf("%s", username);
    printf( "Enter password:");
    scanf("%s", password);

}

void saveLogin(char *username, char *password) {
    FILE *fp = fopen("C:\\Users\\Brecken Enneking\\CLionProjects\\LoginSystem\\logins.txt", "a");
    if (fp == NULL) {
        printf("%s", "cannot open file");
        exit(1);
    }

    fputs( username, fp);
    fputs("\n", fp);
    fputs(password, fp);
    fputs("\n", fp);
    fclose(fp);
}

void checkLogin(char *username, char *password) {
    FILE *fp = fopen("INSERT FILE PATH HERE", "r");
    if (fp == NULL) {
        printf("%s", "cannot open file");
        exit(1);
    }
    int nextLine;
    int cntr = 0;
    char line[40];
    while (fscanf(fp, "%s\n", line) != EOF) {
        cntr++;
        if (strcmp(line, username) == 0) {

            if (cntr % 2 != 0) {
                nextLine = 1;
                continue;
            }
        }
        if (strcmp(line, password) == 0) {
            if (nextLine == 1) {
                printf("%s", "Login successful");
                exit(1);
            }
        }
        nextLine = 0;

    }
    fclose(fp);
    char response;
    printf(  "Could not find login. Would you like to create an account? (Y/N): \n");
    scanf("\n%c", &response);
    if (response == 'Y' || response == 'y') {
        saveLogin(username, password);
        printf("%s", "Account created");
    }
    else {
        printf("%s", "Try again\n");
        loginPage(username, password);
        checkLogin(username, password);
    }


}

int main(void) {
    char username[40];
    char password[40];
    loginPage(username, password);
    checkLogin(username, password);
    //saveLogin(username, password);
    return 0;
}
