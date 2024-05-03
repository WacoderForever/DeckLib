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
Card  *GetCardByIndex(Deck *self,int index){
    //these allows -1 iterations
    if(index < 0){
        index  = self->size - index;
    }

    if(index >= self->size ){
        return NULL;
    }

    return  self->cards[index];
}

void AddCardToDeck(Deck *self,Card *card){

    self->cards=(Card**)realloc(self->cards,(self->size+1) * sizeof(Deck));
    self->cards[self->size]=card;

    self->size++;

}

void LoadFullDeck(Deck *self){

    for(int i=0;i<4;i++){

        for(int j=0;j<13;j++){

            Card *temp=newCard(j,i);
            AddCardToDeck(self,temp);
        }
    }
}

void TransferCards(Deck *src,Deck *dest,int number){

    if(src->size < number){
        printf("Source deck has less cards\n");
        return;
    }

   // ShuffleDeck(src);
    for(int i=0;i<number;i++){
        Card *card=src->cards[0]; //pick top card
        AddCardToDeck(dest,card);
        RemoveCardReferenceByIndex(src,0);
    }

}

void RemoveCardByIndex(Deck *self,int index){


    //these allows -1 iterations
    if(index < 0){
        index  = self->size - index;
    }
    if(index >= self->size ){
        return;
    }

    FreeCard(self->cards[index]); // remove the found card
    self->size--;
    for(int i=index ; i < self->size; i++){
        self->cards[i] = self->cards[i+1];
    }

}

void RemoveCardReferenceByIndex(Deck *self,int index){

    //these allows -1 iterations
    if(index < 0){
        index  = self->size - index;
    }
    if(index >= self->size ){
        return;
    }

    self->size--;
    for(int i=index ; i < self->size; i++){
        self->cards[i] = self->cards[i+1];
    }

}