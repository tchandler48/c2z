

    int I;

    char c;
    char ch;
    char test[7];

int main(int argc, char *argv[])
{
    printf("Test of ctest7\n");

    strcpy(test, "abcde");
    printf("test b4 = %s\n",test);
    toupper(test);
    printf("test after = %s\n",test);

    printf("End of ctest7\n");
}

