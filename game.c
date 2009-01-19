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
char cardPathP1[5][40] = {"./images/card/Geezard.p1.png", "./images/card/Funguar.p1.png", "./images/card/Bite Bug.p1.png", "./images/card/Red Bat.p1.png", "Blobra.p1.png"};
char cardPathP2[5][40] = {"./images/card/Geezard.p2.png", "./images/card/Funguar.p2.png", "./images/card/Bite Bug.p2.png", "./images/card/Red Bat.p2.png", "Blobra.p2.png"};

int triadGridX[10] = { 126, 202, 278, 126, 202, 278, 126, 202, 278 };
int triadGridY[10] = { 13, 13, 13, 88, 88, 88, 163, 163, 163 };
int triadSideCardGridY[5] = { 36, 64, 92, 120, 148 };

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
	cardDrawSideMenuP1();
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

			}	flipScreen();
		}  else if(pad.Buttons & PSP_CTRL_DOWN){
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
	} flipScreen();
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
	blitAlphaImageToScreen(0,0,74,74,cardBack,0,triadSideCardGridY[0]);
	blitAlphaImageToScreen(0,0,74,74,cardBack,0,triadSideCardGridY[1]);
	blitAlphaImageToScreen(0,0,74,74,cardBack,0,triadSideCardGridY[2]);
	blitAlphaImageToScreen(0,0,74,74,cardBack,0,triadSideCardGridY[3]);
	blitAlphaImageToScreen(0,0,74,74,cardBack,0,triadSideCardGridY[4]);
return 1;
}

int cardDrawSideMenuBackP2(){
	char cardBuffer[200];
	Image* cardBack;
	sprintf(cardBuffer, "./images/cards/back.png");
	cardBack = loadImage( cardBuffer );
	blitAlphaImageToScreen(0,0,74,74,cardBack,406,triadSideCardGridY[0]);
	blitAlphaImageToScreen(0,0,74,74,cardBack,406,triadSideCardGridY[1]);
	blitAlphaImageToScreen(0,0,74,74,cardBack,406,triadSideCardGridY[2]);
	blitAlphaImageToScreen(0,0,74,74,cardBack,406,triadSideCardGridY[3]);
	blitAlphaImageToScreen(0,0,74,74,cardBack,406,triadSideCardGridY[4]);
return 1;
}

int cardDrawSideMenuP1(){
//String Compare and Draw for Card One Start.
char * Path = "Default";
int i = 0; 
char cardOnePathP1[40];
Image* playerOneCardOneDraw;
	for( i = 0; i<5; i++ ){
		if(strcmp(playerOneCardOne, cardName[i])==0){
			Path = cardPathP1[i];
			sprintf( cardOnePathP1, Path );
		}
	}
playerOneCardOneDraw = loadImage( cardOnePathP1 );
blitAlphaImageToScreen(0,0,74,74,playerOneCardOneDraw,0,triadSideCardGridY[0]);
// End String Compare and Draw for Card One.	
	
// String Compare and Draw for Card Two Start.
i = 0;
Path = "Default";
char cardTwoPathP1[40];
Image* playerOneCardTwoDraw;
	for( i=0; i<5; i++ ){
		if(strcmp(playerOneCardTwo, cardName[i])==0){
			Path = cardPathP1[i];
			sprintf( cardTwoPathP1, Path );
		}
	}
playerOneCardTwoDraw = loadImage( cardTwoPathP1 );
blitAlphaImageToScreen(0,0,74,74,playerOneCardTwoDraw,0,triadSideCardGridY[1]);
// End String Compare and Draw for Card Two.

// String Compare and Draw for Card Three Start.
i = 0;
Path = "Default"; //Reminder: Set Default to Geezard Path
char cardThreePathP1[40];
Image* playerOneCardThreeDraw;
	for( i=0; i<5; i++){
		if(strcmp(playerOneCardThree,cardName[i])==0){
			Path = cardPathP1[i];
			sprintf( cardThreePathP1, Path );
		}
	}
playerOneCardThreeDraw = loadImage( cardThreePathP1 );
blitAlphaImageToScreen(0,0,74,74,playerOneCardThreeDraw,0,triadSideCardGridY[2]);
// End String Compare and Draw for Card Three.

// String Compare and Draw for Card Four Start.
i = 0;
Path = "Default"; //Reminder: Set Default to Geezard Path
char cardFourPathP1[40];
Image* playerOneCardFourDraw;
	for( i=0; i<5; i++){
		if(strcmp(playerOneCardFour,cardName[i])==0){
			Path = cardPathP1[i];
			sprintf( cardFourPathP1, Path );
		}
	}
playerOneCardFourDraw = loadImage( cardFourPathP1 );
blitAlphaImageToScreen(0,0,74,74,playerOneCardFourDraw,0,triadSideCardGridY[3]);
// End String Compare and Draw for Card Four.

// String Compare and Draw for Card Five Start.
i = 0;
Path = "Default"; //Reminder: Set Default to Geezard Path
char cardFivePathP1[40];
Image* playerOneCardFiveDraw;
	for( i=0; i<5; i++){
		if(strcmp(playerOneCardFive,cardName[i])==0){
			Path = cardPathP1[i];
			sprintf( cardFivePathP1, Path );
		}
	}
playerOneCardFiveDraw = loadImage( cardFivePathP1 );
blitAlphaImageToScreen(0,0,74,74,playerOneCardFiveDraw,0,triadSideCardGridY[4]);
// End String Compare and Draw for Card Five.
return 1;	
}

