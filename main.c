
#include "src/one.h"

int main(){

    srand(time(NULL));

    Card *card1=newCard(ACES,SPADES);
    Card *card1A=newCard(ACES,SPADES);

    Card *card2=newCard(CARD2,DIAMONDS);
    Card *card3=newCard(CARD3,CLUBS);
    Card *card4=newCard(CARD4,HEARTS);
    Card *card5=newCard(CARD5,SPADES);
    Deck *maindeck=newDeck();

    AddCardToDeck(maindeck,card1);
    AddCardToDeck(maindeck,card1A);

    AddCardToDeck(maindeck,card2);
    AddCardToDeck(maindeck,card3);
    AddCardToDeck(maindeck,card4);
    AddCardToDeck(maindeck,card5);

    RemoveCardFromDeck(maindeck,card1);

    printf("Printing cards added to the deck:\n");
    for(int i=0;i<maindeck->size;i++){

        Card *temp=maindeck->cards[i];
        printf("%s\n", GetCardString(temp));
    }


    FreeDeck(maindeck);

    return 0;
}