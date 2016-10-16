char * s_gets(char * st, int n)
{
    char * rev_val;
    int i = 0;

    rev_val = fgets(st, n, stdin);
    if (rev_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}