#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Define the structure for each day of the week
struct Day
{
  char *name;
  int date;
  char *activity;
};
// Define an array to store 7 days of the week
struct Day week[7];
// Function to create the calendar
void create()
{
  for (int i = 0; i < 7; i++)
  {
    week[i].name = (char *)malloc(20 * sizeof(char));
    week[i].activity = (char *)malloc(100 * sizeof(char));
    printf("Enter the name of day %d: ", i + 1);
    scanf("%s", week[i].name);
    printf("Enter the date of day %d: ", i + 1);
    scanf("%d", &week[i].date);
    printf("Enter the activity for day %d: ", i + 1);
    getchar(); // Consume the newline character
    fgets(week[i].activity, 100, stdin);
  }
}

// Function to read data from the keyboard
void read()
{
  create(); // Reusing the create function for reading data
}
// Function to display the calendar
void display()
{
  printf("\nDay\tDate\tActivity\n");
  for (int i = 0; i < 7; i++)
  {
    printf("%s\t%d\t%s", week[i].name, week[i].date, week[i].activity);
  }
}
int main()
{
  printf("Creating a calendar:\n");
  create();
  printf("\nDisplaying the calendar:\n");
  display();
  return 0;
}
