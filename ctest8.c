
    int I;

    char c;
    char ch;
    char test[7];

int main(int argc, char *argv[])
{
    printf("Test of ctest8\n");

    strcpy(test, "ABCDE");
    printf("test b4 = %s\n",test);
    tolower(test);
    printf("test after = %s\n",test);

    printf("End of ctest8\n");
}

