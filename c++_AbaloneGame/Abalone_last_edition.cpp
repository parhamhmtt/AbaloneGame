#include <iostream>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <fstream>
#include <string>
using namespace std;
int winner=0;
string player_1;
string player_2;
int scoreX,scoreO;
int temp[114];
 bool exited = false; 
const int rows = 9;
int* columns = new int[rows] {  5, 6, 7, 8, 9, 8, 7, 6, 5 };
char** hexgrid = new char* [rows];
void init() {
    for (int i = 0; i < rows; i++) {
        hexgrid[i] = new char[2 * columns[i] - 1];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < (2 * columns[i] - 1); j++) {

            if (j % 2 == 0) {
                if(i<=2){
                    if(i<2)
                hexgrid[i][j] = 'x';
                     else{
                        if( j>=4 && j<=8)
                        hexgrid[i][j] = 'x';
                        else
                         hexgrid[i][j] = '#';
                     }
                }
                 else if (i>=6){
                    if(i>6)
                hexgrid[i][j] = 'o';
                     else{
                        if( j>=4 && j<=8)
                        hexgrid[i][j] = 'o';
                        else
                         hexgrid[i][j] = '#';
                     }
                }
                
                else{
                hexgrid[i][j] = '#';
                }
            }
            else {
                hexgrid[i][j] = ' ';
            }
        }
    
    }
    
   
   
    
}

void reset() {
    for (int i = 0; i < rows; i++) {
        hexgrid[i] = new char[2 * columns[i] - 1];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < (2 * columns[i] - 1); j++) {

            if (j % 2 == 0) {
                if(i<=2){
                    if(i<2)
                hexgrid[i][j] = 'x';
                     else{
                        if( j>=4 && j<=8)
                        hexgrid[i][j] = 'x';
                        else
                         hexgrid[i][j] = '#';
                     }
                }
                 else if (i>=6){
                    if(i>6)
                hexgrid[i][j] = 'o';
                     else{
                        if( j>=4 && j<=8)
                        hexgrid[i][j] = 'o';
                        else
                         hexgrid[i][j] = '#';
                     }
                }
                
                else{
                hexgrid[i][j] = '#';
                }
            }
            else {
                hexgrid[i][j] = ' ';
            }
        }
    
    }
    
    
}

struct coord {
    int row;
    int column;
};

string spaces(int num) {
    string ans = "";
    for (int i = 0; i < num; i++) {
        ans += " ";
    }
    return ans;
}

string playerTurn(int playerIndex){
    if (playerIndex%2==1)
            return player_2;
    else
            return player_1;
}

bool checkThecoord(coord source, int playerIndex){
     bool flag=true;
    if(playerIndex%2==0){
    if(hexgrid[source.row][source.column]=='#' ||  hexgrid[source.row][source.column]=='o'){
        flag=false;
        }
     }
     if(playerIndex%2==1){
    if(hexgrid[source.row][source.column]=='#' ||  hexgrid[source.row][source.column]=='x'){
        flag=false;
        }
     }
     return flag;
        
}

//////////////////////////////////////////////////////////////////////////////////////////////// 

coord nextuprightmaker(coord source){
    coord ans = { -1,-1 };
    if (source.row==0) 
            return ans;

     if(source.row<=rows/2 && source.column>=2*columns[source.row]-2)
            return ans;

     if(source.row>4){
        ans={source.row-1,source.column+2};
         return ans;
    }
    if(source.row<=4){
        ans={source.row-1,source.column};
         return ans;
    }
    return ans;
}


coord nextupleftmaker(coord source){
    coord ans = { -1,-1 };
    if (source.row<=0) 
            return ans;

     if(source.row<=rows/2 && source.column<=0)
            return ans;
     
     if(source.row>4){
        ans={source.row-1,source.column};
         return ans;
    }
    if(source.row<=4){
        ans={source.row-1,source.column-2};
         return ans;
    }
    return ans;
}


coord nextdownleftmaker(coord source){
    coord ans = { -1,-1 };
   if (source.row + 1 >= rows)
        return ans;
    if(source.row>=rows/2 && source.column<=0){
        return ans;
    }
     
     if(source.row>=4){
        ans={source.row+1,source.column-2};
         return ans;
    }
    if(source.row<4){
        ans={source.row+1,source.column};
         return ans;
    }
    return ans;
}


coord nextdownrightmaker(coord source){
    coord ans = { -1,-1 };
   if (source.row + 1 >= rows)
        return ans;
    if(source.row>=rows/2 && source.column>=2*columns[source.row]-2){
        return ans;
    }
     
     if(source.row<4){
        ans={source.row+1,source.column+2};
         return ans;
    }
    if(source.row>=4){
        ans={source.row+1,source.column};
         return ans;
    }
    return ans;
}

coord nextrightmaker(coord source) {
    coord ans = { -1,-1 };
    if (source.column>=2*columns[source.row]-2) {
        return ans;
    }
    else{
     ans={source.row,source.column+2};
         return ans;
    }

        
}


coord nextleftmaker(coord source) {
    coord ans = { -1,-1 };
    if (source.column<=0) {
        return ans;
    }
     ans={source.row,source.column-2};
         return ans;
}


//////////////////////////////////////////////////////////////////////////////////////////////// 

coord getright(coord source) {
    coord ans = { -1,-1 };
    if (source.column==2*columns[source.row]-2) {
        return ans;
    }
    swap(hexgrid[source.row][source.column],hexgrid[source.row][source.column+2]);
    ans = {1,1};
    return ans;
}

coord getleft(coord source) {
    coord ans = { -1,-1 };
    if (source.column==0) {
        return ans;
    }
    swap(hexgrid[source.row][source.column],hexgrid[source.row][source.column-2]);
    ans = {1,1};
    return ans;
} 

coord getupleft(coord source) {
    coord ans = { -1,-1 };
    if (source.row==0) 
            return ans;

     if(source.row<=rows/2 && source.column==0)
            return ans;
     
      if(source.row>4){
        swap(hexgrid[source.row][source.column],hexgrid[source.row-1][source.column]);
        ans={1,1};
         return ans;
    }
    if(source.row<=4){
        swap(hexgrid[source.row][source.column],hexgrid[source.row-1][source.column-2]);
        ans={1,1};
         return ans;
    }
    return ans;
}
coord getupright(coord source) {
    coord ans = { -1,-1 };
    if (source.row==0) 
            return ans;

     if(source.row<=rows/2 && source.column==2*columns[source.row]-2)
            return ans;
     
      if(source.row>4){
        swap(hexgrid[source.row][source.column],hexgrid[source.row-1][source.column+2]);
        ans={1,1};
         return ans;
    }
    if(source.row<=4){
        swap(hexgrid[source.row][source.column],hexgrid[source.row-1][source.column]);
        ans={1,1};
         return ans;
    }
    return ans;
    
}

coord getdownleft(coord source) {
    coord ans = { -1,-1 };
    if (source.row + 1 == rows)
        return ans;
    if(source.row>=rows/2 && source.column==0){
        return ans;
    }
    if(source.row>=4){
        swap(hexgrid[source.row][source.column],hexgrid[source.row+1][source.column-2]);
        ans={1,1};
         return ans;
    }
    if(source.row<4){
        swap(hexgrid[source.row][source.column],hexgrid[source.row+1][source.column]);
        ans={1,1};
         return ans;
    }
    return ans;
}

coord getdownright(coord source) {
    coord ans = { -1,-1 };
    if (source.row + 1 == rows)
        return ans;
    if(source.row>=rows/2 && source.column==2*columns[source.row]-2){
        return ans;
    }
    if(source.row<4){
         swap(hexgrid[source.row][source.column],hexgrid[source.row+1][source.column+2]);
         ans={1,1};
         return ans;
    }

    if(source.row>=4){
        swap(hexgrid[source.row][source.column],hexgrid[source.row+1][source.column]);
        ans={1,1};
        return ans;
    }
    return ans;
}


//////////////////////////////////////////////////////////////////////////////////////////////// 

