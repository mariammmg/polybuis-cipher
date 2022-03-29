#include<string.h>
#include <iostream>

using namespace std;
char  array_letters[5][5] = { {'a','b','c','d','e'},{'f','g','h','i','k'}
   ,{'l','m','n','o','p'}, {'q','r','s','t','u'},{'v','w','x','y','z'} };



int decryption(char keys_numbers[5])
{

    char encrypted_text[100];
    char* first_letter_position;
    char* second_letter_position;

    char first_number_index;
    char second_number_index;

    int index_first_letter;
    int index_second_letter;

    cout << "please enter the encrypted text to decrypt";
    cin >> encrypted_text;
    for (int i = 0; encrypted_text[i] != '\0'; i++)
    {
        first_letter_position = strchr(keys_numbers, encrypted_text[i]);
        first_number_index = first_letter_position - keys_numbers + 1;

        second_letter_position = strchr(keys_numbers, encrypted_text[i + 1]);
        second_number_index = second_letter_position - keys_numbers + 1;

        index_first_letter = int(first_number_index);
        index_second_letter = int(second_number_index);
        i++;
        cout << array_letters[index_first_letter - 1][index_second_letter - 1];


    }



    return 0;
}

int encryption(char keys_numbers[5])

{
    char text[100];
    cout << "enter the text you want to encrypt";
    cin >> text;
    for (int i = 0; text[i] != 0; i++)
    {
        for (int k = 0; k < 5; k++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (array_letters[k][j] == text[i])
                {
                    cout << keys_numbers[k] << keys_numbers[j];
                }

            }

        }

    }
    return 0;
}

int menu() {
    int choice;
    bool exit=true;
    
    char keys_numbers[5];
    while (exit)
    {
        cout << " please choose (1) encrypt or (2) decrypt or (3) EXIT" << endl;
        cin >> choice;
        if (choice == 1) {
            cout << "please enter the keys numbers ";
            cin >> keys_numbers;
            encryption(keys_numbers);
        }
        if (choice == 2) {
            cout << "please enter the keys numbers ";
            cin >> keys_numbers;
            decryption(keys_numbers);
        }
        if (choice == 3) {
            cout << "exit";
            exit = true;

        }
    }
    return 0;
}


int main()
{
    menu();
}

