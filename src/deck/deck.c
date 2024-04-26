Deck *newDeck(){

    Deck *self=(Deck*)malloc(sizeof(Deck));
    *self=(Deck){0};
    self->cards=(Card**)malloc(0);

    return self;

}

int SearchCardIndexInDeck(Deck *self, Card *card){

    int result=-1;
    for(int i=0;i<self->size;i++){
        Card  *current = self->cards[i];
        if(current->value == card->value && current->suit == card->suit){
            return i;
        }
    }

    return result;
}

void AddCardToDeck(Deck *self,Card *card){

    self->cards=(Card**)realloc(self->cards,(self->size+1) * sizeof(Deck));
    self->cards[self->size]=card;

    self->size++;

}



void  RemoveCardFromDeck(Deck *self,Card *card){


    int index = SearchCardIndexInDeck(self,card);
    if(index == -1){
        return;
    }

    FreeCard(self->cards[index]); // remove the found card
    self->size--;
    for(int i=index ; i < self->size; i++){
        self->cards[i] = self->cards[i+1];
    }
    //make a recursive call to keep removing
    RemoveCardFromDeck(self,card);
}

void ShuffleDeck(Deck *self){

    int rand1=30+rand()%13;

    for(int i=0;i<rand1;i++){

        int rand2=rand()%(self->size);
        Card *temp=self->cards[rand2];
        self->cards[rand2]=self->cards[rand1%(self->size)];
        self->cards[rand1%(self->size)]=temp;
    }


}

void DealCards(Deck *deck, Deck *mycards){

    ShuffleDeck(deck);
    
    for(int i=0;i<4;i++){
        
        Card *card=deck->cards[i]; //pick top card
        AddCardToDeck(mycards,card); //give selected card to player
        RemoveCardFromDeck(deck,card);  //remove card from the main deck
        ShuffleDeck(deck);
    }
}

void FreeDeck(Deck *self){
    if(!self){
        return;
    }

    for(int i=0;i<self->size;i++){
        Card *card=self->cards[i];
        FreeCard(card);
    }
    free(self->cards);
    free(self);
}