coord checknextright(coord source, int pieceCount){
    coord ans={ -1,-1 };
    if(pieceCount==1){
        if(hexgrid[source.row][source.column]=='x'){
            if(hexgrid[source.row][source.column+2]!='#'){
                return ans;
            }
        }
        if(hexgrid[source.row][source.column]=='o'){
            if(hexgrid[source.row][source.column+2]!='#'){
                return ans;
            }
        }
        ans={ 1,1 };
        return ans;
    }



    if(pieceCount==2){
        
        coord first,second;
       
        coord ans={ -1,-1 };
        first=nextrightmaker(source);
        
        if(first.row==-1 && first.column==-1)
                return ans;
        else if(hexgrid[source.row][source.column]==hexgrid[first.row][first.column])
                return ans;
        
        else if(hexgrid[first.row][first.column]=='#'){
            ans={1,1};
            return ans;
        }
        second=nextrightmaker(first);
        if(second.row==-1 && second.column==-1){
             hexgrid[first.row][first.column]='#';
             ans={ 1,1 };
            return ans;
            }
        if(hexgrid[source.row][source.column]=='x')
        if(hexgrid[first.row][first.column]=='o'){
            ////o#
            if(hexgrid[second.row][second.column]=='#'){
            swap(hexgrid[first.row][first.column],hexgrid[second.row][second.column]);
            ans={1,1};
            return ans;
            }
            ///oo
            if(hexgrid[second.row][second.column]=='o'){
            return ans;
            }
            ///ox
            if(hexgrid[second.row][second.column]=='x'){
            return ans;
            }
            ///o
            if(second.row==-1 && second.column==-1){
             hexgrid[first.row][first.column]='#';
             ans={ 1,1 };
            return ans;
            }
        }


        if(hexgrid[first.row][first.column]=='x'){
            ////x#
            if(hexgrid[second.row][second.column]=='#'){
            swap(hexgrid[first.row][first.column],hexgrid[second.row][second.column]);
            ans={1,1};
            return ans;
            }
            ///xx
            if(hexgrid[second.row][second.column]=='x'){
            return ans;
            }
            ///xo
            if(hexgrid[second.row][second.column]=='o'){
            return ans;
            }
            ///x
            if(second.row==-1 && second.column==-1){
             hexgrid[first.row][first.column]='#';
             ans={ 1,1 };
            return ans;
            }
        }
    }



    if(pieceCount==3){
        coord first,second,third;
         coord ans={ -1,-1 };

         first=nextrightmaker(source);
        
        if(first.row==-1 && first.column==-1)
                return ans;
        else if(hexgrid[source.row][source.column]==hexgrid[first.row][first.column])
                return ans;
        
        else if(hexgrid[first.row][first.column]=='#'){
            ans={1,1};
            return ans;
        }
        second=nextrightmaker(first);
        if(second.row==-1 && second.column==-1){
             hexgrid[first.row][first.column]='#';
             ans={ 1,1 };
            return ans;
            }

        if(hexgrid[source.row][source.column]=='x'){
            if(hexgrid[first.row][first.column]=='o'){
                if(hexgrid[second.row][second.column]=='x')
                        return ans;
                if(hexgrid[second.row][second.column]=='#'){
                    swap(hexgrid[first.row][first.column],hexgrid[second.row][second.column]);
                    ans={1,1};
                    return ans;
                }    
                 if(second.row==-1 && second.column==-1){
                    hexgrid[first.row][first.column]='#';
                      ans={ 1,1 };
                    return ans;
                }
                third=nextrightmaker(second);
                if(third.row==-1 && third.column==-1){
                  hexgrid[second.row][second.column]='#';
                  swap(hexgrid[second.row][second.column],hexgrid[first.row][first.column]);
                      ans={ 1,1 };
                         return ans;
                  }
                if(hexgrid[second.row][second.column]=='o'){
                    if(hexgrid[third.row][third.column]=='o' || hexgrid[third.row][third.column]=='x')
                        {return ans;}

                        if(hexgrid[third.row][third.column]=='#'){
                            swap(hexgrid[second.row][second.column],hexgrid[third.row][third.column]);
                            swap(hexgrid[second.row][second.column],hexgrid[first.row][first.column]);
                            ans={ 1,1 };
                            return ans;
                        }
                }

            }
        }

                if(hexgrid[source.row][source.column]=='o'){
            if(hexgrid[first.row][first.column]=='x'){
                if(hexgrid[second.row][second.column]=='o')
                        return ans;
                if(hexgrid[second.row][second.column]=='#'){
                    swap(hexgrid[first.row][first.column],hexgrid[second.row][second.column]);
                    ans={1,1};
                    return ans;
                }    
                 if(second.row==-1 && second.column==-1){
                    hexgrid[first.row][first.column]='#';
                      ans={ 1,1 };
                    return ans;
                }
                third=nextrightmaker(second);
                if(third.row==-1 && third.column==-1){
                  hexgrid[second.row][second.column]='#';
                  swap(hexgrid[second.row][second.column],hexgrid[first.row][first.column]);
                      ans={ 1,1 };
                         return ans;
                  }
                if(hexgrid[second.row][second.column]=='x'){
                    if(hexgrid[third.row][third.column]=='o' || hexgrid[third.row][third.column]=='x')
                        {return ans;}

                        if(hexgrid[third.row][third.column]=='#'){
                            swap(hexgrid[second.row][second.column],hexgrid[third.row][third.column]);
                            swap(hexgrid[second.row][second.column],hexgrid[first.row][first.column]);
                            ans={ 1,1 };
                            return ans;
                        }
                }

            }
        }
        
    }
return ans;
 }
 coord checknextleft(coord source, int pieceCount){
    coord ans={ -1,-1 };
    if(pieceCount==1){
        if(hexgrid[source.row][source.column]=='x'){
            if(hexgrid[source.row][source.column-2]!='#'){
                return ans;
            }
        }
        if(hexgrid[source.row][source.column]=='o'){
            if(hexgrid[source.row][source.column-2]!='#'){
                return ans;
            }
        }
        ans={ 1,1 };
        return ans;
    }


    if(pieceCount==2){
        coord first,second;
        coord ans={ -1,-1 };
        first=nextleftmaker(source);
        if(first.row==-1 && first.column==-1){
                return ans;
        }
        if(hexgrid[source.row][source.column]==hexgrid[first.row][first.column])
                return ans;
        
        if(hexgrid[first.row][first.column]=='#'){
            ans={1,1};
            return ans;
        }
        second=nextleftmaker(first);
        if(second.row==-1 && second.column==-1){
             hexgrid[first.row][first.column]='#';
             ans={ 1,1 };
            return ans;
            }

        if(hexgrid[first.row][first.column]=='o'){
            ////o#
            if(hexgrid[second.row][second.column]=='#'){
            swap(hexgrid[first.row][first.column],hexgrid[second.row][second.column]);
            ans={1,1};
            return ans;
            }
            ///oo
            if(hexgrid[second.row][second.column]=='o'){
            return ans;
            }
            ///ox
            if(hexgrid[second.row][second.column]=='x'){
            return ans;
            }
            ///o
            if(second.row==-1 && second.column==-1){
             hexgrid[first.row][first.column]='#';
             ans={ 1,1 };
            return ans;
            }
        }


        if(hexgrid[first.row][first.column]=='x'){
            ////x#
            if(hexgrid[second.row][second.column]=='#'){
            swap(hexgrid[first.row][first.column],hexgrid[second.row][second.column]);
            ans={1,1};
            return ans;
            }
            ///xx
            if(hexgrid[second.row][second.column]=='x'){
            return ans;
            }
            ///xo
            if(hexgrid[second.row][second.column]=='o'){
            return ans;
            }
            ///x
            if(second.row==-1 && second.column==-1){
             hexgrid[first.row][first.column]='#';
             ans={ 1,1 };
            return ans;
            }
        }
    }




    if(pieceCount==3){
        coord first,second,third;
         coord ans={ -1,-1 };

         first=nextleftmaker(source);
        
        if(first.row==-1 && first.column==-1)
                return ans;
        else if(hexgrid[source.row][source.column]==hexgrid[first.row][first.column])
                return ans;
        
        else if(hexgrid[first.row][first.column]=='#'){
            ans={1,1};
            return ans;
        }
        second=nextleftmaker(first);
        if(second.row==-1 && second.column==-1){
             hexgrid[first.row][first.column]='#';
             ans={ 1,1 };
            return ans;
            }

        if(hexgrid[source.row][source.column]=='x'){
            if(hexgrid[first.row][first.column]=='o'){
                if(hexgrid[second.row][second.column]=='x')
                        return ans;
                if(hexgrid[second.row][second.column]=='#'){
                    swap(hexgrid[first.row][first.column],hexgrid[second.row][second.column]);
                    ans={1,1};
                    return ans;
                }    
                 if(second.row==-1 && second.column==-1){
                    hexgrid[first.row][first.column]='#';
                      ans={ 1,1 };
                    return ans;
                }
                third=nextleftmaker(second);
                if(third.row==-1 && third.column==-1){
                  hexgrid[second.row][second.column]='#';
                  swap(hexgrid[second.row][second.column],hexgrid[first.row][first.column]);
                      ans={ 1,1 };
                         return ans;
                  }
                if(hexgrid[second.row][second.column]=='o'){
                    if(hexgrid[third.row][third.column]=='o' || hexgrid[third.row][third.column]=='x')
                        {return ans;}

                        if(hexgrid[third.row][third.column]=='#'){
                            swap(hexgrid[second.row][second.column],hexgrid[third.row][third.column]);
                            swap(hexgrid[second.row][second.column],hexgrid[first.row][first.column]);
                            ans={ 1,1 };
                            return ans;
                        }
                }

            }
        }
        
                if(hexgrid[source.row][source.column]=='o'){
            if(hexgrid[first.row][first.column]=='x'){
                if(hexgrid[second.row][second.column]=='o')
                        return ans;
                if(hexgrid[second.row][second.column]=='#'){
                    swap(hexgrid[first.row][first.column],hexgrid[second.row][second.column]);
                    ans={1,1};
                    return ans;
                }    
                 if(second.row==-1 && second.column==-1){
                    hexgrid[first.row][first.column]='#';
                      ans={ 1,1 };
                    return ans;
                }
                third=nextleftmaker(second);
                if(third.row==-1 && third.column==-1){
                  hexgrid[second.row][second.column]='#';
                  swap(hexgrid[second.row][second.column],hexgrid[first.row][first.column]);
                      ans={ 1,1 };
                         return ans;
                  }
                if(hexgrid[second.row][second.column]=='x'){
                    if(hexgrid[third.row][third.column]=='o' || hexgrid[third.row][third.column]=='x')
                        {return ans;}

                        if(hexgrid[third.row][third.column]=='#'){
                            swap(hexgrid[second.row][second.column],hexgrid[third.row][third.column]);
                            swap(hexgrid[second.row][second.column],hexgrid[first.row][first.column]);
                            ans={ 1,1 };
                            return ans;
                        }
                }

            }
        }

        
    }
return ans;
 } 


 coord checknextupleft(coord source, int pieceCount){
    coord ans={ -1,-1 };
    if(pieceCount==1){
        if(source.row>4){
        if((hexgrid[source.row][source.column]=='x' && hexgrid[source.row-1][source.column]!='#')
        ||
        (hexgrid[source.row][source.column]=='o' && hexgrid[source.row-1][source.column]!='#'))
         return ans;
    }
    if(source.row<=4){
        if((hexgrid[source.row][source.column]=='x' && hexgrid[source.row-1][source.column-2]!='#')
        ||
        (hexgrid[source.row][source.column]=='o' && hexgrid[source.row-1][source.column-2]!='#'))
         return ans;
    }
        ans={ 1,1 };
        return ans;
    }
    if(pieceCount==2){
        coord first,second;
        coord ans={ -1,-1 };
        first=nextupleftmaker(source);
        if(first.row==-1 && first.column==-1)
                return ans;
        if(hexgrid[source.row][source.column]==hexgrid[first.row][first.column])
                return ans;
        
        if(hexgrid[first.row][first.column]=='#'){
            ans={1,1};
            return ans;
        }
        second=nextleftmaker(first);
        if(second.row==-1 && second.column==-1){
             hexgrid[first.row][first.column]='#';
             ans={ 1,1 };
            return ans;
            }
         
        if(hexgrid[first.row][first.column]=='o'){
            ////o#
            if(hexgrid[second.row][second.column]=='#'){
            swap(hexgrid[first.row][first.column],hexgrid[second.row][second.column]);
            ans={1,1};
            return ans;
            }
            ///oo
            if(hexgrid[second.row][second.column]=='o'){
            return ans;
            }
            ///ox
            if(hexgrid[second.row][second.column]=='x'){
            return ans;
            }
            ///o
            if(second.row==-1 && second.column==-1){
             hexgrid[first.row][first.column]='#';
             ans={ 1,1 };
            return ans;
            }
        }


        if(hexgrid[first.row][first.column]=='x'){
            ////x#
            if(hexgrid[second.row][second.column]=='#'){
            swap(hexgrid[first.row][first.column],hexgrid[second.row][second.column]);
            ans={1,1};
            return ans;
            }
            ///xx
            if(hexgrid[second.row][second.column]=='x'){
            return ans;
            }
            ///xo
            if(hexgrid[second.row][second.column]=='o'){
            return ans;
            }
            ///x
            if(second.row==-1 && second.column==-1){
             hexgrid[first.row][first.column]='#';
             ans={ 1,1 };
            return ans;
            }
        }
    }



    if(pieceCount==3){
        coord first,second,third;
         coord ans={ -1,-1 };

         first=nextupleftmaker(source);
        
        if(first.row==-1 && first.column==-1)
                return ans;
        else if(hexgrid[source.row][source.column]==hexgrid[first.row][first.column])
                return ans;
        
        else if(hexgrid[first.row][first.column]=='#'){
            ans={1,1};
            return ans;
        }
        second=nextupleftmaker(first);
        if(second.row==-1 && second.column==-1){
             hexgrid[first.row][first.column]='#';
             ans={ 1,1 };
            return ans;
            }

        if(hexgrid[source.row][source.column]=='x'){
            if(hexgrid[first.row][first.column]=='o'){
                if(hexgrid[second.row][second.column]=='x')
                        return ans;
                if(hexgrid[second.row][second.column]=='#'){
                    swap(hexgrid[first.row][first.column],hexgrid[second.row][second.column]);
                    ans={1,1};
                    return ans;
                }    
                 if(second.row==-1 && second.column==-1){
                    hexgrid[first.row][first.column]='#';
                      ans={ 1,1 };
                    return ans;
                }
                third=nextupleftmaker(second);
                if(third.row==-1 && third.column==-1){
                  hexgrid[second.row][second.column]='#';
                  swap(hexgrid[second.row][second.column],hexgrid[first.row][first.column]);
                      ans={ 1,1 };
                         return ans;
                  }
                if(hexgrid[second.row][second.column]=='o'){
                    if(hexgrid[third.row][third.column]=='o' || hexgrid[third.row][third.column]=='x')
                        {return ans;}

                        if(hexgrid[third.row][third.column]=='#'){
                            swap(hexgrid[second.row][second.column],hexgrid[third.row][third.column]);
                            swap(hexgrid[second.row][second.column],hexgrid[first.row][first.column]);
                            ans={ 1,1 };
                            return ans;
                        }
                }

            }
        }

               if(hexgrid[source.row][source.column]=='o'){
            if(hexgrid[first.row][first.column]=='x'){
                if(hexgrid[second.row][second.column]=='o')
                        return ans;
                if(hexgrid[second.row][second.column]=='#'){
                    swap(hexgrid[first.row][first.column],hexgrid[second.row][second.column]);
                    ans={1,1};
                    return ans;
                }    
                 if(second.row==-1 && second.column==-1){
                    hexgrid[first.row][first.column]='#';
                      ans={ 1,1 };
                    return ans;
                }
                third=nextupleftmaker(second);
                if(third.row==-1 && third.column==-1){
                  hexgrid[second.row][second.column]='#';
                  swap(hexgrid[second.row][second.column],hexgrid[first.row][first.column]);
                      ans={ 1,1 };
                         return ans;
                  }
                if(hexgrid[second.row][second.column]=='x'){
                    if(hexgrid[third.row][third.column]=='o' || hexgrid[third.row][third.column]=='x')
                        {return ans;}

                        if(hexgrid[third.row][third.column]=='#'){
                            swap(hexgrid[second.row][second.column],hexgrid[third.row][third.column]);
                            swap(hexgrid[second.row][second.column],hexgrid[first.row][first.column]);
                            ans={ 1,1 };
                            return ans;
                        }
                }

            }
        }
        
    }
return ans;
 }
 coord checknextupright(coord source, int pieceCount){
       coord ans={ -1,-1 }; 
    if(pieceCount==1){
        if(source.row>4){
        if((hexgrid[source.row][source.column]=='x' && hexgrid[source.row-1][source.column+2]!='#')
        ||
        (hexgrid[source.row][source.column]=='o' && hexgrid[source.row-1][source.column+2]!='#'))
         return ans;
    }
    if(source.row<=4){
        if((hexgrid[source.row][source.column]=='x' && hexgrid[source.row-1][source.column]!='#')
        ||
        (hexgrid[source.row][source.column]=='o' && hexgrid[source.row-1][source.column]!='#'))
         return ans;
    }
        ans={ 1,1 };
        return ans;
    }
    if(pieceCount==2){
        coord first,second;
        coord ans={ -1,-1 };
        first=nextuprightmaker(source);
        if(first.row==-1 && first.column==-1)
                return ans;
        if(hexgrid[source.row][source.column]==hexgrid[first.row][first.column])
                return ans;
        
        if(hexgrid[first.row][first.column]=='#'){
            ans={1,1};
            return ans;
        }
        second=nextleftmaker(first);
        if(second.row==-1 && second.column==-1){
             hexgrid[first.row][first.column]='#';
             ans={ 1,1 };
            return ans;
            }

        if(hexgrid[first.row][first.column]=='o'){
            ////o#
            if(hexgrid[second.row][second.column]=='#'){
            swap(hexgrid[first.row][first.column],hexgrid[second.row][second.column]);
            ans={1,1};
            return ans;
            }
            ///oo
            if(hexgrid[second.row][second.column]=='o'){
            return ans;
            }
            ///ox
            if(hexgrid[second.row][second.column]=='x'){
            return ans;
            }
            ///o
            if(second.row==-1 && second.column==-1){
             hexgrid[first.row][first.column]='#';
             ans={ 1,1 };
            return ans;
            }
        }


        if(hexgrid[first.row][first.column]=='x'){
            ////x#
            if(hexgrid[second.row][second.column]=='#'){
            swap(hexgrid[first.row][first.column],hexgrid[second.row][second.column]);
            ans={1,1};
            return ans;
            }
            ///xx
            if(hexgrid[second.row][second.column]=='x'){
            return ans;
            }
            ///xo
            if(hexgrid[second.row][second.column]=='o'){
            return ans;
            }
            ///x
            if(second.row==-1 && second.column==-1){
             hexgrid[first.row][first.column]='#';
             ans={ 1,1 };
            return ans;
            }
        }
    }



    if(pieceCount==3){
        coord first,second,third;
         coord ans={ -1,-1 };

         first=nextuprightmaker(source);
        
        if(first.row==-1 && first.column==-1)
                return ans;
        else if(hexgrid[source.row][source.column]==hexgrid[first.row][first.column])
                return ans;
        
        else if(hexgrid[first.row][first.column]=='#'){
            ans={1,1};
            return ans;
        }
        second=nextuprightmaker(first);
        if(second.row==-1 && second.column==-1){
             hexgrid[first.row][first.column]='#';
             ans={ 1,1 };
            return ans;
            }

        if(hexgrid[source.row][source.column]=='x'){
            if(hexgrid[first.row][first.column]=='o'){
                if(hexgrid[second.row][second.column]=='x')
                        return ans;
                if(hexgrid[second.row][second.column]=='#'){
                    swap(hexgrid[first.row][first.column],hexgrid[second.row][second.column]);
                    ans={1,1};
                    return ans;
                }    
                 if(second.row==-1 && second.column==-1){
                    hexgrid[first.row][first.column]='#';
                      ans={ 1,1 };
                    return ans;
                }
                third=nextuprightmaker(second);
                if(third.row==-1 && third.column==-1){
                  hexgrid[second.row][second.column]='#';
                  swap(hexgrid[second.row][second.column],hexgrid[first.row][first.column]);
                      ans={ 1,1 };
                         return ans;
                  }
                if(hexgrid[second.row][second.column]=='o'){
                    if(hexgrid[third.row][third.column]=='o' || hexgrid[third.row][third.column]=='x')
                        {return ans;}

                        if(hexgrid[third.row][third.column]=='#'){
                            swap(hexgrid[second.row][second.column],hexgrid[third.row][third.column]);
                            swap(hexgrid[second.row][second.column],hexgrid[first.row][first.column]);
                            ans={ 1,1 };
                            return ans;
                        }
                }

            }
        }
                if(hexgrid[source.row][source.column]=='o'){
            if(hexgrid[first.row][first.column]=='x'){
                if(hexgrid[second.row][second.column]=='o')
                        return ans;
                if(hexgrid[second.row][second.column]=='#'){
                    swap(hexgrid[first.row][first.column],hexgrid[second.row][second.column]);
                    ans={1,1};
                    return ans;
                }    
                 if(second.row==-1 && second.column==-1){
                    hexgrid[first.row][first.column]='#';
                      ans={ 1,1 };
                    return ans;
                }
                third=nextuprightmaker(second);
                if(third.row==-1 && third.column==-1){
                  hexgrid[second.row][second.column]='#';
                  swap(hexgrid[second.row][second.column],hexgrid[first.row][first.column]);
                      ans={ 1,1 };
                         return ans;
                  }
                if(hexgrid[second.row][second.column]=='x'){
                    if(hexgrid[third.row][third.column]=='o' || hexgrid[third.row][third.column]=='x')
                        {return ans;}

                        if(hexgrid[third.row][third.column]=='#'){
                            swap(hexgrid[second.row][second.column],hexgrid[third.row][third.column]);
                            swap(hexgrid[second.row][second.column],hexgrid[first.row][first.column]);
                            ans={ 1,1 };
                            return ans;
                        }
                }

            }
        }
        
    }
return ans;
 }


 coord checknextdownleft(coord source, int pieceCount){
   coord ans={ -1,-1 }; 
    if(pieceCount==1){
        if(source.row>=4){
        if((hexgrid[source.row][source.column]=='x' && hexgrid[source.row+1][source.column-2]!='#')
        ||
        (hexgrid[source.row][source.column]=='o' && hexgrid[source.row+1][source.column-2]!='#'))
         return ans;
    }
    if(source.row<4){
        if((hexgrid[source.row][source.column]=='x' && hexgrid[source.row+1][source.column]!='#')
        ||
        (hexgrid[source.row][source.column]=='o' && hexgrid[source.row+1][source.column]!='#'))
         return ans;
    }
        ans={ 1,1 };
        return ans;
    }
    if(pieceCount==2){
        coord first,second;
        coord ans={ -1,-1 };
        first=nextdownleftmaker(source);
        if(first.row==-1 && first.column==-1)
                return ans;
        if(hexgrid[source.row][source.column]==hexgrid[first.row][first.column])
                return ans;
        
        if(hexgrid[first.row][first.column]=='#'){
            ans={1,1};
            return ans;
        }
        second=nextdownleftmaker(first);
        if(second.row==-1 && second.column==-1){
             hexgrid[first.row][first.column]='#';
             ans={ 1,1 };
            return ans;
            }

        if(hexgrid[first.row][first.column]=='o'){
            ////o#
            if(hexgrid[second.row][second.column]=='#'){
            swap(hexgrid[first.row][first.column],hexgrid[second.row][second.column]);
            ans={1,1};
            return ans;
            }
            ///oo
            if(hexgrid[second.row][second.column]=='o'){
            return ans;
            }
            ///ox
            if(hexgrid[second.row][second.column]=='x'){
            return ans;
            }
            ///o
            if(second.row==-1 && second.column==-1){
             hexgrid[first.row][first.column]='#';
             ans={ 1,1 };
            return ans;
            }
        }


        if(hexgrid[first.row][first.column]=='x'){
            ////x#
            if(hexgrid[second.row][second.column]=='#'){
            swap(hexgrid[first.row][first.column],hexgrid[second.row][second.column]);
            ans={1,1};
            return ans;
            }
            ///xx
            if(hexgrid[second.row][second.column]=='x'){
            return ans;
            }
            ///xo
            if(hexgrid[second.row][second.column]=='o'){
            return ans;
            }
            ///x
            if(second.row==-1 && second.column==-1){
             hexgrid[first.row][first.column]='#';
             ans={ 1,1 };
            return ans;
            }
        }
    }



    if(pieceCount==3){
        coord first,second,third;
         coord ans={ -1,-1 };

         first=nextdownleftmaker(source);
        
        if(first.row==-1 && first.column==-1)
                return ans;
        else if(hexgrid[source.row][source.column]==hexgrid[first.row][first.column])
                return ans;
        
        else if(hexgrid[first.row][first.column]=='#'){
            ans={1,1};
            return ans;
        }
        second=nextdownleftmaker(first);
        if(second.row==-1 && second.column==-1){
             hexgrid[first.row][first.column]='#';
             ans={ 1,1 };
            return ans;
            }

        if(hexgrid[source.row][source.column]=='x'){
            if(hexgrid[first.row][first.column]=='o'){
                if(hexgrid[second.row][second.column]=='x')
                        return ans;
                if(hexgrid[second.row][second.column]=='#'){
                    swap(hexgrid[first.row][first.column],hexgrid[second.row][second.column]);
                    ans={1,1};
                    return ans;
                }    
                 if(second.row==-1 && second.column==-1){
                    hexgrid[first.row][first.column]='#';
                      ans={ 1,1 };
                    return ans;
                }
                third=nextdownleftmaker(second);
                if(third.row==-1 && third.column==-1){
                  hexgrid[second.row][second.column]='#';
                  swap(hexgrid[second.row][second.column],hexgrid[first.row][first.column]);
                      ans={ 1,1 };
                         return ans;
                  }
                if(hexgrid[second.row][second.column]=='o'){
                    if(hexgrid[third.row][third.column]=='o' || hexgrid[third.row][third.column]=='x')
                       { return ans;}

                        if(hexgrid[third.row][third.column]=='#'){
                            swap(hexgrid[second.row][second.column],hexgrid[third.row][third.column]);
                            swap(hexgrid[second.row][second.column],hexgrid[first.row][first.column]);
                            ans={ 1,1 };
                            return ans;
                        }
                }

            }
        }
                if(hexgrid[source.row][source.column]=='o'){
            if(hexgrid[first.row][first.column]=='x'){
                if(hexgrid[second.row][second.column]=='o')
                        return ans;
                if(hexgrid[second.row][second.column]=='#'){
                    swap(hexgrid[first.row][first.column],hexgrid[second.row][second.column]);
                    ans={1,1};
                    return ans;
                }    
                 if(second.row==-1 && second.column==-1){
                    hexgrid[first.row][first.column]='#';
                      ans={ 1,1 };
                    return ans;
                }
                third=nextdownleftmaker(second);
                if(third.row==-1 && third.column==-1){
                  hexgrid[second.row][second.column]='#';
                  swap(hexgrid[second.row][second.column],hexgrid[first.row][first.column]);
                      ans={ 1,1 };
                         return ans;
                  }
                if(hexgrid[second.row][second.column]=='x'){
                    if(hexgrid[third.row][third.column]=='o' || hexgrid[third.row][third.column]=='x')
                        {return ans;}

                        if(hexgrid[third.row][third.column]=='#'){
                            swap(hexgrid[second.row][second.column],hexgrid[third.row][third.column]);
                            swap(hexgrid[second.row][second.column],hexgrid[first.row][first.column]);
                            ans={ 1,1 };
                            return ans;
                        }
                }

            }
        }
        
    }
    
    return ans;
 }


