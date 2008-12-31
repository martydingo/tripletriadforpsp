#include <pspkernel.h>
#include <pspdisplay.h>
#include <pspctrl.h>
#include <stdio.h>
//#include <string.h>
#include "graphics.h"
#define RGB(r, g, b) ((r)|((g)<<8)|((b)<<16)) 
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


void resetScreen();
void cardDrawSideMenuBackP1();
void cardDrawSideMenuBackP2();
string cardReturnImagePathP1( string cardNameFunction );
string cardReturnImagePathP2( string cardNameFunction );
void cardDrawSideMenuP1();
void cardDrawSideMenuP2();
void cardDrawImageP1Board( string cardNameFunction, int grid );
void cardDrawImageP2Board( string cardNameFunction, int grid );
int cardCheckTop( string cardNameFunction );
int cardCheckRight( string cardNameFunction );
int cardCheckBottom( string cardNameFunction );
int cardCheckLeft( string cardNameFunction );
string firstRandStart();
void setPlayerOneCards( string player1chosencard1, string player1chosencard2, string player1chosencard3, string player1chosencard4, string player1chosencard5  );
void setPlayerTwoCards( string player2chosencard1, string player2chosencard2, string player2chosencard3, string player2chosencard4, string player2chosencard5  );

char cardName[5][20] = {"Geezard", "Funguar", "Bite Bug", "Red Bat", "Blobra"};

int triadGridX[10] = { 126, 202, 278, 126, 202, 278, 126, 202, 278 };
int triadGridY[10] = { 13, 13, 13, 88, 88, 88, 163, 163, 163 };
int triadSideCardGridX[6] = { 36, 64, 92, 120, 148 };

void game(){
string playerStarting;
playerStarting = firstRandStart();

	resetScreen(); // have to clear the screen to display background etc.
	setPlayerOneCards( "Geezard", "Funguar", "Bite Bug", "Red Bat", "Blobra"); 
	setPlayerTwoCards( "Geezard", "Funguar", "Bite Bug", "Red Bat", "Blobra"); //set player's cards
		
	if(playerStarting == "p1"){
	cardDrawSideMenuP1();
	cardDrawSideMenuBackP2();
	} else {
	cardDrawSideMenuP2();
	cardDrawSideMenuBackP1();
	}
}

void resetScreen(){
	clearScreen(RGB(0,0,0));
	char buffer[200];
	Image* bg;
	sprintf(buffer,"./images/backgrounddeck.png");
	bg = loadImage(buffer);
	blitAlphaImageToScreen(0,0,480,272,bg,0,0); 
	flipScreen(); // printed background
}
void cardDrawSideMenuBackP1(){
	string cardBuffer;
	Image* cardBack;
	sprintf(cardBuffer, "./images/cards/back.png");
	cardBack = loadImage( cardBuffer );
	blitAlphaImageToScreen(0,0,74,74,cardBack,triadSideCardGridX[1],0);
	blitAlphaImageToScreen(0,0,74,74,cardBack,triadSideCardGridX[2],0);
	blitAlphaImageToScreen(0,0,74,74,cardBack,triadSideCardGridX[3],0);
	blitAlphaImageToScreen(0,0,74,74,cardBack,triadSideCardGridX[4],0);
	blitAlphaImageToScreen(0,0,74,74,cardBack,triadSideCardGridX[5],0);
}

void cardDrawSideMenuBackP2(){
	string cardBuffer;
	Image* cardBack;
	sprintf(cardBuffer, "./images/cards/back.png");
	cardBack = loadImage( cardBuffer );
	blitAlphaImageToScreen(0,0,74,74,cardBack,triadSideCardGridX[1],198);
	blitAlphaImageToScreen(0,0,74,74,cardBack,triadSideCardGridX[2],198);
	blitAlphaImageToScreen(0,0,74,74,cardBack,triadSideCardGridX[3],198);
	blitAlphaImageToScreen(0,0,74,74,cardBack,triadSideCardGridX[4],198);
	blitAlphaImageToScreen(0,0,74,74,cardBack,triadSideCardGridX[5],198);
}

string cardReturnImagePathP1( string cardNameFunction ){
	string original = "./images/card/";
	strcat( original, cardNameFunction );
	strcat( original, ".p1.png" );
	return original;
}

