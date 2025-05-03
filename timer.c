#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#ifdef _WIN32
#include <windows.h>
#define sleep(x) Sleep(x * 1000)
#define clrscr() system("cls")
#else
#include <unistd.h>
#define clrscr() system("clear")
#endif

int main()
{
    char again;

    do
    {
        int tar_hour, tar_minute, tar_second, confirm;

        while (1)
        {
            do
            {
                printf("Enter hour (0 - 23): ");
                scanf("%d", &tar_hour);

                if (tar_hour < 0 || tar_hour > 23)
                {
                    printf("Invalid input. Hour range is 0 - 23.\n");
                }
            } while (tar_hour < 0 || tar_hour > 23);

            do
            {
                printf("Enter minute (0 - 59): ");
                scanf("%d", &tar_minute);

                if (tar_minute < 0 || tar_minute > 59)
                {
                    printf("Invalid input. Minute range is 0 - 59.\n");
                }
            } while (tar_minute < 0 || tar_minute > 59);

            do
            {
                printf("Enter second (0 - 59): ");
                scanf("%d", &tar_second);

                if (tar_second < 0 || tar_second > 59)
                {
                    printf("Invalid input. Second range is 0 - 59.\n");
                }
            } while (tar_second < 0 || tar_second > 59);

            printf("\n1. Start countdown\n2. Discard\nDo you want to start timer for %dh %dm %ds? (1 or 2): ", tar_hour, tar_minute, tar_second);
            do
            {
                scanf("%d", &confirm);

                if (confirm == 1)
                {
                    break;
                }
                else if (confirm == 2)
                {
                    printf("\n******* Discarded *******\n\n");
                    break;
                }
                else
                {
                    printf("Invalid input. Choose 1 or 2: ");
                }
            } while (confirm != 1 && confirm != 2);

            if (confirm == 1)
            {
                break;
            }
                }

        clrscr();

        int cur_hour = tar_hour, cur_minute = tar_minute, cur_second = tar_second;

        while (1)
        {
            printf("\n\n######### TIMER #########\n\n\n");
            printf("        %02d:%02d:%02d\n", cur_hour, cur_minute, cur_second);
            printf("\n\n#########################\n\n\n");

            if (cur_hour == 0 && cur_minute == 0 && cur_second == 0)
            {
                break;
            }

            sleep(1);
            clrscr();

            cur_second--;

            if (cur_second == -1)
            {
                cur_second = 59;
                cur_minute--;
            }
            if (cur_minute == -1)
            {
                cur_minute = 59;
                cur_hour--;
            }
        }

        printf("\a***** Time is over! *****\a\n\n\n");

        do
        {
            printf("Do you want to start another countdown timer again? (y/n): ");
            scanf(" %c", &again);
            printf("\n");

            again = tolower(again);

            if (again != 'y' && again != 'n')
            {
                printf("\nInvalid input. Enter 'y' for 'Yes' and 'n' for 'No'.\n");
            }
        } while (again != 'y' && again != 'n');

    } while (again == 'y');

    printf("Exiting...\n");

    return 0;
}