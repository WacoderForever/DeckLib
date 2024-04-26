typedef struct Deck{

    Card **cards;
    int size;

}Deck;

Deck *newDeck();

void AddCardToDeck(Deck *self, Card *card);

int SearchCardIndexInDeck(Deck *self, Card *card);

Card  *GetCardByIndex(Deck *self,int index);

void RemoveCardByIndex(Deck *self,int index);

void RemoveCardFromDeck(Deck *self,Card *card);

void ShuffleDeck(Deck *self);

void DealCards(Deck *self, Deck *mycards);

void FreeDeck(Deck *self);
