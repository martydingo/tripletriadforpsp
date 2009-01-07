#include <pspkernel.h>
#include <pspdisplay.h>
#include <pspctrl.h>
#include <stdio.h>
#include <pspdebug.h>  
#include <stdlib.h>
#include <string.h>
//#include <char.h>
#include "graphics.h"
#define RGB(r, g, b) ((r)|((g)<<8)|((b)<<16)) 
//typedef char char;
#define printf pspDebugScreenPrintf 


struct playerOneCards {
	char *cardOne;
	char *cardTwo;
	char *cardThree;
	char *cardFour;
	char *cardFive;
};

struct playerTwoCards {
	char *cardOne;
	char *cardTwo;
	char *cardThree;
	char *cardFour;
	char *cardFive;
};


void resetScreen();
int cardDrawSideMenuBackP1();
int cardDrawSideMenuBackP2();
char *cardReturnImagePathP1( char *cardNameFunction );
char *cardReturnImagePathP2( char *cardNameFunction );
int cardDrawSideMenuP1();
int cardDrawSideMenuP2();
void cardDrawImageP1Board( char *cardNameFunction, int grid );
void cardDrawImageP2Board( char *cardNameFunction, int grid );
int cardCheckTop( char *cardNameFunction );
int cardCheckRight( char *cardNameFunction );
int cardCheckBottom( char *cardNameFunction );
int cardCheckLeft( char *cardNameFunction );
int firstRandStart();
void setPlayerOneCards( char *player1chosencard1, char *player1chosencard2, char *player1chosencard3, char *player1chosencard4, char *player1chosencard5  );
void setPlayerTwoCards( char *player2chosencard1, char *player2chosencard2, char *player2chosencard3, char *player2chosencard4, char *player2chosencard5  );

char cardName[5][20] = {"Geezard", "Funguar", "Bite Bug", "Red Bat", "Blobra"};

int triadGridX[10] = { 126, 202, 278, 126, 202, 278, 126, 202, 278 };
int triadGridY[10] = { 13, 13, 13, 88, 88, 88, 163, 163, 163 };
int triadSideCardGridY[6] = { 36, 64, 92, 120, 148 };

void game(){
struct playerOneCards p1;
struct playerTwoCards p2;
Image* activeCursor;
SceCtrlData pad;
int playerStarting;
char *cursorPathLeft = "./images/selector_left.png";
char *cursorPathRight = "./images/selector_right.png";
char *activeCursorPath;
char *playerOneChosenCards[5][20] = { {p1.cardOne}, {p1.cardTwo}, {p1.cardThree}, {p1.cardFour}, {p1.cardFive} };
char *playerTwoChosenCards[5][20] = { {p2.cardOne}, {p2.cardTwo}, {p2.cardThree}, {p2.cardFour}, {p2.cardFive} };
char *cardSelectedRight;
int selMenuLeft = 0;
int selMenuRight = 0;
int sideDrawDoneLeft = 0;
int sideDrawDoneRight = 0;
char *cardSelectedPlayerOne;
playerStarting = firstRandStart();
	resetScreen(); // have to clear the screen to display background etc.

	setPlayerOneCards( "Geezard", "Funguar", "Bite Bug", "Red Bat", "Blobra"); 
	setPlayerTwoCards( "Geezard", "Funguar", "Bite Bug", "Red Bat", "Blobra"); //set player's cards
	if(playerStarting == 0){
	//cardDrawSideMenuP1();
	sideDrawDoneLeft = cardDrawSideMenuBackP2();
	activeCursorPath = cursorPathLeft;
	} else {
	cardDrawSideMenuP2();
	sideDrawDoneRight = cardDrawSideMenuBackP1();
	activeCursorPath = cursorPathRight;
	}
	while(sideDrawDoneLeft == 1){
		sceCtrlReadBufferPositive(&pad, 1); 
		if(pad.Buttons & PSP_CTRL_UP){
			if(selMenuLeft > 0){
				selMenuLeft--;
				activeCursor = loadImage(activeCursorPath);
				blitAlphaImageToScreen( 0, 0, 24, 15, activeCursor, 78, triadSideCardGridY[selMenuLeft]);
			}
		} else if(pad.Buttons & PSP_CTRL_DOWN){
			if(selMenuLeft < 4){
				selMenuLeft++;
				activeCursor = loadImage( activeCursorPath );
				blitAlphaImageToScreen( 0, 0, 24, 15, activeCursor, 78, triadSideCardGridY[selMenuLeft]);
			}
				if(pad.Buttons & PSP_CTRL_CROSS){
				switch(selMenuLeft){
					case 0:
						cardSelectedPlayerOne = p1.cardOne;
						break;
					case 1:
						cardSelectedPlayerOne = p1.cardTwo;
						break;
					case 2:
						cardSelectedPlayerOne = p1.cardThree;
						break;
					case 3:
						cardSelectedPlayerOne = p1.cardFour;
						break;
					case 4:
						cardSelectedPlayerOne = p1.cardFive;
						break;
					default:
						break;
				}
			}
		}
flipScreen();
	}
}

void resetScreen(){
	clearScreen(RGB(0,0,0));
	char buffer[200];
	Image* bg;
	sprintf(buffer,"./images/backgrounddeck.png");
	bg = loadImage(buffer);
	blitAlphaImageToScreen(0,0,480,272,bg,0,0);  // printed background
}
int cardDrawSideMenuBackP1(){
	char cardBuffer[200];
	Image* cardBack;
	sprintf(cardBuffer, "./images/cards/back.png");
	cardBack = loadImage( cardBuffer );
	blitAlphaImageToScreen(0,0,74,74,cardBack,0,triadSideCardGridY[1]);
	blitAlphaImageToScreen(0,0,74,74,cardBack,0,triadSideCardGridY[2]);
	blitAlphaImageToScreen(0,0,74,74,cardBack,0,triadSideCardGridY[3]);
	blitAlphaImageToScreen(0,0,74,74,cardBack,0,triadSideCardGridY[4]);
	blitAlphaImageToScreen(0,0,74,74,cardBack,0,triadSideCardGridY[5]);
return 1;
}

