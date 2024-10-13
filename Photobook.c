#include<stdio.h>
#include<string.h>
#include<math.h>
int f=0,f1=0,flag1=0,flag=0;
char b[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char ea[50],pass[50],rea[50],c,repass[50],ch[2],w;
FILE *ac;
int upc=0,digit=0,spc=0,lc=0;
void accountCreation()//This function is making for account creation or sign up.
{
    ac=fopen("photobook.txt","r");//Create a file to store information from the user.
    printf("Enter your E-mail address: ");
    scanf("%s",ea);
    int i=0,flag=0;
    while(!feof(ac))//Read the file for checking the email address.
    {
        c=getc(ac);
        if(c=='\n'){
            rea[i]='\0';
            i=0;
            if(flag==1){
                if(strcmp(rea,ea)==0){
                    flag1=1;
                    break;
                }
            }
            if(strcmp(rea,ea)==0){//compare to the user mail address with the storing mail address in the file.
                 flag=1;
            }
        }
        else{
            rea[i]=c;
            i++;
        }
    }
    if(flag==1){//check this e-mail address is not  new or old.
        printf("There is an account using this email.\n");
        printf("Please enter another email address for creating account\n");
        accountCreation();
    }
    else{//Given email address is new and request to the user for giving the password.
         ac=fopen("photobook.txt","a");
         fprintf(ac,"%s",ea);
         fprintf(ac,"\n");
         printf("Password Criteria:Password must be composed of at least one uppercase,");
         printf("at least one lower case English letter,");
         printf("at least one digit and at least one special character.\n");
         printf("                  The length of the password must be greater than or equal to six.\n");
         printf("                  Special characters are(.,!,@,#,$,*).\n");
         printf("Enter your password: ");
         scanf("%s",pass);
         fprintf(ac,"%s",pass);
         fprintf(ac,"\n");
         int len=strlen(pass);
         if(len<6){//check the password criteria.
            printf("Error: Password length must be >=6.\n");
         }
         else if(len>=6){
            for(int j=0;j<len;j++)
            {
                if(pass[j]>='A'&&pass[j]<='Z') upc++;//count uppercase letter
                else if(pass[j]>='a'&&pass[j]<='z')lc++;//count lowercase letter
                else if(pass[j]>='0'&&pass[j]<='9') digit++;//count digit
                else if(pass[j]=='.'||pass[j]=='!'||pass[j]=='@'||pass[j]=='#'||pass[j]=='$'||pass[j]=='*') spc++;//count special character
            }
        if(upc<1){
            printf("Error!! Password must contain at least one uppercase character.\n");
             }
        else if(lc<1){
                printf("Error!! Password must contain at least one lowercase character.\n");
             }
        else if(digit<1){
                printf("Error!! Password must contain at least one digit character.\n");
             }
        else if(spc<1){
                printf("Error!! Password must contain at least one special character.\n");
             }
        else if(upc>0&&lc>0&&digit>0&&spc>0&&len>=6){
                    printf("Re-type the password: ");
                    scanf("%s",repass);
                  if(strcmp(pass,repass)==0){
                        printf("Your account has been created successfully.\n");
                            }
                else{
                          printf("Error!! Your typed password,does not match with retyped password.\n");
                          printf("Re-type the password again: ");
                          scanf("%s",repass);
                          if(strcmp(pass,repass)==0){
                          printf("Your account has been created successfully.\n");
                            }
                     }
         }
         }
         fclose(ac);
         login();
     }
}
void login()
{
    printf("\n");
    printf(".................Login in your account given following information.................\n");
    ac=fopen("photobook.txt","r");//Open this file to read the e-mail address and password.
    printf("Enter your E-mail address: ");
    scanf("%s",ea);
    printf("Enter your password: ");
    scanf("%s",pass);
    int i=0,flag=0,flag1=0;
    while(!feof(ac))//read the file
    {
        c=getc(ac);
        if(c=='\n'){
            rea[i]='\0';
            i=0;
            if(flag==1){
                if(strcmp(rea,pass)==0){//compare to the password with the storing password in the file.
                    flag1=1;
                    break;
                }
                else{
                    break;
                }
            }
            if(strcmp(rea,ea)==0){//compare to the user mail address with the storing mail address in the file.
            flag=1;
        }
        }
        else{
            rea[i]=c;
            i++;
        }
    }
    if(flag==0) printf("E-mail is not found.\n");
    else if(flag1==0){
         printf("Password is incorrect.\n");
         login();
    }
    else {
            printf("Successfully login.\n");
            choiceZone();
         }
}
void max()//This function create for calculating maximum number.
{
    int n;
    printf("How many numbers do you want to calculate?\n");
    scanf("%d",&n);
    float a[n];
    printf("Enter your numbers: ");
    for(int i=0;i<n;i++)
    {
        scanf("%f",&a[i]);
    }
    float m=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>m){
            m=a[i];
        }
    }
    printf("The maximum number is: %.0f\n",m);
}
void min()//This function create for calculating minimum number.
{
    int n;
    printf("How many numbers do you want to calculate?\n");
    scanf("%d",&n);
    float a[n];
    printf("Enter your numbers: ");
    for(int i=0;i<n;i++)
    {
        scanf("%f",&a[i]);
    }
    float m=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]<m){
            m=a[i];
        }
    }
    printf("The minimum number is: %.0f\n",m);
}
void avg()//This function create for calculating average.
{
    int n;
    printf("How many numbers do you want to calculate?\n");
    scanf("%d",&n);
    double a[n];
    printf("Enter your numbers: ");
    for(int i=0;i<n;i++)
    {
        scanf("%lf",&a[i]);
    }
    double sum=0,avg;
    for(int i=0;i<n;i++) sum+=a[i];
    avg=sum/n;
    printf("The average is: %.2lf\n",avg);
}
void mean()////This function create for calculating mean.
{
    int n;
    printf("How many numbers do you want to calculate?\n");
    scanf("%d",&n);
    double a[n];
    printf("Enter your numbers: ");
    for(int i=0;i<n;i++)
    {
        scanf("%lf",&a[i]);
    }
    double sum=0,mean;
    for(int i=0;i<n;i++) sum+=a[i];
    mean=sum/n;
    printf("The mean is: %.2lf\n",mean);
}
void addition()////This function create for calculating addition.
{
    int n;
    printf("How many numbers do you want to calculate?\n");
    scanf("%d",&n);
    float a[n];
    printf("Enter your numbers: ");
    for(int i=0;i<n;i++)
    {
        scanf("%f",&a[i]);
    }
    float sum=0;
    for(int i=0;i<n;i++) sum+=a[i];
    printf("The addition is: %f\n",sum);
}
void fib()//This function create for calculating fibonacci series.
{
    int n,i;
    printf ("Enter the number of terms: ");
    scanf ("%d",&n);
    int A[n];
    A[0]=0;
    A[1]=1;
    for (i=2; i<n; i++)
    {
        A[i]= A[i-1] + A[i-2];
    }
    for (i=0; i<n; i++)
    {
        printf ("%d ", A[i]);
    }
}
void factorial()//This function create for calculating factorial.
{
    int n,i,fact;
    printf ("Enter any positive number: ");
    scanf ("%d", &n);
    fact=1;
    for (i=1; i<=n; i++)
    {
        fact = fact * i;
    }
    printf ("The factorial is: %d\n", fact);
}
void multiplication()////This function create for calculating multiplication.
{
   int n;
    printf("How many numbers do you want to calculate?\n");
    scanf("%d",&n);
    double a[n];
    printf("Enter your numbers: ");
    for(int i=0;i<n;i++)
    {
        scanf("%lf",&a[i]);
    }
    double m=1;
    for(int i=0;i<n;i++) m*=a[i];
    printf("The multiplication is: %.2lf\n",m);
}
void subtraction()//This function create for calculating subtraction.
{
    int n;
    printf("How many numbers do you want to calculate?\n");
    scanf("%d",&n);
    float a[n];
    printf("Enter your numbers: ");
    for(int i=0;i<n;i++)
    {
        scanf("%f",&a[i]);
    }
    float sub=a[0];
    for(int i=1;i<n;i++) sub-=a[i];
    printf("The subtraction is: %f\n",sub);
}
void division()////This function create for calculating division.
{
   int n;
    printf("How many numbers do you want to calculate?\n");
    scanf("%d",&n);
    double a[n];
    printf("Enter your numbers: ");
    for(int i=0;i<n;i++)
    {
        scanf("%lf",&a[i]);
    }
    double div=a[0]/a[1];
    for(int i=2;i<n;i++) div/=a[i];
    printf("The division is: %lf\n",div);
}
void circle()//This function create for calculating area of the circle.
{
    double radius, area;
    printf ("Enter radius = ");
    scanf ("%lf", &radius);
    area = M_PI* radius * radius;
    printf ("The area of circle = %.2lf\n", area);
}
void triangle()////This function create for calculating area of the triangle.
{
    printf("Press 'a' if given the three sides of the triangle....\n");
    printf("Press 'b' if given the height and base of the triangle....\n");
    printf("Select your choice: ");
    scanf("%s",ch);
    if(ch[0]=='a'){
         double a, b, c, s, area;
         printf ("Enter three values: ");
         scanf ("%lf%lf%lf",&a,&b,&c);
         s = (a+b+c)/2;
         area = sqrt (s*(s-a)*(s-b)*(s-c));
         printf ("Area of triangle: %.2lf\n", area);
    }
    else if(ch[0]=='b'){
         double base, height, area;
         printf ("Base = ");
         scanf ("%lf", &base);
         printf ("Height = ");
         scanf ("%lf", &height);
         area = (double)1/2 * base * height;
         printf ("The area is = %.2lf\n", area);
    }
}
void rectangle()//This function create for calculating area of the rectangle.
{
    double length, width, area;
    printf ("Enter length = ");
    scanf ("%lf",&length);
    printf ("Enter width = ");
    scanf ("%lf",&width);
    area = length*width;
    printf ("The area of rectangle = %.2lf\n", area);
}
void multiplicationTable()//This function create for calculating multiplication table.
{
    int num,i;
    printf ("Enter any integer number: ");
    scanf ("%d",&num);
    for (i=1;i<=10;i++)
    {
        printf ("%d x %d = %d\n",num,i,num*i);
    }
}
void sort()//This function create for calculating sort of the number.
{
    int c,n,i,j,temp;
    printf("Choice \t Operation\n");
    printf("............................\n");
    printf("1  \t Ascending Order\n");
    printf("2   \t Descending Order\n");
    printf("............................\n");
    printf("Select your choice for sorting: ");
    scanf("%d",&c);
    printf("Enter the number of elements in array: ");
    scanf ("%d",&n);
    int a[n];
    printf("Enter elements in an array: ");
    for(i=0;i<n;i++)
    {
        printf("a[%d]= ",i);
        scanf ("%d",&a[i]);
    }
    //outer loop
    for(i=0;i<n-1;i++)
    {
      //inner loop
      for(j=0;j<n-i-1;j++)
      {
          if(a[j]>a[j+1]){
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
      }
    }
    }
    if(c==1){
    printf("After sorting in ascending order: ");
    for(i=0;i<n;i++)
    {
        printf ("%d ",a[i]);
    }
    }
    else if(c==2){
        printf("After sorting in descending order: ");
        for(i=n-1;i>=0;i--)
            {
               printf ("%d ",a[i]);
            }
    }
    printf("\n");
}

