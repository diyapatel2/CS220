#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "poker.h"

/* Global instances of the two players */
struct player P1, P2;

/* Parse card from a 2 char input */
struct card parse(const char *card)
{
	struct card c;
	switch(card[0]) {
	case '2':c.val = TWO;
	case '3': c.val = THREE;
	case '4':c.val = FOUR;
	case '5':c.val = FIVE;
	case '6':c.val = SIX;
	case '7':c.val = SEVEN; 
	case '8':c.val = EIGHT; 
	case '9': c.val = card[0] - '0'; break;
	case 'T': c.val = TEN; break;
	case 'J': c.val = JACK; break;
	case 'Q': c.val = QUEEN; break;
	case 'K': c.val = KING; break;
	case 'A': c.val = ACE; break;
	default: break;
	}
	switch(card[1]) {
	case 'S': c.suit = SPADE; break;
	case 'D': c.suit = DIAMOND; break;
	case 'C': c.suit = CLUB; break;
	case 'H': c.suit = HEART; break;
	default: break;
	}
	return c;
}

/* Count the number of occurrences of each card 2 through Ace */
void count_cards(struct hand *h)
{
	/* TASK 6: For each card in the hand, increment the card_count for that card. */
	int d;
	for(d = 0; d < 5; d++){
		unsigned int a= ((int) (h-> cards[d].val));
		h->card_count[a]++;
	}
}

int is_flush(struct hand *h)
{
	/* TASK 9: Implement is_flush(). A hand is a flush if all the cards are of the same suit */
	/* Return 1 if flush, 0 otherwise */
	int i; 
	int ret;
	for(i =0; i < 4; i++){
		if((h->cards[i].suit == h->cards[i+1].suit)){
			ret = 1; 
		}
		else{
			ret = 0;
			break;
		}

	}
	return ret; 
}

int is_straight(struct hand *h)
{
	/* By this stage, the cards are counted */
	/* TASK 7: Implement is_straight(). 
	   A hand is considered a straight if the number of occurrences of 5 consecutive cards is 1. 
	   If a straight is found, return 1. 
	 */


	int i, a,b,c,d,e, ret;
	ret = a = b = c = d =  0;
	int x = 1; 
	e = 12; 
	for(i = 0; i < 13; i ++){
		a = i+1;
		b = i+2;
		c = i+3; 
		d = i+4; 
		if(h->vector & (x << (i)) && (h->vector & (x << (a))) && (h->vector & (x << (b))) && (h->vector & (x << (c))) && (h->vector & (x << (d))))
		{			
			ret = 1;
		}
	}

	/* TASK 8: handle special case A2345 */
	/* If a straight is not found, return 0 */
	/* bit masking Ace using left shifting and then XORing to set Ace to zero it to reset the bit */
	
	if(ret && h->vector &(1UL << 0) && h->vector & (1UL << e)){
		h->vector = h->vector ^ (x << e);
	}

	return ret;
}
		
/* This important function converts a player's hand into weighted unsigned long number. Larger the number, stronger the hand. 
It is a 55bit vector as shown below (2 is the LSB and StraightFlush is the MSB) */
/* 2, 3, 4, 5, 6, 7, 8, 9, T, J, Q, K, A, 22, 33, 44, 55, 66, 77, 88, 99, TT, JJ, QQ, KK, AA,
222, 333, 444, 555, 666, 777, 888, 999, TTT, JJJ, QQQ, KKK, AAA, Straight, Flush, Full House, 2222, 3333, 
4444, 5555, 6666, 7777, 8888, 9999, TTTT, JJJJ, QQQQ, KKKK, AAAA, StraightFlush */
/* The number of occurrences of each number in the hand is first calculated in count_cards(). 
Then, depending on the numeber of occurrences, the corresponding bit in the bit-vector is set. 
In order to find the winner, a simple comparison of the bit vectors (i.e., unsigned long integers) will suffice! */
void eval_strength(struct hand *h)
{	
	int a, b, c, d, e, f, g; 

	a= b = c = 0;
	d = 40; 
	e = 39; 
	g = 55; 
	f = 41; 
	int pair = 0; 
	int straight_flush = 1;
	int three = 0; 
	int i; 
	/* TASK 5: Implement the eval_strength function */

	/*count the number of occurences */
	count_cards(h);
	/*set the appropriate bit in the vector by iterating through card_count array */
	for(i = 0; i < 13; i++){
		a = i+13; 
		b = i+26; 
		c = i +42; 
		/* setting bits for cards (0-12) */
		if(h->card_count[i] == 1){
			h->vector =h->vector| (1UL << i);
		}
		/* setting bits for cards (13-25) */
		else if (h->card_count[i] == 2){
			h->vector = h->vector| (1UL << (a));
			straight_flush = 0;
			pair = 1;	
		}
		/* setting bits for cards (26 - 38) */
		else if(h->card_count[i] == 3){
			h->vector = h->vector | (1UL << (b));
			three =  1; 
			straight_flush = 0; 
		}
		/* sets bits for (42-54)*/
		else if(h->card_count[i] == 4){
			h->vector = h->vector | (1UL << (c));
			straight_flush = 0; 	
		}
	
	}
	/*check for straight or flush or both, then set the correct bit vector */
	if(straight_flush && is_flush(h)){
		h->vector = h->vector | (1UL << d);
	}
	if(straight_flush && is_straight(h)){
		h->vector = h->vector | (1UL << e );
	}
	if(is_straight(h) && (is_flush(h))){
		h->vector = h->vector | (1UL << g);
	 
	}
	if(three && pair){
		h->vector = h->vector | (1UL << f); 
	}


}

