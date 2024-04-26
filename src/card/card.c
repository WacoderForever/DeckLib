Card *newCard(char value,char *suit){

    Card *self=(Card*)malloc(sizeof(Card));
    *self=(Card){0};

    SetCardValue(self,value);
    SetCardSuit(self,suit);

    return self;
}

void SetCardValue(Card *self,char value){

    self->value=value;
}

void SetCardSuit(Card *self,char *suit){

    if(self->suit){

        free(self->suit);
    }

    self->suit=strdup(suit);
}

char GetCardValue(Card *self){

    return self->value;
}

char *GetCardSuit(Card *self){

    return self->suit;
}

void FreeCard(Card *self){

    if(self){
        
        free(self->suit);
    }

    free(self);
}