coord checknextdownright(coord source, int pieceCount){
   coord ans={ -1,-1 }; 
    if(pieceCount==1){
        if(source.row>=4){
        if((hexgrid[source.row][source.column]=='x' && hexgrid[source.row+1][source.column]!='#')
        ||
        (hexgrid[source.row][source.column]=='o' && hexgrid[source.row+1][source.column]!='#'))
         return ans;
    }
    if(source.row<4){
        if((hexgrid[source.row][source.column]=='x' && hexgrid[source.row+1][source.column+2]!='#')
        ||
        (hexgrid[source.row][source.column]=='o' && hexgrid[source.row+1][source.column+2]!='#'))
         return ans;
    }
        ans={ 1,1 };
        return ans;
    }
    if(pieceCount==2){
        coord first,second;
        coord ans={ -1,-1 };
        first=nextdownrightmaker(source);
        if(first.row==-1 && first.column==-1)
                return ans;
        if(hexgrid[source.row][source.column]==hexgrid[first.row][first.column])
                return ans;
        
        if(hexgrid[first.row][first.column]=='#'){
            ans={1,1};
            return ans;
        }
        second=nextdownrightmaker(first);
        if(second.row==-1 && second.column==-1){
             hexgrid[first.row][first.column]='#';
             ans={ 1,1 };
            return ans;
            }

        if(hexgrid[first.row][first.column]=='o'){
            ////o#
            if(hexgrid[second.row][second.column]=='#'){
            swap(hexgrid[first.row][first.column],hexgrid[second.row][second.column]);
            ans={1,1};
            return ans;
            }
            ///oo
            if(hexgrid[second.row][second.column]=='o'){
            return ans;
            }
            ///ox
            if(hexgrid[second.row][second.column]=='x'){
            return ans;
            }
            ///o
            if(second.row==-1 && second.column==-1){
             hexgrid[first.row][first.column]='#';
             ans={ 1,1 };
            return ans;
            }
        }


        if(hexgrid[first.row][first.column]=='x'){
            ////x#
            if(hexgrid[second.row][second.column]=='#'){
            swap(hexgrid[first.row][first.column],hexgrid[second.row][second.column]);
            ans={1,1};
            return ans;
            }
            ///xx
            if(hexgrid[second.row][second.column]=='x'){
            return ans;
            }
            ///xo
            if(hexgrid[second.row][second.column]=='o'){
            return ans;
            }
            ///x
            if(second.row==-1 && second.column==-1){
             hexgrid[first.row][first.column]='#';
             ans={ 1,1 };
            return ans;
            }
        }
    }
    


    if(pieceCount==3){
        coord first,second,third;
         coord ans={ -1,-1 };

         first=nextdownrightmaker(source);
        
        if(first.row==-1 && first.column==-1)
                return ans;
        else if(hexgrid[source.row][source.column]==hexgrid[first.row][first.column])
                return ans;
        
        else if(hexgrid[first.row][first.column]=='#'){
            ans={1,1};
            return ans;
        }
        second=nextdownrightmaker(first);
        if(second.row==-1 && second.column==-1){
             hexgrid[first.row][first.column]='#';
             ans={ 1,1 };
            return ans;
            }

        if(hexgrid[source.row][source.column]=='x'){
            if(hexgrid[first.row][first.column]=='o'){
                if(hexgrid[second.row][second.column]=='x')
                        return ans;
                if(hexgrid[second.row][second.column]=='#'){
                    swap(hexgrid[first.row][first.column],hexgrid[second.row][second.column]);
                    ans={1,1};
                    return ans;
                }    
                 if(second.row==-1 && second.column==-1){
                    hexgrid[first.row][first.column]='#';
                      ans={ 1,1 };
                    return ans;
                }
                third=nextdownrightmaker(second);
                if(third.row==-1 && third.column==-1){
                  hexgrid[second.row][second.column]='#';
                  swap(hexgrid[second.row][second.column],hexgrid[first.row][first.column]);
                      ans={ 1,1 };
                         return ans;
                  }
                if(hexgrid[second.row][second.column]=='o'){
                    if(hexgrid[third.row][third.column]=='o' || hexgrid[third.row][third.column]=='x')
                        {return ans;}

                        if(hexgrid[third.row][third.column]=='#'){
                            swap(hexgrid[second.row][second.column],hexgrid[third.row][third.column]);
                            swap(hexgrid[second.row][second.column],hexgrid[first.row][first.column]);
                            ans={ 1,1 };
                            return ans;
                        }
                }

            }
        }
                if(hexgrid[source.row][source.column]=='o'){
            if(hexgrid[first.row][first.column]=='x'){
                if(hexgrid[second.row][second.column]=='o')
                        return ans;
                if(hexgrid[second.row][second.column]=='#'){
                    swap(hexgrid[first.row][first.column],hexgrid[second.row][second.column]);
                    ans={1,1};
                    return ans;
                }    
                 if(second.row==-1 && second.column==-1){
                    hexgrid[first.row][first.column]='#';
                      ans={ 1,1 };
                    return ans;
                }
                third=nextdownrightmaker(second);
                if(third.row==-1 && third.column==-1){
                  hexgrid[second.row][second.column]='#';
                  swap(hexgrid[second.row][second.column],hexgrid[first.row][first.column]);
                      ans={ 1,1 };
                         return ans;
                  }
                if(hexgrid[second.row][second.column]=='x'){
                    if(hexgrid[third.row][third.column]=='o' || hexgrid[third.row][third.column]=='x')
                        {return ans;}

                        if(hexgrid[third.row][third.column]=='#'){
                            swap(hexgrid[second.row][second.column],hexgrid[third.row][third.column]);
                            swap(hexgrid[second.row][second.column],hexgrid[first.row][first.column]);
                            ans={ 1,1 };
                            return ans;
                        }
                }

            }
        }
        
    }

    return ans;
 }


