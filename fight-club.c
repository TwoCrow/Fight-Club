// Program made by Patrick J. Sherbondy
// February 22, 2019

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct fighter
{
	char *firstName;
	char *lastName;
	int age;
	int weight;
	char *fightStyle;
	int recordWins;
	int recordLosses;
	int fightScore;
}fighter;

// Reads from one of the name files to find a random first or last name for a given fighter.
//
// NOTE: This function has not been vetted thoroughly for memory leaks yet. While in development, I am more interested
// in getting some aspects of the program working before tackling memory leaks. It is first on my to-do list, though.
char *setName(char *filename)
{
	FILE *ifp = fopen(filename, "r");
	char buffer[51], *name = malloc(sizeof(char) * 51);
	int selection, counter = 1, stringAmount = 0;

	// Checks if the file failed to open.
	if (ifp == NULL)
	{
		printf("Failed to open %s\n", filename);
		printf("Please be certain to include %s in the same directory as fight-club.c!\n", filename);
	}

	// Looks through the file to determine how many distinct names are found within it.
	while (fscanf(ifp, "%s", buffer) != EOF)
	{
		stringAmount++;
	}

	// Get a random number to determine which name to pick.
	selection = (rand() % stringAmount) + 1;

	rewind(ifp);

	// Loops through the file until the randomly-selected name is found.
	while (fscanf(ifp, "%s", buffer) != EOF)
	{
		if (selection == counter)
		{
			strcpy(name, buffer);
			break;
		}
		counter++;
	}

	fclose(ifp);
	return name;
}

// Returns a random number based on an upper and lower bound that is passed to it.
//
// This function is called for multiple, separate integer-based members of the fighter struct.
int set(int lower, int upper)
{
	return rand() % (upper - lower + 1) + lower;
}

// This function returns a string that states what that fighter's fighting style is.
// It is much like rock-paper-scissors. Special modifiers to the fighter's fight score are
// earned if the match-up is in their favor.
char *setFightStyle(void)
{
	int lower = 1, upper = 3;
	int choice = rand() % (upper - lower + 1) + lower;

	if (choice == 1)
	{
		// 1.5x modifier against strong.
		return "Quick";
	}
	else if (choice == 2)
	{
		// 1.5x modifier against quick.
		return "Safe";
	}
	else
	{
		// 1.5x modifier against safe.
		return "Strong";
	}
}

// This function takes a fighter struct, and calculates that fighter's fight score based on the
// randomly generated values found in the struct.
//
// The fight score determines if that fighter will win against their opponent in that round. It will
// likely all come down to a simple comparison. If a fighter's fight score is greater than their
// opponent's, then they will wind that round.
int calculateFightScore(fighter **card)
{

}

// Fills 10 fighter cards' members with random strings and integer values.
// It then prints the values contained in each member.
void fillFighterCards(fighter **card)
{
	int i;
	char firstName[] = "first-names.txt";
	char lastName[] = "last-names.txt";

	for (i = 0; i < 10; i++)
	{
		(*card)[i].firstName = setName(firstName);
		(*card)[i].lastName = setName(lastName);
		(*card)[i].age = set(18, 50);
		(*card)[i].weight = set(100, 200);
		(*card)[i].fightStyle = setFightStyle();
		(*card)[i].recordWins = set(0, 100);
		(*card)[i].recordLosses = set(0, 100);

		printf("%s %s, %d\n", (*card)[i].firstName, (*card)[i].lastName, (*card)[i].age);
		printf("Weight: %d\n", (*card)[i].weight);
		printf("Fighting Style: %s\n", (*card)[i].fightStyle);
		printf("Record: %d-%d\n\n", (*card)[i].recordWins, (*card)[i].recordLosses);
	}
}

// Creates enough space in memory to generate 10 random fighters.
// NOTE: This function has not been properly vetted for memory leaks yet.
fighter **generateFighters(void)
{
	fighter **fighters = malloc(sizeof(fighter *) * 10);
	int i;

	for (i = 0; i < 10; i++)
	{
		fighters[i] = malloc(sizeof(fighter));
	}

	return fighters;
}

int main(void)
{
	fighter **fighters;
	srand(time(NULL));

	fighters = generateFighters();
	fillFighterCards(fighters);

	return 0;
}
