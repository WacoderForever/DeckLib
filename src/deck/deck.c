Deck *newDeck(){

    Deck *self=(Deck*)malloc(sizeof(Deck));
    *self=(Deck){0};
    self->cards=(Card**)malloc(0);

    return self;

}

int SearchCardInDeck(Deck *self,Card *card){

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

    self->cards=(Card**)realloc(
            self->cards,
            (self->size+1) * sizeof(Deck)

            );
    self->cards[self->size]=card;

    self->size++;

}

void UpdateDeckAfterCardRemoval(Deck *self,int pos){
    
    for(pos;pos<self->size;++pos){

        self->cards[pos]=self->cards[pos+1];
    }

    self->size--;
}

int FindCardIndex(Deck *self,Card *card){

    int result;

    for(int i=0;i<self->size;i++){

        if(self->cards[i]==card){

            result=i;
            return result;
        }
    }
}

void RemoveCardFromDeck(Deck *self,Card *card){

    int exists=SearchCardInDeck(self,card);
    if(exists==0){

        exit(1);
    }

    for(int i=0;i<self->size;i++){

        if(card==self->cards[i]){

            UpdateDeckAfterCardRemoval(self,i);
            break;
        }
    }

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