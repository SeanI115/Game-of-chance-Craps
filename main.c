#include "Header.h"

int main(void)
{
	char again = 'y';
	double balance = 0, wage = 0, balance_check = 0, option = 0;
	unsigned int die1 = 0, die2 = 0, sum = 0, point = 0, win_count = 0, loss_count = 0, check = 0, roll_count = 1;
	
		do
		{
			printf("1. Print rules.\n");
			printf("2. Play game.\n");
			printf("3. Exit.\n");
			printf("Please choose which action you would like to perform: ");
			scanf("%lf", &option);
		} while (option < 1 || option > 3);
		if (option == 1)
		{
			print_game_rules();
		}

		else if (option == 2)
		{
				srand((unsigned int)time(NULL));
				balance = get_bank_balance();
					printf("Balance: $%.2lf\n", balance);
					do
					{
						wage = get_wager_amount();
						printf("Wager: $%.2lf\n", wage);
						balance_check = check_wager_amount(balance, wage);
						while (balance_check == 0)
						{
							printf("Your wage amount exceeds your current balance please enter a smaller amount.\n");
							wage = get_wager_amount();
							balance_check = check_wager_amount(balance, wage);
						}
						die1 = roll_die();
						die2 = roll_die();
						sum = calculate_sum_dice(die1, die2);
						printf("Roll 1: %d %d\n", die1, die2);
						printf("Sum: %d\n", sum);
						if (is_win_loss_or_point(sum) == -1)
						{
							point = sum;
							do
							{
								die1 = roll_die();
								die2 = roll_die();
								printf("dice: %u %u\n", die1, die2);
								sum = die1 + die2;
								roll_count += 1;
							} while (sum != 7 && sum != point);
							if (sum == 7 && sum != point)
							{
								check = is_point_loss_or_neither(sum, point);
								if (check == 0)
								{
									balance -= wage;
								}
								loss_count++;
								chatter_messages(check, roll_count, balance);
								printf("You lose!\n");
								printf("Number of roles it took: %d\n", roll_count);
								printf("Balance: %.2lf\n", balance);
								printf("Play again? (y/n): ");
								scanf("%ch", &again);
							}
							else if (sum == point)
							{
								check = is_point_loss_or_neither(sum, point);
								if (check == 1)
								{
									balance += wage;
								}
								win_count++;
								chatter_messages(check, roll_count, balance);
								printf("You win!\n");
								printf("Number of roles it took: %d\n", roll_count);
								printf("Balance: %.2lf\n", balance);
								printf("Play again? (y/n): ");
								scanf("%ch", &again);
							}
						}
						else if (is_win_loss_or_point(sum) == 0)
						{
							balance -= wage;
							loss_count++;
							printf("You lose!\n");
							printf("Number of roles it took: %d\n", roll_count);
							printf("Current balance: %.2lf\n", balance);
							printf("Play again? (y/n): ");
							scanf("%ch", &again);
						}
						else if (is_win_loss_or_point(sum) == 1)
						{
							balance += wage;
							win_count++;
							printf("You win!\n");
							printf("Number of roles it took: %d\n", roll_count);
							printf("Current balance: %.2lf\n", balance);
							printf("Play again? (y/n): ");
							scanf("%ch", &again);
						}
					} while (again != 'n');
					printf("Win count: %d\n", win_count);
					printf("loss count: %d\n", loss_count);
		}

	

return 0;
	
}

