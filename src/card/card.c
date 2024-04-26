Card *newCard(int value, int suit){

    Card *self=(Card*)malloc(sizeof(Card));
    *self=(Card){0};

    SetCardValue(self,value);
    SetCardSuit(self,suit);

    return self;
}

void SetCardValue(Card *self,int value){
    self->value=value;
}

void SetCardSuit(Card *self,int suit){
    self->suit= suit;
}

int  GetCardValue(Card *self){
    return self->value;
}

int GetCardSuit(Card *self){
    return self->suit;
}

void FreeCard(Card *self){
    free(self);
}