void area()
{
    printf("...........................................\n");
    printf("Press 'a' for Triangle...\n");
    printf("Press 'b' for Rectangle...\n");
    printf("Press 'c' for Circle...\n");
    printf("Press B for previous interface....\n");
    printf("...........................................\n\n");
    while(1)
    {
        jump:
        printf("Select your choice for calculating area: ");
        scanf("%s",ch);
        if(ch[0]=='a') triangle();
        else if(ch[0]=='b') rectangle();
        else if(ch[0]=='c') circle();
        else if(ch[0]=='B'){
            calculator();
            break;
        }
        else{
            printf("Invalid choice!! Please enter valid choice!!\n");
            goto jump;
        }
    }
}
void deci_bin()//decimal to binary
{
    int num;
    printf("Enter your decimal number to convert binary: ");
    scanf("%d",&num);
    int a[10005],k=0;
    while(num!=0)
    {
        a[k]=num%2;
        k++;
        num=num/2;
    }
    printf("The binary number is: ");
    for(int i=k-1;i>=0;i--) printf("%d",a[i]);
    printf("\n");
}
void deci_hex()//decimal to hexadecimal
{
    int num;
    printf("Enter your decimal number to convert hexadecimal: ");
    scanf("%d",&num);
      char h[15];
      int k=0,r;
      int deci=num;
     while(deci!=0)
      {
      r=deci%16;
      if(r>9){
        h[k]=(char)(r+55);//ASCII value: A=65,B=66,C=67,D=68,E=69,F=70
      }
      else{
        h[k]=(char)(r+48);//ASCII value: 0=48,1=49,2=50,3=51,4=52,5=53,6=54,7=55,8=56,9=57
      }
      deci=deci/16;
      k++;
  }
    h[k]='\0';
    strrev(h);
    printf("The hexadecimal number is:%s",h);
    printf("\n");
}
void bin_deci()//binary to decimal
{
    int num;
    printf("Enter your binary number to convert decimal: ");
    scanf("%d",&num);
    int i=0,r,deci=0;
    while(num!=0)
    {
        r=num%10;
        deci=deci+r*pow(2,i);
        i++;
        num=num/10;
    }
    printf("The decimal number is: %d\n",deci);
}
void hex_deci()//hexadecimal to decimal
{
    char num[1005];
    printf("Enter your hexadecimal number to convert decimal: ");
    scanf("%s",num);
    int k=0,r,deci=0,d=0;
    int l=strlen(num);
       for(int i=l-1;i>=0;i--)
    {
        num[i]=(int)(num[i]);
        if(num[i]<58){
            d=num[i]-48;
            deci=deci+d*pow(16,k);
        }
        else{
            d=num[i]-55;
            deci=deci+d*pow(16,k);
        }
        k++;
    }
    printf("The decimal number is: %d\n",deci);
}
void bin_hex()//binary to hexadecimal
{
     int num;
    printf("Enter your binary number to convert hexadecimal: ");
    scanf("%d",&num);
    int i=0,r,deci=0;
    //binary to decimal
    while(num!=0)
    {
        r=num%10;
        deci=deci+r*pow(2,i);
        i++;
        num=num/10;
    }
    char h[15];
    int k=0,r1;
    //decimal to hexadecimal
     while(deci!=0)
      {
      r1=deci%16;
      if(r1>9){
        h[k]=(char)(r1+55);//ASCII value: A=65,B=66,C=67,D=68,E=69,F=70
      }
      else{
        h[k]=(char)(r1+48);//ASCII value: 0=48,1=49,2=50,3=51,4=52,5=53,6=54,7=55,8=56,9=57
      }
      deci=deci/16;
      k++;
  }
    h[k]='\0';
    strrev(h);
    printf("The hexadecimal number is:%s",h);
    printf("\n");
}
void hex_bin()//hexadecimal to binary
{
    char num[1005];
    printf("Enter your hexadecimal number to convert binary: ");
    scanf("%s",num);
    //hexadecimal to decimal
    int k=0,r,deci=0,d=0;
    int l=strlen(num);
       for(int i=l-1;i>=0;i--)
    {
        num[i]=(int)(num[i]);
        if(num[i]<58){
            d=num[i]-48;
            deci=deci+d*pow(16,k);
        }
        else{
            d=num[i]-55;
            deci=deci+d*pow(16,k);
        }
        k++;
    }
    //decimal to binary
    int a[10005],k1=0;
    while(deci!=0)
    {
        a[k1]=deci%2;
        k1++;
        deci=deci/2;
    }
    printf("The binary number is: ");
    for(int i=k1-1;i>=0;i--) printf("%d",a[i]);
    printf("\n");
}
void oct_hex()
{
    int num;
    printf("Enter your octal number to convert hexadecimal: ");
    scanf("%d",&num);
    //octal to decimal
    int i=0,r,deci=0;
        while(num!=0)
    {
        r=num%10;
        deci=deci+r*pow(8,i);
        i++;
        num=num/10;
    }
    //decimal to hexadecimal
    char h[15];
    int k=0,r1;
     while(deci!=0)
      {
      r1=deci%16;
      if(r1>9){
        h[k]=(char)(r1+55);//ASCII value: A=65,B=66,C=67,D=68,E=69,F=70
      }
      else{
        h[k]=(char)(r1+48);//ASCII value: 0=48,1=49,2=50,3=51,4=52,5=53,6=54,7=55,8=56,9=57
      }
      deci=deci/16;
      k++;
  }
    h[k]='\0';
    strrev(h);
    printf("The hexadecimal number is:%s",h);
    printf("\n");
}
void hex_oct()//hexadecimal to octal
{
   char num[1005];
    printf("Enter your hexadecimal number to convert octal: ");
    scanf("%s",num);
    //hexadecimal to decimal
    int k=0,r,deci=0,d=0;
    int l=strlen(num);
       for(int i=l-1;i>=0;i--)
    {
        num[i]=(int)(num[i]);
        if(num[i]<58){
            d=num[i]-48;
            deci=deci+d*pow(16,k);
        }
        else{
            d=num[i]-55;
            deci=deci+d*pow(16,k);
        }
        k++;
    }
    //decimal to octal
    int a[10005],k1=0;
    while(deci!=0)
    {
        a[k1]=deci%8;
        k1++;
        deci=deci/8;
    }
    printf("The octal number is: ");
    for(int i=k1-1;i>=0;i--) printf("%d",a[i]);
    printf("\n");
}
void numberConversion()
{
    printf("Choice    \tNumber Conversion\n");
    printf("...........................................\n");
    printf("a     \t        Binary to Decimal\n");
    printf("b     \t        Decimal to Binary\n");
    printf("c     \t        Binary to Hexadecimal\n");
    printf("d     \t        Hexadecimal to Binary\n");
    printf("e     \t        Decimal to Hexadecimal\n");
    printf("f     \t        Hexadecimal to Decimal\n");
    printf("g     \t        Octal to Hexadecimal\n");
    printf("h     \t        Hexadecimal to Octal\n");
    printf("B     \t        Previous interface\n");
    printf("...........................................\n\n");
    while(1)
    {
    jump:
    printf("\nSelect your choice for converting number: ");
    scanf("%s",ch);
    if(ch[0]=='a') bin_deci();//calling function binary to decimal
    else if(ch[0]=='b') deci_bin();//calling function decimal to binary
    else if(ch[0]=='c') bin_hex();//calling function binary to hexadecimal
    else if(ch[0]=='d') hex_bin();//calling function hexadecimal to binary
    else if(ch[0]=='e') deci_hex();//calling function decimal to hexadecimal
    else if(ch[0]=='f') hex_deci();//calling function hexadecimal to decimal
    else if(ch[0]=='g') oct_hex();//calling function octal to hexadecimal
    else if(ch[0]=='h') hex_oct();//calling function hexadecimal to octal
    else if(ch[0]=='B'){
        calculator();
        break;
    }
    else{
        printf("Invalid choice!! Please enter valid choice!!\n");
        goto jump;
    }
    }
}
void calculator()
{
    printf("..............................................\n");
    printf("Press a for Max....\n");
    printf("Press b for Min....\n");
    printf("Press c for Avg....\n");
    printf("Press d for Mean....\n");
    printf("Press e for Addition....\n");
    printf("Press f for Subtraction....\n");
    printf("Press g for Multiplication....\n");
    printf("Press h for Division....\n");
    printf("Press i for Factorial....\n");
    printf("Press j for Fibonacci....\n");
    printf("Press k for Area Calculator....\n");
    printf("Press l for Number Conversion....\n");
    printf("Press m for Multiplication Table....\n");
    printf("Press n for Sort a list of elements....\n");
    printf("Press B for previous interface....\n");
    printf("..............................................\n\n");
    while(1)
    {
         printf("\n");
         jump:
         printf("Enter your choice what do you want from the calculator: ");
         scanf("%s",ch);
         if(ch[0]=='a') max();
         else if(ch[0]=='b') min();
         else if(ch[0]=='c') avg();
         else if(ch[0]=='d') mean();
         else if(ch[0]=='e') addition();
         else if(ch[0]=='f') subtraction();
         else if(ch[0]=='g') multiplication();
         else if(ch[0]=='h') division();
         else if(ch[0]=='i') factorial();
         else if(ch[0]=='j') fib();
         else if(ch[0]=='k') area();
         else if(ch[0]=='l') numberConversion();
         else if(ch[0]=='m') multiplicationTable();
         else if(ch[0]=='n') sort();
         else if(ch[0]=='B') {
            choiceZone();
            break;
         }
         else{
            printf("Invalid choice!! Please enter valid choice!!\n");
            goto jump;
         }
    }
}
void homePage()
{
    printf("\n");
    printf("\t\t\t\t\t.....................................................................\n");
    printf("\t\t\t\t\t|\t         Please Choose Your Operation                       |\n");
    printf("\t\t\t\t\t.....................................................................\n");
    printf("\t\t\t\t\t|\t    Choice             |         Operation Name             |\n");
    printf("\t\t\t\t\t.....................................................................\n");
    printf("\t\t\t\t\t|\t      'a'                |\t Account Creation           |\n");
    printf("\t\t\t\t\t.....................................................................\n");
    printf("\t\t\t\t\t|\t      'b'                |\t Account Login              |\n");
    printf("\t\t\t\t\t.....................................................................\n");
    printf("\t\t\t\t\t|\t      'Q'                |\t Account Logout             |\n");
    printf("\t\t\t\t\t.....................................................................\n");
    printf("\n");
    while(f1==0)
    {
        jump:
        printf("Please enter your choice from our photobook system: ");
        scanf("%s",ch);
        if(ch[0]=='a') accountCreation();
        else if(ch[0]=='b') login();
        else if(ch[0]=='Q'){
            f=1;
            main();
            break;
        }
        else{
            printf("Invalid choice!! Please enter valid choice!!\n");
            goto jump;
        }
    }
}
void draw_board()
{
    system("cls");
    printf("\t\t\t\t      T i c  T a c  T o e  G a m e\n");
    printf("\n");
    printf("\t\t\t\t\t        |       |       \n");
    printf("\t\t\t\t\t    %c   |   %c   |   %c   \n",b[0][0],b[0][1],b[0][2]);
    printf("\t\t\t\t\t -----------------------\n");
    printf("\t\t\t\t\t        |       |       \n");
    printf("\t\t\t\t\t    %c   |   %c   |   %c   \n",b[1][0],b[1][1],b[1][2]);
    printf("\t\t\t\t\t -----------------------\n");
    printf("\t\t\t\t\t    %c   |   %c   |   %c   \n",b[2][0],b[2][1],b[2][2]);
    printf("\t\t\t\t\t        |       |       \n");
}
void player_turn(int position,int count)
{
    if(count%2!=0){
        if(position==1&&b[0][0]=='1'&&b[0][0]!='X'&&b[0][0]!='O'){
            b[0][0]='X';
        }
        else if(position==2&&b[0][1]=='2'&&b[0][1]!='X'&&b[0][1]!='O'){
            b[0][1]='X';
        }
        else if(position==3&&b[0][2]=='3'&&b[0][2]!='X'&&b[0][2]!='O'){
            b[0][2]='X';
        }
        else if(position==4&&b[1][0]=='4'&&b[1][0]!='X'&&b[1][0]!='O'){
            b[1][0]='X';
        }
        else if(position==5&&b[1][1]=='5'&&b[1][1]!='X'&&b[1][1]!='O'){
            b[1][1]='X';
        }
        else if(position==6&&b[1][2]=='6'&&b[1][2]!='X'&&b[1][2]!='O'){
            b[1][2]='X';
        }
        else if(position==7&&b[2][0]=='7'&&b[2][0]!='X'&&b[2][0]!='O'){
            b[2][0]='X';
        }
        else if(position==8&&b[2][1]=='8'&&b[2][1]!='X'&&b[2][1]!='O'){
            b[2][1]='X';
        }
        else if(position==9&&b[2][2]=='9'&&b[2][2]!='X'&&b[2][2]!='O'){
            b[2][2]='X';
        }
        else if(position>=10){
            printf("Invalid move!!\nPlease choose the valid move!!\n");
            printf("First player turn: ");
            count=count;
            scanf("%d",&position);
            player_turn(position,count);
        }
            else{
            printf("Box is already filled!!\nTry to again!!\n");
            printf("First player turn: ");
            count=count;
            scanf("%d",&position);
            player_turn(position,count);
        }
    }
    else if(count%2==0){
        if(position==1&&b[0][0]=='1'&&b[0][0]!='X'&&b[0][0]!='O'){
            b[0][0]='O';
        }
        else if(position==2&&b[0][1]=='2'&&b[0][1]!='X'&&b[0][1]!='O'){
            b[0][1]='O';
        }
        else if(position==3&&b[0][2]=='3'&&b[0][2]!='X'&&b[0][2]!='O'){
            b[0][2]='O';
        }
        else if(position==4&&b[1][0]=='4'&&b[1][0]!='X'&&b[1][0]!='O'){
            b[1][0]='O';
        }
        else if(position==5&&b[1][1]=='5'&&b[1][1]!='X'&&b[1][1]!='O'){
            b[1][1]='O';
        }
        else if(position==6&&b[1][2]=='6'&&b[1][2]!='X'&&b[1][2]!='O'){
            b[1][2]='O';
        }
        else if(position==7&&b[2][0]=='7'&&b[2][0]!='X'&&b[2][0]!='O'){
            b[2][0]='O';
        }
        else if(position==8&&b[2][1]=='8'&&b[2][1]!='X'&&b[2][1]!='O'){
            b[2][1]='O';
        }
        else if(position==9&&b[2][2]=='9'&&b[2][2]!='X'&&b[2][2]!='O'){
            b[2][2]='O';
        }
        else if(position>=10){
            printf("Invalid move!!\nPlease choose the valid move!!\n");
            printf("Second player turn: ");
            count=count;
            scanf("%d",&position);
            player_turn(position,count);
        }
        else{
            printf("Box is already filled!!\nTry to again!!\n");
            printf("Second player turn: ");
            count=count;
            scanf("%d",&position);
            player_turn(position,count);
        }
    }
}
char game_result()
{
     if(b[0][0]=='X'&&b[0][1]=='X'&&b[0][2]=='X') return 'X';//1st row
     else if(b[1][0]=='X'&&b[1][1]=='X'&&b[1][2]=='X') return 'X';//2nd row
     else if(b[2][0]=='X'&&b[2][1]=='X'&&b[2][2]=='X') return 'X';//3rd row
     else if(b[0][0]=='X'&&b[1][0]=='X'&&b[2][0]=='X') return 'X';//1st column
     else if(b[0][1]=='X'&&b[1][1]=='X'&&b[2][1]=='X') return 'X';//2nd column
     else if(b[0][2]=='X'&&b[1][2]=='X'&&b[2][2]=='X') return 'X';//3rd column
     else if(b[0][0]=='X'&&b[1][1]=='X'&&b[2][2]=='X') return 'X';//1st diagonal
     else if(b[0][2]=='X'&&b[1][1]=='X'&&b[2][0]=='X') return 'X';//2nd diagonal
     else if(b[0][0]=='O'&&b[0][1]=='O'&&b[0][2]=='O') return 'O';//1st row
     else if(b[1][0]=='O'&&b[1][1]=='O'&&b[1][2]=='O') return 'O';//2nd row
     else if(b[2][0]=='O'&&b[2][1]=='O'&&b[2][2]=='O') return 'O';//3rd row
     else if(b[0][0]=='O'&&b[1][0]=='O'&&b[2][0]=='O') return 'O';//1st column
     else if(b[0][1]=='O'&&b[1][1]=='O'&&b[2][1]=='O') return 'O';//2nd column
     else if(b[0][2]=='O'&&b[1][2]=='O'&&b[2][2]=='O') return 'O';//3rd column
     else if(b[0][0]=='O'&&b[1][1]=='O'&&b[2][2]=='O') return 'O';//1st diagonal
     else if(b[0][2]=='O'&&b[1][1]=='O'&&b[2][0]=='O') return 'O';//2nd diagonal
     else return '1';
}
void ticTac()
{
    int count=1,position;
    draw_board();
    printf("First player will place 'X'\n");
    printf("Second player will place 'O'\n");
    while(count!=10){
        if(count%2!=0){
                printf("\n");
        printf("First player turn: ");
        scanf("%d",&position);
        player_turn(position,count);
        count++;
    }
    else if(count%2==0){
            printf("\n");
        printf("Second player turn: ");
        scanf("%d",&position);
        player_turn(position,count);
        count++;
    }
    draw_board();
    w=game_result();
    if(w=='X'){
        printf("The first player is winner!!\n");
        break;
    }
    else if(w=='O'){
        printf("The second player is winner!!\n");
        getchar();
        break;
    }
    else if(w=='1'&&count==10){
        printf("The match is draw!!\n");
        break;
    }
    }
}
void gamesZone()
{
    printf("..............................................\n");
    printf("Press 'a' for Tic Tac Toe (3X3) board\n");
    printf("Press 'B' for previous interface\n");
    printf("..............................................\n");
    while(1)
    {
        jump:
        printf("Select your choice from the games zone: ");
        scanf("%s",ch);
        if(ch[0]=='a') ticTac();
        else if(ch[0]=='B'){
            homePage();
            break;
        }
        else{
            printf("Invalid Choice!! Please enter valid choice!!.\n");
            goto jump;
        }
    }
}
void choiceZone()
{
    printf("..............................................\n");
    printf("Press 'c' for Calculator.....\n");
    printf("Press 'g' for GamesZone.....\n");
    printf("press 'q' to logout and goto the login in interface.\n");
    printf("..............................................\n");
    while(f1==0)
    {
            jump:
            printf("Select your choice: ");
            scanf("%s",ch);
            if(ch[0]=='c') calculator();
            else if(ch[0]=='g') gamesZone();
            else if(ch[0]=='q'){
                homePage();
                break;
            }
            else{
                printf("Enter Correct Key Again!\n");
                goto jump;
            }
    }
}
int main()
{
    while(1)
    {
        if(f==1){
                f1=1;
              break;
        }
        else if(f==0){
        printf("\t\t\t\t\t....................Welcome To Photobook System....................\n");
        homePage();
    }
     }
    return 0;
}