int cardDrawSideMenuP2(){
//String Compare and Draw for Card One Start.
char * Path = "Default";
int i = 0; 
char cardOnePathP2[40];
Image* playerTwoCardOneDraw;
	for( i = 0; i<5; i++ ){
		if(strcmp(playerTwoCardOne, cardName[i])==0){
			Path = cardPathP2[i];
			sprintf( cardOnePathP2, Path );
		}
	}
playerTwoCardOneDraw = loadImage( cardOnePathP2 );
blitAlphaImageToScreen(0,0,74,74,playerTwoCardOneDraw,0,triadSideCardGridY[0]);
// End String Compare and Draw for Card One.	
	
// String Compare and Draw for Card Two Start.
i = 0;
Path = "Default";
char cardTwoPathP2[40];
Image* playerTwoCardTwoDraw;
	for( i=0; i<5; i++ ){
		if(strcmp(playerTwoCardTwo, cardName[i])==0){
			Path = cardPathP2[i];
			sprintf( cardTwoPathP2, Path );
		}
	}
playerTwoCardTwoDraw = loadImage( cardTwoPathP2 );
blitAlphaImageToScreen(0,0,74,74,playerTwoCardTwoDraw,0,triadSideCardGridY[1]);
// End String Compare and Draw for Card Two.

// String Compare and Draw for Card Three Start.
i = 0;
Path = "Default"; //Reminder: Set Default to Geezard Path
char cardThreePathP2[40];
Image* playerTwoCardThreeDraw;
	for( i=0; i<5; i++){
		if(strcmp(playerTwoCardThree,cardName[i])==0){
			Path = cardPathP2[i];
			sprintf( cardThreePathP2, Path );
		}
	}
playerTwoCardThreeDraw = loadImage( cardThreePathP2 );
blitAlphaImageToScreen(0,0,74,74,playerTwoCardThreeDraw,0,triadSideCardGridY[2]);
// End String Compare and Draw for Card Three.

// String Compare and Draw for Card Four Start.
i = 0;
Path = "Default"; //Reminder: Set Default to Geezard Path
char cardFourPathP2[40];
Image* playerTwoCardFourDraw;
	for( i=0; i<5; i++){
		if(strcmp(playerTwoCardFour,cardName[i])==0){
			Path = cardPathP2[i];
			sprintf( cardFourPathP2, Path );
		}
	}
playerTwoCardFourDraw = loadImage( cardFourPathP2 );
blitAlphaImageToScreen(0,0,74,74,playerTwoCardFourDraw,0,triadSideCardGridY[3]);
// End String Compare and Draw for Card Four.

// String Compare and Draw for Card Five Start.
i = 0;
Path = "Default"; //Reminder: Set Default to Geezard Path
char cardFivePathP2[40];
Image* playerTwoCardFiveDraw;
	for( i=0; i<5; i++){
		if(strcmp(playerTwoCardFive,cardName[i])==0){
			Path = cardPathP2[i];
			sprintf( cardFivePathP2, Path );
		}
	}
playerTwoCardFiveDraw = loadImage( cardFivePathP2 );
blitAlphaImageToScreen(0,0,74,74,playerTwoCardFiveDraw,0,triadSideCardGridY[4]);
// End String Compare and Draw for Card Five.
return 1;
}

void cardDrawImageP1Board( char *cardNameFunction, int grid ){
char * path = "Default";
char cardPathBuffer[40];
Image* cardBuffer;
int i = 0;
	for( i = 0; i<5; i++ ){
		if(strcmp(cardNameFunction, cardName[i])==0){
			path = cardPathP1[i];
			sprintf( cardPathBuffer, path );
		}
	}
	int x=0;
	int y=0;
	x = triadGridX[grid];
	y = triadGridY[grid];
	cardBuffer = loadImage( cardPathBuffer );
	blitAlphaImageToScreen(0,0,74,74,cardBuffer,x,y);
}

void cardDrawImageP2Board( char *cardNameFunction, int grid ){
char * path = "Default";
char cardPathBuffer[40];
Image* cardBuffer;
int i = 0;
	for( i = 0; i<5; i++ ){
		if(strcmp(cardNameFunction, cardName[i])==0){
			path = cardPathP2[i];
			sprintf( cardPathBuffer, path );
		}
	}
	int x=0;
	int y=0;
	x = triadGridX[grid];
	y = triadGridY[grid];
	cardBuffer = loadImage( cardPathBuffer );
	blitAlphaImageToScreen(0,0,74,74,cardBuffer,x,y);
}

int cardCheckTop( char *cardNameFunction ){
int ti;
int cardTopReturn = 0;

int cardTop[5];
	cardTop[0] = 1;
	cardTop[1] = 5;
	cardTop[2] = 1;
	cardTop[3] = 6;
	cardTop[4] = 2;

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

int cardBottom[5];
	cardBottom[0] = 1;
	cardBottom[1] = 5;
	cardBottom[2] = 1;
	cardBottom[3] = 6;
	cardBottom[4] = 2;

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

int cardLeft[5];
	cardLeft[0] = 1;
	cardLeft[1] = 5;
	cardLeft[2] = 1;
	cardLeft[3] = 6;
	cardLeft[4] = 2;

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