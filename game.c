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


static char *playerOneCardOne;
static char *playerOneCardTwo;
static char *playerOneCardThree;
static char *playerOneCardFour;
static char *playerOneCardFive;

static char *playerTwoCardOne;
static char *playerTwoCardTwo;
static char *playerTwoCardThree;
static char *playerTwoCardFour;
static char *playerTwoCardFive;



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
SceCtrlData pad;
int playerStarting;
char cursorPathLeft[200] = "./images/selector_left.png";
char cursorPathRight[200] = "./images/selector_right.png";
char *activeCursorPath;
Image* lCursorSide1 = loadImage( cursorPathLeft );
Image* lCursorSide2 = loadImage( cursorPathLeft );
Image* lCursorSide3 = loadImage( cursorPathLeft );
Image* lCursorSide4 = loadImage( cursorPathLeft );
Image* lCursorSide5 = loadImage( cursorPathLeft );
//char *playerOneChosenCards[5][20] = { {p1.cardOne}, {p1.cardTwo}, {p1.cardThree}, {p1.cardFour}, {p1.cardFive} };
//char *playerTwoChosenCards[5][20] = { {p2.cardOne}, {p2.cardTwo}, {p2.cardThree}, {p2.cardFour}, {p2.cardFive} };
char *cardSelectedRight;
int selMenuLeft = 0;
int selMenuRight = 0;
int sideDrawDoneLeft = 0;
int sideDrawDoneRight = 0;
int cursorDrawn = 0;
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
		sprintf( activeCursorPath, cursorPathLeft );
		lCursorSide1 = loadImage( activeCursorPath );
		blitAlphaImageToScreen( 0, 0, 24, 15, lCursorSide1, 78, triadSideCardGridY[selMenuLeft]);
		cursorDrawn = 1;
		if(pad.Buttons & PSP_CTRL_UP){
			if(selMenuLeft > 0){
				selMenuLeft--;
				switch(selMenuLeft){
					case 0:
						if(cursorDrawn == 1){
							freeImage( lCursorSide1 );
							freeImage( lCursorSide2 );
							freeImage( lCursorSide3 );
							freeImage( lCursorSide4 );
							freeImage( lCursorSide5 );
						}
						sprintf( activeCursorPath, cursorPathLeft );
						lCursorSide1 = loadImage( activeCursorPath );
						blitAlphaImageToScreen( 0, 0, 24, 15, lCursorSide1, 78, triadSideCardGridY[selMenuLeft]);
						cursorDrawn = 1;
						break;
					
					case 1:
						if(cursorDrawn == 1){
							freeImage( lCursorSide1 );
							freeImage( lCursorSide2 );
							freeImage( lCursorSide3 );
							freeImage( lCursorSide4 );
							freeImage( lCursorSide5 );
						}
						sprintf( activeCursorPath, cursorPathLeft );
						lCursorSide2 = loadImage( activeCursorPath );
						blitAlphaImageToScreen( 0, 0, 24, 15, lCursorSide1, 78, triadSideCardGridY[selMenuLeft]);
						cursorDrawn = 1;
						break;

					case 2:
						if(cursorDrawn == 1){
							freeImage( lCursorSide1 );
							freeImage( lCursorSide2 );
							freeImage( lCursorSide3 );
							freeImage( lCursorSide4 );
							freeImage( lCursorSide5 );
						}
						sprintf( activeCursorPath, cursorPathLeft );
						lCursorSide3 = loadImage( activeCursorPath );
						blitAlphaImageToScreen( 0, 0, 24, 15, lCursorSide1, 78, triadSideCardGridY[selMenuLeft]);
						cursorDrawn = 1;
						break;
					case 3:
						if(cursorDrawn == 1){
							freeImage( lCursorSide1 );
							freeImage( lCursorSide2 );
							freeImage( lCursorSide3 );
							freeImage( lCursorSide4 );
							freeImage( lCursorSide5 );
						}
						sprintf( activeCursorPath, cursorPathLeft );
						lCursorSide4 = loadImage( activeCursorPath );
						blitAlphaImageToScreen( 0, 0, 24, 15, lCursorSide1, 78, triadSideCardGridY[selMenuLeft]);
						cursorDrawn = 1;
						break;

					case 4:
						if(cursorDrawn == 1){
							freeImage( lCursorSide1 );
							freeImage( lCursorSide2 );
							freeImage( lCursorSide3 );
							freeImage( lCursorSide4 );
							freeImage( lCursorSide5 );
						}
						sprintf( activeCursorPath, cursorPathLeft );
						lCursorSide5 = loadImage( activeCursorPath );
						blitAlphaImageToScreen( 0, 0, 24, 15, lCursorSide1, 78, triadSideCardGridY[selMenuLeft]);
						cursorDrawn = 1;
						break;

					default:
						break;
				}

			}
		} else if(pad.Buttons & PSP_CTRL_DOWN){
			if(selMenuLeft < 4){
				selMenuLeft++;
				switch(selMenuLeft){
					case 0:
						if(cursorDrawn == 1){
							freeImage( lCursorSide1 );
							freeImage( lCursorSide2 );
							freeImage( lCursorSide3 );
							freeImage( lCursorSide4 );
							freeImage( lCursorSide5 );
						}
						sprintf( activeCursorPath, cursorPathLeft );
						lCursorSide1 = loadImage( activeCursorPath );
						blitAlphaImageToScreen( 0, 0, 24, 15, lCursorSide1, 78, triadSideCardGridY[selMenuLeft]);
						cursorDrawn = 1;
						break;
					
					case 1:
						if(cursorDrawn == 1){
							freeImage( lCursorSide1 );
							freeImage( lCursorSide2 );
							freeImage( lCursorSide3 );
							freeImage( lCursorSide4 );
							freeImage( lCursorSide5 );
						}
						sprintf( activeCursorPath, cursorPathLeft );
						lCursorSide2 = loadImage( activeCursorPath );
						blitAlphaImageToScreen( 0, 0, 24, 15, lCursorSide1, 78, triadSideCardGridY[selMenuLeft]);
						cursorDrawn = 1;
						break;

					case 2:
						if(cursorDrawn == 1){
							freeImage( lCursorSide1 );
							freeImage( lCursorSide2 );
							freeImage( lCursorSide3 );
							freeImage( lCursorSide4 );
							freeImage( lCursorSide5 );
						}
						sprintf( activeCursorPath, cursorPathLeft );
						lCursorSide3 = loadImage( activeCursorPath );
						blitAlphaImageToScreen( 0, 0, 24, 15, lCursorSide1, 78, triadSideCardGridY[selMenuLeft]);
						cursorDrawn = 1;
						break;
					case 3:
						if(cursorDrawn == 1){
							freeImage( lCursorSide1 );
							freeImage( lCursorSide2 );
							freeImage( lCursorSide3 );
							freeImage( lCursorSide4 );
							freeImage( lCursorSide5 );
						}
						sprintf( activeCursorPath, cursorPathLeft );
						lCursorSide4 = loadImage( activeCursorPath );
						blitAlphaImageToScreen( 0, 0, 24, 15, lCursorSide1, 78, triadSideCardGridY[selMenuLeft]);
						cursorDrawn = 1;
						break;

					case 4:
						if(cursorDrawn == 1){
							freeImage( lCursorSide1 );
							freeImage( lCursorSide2 );
							freeImage( lCursorSide3 );
							freeImage( lCursorSide4 );
							freeImage( lCursorSide5 );
						}
						sprintf( activeCursorPath, cursorPathLeft );
						lCursorSide5 = loadImage( activeCursorPath );
						blitAlphaImageToScreen( 0, 0, 24, 15, lCursorSide1, 78, triadSideCardGridY[selMenuLeft]);
						cursorDrawn = 1;
						break;

					default:
						break;
			}
				if(pad.Buttons & PSP_CTRL_CROSS){
				switch(selMenuLeft){
					case 0:
						cardSelectedPlayerOne = playerOneCardOne;
						break;
					case 1:
						cardSelectedPlayerOne = playerOneCardTwo;
						break;
					case 2:
						cardSelectedPlayerOne = playerOneCardThree;
						break;
					case 3:
						cardSelectedPlayerOne = playerOneCardFour;
						break;
					case 4:
						cardSelectedPlayerOne = playerOneCardFive;
						break;
					default:
						break;
				}
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
	blitAlphaImageToScreen(0,0,74,74,cardBack,0,triadSideCardGridY[4]);
	blitAlphaImageToScreen(0,0,74,74,cardBack,0,triadSideCardGridY[3]);
	blitAlphaImageToScreen(0,0,74,74,cardBack,0,triadSideCardGridY[2]);
	blitAlphaImageToScreen(0,0,74,74,cardBack,0,triadSideCardGridY[1]);
	blitAlphaImageToScreen(0,0,74,74,cardBack,0,triadSideCardGridY[0]);
return 1;
}

int cardDrawSideMenuBackP2(){
	char cardBuffer[200];
	Image* cardBack;
	sprintf(cardBuffer, "./images/cards/back.png");
	cardBack = loadImage( cardBuffer );
	blitAlphaImageToScreen(0,0,74,74,cardBack,406,triadSideCardGridY[4]);
	blitAlphaImageToScreen(0,0,74,74,cardBack,406,triadSideCardGridY[3]);
	blitAlphaImageToScreen(0,0,74,74,cardBack,406,triadSideCardGridY[2]);
	blitAlphaImageToScreen(0,0,74,74,cardBack,406,triadSideCardGridY[1]);
	blitAlphaImageToScreen(0,0,74,74,cardBack,406,triadSideCardGridY[0]);
return 1;
}

char *cardReturnImagePathP1( char *cardNameFunction ){
	char original[200] = "./images/card/";
	strcat( original, *cardNameFunction );
	strcat( original, ".p1.png" );
	return *original;
}

char *cardReturnImagePathP2( char *cardNameFunction ){
	char original[200] = "./images/card/";
	strcat( original, *cardNameFunction );
	strcat( original, ".p2.png" );
	return *original;
}


int cardDrawSideMenuP1(){
	
	char cardBufferCardOne[200];
	char cardBufferCardTwo[200];
	char cardBufferCardThree[200];
	char cardBufferCardFour[200];
	char cardBufferCardFive[200];
	
	Image* playerOneCardOneDraw;
	Image* playerOneCardTwoDraw;
	Image* playerOneCardThreeDraw;
	Image* playerOneCardFourDraw;
	Image* playerOneCardFiveDraw;

	sprintf(cardBufferCardOne, cardReturnImagePathP1( playerOneCardOne ));
	sprintf(cardBufferCardTwo, cardReturnImagePathP1( playerOneCardTwo ));
	sprintf(cardBufferCardThree, cardReturnImagePathP1( playerOneCardThree ));
	sprintf(cardBufferCardFour, cardReturnImagePathP1( playerOneCardFour ));
	sprintf(cardBufferCardFive, cardReturnImagePathP1( playerOneCardFive ));

	playerOneCardOneDraw = loadImage( cardBufferCardOne );
	blitAlphaImageToScreen(0,0,74,74,playerOneCardOneDraw,0,triadSideCardGridY[0]);
	
	playerOneCardTwoDraw = loadImage( cardBufferCardTwo );
	blitAlphaImageToScreen(0,0,74,74,playerOneCardTwoDraw,0,triadSideCardGridY[1]);

	playerOneCardThreeDraw = loadImage( cardBufferCardThree );
	blitAlphaImageToScreen(0,0,74,74,playerOneCardThreeDraw,0,triadSideCardGridY[2]);
	
	playerOneCardFourDraw = loadImage( cardBufferCardFour );
	blitAlphaImageToScreen(0,0,74,74,playerOneCardFourDraw,0,triadSideCardGridY[3]);
	
	playerOneCardFiveDraw = loadImage( cardBufferCardFive );
	blitAlphaImageToScreen(0,0,74,74,playerOneCardFiveDraw,0,triadSideCardGridY[4]);
	return 1;
}

int cardDrawSideMenuP2(){

/*
	blitAlphaImageToScreen(0,0,74,74,playerTwoCardOne,198,triadSideCardGridY[0]);
	blitAlphaImageToScreen(0,0,74,74,playerTwoCardTwo,198,triadSideCardGridY[1]);
	blitAlphaImageToScreen(0,0,74,74,playerTwoCardThree,198,triadSideCardGridY[2]);
	blitAlphaImageToScreen(0,0,74,74,playerTwoCardFour,198,triadSideCardGridY[3]);
	blitAlphaImageToScreen(0,0,74,74,playerTwoCardFive,198,triadSideCardGridY[4]);
*/
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

int cardRight[5];
	cardRight[0] = 1;
	cardRight[1] = 5;
	cardRight[2] = 1;
	cardRight[3] = 6;
	cardRight[4] = 2;

	for( ti = 0; ti < 5; ti++){
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
playerOneCardOne = player1chosencard1;
playerOneCardTwo = player1chosencard2;
playerOneCardThree = player1chosencard3;
playerOneCardFour = player1chosencard4;
playerOneCardFive = player1chosencard5;

}

void setPlayerTwoCards( char *player2chosencard1, char *player2chosencard2, char *player2chosencard3, char *player2chosencard4, char *player2chosencard5  ){
playerTwoCardOne = player2chosencard1;
playerTwoCardTwo = player2chosencard2;
playerTwoCardThree = player2chosencard3;
playerTwoCardFour = player2chosencard4;
playerTwoCardFive = player2chosencard5;

}