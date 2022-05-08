#include<stdio.h>


// void strcpy(char* str1,char* str2, offset){
//     for(int i=0;i<offset;i++){
//         str1[i]=str2[i];
//     }
//     str1[offset]='0';
// }

int mycmp(char* str1, char*str2){
    int count=0;
    while(str1[count]!=0&&str2[count]!=0){
        if(str1[count]==str2[count]) count++;
        else return 0;
    }
    if(str1[count]==0&&str2[count]==0) return 1;
    return 0;
}

int main(){
    int count=0;
    char name[128][7]={0};
    int  credits[128] ={0};
    //三维数组，第二维是一个or，也就是第三维满足一个就算成功
    char condition[128][10][10][7]={0};
    int  con_count[128]={0};
    int score[128]={0};

    //int reverse[128]={0};
    //录入
    //printf("input\n");
    while(1){
        //name
        char ch;
        scanf("%c",&ch);
        if(ch==' '||ch=='\n') break;
        int len=0;
        while(ch!='|'){
            name[count][len++] = ch;
            scanf("%c",&ch);
        }
        //printf("%s\n",name[count]);

        //credits
        scanf("%c\n",&ch);
        credits[count]=ch-'0';
        //printf("%d\n",credits[count]);


        //condition
        scanf("%c",&ch);
        scanf("%c",&ch);
        if(ch!='|'){
            int orcount=0;
            int andcount=0;
            int namec=0;
            while(1){

                if(ch!=','&&ch!=';'&&ch!='|'){
                    condition[count][orcount][andcount][namec++]=ch;
                }
                else if(ch==',') {
                    andcount++;
                    namec=0;
                }
                else {
                    orcount++;
                    andcount=0;
                    namec=0;
                }

                if(ch=='|') break;
                scanf("%c",&ch);
            }
        }

        scanf("%c",&ch);
        if(ch=='A') score[count]=4;
        else if( ch=='B') score[count]=3;
        else if(ch == 'C') score[count]=2;
        else if(ch=='D') score[count]=1;
        else if(ch=='F') score[count]=0;
        
        if(ch=='\n') {
            score[count++]=-1;
            continue;
        }
        //printf("%d\n",score[count]);
        scanf("%c",&ch);
        count++;

    }
    // printf("test:%s\n",condition[1][0][0]);
    // printf("test:%s\n",condition[1][1][0]);
    // printf("test:%s\n",condition[1][1][1]);
    // printf("test:%s\n",condition[1][1][2]);
    int i=0;
    int attemp=0;
    int complete=0;
    int totalA=0;
    int need=0;
    for(i=0;i<count;i++){

        //printf("%s\n",name[i]);

        if(score[i]==0){
            attemp+=credits[i];
           
        }
        else if(score[i]==-1){
            
        }
        else{
            attemp+=credits[i];
            complete+=credits[i];
        }
        if(score[i]!=-1) totalA+=credits[i]*score[i];
        need+=credits[i];
    }

    double GPA=totalA;
    if(attemp==0) GPA=0;
    else GPA = GPA/attemp;
    need-=complete;
    printf("GPA: %.1lf\n",GPA);
    printf("Hours Attempted: %d\n",attemp);
    printf("Hours Completed: %d\n",complete);
    printf("Credits Remaining: %d\n",need);
    printf("\nPossible Courses to Take Next\n");
    //char condition[128][10][10][7]={0};
    int j=0;
    int k=0;
    int l=0;
    int count2=0;
    for(i=0;i<count;i++){
        if(score[i]>0) continue;
        int flagi=0;
        if(condition[i][0][0][0]==0) {
            //printf("%c\n",condition[count][0][0][0]);
            flagi=1;
        }
        else{
            //每一个j代表一个且条件，只要有一个j能同时满足就行
            for(j=0;j<8;j++){
                
                if(condition[i][j][0][0]==0) break;

                int flagj=1;
                //k循环判断每一个且里面的条件，有一个不满足j就跳下一个
                for(k=0;k<8;k++){
                    if(condition[i][j][k][0]==0) {
                        break;
                    }
                    int flagk=0;
                    //便利l，有一个是就是
                    for(int l=0;l<count;l++){
                        //printf("%s :: %s\n",name[l],condition[i][j][k]);
                        if(mycmp(name[l],condition[i][j][k])==1&&score[l]>0){
                            
                            flagk=1;
                            break;
                        }
                    }
                    if(flagk!=1){
                        flagj=0;
                        break;
                    }   
                }
                if(flagj==1){
                    flagi=1;
                    break;
                }
            }
        }
        if(flagi==1){
            count2++;
            printf("  %s\n",name[i]);
        }

    }
    if(need==0){
        printf("  None - Congratulations!\n");
    }
    getchar();


    

}
/*
c53|2||B
c40|5|c28,c26,c9,c25,c23,c38,c17;c53,c34,c18,c33,c47,y7;c2,c8,c3;c38,c18,c27;c18,c23,c38,c20,c39,c0,c32|B
c34|4|c17;c20,c16,c21,c9,c25;c3,c1,c23,c31,c2,c20|C
c18|3|c7,c3,c2,c13,c0,c15,c1;c6,c10,c14;c13;c17,c8,c0,c5,c13;c11,c2,c12;c1,c8,c7,c6|F
c33|4|c31,c4,c12,c15,c20,c28;c24,c28,c21,c12;c24;c25,c31,c22,c14;c13,c25,c23,c31,c15;c3,c2,c28,c5,c30,c16|C
c47|5|c11,c0;c20,c11,c32;c22,c39,c34;c5,c42,c3|C
c15|2||C
*/