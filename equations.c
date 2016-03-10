#include "Header.h"
#include <time.h>

void print_game_rules(void)
{
	printf("A player rolls two dice. Each die has six faces. These faces contain 1, 2, 3, 4, 5, and 6 spots. After the dice have come to rest, the sum of the spots on the two upward faces is calculated. If the sum is 7 or 11 on the first throw, the player wins. If the sum is 2, 3, or 12 on the first throw (called craps), the player loses (i.e. the house wins). If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's point. To win, you must continue rolling the dice until you make your point. The player loses by rolling a 7 before making the point.\n");
}

double get_bank_balance(void)
{
	double balance = 0;
	printf("Enter your bank balance: ");
	scanf("%lf", &balance);
	return balance;
}

double get_wager_amount(void)
{
	double wager = 0;
	printf("Enter amount you would like to wager: ");
	scanf("%lf", &wager);
	return wager;
}

int check_wager_amount(double balance, double wage)
{
	if (wage > balance)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

unsigned int roll_die(void)
{
	unsigned int die = 0;

	// generate numbers between 1 - 6, inclusive
	die = (rand() % 6) + 1;

	return die;
}

int calculate_sum_dice(int die1, int die2)
{
	int sum = 0;
	sum = die1 + die2;
	return sum;
}

int is_win_loss_or_point(int sum)
{
	if (sum == 7 || sum == 11)
	{
		return 1;
	}
	else if (sum == 2 || sum == 3 || sum == 12)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

int is_point_loss_or_neither(int sum, int point)
{
	if (sum == point)
	{
		return 1;
	}
	else if (sum == 7)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

void chatter_messages(int check, int roll_count,double balance)
{
	if (roll_count >= 10)
	{
		printf("Took you a while didn't it?");
	}
	else if (check == 0)
	{
		printf("Thanks for your money. I think you should try again.\n");
	}
	else if (check == 1)
	{
		printf("You got lucky this time. ");
	}

}


