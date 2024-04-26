typedef struct Card{

    char value;
    char *suit;

}Card;

void SetCardValue(Card *self,char value);
void SetCardSuit(Card *self,char *suit);

Card *newCard(char value,char *suit);

char GetCardValue(Card *self);
char *GetCardSuit(Card *self);

void FreeCard(Card *self);