//////////////////////////////////////////////////////////////////////////////////////////////// 


///////////////////////////////////////////////////////piececount=2

coord checkingCorrectCoordEntry(coord first, coord second , char move){
    coord ans={ -1,-1 };
    if (move == 'q') {
        if(second.row==nextupleftmaker(first).row && second.column==nextupleftmaker(first).column){
            ans={ 1,1 };
            return ans;
            }   
        }
    if (move == 'e') {
        if(second.row==nextuprightmaker(first).row && second.column==nextuprightmaker(first).column){
            ans={ 1,1 };
            return ans;
            }   
           
        }
    if (move == 'a') {
        if(second.row==nextleftmaker(first).row && second.column==nextleftmaker(first).column){
            ans={ 1,1 };
            return ans;
            }   
          
        }
    if (move == 'd') {
        if(second.row==nextrightmaker(first).row && second.column==nextrightmaker(first).column){
            ans={ 1,1 };
            return ans;
            }   
          
        }
    if (move == 'z') {
        if(second.row==nextdownleftmaker(first).row && second.column==nextdownleftmaker(first).column){
            ans={ 1,1 };
            return ans;
            }   
          
        }
    if (move == 'c') {
        if(second.row==nextdownrightmaker(first).row && second.column==nextdownrightmaker(first).column){
            ans={ 1,1 };
            return ans;
            }   
           
        }
    return ans;

}