int cardDrawSideMenuBackP2(){
	char cardBuffer[200];
	Image* cardBack;
	sprintf(cardBuffer, "./images/cards/back.png");
	cardBack = loadImage( cardBuffer );
	blitAlphaImageToScreen(0,0,74,74,cardBack,406,triadSideCardGridY[1]);
	blitAlphaImageToScreen(0,0,74,74,cardBack,406,triadSideCardGridY[2]);
	blitAlphaImageToScreen(0,0,74,74,cardBack,406,triadSideCardGridY[3]);
	blitAlphaImageToScreen(0,0,74,74,cardBack,406,triadSideCardGridY[4]);
	blitAlphaImageToScreen(0,0,74,74,cardBack,406,triadSideCardGridY[5]);
return 1;
}

char *cardReturnImagePathP1( char *cardNameFunction ){
	char *original = "./images/card/";
	strcat( original, cardNameFunction );
	strcat( original, ".p1.png" );
	return original;
}

char *cardReturnImagePathP2( char *cardNameFunction ){
	char *original = "./images/card/";
	strcat( original, cardNameFunction );
	strcat( original, ".p2.png" );
	return original;
}


int cardDrawSideMenuP1(){
	struct playerOneCards p1;
	p1.cardOne = "cardOne";
	p1.cardTwo = "cardTwo";
	p1.cardThree = "cardThree";
	p1.cardFour = "cardFour";
	p1.cardFive = "cardFive";

	Image* playerOneCardOne;
	playerOneCardOne = loadImage(cardReturnImagePathP1( p1.cardOne ));
	blitAlphaImageToScreen(0,0,74,74,playerOneCardOne,0,triadSideCardGridY[1]);
	Image* playerOneCardTwo;
	playerOneCardTwo = loadImage(cardReturnImagePathP1( p1.cardTwo ));
	blitAlphaImageToScreen(0,0,74,74,playerOneCardTwo,0,triadSideCardGridY[2]);
	Image* playerOneCardThree;
	playerOneCardThree = loadImage(cardReturnImagePathP1( p1.cardThree ));
	blitAlphaImageToScreen(0,0,74,74,playerOneCardThree,0,triadSideCardGridY[3]);
	Image* playerOneCardFour;
	playerOneCardFour = loadImage(cardReturnImagePathP1( p1.cardFour ));
	blitAlphaImageToScreen(0,0,74,74,playerOneCardFour,0,triadSideCardGridY[4]);
	Image* playerOneCardFive;
	playerOneCardFive = loadImage(cardReturnImagePathP1( p1.cardFive ));
	blitAlphaImageToScreen(0,0,74,74,playerOneCardFive,0,triadSideCardGridY[5]);
	return 1;
}

int cardDrawSideMenuP2(){
	struct playerTwoCards p2;
	p2.cardOne = "cardOne";
	p2.cardTwo = "cardTwo";
	p2.cardThree = "cardThree";
	p2.cardFour = "cardFour";
	p2.cardFive = "cardFive";


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
	blitAlphaImageToScreen(0,0,74,74,playerTwoCardOne,198,triadSideCardGridY[1]);
	blitAlphaImageToScreen(0,0,74,74,playerTwoCardTwo,198,triadSideCardGridY[2]);
	blitAlphaImageToScreen(0,0,74,74,playerTwoCardThree,198,triadSideCardGridY[3]);
	blitAlphaImageToScreen(0,0,74,74,playerTwoCardFour,198,triadSideCardGridY[4]);
	blitAlphaImageToScreen(0,0,74,74,playerTwoCardFive,198,triadSideCardGridY[5]);
	return 1;
}

void cardDrawImageP1Board( char *cardNameFunction, int grid ){
	char *original = "./images/card/";
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

void cardDrawImageP2Board( char *cardNameFunction, int grid ){
	char *original = "./images/card/";
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

int cardCheckTop( char *cardNameFunction ){
int ti;
int cardTopReturn = 0;

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

int cardCheckRight( char *cardNameFunction ){
int ti;
int cardRightReturn = 0;

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

int cardCheckBottom( char *cardNameFunction ){
int ti;
int cardBottomReturn = 0;

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


int cardCheckLeft( char *cardNameFunction ){
int ti;
int cardLeftReturn = 0;

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
n=0;
return n;
}

void setPlayerOneCards( char *player1chosencard1, char *player1chosencard2, char *player1chosencard3, char *player1chosencard4, char *player1chosencard5  ){
struct playerOneCards p1;
p1.cardOne = player1chosencard1;
p1.cardTwo = player1chosencard2;
p1.cardThree = player1chosencard3;
p1.cardFour = player1chosencard4;
p1.cardFive = player1chosencard5;

}

void setPlayerTwoCards( char *player2chosencard1, char *player2chosencard2, char *player2chosencard3, char *player2chosencard4, char *player2chosencard5  ){
struct playerTwoCards p2;
p2.cardOne = player2chosencard1;
p2.cardTwo = player2chosencard2;
p2.cardThree = player2chosencard3;
p2.cardFour = player2chosencard4;
p2.cardFive = player2chosencard5;

}