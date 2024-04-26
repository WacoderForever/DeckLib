typedef struct Card{

    int value;
    int suit;

}Card;

void SetCardValue(Card *self,int value);

void SetCardSuit(Card *self,int suit);

Card *newCard(int value, int suit);

const char * GetCardString(Card *self);

const char * GetCardValueString(Card *self);

const char * GetCardSuitString(Card *self);

Card *copyCard(Card *self);

int GetCardValue(Card *self);

int GetCardSuit(Card *self);

void FreeCard(Card *self);