string cardReturnImagePathP2( string cardNameFunction ){
	string original = "./images/card/";
	strcat( original, cardNameFunction );
	strcat( original, ".p2.png" );
	return original;
}


void cardDrawSideMenuP1(){
	struct playerOneCards p1;
	Image* playerOneCardOne;
	playerOneCardOne = loadImage(cardReturnImagePathP1( p1.cardOne ));
	Image* playerOneCardTwo;
	playerOneCardTwo = loadImage(cardReturnImagePathP1( p1.cardTwo ));
	Image* playerOneCardThree;
	playerOneCardThree = loadImage(cardReturnImagePathP1( p1.cardThree ));
	Image* playerOneCardFour;
	playerOneCardFour = loadImage(cardReturnImagePathP1( p1.cardFour ));
	Image* playerOneCardFive;
	playerOneCardFive = loadImage(cardReturnImagePathP1( p1.cardFive ));
	blitAlphaImageToScreen(0,0,74,74,playerOneCardOne,triadSideCardGridX[1],0);
	blitAlphaImageToScreen(0,0,74,74,playerOneCardTwo,triadSideCardGridX[2],0);
	blitAlphaImageToScreen(0,0,74,74,playerOneCardThree,triadSideCardGridX[3],0);
	blitAlphaImageToScreen(0,0,74,74,playerOneCardFour,triadSideCardGridX[4],0);
	blitAlphaImageToScreen(0,0,74,74,playerOneCardFive,triadSideCardGridX[5],0);
	flipScreen();
}

void cardDrawSideMenuP2(){
	struct playerTwoCards p2;
	Image* playerTwoCardOne;
	playerTwoCardOne = loadImage(cardReturnImagePathP2( p2.cardOne ));
	Image* playerTwoCardTwo;
	playerTwoCardTwo = loadImage(cardReturnImagePathP2( p2.cardTwo ));
	Image* playerTwoCardThree;
	playerTwoCardThree = loadImage(cardReturnImagePathP2( p2.cardThree ));
	Image* playerTwoCardFour;
	playerTwoCardFour = loadImage(cardReturnImagePathP2( p2.cardFour ));
	Image* playerTwoCardFive;
	playerTwoCardFive = loadImage(cardReturnImagePathP2( p2.cardFive ));
	blitAlphaImageToScreen(0,0,74,74,playerTwoCardOne,triadSideCardGridX[1],198);
	blitAlphaImageToScreen(0,0,74,74,playerTwoCardTwo,triadSideCardGridX[2],198);
	blitAlphaImageToScreen(0,0,74,74,playerTwoCardThree,triadSideCardGridX[3],198);
	blitAlphaImageToScreen(0,0,74,74,playerTwoCardFour,triadSideCardGridX[4],198);
	blitAlphaImageToScreen(0,0,74,74,playerTwoCardFive,triadSideCardGridX[5],198);
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

void cardDrawImageP2Board( string cardNameFunction, int grid ){
	string original = "./images/card/";
	strcat( original, cardNameFunction );
	strcat( original, ".p2.png" );
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

string firstRandStart(){
int n;
string playerStarting;
n = rand() / ( 32767 / 2 + 1);
	if(n == 0){
	playerStarting = "p1";
	} else {
	playerStarting = "p2";
	}
return playerStarting;
}

void setPlayerOneCards( string player1chosencard1, string player1chosencard2, string player1chosencard3, string player1chosencard4, string player1chosencard5  ){
struct playerOneCards p1;
p1.cardOne = player1chosencard1;
p1.cardTwo = player1chosencard2;
p1.cardThree = player1chosencard3;
p1.cardFour = player1chosencard4;
p1.cardFive = player1chosencard5;

}

void setPlayerTwoCards( string player2chosencard1, string player2chosencard2, string player2chosencard3, string player2chosencard4, string player2chosencard5  ){
struct playerTwoCards p2;
p2.cardOne = player2chosencard1;
p2.cardTwo = player2chosencard2;
p2.cardThree = player2chosencard3;
p2.cardFour = player2chosencard4;
p2.cardFive = player2chosencard5;

}