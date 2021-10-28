#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int f = 1;
    char input[100];
    printf("Enter a token to identify, EOF to stop:\n");
    scanf("%s", input);
    if (feof(stdin))
    {
        f = 0;
    }
    while (f)
    {
        if (feof(stdin))
        {
            break;
        }

        int posdigits = 0, negdigits = 0, valid = 0, floatdigits = 0;

        for (int i = 0; i < strlen(input); i++)
        {
            if (input[8] == '-' && input[13] == '-' && input[18] == '-' && input[23] == '-' && (isxdigit(input[i]) || input[i] == '-'))
            {
                if (strlen(input) == 36)
                {
                    if (isxdigit(input[i]) || input[i] == '-')
                    {
                        valid = 1;
                        printf("The token is a guid\n");
                    }
                }
            }

            else if (input[0] == '-' && isdigit(input[i + 1]) && isdigit(input[i + 2]))
            { // for  neg digits
                negdigits++;
                if (negdigits == (strlen(input) - 1))
                {
                    valid = 1;
                    printf("The token is a negative integer\n");
                }
                else
                {
                    valid = 0;
                }
            }

            else if (isdigit(input[i]))
            {
                posdigits++;
                if (posdigits == strlen(input))
                {
                    valid = 1;
                    printf("The token is a positive integer\n");
                }
            }

            else if (input[i] == '.' && isdigit(input[i - 1]) && isdigit(input[i + 1]))
            {
                for (int z = 0; z < strlen(input); z++)
                {
                    if (isdigit(input[z]))
                        floatdigits++;
                }
                if (input[0] != '-' && floatdigits == strlen(input) - 1)
                {
                    valid = 1;
                    printf("The token is a positive floating-point number\n");
                    break;

                } // for pos float
                else if (input[0] == '-' && floatdigits == strlen(input) - 2)
                {
                    valid = 1;
                    printf("The token is a negative floating-point number\n");
                    break;
                }

            } // for neg float

            else if (input[0] == '0' && input[1] == 'b')
            {
                if ((input[i + 2] == '0' || input[i + 2] == '1'))
                    ;
                valid = 1;
                printf("The token is a binary number\n");
            }

            else if (valid == 0)
            {
                printf("The token cannot be identified\n");
            }
        }

        printf("Enter a token to identify, EOF to stop:\n");
        scanf("%s", input);
    }

    return 0;
}