void eval_players_best_hand(struct player *p)
{
	/* TASK 10: For each hand in the 'hands' array of the player, use eval_strength to evaluate the strength of the hand */
	/*
	eval_strength(p.P1);
	eval_strength(p.P2);
	*/
	/*       Point best_hand to the strongest hand. */
	/*       HINT: eval_strength will set the hands vector according to its strength. Larger the vector, stronger the hand. */
	int i,best;
	unsigned long vec;
	eval_strength(&(p->hands[0]));
	vec = p->hands[0].vector;
	for(i = 0; i < MAX_COMBINATIONS; i++){
		eval_strength(&p->hands[i]);
		if((p->hands[i].vector) > (vec)){
			vec = p->hands[i].vector;
			best = i;
		}
	}
	(p->best_hand) = &p->hands[best];
}


void copy_card(struct card *dst, struct card *src)
{
	/* TASK 3: Implement function copy_card that copies a card structure from src to dst. */ 
	*dst = *src; 

}
void initialize_player(struct player *p, struct card *player_cards, struct card *community_cards)
{
	memset(p, 0, sizeof(struct player));

	/* There are 21 possible 5 card combinations (i.e., 7C5) in Pc1 Pc2 Cc1 Cc2 Cc3 Cc4 Cc5 */
	/* TASK 4: Initialize the 'hands' array in the player structure with the cards. 
	 *       Each element of the hands array will contain one possible combination of the hand.
	 *       Use copy_card function.
	 */ 
	/* 1:  Pc1 Pc2 Cc1 Cc2 Cc3 */
	/* 2:  Pc1 Pc2 Cc1 Cc2 Cc4 */
	/* 3:  Pc1 Pc2 Cc1 Cc2 Cc5 */

	copy_card(&(p->hands[0].cards[0]), &(player_cards[0]));
	copy_card(&(p->hands[0].cards[1]), &(player_cards[1]));
	copy_card(&(p->hands[0].cards[2]), &(community_cards[0]));
	copy_card(&(p->hands[0].cards[3]), &(community_cards[1]));
	copy_card(&(p->hands[0].cards[4]), &(community_cards[2]));
        copy_card(&(p->hands[1].cards[0]), &(player_cards[0]));
        copy_card(&(p->hands[1].cards[1]), &(player_cards[1])); 
	copy_card(&(p->hands[1].cards[3]), &(community_cards[0]));
	copy_card(&(p->hands[1].cards[4]), &(community_cards[1]));
	copy_card(&(p->hands[1].cards[5]), &(community_cards[3]));
	copy_card(&(p->hands[2].cards[0]), &(player_cards[0]));
	copy_card(&(p->hands[2].cards[1]), &(player_cards[1]));
	copy_card(&(p->hands[2].cards[2]), &(community_cards[0]));
	copy_card(&(p->hands[2].cards[3]), &(community_cards[1]));
	copy_card(&(p->hands[2].cards[4]), &(community_cards[4]));
	copy_card(&(p->hands[3].cards[0]),  &(player_cards[0]));
        copy_card(&(p->hands[3].cards[1]),  &(player_cards[1]));
	copy_card(&(p->hands[3].cards[2]), &(community_cards[0]));
	copy_card(&(p->hands[3].cards[3]), &(community_cards[2]));
	copy_card(&(p->hands[3].cards[4]), &(community_cards[3]));
	copy_card(&(p->hands[4].cards[0]),  &(player_cards[0]));
	copy_card(&(p->hands[4].cards[1]),  &(player_cards[1]));
	copy_card(&(p->hands[4].cards[2]), &(community_cards[0]));
	copy_card(&(p->hands[4].cards[3]), &(community_cards[2]));
	copy_card(&(p->hands[4].cards[4]), &(community_cards[4]));
        copy_card(&(p->hands[5].cards[0]),  &(player_cards[0]));
	copy_card(&(p->hands[5].cards[1]),  &(player_cards[1]));
        copy_card(&(p->hands[5].cards[2]), &(community_cards[0]));
        copy_card(&(p->hands[5].cards[3]), &(community_cards[3]));
        copy_card(&(p->hands[5].cards[4]), &(community_cards[4]));
        copy_card(&(p->hands[6].cards[0]),  &(player_cards[0]));
        copy_card(&(p->hands[6].cards[1]),  &(player_cards[1]));
        copy_card(&(p->hands[6].cards[2]), &(community_cards[1]));
        copy_card(&(p->hands[6].cards[3]), &(community_cards[2]));
        copy_card(&(p->hands[6].cards[4]), &(community_cards[3]));
	copy_card(&(p->hands[7].cards[0]),  &(player_cards[0]));
        copy_card(&(p->hands[7].cards[1]),  &(player_cards[1]));
        copy_card(&(p->hands[7].cards[2]), &(community_cards[1]));
	copy_card(&(p->hands[7].cards[3]), &(community_cards[2]));
	copy_card(&(p->hands[7].cards[4]), &(community_cards[4]));
	copy_card(&(p->hands[8].cards[0]),  &(player_cards[0]));
	copy_card(&(p->hands[8].cards[1]),  &(player_cards[1]));
	copy_card(&(p->hands[8].cards[2]), &(community_cards[1]));
	copy_card(&(p->hands[8].cards[3]), &(community_cards[3]));
	copy_card(&(p->hands[8].cards[4]), &(community_cards[4]));
	copy_card(&(p->hands[9].cards[0]),  &(player_cards[0]));
	copy_card(&(p->hands[9].cards[1]),  &(player_cards[1]));
	copy_card(&(p->hands[9].cards[2]), &(community_cards[2]));
	copy_card(&(p->hands[9].cards[3]), &(community_cards[3]));
	copy_card(&(p->hands[9].cards[4]), &(community_cards[4]));
	copy_card(&(p->hands[10].cards[0]), &(player_cards[0]));
	copy_card(&(p->hands[10].cards[1]), &(community_cards[0]));
	copy_card(&(p->hands[10].cards[2]), &(community_cards[1]));
	copy_card(&(p->hands[10].cards[3]), &(community_cards[2]));
	copy_card(&(p->hands[10].cards[4]), &(community_cards[3]));
	copy_card(&(p->hands[11].cards[0]),  &(player_cards[0]));
	copy_card(&(p->hands[11].cards[1]),  &(community_cards[0]));
	copy_card(&(p->hands[11].cards[2]), &(community_cards[1]));
	copy_card(&(p->hands[11].cards[3]), &(community_cards[2]));
	copy_card(&(p->hands[11].cards[4]), &(community_cards[4]));
	copy_card(&(p->hands[12].cards[0]),  &(player_cards[0]));
	copy_card(&(p->hands[12].cards[1]),  &(community_cards[0]));
	copy_card(&(p->hands[12].cards[2]), &(community_cards[1]));
	copy_card(&(p->hands[12].cards[3]), &(community_cards[3]));
	copy_card(&(p->hands[12].cards[4]), &(community_cards[4]));
	copy_card(&(p->hands[13].cards[0]),  &(player_cards[0]));
	copy_card(&(p->hands[13].cards[1]),  &(community_cards[0]));
	copy_card(&(p->hands[13].cards[2]), &(community_cards[2]));
	copy_card(&(p->hands[13].cards[3]), &(community_cards[3]));
	copy_card(&(p->hands[13].cards[4]), &(community_cards[4]));
	copy_card(&(p->hands[14].cards[0]),  &(player_cards[0]));
	copy_card(&(p->hands[14].cards[1]),  &(community_cards[1]));
	copy_card(&(p->hands[14].cards[2]), &(community_cards[2]));
	copy_card(&(p->hands[14].cards[3]), &(community_cards[3]));
	copy_card(&(p->hands[14].cards[4]), &(community_cards[4]));
	copy_card(&(p->hands[15].cards[0]),  &(player_cards[1]));
	copy_card(&(p->hands[15].cards[1]),  &(community_cards[0]));
	copy_card(&(p->hands[15].cards[2]), &(community_cards[1]));
	copy_card(&(p->hands[15].cards[3]), &(community_cards[2]));
	copy_card(&(p->hands[15].cards[4]), &(community_cards[3]));
	copy_card(&(p->hands[16].cards[0]), &(player_cards[1]));
	copy_card(&(p->hands[16].cards[1]), &(community_cards[0]));
	copy_card(&(p->hands[16].cards[2]), &(community_cards[1]));
	copy_card(&(p->hands[16].cards[3]), &(community_cards[2]));
	copy_card(&(p->hands[16].cards[4]), &(community_cards[4]));
	copy_card(&(p->hands[17].cards[0]), &(player_cards[1]));
	copy_card(&(p->hands[17].cards[1]), &(community_cards[0]));
	copy_card(&(p->hands[17].cards[2]), &(community_cards[1]));
	copy_card(&(p->hands[17].cards[3]), &(community_cards[3]));
	copy_card(&(p->hands[17].cards[4]), &(community_cards[4]));
	copy_card(&(p->hands[18].cards[0]),  &(player_cards[1]));
	copy_card(&(p->hands[18].cards[1]),  &(community_cards[0]));
	copy_card(&(p->hands[18].cards[2]), &(community_cards[2]));
	copy_card(&(p->hands[18].cards[3]), &(community_cards[3]));
	copy_card(&(p->hands[18].cards[4]), &(community_cards[4]));
	copy_card(&(p->hands[19].cards[0]), &(player_cards[1]));
	copy_card(&(p->hands[19].cards[1]), &(community_cards[1]));
	copy_card(&(p->hands[19].cards[2]), &(community_cards[2]));
	copy_card(&(p->hands[19].cards[3]), &(community_cards[3]));
	copy_card(&(p->hands[19].cards[4]), &(community_cards[4]));
	copy_card(&(p->hands[20].cards[0]), &(community_cards[0]));
	copy_card(&(p->hands[20].cards[1]), &(community_cards[1]));
	copy_card(&(p->hands[20].cards[2]), &(community_cards[2]));
	copy_card(&(p->hands[20].cards[3]), &(community_cards[3]));
	copy_card(&(p->hands[20].cards[4]), &(community_cards[4]));
}

