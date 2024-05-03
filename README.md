# DeckLib
A library to provide deck functions

## Installing
Installation of the lib in your project is made as simple as possible. You just need to copy **decklib.h** file in your project and include it as a header file.

## Usage Functions
### Add cards
Cards are added by specifying the value of the card together with its suit.

~~~c

#include "decklib.h"

int main(){

    Card *card1=newCard(ACE,SPADE);
    Card *card2=newCard(CARD2,DIAMOND);

    printf("%s\n",GetCardString(card1));
    printf("%s\n",GetCardString(card2));

    FreeCard(card1);
    FreCard(card2);
    return 0;
}
~~~

### Creating a deck of cards
~~~c
#include "decklib.h"

int main(){

    //creating new cards
    Card *card1=newCard(CARD3,HEARTS);
    Card *card2=newCard(CARD4,DIAMONDS);
    Card *card3=newCard(CARD4,CLUBS);

    //creating new deck
    Deck *deck1=newDeck();

    AddCardToDeck(deck1,card1);
    AddCardToDeck(deck1,card2);
    AddCardToDeck(deck1,card3);

    printf("Printing cards added to the deck:\n");
    for(int i=0;i<deck1->size;i++){

        Card *temp= GetCardByIndex(deck1,i);
        printf("%s\n", GetCardString(temp));
    }

    FreeDeck(deck1);
    return 0;
}
~~~
### Loading all 52 cards to a deck

~~~c

#include "decklib,h"

int main(){

    Deck *fulldeck=newDeck();
    LoadFullDeck(fulldeck);

    printf("Printing a full deck of cards\n");
    printf("===============================\n");

    for(int i=o;i<fulldeck->size;i++){

        Card *temp=fulldeck->cards[i];
        printf("%s\n",GetCardString(temp));
    }

    FreeDeck(fulldeck);
    return 0;
}
~~~

### Dealing cards

~~~c
#include "decklib.h"

int main(){

     //creating new cards
    Card *card1=newCard(CARD3,HEARTS);
    Card *card2=newCard(CARD4,DIAMONDS);
    Card *card3=newCard(CARD4,CLUBS);
    Card *card4=newCard(ACE,SPADE);

    //creating new deck
    Deck *deck1=newDeck();

    AddCardToDeck(deck1,card1);
    AddCardToDeck(deck1,card2);
    AddCardToDeck(deck1,card3);
    AddCardToDeck(deck1,card4);

    //dealing cards
    Deck *player=DealCards(deck1,2);

    printf("Printing cards dealt to player===================\n");
    for(int i=0;i<player->size;i++){

        Card *temp=GetCardByIndex(player,i);
        printf("%s\n",GetCardString(temp));

    }
    printf("Printing cards remaining on the deck:============\n");
    for(int i=0;i<deck1->size;i++){

        Card *temp= GetCardByIndex(deck1,i);
        printf("%s\n", GetCardString(temp));
    }

    FreeDeck(player);
    FreeDeck(deck1);
    return 0;
}
~~~

### Transferring cards from one deck to another

~~~c
#include "decklib.h"

int main(){

     //creating new cards
    Card *card1=newCard(CARD3,HEARTS);
    Card *card2=newCard(CARD4,DIAMONDS);
    Card *card3=newCard(CARD4,CLUBS);
    Card *card4=newCard(ACE,SPADE);

    //creating new deck
    Deck *deck1=newDeck();

    AddCardToDeck(deck1,card1);
    AddCardToDeck(deck1,card2);
    AddCardToDeck(deck1,card3);
    AddCardToDeck(deck1,card4);

    Deck *deck2=newDeck();
    TransferCards(deck1,deck2,2);//transferring 2 cards from deck1 to deck2

    printf("Printing cards transfered to deck2===================\n");
    for(int i=0;i<deck2->size;i++){

        Card *temp=GetCardByIndex(deck2,i);
        printf("%s\n",GetCardString(temp));

    }
    printf("Printing cards remaining on the deck:============\n");
    for(int i=0;i<deck1->size;i++){

        Card *temp= GetCardByIndex(deck1,i);
        printf("%s\n", GetCardString(temp));
    }

    FreeDeck(deck2);
    FreeDeck(deck1);
    return 0;
}
~~~






