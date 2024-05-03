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
        Card  *copy = copyCard(card);
        AddCardToDeck(dest,copy);
        RemoveCardByIndex(src,0);
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

void  RemoveCardFromDeck(Deck *self,Card *card){
    //these its important because it avoids null refes
    Card  *copy = copyCard(card);
    while (true){
        int index = SearchCardIndexInDeck(self,copy);
        if(index == -1){
            break;
        }
        RemoveCardByIndex(self,index);
    }
    FreeCard(copy);

}
int privateDeck_lib_get_random_card_index(Deck *self){
    unsigned  long current_seed = time(NULL) + DECK_LIB_SEED + TOTAL_ITERATIONS;
    TOTAL_ITERATIONS+=1;
    srand(current_seed);
    return rand() %( self->size-1);

}
void ShuffleDeck(Deck *self){

    for(int i = 0; i < DECK_LIB_TOTAL_SHUFFLE; i++){
        int card_index = privateDeck_lib_get_random_card_index(self);
        int index_to_swap = privateDeck_lib_get_random_card_index(self);

        if(card_index == index_to_swap){
            continue;
        }
        Card  *temp =  self->cards[card_index];
        self->cards[card_index] = self->cards[index_to_swap];
        self->cards[index_to_swap] = temp;
    }

}

Deck * DealCards(Deck *self,int size){

    ShuffleDeck(self);
    Deck  *sub_deck  = newDeck();

    for(int i=0;i<size;i++){
        Card *card=self->cards[0]; //pick top card
        Card  *copy = copyCard(card);
        AddCardToDeck(sub_deck,copy);
        RemoveCardByIndex(self,0);

    }
    return sub_deck;
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