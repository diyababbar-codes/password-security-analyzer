#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[100];
    int upper = 0, lower = 0;
    int digit = 0, special = 0;
    int score = 0;

    printf("================================\n");
    printf("    PASSWORD SECURITY ANALYZER\n");
    printf("================================\n");

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);

    password[strcspn(password, "\n")] = '\0';

    int length = strlen(password);

    for (int i = 0; i < length; i++)
    {
        if (isupper((unsigned char)password[i]))
            upper = 1;

        else if (islower((unsigned char)password[i]))
            lower = 1;

        else if (isdigit((unsigned char)password[i]))
            digit = 1;

        else
            special = 1;
    }

    if (length >= 8) score++;
    if (upper) score++;
    if (lower) score++;
    if (digit) score++;
    if (special) score++;

    printf("\n========== ANALYSIS ==========\n");

    printf("Length: %d\n", length);
    printf("Uppercase: %s\n", upper ? "YES" : "NO");
    printf("Lowercase: %s\n", lower ? "YES" : "NO");
    printf("Numbers: %s\n", digit ? "YES" : "NO");
    printf("Special Characters: %s\n", special ? "YES" : "NO");

    printf("\nSecurity Score: %d/5\n", score);

    if (score <= 2)
        printf("Strength: WEAK\n");

    else if (score <= 4)
        printf("Strength: MODERATE\n");

    else
        printf("Strength: STRONG\n");

    return 0;
}
