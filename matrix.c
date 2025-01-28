#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Constants
#define MAX_ROWS 10
#define MAX_COLS 101
#define MAX_NAME_LENGTH 50

// Function Prototypes
int is_vowel(char ch);
void input_matrix(char names[MAX_ROWS][MAX_COLS][MAX_NAME_LENGTH], int rows, int cols);
void print_matrix(char names[MAX_ROWS][MAX_COLS][MAX_NAME_LENGTH], int rows, int cols);
int count_vowel_names(char names[MAX_ROWS][MAX_COLS][MAX_NAME_LENGTH], int rows, int cols);
void find_longest_name(char names[MAX_ROWS][MAX_COLS][MAX_NAME_LENGTH], int rows, int cols, char longest_name[]);

// Function to check if a character is a vowel
int is_vowel(char ch)
{
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

// Function to input names into the matrix
void input_matrix(char names[MAX_ROWS][MAX_COLS][MAX_NAME_LENGTH], int rows, int cols)
{
    printf("Enter the names:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Name at (%d,%d): ", i, j);
            scanf("%s", names[i][j]);
        }
    }
}

// Function to print the matrix of names
void print_matrix(char names[MAX_ROWS][MAX_COLS][MAX_NAME_LENGTH], int rows, int cols)
{
    printf("\nThe 2D array of names is:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%s ", names[i][j]);
        }
        printf("\n");
    }
}

// Function to count names starting with a vowel
int count_vowel_names(char names[MAX_ROWS][MAX_COLS][MAX_NAME_LENGTH], int rows, int cols)
{
    int count = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (is_vowel(names[i][j][0]))
            {
                count++;
            }
        }
    }
    return count;
}

// Function to find the longest name in the matrix
void find_longest_name(char names[MAX_ROWS][MAX_COLS][MAX_NAME_LENGTH], int rows, int cols, char longest_name[])
{
    strcpy(longest_name, ""); // Initialize longest_name as an empty string
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (strlen(names[i][j]) > strlen(longest_name))
            {
                strcpy(longest_name, names[i][j]);
            }
        }
    }
}

// Main Function
int main()
{
    int rows, cols;
    char names[MAX_ROWS][MAX_COLS][MAX_NAME_LENGTH];
    char longest_name[MAX_NAME_LENGTH];

    // Input: Number of rows and columns
    printf("Enter number of rows (1-10): ");
    scanf("%d", &rows);
    while (rows < 1 || rows > 10)
    {
        printf("Invalid input. Enter number of rows (1-10): ");
        scanf("%d", &rows);
    }

    printf("Enter number of columns (1-101): ");
    scanf("%d", &cols);
    while (cols < 1 || cols > 101)
    {
        printf("Invalid input. Enter number of columns (1-101): ");
        scanf("%d", &cols);
    }

    // Input: Names in the matrix
    input_matrix(names, rows, cols);

    // Output: Matrix of names
    print_matrix(names, rows, cols);

    // Output: Count of names starting with vowels
    int vowel_count = count_vowel_names(names, rows, cols);
    printf("\nNumber of names starting with a vowel: %d\n", vowel_count);

    // Output: Longest name
    find_longest_name(names, rows, cols, longest_name);
    printf("The longest name: %s\n", longest_name);

    return 0;
}
