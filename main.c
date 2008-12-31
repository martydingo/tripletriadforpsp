#include <pspkernel.h>
#include <pspdisplay.h>
#include <pspctrl.h>
#include <stdio.h>
#include <psppower.h>

#include "graphics.h"
#include "game.h"

PSP_MODULE_INFO("Background Changer", 0, 1, 1);

#define RGB(r, g, b) ((r)|((g)<<8)|((b)<<16)) 
int * selItem;

int exit_callback(int arg1, int arg2, void *common){
	sceKernelExitGame();
	return 0;
}
int CallbackThread(SceSize args, void *argp) {
	int cbid;
	
	cbid = sceKernelCreateCallback("Exit Callback", exit_callback, NULL);
	sceKernelRegisterExitCallback(cbid);
	
	sceKernelSleepThreadCB();
	
	return 0;
}

int SetupCallbacks(void){
	int thid = 0;
	
	thid = sceKernelCreateThread("update_thread", CallbackThread, 0x11, 0xFA0, 0, 0);
	if(thid >= 0){
		sceKernelStartThread(thid, 0, 0);
	}
	return thid;
}


int main(void){
	scePowerSetClockFrequency( 333, 333, 166 );
	SetupCallbacks();
	initGraphics();
	
	SceCtrlData pad;
	int i;
	int selItem = 0;
	char filler[15];

	Color highlightColor = RGB(200, 200, 200);
    Color dimmedColor = RGB(100, 100, 100);
    Color shadowColorH = RGB(55, 55, 55 );
    Color shadowColorD = RGB(55, 55, 55 ); 
	char buffer[200];
	Image* bg;
	sprintf(buffer,"background.png");
	bg = loadImage(buffer);
	int x = 0;
	int y = 0;
	while(1){
		sceCtrlReadBufferPositive(&pad, 1);
		
	if(pad.Buttons & PSP_CTRL_UP){
		if(selItem > 0){
			selItem--;
		}
		for(i=0; i<10; i++){
			sceDisplayWaitVblankStart();
		}
	} else if(pad.Buttons & PSP_CTRL_DOWN){
		if(selItem < 2){
			selItem++;
		}
		for(i=0; i<10; i++){
			sceDisplayWaitVblankStart();
		}
	}
		if(pad.Buttons & PSP_CTRL_CROSS){
			switch(selItem){
				case 0:
					game();
					break;
				case 1:
					break;
				case 2:
					sceKernelExitGame();
					break;
				default:
				break;
			}
		}	
	blitAlphaImageToScreen(0, 0, 480, 272, bg, x, y);
	sprintf(filler, "New Game");
		if(selItem == 0){
			printTextScreen(190, 60, filler, shadowColorH);
			printTextScreen(190, 60, filler,	highlightColor);
		} else {
			printTextScreen(190, 60, filler, shadowColorD);
			printTextScreen(190, 60, filler, dimmedColor);
		}
    sprintf(filler, "How To Play");
        if(selItem == 1) {
			printTextScreen(190, 70, filler, shadowColorH);
            printTextScreen(190, 70, filler, highlightColor);
        } else {
            printTextScreen(190, 70, filler, shadowColorD);
			printTextScreen(190, 70, filler, dimmedColor);
        }
    sprintf(filler, "Exit");
        if(selItem == 2) {
            printTextScreen(190, 80, filler, shadowColorH);
            printTextScreen(190, 80, filler, highlightColor);
        } else {
             printTextScreen(190, 80, filler, shadowColorD);
             printTextScreen(190, 80, filler, dimmedColor);
        } 
		flipScreen();
	}
	return 0;
}

