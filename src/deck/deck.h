typedef struct Deck{

    Card **cards;
    int size;

}Deck;

Deck *newDeck();

void AddCardToDeck(Deck *self, Card *card);

void LoadFullDeck(Deck *self);

int SearchCardIndexInDeck(Deck *self, Card *card);

Card  *GetCardByIndex(Deck *self,int index);

void TransferCards(Deck *src,Deck *dest,int number);

void RemoveCardByIndex(Deck *self,int index);

void RemoveCardReferenceByIndex(Deck *self,int index);

void RemoveCardFromDeck(Deck *self,Card *card);

int privateDeck_lib_get_random_card_index(Deck *self);

void ShuffleDeck(Deck *self);

Deck * DealCards(Deck *self,int size);

void FreeDeck(Deck *self);
