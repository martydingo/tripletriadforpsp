#include <pspkernel.h>
#include <pspdisplay.h>
#include <pspctrl.h>
#include <stdio.h>
//#include <string.h>
#include "graphics.h"
typedef char string;


struct playerOneCards {
	string cardOne;
	string cardTwo;
	string cardThree;
	string cardFour;
	string cardFive;
};

struct playerTwoCards {
	string cardOne;
	string cardTwo;
	string cardThree;
	string cardFour;
	string cardFive;
};




int cardCheckTop( string cardNameFunction );
int cardCheckRight( string cardNameFunction );
int cardCheckBottom( string cardNameFunction );
int cardCheckLeft( string cardNameFunction );
int setPlayerOneCards( string player1chosencard1, string player1chosencard2, string player1chosencard3, string player1chosencard4, string player1chosencard5  );
int randFirstStart( void );

char cardName[6][20] = {"Geezard", "Funguar", "Bite Bug", "Red Bat", "Blobra"};

int triadGridX[10] = { 126, 202, 278, 126, 202, 278, 126, 202, 278 };
int triadGridY[10] = { 13, 13, 13, 88, 88, 88, 163, 163, 163 };
int triadSideCardP1GridX[6] = { 36, 64, 92, 120, 148 };
int triadSideCardP1GridY[6] = { 0, 0, 0, 0, 0 };

void game(){

}

void cardDrawSideMenuP1(){
	struct playerOneCards p1;
	
	setPlayerOneCards( "Geezard", "Funguar", "Bite Bug", "Red Bat", "Blobra");
	setPlayerTwoCards( "Geezard", "Funguar", "Bite Bug", "Red Bat", "Blobra");
	Image* playerOneCardOne;
	playerOneCardOne = loadImage(cardReturnImagePathP1( p1.cardOne );
	Image* playerOneCardTwo;
	playerOneCardTwo = loadImage(cardReturnImagePathP1( p1.cardTwo );
	Image* playerOneCardThree;
	playerOneCardThree = loadImage(cardReturnImagePathP1( p1.cardThree );
	Image* playerOneCardFour;
	playerOneCardFour = loadImage(cardReturnImagePathP1( p1.cardFour );
	Image* playerOneCardFive;
	playerOneCardFive = loadImage(cardReturnImagePathP1( p1.cardFive );
	blitAlphaImageToScreen(0,0,74,74,playerOneCardOne,triadSideCardP1GridX[1],0);
	blitAlphaImageToScreen(0,0,74,74,playerOneCardTwo,triadSideCardP1GridX[2],0);
	blitAlphaImageToScreen(0,0,74,74,playerOneCardThree,triadSideCardP1GridX[3],0);
	blitAlphaImageToScreen(0,0,74,74,playerOneCardFour,triadSideCardP1GridX[4],0);
	blitAlphaImageToScreen(0,0,74,74,playerOneCardFive,triadSideCardP1GridX[5],0);
	flipScreen();
}

void cardDrawImageP1Board( string cardNameFunction, int grid ){
	string original = "./images/card/";
	strcat( original, cardNameFunction );
	strcat( original, ".p1.png" );
	Image* cardBuffer;
	cardBuffer = loadImage(original);
	int x;
	int y;
	x = triadGridX[grid];
	y = triadGridY[grid];
	blitAlphaImageToScreen(0,0,74,74,cardBuffer,x,y);
	flipScreen();
}

int cardCheckTop( string cardNameFunction ){
int ti;
int cardTopReturn;

int cardTop[6];
	cardTop[1] = 1;
	cardTop[2] = 5;
	cardTop[3] = 1;
	cardTop[4] = 6;
	cardTop[5] = 2;

	for( ti = 0; ti < 6; ti++){
		if(cardName[ti] == cardNameFunction){
			cardTopReturn = cardTop[ti];
		}
	}

	return cardTopReturn;
}

int cardCheckRight( string cardNameFunction ){
int ti;
int cardRightReturn;

int cardRight[6];
	cardRight[1] = 1;
	cardRight[2] = 5;
	cardRight[3] = 1;
	cardRight[4] = 6;
	cardRight[5] = 2;

	for( ti = 0; ti < 6; ti++){
		if(cardName[ti] == cardNameFunction){
			cardRightReturn = cardRight[ti];
		}
	}

	return cardRightReturn;
}

int cardCheckBottom( string cardNameFunction ){
int ti;
int cardBottomReturn;

int cardBottom[6];
	cardBottom[1] = 1;
	cardBottom[2] = 5;
	cardBottom[3] = 1;
	cardBottom[4] = 6;
	cardBottom[5] = 2;

	for( ti = 0; ti < 6; ti++){
		if(cardName[ti] == cardNameFunction){
			cardBottomReturn = cardBottom[ti];
		}
	}

	return cardBottomReturn;
}


int cardCheckLeft( string cardNameFunction ){
int ti;
int cardLeftReturn;

int cardLeft[6];
	cardLeft[1] = 1;
	cardLeft[2] = 5;
	cardLeft[3] = 1;
	cardLeft[4] = 6;
	cardLeft[5] = 2;

	for( ti = 0; ti < 6; ti++){
		if(cardName[ti] == cardNameFunction){
			cardLeftReturn = cardLeft[ti];
		}
	}

	return cardLeftReturn;
}

int firstRandStart(){
int n;
n = rand() / ( 32767 / 2 + 1);
return n;
}

int setPlayerOneCards( string player1chosencard1, string player1chosencard2, string player1chosencard3, string player1chosencard4, string player1chosencard5  ){
struct playerOneCards p1;
p1.cardOne = player1chosencard1;
p1.cardTwo = player1chosencard2;
p1.cardThree = player1chosencard3;
p1.cardFour = player1chosencard4;
p1.cardFive = player1chosencard5;

return 1;
}

int setPlayerTwoCards( string player2chosencard1, string player2chosencard2, string player2chosencard3, string player2chosencard4, string player2chosencard5  ){
struct playerTwoCards p2;
p2.cardOne = player2chosencard1;
p2.cardTwo = player2chosencard2;
p2.cardThree = player2chosencard3;
p2.cardFour = player2chosencard4;
p2.cardFive = player2chosencard5;

return 1;
}