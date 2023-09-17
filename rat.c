#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rat.h"

#if defined(__MINGW32__) || defined(__linux__)
#include <unistd.h>
#endif

#ifdef __WATSONC__
#include <dos.h>
#include <conio.h>
#endif

#ifdef __MINGW32__
#include <windows.h>
#include <mmsystem.h>
#endif

#ifdef __linux__
#include "linux_audio.h" 
#include <pthread.h>
#endif

#include "frames.h"

void port_sleep(int ms)
{
    #ifdef __MINGW32__
        Sleep(ms);
    #endif

    #ifdef __linux__
        usleep(ms * 1000);
    #endif

    #ifdef __WATCOMC__
        delay(ms);
    #endif
}

void port_audio() 
{
    #ifdef __MINGW32__
    PlaySound("loop", NULL, SND_RESOURCE | SND_LOOP | SND_ASYNC);
    #endif

    #ifdef __linux__
    pthread_t audio_thread;
    pthread_create(&audio_thread, NULL, linux_audioplay, NULL);
    pthread_join(audio_thread, NULL);
    #endif
}

void port_cls()
{
    printf("\033[H\033[J");
}

void port_gotoxy(int x, int y)
{
    printf("\033[%d;%dH", (y), (x));
}

int main()
{
	//int arrLen = sizeof frames / sizeof frames[0];
    int framecount = 0;

    port_audio();

    port_cls();
    port_gotoxy(0, 0);
    
    for(int i = 0; i == i; i++) {
        port_gotoxy(0, 0);
        
        printf("\n                                                         You have been blessed with %d spins of the rat.\n", framecount / 30);
        printf(frames[i]);
        port_sleep(100);        

        if(i == 30) {
            i = 0;
        }
        framecount++;
    }
	return 0;
}
