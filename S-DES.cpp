#include <iostream>
using namespace std;

int txt[8];
int ten_bit_key[10];
int ip[8] = {2, 6, 3, 1, 4, 8, 5, 7};
int ip_1[8] = {4, 1, 3, 5, 7, 2, 8, 6};
int p_10[10] = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6};
int p_8[8] = {6, 3, 7, 4, 8, 5, 10, 9};
int e_p[8] = {4, 1, 2, 3, 2, 3, 4, 1};
int p_4[4] = {2, 4, 3, 1};

int s0_arr[4][4] = {
    1, 0, 3, 2,
    3, 2, 1, 0,
    0, 2, 1, 3,
    3, 1, 3, 2};
int s1_arr[4][4] = {
    0, 1, 2, 3,
    2, 0, 1, 3,
    3, 0, 1, 0,
    2, 1, 0, 3

};

///////////////////////////////////////

int p10_output[10];
int p10_first_half[5];
int p10_second_half[5];
int p10_after_1_shift[10];
int p10_after_2_shift[10];
int k1[8];
int k2[8];
int ip_output[8];
int E_P_output[8];
int x_or[8];
int x_or_2[4];
int s0;
int s1;
int s0s1[4];
int s0s1_1[2];
int s0s1_2[2];
int p4_output[4];
int left_part[4];
int right_part[4];
int first_result[8];
int swap_first_result[8];
int final_result[8];
///////////////////////////////////////

void p_10_key() // applying p10 to the key
{
    int a;
    for (int i = 0; i < 10; i++)
    {
        a = p_10[i];
        p10_output[i] = ten_bit_key[a - 1];
    }
}
void first_shift(int arr[10]) // first shift
{
    int temp1[5];
    int temp2[5];
    int j = 0;
    for (int i = 0; i < 10; i++)
    {
        if (i < 5)
        {
            temp1[i] = arr[i];
        }
        else
        {
            temp2[j] = arr[i];
            j++;
        }
    }
    for (int i = 1; i < 5; i++)
    {
        p10_first_half[i - 1] = temp1[i];
    }
    p10_first_half[4] = temp1[0];
    for (int i = 1; i < 5; i++)
    {
        p10_second_half[i - 1] = temp2[i];
    }
    p10_second_half[4] = temp2[0];
    j = 0;
    for (int i = 0; i < 10; i++)
    {
        if (i < 5)
        {
            p10_after_1_shift[i] = p10_first_half[i];
        }
        else
        {

            p10_after_1_shift[i] = p10_second_half[j];
            j++;
        }
    }
}
void second_shift(int arr[10]) // first shift
{
    int temp1[5];
    int temp2[5];
    int j = 0;
    for (int i = 0; i < 10; i++)
    {
        if (i < 5)
        {
            temp1[i] = arr[i];
        }
        else
        {
            temp2[j] = arr[i];
            j++;
        }
    }
    for (int i = 2; i < 5; i++)
    {
        p10_first_half[i - 2] = temp1[i];
    }
    p10_first_half[3] = temp1[0];
    p10_first_half[4] = temp1[1];

    for (int i = 2; i < 5; i++)
    {
        p10_second_half[i - 2] = temp2[i];
    }
    p10_second_half[3] = temp2[0];
    p10_second_half[4] = temp2[1];
    j = 0;
    for (int i = 0; i < 10; i++)
    {
        if (i < 5)
        {
            p10_after_2_shift[i] = p10_first_half[i];
        }
        else
        {

            p10_after_2_shift[i] = p10_second_half[j];
            j++;
        }
    }
}
void k1_generator(int arr[10]) //  generating K1
{
    int a;
    for (int i = 0; i < 8; i++)
    {
        a = p_8[i];
        k1[i] = arr[a - 1];
    }
}
void k2_generator(int arr[10]) //  generating K2
{
    int a;
    for (int i = 0; i < 8; i++)
    {
        a = p_8[i];
        k2[i] = arr[a - 1];
    }
}
void IP(int txt[8])
{
    int a;
    for (int i = 0; i < 8; i++)
    {
        a = ip[i];
        ip_output[i] = txt[a - 1];
    }
}
void apply_E_P(int arr[8]) // applying e/p
{
    int temp1[4];
    int temp2[4];
    int j = 0;
    for (int i = 0; i < 8; i++)
    {
        if (i < 4)
        {
            temp1[i] = arr[i];
            left_part[i] = arr[i];
        }
        else
        {
            temp2[j] = arr[i];
            right_part[i] = arr[i];
            j++;
        }
    }
    int a;
    for (int i = 0; i < 8; i++)
    {
        a = e_p[i];

        E_P_output[i] = temp2[a - 1];
    }
}

void XOR(int k1[8], int E_P_output[8]) // x or k1 with the output of e/p
{
    for (int i = 0; i < 8; i++)
    {
        if (k1[i] == E_P_output[i])
        {
            x_or[i] = 0;
        }
        else
        {
            x_or[i] = 1;
        }
    }
}
void XOR_2(int k1[4], int p4_output[4]) // xor the result of p4 with left part of IP
{
    for (int i = 0; i < 4; i++)
    {
        if (k1[i] == p4_output[i])
        {
            x_or_2[i] = 0;
        }
        else
        {
            x_or_2[i] = 1;
        }
    }
}
void S0(int x_or[8])
{
    int row = x_or[3] + (x_or[0] * 2);    // first and last gives us the row
    int column = x_or[2] + (x_or[1] * 2); // the second and third gives us the column
    s0 = s0_arr[row][column];
}