////////////////////////////////////////////////////////////piececount3

coord checkingCorrectCoordEntry(coord first, coord second ,coord third , char move){
    coord ans={ -1,-1 };
    if (move == 'q') {
        if(third.row==nextupleftmaker(second).row && third.column==nextupleftmaker(second).column
        && second.row==nextupleftmaker(first).row && second.column==nextupleftmaker(first).column){
            ans={ 1,1 };
            return ans;
            }   
        }
    if (move == 'e') {
        if(third.row==nextuprightmaker(second).row && third.column==nextuprightmaker(second).column
        && second.row==nextuprightmaker(first).row && second.column==nextuprightmaker(first).column){
            ans={ 1,1 };
            return ans;
            }   
           
        }
    if (move == 'a') {
        if(third.row==nextleftmaker(second).row && third.column==nextleftmaker(second).column
         && second.row==nextleftmaker(first).row && second.column==nextleftmaker(first).column){
            ans={ 1,1 };
            return ans;
            }   
          
        }
    if (move == 'd') {
        if(third.row==nextrightmaker(second).row && third.column==nextrightmaker(second).column
         && second.row==nextrightmaker(first).row && second.column==nextrightmaker(first).column){
            ans={ 1,1 };
            return ans;
            }   
          
        }
    if (move == 'z') {
        if(third.row==nextdownleftmaker(second).row && third.column==nextdownleftmaker(second).column
         && second.row==nextdownleftmaker(first).row && second.column==nextdownleftmaker(first).column){
            ans={ 1,1 };
            return ans;
            }   
          
        }
    if (move == 'c') {
        if(third.row==nextdownrightmaker(second).row && third.column==nextdownrightmaker(second).column
         && second.row==nextdownrightmaker(first).row && second.column==nextdownrightmaker(first).column){
            ans={ 1,1 };
            return ans;
            }   
           
        }
    return ans;

}


