//
//  main.c
//  infestPath
//
//  Created by Juyeop Kim on 2022/10/20.
//

#include <stdio.h>
#include <string.h>
#include "ifct_element.h"
#include "ifct_database.h"

#define MENU_PATIENT        1
#define MENU_PLACE          2
#define MENU_AGE            3
#define MENU_TRACK          4
#define MENU_EXIT           0

#define TIME_HIDE           2


int trackInfester(int patient_no, int *detected_time, int *place); // 감염자 추적하는 함수  
int main(int argc, const char * argv[]) { 
    
    int i;
    int menu_selection;
    void *ifct_element;
    FILE* fp;
    int pIndex, age, time;
    int placeHist[N_HISTORY]; // 과거 장소 배열  
     
    //------------- 1. loading patient info file ------------------------------
    //1-1. FILE pointer open
    if (argc != 2) // 메인함수에 전달된 정보가 2개가 아니면  
    {
        printf("[ERROR] syntax : infestPath (file path)."); // 에러! 
        return -1;
    }
    
    fp = fopen(argv[1],"r"); //파일 오픈  
    if (fp == NULL) // 파일이 오픈되지 않음  
    {
        printf("[ERROR] Failed to open database file!! (%s)\n", argv[1]);
        return -1; // 에러  
    }
    
    //1-2. loading each patient informations 환자의 정보를 로딩함  
    while(3==fscanf(fp, "%d %d %d", &pIndex, &age, &time)) 
    {
    	for(i=3; i<8; i++)
    	   fscanf(fp[i],"%d", &placeHist[i]);
    	   
    	ifct_element = ifctele_genElement(index, age, time, placeHist[i]);
		
		ifctdb_addTail(ifct_element);   
	}
    
    //1-3. FILE pointer close
    fclose(fp);
    
     {
    	int place1, place2;
    	
		place1 = 3;
    	place2 = 15;
    	
    	printf("The first place is %s\n", ifctele_getPlaceName(place1)) ;
    	printf("The second place is %s\n", ifctele_getPlaceName(place2)) ;
	}
    
    do {
        printf("\n=============== INFECTION PATH MANAGEMENT PROGRAM (No. of patients : %i) =============\n", ifctdb_len());
        printf("1. Print details about a patient.\n");                      //MENU_PATIENT
        printf("2. Print list of patients infected at a place.\n");        //MENU_PLACE
        printf("3. Print list of patients in a range of age.\n");          //MENU_AGE
        printf("4. Track the root of the infection\n");                     //MENU_TRACK
        printf("0. Exit.\n");                                               //MENU_EXIT
        printf("=============== ------------------------------------------------------- =============\n\n");
        
        printf("Select a menu :");
        scanf("%d", &menu_selection);
        fflush(stdin);
        
        switch(menu_selection)
        {
            case MENU_EXIT:
                printf("Exiting the program... Bye bye.\n");
                break;
                
            case MENU_PATIENT:
                ifctele_printElement(void* obj);
                break;
                ifctele_printElement(void* obj);
            case MENU_PLACE:
                ifctele_printElement(void* obj);
                break;
                
            case MENU_AGE:
                ifctele_printElement(void* obj);
                break;
                
            case MENU_TRACK:
            	ifctele_printElement(void* obj);
                    
                break;
                
            default:
                printf("[ERROR Wrong menu selection! (%i), please choose between 0 ~ 4\n", menu_selection);
                break;
        }
    
    } while(menu_selection != 0);
    
    
    return 0;
}
