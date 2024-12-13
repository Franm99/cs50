#include <stdio.h>

#define INPUT_SIZE 30

int get_string_length(char* user_input);
int check_card_type(char* user_input);
const char* check_lunh_algorithm(char* user_input);

int main(void)
{
    char user_input[INPUT_SIZE];
    const char* response;
    printf("Your number: ");
    scanf("%s", &user_input);
    int is_valid_type = check_card_type(user_input);
    if (is_valid_type == 0)
    {
        response = check_lunh_algorithm(user_input);
        printf("%s\n", response);
    }
    else 
    {
        printf("INVALID - Wrong length");
    }
    // response = check_if_valid(user_input);
    return 0;
}

int get_string_length(char* str) {
    int length = 0;

    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

int check_card_type(char* user_input) {
    int expected_size1, expected_size2;
    int actual_size;
    if ((user_input[0] == '3') && ((user_input[1] == '4') || (user_input[1] == '7')))
    {
        // American Express: 15 digits.
        printf("American Express\n");
        expected_size1 = 15;
        expected_size2 = 15;
    } else if (user_input[0] == '4') 
    {
        // Visa: 13 or 16 digits
        printf("Visa\n");
        expected_size1 = 13;
        expected_size2 = 16;
    } else if ((user_input[0] == '5') && ((user_input[1] == '1') || (user_input[1] == '2') || (user_input[1] == '3') || (user_input[1] == '4') || (user_input[1] == '5'))) 
    {
        // Mastercard: 16 digits
        printf("Mastercard\n");
        expected_size1 = 16;
        expected_size2 = 16;
    } else {
        return -1;  // Invalid start.
    }

    // Now, check length
    actual_size = get_string_length(user_input);
    if ((actual_size == expected_size1) || (actual_size == expected_size2))
    {
        return 0;
    } else
    {
        return -1;
    }
}

const char* check_lunh_algorithm(char* user_input)
{
    // printf("LOG[INFO]: Starting to compute algorithm.\n");
    int i = 0;
    int sum = 0;
    int current_val;
    do 
    {
        current_val = (int)user_input[i] - (int)'0';
        if ((i % 2 == 1)) // even numbers: do not multiply by 2, just add up.
        {
            sum += current_val;            
        } else   // Odd numbers must be multiplied by 2, and their resulting digits must be added up.
        {
            current_val = current_val * 2;
            sum += (current_val / 10) + (current_val % 10);
        }
        i++;
    } while (user_input[i] != '\0');

    // Compute the modulo 10 of the result to now if the card is legit.
    if (sum % 10 == 0)
    {
        return "VALID";
    }
    else 
    {
        return "INVALID - Wrong pattern";
    }
}