void print() {
    system("color B");
    for (int i = 0; i < rows; i++) {
        cout << spaces(abs(rows / 2 - i));
        for (int j = 0; j < (2 * columns[i] - 1); j++) {
            cout << hexgrid[i][j];
        }
        cout << "\n";
    }
}

int scoreBoard(){
    int countO=0,countX=0;
    ofstream score("score.txt");
    for(int i=0; i<rows; i++)
         for(int j=0; j< 2*columns[i]-1; j++){
            if(hexgrid[i][j]=='o')
                countO++;

            if(hexgrid[i][j]=='x')
                countX++;
         }
          
            scoreO=(100/(15-countO))+((14-countX)*100);
            scoreX=(100/(15-countX))+((14-countO)*100);

         if(countO==8 || countX==8){
                exited=true;
                system("cls");
                if(countO==8){
                    winner=1;  
                }
                if(countX==8){
                    winner=2;
                }
         }
         score<<" THe score of " <<player_1<<" : "<<scoreX<<endl;
         score<<" THe score of " <<player_2<<" : "<<scoreO<<endl;

        return winner;

}
void saveLastGame(){
    ofstream save("save.txt");
    for(int i=0; i<rows; i++)
         for(int j=0; j< 2*columns[i]-1; j++){
            save<<hexgrid[i][j];
         }
}

void loadLastGame(){
    ifstream save("save.txt");

int index=0;
char charcharchar;
int secondIndex=0;
   
   while(save.get(charcharchar)){
    temp[secondIndex]=charcharchar;
    secondIndex++;
   }

   for(int i=0; i<rows; i++)
         for(int j=0; j< 2*columns[i]-1; j++){
            hexgrid[i][j]=temp[index];
            index++;
         }
}

