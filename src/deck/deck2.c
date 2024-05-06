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
    unsigned  long current_seed = DECKLIB_DEBUG_SEED +TOTAL_ITERATIONS;
    if(!DECKLIB_DEBUG_SEED){
        current_seed = time(NULL) + DECK_LIB_SEED + TOTAL_ITERATIONS;
    }
    if(!DECK_LIB_STARTED_SEED){
        DECK_LIB_STARTED_SEED = current_seed;
    }

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
    if(self->size < size){
        printf("Source deck has less cards\n");
        return NULL;
   }

    ShuffleDeck(self);
    Deck  *sub_deck  = newDeck();

    for(int i=0;i<size;i++){
        Card *card=self->cards[0]; //pick top card
        AddCardToDeck(sub_deck,card);
        RemoveCardReferenceByIndex(self,0);

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