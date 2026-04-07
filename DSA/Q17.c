/*Email validation with enterprise rules using regular expression 
Natural text: extract phone numbers in multiple formats
Invoice number validation with checksum stub - Invoices follow INV-<year><month>-<serial> e.g., INV-202511-000123; year is 4 digits, month 01–12, serial exactly 6 digits*/

#include<stdio.h>
#include<regex.h>
#include<string.h>

void validateEmail() {
    regex_t regex;
    char email[100];

    char *pattern = "^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,6}$";

    printf("\nEnter Email: ");
    scanf("%s", email);

    regcomp(&regex, pattern, REG_EXTENDED);

    if(regexec(&regex, email, 0, NULL, 0) == 0)
        printf("Valid Email\n");
    else
        printf("Invalid Email\n");

    regfree(&regex);
}

void extractPhone() {
    regex_t regex;
    char text[200];

    char *pattern = "[0-9]{10}|[0-9]{3}-[0-9]{3}-[0-9]{4}";

    printf("\nEnter text: ");
    getchar(); 
    fgets(text, sizeof(text), stdin);

    regcomp(&regex, pattern, REG_EXTENDED);

    if(regexec(&regex, text, 0, NULL, 0) == 0)
        printf("Phone number detected in text\n");
    else
        printf("No phone number found\n");

    regfree(&regex);
}

void validateInvoice() {
    regex_t regex;
    char invoice[50];

    char *pattern = "^INV-[0-9]{4}(0[1-9]|1[0-2])-[0-9]{6}$";

    printf("\nEnter Invoice Number: ");
    scanf("%s", invoice);

    regcomp(&regex, pattern, REG_EXTENDED);

    if(regexec(&regex, invoice, 0, NULL, 0) == 0)
        printf("Valid Invoice Number\n");
    else
        printf("Invalid Invoice Number\n");

    regfree(&regex);
}

int main() {

    int choice;

    printf("\n1. Email Validation");
    printf("\n2. Extract Phone Number from Text");
    printf("\n3. Invoice Number Validation");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {

        case 1:
            validateEmail();
            break;

        case 2:
            extractPhone();
            break;

        case 3:
            validateInvoice();
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}
