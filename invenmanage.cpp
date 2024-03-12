#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;


struct itemEntry
{
   char name[40];
   char company[30];
   int unit_price;
   int copies,product_id;
};



class Cafe
{

public:
    int numitem;
    itemEntry data[100];

    cafe()
    {
    numitem=0;
    }

   void insertItem(char itemname[],char company[],int money,int copie,int pid);
   void deleteItem(char itemname[],int pid);
   itemEntry *search(char itemname[],int pid);
   void updeteItem(char itemname[],int pid,int total, int money);


};



void Cafe::insertItem(char itemname[],char company[],int pid,int copie,int money){
          strcpy(data[numitem].name,itemname);
          strcpy(data[numitem].company,company);
          data[numitem].product_id=pid;
          data[numitem].copies=copie;
          data[numitem].unit_price=money;
        cout<<"\n\t\t ITEM INSERTD SUCCESSFULLY \n";
        numitem++;
}



void Cafe::deleteItem(char itemname[],int pid){
int i;
for(i=0;i<numitem; i++)
    {

    if(((itemname,data[i].name)==0)&&(data[i].product_id==pid)){
                  data[i].copies--;
           cout<<"\n\t\t ITEM DELETED SUCCESSFULY \n";
    }



    else{
    cout<<"\n\t\t\t ITEM NOT FOUND \n";
    }

}

}


itemEntry *Cafe ::search(char itemname[],int pid)
{

int i;
for(i=0;i<numitem; i++)
    {
     if((strcmp(itemname,data[i].name)==0)&&(data[i].product_id==pid))
        return &data[i];
   }
   return NULL;

}



void Cafe:: updeteItem(char itemname[],int pid,int total, int money)
{

itemEntry *item=search(itemname,pid);
if(item==NULL)
    {
    cout<<"\n\t\t\t ITEM NOT FOUND \n";
    return;
    }
    item->copies=total;
    item->unit_price=money;
}

int main(){

    Cafe caf;
    char name[30],company[30];
    int product_id,copies,unit_price,option;
    do{

      cout<<"\n\t  ------------------>DEPARMENTAL CAFE<------------------";
      cout<<"\n\t\t ----------------->MENU<-----------";
      cout<<"\n\t\t\t     1 for insert";
      cout<<"\n\t\t\t     2 for delete";
      cout<<"\n\t\t\t     3 for search";
      cout<<"\n\t\t\t     4 for update";
      cout<<"\n\t\t\t     5 for exit";
      cout<<"\n\t\t\t   entre your choice :";
      cin>>option;
      switch(option)
      {

       case 1:    cin.getline(name,80);
                  cout<<"\n\t\t\t enter name of Item:";
                  cin.getline(name,80);
                  cout<<"\n\t\t\t company:";
                  cin.getline(company,80);
                  cout<<"\n\t\t\t enter product ID:";
                  cin>>product_id;
                  cout<<"\n\t\t\t no of copies:";
                  cin>>copies;
                  cout<<"\n\t\t\t unit price per Item:";
                  cin>>unit_price;
                  caf.insertItem(name,company,product_id,copies,unit_price);
                  break;


    case 2:       cin.getline(name,80);
                  cout<<"\n\t\t\t enter name of Item:";
                  cin.getline(name,80);
                  cout<<"\n\t\t\t enter product ID:";
                  cin>>product_id;
                  caf.deleteItem(name,product_id);
                  break;



    case 3:       cin.getline(name,80);
                  cout<<"\n\t\t\t enter name of Item:";
                  cin.getline(name,80);
                  cout<<"\n\t\t\t enter product ID:";
                  cin>>product_id;
                  itemEntry *test;
                  test=caf.search(name,product_id);
                  if(test!=NULL){

                    cout<<"\n\t  ---------->SERCHING RESULT<----------------";
                    cout<<"\n\t\t\t  ITEM FOUND "<<"\n\t\t\t name of the Item:"<<test->name<<"\n\t\t\t company name:"
                    <<test->company<<"\n\t\t\t product ID:"<<test->product_id<<"\n\t\t\t number of copies available:"<<test->copies<<"\n\t\t\t unit price:";

                }
                else
                    cout<<"n\t\t\t ITEM NOT FOUND";
                break;



   case 4:        cout<<"\n\t\t\t enter details for item";
                  cin.getline(name,80);
                  cout<<"\n\t\t\t enter name of Item:";
                  cin.getline(name,80);
                  cout<<"\n\t\t\t company:";
                  cin.getline(company,80);
                  cout<<"\n\t\t\t enter total new entry:";
                  cin>>copies;
                  cout<<"\n\t\t\t enter new price:";
                  cin>>unit_price;
                  caf.updeteItem(name,product_id,copies,unit_price);
                  break;

         }

      }while(option!=5);
        return 0;


}
























