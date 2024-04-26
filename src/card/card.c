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
const char * GetCardValueString(Card *self){
    if(self->value == ACES){
        return "Aces";
    }
    if(self->value == CARD2){
        return "2";
    }
    if(self->value == CARD3){
        return "3";
    }
    if(self->value == CARD4){
        return "4";
    }
    if(self->value == CARD5){
        return "5";
    }
    if(self->value == CARD6){
        return "6";
    }
    if(self->value == CARD7){
        return "2";
    }
    if(self->value == CARD8){
        return "8";
    }
    if(self->value == CARD9){
        return "9";
    }
    if(self->value == CARD10){
        return "10";
    }
    if(self->value == JACKS){
        return "Jack";
    }
    if(self->value == QUEEN){
        return "Queen";
    }
    if(self->value == KING){
        return "King";
    }
    return  NULL;

}
const char * GetCardSuitString(Card *self){
    if(self->suit == HEARTS){
        return "Hearts";
    }
    if(self->suit == SPADES){
        return "Spades";
    }
    if(self->suit == CLUBS){
        return "Clubs";
    }
    if(self->suit == DIAMONDS){
        return "Diamonds";
    }
    return  NULL;
}

const char * GetCardSuitString(Card *self);