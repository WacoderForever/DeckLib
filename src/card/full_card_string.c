//
// Created by mateusmoutinho on 26/04/24.
//

const char * GetCardString(Card *self){
    if(self->suit == SPADES){
        if(self->value == ACES){
            return "Ace of Spades";
        }
        if(self->value == CARD2){
            return "2 of Spades";
        }
        if(self->value == CARD3){
            return "3 of Spades";
        }
        if(self->value == CARD4){
            return "4 of Spades";
        }
        if(self->value == CARD5){
            return "5 of Spades";
        }
        if(self->value == CARD6){
            return "6 of Spades";
        }
        if(self->value == CARD7){
            return "7 of Spades";
        }
        if(self->value == CARD8){
            return "8 of Spades";
        }
        if(self->value == CARD9){
            return "9 of Spades";
        }
        if(self->value == CARD10){
            return "10 of Spades";
        }
        if(self->value == JACKS){
            return "Jack of Spades";
        }
        if(self->value == QUEEN){
            return "Queen of Spades";
        }
        if(self->value == KING){
            return "King of Spades";
        }


    }

    if(self->suit == DIAMONDS){
        if(self->value == ACES){
            return "Ace of Diamonds";
        }
        if(self->value == CARD2){
            return "2 of Diamonds";
        }
        if(self->value == CARD3){
            return "3 of Diamonds";
        }
        if(self->value == CARD4){
            return "4 of Diamonds";
        }
        if(self->value == CARD5){
            return "5 of Diamonds";
        }
        if(self->value == CARD6){
            return "6 of Diamonds";
        }
        if(self->value == CARD7){
            return "7 of Diamonds";
        }
        if(self->value == CARD8){
            return "8 of Diamonds";
        }
        if(self->value == CARD9){
            return "9 of Diamonds";
        }
        if(self->value == CARD10){
            return "10 of Diamonds";
        }
        if(self->value == JACKS){
            return "Jack of Diamonds";
        }
        if(self->value == QUEEN){
            return "Queen of Diamonds";
        }
        if(self->value == KING){
            return "King of Diamonds";
        }

    }
    if(self->suit == CLUBS){
        if(self->value == ACES){
            return "Ace of Clubs";
        }
        if(self->value == CARD2){
            return "2 of Clubs";
        }
        if(self->value == CARD3){
            return "3 of Clubs";
        }
        if(self->value == CARD4){
            return "4 of Clubs";
        }
        if(self->value == CARD5){
            return "5 of Clubs";
        }
        if(self->value == CARD6){
            return "6 of Clubs";
        }
        if(self->value == CARD7){
            return "7 of Clubs";
        }
        if(self->value == CARD8){
            return "8 of Clubs";
        }
        if(self->value == CARD9){
            return "9 of Clubs";
        }
        if(self->value == CARD10){
            return "10 of Clubs";
        }
        if(self->value == JACKS){
            return "Jack of Clubs";
        }
        if(self->value == QUEEN){
            return "Queen of Clubs";
        }
        if(self->value == KING){
            return "King of Clubs";
        }
    }
    if(self->suit == HEARTS){
        if(self->value == ACES){
            return "Ace of Hearts";
        }
        if(self->value == CARD2){
            return "2 of Hearts";
        }
        if(self->value == CARD3){
            return "3 of Hearts";
        }
        if(self->value == CARD4){
            return "4 of Hearts";
        }
        if(self->value == CARD5){
            return "5 of Hearts";
        }
        if(self->value == CARD6){
            return "6 of Hearts";
        }
        if(self->value == CARD7){
            return "7 of Hearts";
        }
        if(self->value == CARD8){
            return "8 of Hearts";
        }
        if(self->value == CARD9){
            return "9 of Hearts";
        }
        if(self->value == CARD10){
            return "10 of Hearts";
        }
        if(self->value == JACKS){
            return "Jack of Hearts";
        }
        if(self->value == QUEEN){
            return "Queen of Hearts";
        }
        if(self->value == KING){
            return "King of Hearts";
        }

    }

    return NULL;



}