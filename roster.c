#include <stdio.h>
#include <ctype.h>
#include <string.h>

const int NUM_PLAYERS = 5;

void jerseyPrompt(int i){
    printf("Enter player %d's jersey number:\n", i+1);
}

void printRoster(int jerseyNums[], int ratingNums[]){
    printf("ROSTER\n");

    for (int i = 0; i < NUM_PLAYERS; i++){
        printf("Player %d -- Jersey number: %d, Rating: %d\n", i+1, jerseyNums[i], ratingNums[i]);
    }
}


char menu(){
    char input;
    printf("\n");
    printf("MENU\n");
    printf("u - Update player rating\n");
    printf("r - Replace player\n");
    printf("o - Output roster\n");
    printf("q - Quit\n\n");
    printf("Choose an option:\n");
        scanf(" %c", &input);
    return input;
}

void ratingPrompt(int i){
    printf("Enter player %d's rating:\n", i+1);
}



void jersey_out (int jersey[], int index){
    
    while (1){
        scanf("%d", &jersey[index]);

        if (jersey[index] > -1 && jersey[index] < 100){
            break;
        }
        else{
            printf("Invalid jersey number. Enter player %d's jersey number:\n", index+1);

        }

    }
}

void rating_out (int rank[], int index){

    while (1){
        scanf("%d", &rank[index]);

        if (rank[index] > 0 && rank[index] < 11){
            break;
        }
        else{
            printf("Invalid player rating. Enter player %d's rating:\n", index+1);

        }

    }
}

void update (int jersey[], int ranking[]){
    int flag = 0;
    int number = 0, z = 0;
    
    while (!flag){
       if (z == 0) {printf("Enter jersey number for rating update:\n");}
        scanf("%d", &number); z++;

    for (int i = 0; i < NUM_PLAYERS; i++){
        if (number == jersey[i]){
            printf("Found jersey number. Enter new rating for player:\n");
            scanf("%d", &ranking[i]);
            flag = 1;
            while(ranking[i] < 1 || ranking[i] > 10){
                printf("Invalid player rating. Enter valid rating:\n");
                scanf("%d", &ranking[i]);
            }
        }
    }
        if (!flag) printf("Invalid jersey number. Enter valid jersey number:\n");
      
    }
}

void replace(int jersey[], int ranking[]){
    int flag = 0;
    int number = 0, z = 0;
    
    while (!flag){
       if (z == 0) {printf("Enter jersey number to replace:\n");}
        scanf("%d", &number); z++;

    for (int i = 0; i < NUM_PLAYERS; i++){
        if (number == jersey[i]){
            printf("Found player. Enter new jersey number:\n");
            scanf("%d", &number);
            flag = 1;
            while(number < 0 || number > 99){
                printf("Invalid jersey number. Enter valid jersey number:\n");
                scanf("%d", &number);
            }
            jersey[i] = number;
            printf("Enter player rating:\n");
            scanf("%d", &number);

            while(number < 0 || number > 10){
                printf("Invalid player rating. Enter valid rating:\n");
                scanf("%d", &number);
            }
            ranking[i] = number;
        }
    }
        if (!flag) printf("Invalid jersey number. Enter valid jersey number:\n");
      
    }
}

int main() {
    int jersey[5];
    int ranking[5];
    int i;
    char letter;

    for (i=0; i < NUM_PLAYERS; i++){
        jerseyPrompt(i);
        jersey_out (jersey, i);
        ratingPrompt(i);
        rating_out (ranking, i);
        printf("\n");
    }


    printRoster(jersey, ranking);
    letter = menu();
    
    
    while(letter != 'q'){
    printf("\n");
    if (letter == 'u'|| letter == 'r'|| letter == 'o'){
        if (letter == 'u'){
            update(jersey, ranking);
            letter = menu();
        }

        else if(letter == 'r'){
            replace(jersey, ranking);
            letter = menu();
        }

        else if(letter == 'o'){
            printRoster(jersey, ranking);
            letter = menu();
        }
    }

    else {
        printf("Invalid option\n");
        letter = menu();
    }
    
    }




    return 0;
}