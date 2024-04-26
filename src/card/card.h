typedef struct Card{

    int value;
    int suit;

}Card;

void SetCardValue(Card *self,int value);

void SetCardSuit(Card *self,int suit);

Card *newCard(int value, int suit);

const char * GetCardString(Card *self);

int GetCardValue(Card *self);

int GetCardSuit(Card *self);

void FreeCard(Card *self);