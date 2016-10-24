#include <stdio.h>
#include <string.h>
#include <memory.h>
void daozhuan(char s[],int len){//将字符串对调,例如123对调为321
    int j,t;
    for(j=0;j<len/2;j++){
        t=s[j];
        s[j]=s[len-j-1];
        s[len-j-1]=t;
    }
}
void sum(char s[],char a[],char b[]){//求a+b的和 s
    int i,j,lena,lenb,n,t;
    lena=strlen(a);
    lenb=strlen(b);
    n=(lena>lenb) ? lenb : lena;//n取两字符串中长度最小的值
    daozhuan(a,lena);//对调a与b,从个位逐个相加
    daozhuan(b,lenb);
    for(i=0;i<n;i++){
        s[i]=a[i]+b[i]-48;//从个位开始相加后存入s中(s中的元素允许有大于字符9的字符,此时不存在进位)
    }
    while(i<lena){//如果a的长度比b大,则将a中多余的位照搬进s中
        s[i]=a[i++]+s[i]-48;
    }
    while(i<lenb){//如果b的长度比a大,则将b中多余的位照搬进s中
        s[i]=b[i++]+s[i]-48;
    }
    j=0;
    while(j<i){//处理s中大于字符9的元素
        if(s[j]>'9'){
            t=s[j]-48;
            s[j]-=10*(t/10);
            s[j+1]+=t/10;
        }
        j++;
    }
    s[i+1]='\0';
    daozhuan(s,i+1);
}
void print(char s[],int len){
    int flag=1,i;
    for(i=0;i<len;i++){//从第一个不为0的元素开始,输出s的值;如果全部为0,结果输出0
        if(s[i]=='0' && flag && i!=len-1)
            continue;
        else{
            flag=0;
            printf("%c",s[i]);
        }
    }
    printf("\n");
}
int main(){
    char a[1002],b[1002],s[1002],ta[1002],tb[1002];
    int T,cnt=1;
    scanf("%d",&T);
    while(T--){
        if(cnt>1)printf("\n");  //在这里判断不是第一次就加空行
        scanf("%s%s",a,b);
        strcpy(ta,a);
        strcpy(tb,b);
        memset(s,'0',sizeof(s));
        sum(s,a,b);
        printf("Case %d:\n",cnt++);
        printf(ta);printf(" + ");printf(tb);
        printf(" = ");
        print(s,strlen(s));
    }
    return 0;
}