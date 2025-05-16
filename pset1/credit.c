#include <cs50.h> // cs50 Library im using
#include <stdio.h>


bool check_sum(long num);
int count;
bool check_type(long num);

int main(void)
{
    //Input for taking in number
    long number = get_long("Number: ");
    long num = number;
    // used for counting the length of a number
    while (number != 0)
    {
        number = number / 10;
        count++;
    }
    //Applying the Luhn's formula here
    if (check_sum(num) == false)
    {
        printf("INVALID\n");
    }
    else
    {
        // Checking the type of the card after it has passed check_sum function
        check_type(num);
    }



}

// This function is used to check the sum value of a card number
bool check_sum(long num)
{
    // These are all the variables used in the check_sum function
    int total = 0;
    int even_sum = 0;
    int odd_sum = 0;
    long long even_ten1 = 100;
    long long even_ten2 = 10;
    long long odd_ten1 = 10;
    long long odd_ten2 = 1;

    // This finds the sum of even places in the number
    for (int j = 0 ; j < 1 + (count / 2) ; j++)
    {
        int sum = 2 * ((num % even_ten1) / even_ten2);
        // This is used when the digit exceeds the value of 10 and we want to add only the unit places together
        if (sum > 9)
        {
            even_sum += (sum / 10);
            even_sum += (sum % 10);
        }
        // Normal case when sum is less than 10
        else
        {
            even_sum += sum;
        }
        even_ten1 *= 100;
        even_ten2 *= 100;

    }
    for (int k = 0 ; k < 1 + (count / 2) ; k++)
    {
        odd_sum += ((num % odd_ten1) / odd_ten2);
        odd_ten1 *= 100;
        odd_ten2 *= 100;
    }
    // assigning the total value of the sum
    total = even_sum + odd_sum;

    //Final checking of the check_sum fucntion if it is a multiple of 10
    if ((total % 10) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


//American Express - 15 digits           starts with 34 and 37
//MasterCard       - 16 digits           starts with 51,52,53,54 and 55
//Visa             - 13 and 16 digits    starts with 4
bool check_type(long num)
{
    // using count number here to check if it checks out the nard requirements
    if (count == 15)
    {
        // if the first 2 digits of the card are 34 or 36
        if (((num % 1000000000000000) / 10000000000000) == 34 || ((num % 1000000000000000) / 10000000000000) == 37)
        {
            printf("AMEX\n");
            return true;
        }
        else
        {
            printf("INVALID\n");
            return false;
        }

    }
    else if (count == 13)
    {
        // If the first digit of the card is 4
        if (((num % 10000000000000) / 1000000000000) == 4)
        {
            printf("VISA\n");
            return true;
        }
        else
        {
            printf("INVALID\n");
            return false;
        }

    }
    else if (count == 16)
    {
        //if the first two digits of the card is 51 or 52 or 53 or 54 or 55
        if (((num % 10000000000000000) / 100000000000000) == 51 || ((num % 10000000000000000) / 100000000000000) == 52
            || ((num % 10000000000000000) / 100000000000000) == 53 || ((num % 10000000000000000) / 100000000000000) == 54
            || ((num % 10000000000000000) / 100000000000000) == 55)
        {
            printf("MASTERCARD\n");
            return true;
        }
        // if the first digit of the card is 4
        else if (((num % 10000000000000000) / 1000000000000000) == 4)
        {
            printf("VISA\n");
            return true;
        }
        else
        {
            printf("INVALID\n");
            return false;
        }
    }
    // If all value do not checks out
    else
    {
        printf("INVALID\n");
        return false;
    }
}