int main(){
   system("color B");
    startgame:
    int winner=0;
    ////////menu;
    cout<<"======ABALONE======"<<endl;
    cout<<"[0]: Start"<<endl;
    cout<<"[1]: Continue"<<endl;
    cout<<"[2]: ScoreBoard"<<endl;
    cout<<"[3]: How to play?"<<endl;
    cout<<"[4]: Exit"<<endl;

    int menuIndex = _getch();
    bool flagContinue=false;
    bool flagScoreBoard=true;
    switch (menuIndex){
    case '0':
        exited = false;
        init();
        reset();
         break;

    case '4':
        return 0;
        break;
    }
   if(menuIndex=='2'){
        ifstream score("score.txt");
        string paragraph;
        while (getline(score,paragraph))
        {
            cout<<paragraph<<endl;
        }
        
        flagScoreBoard=false;
       
   }
   
   if(menuIndex=='1'){
        init();
        reset();
       loadLastGame();
       flagContinue=true;
         ifstream saveName("saveName.txt");
        string paragraph;
        int k=0;
        while (getline(saveName,paragraph))
        {
            if(k==0)
            player_1=paragraph;
            if(k==1)
                player_2=paragraph;
                    k++;
            
        }
        
        
       
       
   }
   if(menuIndex=='3'){
        system("cls");
        cout<<"[q]: upleft "<<endl<<"[e]: upright"<< endl<<"[d]: right"<<endl<<"[c]: downright"<<endl<<"[z]: downleft"<<endl<<"[a]: left"<<endl;
        cout<<"#.Piece count only could be 1,2 and 3 ."<<endl;
        cout<<"#.Coord entry form : Row and Column ."<<endl;
        cout<<"#.rows and column start from 0 to the lase."<<endl;
        cout<<"#.The Coord selection must be chosen in order to the way,for example: "<<endl<<" coord 1= 2 2 , coord 2= 2 3 , coord 3= 2 4 , move = d(right) "<<endl<<endl
        ;
        cout<<"Press any key to continue : ";
         _getch();
        system("cls");
        goto startgame;

            
        }

  if(flagScoreBoard)
  {
    system("cls");
    




    clock();
     int playerIndex;
    int pieceCount1=1;
    if(flagContinue){
    ifstream savePlayer("savePlayer.txt");
     char ch;
     while(savePlayer.get(ch)){
        playerIndex=ch;
     }
    }
    else
    { playerIndex=0;}
    if (!flagContinue)
    {
       cout<<"Starting the game ..."<<endl;
    cout<<" Enter player names : "<<endl;
    cin>>player_1>>player_2;
    }
    
    
    ofstream saveName("saveName.txt");
    saveName<<player_1<<endl;
    saveName<<player_2<<endl;
        system("cls");

    
    
   
    coord now = { 0,0 };
    coord second = { 0,0 };
    coord third = { 0,0 };
    
        
    while (!exited) {

        here:
        cout<<"The Time is :"<<double(clock())/(double)CLOCKS_PER_SEC<<endl;
        bool flagSameRow=false;
        print();

        cout<<playerTurn(playerIndex)<<endl; 


        int pieceCount=0;
        cout<<"Piece count :";

        
        cin>>pieceCount;

        if(pieceCount>=1 || pieceCount<=3){
        }
          else{
                system("cls");
                goto here;
        }
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// pieceCount=1
        if(pieceCount==1){
        cout<< "coord :";
        cin>>now.row>>now.column;
        if (now.row<0 || now.row >8 || now.column<0 || now.column > columns[now.row] )
        { system("cls");
            goto here;
        }

        now.column=2*now.column;

        if(!checkThecoord(now, playerIndex)){
                system("cls");
                goto here;
        }

       cout<<"way :";
        char move = _getch();
         bool moveflag=true;
         while (moveflag){
          if( move=='a' || move=='e' || move=='q' || move=='z' || move=='c' || move=='d')
            {moveflag=false;}
           else
           { move = _getch();} 
         }
         

        system("cls");
        if (move == 'q') {
            coord next;
            next=checknextupleft(now,pieceCount);
            if (next.row == -1 && next.column == -1) {
                system("cls");
                goto here;
            }
            next = getupleft(now);
            if (next.row != -1 && next.column != -1) {
                now = next;
            }
        }


        if (move == 'e') {
            coord next;
            next=checknextupright(now,pieceCount);
            if (next.row == -1 && next.column == -1) {
                system("cls");
                goto here;
            }
            next = getupright(now);
            if (next.row != -1 && next.column != -1) {
                now = next;
            }
        }


        if (move == 'a') {
            coord next;
             next=checknextleft(now,pieceCount);
            if (next.row == -1 && next.column == -1) {
                
                system("cls");
                goto here;
            }
            next = getleft(now);
            if (next.row != -1 && next.column != -1) {
                now = next;
            }
        }


        if (move == 'd') {
            coord next;
             next=checknextright(now,pieceCount);
            if (next.row == -1 && next.column == -1) {
                system("cls");
                goto here;
            }
            next = getright(now);
            if (next.row != -1 && next.column != -1) {
                now = next;
            }
        }


        if (move == 'z') {
            coord next;
             next=checknextdownleft(now,pieceCount);
            if (next.row == -1 && next.column == -1) {
                system("cls");
                goto here;
            }
            next = getdownleft(now);
            if (next.row != -1 && next.column != -1) {
                now = next;
            }
        }


        if (move == 'c') {
            coord next;
             next=checknextdownright(now,pieceCount);
            if (next.row == -1 && next.column == -1) {
                system("cls");
                goto here;
            }
            next = getdownright(now);
            if (next.row != -1 && next.column != -1) {
                now = next;
            
            }
        }
        playerIndex++;

        
    }




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// // piececount=2

if(pieceCount==2){
        cout<< "coord 1:";
        cin>>now.row>>now.column;
        if (now.row<0 || now.row >8 || now.column<0 || now.column > columns[now.row] )
        { system("cls");
            goto here;
        }
        now.column=2*now.column;
        if(!checkThecoord(now, playerIndex)){
                system("cls");
                goto here;
        }

        cout<< "coord 2:";
        cin>>second.row>>second.column;
        if (second.row<0 || second.row >8 || second.column<0 || second.column > columns[second.row] )
        { system("cls");
            goto here;
        }
        second.column=2*second.column;


        
        if(!checkThecoord(second, playerIndex)){
                system("cls");
                goto here;
        }

       cout<<"way :";
        char move = _getch();
         bool moveflag=true;
         while (moveflag){
          if( move=='a' || move=='e' || move=='q' || move=='z' || move=='c' || move=='d')
            {moveflag=false;}
           else
           { move = _getch();} 
         }
        if(move!='d'  && move!='a'){
            if(second.row==now.row)
                    flagSameRow=true;
        }

        if(flagSameRow==false){
            coord ans=checkingCorrectCoordEntry(now,second,move);
          if (ans.row == -1 && ans.column == -1) {
                   system("cls");
                   goto here;
                 }
            
        }
        system("cls");
        if (move == 'q') {
            coord next;
            if(flagSameRow==true){
               next=checknextupleft(second,pieceCount1);
                if (next.row == -1 && next.column == -1) {
                   system("cls");
                   goto here;
                 }
              next=checknextupleft(now,pieceCount1);
                 if (next.row == -1 && next.column == -1) {
                    system("cls");
                    goto here;
                 }
            }

             next=checknextupleft(second,pieceCount1);
                if (next.row == -1 && next.column == -1) {
                   system("cls");
                   goto here;
                 }
            next = getupleft(second);
            if (next.row != -1 && next.column != -1) {
                second = next;
            
            }
            next = getupleft(now);
            if (now.row != -1 && now.column != -1) {
                now = next;
            
            }
            
        }
        if (move == 'e') {
            coord next;
            if(flagSameRow==true){
               next=checknextupright(second,pieceCount1);
                if (next.row == -1 && next.column == -1) {
                   system("cls");
                   goto here;
                 }
              next=checknextupright(now,pieceCount1);
                 if (next.row == -1 && next.column == -1) {
                    system("cls");
                    goto here;
                 }
            }

             next=checknextupright(second,pieceCount1);
                if (next.row == -1 && next.column == -1) {
                   system("cls");
                   goto here;
                 }
            next = getupright(second);
            if (next.row != -1 && next.column != -1) {
                second = next;
            
            }
            next = getupright(now);
            if (now.row != -1 && now.column != -1) {
                now = next;
            
            }
        }
        if (move == 'a') {
            coord next;
             next=checknextleft(second,pieceCount);
            if (next.row == -1 && next.column == -1) {
                system("cls");
                goto here;
            }
            next = getleft(second);
            if (next.row != -1 && next.column != -1) {
                second = next;
            
            }
            next = getleft(now);
            if (now.row != -1 && now.column != -1) {
                now = next;
            
            }
        }
        if (move == 'd') {
            coord next;
             next=checknextright(second,pieceCount);
            if (next.row == -1 && next.column == -1) {
                system("cls");
                goto here;
            }
            next = getright(second);
            if (next.row != -1 && next.column != -1) {
                second = next;
            
            }
            next = getright(now);
            if (now.row != -1 && now.column != -1) {
                now = next;
            
            }
        }
        if (move == 'z') {
            coord next;
            if(flagSameRow==true){
               next=checknextdownleft(second,pieceCount1);
                if (next.row == -1 && next.column == -1) {
                   system("cls");
                   goto here;
                 }
              next=checknextdownleft(now,pieceCount1);
                 if (next.row == -1 && next.column == -1) {
                    system("cls");
                    goto here;
                 }
            }

             next=checknextdownleft(second,pieceCount1);
                if (next.row == -1 && next.column == -1) {
                   system("cls");
                   goto here;
                 }
            next = getdownleft(second);
            if (next.row != -1 && next.column != -1) {
                second = next;
            
            }
            next = getdownleft(now);
            if (now.row != -1 && now.column != -1) {
                now = next;
            
            }
        }
        if (move == 'c') {
            coord next;
            if(flagSameRow==true){
               next=checknextdownright(second,pieceCount1);
                if (next.row == -1 && next.column == -1) {
                   system("cls");
                   goto here;
                 }
              next=checknextdownright(now,pieceCount1);
                 if (next.row == -1 && next.column == -1) {
                    system("cls");
                    goto here;
                 }
            }

             next=checknextdownright(second,pieceCount1);
                if (next.row == -1 && next.column == -1) {
                   system("cls");
                   goto here;
                 }
            next = getdownright(second);
            if (next.row != -1 && next.column != -1) {
                second = next;
            
            }
            next = getdownright(now);
            if (now.row != -1 && now.column != -1) {
                now = next;
            
            }
        }
        playerIndex++;

        
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// piececount=3
    if(pieceCount==3){
        cout<< "coord 1:";
        cin>>now.row>>now.column;
        if (now.row<0 || now.row >8 || now.column<0 || now.column > columns[now.row] )
        { system("cls");
            goto here;
        }
        now.column=2*now.column;
        if(!checkThecoord(now, playerIndex)){
                system("cls");
                goto here;
        }

        cout<< "coord 2:";
        cin>>second.row>>second.column;
        if (second.row<0 || second.row >8 || second.column<0 || second.column > columns[second.row] )
        { system("cls");
            goto here;
        }
        second.column=2*second.column;

                if(!checkThecoord(second, playerIndex)){
                system("cls");
                goto here;
        }

        cout<< "coord 3:";
        cin>>third.row>>third.column;
        if (third.row<0 || third.row >8 || third.column<0 || third.column > columns[third.row] )
        { system("cls");
            goto here;
        }
        third.column=2*third.column;
        
        if(!checkThecoord(third, playerIndex)){
                system("cls");
                goto here;
        }

       cout<<"way :";
        char move = _getch();
         bool moveflag=true;
         while (moveflag){
          if( move=='a' || move=='e' || move=='q' || move=='z' || move=='c' || move=='d')
            {moveflag=false;}
           else
           { move = _getch();} 
         }
         if(move!='d'  && move!='a'){
            if(second.row==now.row)
                    flagSameRow=true;
        }

        if(flagSameRow==false){
            coord ans=checkingCorrectCoordEntry(now,second,third,move);
          if (ans.row == -1 && ans.column == -1) {
                   system("cls");
                   goto here;
                 }
        }
        system("cls");
        if (move == 'q') {
            coord next;
            if(flagSameRow==true){
             next=checknextupleft(third,pieceCount1);
            if (next.row == -1 && next.column == -1) {
                system("cls");
                goto here;
            }
             next=checknextupleft(second,pieceCount1);
            if (next.row == -1 && next.column == -1) {
                system("cls");
                goto here;
            }
             next=checknextupleft(now,pieceCount1);
            if (next.row == -1 && next.column == -1) {
                system("cls");
                goto here;
            }
        }
            next=checknextupleft(third,pieceCount1);
                if (next.row == -1 && next.column == -1) {
                system("cls");
                goto here;
            }
             next = getupleft(third);
            if (next.row != -1 && next.column != -1) {
                third = next;
            
            }
            next = getupleft(second);
            if (next.row != -1 && next.column != -1) {
                second = next;
            
            }
            next = getupleft(now);
            if (now.row != -1 && now.column != -1) {
                now = next;
            
            }
            
        }
        if (move == 'e') {
            coord next;
            if(flagSameRow==true){
             next=checknextupright(third,pieceCount1);
            if (next.row == -1 && next.column == -1) {
                system("cls");
                goto here;
            }
            next=checknextupright(second,pieceCount1);
            if (next.row == -1 && next.column == -1) {
                system("cls");
                goto here;
            }
            next=checknextupright(now,pieceCount1);
            if (next.row == -1 && next.column == -1) {
                system("cls");
                goto here;
            }
        }   
             next=checknextupright(third,pieceCount);
            if (next.row == -1 && next.column == -1) {
                system("cls");
                goto here;
            }
            next = getupright(third);
            if (next.row != -1 && next.column != -1) {
                third = next;
            
            }
            next = getupright(second);
            if (next.row != -1 && next.column != -1) {
                second = next;
            
            }
            next = getupright(now);
            if (now.row != -1 && now.column != -1) {
                now = next;
            
            }
        }
        if (move == 'a') {
            coord next;
             next=checknextleft(third,pieceCount);
            if (next.row == -1 && next.column == -1) {
                system("cls");
                goto here;
            }
            
            next = getleft(third);
            if (next.row != -1 && next.column != -1) {
                third = next;
            
            }
            next = getleft(second);
            if (next.row != -1 && next.column != -1) {
                second = next;
            
            }
            next = getleft(now);
            if (now.row != -1 && now.column != -1) {
                now = next;
            
            }
        }
        if (move == 'd') {
            coord next;
             next=checknextright(third,pieceCount);
            if (next.row == -1 && next.column == -1) {
                system("cls");
                goto here;
            }
             next = getright(third);
            if (next.row != -1 && next.column != -1) {
                third = next;
            
            }
            next = getright(second);
            if (next.row != -1 && next.column != -1) {
                second = next;
            
            }
            next = getright(now);
            if (now.row != -1 && now.column != -1) {
                now = next;
            
            }
        }
        if (move == 'z') {
            coord next;
            if(flagSameRow==true){
             next=checknextdownleft(third,pieceCount1);
            if (next.row == -1 && next.column == -1) {
                system("cls");
                goto here;
            }
             next=checknextdownleft(second,pieceCount1);
            if (next.row == -1 && next.column == -1) {
                system("cls");
                goto here;
            }
             next=checknextdownleft(now,pieceCount1);
            if (next.row == -1 && next.column == -1) {
                system("cls");
                goto here;
            }
        }
             next=checknextdownleft(third,pieceCount);
            if (next.row == -1 && next.column == -1) {
                system("cls");
                goto here;
            }

            next = getdownleft(third);
            if (next.row != -1 && next.column != -1) {
                third = next;
            
            }
            next = getdownleft(second);
            if (next.row != -1 && next.column != -1) {
                second = next;
            
            }
            next = getdownleft(now);
            if (now.row != -1 && now.column != -1) {
                now = next;
            
            }
        }
        if (move == 'c') {
            coord next;
            if(flagSameRow==true){
             next=checknextdownright(third,pieceCount1);
            if (next.row == -1 && next.column == -1) {
                system("cls");
                goto here;
            }
             next=checknextdownright(second,pieceCount1);
            if (next.row == -1 && next.column == -1) {
                system("cls");
                goto here;
            }
             next=checknextdownright(now,pieceCount1);
            if (next.row == -1 && next.column == -1) {
                system("cls");
                goto here;
            }
        }
             next=checknextdownright(third,pieceCount);
            if (next.row == -1 && next.column == -1) {
                system("cls");
                goto here;
            }
            next = getdownright(third);
            if (next.row != -1 && next.column != -1) {
                third = next;
            
            }
            next = getdownright(second);
            if (next.row != -1 && next.column != -1) {
                second = next;
            
            }
            next = getdownright(now);
            if (now.row != -1 && now.column != -1) {
                now = next;
            
            }
        }
        playerIndex++;
         
         ofstream savePlayer("savePlayer.txt");

        
    }
    saveLastGame();
    scoreBoard();
switch (winner)
{
case 1:
    system ("cls");
    cout<< "***Game ended***"<<endl;
    print();
    cout<<endl;
    cout<<" THe winner is "<<player_1<<endl;
    cout<<" THe score of " <<player_1<<" : "<<scoreX<<endl;
    cout<<" THe score of " <<player_2<<" : "<<scoreO<<endl;
    exited=true;
    break;
case 2:
    system ("cls");
    cout<< "***Game ended***"<<endl;
    print();
    cout<<endl;
    cout<<" THe winner is "<<player_2<<endl;
    cout<<" THe score of " <<player_2<<" : "<<scoreX<<endl;
    cout<<" THe score of " <<player_1<<" : "<<scoreO<<endl;
    exited=true;
    break;
default:
    break;
}

 ofstream savePlayer("savePlayer.txt");
 savePlayer<<playerIndex;

}

system("cls");

  }

cout<<"Press any key to continue : ";
_getch();
system("cls");
goto startgame;


   
    


}

