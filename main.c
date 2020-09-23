#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <math.h>

                                        // case1 biraz eksik

struct dotsxyz{
double x1,y1,z1;

}points1[85000];

struct dotsxyzrgb{
double x2,y2,z2;
int r,g,b;

}points2[85000];
struct bindotsxyz{
float binx1,biny1,binz1;

}binpoints1[50000];

struct bindotsxyzrgb{
float binx2,biny2,binz2;
char binr,bing,binb;

}binpoints2[50000];

struct cube{
    double cx,cy,cz;
    int cr,cg,cb;

}corners[8];

struct bincube{
float bincx,bincy,bincz;
int bincr,bincg,bincb;

}bincorners[8];


int main()
{
    struct dirent *entry;
    DIR *dp;
    dp=opendir(".");
    if(dp==NULL){   // (1) dp kontrolu yaptým eger acilmadiysa hata verir
        printf("file can't open\n");

    }
    int files_Count=0; // (2) dosyanin icinde kac tane belge var oldugunu tutan sayac

    while(entry=readdir(dp)){  // (3) dosyanin icindeki
        puts(entry->d_name);   // belgelerin ismini yazdirip
        files_Count++;         // kac dosya oldugunu buluyor
    }
    printf("\n-----files count: %d-----\n\n",files_Count);
    closedir(dp);
    dp=opendir(".");
    if(dp==NULL){   // (1)'deki islemlerin aynisini yapar
        printf("file can't open\n");

    }
    char all_Files[files_Count][100]; //(4) dosya icindeki butun belgelerin ismini tutar
    int k=0;
    while(entry=readdir(dp)){       // (5) dosya icindeki
        strcpy(all_Files[k],entry->d_name); // belgelerin ismini
        k++;                                // all_Files dizisine atar
    }
    int i;
    for(i=0;i<files_Count;i++){ // (6) all_Files dizisinin icindeki
        puts(all_Files[i]);     //  belgelerin ismini yazar
    }

    closedir(dp);

    char nkt[]=".nkt";
    int nkt_Counts=0; // (7) dosya icindeki .nkt uzantili belgelerin sayisini tutan sayac
    dp=opendir(".");
    if(dp==NULL){   // (1)'deki islemlerin aynisini yapar
        printf("file can't open\n");

    }


    while(entry=readdir(dp)){       //  (8) dosya icinde
        if(strstr(entry->d_name,nkt)){  // kac tane .nkt uzantili belge
            nkt_Counts++;               // var oldugunu hesaplar
        }
    }
    closedir(dp);
    printf("\n-----nkt counts: %d-----\n",nkt_Counts);

    char nkt_Files[nkt_Counts][100]; // (9) dosya icindeki .nkt uzantili belgelerin ismini tutar
    dp=opendir(".");
    if(dp==NULL){   // (1)'deki islemlerin aynisini yapar
        printf("file can't open\n");

    }
    int a=0;
    while(entry=readdir(dp)){                  // (10) dosya icindeki
        if(strstr(entry->d_name,nkt)!=NULL){   // .nkt uzantili belgelerin
            strcpy(nkt_Files[a],entry->d_name); // nkt_Files dizisine atar
            a++;
        }
    }



    printf("\n-----nkt files-----\n\n");
    for(i=0;i<nkt_Counts;i++){   // (11) nkt_Files dizisinin icimdeki
        puts(nkt_Files[i]);       //  belgelerin isimlerini yazar
    }
    closedir(dp);



    FILE *fptr;
    int p,j;
    char files_Controls[50][30];
    char data_Type_Ascii[]="ascii";
    char data_Type_Binary[]="binary";
    int choise=10;
    double central_X,central_Y,central_Z,central_R;

    while(choise!=0){
            printf("\nPlease entry a choise: \n1- Dosya kontrolu\n2- En yakin ve en uzak Noktalar\n3- Kup\n4- Kure\n5- Nokta uzakliklari\n0- Cikmak icin 0'a basiniz\n");
            scanf("%d",&choise);


     switch(choise){
        case 1:

            for(p=0;p<nkt_Counts;p++){

        fptr=fopen(nkt_Files[p],"r");
        printf("\n\n\n");


        if(fptr!=NULL){

                free(files_Controls);








            for(j=0;j<17;j++){
                fscanf(fptr,"%s",files_Controls[j]);
                printf("%s",files_Controls[j]);
                }
                if( strcmp(files_Controls[0],"#") ==0 && strcmp(files_Controls[1],"Noktalar")==0 && strcmp(files_Controls[2],"dosya")==0 && strcmp(files_Controls[3],"format")==0 && strcmp(files_Controls[4],"VERSION")==0 && strcmp(files_Controls[5],"1")==0 && strcmp(files_Controls[6],"ALANLAR")==0 && strcmp(files_Controls[7],"x")==0 && strcmp(files_Controls[8],"y")==0 && strcmp(files_Controls[9],"z")==0 && strcmp(files_Controls[10],"r")==0 && strcmp(files_Controls[11],"g")==0 && strcmp(files_Controls[12],"b")==0 && strcmp(files_Controls[13],"NOKTALAR")==0 && strcmp(files_Controls[15],"DATA")==0 && strcmp(files_Controls[16],"ascii")==0   )  {
                  //  printf("\n**BASARILI**\n");
                }

                else if( strcmp(files_Controls[0],"#") ==0 && strcmp(files_Controls[1],"Noktalar")==0 && strcmp(files_Controls[2],"dosya")==0 && strcmp(files_Controls[3],"format")==0 && strcmp(files_Controls[4],"VERSION")==0 && strcmp(files_Controls[5],"1")==0 && strcmp(files_Controls[6],"ALANLAR")==0 && strcmp(files_Controls[7],"x")==0 && strcmp(files_Controls[8],"y")==0 && strcmp(files_Controls[9],"z")==0 && strcmp(files_Controls[10],"r")==0 && strcmp(files_Controls[11],"g")==0 && strcmp(files_Controls[12],"b")==0 && strcmp(files_Controls[13],"NOKTALAR")==0 && strcmp(files_Controls[15],"DATA")==0 && strcmp(files_Controls[16],"binary")==0   )  {

                //printf("\n**BASARILI**\n");
                }
                else if( strcmp(files_Controls[0],"#") ==0 && strcmp(files_Controls[1],"Noktalar")==0 && strcmp(files_Controls[2],"dosya")==0 && strcmp(files_Controls[3],"format")==0 && strcmp(files_Controls[4],"VERSION")==0 && strcmp(files_Controls[5],"1")==0 && strcmp(files_Controls[6],"ALANLAR")==0 && strcmp(files_Controls[7],"x")==0 && strcmp(files_Controls[8],"y")==0 && strcmp(files_Controls[9],"z")==0 && strcmp(files_Controls[10],"NOKTALAR")==0 && strcmp(files_Controls[12],"DATA")==0 && strcmp(files_Controls[13],"ascii")==0   )  {

                //printf("\n**BASARILI**\n");
                }
                else if( strcmp(files_Controls[0],"#") ==0 && strcmp(files_Controls[1],"Noktalar")==0 && strcmp(files_Controls[2],"dosya")==0 && strcmp(files_Controls[3],"format")==0 && strcmp(files_Controls[4],"VERSION")==0 && strcmp(files_Controls[5],"1")==0 && strcmp(files_Controls[6],"ALANLAR")==0 && strcmp(files_Controls[7],"x")==0 && strcmp(files_Controls[8],"y")==0 && strcmp(files_Controls[9],"z")==0 &&  strcmp(files_Controls[10],"NOKTALAR")==0 && strcmp(files_Controls[12],"DATA")==0 && strcmp(files_Controls[13],"binary")==0   )  {

                //printf("\n**BASARILI**\n");
                }else{
                    FILE *outptr;
                                                                char out_Name[30];
                                                                strcpy(out_Name,"output");
                                                                strcat(out_Name,nkt_Files[p]);
                                                                outptr=fopen(out_Name,"a");
                                                                fprintf(outptr,"\nSecim 1\nUyusmayan format\n");

                                                                fclose(outptr);

                continue;

                }



            for(j=0;j<50;j++){

                if(strcmp(files_Controls[j],"ALANLAR")==0){
                        if(strcmp(files_Controls[j+1],"x")==0){
                        printf("X IS HERE ");
                            if(strcmp(files_Controls[j+2],"y")==0){
                            printf("Y IS HERE ");
                                if(strcmp(files_Controls[j+3],"z")==0){
                                printf("Z IS HERE ");
                                    if(strcmp(files_Controls[j+4],"r")==0){
                                    printf("R IS HERE ");
                                        if(strcmp(files_Controls[j+5],"g")==0){
                                            printf("G IS HERE ");
                                                if(strcmp(files_Controls[j+6],"b")==0){
                                                printf("B IS HERE ");
                                                //x y z r g b kodlari buraya
                                                printf("\nThis is X Y Z R G B\n");
                                                int t;
                                                    for(t=0;t<50;t++){
                                                        if(strcmp(files_Controls[t],"DATA")==0){
                                                            if(strcmp(files_Controls[t+1],data_Type_Ascii)==0){
                                                                printf("\nThis file is ASCII\n");
                                                                //x y z r g b ascii kodlari buraya
                                                                fclose(fptr);
                                                                fptr=fopen(nkt_Files[p],"r");
                                                                int y=0,u,counter=0;
                                                                //fseek(fptr,79,SEEK_SET);
                                                                //printf("%ld\n",ftell(fptr));
                                                                char words[900][20];
                                                                int words_Counter=0;

                                                                while(!feof(fptr)){
                                                                    fscanf(fptr,"%s",&words[words_Counter]);


                                                                    if(strcmp(words[words_Counter],"ascii")==0){
                                                                        break;

                                                                    }
                                                                    words_Counter++;



                                                                }
                                                                //printf("TEST%d",words_Counter);




                                                                while(!feof(fptr)){
                                                                    fscanf(fptr,"%lf %lf %lf",&points2[y].x2,&points2[y].y2,&points2[y].z2);
                                                                    fscanf(fptr,"%d %d %d",&points2[y].r,&points2[y].g,&points2[y].b);
                                                                    //printf("%lf %lf %lf ",points2[y].x2,points2[y].y2,points2[y].z2);
                                                                   // printf("%d %d %d\n",points2[y].r,points2[y].g,points2[y].b);
                                                                    y++;

                                                                }
                                                                //printf("\nBu Dosyada %s\n",nkt_Files[p]);
                                                                //printf("\nnokta sayısı: %d\n",y);


                                                                        /*for(u=0;u<y-1;u++){
                                                                    printf("%lf %lf %lf ",points2[u].x2,points2[u].y2,points2[u].z2);
                                                                    printf("%d %d %d\n",points2[u].r,points2[u].g,points2[u].b);

                                                                }*/




                                                                /*for(u=0;u<y-1;u++){
                                                                    printf("%lf %lf %lf ",points2[u].x2,points2[u].y2,points2[u].z2);
                                                                    printf("%d %d %d\n",points2[u].r,points2[u].g,points2[u].b);

                                                                }*/
                                                                int any_Counter;
                                                                for(any_Counter=0;any_Counter<y;any_Counter++){

                                                                    if(points2[any_Counter].g==0 && points2[any_Counter].b==0){
                                                                            FILE *outptr;
                                                                    char out_Name[30];
                                                                    strcpy(out_Name,"output");
                                                                    strcat(out_Name,nkt_Files[p]);
                                                                    outptr=fopen(out_Name,"a");
                                                                    fprintf(outptr,"\nSecim 1\n%d. satirdaki nokta r g b'si yoktur\n",any_Counter);
                                                                    fclose(outptr);


                                                                    }

                                                                }

                                                                if(y!=atoi(files_Controls[14])){
                                                                        FILE *outptr;
                                                                    char out_Name[30];
                                                                    strcpy(out_Name,"output");
                                                                    strcat(out_Name,nkt_Files[p]);
                                                                    outptr=fopen(out_Name,"a");
                                                                    fprintf(outptr,"\nSecim 1\n nokta sayisi gecerli degildir \n");
                                                                    fclose(outptr);

                                                                }
                                                                //printf("\nnokta sayısı: %s\n",files_Controls[14]);




                                                               /* FILE *outptr;
                                                                char out_Name[30];
                                                                strcpy(out_Name,"output");
                                                                strcat(out_Name,nkt_Files[p]);
                                                                outptr=fopen(out_Name,"a");

                                                                fclose(outptr);

                                                                //printf("\ny: %d\n",y);
                                                                counter=y-1;
                                                                u=0;*/



















                                                                break;
                                                            }else if(strcmp(files_Controls[t+1],data_Type_Binary)==0){
                                                                printf("\nThis file is Binary\n");
                                                                //x y z r g b binary kodlari buraya
                                                                fclose(fptr);
                                                                fptr=fopen(nkt_Files[p],"rb");

                                                                int binary_Word_Counter=0,search_Counter=0;
                                                                char ch;
                                                                while(!feof(fptr)){
                                                                    ch=fgetc(fptr);
                                                                    if(ch=='y'){
                                                                        search_Counter++;
                                                                    }
                                                                    if(search_Counter==3){
                                                                        break;
                                                                    }
                                                                    binary_Word_Counter++;

                                                                }
                                                                binary_Word_Counter=binary_Word_Counter+2;
                                                                //printf("binarywordc %d",binary_Word_Counter);


                                                                fseek(fptr,binary_Word_Counter,SEEK_SET);



                                                                int counter7=0,counter8;
                                                                while(!feof(fptr)){

                                                                    fread(&binpoints2[counter7].binx2,sizeof(float),1,fptr);
                                                                    fread(&binpoints2[counter7].biny2,sizeof(float),1,fptr);
                                                                    fread(&binpoints2[counter7].binz2,sizeof(float),1,fptr);
                                                                    fread(&binpoints2[counter7].binr,sizeof(int),1,fptr);
                                                                    fread(&binpoints2[counter7].bing,sizeof(int),1,fptr);
                                                                    fread(&binpoints2[counter7].binb,sizeof(int),1,fptr);

                                                                    counter7++;


                                                                }
                                                                //printf("\nnokta sayısı: %d\n",counter7);
                                                                 /*for(counter8=0;counter8<counter7-1;counter8++){
                                                                    printf("binary--> x:%f y:%f z:%f r:%d g:%d b:%d\n",binpoints2[counter8].binx2,binpoints2[counter8].biny2,binpoints2[counter8].binz2,binpoints2[counter8].binr,binpoints2[counter8].bing,binpoints2[counter8].binb);
                                                                }*/


                                                                int any_Counter;
                                                                for(any_Counter=0;any_Counter<counter7-1;any_Counter++){

                                                                    if(binpoints2[any_Counter].bing==0 && binpoints2[any_Counter].binb==0){
                                                                            FILE *outptr;
                                                                    char out_Name[30];
                                                                    strcpy(out_Name,"output");
                                                                    strcat(out_Name,nkt_Files[p]);
                                                                    outptr=fopen(out_Name,"a");
                                                                    fprintf(outptr,"\nSecim 1\n%d. satirdaki nokta r g b'si yoktur\n",any_Counter);
                                                                    fclose(outptr);


                                                                    }

                                                                }
                                                                //printf("\nnokta sayısı: %s\n",files_Controls[14]);

                                                                if(counter7-1!=atoi(files_Controls[14])){
                                                                        FILE *outptr;
                                                                    char out_Name[30];
                                                                    strcpy(out_Name,"output");
                                                                    strcat(out_Name,nkt_Files[p]);
                                                                    outptr=fopen(out_Name,"a");
                                                                    fprintf(outptr,"\nSecim 1\n nokta sayisi gecerli degildir \n");
                                                                    fclose(outptr);

                                                                }



                                                                /*FILE *outptr;
                                                                char out_Name[30];
                                                                strcpy(out_Name,"output");
                                                                strcat(out_Name,nkt_Files[p]);
                                                                outptr=fopen(out_Name,"a");

                                                                fclose(outptr);*/







                                                                break;

                                                            }else{
                                                            break;
                                                            }

                                                        }


                                                    }



                                                    break;


                                                }else{
                                                    FILE *outptr;
                                                        char out_Name[30];
                                                        strcpy(out_Name,"output");
                                                        strcat(out_Name,nkt_Files[p]);
                                                        outptr=fopen(out_Name,"a");
                                                        fprintf(outptr,"\nFaulty file\n");

                                                                fclose(outptr);
                                //printf("\nFaulty file\n");


                                                break;
                                                }



                                            }else{

                                                FILE *outptr;
                                                        char out_Name[30];
                                                        strcpy(out_Name,"output");
                                                        strcat(out_Name,nkt_Files[p]);
                                                        outptr=fopen(out_Name,"a");
                                                        fprintf(outptr,"\nFaulty file\n");

                                                                fclose(outptr);
                                //printf("\nFaulty file\n");

                                            break;
                                            }

                                        }else{
                                        //x y z kodlari buraya
                                        printf("\nThis is X Y Z\n");
                                        int n;
                                        for(n=0;n<50;n++){
                                                        if(strcmp(files_Controls[n],"DATA")==0){
                                                            if(strcmp(files_Controls[n+1],data_Type_Ascii)==0){
                                                                printf("\nThis file is ASCII\n");
                                                                //x y z ascii kodlari buraya
                                                                fclose(fptr);
                                                                fptr=fopen(nkt_Files[p],"r");
                                                                //fseek(fptr,74,SEEK_SET);
                                                                int counter2=0,m;
                                                                //printf("%ld\n",ftell(fptr));

                                                                char words[900][20];
                                                                int words_Counter=0;

                                                                while(!feof(fptr)){
                                                                    fscanf(fptr,"%s",&words[words_Counter]);


                                                                    if(strcmp(words[words_Counter],"ascii")==0){
                                                                        break;

                                                                    }
                                                                    words_Counter++;



                                                                }
                                                                //printf("TEST%d",words_Counter);


                                                                while(!feof(fptr)){
                                                                    fscanf(fptr,"%lf %lf %lf",&points1[counter2].x1,&points1[counter2].y1,&points1[counter2].z1);

                                                                    counter2++;

                                                                }
                                                                //printf("\nTEST%s\n",nkt_Files[p]);
                                                                //printf("\nnokta sayısı: %d\n",counter2);
                                                                //printf("\nnokta sayısı: %s\n",files_Controls[11]);

                                                                if(counter2!=atoi(files_Controls[11])){
                                                                        FILE *outptr;
                                                                    char out_Name[30];
                                                                    strcpy(out_Name,"output");
                                                                    strcat(out_Name,nkt_Files[p]);
                                                                    outptr=fopen(out_Name,"a");
                                                                    fprintf(outptr,"\nSecim 1\n nokta sayisi gecerli degildir \n");
                                                                    fclose(outptr);

                                                                }





                                                                /*FILE *outptr;
                                                                char out_Name[30];
                                                                strcpy(out_Name,"output");
                                                                strcat(out_Name,nkt_Files[p]);
                                                                outptr=fopen(out_Name,"a");

                                                                fclose(outptr);*/









                                                            break;
                                                            }else if(strcmp(files_Controls[n+1],data_Type_Binary)==0){
                                                                printf("\nThis file is Binary\n");
                                                                //x y z binary kodlari buraya
                                                                fclose(fptr);
                                                                fptr=fopen(nkt_Files[p],"rb");

                                                                int binary_Word_Counter=0,search_Counter=0;
                                                                char ch;
                                                                while(!feof(fptr)){
                                                                    ch=fgetc(fptr);
                                                                    if(ch=='y'){
                                                                        search_Counter++;
                                                                    }
                                                                    if(search_Counter==3){
                                                                        break;
                                                                    }
                                                                    binary_Word_Counter++;

                                                                }
                                                                binary_Word_Counter=binary_Word_Counter+2;
                                                                //printf("binarywordc %d",binary_Word_Counter);


                                                                fseek(fptr,binary_Word_Counter,SEEK_SET);

                                                                /*char words[900][20];
                                                                int words_Counter=0;

                                                                while(!feof(fptr)){
                                                                    fscanf(fptr,"%s",&words[words_Counter]);


                                                                    if(strcmp(words[words_Counter],"binary")==0){
                                                                        break;

                                                                    }
                                                                    words_Counter++;



                                                                }
                                                                printf("TEST%d",words_Counter);*/


                                                                int counter7=0;
                                                                while(!feof(fptr)){

                                                                    fread(&binpoints1[counter7].binx1,sizeof(float),1,fptr);
                                                                    fread(&binpoints1[counter7].biny1,sizeof(float),1,fptr);
                                                                    fread(&binpoints1[counter7].binz1,sizeof(float),1,fptr);
                                                                    //printf("binary--> x:%f y:%f z:%f\n",binpoints1[counter7].binx1,binpoints1[counter7].biny1,binpoints1[counter7].binz1);
                                                                    counter7++;


                                                                }
                                                                //printf("\nnokta sayısı: %d\n",counter7);
                                                                //printf("\nnokta sayısı: %s\n",files_Controls[11]);
                                                                int counter8;


                                                                if(counter7-1!=atoi(files_Controls[11])){
                                                                        FILE *outptr;
                                                                    char out_Name[30];
                                                                    strcpy(out_Name,"output");
                                                                    strcat(out_Name,nkt_Files[p]);
                                                                    outptr=fopen(out_Name,"a");
                                                                    fprintf(outptr,"\nSecim 1\n nokta sayisi gecerli degildir \n");
                                                                    fclose(outptr);

                                                                }

                                                                /*for(counter8=0;counter8<counter7-1;counter8++){
                                                                    printf("binary--> x:%f y:%f z:%f\n",binpoints1[counter8].binx1,binpoints1[counter8].biny1,binpoints1[counter8].binz1);
                                                                }*/

                                                                /*FILE *outptr;
                                                                char out_Name[30];
                                                                strcpy(out_Name,"output");
                                                                strcat(out_Name,nkt_Files[p]);
                                                                outptr=fopen(out_Name,"a");

                                                                fclose(outptr);*/











                                                                break;
                                                            }else{
                                                            break;
                                                            }

                                                        }


                                                    }



                                        break;
                                        }

                                    }else{
                                        FILE *outptr;
                                                        char out_Name[30];
                                                        strcpy(out_Name,"output");
                                                        strcat(out_Name,nkt_Files[p]);
                                                        outptr=fopen(out_Name,"a");
                                                        fprintf(outptr,"\nFaulty file\n");

                                                                fclose(outptr);
                                //printf("\nFaulty file\n");




                                    break;
                                    }

                                }else{
                                    FILE *outptr;
                                                        char out_Name[30];
                                                        strcpy(out_Name,"output");
                                                        strcat(out_Name,nkt_Files[p]);
                                                        outptr=fopen(out_Name,"a");
                                                        fprintf(outptr,"\nFaulty file\n");

                                                                fclose(outptr);
                                //printf("\nFaulty file\n");



                                break;
                                }

                            }else{
                                                        FILE *outptr;
                                                        char out_Name[30];
                                                        strcpy(out_Name,"output");
                                                        strcat(out_Name,nkt_Files[p]);
                                                        outptr=fopen(out_Name,"a");
                                                        fprintf(outptr,"\nFaulty file\n");

                                                                fclose(outptr);
                                //printf("\nFaulty file\n");
                            break;
                            }

                        }









                }







                }else{
                printf("file can't open\n");
            }








            fclose(fptr);




     }







        break;

        case 2:

    for(p=0;p<nkt_Counts;p++){

        fptr=fopen(nkt_Files[p],"r");
        printf("\n\n\n");

        if(fptr!=NULL){
                free(files_Controls);

            for(j=0;j<17;j++){
                fscanf(fptr,"%s",files_Controls[j]);
                printf("%s",files_Controls[j]);
                }
                if( strcmp(files_Controls[0],"#") ==0 && strcmp(files_Controls[1],"Noktalar")==0 && strcmp(files_Controls[2],"dosya")==0 && strcmp(files_Controls[3],"format")==0 && strcmp(files_Controls[4],"VERSION")==0 && strcmp(files_Controls[5],"1")==0 && strcmp(files_Controls[6],"ALANLAR")==0 && strcmp(files_Controls[7],"x")==0 && strcmp(files_Controls[8],"y")==0 && strcmp(files_Controls[9],"z")==0 && strcmp(files_Controls[10],"r")==0 && strcmp(files_Controls[11],"g")==0 && strcmp(files_Controls[12],"b")==0 && strcmp(files_Controls[13],"NOKTALAR")==0 && strcmp(files_Controls[15],"DATA")==0 && strcmp(files_Controls[16],"ascii")==0   )  {
                  //  printf("\n**BASARILI**\n");
                }

                else if( strcmp(files_Controls[0],"#") ==0 && strcmp(files_Controls[1],"Noktalar")==0 && strcmp(files_Controls[2],"dosya")==0 && strcmp(files_Controls[3],"format")==0 && strcmp(files_Controls[4],"VERSION")==0 && strcmp(files_Controls[5],"1")==0 && strcmp(files_Controls[6],"ALANLAR")==0 && strcmp(files_Controls[7],"x")==0 && strcmp(files_Controls[8],"y")==0 && strcmp(files_Controls[9],"z")==0 && strcmp(files_Controls[10],"r")==0 && strcmp(files_Controls[11],"g")==0 && strcmp(files_Controls[12],"b")==0 && strcmp(files_Controls[13],"NOKTALAR")==0 && strcmp(files_Controls[15],"DATA")==0 && strcmp(files_Controls[16],"binary")==0   )  {

                //printf("\n**BASARILI**\n");
                }
                else if( strcmp(files_Controls[0],"#") ==0 && strcmp(files_Controls[1],"Noktalar")==0 && strcmp(files_Controls[2],"dosya")==0 && strcmp(files_Controls[3],"format")==0 && strcmp(files_Controls[4],"VERSION")==0 && strcmp(files_Controls[5],"1")==0 && strcmp(files_Controls[6],"ALANLAR")==0 && strcmp(files_Controls[7],"x")==0 && strcmp(files_Controls[8],"y")==0 && strcmp(files_Controls[9],"z")==0 && strcmp(files_Controls[10],"NOKTALAR")==0 && strcmp(files_Controls[12],"DATA")==0 && strcmp(files_Controls[13],"ascii")==0   )  {

                //printf("\n**BASARILI**\n");
                }
                else if( strcmp(files_Controls[0],"#") ==0 && strcmp(files_Controls[1],"Noktalar")==0 && strcmp(files_Controls[2],"dosya")==0 && strcmp(files_Controls[3],"format")==0 && strcmp(files_Controls[4],"VERSION")==0 && strcmp(files_Controls[5],"1")==0 && strcmp(files_Controls[6],"ALANLAR")==0 && strcmp(files_Controls[7],"x")==0 && strcmp(files_Controls[8],"y")==0 && strcmp(files_Controls[9],"z")==0 &&  strcmp(files_Controls[10],"NOKTALAR")==0 && strcmp(files_Controls[12],"DATA")==0 && strcmp(files_Controls[13],"binary")==0   )  {

                //printf("\n**BASARILI**\n");
                }else{
                    FILE *outptr;
                                                                char out_Name[30];
                                                                strcpy(out_Name,"output");
                                                                strcat(out_Name,nkt_Files[p]);
                                                                outptr=fopen(out_Name,"a");
                                                                fprintf(outptr,"\nSecim 2\nUyusmayan format\n");

                                                                fclose(outptr);

                continue;

                }






            for(j=0;j<50;j++){

                if(strcmp(files_Controls[j],"ALANLAR")==0){
                        if(strcmp(files_Controls[j+1],"x")==0){
                        printf("X IS HERE ");
                            if(strcmp(files_Controls[j+2],"y")==0){
                            printf("Y IS HERE ");
                                if(strcmp(files_Controls[j+3],"z")==0){
                                printf("Z IS HERE ");
                                    if(strcmp(files_Controls[j+4],"r")==0){
                                    printf("R IS HERE ");
                                        if(strcmp(files_Controls[j+5],"g")==0){
                                            printf("G IS HERE ");
                                                if(strcmp(files_Controls[j+6],"b")==0){
                                                printf("B IS HERE ");
                                                //x y z r g b kodlari buraya
                                                printf("\nThis is X Y Z R G B\n");
                                                int t;
                                                    for(t=0;t<50;t++){
                                                        if(strcmp(files_Controls[t],"DATA")==0){
                                                            if(strcmp(files_Controls[t+1],data_Type_Ascii)==0){
                                                                printf("\nThis file is ASCII\n");
                                                                //x y z r g b ascii kodlari buraya
                                                                fclose(fptr);
                                                                fptr=fopen(nkt_Files[p],"r");
                                                                int y=0,u,counter=0;
                                                                //fseek(fptr,79,SEEK_SET);
                                                                //printf("%ld\n",ftell(fptr));

                                                                char words[900][20];
                                                                int words_Counter=0;

                                                                while(!feof(fptr)){
                                                                    fscanf(fptr,"%s",&words[words_Counter]);


                                                                    if(strcmp(words[words_Counter],"ascii")==0){
                                                                        break;

                                                                    }
                                                                    words_Counter++;



                                                                }
                                                                //printf("TEST%d",words_Counter);

                                                                while(!feof(fptr)){
                                                                    fscanf(fptr,"%lf %lf %lf",&points2[y].x2,&points2[y].y2,&points2[y].z2);
                                                                    fscanf(fptr,"%d %d %d",&points2[y].r,&points2[y].g,&points2[y].b);
                                                                    y++;

                                                                }


                                                                /*for(u=0;u<y-1;u++){
                                                                    printf("%lf %lf %lf ",points2[u].x2,points2[u].y2,points2[u].z2);
                                                                    printf("%d %d %d\n",points2[u].r,points2[u].g,points2[u].b);

                                                                }*/
                                                                double max_Distance,min_Distance;
                                                                int max_Distance_i,max_Distance_i2,min_Distance_i,min_Distance_i2;
                                                                max_Distance=sqrt( ((points2[0].x2-points2[1].x2)* (points2[0].x2-points2[1].x2))+ ((points2[0].y2-points2[1].y2)*(points2[0].y2-points2[1].y2))+((points2[0].z2-points2[1].z2)*(points2[0].z2-points2[1].z2))    );
                                                                min_Distance=sqrt( ((points2[0].x2-points2[1].x2)* (points2[0].x2-points2[1].x2))+ ((points2[0].y2-points2[1].y2)*(points2[0].y2-points2[1].y2))+((points2[0].z2-points2[1].z2)*(points2[0].z2-points2[1].z2))    );
                                                                int counter5,counter6;
                                                               // printf("first max distance: %lf\n",max_Distance);
                                                                //printf("first min distance: %lf\n",min_Distance);
                                                                for(counter5=0;counter5<y;counter5++){
                                                                    for(counter6=counter5+1;counter6<y;counter6++){
                                                                            if(max_Distance<sqrt( ((points2[counter5].x2-points2[counter6].x2)* (points2[counter5].x2-points2[counter6].x2))+ ((points2[counter5].y2-points2[counter6].y2)*(points2[counter5].y2-points2[counter6].y2))+((points2[counter5].z2-points2[counter6].z2)*(points2[counter5].z2-points2[counter6].z2)) )){
                                                                            max_Distance=sqrt( ((points2[counter5].x2-points2[counter6].x2)* (points2[counter5].x2-points2[counter6].x2))+ ((points2[counter5].y2-points2[counter6].y2)*(points2[counter5].y2-points2[counter6].y2))+((points2[counter5].z2-points2[counter6].z2)*(points2[counter5].z2-points2[counter6].z2)) );
                                                                            //printf("max distance: %lf\n",max_Distance);
                                                                            max_Distance_i=counter5;
                                                                            max_Distance_i2=counter6;
                                                                            }
                                                                            if(min_Distance>sqrt( ((points2[counter5].x2-points2[counter6].x2)* (points2[counter5].x2-points2[counter6].x2))+ ((points2[counter5].y2-points2[counter6].y2)*(points2[counter5].y2-points2[counter6].y2))+((points2[counter5].z2-points2[counter6].z2)*(points2[counter5].z2-points2[counter6].z2)) )){
                                                                            min_Distance=sqrt( ((points2[counter5].x2-points2[counter6].x2)* (points2[counter5].x2-points2[counter6].x2))+ ((points2[counter5].y2-points2[counter6].y2)*(points2[counter5].y2-points2[counter6].y2))+((points2[counter5].z2-points2[counter6].z2)*(points2[counter5].z2-points2[counter6].z2)) );
                                                                            //printf("min distance: %lf \n",min_Distance);
                                                                            min_Distance_i=counter5;
                                                                            min_Distance_i2=counter6;
                                                                            }

                                                                    }

                                                                }
                                                                FILE *outptr;
                                                                char out_Name[30];
                                                                strcpy(out_Name,"output");
                                                                strcat(out_Name,nkt_Files[p]);
                                                                outptr=fopen(out_Name,"a");
                                                                fprintf(outptr,"\nSecim 2\nFarthest points informations\n %d.Line x:%lf y:%lf z:%lf and %d.Line x:%lf y:%lf z:%lf\n",max_Distance_i,points2[max_Distance_i].x2,points2[max_Distance_i].y2,points2[max_Distance_i].z2,max_Distance_i2,points2[max_Distance_i2].x2,points2[max_Distance_i2].y2,points2[max_Distance_i2].z2);
                                                                fprintf(outptr,"Closest points informations\n %d.Line x:%lf y:%lf z:%lf and %d.Line x:%lf y:%lf z:%lf\n",min_Distance_i,points2[min_Distance_i].x2,points2[min_Distance_i].y2,points2[min_Distance_i].z2,min_Distance_i2,points2[min_Distance_i2].x2,points2[min_Distance_i2].y2,points2[min_Distance_i2].z2);
                                                                fclose(outptr);

                                                                //printf("\ny: %d\n",y);
                                                                counter=y-1;
                                                                u=0;



















                                                                break;
                                                            }else if(strcmp(files_Controls[t+1],data_Type_Binary)==0){
                                                                printf("\nThis file is Binary\n");
                                                                //x y z r g b binary kodlari buraya
                                                                fclose(fptr);
                                                                fptr=fopen(nkt_Files[p],"rb");
                                                                int binary_Word_Counter=0,search_Counter=0;
                                                                char ch;
                                                                while(!feof(fptr)){
                                                                    ch=fgetc(fptr);
                                                                    if(ch=='y'){
                                                                        search_Counter++;
                                                                    }
                                                                    if(search_Counter==3){
                                                                        break;
                                                                    }
                                                                    binary_Word_Counter++;

                                                                }
                                                                binary_Word_Counter=binary_Word_Counter+2;
                                                                //printf("binarywordc %d",binary_Word_Counter);


                                                                fseek(fptr,binary_Word_Counter,SEEK_SET);






                                                                int counter7=0,counter8;
                                                                while(!feof(fptr)){

                                                                    fread(&binpoints2[counter7].binx2,sizeof(float),1,fptr);
                                                                    fread(&binpoints2[counter7].biny2,sizeof(float),1,fptr);
                                                                    fread(&binpoints2[counter7].binz2,sizeof(float),1,fptr);
                                                                    fread(&binpoints2[counter7].binr,sizeof(int),1,fptr);
                                                                    fread(&binpoints2[counter7].bing,sizeof(int),1,fptr);
                                                                    fread(&binpoints2[counter7].binb,sizeof(int),1,fptr);

                                                                    counter7++;


                                                                }
                                                                 /*for(counter8=0;counter8<counter7-1;counter8++){
                                                                    printf("binary--> x:%f y:%f z:%f r:%d g:%d b:%d\n",binpoints2[counter8].binx2,binpoints2[counter8].biny2,binpoints2[counter8].binz2,binpoints2[counter8].binr,binpoints2[counter8].bing,binpoints2[counter8].binb);
                                                                }*/
                                                                double max_Distance,min_Distance;
                                                                int max_Distance_i,max_Distance_i2,min_Distance_i,min_Distance_i2;
                                                                max_Distance=sqrt( ((binpoints2[0].binx2-binpoints2[1].binx2)* (binpoints2[0].binx2-binpoints2[1].binx2))+ ((binpoints2[0].biny2-binpoints2[1].biny2)*(binpoints2[0].biny2-binpoints2[1].biny2))+((binpoints2[0].binz2-binpoints2[1].binz2)*(binpoints2[0].binz2-binpoints2[1].binz2))    );
                                                                min_Distance=sqrt( ((binpoints2[0].binx2-binpoints2[1].binx2)* (binpoints2[0].binx2-binpoints2[1].binx2))+ ((binpoints2[0].biny2-binpoints2[1].biny2)*(binpoints2[0].biny2-binpoints2[1].biny2))+((binpoints2[0].binz2-binpoints2[1].binz2)*(binpoints2[0].binz2-binpoints2[1].binz2))    );
                                                                int counter5,counter6;

                                                               // printf("first max distance: %lf\n",max_Distance);
                                                                //printf("first min distance: %lf\n",min_Distance);
                                                                for(counter5=0;counter5<counter7-1;counter5++){
                                                                    for(counter6=counter5+1;counter6<counter7-1;counter6++){
                                                                            if(max_Distance<sqrt( ((binpoints2[counter5].binx2-binpoints2[counter6].binx2)* (binpoints2[counter5].binx2-binpoints2[counter6].binx2))+ ((binpoints2[counter5].biny2-binpoints2[counter6].biny2)*(binpoints2[counter5].biny2-binpoints2[counter6].biny2))+((binpoints2[counter5].binz2-binpoints2[counter6].binz2)*(binpoints2[counter5].binz2-binpoints2[counter6].binz2)) )){
                                                                            max_Distance=sqrt( ((binpoints2[counter5].binx2-binpoints2[counter6].binx2)* (binpoints2[counter5].binx2-binpoints2[counter6].binx2))+ ((binpoints2[counter5].biny2-binpoints2[counter6].biny2)*(binpoints2[counter5].biny2-binpoints2[counter6].biny2))+((binpoints2[counter5].binz2-binpoints2[counter6].binz2)*(binpoints2[counter5].binz2-binpoints2[counter6].binz2)) );
                                                                            //printf("max distance: %lf\n",max_Distance);
                                                                            max_Distance_i=counter5;
                                                                            max_Distance_i2=counter6;
                                                                            }
                                                                            if(min_Distance>sqrt( ((binpoints2[counter5].binx2-binpoints2[counter6].binx2)* (binpoints2[counter5].binx2-binpoints2[counter6].binx2))+ ((binpoints2[counter5].biny2-binpoints2[counter6].biny2)*(binpoints2[counter5].biny2-binpoints2[counter6].biny2))+((binpoints2[counter5].binz2-binpoints2[counter6].binz2)*(binpoints2[counter5].binz2-binpoints2[counter6].binz2)) )){
                                                                            min_Distance=sqrt( ((binpoints2[counter5].binx2-binpoints2[counter6].binx2)* (binpoints2[counter5].binx2-binpoints2[counter6].binx2))+ ((binpoints2[counter5].biny2-binpoints2[counter6].biny2)*(binpoints2[counter5].biny2-binpoints2[counter6].biny2))+((binpoints2[counter5].binz2-binpoints2[counter6].binz2)*(binpoints2[counter5].binz2-binpoints2[counter6].binz2)) );
                                                                            //printf("min distance: %lf \n",min_Distance);
                                                                            min_Distance_i=counter5;
                                                                            min_Distance_i2=counter6;
                                                                            }

                                                                    }

                                                                }
                                                                FILE *outptr;
                                                                char out_Name[30];
                                                                strcpy(out_Name,"output");
                                                                strcat(out_Name,nkt_Files[p]);
                                                                outptr=fopen(out_Name,"a");
                                                                fprintf(outptr,"\nSecim 2\nFarthest points informations\n %d.Line x:%lf y:%lf z:%lf r:%d g:%d b:%d and %d.Line x:%lf y:%lf z:%lf r:%d g:%d b:%d\n",max_Distance_i,binpoints2[max_Distance_i].binx2,binpoints2[max_Distance_i].biny2,binpoints2[max_Distance_i].binz2,binpoints2[max_Distance_i].binr,binpoints2[max_Distance_i].bing,binpoints2[max_Distance_i].binb,max_Distance_i2,binpoints2[max_Distance_i2].binx2,binpoints2[max_Distance_i2].biny2,binpoints2[max_Distance_i2].binz2,binpoints2[max_Distance_i2].binr,binpoints2[max_Distance_i2].bing,binpoints2[max_Distance_i2].binb);
                                                                fprintf(outptr,"Closest points informations\n %d.Line x:%lf y:%lf z:%lf r:%d g:%d b:%d and %d.Line x:%lf y:%lf z:%lf r:%d g:%d b:%d\n",min_Distance_i,binpoints2[min_Distance_i].binx2,binpoints2[min_Distance_i].biny2,binpoints2[min_Distance_i].binz2,binpoints2[min_Distance_i].binr,binpoints2[min_Distance_i].bing,binpoints2[min_Distance_i].binb,min_Distance_i2,binpoints2[min_Distance_i2].binx2,binpoints2[min_Distance_i2].biny2,binpoints2[min_Distance_i2].binz2,binpoints2[min_Distance_i2].binr,binpoints2[min_Distance_i2].bing,binpoints2[min_Distance_i2].binb);
                                                                fclose(outptr);







                                                                break;

                                                            }else{
                                                            break;
                                                            }

                                                        }


                                                    }



                                                    break;


                                                }else{
                                                break;
                                                }



                                            }else{
                                            break;
                                            }

                                        }else{
                                        //x y z kodlari buraya
                                        printf("\nThis is X Y Z\n");
                                        int n;
                                        for(n=0;n<50;n++){
                                                        if(strcmp(files_Controls[n],"DATA")==0){
                                                            if(strcmp(files_Controls[n+1],data_Type_Ascii)==0){
                                                                printf("\nThis file is ASCII\n");
                                                                //x y z ascii kodlari buraya
                                                                fclose(fptr);
                                                                fptr=fopen(nkt_Files[p],"r");
                                                                //fseek(fptr,74,SEEK_SET);
                                                                int counter2=0,m;
                                                                //printf("%ld\n",ftell(fptr));


                                                                char words[900][20];
                                                                int words_Counter=0;

                                                                while(!feof(fptr)){
                                                                    fscanf(fptr,"%s",&words[words_Counter]);


                                                                    if(strcmp(words[words_Counter],"ascii")==0){
                                                                        break;

                                                                    }
                                                                    words_Counter++;



                                                                }
                                                                //printf("TEST%d",words_Counter);


                                                                while(!feof(fptr)){
                                                                    fscanf(fptr,"%lf %lf %lf",&points1[counter2].x1,&points1[counter2].y1,&points1[counter2].z1);

                                                                    counter2++;

                                                                }

                                                                int counter4=0,up2=0;
                                                                double max_Distance,min_Distance;
                                                                int max_Distance_i,max_Distance_i2,min_Distance_i,min_Distance_i2;
                                                                max_Distance=sqrt( ((points1[0].x1-points1[1].x1)* (points1[0].x1-points1[1].x1))+ ((points1[0].y1-points1[1].y1)*(points1[0].y1-points1[1].y1))+((points1[0].z1-points1[1].z1)*(points1[0].z1-points1[1].z1))    );
                                                                min_Distance=sqrt( ((points1[0].x1-points1[1].x1)* (points1[0].x1-points1[1].x1))+ ((points1[0].y1-points1[1].y1)*(points1[0].y1-points1[1].y1))+((points1[0].z1-points1[1].z1)*(points1[0].z1-points1[1].z1))    );
                                                                int counter5,counter6;

                                                               // printf("first max distance: %lf\n",max_Distance);
                                                                //printf("first min distance: %lf\n",min_Distance);
                                                                for(counter5=0;counter5<counter2;counter5++){
                                                                    for(counter6=counter5+1;counter6<counter2;counter6++){
                                                                            if(max_Distance<sqrt( ((points1[counter5].x1-points1[counter6].x1)* (points1[counter5].x1-points1[counter6].x1))+ ((points1[counter5].y1-points1[counter6].y1)*(points1[counter5].y1-points1[counter6].y1))+((points1[counter5].z1-points1[counter6].z1)*(points1[counter5].z1-points1[counter6].z1)) )){
                                                                            max_Distance=sqrt( ((points1[counter5].x1-points1[counter6].x1)* (points1[counter5].x1-points1[counter6].x1))+ ((points1[counter5].y1-points1[counter6].y1)*(points1[counter5].y1-points1[counter6].y1))+((points1[counter5].z1-points1[counter6].z1)*(points1[counter5].z1-points1[counter6].z1)) );
                                                                            //printf("max distance: %lf\n",max_Distance);
                                                                            max_Distance_i=counter5;
                                                                            max_Distance_i2=counter6;
                                                                            }
                                                                            if(min_Distance>sqrt( ((points1[counter5].x1-points1[counter6].x1)* (points1[counter5].x1-points1[counter6].x1))+ ((points1[counter5].y1-points1[counter6].y1)*(points1[counter5].y1-points1[counter6].y1))+((points1[counter5].z1-points1[counter6].z1)*(points1[counter5].z1-points1[counter6].z1)) )){
                                                                            min_Distance=sqrt( ((points1[counter5].x1-points1[counter6].x1)* (points1[counter5].x1-points1[counter6].x1))+ ((points1[counter5].y1-points1[counter6].y1)*(points1[counter5].y1-points1[counter6].y1))+((points1[counter5].z1-points1[counter6].z1)*(points1[counter5].z1-points1[counter6].z1)) );
                                                                            //printf("min distance: %lf \n",min_Distance);
                                                                            min_Distance_i=counter5;
                                                                            min_Distance_i2=counter6;
                                                                            }

                                                                    }

                                                                }
                                                                FILE *outptr;
                                                                char out_Name[30];
                                                                strcpy(out_Name,"output");
                                                                strcat(out_Name,nkt_Files[p]);
                                                                outptr=fopen(out_Name,"a");
                                                                fprintf(outptr,"\nSecim 2\nFarthest points informations\n %d.Line x:%lf y:%lf z:%lf and %d.Line x:%lf y:%lf z:%lf\n",max_Distance_i,points1[max_Distance_i].x1,points1[max_Distance_i].y1,points1[max_Distance_i].z1,max_Distance_i2,points1[max_Distance_i2].x1,points1[max_Distance_i2].y1,points1[max_Distance_i2].z1);
                                                                fprintf(outptr,"Closest points informations\n %d.Line x:%lf y:%lf z:%lf and %d.Line x:%lf y:%lf z:%lf\n",min_Distance_i,points1[min_Distance_i].x1,points1[min_Distance_i].y1,points1[min_Distance_i].z1,min_Distance_i2,points1[min_Distance_i2].x1,points1[min_Distance_i2].y1,points1[min_Distance_i2].z1);
                                                                fclose(outptr);









                                                                break;
                                                            }else if(strcmp(files_Controls[n+1],data_Type_Binary)==0){
                                                                printf("\nThis file is Binary\n");
                                                                //x y z binary kodlari buraya
                                                                fclose(fptr);
                                                                fptr=fopen(nkt_Files[p],"rb");

                                                                int binary_Word_Counter=0,search_Counter=0;
                                                                char ch;
                                                                while(!feof(fptr)){
                                                                    ch=fgetc(fptr);
                                                                    if(ch=='y'){
                                                                        search_Counter++;
                                                                    }
                                                                    if(search_Counter==3){
                                                                        break;
                                                                    }
                                                                    binary_Word_Counter++;

                                                                }
                                                                binary_Word_Counter=binary_Word_Counter+2;
                                                                //printf("binarywordc %d",binary_Word_Counter);


                                                                fseek(fptr,binary_Word_Counter,SEEK_SET);


                                                                int counter7=0;
                                                                while(!feof(fptr)){

                                                                    fread(&binpoints1[counter7].binx1,sizeof(float),1,fptr);
                                                                    fread(&binpoints1[counter7].biny1,sizeof(float),1,fptr);
                                                                    fread(&binpoints1[counter7].binz1,sizeof(float),1,fptr);
                                                                    counter7++;


                                                                }
                                                                int counter8;
                                                               /* for(counter8=0;counter8<counter7-1;counter8++){
                                                                    printf("binary--> x:%f y:%f z:%f\n",binpoints1[counter8].binx1,binpoints1[counter8].biny1,binpoints1[counter8].binz1);
                                                                }*/
                                                                double max_Distance,min_Distance;
                                                                int max_Distance_i,max_Distance_i2,min_Distance_i,min_Distance_i2;
                                                                max_Distance=sqrt( ((binpoints1[0].binx1-binpoints1[1].binx1)* (binpoints1[0].binx1-binpoints1[1].binx1))+ ((binpoints1[0].biny1-binpoints1[1].biny1)*(binpoints1[0].biny1-binpoints1[1].biny1))+((binpoints1[0].binz1-binpoints1[1].binz1)*(binpoints1[0].binz1-binpoints1[1].binz1))    );
                                                                min_Distance=sqrt( ((binpoints1[0].binx1-binpoints1[1].binx1)* (binpoints1[0].binx1-binpoints1[1].binx1))+ ((binpoints1[0].biny1-binpoints1[1].biny1)*(binpoints1[0].biny1-binpoints1[1].biny1))+((binpoints1[0].binz1-binpoints1[1].binz1)*(binpoints1[0].binz1-binpoints1[1].binz1))    );
                                                                int counter5,counter6;

                                                               // printf("first max distance: %lf\n",max_Distance);
                                                                //printf("first min distance: %lf\n",min_Distance);
                                                                for(counter5=0;counter5<counter7-1;counter5++){
                                                                    for(counter6=counter5+1;counter6<counter7-1;counter6++){
                                                                            if(max_Distance<sqrt( ((binpoints1[counter5].binx1-binpoints1[counter6].binx1)* (binpoints1[counter5].binx1-binpoints1[counter6].binx1))+ ((binpoints1[counter5].biny1-binpoints1[counter6].biny1)*(binpoints1[counter5].biny1-binpoints1[counter6].biny1))+((binpoints1[counter5].binz1-binpoints1[counter6].binz1)*(binpoints1[counter5].binz1-binpoints1[counter6].binz1)) )){
                                                                            max_Distance=sqrt( ((binpoints1[counter5].binx1-binpoints1[counter6].binx1)* (binpoints1[counter5].binx1-binpoints1[counter6].binx1))+ ((binpoints1[counter5].biny1-binpoints1[counter6].biny1)*(binpoints1[counter5].biny1-binpoints1[counter6].biny1))+((binpoints1[counter5].binz1-binpoints1[counter6].binz1)*(binpoints1[counter5].binz1-binpoints1[counter6].binz1)) );
                                                                            //printf("max distance: %lf\n",max_Distance);
                                                                            max_Distance_i=counter5;
                                                                            max_Distance_i2=counter6;
                                                                            }
                                                                            if(min_Distance>sqrt( ((binpoints1[counter5].binx1-binpoints1[counter6].binx1)* (binpoints1[counter5].binx1-binpoints1[counter6].binx1))+ ((binpoints1[counter5].biny1-binpoints1[counter6].biny1)*(binpoints1[counter5].biny1-binpoints1[counter6].biny1))+((binpoints1[counter5].binz1-binpoints1[counter6].binz1)*(binpoints1[counter5].binz1-binpoints1[counter6].binz1)) )){
                                                                            min_Distance=sqrt( ((binpoints1[counter5].binx1-binpoints1[counter6].binx1)* (binpoints1[counter5].binx1-binpoints1[counter6].binx1))+ ((binpoints1[counter5].biny1-binpoints1[counter6].biny1)*(binpoints1[counter5].biny1-binpoints1[counter6].biny1))+((binpoints1[counter5].binz1-binpoints1[counter6].binz1)*(binpoints1[counter5].binz1-binpoints1[counter6].binz1)) );
                                                                            //printf("min distance: %lf \n",min_Distance);
                                                                            min_Distance_i=counter5;
                                                                            min_Distance_i2=counter6;
                                                                            }

                                                                    }

                                                                }
                                                                FILE *outptr;
                                                                char out_Name[30];
                                                                strcpy(out_Name,"output");
                                                                strcat(out_Name,nkt_Files[p]);
                                                                outptr=fopen(out_Name,"a");
                                                                fprintf(outptr,"\nSecim 2\nFarthest points informations\n %d.Line x:%lf y:%lf z:%lf and %d.Line x:%lf y:%lf z:%lf\n",max_Distance_i,binpoints1[max_Distance_i].binx1,binpoints1[max_Distance_i].biny1,binpoints1[max_Distance_i].binz1,max_Distance_i2,binpoints1[max_Distance_i2].binx1,binpoints1[max_Distance_i2].biny1,binpoints1[max_Distance_i2].binz1);
                                                                fprintf(outptr,"Closest points informations\n %d.Line x:%lf y:%lf z:%lf and %d.Line x:%lf y:%lf z:%lf\n",min_Distance_i,binpoints1[min_Distance_i].binx1,binpoints1[min_Distance_i].biny1,binpoints1[min_Distance_i].binz1,min_Distance_i2,binpoints1[min_Distance_i2].binx1,binpoints1[min_Distance_i2].biny1,binpoints1[min_Distance_i2].binz1);
                                                                fclose(outptr);










                                                                break;

                                                            }else{
                                                            break;
                                                            }

                                                        }


                                                    }



                                        break;
                                        }

                                    }else{
                                    break;
                                    }

                                }else{
                                break;
                                }

                            }else{
                                //printf("\nFaulty file\n");
                            break;
                            }

                        }




                }







                }else{
                //printf("file can't open\n");
            }








            fclose(fptr);




     }
     choise=10;
     break;
        case 3:

            for(p=0;p<nkt_Counts;p++){


        fptr=fopen(nkt_Files[p],"r");
        printf("\n\n\n");

        if(fptr!=NULL){
                free(files_Controls);

            for(j=0;j<17;j++){
                fscanf(fptr,"%s",files_Controls[j]);
                printf("%s",files_Controls[j]);
                }

                if( strcmp(files_Controls[0],"#") ==0 && strcmp(files_Controls[1],"Noktalar")==0 && strcmp(files_Controls[2],"dosya")==0 && strcmp(files_Controls[3],"format")==0 && strcmp(files_Controls[4],"VERSION")==0 && strcmp(files_Controls[5],"1")==0 && strcmp(files_Controls[6],"ALANLAR")==0 && strcmp(files_Controls[7],"x")==0 && strcmp(files_Controls[8],"y")==0 && strcmp(files_Controls[9],"z")==0 && strcmp(files_Controls[10],"r")==0 && strcmp(files_Controls[11],"g")==0 && strcmp(files_Controls[12],"b")==0 && strcmp(files_Controls[13],"NOKTALAR")==0 && strcmp(files_Controls[15],"DATA")==0 && strcmp(files_Controls[16],"ascii")==0   )  {
                  //  printf("\n**BASARILI**\n");
                }

                else if( strcmp(files_Controls[0],"#") ==0 && strcmp(files_Controls[1],"Noktalar")==0 && strcmp(files_Controls[2],"dosya")==0 && strcmp(files_Controls[3],"format")==0 && strcmp(files_Controls[4],"VERSION")==0 && strcmp(files_Controls[5],"1")==0 && strcmp(files_Controls[6],"ALANLAR")==0 && strcmp(files_Controls[7],"x")==0 && strcmp(files_Controls[8],"y")==0 && strcmp(files_Controls[9],"z")==0 && strcmp(files_Controls[10],"r")==0 && strcmp(files_Controls[11],"g")==0 && strcmp(files_Controls[12],"b")==0 && strcmp(files_Controls[13],"NOKTALAR")==0 && strcmp(files_Controls[15],"DATA")==0 && strcmp(files_Controls[16],"binary")==0   )  {

                //printf("\n**BASARILI**\n");
                }
                else if( strcmp(files_Controls[0],"#") ==0 && strcmp(files_Controls[1],"Noktalar")==0 && strcmp(files_Controls[2],"dosya")==0 && strcmp(files_Controls[3],"format")==0 && strcmp(files_Controls[4],"VERSION")==0 && strcmp(files_Controls[5],"1")==0 && strcmp(files_Controls[6],"ALANLAR")==0 && strcmp(files_Controls[7],"x")==0 && strcmp(files_Controls[8],"y")==0 && strcmp(files_Controls[9],"z")==0 && strcmp(files_Controls[10],"NOKTALAR")==0 && strcmp(files_Controls[12],"DATA")==0 && strcmp(files_Controls[13],"ascii")==0   )  {

                //printf("\n**BASARILI**\n");
                }
                else if( strcmp(files_Controls[0],"#") ==0 && strcmp(files_Controls[1],"Noktalar")==0 && strcmp(files_Controls[2],"dosya")==0 && strcmp(files_Controls[3],"format")==0 && strcmp(files_Controls[4],"VERSION")==0 && strcmp(files_Controls[5],"1")==0 && strcmp(files_Controls[6],"ALANLAR")==0 && strcmp(files_Controls[7],"x")==0 && strcmp(files_Controls[8],"y")==0 && strcmp(files_Controls[9],"z")==0 &&  strcmp(files_Controls[10],"NOKTALAR")==0 && strcmp(files_Controls[12],"DATA")==0 && strcmp(files_Controls[13],"binary")==0   )  {

                //printf("\n**BASARILI**\n");
                }else{
                    FILE *outptr;
                                                                char out_Name[30];
                                                                strcpy(out_Name,"output");
                                                                strcat(out_Name,nkt_Files[p]);
                                                                outptr=fopen(out_Name,"a");
                                                                fprintf(outptr,"\nSecim 3\nUyusmayan format\n");

                                                                fclose(outptr);

                continue;

                }


            for(j=0;j<50;j++){

                if(strcmp(files_Controls[j],"ALANLAR")==0){
                        if(strcmp(files_Controls[j+1],"x")==0){
                        printf("X IS HERE ");
                            if(strcmp(files_Controls[j+2],"y")==0){
                            printf("Y IS HERE ");
                                if(strcmp(files_Controls[j+3],"z")==0){
                                printf("Z IS HERE ");
                                    if(strcmp(files_Controls[j+4],"r")==0){
                                    printf("R IS HERE ");
                                        if(strcmp(files_Controls[j+5],"g")==0){
                                            printf("G IS HERE ");
                                                if(strcmp(files_Controls[j+6],"b")==0){
                                                printf("B IS HERE ");
                                                //x y z r g b kodlari buraya
                                                printf("\nThis is X Y Z R G B\n");
                                                int t;
                                                    for(t=0;t<50;t++){
                                                        if(strcmp(files_Controls[t],"DATA")==0){
                                                            if(strcmp(files_Controls[t+1],data_Type_Ascii)==0){
                                                                printf("\nThis file is ASCII\n");
                                                                //x y z r g b ascii kodlari buraya
                                                                fclose(fptr);
                                                                fptr=fopen(nkt_Files[p],"r");
                                                                int y=0,u,counter=0;
                                                                //fseek(fptr,79,SEEK_SET);
                                                                //printf("%ld\n",ftell(fptr));

                                                                char words[900][20];
                                                                int words_Counter=0;

                                                                while(!feof(fptr)){
                                                                    fscanf(fptr,"%s",&words[words_Counter]);


                                                                    if(strcmp(words[words_Counter],"ascii")==0){
                                                                        break;

                                                                    }
                                                                    words_Counter++;



                                                                }
                                                                //printf("TEST%d",words_Counter);


                                                                while(!feof(fptr)){
                                                                    fscanf(fptr,"%lf %lf %lf",&points2[y].x2,&points2[y].y2,&points2[y].z2);
                                                                    fscanf(fptr,"%d %d %d",&points2[y].r,&points2[y].g,&points2[y].b);
                                                                    y++;

                                                                }


                                                                /*for(u=0;u<y-1;u++){
                                                                    printf("%lf %lf %lf ",points2[u].x2,points2[u].y2,points2[u].z2);
                                                                    printf("%d %d %d\n",points2[u].r,points2[u].g,points2[u].b);

                                                                }*/

                                                                double max_X,max_Y,max_Z,min_X,min_Y,min_Z,edge1,edge2,edge3;
                                                                max_X=points2[0].x2;
                                                                max_Y=points2[0].y2;
                                                                max_Z=points2[0].z2;
                                                                min_X=points2[0].x2;
                                                                min_Y=points2[0].y2;
                                                                min_Z=points2[0].z2;

                                                                for(u=0;u<y;u++){
                                                                        if(max_X<points2[u].x2){
                                                                                max_X=points2[u].x2;

                                                                        }
                                                                        if(max_Y<points2[u].y2){
                                                                            max_Y=points2[u].y2;
                                                                        }
                                                                        if(max_Z<points2[u].z2){
                                                                            max_Z=points2[u].z2;
                                                                        }
                                                                        if(min_X>points2[u].x2){
                                                                                min_X=points2[u].x2;

                                                                        }
                                                                        if(min_Y>points2[u].y2){
                                                                            min_Y=points2[u].y2;
                                                                        }
                                                                        if(min_Z>points2[u].z2){
                                                                            min_Z=points2[u].z2;
                                                                        }



                                                                }

                                                                edge1=max_X-min_X;
                                                                edge2=max_Y-min_Y;
                                                                edge3=max_Z-min_Z;
                                                                //printf("1:%lf 2:%lf 3:%lf\n",edge1,edge2,edge3);
                                                                double biggest_edge,min_Point_X,min_Point_Y,min_Point_Z;
                                                                min_Point_X=min_X;
                                                                min_Point_Y=min_Y;
                                                                min_Point_Z=min_Z;

                                                                if(edge1>=edge2 &&edge1>=edge3){
                                                                    biggest_edge=edge1;
                                                                }
                                                                if(edge2>=edge1 &&edge2>=edge3){
                                                                    biggest_edge=edge2;
                                                                }
                                                                if(edge3>=edge1 &&edge3>=edge2){
                                                                    biggest_edge=edge3;
                                                                }
                                                                //printf("biggest : %lf",biggest_edge);



                                                                corners[0].cx=min_Point_X;
                                                                corners[0].cy=min_Point_Y;
                                                                corners[0].cz=min_Point_Z;
                                                                corners[0].cr=255;
                                                                corners[0].cg=255;
                                                                corners[0].cb=255;

                                                                corners[1].cx=min_Point_X;
                                                                corners[1].cy=min_Point_Y+biggest_edge;
                                                                corners[1].cz=min_Point_Z;
                                                                corners[1].cr=255;
                                                                corners[1].cg=255;
                                                                corners[1].cb=255;

                                                                corners[2].cx=min_Point_X;
                                                                corners[2].cy=min_Point_Y;
                                                                corners[2].cz=min_Point_Z+biggest_edge;
                                                                corners[2].cr=255;
                                                                corners[2].cg=255;
                                                                corners[2].cb=255;


                                                                corners[3].cx=min_Point_X+biggest_edge;
                                                                corners[3].cy=min_Point_Y;
                                                                corners[3].cz=min_Point_Z;
                                                                corners[3].cr=255;
                                                                corners[3].cg=255;
                                                                corners[3].cb=255;

                                                                corners[4].cx=min_Point_X;
                                                                corners[4].cy=min_Point_Y+biggest_edge;
                                                                corners[4].cz=min_Point_Z+biggest_edge;
                                                                corners[4].cr=255;
                                                                corners[4].cg=255;
                                                                corners[4].cb=255;

                                                                corners[5].cx=min_Point_X+biggest_edge;
                                                                corners[5].cy=min_Point_Y;
                                                                corners[5].cz=min_Point_Z+biggest_edge;
                                                                corners[5].cr=255;
                                                                corners[5].cg=255;
                                                                corners[5].cb=255;

                                                                corners[6].cx=min_Point_X+biggest_edge;
                                                                corners[6].cy=min_Point_Y+biggest_edge;
                                                                corners[6].cz=min_Point_Z;
                                                                corners[6].cr=255;
                                                                corners[6].cg=255;
                                                                corners[6].cb=255;

                                                                corners[7].cx=min_Point_X+biggest_edge;
                                                                corners[7].cy=min_Point_Y+biggest_edge;
                                                                corners[7].cz=min_Point_Z+biggest_edge;
                                                                corners[7].cr=255;
                                                                corners[7].cg=255;
                                                                corners[7].cb=255;








                                                                FILE *outptr;
                                                                char out_Name[30];
                                                                strcpy(out_Name,"output");
                                                                strcat(out_Name,nkt_Files[p]);
                                                                outptr=fopen(out_Name,"a");
                                                                fprintf(outptr,"\nSecim 3\nButun noktalari kapsayan en kucuk kupun kose bilgileri\n");
                                                                int counter10;
                                                                for(counter10=0;counter10<8;counter10++){
                                                                    fprintf(outptr,"cx:%lf cy:%lf cz:%lf bincr:%d bincg:%d bincb:%d\n",corners[counter10].cx,corners[counter10].cy,corners[counter10].cz,corners[counter10].cr,corners[counter10].cg,corners[counter10].cb);
                                                                }
                                                                fclose(outptr);

                                                                //printf("\ny: %d\n",y);
                                                                counter=y-1;
                                                                u=0;



















                                                                break;
                                                            }else if(strcmp(files_Controls[t+1],data_Type_Binary)==0){
                                                                printf("\nThis file is Binary\n");
                                                                //x y z r g b binary kodlari buraya
                                                                fclose(fptr);
                                                                fptr=fopen(nkt_Files[p],"rb");

                                                                int binary_Word_Counter=0,search_Counter=0;
                                                                char ch;
                                                                while(!feof(fptr)){
                                                                    ch=fgetc(fptr);
                                                                    if(ch=='y'){
                                                                        search_Counter++;
                                                                    }
                                                                    if(search_Counter==3){
                                                                        break;
                                                                    }
                                                                    binary_Word_Counter++;

                                                                }
                                                                binary_Word_Counter=binary_Word_Counter+2;
                                                                //printf("binarywordc %d",binary_Word_Counter);


                                                                fseek(fptr,binary_Word_Counter,SEEK_SET);



                                                                int counter7=0,counter8;
                                                                while(!feof(fptr)){

                                                                    fread(&binpoints2[counter7].binx2,sizeof(float),1,fptr);
                                                                    fread(&binpoints2[counter7].biny2,sizeof(float),1,fptr);
                                                                    fread(&binpoints2[counter7].binz2,sizeof(float),1,fptr);
                                                                    fread(&binpoints2[counter7].binr,sizeof(int),1,fptr);
                                                                    fread(&binpoints2[counter7].bing,sizeof(int),1,fptr);
                                                                    fread(&binpoints2[counter7].binb,sizeof(int),1,fptr);

                                                                    counter7++;


                                                                }
                                                                 /*for(counter8=0;counter8<counter7-1;counter8++){
                                                                    printf("binary--> x:%f y:%f z:%f r:%d g:%d b:%d\n",binpoints2[counter8].binx2,binpoints2[counter8].biny2,binpoints2[counter8].binz2,binpoints2[counter8].binr,binpoints2[counter8].bing,binpoints2[counter8].binb);
                                                                }*/
                                                                int counter11=0;
                                                                float max_X,max_Y,max_Z,min_X,min_Y,min_Z,edge1,edge2,edge3;
                                                                max_X=binpoints2[0].binx2;
                                                                max_Y=binpoints2[0].biny2;
                                                                max_Z=binpoints2[0].binz2;
                                                                min_X=binpoints2[0].binx2;
                                                                min_Y=binpoints2[0].biny2;
                                                                min_Z=binpoints2[0].binz2;

                                                                for(counter11=0;counter11<counter7-1;counter11++){
                                                                        if(max_X<binpoints2[counter11].binx2){
                                                                                max_X=binpoints2[counter11].binx2;

                                                                        }
                                                                        if(max_Y<binpoints2[counter11].biny2){
                                                                            max_Y=points2[counter11].y2;
                                                                        }
                                                                        if(max_Z<binpoints2[counter11].binz2){
                                                                            max_Z=binpoints2[counter11].binz2;
                                                                        }
                                                                        if(min_X>binpoints2[counter11].binx2){
                                                                                min_X=binpoints2[counter11].binx2;

                                                                        }
                                                                        if(min_Y>binpoints2[counter11].biny2){
                                                                            min_Y=binpoints2[counter11].biny2;
                                                                        }
                                                                        if(min_Z>binpoints2[counter11].binz2){
                                                                            min_Z=binpoints2[counter11].binz2;
                                                                        }



                                                                }

                                                                edge1=max_X-min_X;
                                                                edge2=max_Y-min_Y;
                                                                edge3=max_Z-min_Z;
                                                                //printf("1:%f 2:%f 3:%f\n",edge1,edge2,edge3);
                                                                float biggest_edge,min_Point_X,min_Point_Y,min_Point_Z;
                                                                min_Point_X=min_X;
                                                                min_Point_Y=min_Y;
                                                                min_Point_Z=min_Z;

                                                                if(edge1>=edge2 &&edge1>=edge3){
                                                                    biggest_edge=edge1;
                                                                }
                                                                if(edge2>=edge1 &&edge2>=edge3){
                                                                    biggest_edge=edge2;
                                                                }
                                                                if(edge3>=edge1 &&edge3>=edge2){
                                                                    biggest_edge=edge3;
                                                                }
                                                                //printf("biggest : %f",biggest_edge);



                                                                bincorners[0].bincx=min_Point_X;
                                                                bincorners[0].bincy=min_Point_Y;
                                                                bincorners[0].bincz=min_Point_Z;
                                                                bincorners[0].bincr=255;
                                                                bincorners[0].bincg=255;
                                                                bincorners[0].bincb=255;

                                                                bincorners[1].bincx=min_Point_X;
                                                                bincorners[1].bincy=min_Point_Y+biggest_edge;
                                                                bincorners[1].bincz=min_Point_Z;
                                                                bincorners[1].bincr=255;
                                                                bincorners[1].bincg=255;
                                                                bincorners[1].bincb=255;

                                                                bincorners[2].bincx=min_Point_X;
                                                                bincorners[2].bincy=min_Point_Y;
                                                                bincorners[2].bincz=min_Point_Z+biggest_edge;
                                                                bincorners[2].bincr=255;
                                                                bincorners[2].bincg=255;
                                                                bincorners[2].bincb=255;

                                                                bincorners[3].bincx=min_Point_X+biggest_edge;
                                                                bincorners[3].bincy=min_Point_Y;
                                                                bincorners[3].bincz=min_Point_Z;
                                                                bincorners[3].bincr=255;
                                                                bincorners[3].bincg=255;
                                                                bincorners[3].bincb=255;

                                                                bincorners[4].bincx=min_Point_X;
                                                                bincorners[4].bincy=min_Point_Y+biggest_edge;
                                                                bincorners[4].bincz=min_Point_Z+biggest_edge;
                                                                bincorners[4].bincr=255;
                                                                bincorners[4].bincg=255;
                                                                bincorners[4].bincb=255;

                                                                bincorners[5].bincx=min_Point_X+biggest_edge;
                                                                bincorners[5].bincy=min_Point_Y;
                                                                bincorners[5].bincz=min_Point_Z+biggest_edge;
                                                                bincorners[5].bincr=255;
                                                                bincorners[5].bincg=255;
                                                                bincorners[5].bincb=255;

                                                                bincorners[6].bincx=min_Point_X+biggest_edge;
                                                                bincorners[6].bincy=min_Point_Y+biggest_edge;
                                                                bincorners[6].bincz=min_Point_Z;
                                                                bincorners[6].bincr=255;
                                                                bincorners[6].bincg=255;
                                                                bincorners[6].bincb=255;

                                                                bincorners[7].bincx=min_Point_X+biggest_edge;
                                                                bincorners[7].bincy=min_Point_Y+biggest_edge;
                                                                bincorners[7].bincz=min_Point_Z+biggest_edge;
                                                                bincorners[7].bincr=255;
                                                                bincorners[7].bincg=255;
                                                                bincorners[7].bincb=255;








                                                                FILE *outptr;
                                                                char out_Name[30];
                                                                strcpy(out_Name,"output");
                                                                strcat(out_Name,nkt_Files[p]);
                                                                outptr=fopen(out_Name,"a");
                                                                fprintf(outptr,"\nSecim 3\nButun noktalari kapsayan en kucuk kupun kose bilgileri\n");
                                                                int counter10;
                                                                for(counter10=0;counter10<8;counter10++){
                                                                    fprintf(outptr,"bincx:%f bincy:%f bincz:%f bincr:%d bincg:%d bincb:%d\n",bincorners[counter10].bincx,bincorners[counter10].bincy,bincorners[counter10].bincz,bincorners[counter10].bincr,bincorners[counter10].bincg,bincorners[counter10].bincb);
                                                                }
                                                                fclose(outptr);









                                                                break;

                                                            }else{
                                                            break;
                                                            }

                                                        }


                                                    }



                                                    break;


                                                }else{
                                                break;
                                                }



                                            }else{
                                            break;
                                            }

                                        }else{
                                        //x y z kodlari buraya
                                        printf("\nThis is X Y Z\n");
                                        int n;
                                        for(n=0;n<50;n++){
                                                        if(strcmp(files_Controls[n],"DATA")==0){
                                                            if(strcmp(files_Controls[n+1],data_Type_Ascii)==0){
                                                                printf("\nThis file is ASCII\n");
                                                                //x y z ascii kodlari buraya
                                                                fclose(fptr);
                                                                fptr=fopen(nkt_Files[p],"r");
                                                                //fseek(fptr,74,SEEK_SET);
                                                                int counter2=0,m;
                                                                //printf("%ld\n",ftell(fptr));

                                                                char words[900][20];
                                                                int words_Counter=0;

                                                                while(!feof(fptr)){
                                                                    fscanf(fptr,"%s",&words[words_Counter]);


                                                                    if(strcmp(words[words_Counter],"ascii")==0){
                                                                        break;

                                                                    }
                                                                    words_Counter++;



                                                                }
                                                                //printf("TEST%d",words_Counter);


                                                                while(!feof(fptr)){
                                                                    fscanf(fptr,"%lf %lf %lf",&points1[counter2].x1,&points1[counter2].y1,&points1[counter2].z1);

                                                                    counter2++;

                                                                }

                                                                int counter4=0,up2=0,counter12;

                                                                double max_X,max_Y,max_Z,min_X,min_Y,min_Z,edge1,edge2,edge3;
                                                                max_X=points1[0].x1;
                                                                max_Y=points1[0].y1;
                                                                max_Z=points1[0].z1;
                                                                min_X=points1[0].x1;
                                                                min_Y=points1[0].y1;
                                                                min_Z=points1[0].z1;

                                                                for(counter12=0;counter12<counter2;counter12++){
                                                                        if(max_X<points1[counter12].x1){
                                                                                max_X=points1[counter12].x1;

                                                                        }
                                                                        if(max_Y<points1[counter12].y1){
                                                                            max_Y=points1[counter12].y1;
                                                                        }
                                                                        if(max_Z<points1[counter12].z1){
                                                                            max_Z=points1[counter12].z1;
                                                                        }
                                                                        if(min_X>points1[counter12].x1){
                                                                                min_X=points1[counter12].x1;

                                                                        }
                                                                        if(min_Y>points1[counter12].y1){
                                                                            min_Y=points1[counter12].y1;
                                                                        }
                                                                        if(min_Z>points1[counter12].z1){
                                                                            min_Z=points1[counter12].z1;
                                                                        }



                                                                }

                                                                edge1=max_X-min_X;
                                                                edge2=max_Y-min_Y;
                                                                edge3=max_Z-min_Z;
                                                                //printf("1:%lf 2:%lf 3:%lf\n",edge1,edge2,edge3);
                                                                double biggest_edge,min_Point_X,min_Point_Y,min_Point_Z;
                                                                min_Point_X=min_X;
                                                                min_Point_Y=min_Y;
                                                                min_Point_Z=min_Z;

                                                                if(edge1>=edge2 &&edge1>=edge3){
                                                                    biggest_edge=edge1;
                                                                }
                                                                if(edge2>=edge1 &&edge2>=edge3){
                                                                    biggest_edge=edge2;
                                                                }
                                                                if(edge3>=edge1 &&edge3>=edge2){
                                                                    biggest_edge=edge3;
                                                                }
                                                                //printf("biggest : %lf",biggest_edge);



                                                                corners[0].cx=min_Point_X;
                                                                corners[0].cy=min_Point_Y;
                                                                corners[0].cz=min_Point_Z;
                                                                corners[0].cr=255;
                                                                corners[0].cg=255;
                                                                corners[0].cb=255;

                                                                corners[1].cx=min_Point_X;
                                                                corners[1].cy=min_Point_Y+biggest_edge;
                                                                corners[1].cz=min_Point_Z;
                                                                corners[1].cr=255;
                                                                corners[1].cg=255;
                                                                corners[1].cb=255;

                                                                corners[2].cx=min_Point_X;
                                                                corners[2].cy=min_Point_Y;
                                                                corners[2].cz=min_Point_Z+biggest_edge;
                                                                corners[2].cr=255;
                                                                corners[2].cg=255;
                                                                corners[2].cb=255;

                                                                corners[3].cx=min_Point_X+biggest_edge;
                                                                corners[3].cy=min_Point_Y;
                                                                corners[3].cz=min_Point_Z;
                                                                corners[3].cr=255;
                                                                corners[3].cg=255;
                                                                corners[3].cb=255;

                                                                corners[4].cx=min_Point_X;
                                                                corners[4].cy=min_Point_Y+biggest_edge;
                                                                corners[4].cz=min_Point_Z+biggest_edge;
                                                                corners[4].cr=255;
                                                                corners[4].cg=255;
                                                                corners[4].cb=255;

                                                                corners[5].cx=min_Point_X+biggest_edge;
                                                                corners[5].cy=min_Point_Y;
                                                                corners[5].cz=min_Point_Z+biggest_edge;
                                                                corners[5].cr=255;
                                                                corners[5].cg=255;
                                                                corners[5].cb=255;

                                                                corners[6].cx=min_Point_X+biggest_edge;
                                                                corners[6].cy=min_Point_Y+biggest_edge;
                                                                corners[6].cz=min_Point_Z;
                                                                corners[6].cr=255;
                                                                corners[6].cg=255;
                                                                corners[6].cb=255;

                                                                corners[7].cx=min_Point_X+biggest_edge;
                                                                corners[7].cy=min_Point_Y+biggest_edge;
                                                                corners[7].cz=min_Point_Z+biggest_edge;
                                                                corners[7].cr=255;
                                                                corners[7].cg=255;
                                                                corners[7].cb=255;








                                                                FILE *outptr;
                                                                char out_Name[30];
                                                                strcpy(out_Name,"output");
                                                                strcat(out_Name,nkt_Files[p]);
                                                                outptr=fopen(out_Name,"a");
                                                                fprintf(outptr,"\nSecim 3\nButun noktalari kapsayan en kucuk kupun kose bilgileri\n");
                                                                int counter10;
                                                                for(counter10=0;counter10<8;counter10++){
                                                                    fprintf(outptr,"cx:%lf cy:%lf cz:%lf cr:%d cg:%d cb:%d\n",corners[counter10].cx,corners[counter10].cy,corners[counter10].cz,corners[counter10].cr,corners[counter10].cg,corners[counter10].cb);
                                                                }
                                                                fclose(outptr);













                                                                break;
                                                            }else if(strcmp(files_Controls[n+1],data_Type_Binary)==0){
                                                                printf("\nThis file is Binary\n");
                                                                //x y z binary kodlari buraya
                                                                fclose(fptr);
                                                                fptr=fopen(nkt_Files[p],"rb");

                                                                int binary_Word_Counter=0,search_Counter=0;
                                                                char ch;
                                                                while(!feof(fptr)){
                                                                    ch=fgetc(fptr);
                                                                    if(ch=='y'){
                                                                        search_Counter++;
                                                                    }
                                                                    if(search_Counter==3){
                                                                        break;
                                                                    }
                                                                    binary_Word_Counter++;

                                                                }
                                                                binary_Word_Counter=binary_Word_Counter+2;
                                                                //printf("binarywordc %d",binary_Word_Counter);


                                                                fseek(fptr,binary_Word_Counter,SEEK_SET);



                                                                int counter7=0;
                                                                while(!feof(fptr)){

                                                                    fread(&binpoints1[counter7].binx1,sizeof(float),1,fptr);
                                                                    fread(&binpoints1[counter7].biny1,sizeof(float),1,fptr);
                                                                    fread(&binpoints1[counter7].binz1,sizeof(float),1,fptr);
                                                                    counter7++;


                                                                }
                                                                int counter8;
                                                               /* for(counter8=0;counter8<counter7-1;counter8++){
                                                                    printf("binary--> x:%f y:%f z:%f\n",binpoints1[counter8].binx1,binpoints1[counter8].biny1,binpoints1[counter8].binz1);
                                                                }*/

                                                                int counter11;
                                                                float max_X,max_Y,max_Z,min_X,min_Y,min_Z,edge1,edge2,edge3;
                                                                max_X=binpoints1[0].binx1;
                                                                max_Y=binpoints1[0].biny1;
                                                                max_Z=binpoints1[0].binz1;
                                                                min_X=binpoints1[0].binx1;
                                                                min_Y=binpoints1[0].biny1;
                                                                min_Z=binpoints1[0].binz1;

                                                                for(counter11=0;counter11<counter7-1;counter11++){
                                                                        if(max_X<binpoints1[counter11].binx1){
                                                                                max_X=binpoints1[counter11].binx1;

                                                                        }
                                                                        if(max_Y<binpoints1[counter11].biny1){
                                                                            max_Y=points1[counter11].y1;
                                                                        }
                                                                        if(max_Z<binpoints1[counter11].binz1){
                                                                            max_Z=binpoints1[counter11].binz1;
                                                                        }
                                                                        if(min_X>binpoints1[counter11].binx1){
                                                                                min_X=binpoints1[counter11].binx1;

                                                                        }
                                                                        if(min_Y>binpoints1[counter11].biny1){
                                                                            min_Y=binpoints1[counter11].biny1;
                                                                        }
                                                                        if(min_Z>binpoints1[counter11].binz1){
                                                                            min_Z=binpoints1[counter11].binz1;
                                                                        }



                                                                }

                                                                edge1=max_X-min_X;
                                                                edge2=max_Y-min_Y;
                                                                edge3=max_Z-min_Z;
                                                                //printf("1:%f 2:%f 3:%f\n",edge1,edge2,edge3);
                                                                float biggest_edge,min_Point_X,min_Point_Y,min_Point_Z;
                                                                min_Point_X=min_X;
                                                                min_Point_Y=min_Y;
                                                                min_Point_Z=min_Z;

                                                                if(edge1>=edge2 &&edge1>=edge3){
                                                                    biggest_edge=edge1;
                                                                }
                                                                if(edge2>=edge1 &&edge2>=edge3){
                                                                    biggest_edge=edge2;
                                                                }
                                                                if(edge3>=edge1 &&edge3>=edge2){
                                                                    biggest_edge=edge3;
                                                                }
                                                                //printf("biggest : %f",biggest_edge);



                                                                bincorners[0].bincx=min_Point_X;
                                                                bincorners[0].bincy=min_Point_Y;
                                                                bincorners[0].bincz=min_Point_Z;
                                                                bincorners[0].bincr=255;
                                                                bincorners[0].bincg=255;
                                                                bincorners[0].bincb=255;

                                                                bincorners[1].bincx=min_Point_X;
                                                                bincorners[1].bincy=min_Point_Y+biggest_edge;
                                                                bincorners[1].bincz=min_Point_Z;
                                                                bincorners[1].bincr=255;
                                                                bincorners[1].bincg=255;
                                                                bincorners[1].bincb=255;

                                                                bincorners[2].bincx=min_Point_X;
                                                                bincorners[2].bincy=min_Point_Y;
                                                                bincorners[2].bincz=min_Point_Z+biggest_edge;
                                                                bincorners[2].bincr=255;
                                                                bincorners[2].bincg=255;
                                                                bincorners[2].bincb=255;

                                                                bincorners[3].bincx=min_Point_X+biggest_edge;
                                                                bincorners[3].bincy=min_Point_Y;
                                                                bincorners[3].bincz=min_Point_Z;
                                                                bincorners[3].bincr=255;
                                                                bincorners[3].bincg=255;
                                                                bincorners[3].bincb=255;

                                                                bincorners[4].bincx=min_Point_X;
                                                                bincorners[4].bincy=min_Point_Y+biggest_edge;
                                                                bincorners[4].bincz=min_Point_Z+biggest_edge;
                                                                bincorners[4].bincr=255;
                                                                bincorners[4].bincg=255;
                                                                bincorners[4].bincb=255;

                                                                bincorners[5].bincx=min_Point_X+biggest_edge;
                                                                bincorners[5].bincy=min_Point_Y;
                                                                bincorners[5].bincz=min_Point_Z+biggest_edge;
                                                                bincorners[5].bincr=255;
                                                                bincorners[5].bincg=255;
                                                                bincorners[5].bincb=255;

                                                                bincorners[6].bincx=min_Point_X+biggest_edge;
                                                                bincorners[6].bincy=min_Point_Y+biggest_edge;
                                                                bincorners[6].bincz=min_Point_Z;
                                                                bincorners[6].bincr=255;
                                                                bincorners[6].bincg=255;
                                                                bincorners[6].bincb=255;

                                                                bincorners[7].bincx=min_Point_X+biggest_edge;
                                                                bincorners[7].bincy=min_Point_Y+biggest_edge;
                                                                bincorners[7].bincz=min_Point_Z+biggest_edge;
                                                                bincorners[7].bincr=255;
                                                                bincorners[7].bincg=255;
                                                                bincorners[7].bincb=255;








                                                                FILE *outptr;
                                                                char out_Name[30];
                                                                strcpy(out_Name,"output");
                                                                strcat(out_Name,nkt_Files[p]);
                                                                outptr=fopen(out_Name,"a");
                                                                fprintf(outptr,"\nSecim 3\nButun noktalari kapsayan en kucuk kupun kose bilgileri\n");
                                                                int counter10;
                                                                for(counter10=0;counter10<8;counter10++){
                                                                    fprintf(outptr,"bincx:%f bincy:%f bincz:%f bincr:%d bincg:%d bincb:%d\n",bincorners[counter10].bincx,bincorners[counter10].bincy,bincorners[counter10].bincz,bincorners[counter10].bincr,bincorners[counter10].bincg,bincorners[counter10].bincb);
                                                                }
                                                                fclose(outptr);
















                                                                break;

                                                            }else{
                                                            break;
                                                            }

                                                        }


                                                    }



                                        break;
                                        }

                                    }else{
                                    break;
                                    }

                                }else{
                                break;
                                }

                            }else{
                                //printf("\nFaulty file\n");
                            break;
                            }

                        }




                }







                }else{
                printf("file can't open\n");
            }








            fclose(fptr);




     }







            choise=10;
            break;
        case 4:

            printf("\nFor all files -->Enter coordinates and radius of the sphere (x,y,z,r): \n");
            scanf("%lf %lf %lf %lf",&central_X,&central_Y,&central_Z,&central_R);




            for(p=0;p<nkt_Counts;p++){


        fptr=fopen(nkt_Files[p],"r");
        printf("\n\n\n");

        if(fptr!=NULL){
                free(files_Controls);

            for(j=0;j<17;j++){
                fscanf(fptr,"%s",files_Controls[j]);
                printf("%s",files_Controls[j]);
                }

                if( strcmp(files_Controls[0],"#") ==0 && strcmp(files_Controls[1],"Noktalar")==0 && strcmp(files_Controls[2],"dosya")==0 && strcmp(files_Controls[3],"format")==0 && strcmp(files_Controls[4],"VERSION")==0 && strcmp(files_Controls[5],"1")==0 && strcmp(files_Controls[6],"ALANLAR")==0 && strcmp(files_Controls[7],"x")==0 && strcmp(files_Controls[8],"y")==0 && strcmp(files_Controls[9],"z")==0 && strcmp(files_Controls[10],"r")==0 && strcmp(files_Controls[11],"g")==0 && strcmp(files_Controls[12],"b")==0 && strcmp(files_Controls[13],"NOKTALAR")==0 && strcmp(files_Controls[15],"DATA")==0 && strcmp(files_Controls[16],"ascii")==0   )  {
                  //  printf("\n**BASARILI**\n");
                }

                else if( strcmp(files_Controls[0],"#") ==0 && strcmp(files_Controls[1],"Noktalar")==0 && strcmp(files_Controls[2],"dosya")==0 && strcmp(files_Controls[3],"format")==0 && strcmp(files_Controls[4],"VERSION")==0 && strcmp(files_Controls[5],"1")==0 && strcmp(files_Controls[6],"ALANLAR")==0 && strcmp(files_Controls[7],"x")==0 && strcmp(files_Controls[8],"y")==0 && strcmp(files_Controls[9],"z")==0 && strcmp(files_Controls[10],"r")==0 && strcmp(files_Controls[11],"g")==0 && strcmp(files_Controls[12],"b")==0 && strcmp(files_Controls[13],"NOKTALAR")==0 && strcmp(files_Controls[15],"DATA")==0 && strcmp(files_Controls[16],"binary")==0   )  {

                //printf("\n**BASARILI**\n");
                }
                else if( strcmp(files_Controls[0],"#") ==0 && strcmp(files_Controls[1],"Noktalar")==0 && strcmp(files_Controls[2],"dosya")==0 && strcmp(files_Controls[3],"format")==0 && strcmp(files_Controls[4],"VERSION")==0 && strcmp(files_Controls[5],"1")==0 && strcmp(files_Controls[6],"ALANLAR")==0 && strcmp(files_Controls[7],"x")==0 && strcmp(files_Controls[8],"y")==0 && strcmp(files_Controls[9],"z")==0 && strcmp(files_Controls[10],"NOKTALAR")==0 && strcmp(files_Controls[12],"DATA")==0 && strcmp(files_Controls[13],"ascii")==0   )  {

                //printf("\n**BASARILI**\n");
                }
                else if( strcmp(files_Controls[0],"#") ==0 && strcmp(files_Controls[1],"Noktalar")==0 && strcmp(files_Controls[2],"dosya")==0 && strcmp(files_Controls[3],"format")==0 && strcmp(files_Controls[4],"VERSION")==0 && strcmp(files_Controls[5],"1")==0 && strcmp(files_Controls[6],"ALANLAR")==0 && strcmp(files_Controls[7],"x")==0 && strcmp(files_Controls[8],"y")==0 && strcmp(files_Controls[9],"z")==0 &&  strcmp(files_Controls[10],"NOKTALAR")==0 && strcmp(files_Controls[12],"DATA")==0 && strcmp(files_Controls[13],"binary")==0   )  {

                //printf("\n**BASARILI**\n");
                }else{
                    FILE *outptr;
                                                                char out_Name[30];
                                                                strcpy(out_Name,"output");
                                                                strcat(out_Name,nkt_Files[p]);
                                                                outptr=fopen(out_Name,"a");
                                                                fprintf(outptr,"\nSecim 4\nUyusmayan format\n");

                                                                fclose(outptr);

                continue;

                }



            for(j=0;j<50;j++){

                if(strcmp(files_Controls[j],"ALANLAR")==0){
                        if(strcmp(files_Controls[j+1],"x")==0){
                        printf("X IS HERE ");
                            if(strcmp(files_Controls[j+2],"y")==0){
                            printf("Y IS HERE ");
                                if(strcmp(files_Controls[j+3],"z")==0){
                                printf("Z IS HERE ");
                                    if(strcmp(files_Controls[j+4],"r")==0){
                                    printf("R IS HERE ");
                                        if(strcmp(files_Controls[j+5],"g")==0){
                                            printf("G IS HERE ");
                                                if(strcmp(files_Controls[j+6],"b")==0){
                                                printf("B IS HERE ");
                                                //x y z r g b kodlari buraya
                                                printf("\nThis is X Y Z R G B\n");
                                                int t;
                                                    for(t=0;t<50;t++){
                                                        if(strcmp(files_Controls[t],"DATA")==0){
                                                            if(strcmp(files_Controls[t+1],data_Type_Ascii)==0){
                                                                printf("\nThis file is ASCII\n");
                                                                //x y z r g b ascii kodlari buraya
                                                                fclose(fptr);
                                                                fptr=fopen(nkt_Files[p],"r");
                                                                int y=0,u,counter=0;
                                                                //fseek(fptr,79,SEEK_SET);
                                                                //printf("%ld\n",ftell(fptr));


                                                                char words[900][20];
                                                                int words_Counter=0;

                                                                while(!feof(fptr)){
                                                                    fscanf(fptr,"%s",&words[words_Counter]);


                                                                    if(strcmp(words[words_Counter],"ascii")==0){
                                                                        break;

                                                                    }
                                                                    words_Counter++;



                                                                }
                                                                //printf("TEST%d",words_Counter);


                                                                while(!feof(fptr)){
                                                                    fscanf(fptr,"%lf %lf %lf",&points2[y].x2,&points2[y].y2,&points2[y].z2);
                                                                    fscanf(fptr,"%d %d %d",&points2[y].r,&points2[y].g,&points2[y].b);
                                                                    y++;

                                                                }


                                                                /*for(u=0;u<y-1;u++){
                                                                    printf("%lf %lf %lf ",points2[u].x2,points2[u].y2,points2[u].z2);
                                                                    printf("%d %d %d\n",points2[u].r,points2[u].g,points2[u].b);

                                                                }*/
                                                                int counter9,control=0;

                                                                /*double central_X,central_Y,central_Z,central_R;
                                                                printf("\nFor %s -->Enter coordinates and radius of the sphere (x,y,z,r): \n",nkt_Files[p]);
                                                                scanf("%lf %lf %lf %lf",&central_X,&central_Y,&central_Z,&central_R);*/
                                                                for(counter9=0;counter9<y;counter9++){
                                                                    if(central_R>=sqrt(  ((central_X-points2[counter9].x2)*(central_X-points2[counter9].x2))+((central_Y-points2[counter9].y2)*(central_Y-points2[counter9].y2))+((central_Z-points2[counter9].z2)*(central_Z-points2[counter9].z2))   )     ){
                                                                    control++;
                                                                    FILE *outptr;
                                                                    char out_Name[30];
                                                                    strcpy(out_Name,"output");
                                                                    strcat(out_Name,nkt_Files[p]);
                                                                    outptr=fopen(out_Name,"a");
                                                                    fprintf(outptr,"\nSecim 4\n");
                                                                    fprintf(outptr,"icindeki noktalar-->x:%lf y:%lf z:%lf r:%d g:%d b:%d\n",points2[counter9].x2,points2[counter9].y2,points2[counter9].z2,points2[counter9].r,points2[counter9].g,points2[counter9].b);


                                                                    fclose(outptr);

                                                                    }

                                                                }
                                                                if(control==0){
                                                                    FILE *outptr;
                                                                    char out_Name[30];
                                                                    strcpy(out_Name,"output");
                                                                    strcat(out_Name,nkt_Files[p]);
                                                                    outptr=fopen(out_Name,"a");
                                                                    fprintf(outptr,"\nSecim 4\n");
                                                                    fprintf(outptr,"Girilen kurenin bilgileri icinde nokta bulunamamistir.\n");


                                                                    fclose(outptr);

                                                                }












                                                                //printf("\ny: %d\n",y);
                                                                counter=y-1;
                                                                u=0;



















                                                                break;
                                                            }else if(strcmp(files_Controls[t+1],data_Type_Binary)==0){
                                                                printf("\nThis file is Binary\n");
                                                                //x y z r g b binary kodlari buraya
                                                                fclose(fptr);
                                                                fptr=fopen(nkt_Files[p],"rb");


                                                                int binary_Word_Counter=0,search_Counter=0;
                                                                char ch;
                                                                while(!feof(fptr)){
                                                                    ch=fgetc(fptr);
                                                                    if(ch=='y'){
                                                                        search_Counter++;
                                                                    }
                                                                    if(search_Counter==3){
                                                                        break;
                                                                    }
                                                                    binary_Word_Counter++;

                                                                }
                                                                binary_Word_Counter=binary_Word_Counter+2;
                                                                //printf("binarywordc %d",binary_Word_Counter);


                                                                fseek(fptr,binary_Word_Counter,SEEK_SET);




                                                                int counter7=0,counter8;
                                                                while(!feof(fptr)){

                                                                    fread(&binpoints2[counter7].binx2,sizeof(float),1,fptr);
                                                                    fread(&binpoints2[counter7].biny2,sizeof(float),1,fptr);
                                                                    fread(&binpoints2[counter7].binz2,sizeof(float),1,fptr);
                                                                    fread(&binpoints2[counter7].binr,sizeof(int),1,fptr);
                                                                    fread(&binpoints2[counter7].bing,sizeof(int),1,fptr);
                                                                    fread(&binpoints2[counter7].binb,sizeof(int),1,fptr);

                                                                    counter7++;


                                                                }
                                                                 /*for(counter8=0;counter8<counter7-1;counter8++){
                                                                    printf("binary--> x:%f y:%f z:%f r:%d g:%d b:%d\n",binpoints2[counter8].binx2,binpoints2[counter8].biny2,binpoints2[counter8].binz2,binpoints2[counter8].binr,binpoints2[counter8].bing,binpoints2[counter8].binb);
                                                                }*/


                                                                int counter9,control=0;

                                                                /*double central_X,central_Y,central_Z,central_R;
                                                                printf("\nFor %s -->Enter coordinates and radius of the sphere (x,y,z,r): \n",nkt_Files[p]);
                                                                scanf("%lf %lf %lf %lf",&central_X,&central_Y,&central_Z,&central_R);*/
                                                                for(counter9=0;counter9<counter7-1;counter9++){
                                                                    if(central_R>=sqrt(  ((central_X-binpoints2[counter9].binx2)*(central_X-binpoints2[counter9].binx2))+((central_Y-binpoints2[counter9].biny2)*(central_Y-binpoints2[counter9].biny2))+((central_Z-binpoints2[counter9].binz2)*(central_Z-binpoints2[counter9].binz2))    )    ){
                                                                    control++;
                                                                    FILE *outptr;
                                                                    char out_Name[30];
                                                                    strcpy(out_Name,"output");
                                                                    strcat(out_Name,nkt_Files[p]);
                                                                    outptr=fopen(out_Name,"a");
                                                                    fprintf(outptr,"\nSecim 4\n");
                                                                    fprintf(outptr,"Kure icindeki noktalar-->x:%lf y:%lf z:%lf\n",binpoints2[counter9].binx2,binpoints2[counter9].biny2,binpoints2[counter9].binz2);


                                                                    fclose(outptr);

                                                                    }

                                                                }
                                                                if(control==0){
                                                                    FILE *outptr;
                                                                    char out_Name[30];
                                                                    strcpy(out_Name,"output");
                                                                    strcat(out_Name,nkt_Files[p]);
                                                                    outptr=fopen(out_Name,"a");
                                                                    fprintf(outptr,"\nSecim 4\n");
                                                                    fprintf(outptr,"Girilen kurenin bilgileri icinde nokta bulunamamistir.\n");


                                                                    fclose(outptr);

                                                                }











                                                                break;

                                                            }else{
                                                            break;
                                                            }

                                                        }


                                                    }



                                                    break;


                                                }else{
                                                break;
                                                }



                                            }else{
                                            break;
                                            }

                                        }else{
                                        //x y z kodlari buraya
                                        printf("\nThis is X Y Z\n");
                                        int n;
                                        for(n=0;n<50;n++){
                                                        if(strcmp(files_Controls[n],"DATA")==0){
                                                            if(strcmp(files_Controls[n+1],data_Type_Ascii)==0){
                                                                printf("\nThis file is ASCII\n");
                                                                //x y z ascii kodlari buraya
                                                                fclose(fptr);
                                                                fptr=fopen(nkt_Files[p],"r");
                                                                //fseek(fptr,74,SEEK_SET);
                                                                int counter2=0,m;
                                                                //printf("%ld\n",ftell(fptr));


                                                                char words[900][20];
                                                                int words_Counter=0;

                                                                while(!feof(fptr)){
                                                                    fscanf(fptr,"%s",&words[words_Counter]);


                                                                    if(strcmp(words[words_Counter],"ascii")==0){
                                                                        break;

                                                                    }
                                                                    words_Counter++;



                                                                }
                                                                //printf("TEST%d",words_Counter);


                                                                while(!feof(fptr)){
                                                                    fscanf(fptr,"%lf %lf %lf",&points1[counter2].x1,&points1[counter2].y1,&points1[counter2].z1);
                                                                    //printf("%lf %lf %lf\n",points1[counter2].x1,points1[counter2].y1,points1[counter2].z1);

                                                                    counter2++;

                                                                }



                                                                int counter4=0,up2=0;

                                                                /*for(counter4=0;counter4<counter2;counter4++){
                                                                    printf("%lf %lf %lf\n",points1[counter4].x1,points1[counter4].y1,points1[counter4].z1);
                                                                }*/


                                                                int counter9,control=0;

                                                                /*double central_X,central_Y,central_Z,central_R;
                                                                printf("\nFor %s -->Enter coordinates and radius of the sphere (x,y,z,r): \n",nkt_Files[p]);
                                                                scanf("%lf %lf %lf %lf",&central_X,&central_Y,&central_Z,&central_R);*/
                                                                for(counter9=0;counter9<counter2;counter9++){
                                                                    if(central_R>=sqrt(  ((central_X-points1[counter9].x1)*(central_X-points1[counter9].x1))+((central_Y-points1[counter9].y1)*(central_Y-points1[counter9].y1))+((central_Z-points1[counter9].z1)*(central_Z-points1[counter9].z1))   )     ){
                                                                    control++;
                                                                    FILE *outptr;
                                                                    char out_Name[30];
                                                                    strcpy(out_Name,"output");
                                                                    strcat(out_Name,nkt_Files[p]);
                                                                    outptr=fopen(out_Name,"a");
                                                                    fprintf(outptr,"\nSecim 4\n");
                                                                    fprintf(outptr,"icindeki noktalar-->x:%lf y:%lf z:%lf\n",points1[counter9].x1,points1[counter9].y1,points1[counter9].z1);


                                                                    fclose(outptr);

                                                                    }

                                                                }
                                                                if(control==0){
                                                                    FILE *outptr;
                                                                    char out_Name[30];
                                                                    strcpy(out_Name,"output");
                                                                    strcat(out_Name,nkt_Files[p]);
                                                                    outptr=fopen(out_Name,"a");
                                                                    fprintf(outptr,"\nSecim 4\n");
                                                                    fprintf(outptr,"Girilen kurenin bilgileri icinde nokta bulunamamistir.\n");


                                                                    fclose(outptr);

                                                                }











                                                                break;
                                                            }else if(strcmp(files_Controls[n+1],data_Type_Binary)==0){
                                                                printf("\nThis file is Binary\n");
                                                                //x y z binary kodlari buraya
                                                                fclose(fptr);
                                                                fptr=fopen(nkt_Files[p],"rb");


                                                                int binary_Word_Counter=0,search_Counter=0;
                                                                char ch;
                                                                while(!feof(fptr)){
                                                                    ch=fgetc(fptr);
                                                                    if(ch=='y'){
                                                                        search_Counter++;
                                                                    }
                                                                    if(search_Counter==3){
                                                                        break;
                                                                    }
                                                                    binary_Word_Counter++;

                                                                }
                                                                binary_Word_Counter=binary_Word_Counter+2;
                                                                //printf("binarywordc %d",binary_Word_Counter);


                                                                fseek(fptr,binary_Word_Counter,SEEK_SET);





                                                                int counter7=0;
                                                                while(!feof(fptr)){

                                                                    fread(&binpoints1[counter7].binx1,sizeof(float),1,fptr);
                                                                    fread(&binpoints1[counter7].biny1,sizeof(float),1,fptr);
                                                                    fread(&binpoints1[counter7].binz1,sizeof(float),1,fptr);
                                                                    counter7++;


                                                                }
                                                                int counter8;
                                                               /* for(counter8=0;counter8<counter7-1;counter8++){
                                                                    printf("binary--> x:%f y:%f z:%f\n",binpoints1[counter8].binx1,binpoints1[counter8].biny1,binpoints1[counter8].binz1);
                                                                }*/

                                                                int counter9,control=0;

                                                                /*double central_X,central_Y,central_Z,central_R;
                                                                printf("\nFor %s -->Enter coordinates and radius of the sphere (x,y,z,r): \n",nkt_Files[p]);
                                                                scanf("%lf %lf %lf %lf",&central_X,&central_Y,&central_Z,&central_R);*/
                                                                for(counter9=0;counter9<counter7-1;counter9++){
                                                                    if(central_R>=sqrt(  ((central_X-binpoints1[counter9].binx1)*(central_X-binpoints1[counter9].binx1))+((central_Y-binpoints1[counter9].biny1)*(central_Y-binpoints1[counter9].biny1))+((central_Z-binpoints1[counter9].binz1)*(central_Z-binpoints1[counter9].binz1))    )    ){
                                                                    control++;
                                                                    FILE *outptr;
                                                                    char out_Name[30];
                                                                    strcpy(out_Name,"output");
                                                                    strcat(out_Name,nkt_Files[p]);
                                                                    outptr=fopen(out_Name,"a");
                                                                    fprintf(outptr,"\nSecim 4\n");
                                                                    fprintf(outptr,"Kure icindeki noktalar-->x:%lf y:%lf z:%lf\n",binpoints1[counter9].binx1,binpoints1[counter9].biny1,binpoints1[counter9].binz1);


                                                                    fclose(outptr);

                                                                    }

                                                                }
                                                                if(control==0){
                                                                    FILE *outptr;
                                                                    char out_Name[30];
                                                                    strcpy(out_Name,"output");
                                                                    strcat(out_Name,nkt_Files[p]);
                                                                    outptr=fopen(out_Name,"a");
                                                                    fprintf(outptr,"\nSecim 4\n");
                                                                    fprintf(outptr,"Girilen kurenin bilgileri icinde nokta bulunamamistir.\n");


                                                                    fclose(outptr);

                                                                }













                                                                break;

                                                            }else{
                                                            break;
                                                            }

                                                        }


                                                    }



                                        break;
                                        }

                                    }else{
                                    break;
                                    }

                                }else{
                                break;
                                }

                            }else{
                                //printf("\nFaulty file\n");
                            break;
                            }

                        }





                }







                }else{
                printf("file can't open\n");
            }








            fclose(fptr);




     }











            choise=10;
            break;

        case 5:
            for(p=0;p<nkt_Counts;p++){

        fptr=fopen(nkt_Files[p],"r");
        printf("\n\n\n");

        if(fptr!=NULL){
                free(files_Controls);

            for(j=0;j<17;j++){
                fscanf(fptr,"%s",files_Controls[j]);
                printf("%s",files_Controls[j]);
                }

                if( strcmp(files_Controls[0],"#") ==0 && strcmp(files_Controls[1],"Noktalar")==0 && strcmp(files_Controls[2],"dosya")==0 && strcmp(files_Controls[3],"format")==0 && strcmp(files_Controls[4],"VERSION")==0 && strcmp(files_Controls[5],"1")==0 && strcmp(files_Controls[6],"ALANLAR")==0 && strcmp(files_Controls[7],"x")==0 && strcmp(files_Controls[8],"y")==0 && strcmp(files_Controls[9],"z")==0 && strcmp(files_Controls[10],"r")==0 && strcmp(files_Controls[11],"g")==0 && strcmp(files_Controls[12],"b")==0 && strcmp(files_Controls[13],"NOKTALAR")==0 && strcmp(files_Controls[15],"DATA")==0 && strcmp(files_Controls[16],"ascii")==0   )  {
                  //  printf("\n**BASARILI**\n");
                }

                else if( strcmp(files_Controls[0],"#") ==0 && strcmp(files_Controls[1],"Noktalar")==0 && strcmp(files_Controls[2],"dosya")==0 && strcmp(files_Controls[3],"format")==0 && strcmp(files_Controls[4],"VERSION")==0 && strcmp(files_Controls[5],"1")==0 && strcmp(files_Controls[6],"ALANLAR")==0 && strcmp(files_Controls[7],"x")==0 && strcmp(files_Controls[8],"y")==0 && strcmp(files_Controls[9],"z")==0 && strcmp(files_Controls[10],"r")==0 && strcmp(files_Controls[11],"g")==0 && strcmp(files_Controls[12],"b")==0 && strcmp(files_Controls[13],"NOKTALAR")==0 && strcmp(files_Controls[15],"DATA")==0 && strcmp(files_Controls[16],"binary")==0   )  {

                //printf("\n**BASARILI**\n");
                }
                else if( strcmp(files_Controls[0],"#") ==0 && strcmp(files_Controls[1],"Noktalar")==0 && strcmp(files_Controls[2],"dosya")==0 && strcmp(files_Controls[3],"format")==0 && strcmp(files_Controls[4],"VERSION")==0 && strcmp(files_Controls[5],"1")==0 && strcmp(files_Controls[6],"ALANLAR")==0 && strcmp(files_Controls[7],"x")==0 && strcmp(files_Controls[8],"y")==0 && strcmp(files_Controls[9],"z")==0 && strcmp(files_Controls[10],"NOKTALAR")==0 && strcmp(files_Controls[12],"DATA")==0 && strcmp(files_Controls[13],"ascii")==0   )  {

                //printf("\n**BASARILI**\n");
                }
                else if( strcmp(files_Controls[0],"#") ==0 && strcmp(files_Controls[1],"Noktalar")==0 && strcmp(files_Controls[2],"dosya")==0 && strcmp(files_Controls[3],"format")==0 && strcmp(files_Controls[4],"VERSION")==0 && strcmp(files_Controls[5],"1")==0 && strcmp(files_Controls[6],"ALANLAR")==0 && strcmp(files_Controls[7],"x")==0 && strcmp(files_Controls[8],"y")==0 && strcmp(files_Controls[9],"z")==0 &&  strcmp(files_Controls[10],"NOKTALAR")==0 && strcmp(files_Controls[12],"DATA")==0 && strcmp(files_Controls[13],"binary")==0   )  {

                //printf("\n**BASARILI**\n");
                }else{
                    FILE *outptr;
                                                                char out_Name[30];
                                                                strcpy(out_Name,"output");
                                                                strcat(out_Name,nkt_Files[p]);
                                                                outptr=fopen(out_Name,"a");
                                                                fprintf(outptr,"\nSecim 5\nUyusmayan format\n");

                                                                fclose(outptr);

                continue;

                }




            for(j=0;j<50;j++){

                if(strcmp(files_Controls[j],"ALANLAR")==0){
                        if(strcmp(files_Controls[j+1],"x")==0){
                        printf("X IS HERE ");
                            if(strcmp(files_Controls[j+2],"y")==0){
                            printf("Y IS HERE ");
                                if(strcmp(files_Controls[j+3],"z")==0){
                                printf("Z IS HERE ");
                                    if(strcmp(files_Controls[j+4],"r")==0){
                                    printf("R IS HERE ");
                                        if(strcmp(files_Controls[j+5],"g")==0){
                                            printf("G IS HERE ");
                                                if(strcmp(files_Controls[j+6],"b")==0){
                                                printf("B IS HERE ");
                                                //x y z r g b kodlari buraya
                                                printf("\nThis is X Y Z R G B\n");
                                                int t;
                                                    for(t=0;t<50;t++){
                                                        if(strcmp(files_Controls[t],"DATA")==0){
                                                            if(strcmp(files_Controls[t+1],data_Type_Ascii)==0){
                                                                printf("\nThis file is ASCII\n");
                                                                //x y z r g b ascii kodlari buraya
                                                                fclose(fptr);
                                                                fptr=fopen(nkt_Files[p],"r");
                                                                int y=0,u,counter=0;
                                                                //fseek(fptr,79,SEEK_SET);
                                                                //printf("%ld\n",ftell(fptr));

                                                                char words[900][20];
                                                                int words_Counter=0;

                                                                while(!feof(fptr)){
                                                                    fscanf(fptr,"%s",&words[words_Counter]);


                                                                    if(strcmp(words[words_Counter],"ascii")==0){
                                                                        break;

                                                                    }
                                                                    words_Counter++;



                                                                }
                                                                //printf("TEST%d",words_Counter);


                                                                while(!feof(fptr)){
                                                                    fscanf(fptr,"%lf %lf %lf",&points2[y].x2,&points2[y].y2,&points2[y].z2);
                                                                    fscanf(fptr,"%d %d %d",&points2[y].r,&points2[y].g,&points2[y].b);
                                                                    y++;

                                                                }

                                                                /*for(u=0;u<y-1;u++){
                                                                    printf("%lf %lf %lf ",points2[u].x2,points2[u].y2,points2[u].z2);
                                                                    printf("%d %d %d\n",points2[u].r,points2[u].g,points2[u].b);

                                                                }*/
                                                                int counter5,counter6;
                                                                double dots_Total=0,dots_Average,dots_Count=0;

                                                                for(counter5=0;counter5<y;counter5++){
                                                                    for(counter6=counter5+1;counter6<y-1;counter6++){
                                                                        dots_Total=dots_Total+sqrt( ((points2[counter5].x2-points2[counter6].x2)* (points2[counter5].x2-points2[counter6].x2))+ ((points2[counter5].y2-points2[counter6].y2)*(points2[counter5].y2-points2[counter6].y2))+((points2[counter5].z2-points2[counter6].z2)*(points2[counter5].z2-points2[counter6].z2)) );
                                                                        dots_Count++;


                                                                    }

                                                                }
                                                                dots_Average=dots_Total/dots_Count;
                                                                FILE *outptr;
                                                                char out_Name[30];
                                                                strcpy(out_Name,"output");
                                                                strcat(out_Name,nkt_Files[p]);
                                                                outptr=fopen(out_Name,"a");
                                                                fprintf(outptr,"\nSecim 5\nAverage length: %lf\n",dots_Average);
                                                                fclose(outptr);










                                                                break;
                                                            }else if(strcmp(files_Controls[t+1],data_Type_Binary)==0){
                                                                printf("\nThis file is Binary\n");
                                                                //x y z r g b binary kodlari buraya

                                                                fclose(fptr);
                                                                fptr=fopen(nkt_Files[p],"rb");


                                                                int binary_Word_Counter=0,search_Counter=0;
                                                                char ch;
                                                                while(!feof(fptr)){
                                                                    ch=fgetc(fptr);
                                                                    if(ch=='y'){
                                                                        search_Counter++;
                                                                    }
                                                                    if(search_Counter==3){
                                                                        break;
                                                                    }
                                                                    binary_Word_Counter++;

                                                                }
                                                                binary_Word_Counter=binary_Word_Counter+2;
                                                                //printf("binarywordc %d",binary_Word_Counter);


                                                                fseek(fptr,binary_Word_Counter,SEEK_SET);



                                                                int counter7=0,counter8;
                                                                while(!feof(fptr)){

                                                                    fread(&binpoints2[counter7].binx2,sizeof(float),1,fptr);
                                                                    fread(&binpoints2[counter7].biny2,sizeof(float),1,fptr);
                                                                    fread(&binpoints2[counter7].binz2,sizeof(float),1,fptr);
                                                                    fread(&binpoints2[counter7].binr,sizeof(int),1,fptr);
                                                                    fread(&binpoints2[counter7].bing,sizeof(int),1,fptr);
                                                                    fread(&binpoints2[counter7].binb,sizeof(int),1,fptr);

                                                                    counter7++;


                                                                }
                                                                 /*for(counter8=0;counter8<counter7-1;counter8++){
                                                                    printf("binary--> x:%f y:%f z:%f r:%d g:%d b:%d\n",binpoints2[counter8].binx2,binpoints2[counter8].biny2,binpoints2[counter8].binz2,binpoints2[counter8].binr,binpoints2[counter8].bing,binpoints2[counter8].binb);
                                                                }*/


                                                                int counter5,counter6;
                                                                double dots_Total=0,dots_Average=0,dots_Count=0;


                                                                for(counter5=0;counter5<counter7-1;counter5++){
                                                                    for(counter6=counter5+1;counter6<counter7-1;counter6++){
                                                                        dots_Total=dots_Total+sqrt( ((binpoints2[counter5].binx2-binpoints2[counter6].binx2)* (binpoints2[counter5].binx2-binpoints2[counter6].binx2))+ ((binpoints2[counter5].biny2-binpoints2[counter6].biny2)*(binpoints2[counter5].biny2-binpoints2[counter6].biny2))+((binpoints2[counter5].binz2-binpoints2[counter6].binz2)*(binpoints2[counter5].binz2-binpoints2[counter6].binz2)) );
                                                                        dots_Count++;



                                                                    }

                                                                }


                                                                dots_Average=dots_Total/dots_Count;
                                                                FILE *outptr;
                                                                char out_Name[30];
                                                                strcpy(out_Name,"output");
                                                                strcat(out_Name,nkt_Files[p]);
                                                                outptr=fopen(out_Name,"a");
                                                                fprintf(outptr,"\nSecim 5\nAverage length: %lf\n",dots_Average);

                                                                fclose(outptr);







                                                                break;

                                                            }else{
                                                            break;
                                                            }

                                                        }


                                                    }



                                                    break;


                                                }else{
                                                break;
                                                }



                                            }else{
                                            break;
                                            }

                                        }else{
                                        //x y z kodlari buraya
                                        printf("\nThis is X Y Z\n");
                                        int n;
                                        for(n=0;n<50;n++){
                                                        if(strcmp(files_Controls[n],"DATA")==0){
                                                            if(strcmp(files_Controls[n+1],data_Type_Ascii)==0){
                                                                printf("\nThis file is ASCII\n");
                                                                //x y z ascii kodlari buraya

                                                                fclose(fptr);
                                                                fptr=fopen(nkt_Files[p],"r");
                                                                //fseek(fptr,74,SEEK_SET);
                                                                int counter2=0,m;
                                                                //printf("%ld\n",ftell(fptr));


                                                                char words[900][20];
                                                                int words_Counter=0;

                                                                while(!feof(fptr)){
                                                                    fscanf(fptr,"%s",&words[words_Counter]);


                                                                    if(strcmp(words[words_Counter],"ascii")==0){
                                                                        break;

                                                                    }
                                                                    words_Counter++;



                                                                }
                                                                //printf("TEST%d",words_Counter);



                                                                while(!feof(fptr)){
                                                                    fscanf(fptr,"%lf %lf %lf",&points1[counter2].x1,&points1[counter2].y1,&points1[counter2].z1);

                                                                    counter2++;

                                                                }


                                                                int counter5,counter6;
                                                                double dots_Total=0,dots_Average=0,dots_Count=0;


                                                                for(counter5=0;counter5<counter2;counter5++){
                                                                    for(counter6=counter5+1;counter6<counter2-1;counter6++){
                                                                            dots_Total=dots_Total+sqrt( ((points1[counter5].x1-points1[counter6].x1)* (points1[counter5].x1-points1[counter6].x1))+ ((points1[counter5].y1-points1[counter6].y1)*(points1[counter5].y1-points1[counter6].y1))+((points1[counter5].z1-points1[counter6].z1)*(points1[counter5].z1-points1[counter6].z1)) );
                                                                            dots_Count++;

                                                                    }

                                                                }
                                                                dots_Average=dots_Total/dots_Count;
                                                                FILE *outptr;
                                                                char out_Name[30];
                                                                strcpy(out_Name,"output");
                                                                strcat(out_Name,nkt_Files[p]);
                                                                outptr=fopen(out_Name,"a");
                                                                fprintf(outptr,"\nSecim 5\nAverage length: %lf\n",dots_Average);


                                                                fclose(outptr);








                                                                choise=10;

                                                                break;
                                                            }else if(strcmp(files_Controls[n+1],data_Type_Binary)==0){
                                                                printf("\nThis file is Binary\n");
                                                                //x y z binary kodlari buraya

                                                                fclose(fptr);
                                                                fptr=fopen(nkt_Files[p],"rb");


                                                                int binary_Word_Counter=0,search_Counter=0;
                                                                char ch;
                                                                while(!feof(fptr)){
                                                                    ch=fgetc(fptr);
                                                                    if(ch=='y'){
                                                                        search_Counter++;
                                                                    }
                                                                    if(search_Counter==3){
                                                                        break;
                                                                    }
                                                                    binary_Word_Counter++;

                                                                }
                                                                binary_Word_Counter=binary_Word_Counter+2;
                                                                //printf("binarywordc %d",binary_Word_Counter);


                                                                fseek(fptr,binary_Word_Counter,SEEK_SET);



                                                                int counter7=0;
                                                                while(!feof(fptr)){

                                                                    fread(&binpoints1[counter7].binx1,sizeof(float),1,fptr);
                                                                    fread(&binpoints1[counter7].biny1,sizeof(float),1,fptr);
                                                                    fread(&binpoints1[counter7].binz1,sizeof(float),1,fptr);
                                                                    counter7++;


                                                                }
                                                                int counter8;


                                                                int counter5,counter6;
                                                                double dots_Total=0,dots_Average=0,dots_Count=0;


                                                                for(counter5=0;counter5<counter7-1;counter5++){
                                                                    for(counter6=counter5+1;counter6<counter7-1;counter6++){
                                                                        dots_Total=dots_Total+sqrt( ((binpoints1[counter5].binx1-binpoints1[counter6].binx1)* (binpoints1[counter5].binx1-binpoints1[counter6].binx1))+ ((binpoints1[counter5].biny1-binpoints1[counter6].biny1)*(binpoints1[counter5].biny1-binpoints1[counter6].biny1))+((binpoints1[counter5].binz1-binpoints1[counter6].binz1)*(binpoints1[counter5].binz1-binpoints1[counter6].binz1)) );
                                                                        dots_Count++;



                                                                    }

                                                                }


                                                                dots_Average=dots_Total/dots_Count;
                                                                FILE *outptr;
                                                                char out_Name[30];
                                                                strcpy(out_Name,"output");
                                                                strcat(out_Name,nkt_Files[p]);
                                                                outptr=fopen(out_Name,"a");
                                                                fprintf(outptr,"\nSecim 5\nAverage length: %lf\n",dots_Average);

                                                                fclose(outptr);

                                                                /*for(counter8=0;counter8<counter7-1;counter8++){
                                                                    printf("binary--> x:%f y:%f z:%f\n",binpoints1[counter8].binx1,binpoints1[counter8].biny1,binpoints1[counter8].binz1);
                                                                }*/





                                                                break;

                                                            }else{
                                                            break;
                                                            }

                                                        }


                                                    }



                                        break;
                                        }

                                    }else{
                                    break;
                                    }

                                }else{
                                break;
                                }

                            }else{
                                //printf("\nFaulty file\n");
                            break;
                            }

                        }




                }







                }else{
                printf("file can't open\n");
            }








            fclose(fptr);




     }





            choise=10;
            break;


    }//switch
}//while








    return 0;
}