/* Parse each hand in the input file, evaluate the strengths of hands and identify a winner by comparing the weighted vectors */
void process_input(FILE *fp)
{
	char p1[2][3];
	char p2[2][3];
	char comm[5][3];
	struct card p1_cards[2], p2_cards[2], community_cards[5];
	int i;
        FILE *fo = fopen("Output.txt", "w");
	while(fscanf(fp, "%s %s %s %s %s %s%s %s %s", 
		&p1[0][0], &p1[1][0], &p2[0][0], &p2[1][0], &comm[0][0], 
		&comm[1][0], &comm[2][0], &comm[3][0], &comm[4][0]) == 9) {

		memset(p1_cards, 0, sizeof(struct card) * 2);
		memset(p2_cards, 0, sizeof(struct card) * 2); 
		memset(community_cards, 0, sizeof(struct card) * 5);

		for(i = 0; i < 2; i++) {
			p1_cards[i] = parse(&p1[i][0]);
			p2_cards[i] = parse(&p2[i][0]);
		}

		for(i = 0; i < 5; i++) {
			community_cards[i] = parse(&comm[i][0]);
		}
		initialize_player(&P1, &p1_cards[0], &community_cards[0]);
		initialize_player(&P2, &p2_cards[0], &community_cards[0]);
		eval_players_best_hand(&P1);
		eval_players_best_hand(&P2);

		/* TASK 11: Check which player has the strongest hand and print either "Player 1 wins" or "Player 2 wins" */

		if(P1.best_hand->vector < P2.best_hand->vector)
		{
			fprintf(fo, "%s\n", "Player 2 wins");
		}
		if(P1.best_hand->vector  > P2.best_hand->vector){
			fprintf(fo, "%s\n", "Player 1 wins");
		}
	
}
fclose(fo);
}
int main(int argc, char *argv[])
{
	FILE *fp;

	if(argc != 2 || (fp = fopen(argv[1], "r")) == NULL) {
		printf("Unable to open input file\n");
		exit(-1);
	}
	
	process_input(fp);

	return 0;
}
