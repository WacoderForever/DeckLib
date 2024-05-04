
#include "decklib.h"

int main(){



    Deck *maindeck=newDeck();
    LoadFullDeck(maindeck);
    ShuffleDeck(maindeck);
    
    for(int i =0; i < maindeck->size;i++){
        printf("%s\n",GetCardString(maindeck->cards[i]));
    }

    FreeDeck(maindeck);


    return 0;
}