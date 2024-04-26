#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "card/card.h"
#include "deck/deck.h"

#include "card/card.c"
#include "deck/deck.c"

int main(){

    srand(time(NULL));

    Card *card1=newCard('A',"Spade");
    Card *card2=newCard('2',"Diamond");
    Card *card3=newCard('3',"Clubs");
    Card *card4=newCard('4',"Hearts");
    Card *card5=newCard('5',"Spade");

    Deck *maindeck=newDeck();
    AddCardToDeck(maindeck,card1);
    AddCardToDeck(maindeck,card2);
    AddCardToDeck(maindeck,card3);
    AddCardToDeck(maindeck,card4);
    AddCardToDeck(maindeck,card5);

    printf("Printing cards added to the deck:\n");
    for(int i=0;i<maindeck->size;i++){

        Card *temp=maindeck->cards[i];
        printf("%c %s\n",GetCardValue(temp),GetCardSuit(temp));
    }

    Deck *player=newDeck();

    DealCards(maindeck,player);
    printf("Cards dealt:\n");

    for(int i=0;i<player->size;i++){

        Card *temp=player->cards[i];
        printf("%c %s\n",GetCardValue(temp),GetCardSuit(temp));
    }

    FreeDeck(player);
    FreeDeck(maindeck);

    return 0;
}