#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROCK 1
#define PAPER 2
#define SCISSORS 3

int main(void){
    
    int ownHand, theirHand, wins, loses;
    char usrInput[10];
    char* cmpOutput;
    ownHand = rand();
    ownHand = ownHand%3 + 1;
    if(ownHand == ROCK){
	cmpOutput = "Rock";
    }
    else if(ownHand == PAPER){
	cmpOutput = "Paper";
    }
    else{
	cmpOutput = "Scissors";
    }
    printf("Enter 'rock','paper','scissors','score' or 'quit': ");
    scanf("%s", usrInput);
    wins=0;
    loses=0;
    while(strcmp(usrInput, "quit") != 0){
	
	if(strcmp(usrInput, "rock") == 0){
	    theirHand = ROCK;
	}
	else if(strcmp(usrInput, "paper") == 0){
	    theirHand = PAPER;
	}
	else if(strcmp(usrInput, "scissors") == 0){
	    theirHand = SCISSORS;
	}
	else if(strcmp(usrInput, "score") == 0){
	    printf("You have won %d times and lost %d times.\n",wins,loses);
	    printf("Enter 'rock','paper','scissors','score' or 'quit': ");
	    scanf("%s",usrInput);
	    continue;
	}
	else{
	    printf("invalid input, please enter 'rock','paper','scissors','score' or 'quit': ");
	    scanf("%s",usrInput);
	    continue;
	}

	if(ownHand == theirHand){
	    printf("%s, it's a draw.\n",cmpOutput);
	    ownHand = rand();
	    ownHand = ownHand%3 +1;
	}
	else if(ownHand == ROCK && theirHand == SCISSORS || ownHand == PAPER && theirHand == ROCK ||
	    ownHand == SCISSORS && theirHand == PAPER){
	    printf("%s, I win.\n", cmpOutput);
	    ownHand = theirHand;
	    loses++;
	}
	else{
	    printf("%s, you win.\n", cmpOutput);
	    wins++;
	    if(ownHand == ROCK){
		ownHand = SCISSORS;
	    }
	    else if(ownHand == PAPER){
		ownHand = ROCK;
	    }
	    else{
		ownHand = PAPER;
	    }
	}
	if(ownHand == ROCK){
            cmpOutput = "Rock";
        }
        else if(ownHand == PAPER){
            cmpOutput = "Paper";
        }
        else{
            cmpOutput = "Scissors";
        }
	printf("Enter 'rock','paper','scissors','score' or 'quit': ");
	scanf("%s", usrInput);
    }
}
