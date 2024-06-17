#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
using  namespace std;


void showBattleShip(char * ptrGameElement,char * ptrGameElementTwo,int * ptrRowElement,char * ptrColumnElement,int gameElementColumnCount,
                            int gameElementTwoColumnCount){
    cout<<"  ";
    for(int i=0;i<9;i++){
        cout<<" "<<(*ptrRowElement)++<<" ";
    }
    cout<<"                                                                                          ";
    *ptrRowElement=1;
    for(int i=0;i<9;i++){
        cout<<" "<<(*ptrRowElement)++<<" ";
    }
    cout<<endl;
     for(int i=0;i<9;i++){
         cout<<(*ptrColumnElement)++<<"|";
         for(int j=0;j<9;j++){
             cout<<" "<<*(ptrGameElement+(i*gameElementColumnCount+j))<<" ";
         }
         cout<<"                                                                                        ";
         (*ptrColumnElement)--;
         cout<<(*ptrColumnElement)++<<"|";
        for(int j=0;j<9;j++){
             cout<<" "<<*(ptrGameElementTwo+(i*gameElementTwoColumnCount+j))<<" ";
         }
         
         cout<<endl;
      
    }
    *ptrRowElement=1;
    * ptrColumnElement='a';
    
}
void writeBattleShip(char * ptrGameElement,char gameElement[9][9],int * ptrCurrentGameElementLongg,int gameElementColumnCount){
    int f=0;
    while(f<4){
        int length2=rand() % 2;
        int * ptrCurrentGameElementPosition=&length2;
   
        int length3=rand() % 9 ;
        int *ptrCurrentGameElementStartPointRow=&length3;
    
        int length4=rand() % 9 ;
        int  *ptrCurrentGameElementStartPointColumn=&length4;
    
    
//
//        cout<<ptrCurrentGameElementLongg[f]<<"   "<<*ptrCurrentGameElementPosition<<"   "<<*ptrCurrentGameElementStartPointRow<<"   "<<*ptrCurrentGameElementStartPointColumn<<endl;
        if(*ptrCurrentGameElementPosition==0){
           
            int j=1;
            int k=0;
            int m=1;
            for(int i=1;i<ptrCurrentGameElementLongg[f];i++){
                if(*ptrCurrentGameElementStartPointColumn+i<=8){
                     
                    if(*(ptrGameElement+((*ptrCurrentGameElementStartPointRow)*gameElementColumnCount+(*ptrCurrentGameElementStartPointColumn+i)))!='X' && *(ptrGameElement+((*ptrCurrentGameElementStartPointRow)*gameElementColumnCount+(*ptrCurrentGameElementStartPointColumn)))!='X'){
                        k++;
                    }
                
                  }
                 else{
                
                     if(*(ptrGameElement+((*ptrCurrentGameElementStartPointRow)*gameElementColumnCount+(*ptrCurrentGameElementStartPointColumn-m)))!='X' && *(ptrGameElement+((*ptrCurrentGameElementStartPointRow)*gameElementColumnCount+(*ptrCurrentGameElementStartPointColumn)))!='X'){
                         k++;
                         m++;
                     }
                
                         
                }
              
                
              
            }
            for(int i=1;i<ptrCurrentGameElementLongg[f];i++){
                if(ptrCurrentGameElementLongg[f]==k+1){
                    *(ptrGameElement+((*ptrCurrentGameElementStartPointRow)*gameElementColumnCount+(*ptrCurrentGameElementStartPointColumn)))='X';
                    if(*ptrCurrentGameElementStartPointColumn+i<=8){
                        *(ptrGameElement+((*ptrCurrentGameElementStartPointRow)*gameElementColumnCount+(*ptrCurrentGameElementStartPointColumn+i)))='X';
                        
                    }
                    else{
                        *(ptrGameElement+((*ptrCurrentGameElementStartPointRow)*gameElementColumnCount+(*ptrCurrentGameElementStartPointColumn-j)))='X';
                        j++;
                    }
                    
                }
                else{
                    goto restart;

                }
               
                
            }
           
            
     
//            cout<<k<<endl;
            if(ptrCurrentGameElementLongg[f]==k+1){
                f++;
            }
            
            
        }
        else{
           
            int j=0;
            int k=0;
            int m=1;
            for(int i=1;i<ptrCurrentGameElementLongg[f];i++){
                if(*ptrCurrentGameElementStartPointRow+i<=8){
                     
                    if(*(ptrGameElement+((*ptrCurrentGameElementStartPointRow+i)*gameElementColumnCount+(*ptrCurrentGameElementStartPointColumn)))!='X' && *(ptrGameElement+((*ptrCurrentGameElementStartPointRow)*gameElementColumnCount+(*ptrCurrentGameElementStartPointColumn)))!='X'){
                        k++;
                    }
                
                  }
                 else{
                
                     if(*(ptrGameElement+((*ptrCurrentGameElementStartPointRow-m)*gameElementColumnCount+(*ptrCurrentGameElementStartPointColumn)))!='X' && *(ptrGameElement+((*ptrCurrentGameElementStartPointRow)*gameElementColumnCount+(*ptrCurrentGameElementStartPointColumn)))!='X'){
                         k++;
                         m++;
                     }
                         
                }
          
              
            }
            for(int i=1;i<ptrCurrentGameElementLongg[f];i++){
                if(ptrCurrentGameElementLongg[f]==k+1){
                    *(ptrGameElement+((*ptrCurrentGameElementStartPointRow)*gameElementColumnCount+(*ptrCurrentGameElementStartPointColumn)))='X';
                    if(*ptrCurrentGameElementStartPointRow+i<=8){
                        *(ptrGameElement+((*ptrCurrentGameElementStartPointRow+i)*gameElementColumnCount+(*ptrCurrentGameElementStartPointColumn)))='X';
                        
                    }
                    else{
                        j++;
                        *(ptrGameElement+((*ptrCurrentGameElementStartPointRow-j)*gameElementColumnCount+(*ptrCurrentGameElementStartPointColumn)))='X';
                       
                    }
                    
                }
                else{
                    goto restart;
                  
               }
               
                
            }
           
//            cout<<k<<endl;
            if(ptrCurrentGameElementLongg[f]==k+1){

                f++;
            }
            
            
        }
       
        restart:
            continue;
        
        
    }
    
}

