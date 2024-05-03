
#include "src/one.h"

int main(){


    Card *card1=newCard(ACES,SPADES);

    Card *card2=newCard(CARD2,DIAMONDS);
    Card *card3=newCard(CARD3,CLUBS);
    Card *card4=newCard(CARD4,HEARTS);
    Card *card5=newCard(CARD5,SPADES);
    Deck *maindeck=newDeck();

    AddCardToDeck(maindeck,card1);

    AddCardToDeck(maindeck,card2);
    AddCardToDeck(maindeck,card3);
    AddCardToDeck(maindeck,card4);
    AddCardToDeck(maindeck,card5);
    ShuffleDeck(maindeck);

    printf("Printing cards added to the deck:\n");
    for(int i=0;i<maindeck->size;i++){

        Card *temp= GetCardByIndex(maindeck,i);
        printf("%s\n", GetCardString(temp));
    }

    printf("Printing sub deck:============================\n");
    Deck  *sub_deck = newDeck();
    TransferCards(maindeck,sub_deck,4);

    for(int i = 0; i < sub_deck->size;i++){
        Card *temp= GetCardByIndex(sub_deck,i);
        printf("%s\n", GetCardString(temp));
    }
    printf("Printing main deck after deal:============================\n");
    for(int i=0;i<maindeck->size;i++){

        Card *temp= GetCardByIndex(maindeck,i);
        printf("%s\n", GetCardString(temp));
    }

    
    FreeDeck(maindeck);
    FreeDeck(sub_deck);

    return 0;
}