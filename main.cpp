#include <iostream>
#include "my_functions.h"
using namespace std;

int main() {
	
	int sTS, sR2D, sSA, sSB, sEBS, sASSI, sASMS, sBRAKES, sMISSION, SPEED, SIGNAL, TIME, sTIME, sRES, sSOUND;//FUNCTION'S STATUS
	char mission;
	
	
	while(1){
	//AS OFF
	TS(sTS=0);//OFF
	RSD(sR2D=0);//OFF
	SA(sSA=0);//UNAVAILABLE
	SB(sSB=0);//UNAVAILABLE
	ASSI(sASSI=0);//OFF
	
	switch (mission){
		
		case 'manual':
					EBS(sEBS=0);//UNAVAILABLE
					ASMS(sASMS=0);//OFF
					TS(sTS=1);//ACTIVATED
					
					//MANUAL DRIVING
					R2D(sR2D=1);//ON
					
					while(sTS=1){
						//R2D(sR2D=1);//ON
					}
			break;
		
		case 'autonomous':
					EBS(sEBS=1);//ARMED
					ASMS(sASMS=1);//ON
					TS(sTS=1);//ON
					
					//AS READY
					SA(sSA=1);//AVAILABLE
					SB(sSB=2);//ENGAGED
					ASSI(sASSI=1);//YELLOW COUNT
					t=TIME(sTIME=1);//START COUNTING(ms)
					while(1){
						if(sASMS=0 && sBRAKES=0){break;
						}
						if(t>5000 && SIGNAL==1/*GO SIGNAL*/){
							//AS DRIVING
							R2D(sR2D=1);
							SB(sSB=1);
							ASSI(sASSI=2);//YELLOW FLASH
							
							while(1){
								if(sMISSION==0 && SPEED==0){
									//AS FINISHED
									TS(sTS=0);
									R2D(sR2D=0);
									SA(sSA=0);
									EBS(sEBS=2);
									ASSI(sASSI=3);//BLUE CONT
									
									while(1){
										if(sRES=1){
											//AS EMERGENCY
											ASSI(sASSI=4);//BLUE FLASH
											SOUND(sSOUNF=1);//INTERMITTENT SOUND 8-10sec	
											
											while(1){
												if(sASMS==0 && sBRAKES==0 &&){break;
												}
											}
										}
										if(sASMS==0 && sBRAKES==0){break;
										}
									}
								}
								if(sEBS=2/*ACTIVATED*/){
									//AS EMERGENCY
									TS(sTS=0);
									R2D(sR2D=0);
									ASSI(sASSI=4);
									SOUND(sSOUNF=1);	
									
									while(1){
										if(sASMS==0 && sBRAKES==0 && sSOUND==0){break;
										}
									}
								}
							}
						}
						if(sEBS=2/*ACTIVATED*/){
							//AS EMERGENCY
							TS(sTS=0);
							ASSI(sASSI=4);
							SOUND(sSOUNF=1);	
							
							while(1){
								if(sASMS==0 && sBRAKES==0 && sSOUND==0){break;
								}
							}
						}
					}
			break;
	}
	return 0;
	}
}
