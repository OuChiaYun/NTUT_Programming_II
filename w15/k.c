#ifdef DEBUG
#define dbgprint(format, args...) \
    fprintf(stderr, format, ##args)
#else
#define dbgprint(format, args...)
#endif
int main()
{
    dbgprint("%s", __FILE__);
    return 0;
}