void S1(int x_or[8])
{
    int row = x_or[7] + (x_or[4] * 2);
    int column = x_or[6] + (x_or[5] * 2);
    s1 = s1_arr[row][column];
}
void S0S1(int s0_0, int s1_1) // merging s0 and s1 toghether
{

    int i = 0;
    while (s0_0 != 0)
    {
        if (s0_0 & 1) // checking the first bit to the right in the binary of s0
        {
            s0s1_1[i] = 1;// if the first bit is 1 we add a to our first value of s0
        }
        else if (s0_0 & 0) // if its 0 we add 0 to s0
        {
            s0s1_1[i] = 0;
        }

        i++;
        s0_0 = s0_0 >> 1; // shifting the bits to the right eg: 11 will be 01
    }
    i = 0;
    while (s1_1 != 0)
    {
        if (s1_1 & 1) // checking the first bit to the right in the binary of s1
        {
            s0s1_2[i] = 1; // if the first bit is 1 we add a to our first value of s1
        }
        else if (s1_1 & 0) // if its 0 we add 0 to s1
        {
            s0s1_2[i] = 0;
        }

        i++;
        s1_1 = s1_1 >> 1; // shifting the bits to the right eg: 11 will be 01
    }
    s0s1[0] = s0s1_1[1];
    s0s1_1[1] = 0; // restore the value to 0 so it wont affect the second round
    s0s1[1] = s0s1_1[0];
    s0s1_1[0] = 0;
    s0s1[2] = s0s1_2[1];
    s0s1_2[1] = 0;
    s0s1[3] = s0s1_2[0];
    s0s1_2[0] = 0;
}

void P4(int txt[4]) //applying p4
{
    int a;
    for (int i = 0; i < 4; i++)
    {
        a = p_4[i];
        p4_output[i] = txt[a - 1];
    }
}
void first_res(int p4_output[4], int right_part[4]) //this is to find the first round result
{
    for (int i = 0; i < 8; i++)
    {
        if (i < 4)
        {
            first_result[i] = p4_output[i];
        }
        else
        {
            first_result[i] = right_part[i];
        }
    }
}
void first_res_swap(int first_result[8]) //swapping before second round
{
    int j = 0;
    int temp1[4];
    int temp2[4];
    for (int i = 0; i < 8; i++)
    {
        if (i < 4)
        {
            temp1[i] = first_result[i];
        }
        else
        {
            temp2[j] = first_result[i];

            j++;
        }
    }
    j = 0;
    for (int i = 0; i < 8; i++)
    {
        if (i < 4)
        {
            swap_first_result[i] = temp2[i];
        }
        else
        {
            swap_first_result[i] = temp1[j];
            j++;
        }
    }
}

void apply_p_(int arr[8]) //last step apply p-1
{

    int a;
    for (int i = 0; i < 8; i++)
    {
        a = ip_1[i];

        final_result[i] = arr[a - 1];
    }
}

void txtInput() //inputing plain text
{
    cout << "Enter your text (one by one)" << endl;
    for (int i = 0; i < 8; i++)
    {
        cin >> txt[i];
        if (txt[i] > 1 || txt[i] < 0)
        {
            cout << "Please make sure the value is in binary format!" << endl;
            i--;
        }
    }
}

void keyinput() //inputing the key
{
    cout << "Enter your 10 bit key (one by one)" << endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> ten_bit_key[i];
        if (ten_bit_key[i] > 1 || ten_bit_key[i] < 0)
        {
            cout << "Please make sure the value is in binary format!" << endl;
            i--;
        }
    }
}
int main()
{
    int choice;

    do
    {
        cout << "Please choose one: " << endl;  //menu
        cout << "1. Encryption: " << endl;
        cout << "2. Decryption: " << endl;
        cout << "3. Exit: " << endl;
        cin >> choice;
        txtInput();
        keyinput();

        ///////////////Round 1 /////////////

        p_10_key();
        first_shift(p10_output);
        k1_generator(p10_after_1_shift);
        second_shift(p10_after_1_shift);
        k2_generator(p10_after_2_shift);
        IP(txt);
        apply_E_P(ip_output);
        if (choice == 1)
        {
            XOR(E_P_output, k1);
        }
        else
        {
            XOR(E_P_output, k2);
        }

        S0(x_or);
        S1(x_or);
        S0S1(s0, s1);
        P4(s0s1);
        XOR_2(left_part, p4_output);
        first_res(x_or_2, right_part);
        first_res_swap(first_result);

        ///////////////Round 2 /////////////

        apply_E_P(swap_first_result);
        if (choice == 1)
        {
            XOR(E_P_output, k2);
        }
        else
        {
            XOR(E_P_output, k1);
        }
        S0(x_or);
        S1(x_or);
        S0S1(s0, s1);
        P4(s0s1);
        XOR_2(left_part, p4_output);
        first_res(x_or_2, right_part);
        apply_p_(first_result);

        cout << endl;
        cout << "K1 = ";
        for (int i = 0; i < 8; i++)
        {
            cout << k1[i];
        }

        cout << endl;
        cout << "K2 = ";
        for (int i = 0; i < 8; i++)
        {
            cout << k2[i];
        }

        cout << endl;
        cout << "Final result " << endl;
        for (int i = 0; i < 8; i++)
        {
            cout << final_result[i];
        }
        cout << "\n\n\n\n\n";
    } while (choice != 3);
}