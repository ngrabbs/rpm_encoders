#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argv, char **argc) {

	/* 36-1@6000 rpm */
	int rpm = 6000;
	int teeth = 36;
	int missing = 1;
	int i = 0;
	int tooth_count;
	int c;

	/* milli second = .001 second */
	/* micro second = .000001 second */

	while (( c = getopt (argv, argc, "r:")) != -1) {
		switch(c)
			{
			case 'r':
				rpm = atoi(optarg);
				break;
			case '?':
				return 1;
			default:
				return 1;
			}
	}
			

	printf("at %d rpm our rpm per sec is: %d\n", rpm, rpm/60);
	printf("number of teeth per second: %d\n", teeth*(rpm/60));
	printf("number of highs and lows per second: %d\n", teeth*(rpm/60)*2);

	printf("number of milli seconds per tooth: %f\n", (float)(teeth*(rpm/60)*2)/1000);
	printf("number of micro seconds per tooth; %f\n", (float)(teeth*(rpm/60)*2)/1000000);

	/* how long in micro seconds is a tooth up and down */
	for(i=0; i<(rpm/60); i++) {
		/* cycle through teeth count */
		for(tooth_count = 0; tooth_count < teeth; tooth_count++) {
			if(missing != 0 && tooth_count+1 <= missing) {
				printf("0");
			} else {
				printf("1");
			}
			usleep(((teeth*(rpm/60)*2))/1000000);
			printf("0");
			usleep(((teeth*(rpm/60)*2))/1000000);
		}
		printf("\n");
	}

	return 0;
}
