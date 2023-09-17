win: rat.c loop
	gcc rat.c windows_loop.o -o bin/rat.exe -lwinmm

loop:
	windres -i .\rat.rc -o windows_loop.o

linux:
	gcc rat.c linux_audio.c -o bin/rat -lm -lpthread

dos:
	wcl386 rat.c -za99 -d1 -l=dos4g -fe=rat_dos.exe
	del rat.err
	del rat.obj
	move rat_dos.exe bin/

win95:
	wcl386 rat.c -za99 -d1 -l=win95 -fe=rat_w95.exe
	del rat.err
	del rat.obj
	move rat_w95.exe bin/

watcom_nt:
	wcl386 rat.c -za99 -d1 -l=nt -fe=rat_nt.exe
	del rat.err
	del rat.obj
	move rat_nt.exe bin/

clean:
	del rat.exe
	del loop.o