int main(int argc, const char * argv[]) {
    srand(static_cast<unsigned int>(time(0)));
    char columnElement='a';
    char * ptrColumnElement=&columnElement;
    int rowElement=1;
    int * ptrRowElement=&rowElement;
    string coordinate;
    char showGameElement[9][9]={
        {'*','*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*','*'}
    };
    char gameElement[9][9]={
        {'*','*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*','*'}
    };
    char showGameElementTwo[9][9]={
        {'*','*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*','*'}
    };
    char gameElementTwo[9][9]={
        {'*','*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*','*'},
        {'*','*','*','*','*','*','*','*','*'}
    };
//    int gameElementRowCount=sizeof(gameElement)/sizeof(gameElement[0]);
    int gameElementColumnCount=sizeof(gameElement[0]);
    int  gameElementTwoColumnCount=sizeof(gameElementTwo[0]);
    char * ptrGameElement=gameElement[0];
    char * ptrGameElementTwo=gameElementTwo[0];
    char * ptrShowGameElement=showGameElement[0];
    char * ptrShowGameElementTwo=showGameElementTwo[0];
    
    showBattleShip(ptrGameElement, ptrGameElementTwo,ptrRowElement, ptrColumnElement,gameElementColumnCount,gameElementTwoColumnCount);
 


    cout<<endl;
 
    
    int currentGameElementLongg[4];
    int * ptrCurrentGameElementLongg=currentGameElementLongg;
    int sumCurrentGameElementLongg=0;
    int *ptrSumCurrentGameElementLongg=&sumCurrentGameElementLongg;

    for(int i=0;i<4;i++){
        int length=rand() % 4 + 2;
        ptrCurrentGameElementLongg[i]=length;
        
    }
    for(int i=0;i<4;i++){
        sumCurrentGameElementLongg+=ptrCurrentGameElementLongg[i];
    }
 
 

  
   
    writeBattleShip(ptrGameElement,gameElement,ptrCurrentGameElementLongg,gameElementColumnCount);
    writeBattleShip(ptrGameElementTwo,gameElementTwo,ptrCurrentGameElementLongg,gameElementTwoColumnCount);
    showBattleShip(ptrGameElement, ptrGameElementTwo,ptrRowElement, ptrColumnElement,gameElementColumnCount,gameElementTwoColumnCount);
    cout<<endl;
    cout<<"koordinat nece daxil olunmalidir: a1,b2 ve s.";
    cout<<endl;
    bool answer=true;
    int h=0;
    int checkSum=0;
     while(checkSum<sumCurrentGameElementLongg){
         string coordinat;
         cout<<"enter coordinat: ";
         cin>>coordinat;
         char coordinateRow=coordinat[0];
         char * ptrCoordinateRow=&coordinateRow;
         int coordinateColumn=coordinat[1]-'0';
         int * ptrCoordinateColumn=&coordinateColumn;
         if((*ptrCoordinateRow)-(*ptrColumnElement)>8 || (*ptrCoordinateColumn)-(*ptrRowElement)>8 || coordinat.length()>2){
             cout<<endl;
             cout<<"daxil etdiyiniz koordinatlar movcud deyil"<<endl;
             cout<<endl;
             continue;
         }
//         cout<<gameElement[(*ptrCoordinateRow)-(*ptrColumnElement)][(*ptrCoordinateColumn)-(*ptrRowElement)]<<endl;
         if(gameElement[(*ptrCoordinateRow)-(*ptrColumnElement)][(*ptrCoordinateColumn)-(*ptrRowElement)]=='X'){
             showGameElement[(*ptrCoordinateRow)-(*ptrColumnElement)][(*ptrCoordinateColumn)-(*ptrRowElement)]='X';
             checkSum++;
//             cout<<checkSum<<endl;
         }
         else{
             showGameElement[(*ptrCoordinateRow)-(*ptrColumnElement)][(*ptrCoordinateColumn)-(*ptrRowElement)]='O';
         }
         bool enemyCoordinatCheck=true;
         while(enemyCoordinatCheck){
             int enemyCoordinatRow=rand() % 9 ;
             int enemyCoordinatColumn=rand() % 9;
             if(showGameElementTwo[enemyCoordinatRow][enemyCoordinatColumn]=='X' ||showGameElementTwo[enemyCoordinatRow][enemyCoordinatColumn]=='O' ){
                 continue;
             }
         
             else{
                 if(gameElementTwo[enemyCoordinatRow][enemyCoordinatColumn]=='X'){
                     showGameElementTwo[enemyCoordinatRow][enemyCoordinatColumn]='X';
                 }
                 else{
                     showGameElementTwo[enemyCoordinatRow][enemyCoordinatColumn]='O';
                 }
                 enemyCoordinatCheck=false;
             }
             
            
         }
         
         
         
         showBattleShip(ptrShowGameElement, ptrShowGameElementTwo,ptrRowElement, ptrColumnElement,gameElementColumnCount,gameElementTwoColumnCount);
         
         if(checkSum==sumCurrentGameElementLongg){
             cout<<endl;
             cout<<endl;
             cout<<endl;
             
             cout<<"oyunu qazandiniz...";
             cout<<endl;
             cout<<endl;
             cout<<endl;
         }
         
         
         
         
         h++;
     }
    
    cout<<endl;
    


    
  

    
    return 0;
}
