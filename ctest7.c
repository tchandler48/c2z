

    int I;

    char c;
    char ch;
    char test[5];


int main() 
{

    strcpy(ch, "l");
    printf("ch #1a = %s\n",ch);
    toupper(ch);
    printf("ch #1b -> %s\n",ch);

    strcpy(ch, "#");
    printf("ch #2a = %s\n",ch);
    toupper(ch);
    printf("ch #2b -> %s\n",ch);

    strcpy(test, "test");
    printf("test #3a = %s\n",test);
    for(I = 0; I < 4; I++)
    {
      ch = test[I];
      toupper(ch);
      test[I] = ch;
    }
    printf("test #3b -> %s\n",test);


}

