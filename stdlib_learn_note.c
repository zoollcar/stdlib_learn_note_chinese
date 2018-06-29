#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void test(){ printf("do this at exit\n"); }
int cmptest(const void * a, const void * b){
    return (int)( *(char*)a - *(char*)b );
}
int main (){
///
/// ## 数据类型
///
 
/// ### size_t是sizeof关键词的值，无符号整形
    printf("size_t %d\n",sizeof(size_t));
    
/// ### wchar_t 宽字符类型
    printf("wchar_t %d\n",sizeof(wchar_t));
    
    
/// ### div_t与ldiv_t结构体 作为 div 的返回值
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c
/// typedef struct {
///     int quot; // 商
///     int rem;  // 余数
/// } div_t;

    div_t div_t_timp;
    printf("div_t %d  div_t.quot %d div_t.rem %d\n",
    sizeof(div_t),sizeof(div_t_timp.quot),sizeof(div_t_timp.rem));
/// //-------------------------------
/// typedef struct {
///     long int quot; // 商
///     long int rem;  // 余数
/// } ldiv_t;
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    ldiv_t ldiv_t_timp;
    printf("ldiv_t %d  ldiv_t.quot %d ldiv_t.rem %d\n",
    sizeof(ldiv_t),sizeof(ldiv_t_timp.quot),sizeof(ldiv_t_timp.rem));
    
    
///
/// ## 宏
///
    
/// ### EXIT_SUCCESS 和 EXIT_FAILURE
/// exit函数成功退出和失败的返回值
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c
/// #define EXIT_SUCCESS	0
/// #define EXIT_FAILURE	1
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    printf("EXIT_SUCCESS %d\nEXIT_FAILURE %d\n",EXIT_SUCCESS,EXIT_FAILURE);
    
    
/// ### RAND_MAX rand 函数返回的最大的数
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c
/// #define RAND_MAX	0x7FFF
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    printf("RAND_MAX %d\n",RAND_MAX);

    
/// ### MB_CUR_MAX 一个多字节字符的最大字节数
/// 头文件中的处理比较复杂
    printf("MB_CUR_MAX %d\n",MB_CUR_MAX);
    
    
///
/// ## 函数
///
    
/// ### 将字符串转换为 double
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c
/// double atof (const char *);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    printf("atof(\"12.3\") %f\n",atof("12.3"));
    
/// ### 将字符串转换为 int
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c
/// int atoi (const char *);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    printf("atoi(\"12\") %d\n",atoi("12"));
    
/// ### 将字符串转换为 long int
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c
/// long atol (const char *);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    printf("atol(\"123456789\") %ld\n",atol("123456789"));
    
/// ### 将以数字开头的字符串转换为 double
/// str 是一个以数字开头的字符串，
/// 返回把 str 转换后的 double ， endptr 指向第一个不是数字的字符
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c
/// double strtod(const char *str, char **endptr)
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    char *p;
    printf("strtod(\"12.030 hello\",&p) %f",strtod("12.030hello",&p));
    printf(" %s\n",p);
    
/// ### 将以数字开头的字符串转换为 long int
/// str 是一个以数字开头的字符串，
/// 返回把 str 以 base 为基数（进制）转换后的 long int ，
/// endptr 指向第一个不是数字的字符
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c
/// long int strtol(const char *str, char **endptr, int base)
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    printf("strtol(\"ffhello\",&p,16) %ld",strtol("ffhello",&p,16));
    printf(" %s\n",p);
    
/// ### str 是一个以数字开头的字符串，
/// 返回把 str 以 base 为基数 转换后的 unsigned long int ，
/// endptr 指向第一个不是数字的字符
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c
/// unsigned long int strtoul(const char *str, char **endptr, int base)
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    printf("strtoul(\"ffhello\",&p,16) %uld",strtoul("ffhello",&p,16));
    printf(" %s\n",p);
    
/// ### 分配请求的内存大小(nitems * size)并返回指向它的指针
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c
/// void *calloc(size_t nitems, size_t size)
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    p = (char *)calloc(5, sizeof(char));
    printf("calloc(5, sizeof(char))  %p\n",p);
    
/// ### 分配请求的内存(size)并返回指向它的指针
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c
/// void *malloc(size_t size)
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    /* p = (char *)calloc(5 * sizeof(char)); */
    
/// ### 调整之前分配的内存块大小
/// * ptr 执行要调整的内存块
/// * size 要调整到的字节数
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c
/// void *realloc(void *ptr, size_t size)
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    p = realloc(p,10*sizeof(char));
    printf("realloc(p,10*sizeof(char))  %p\n",p);
    p = realloc(p,10000*sizeof(char));
    printf("realloc(p,10000*sizeof(char))  %p\n",p);
    
/// ### 回收先前分配的内存
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c
/// void free(void *ptr)
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    free(p);
    
/// ### 搜索环境变量并返回字符串
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c
/// char *getenv(const char *name)
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    printf("getenv(\"PATH\")  %.30s ...\n", getenv("PATH"));
    
/// ### 把命令(string)传递给主机由主机执行
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c
/// int system(const char *string)
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    printf("system(\"echo ok\")\n");
    system("echo ok");
    
/// ### 快速排序
/// * base是数组的基地址 
/// * nitems是数组的元素个数 
/// * size是数组元素大小
/// * compar是比较函数，靠返回值正负来比较，为0的情况未定义
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c
/// void qsort(void *base, size_t nitems, size_t size,
///                 int (*compar)(const void *, const void*))
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    p = (char *)calloc(11, sizeof(char));
    strcpy(p,"5147096382");
    qsort(p,10,sizeof(char),cmptest);
    printf("qsort  ");
    printf(p);
    putchar('\n');
    
/// ### 二分查找
/// * key是要查找的元素 
/// * base是数组的基地址 
/// * num是数组的元素个数 
/// * size数组元素大小
/// * cmp是比较函数，靠返回值正负来比较，数组必须是排好序的
/// * 返回找到的元素的指针
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c
/// void *bsearch(const void *key, const void *base, size_t num, size_t size,
///                 int (*cmp)(const void *, const void *));
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    char a = '3'; /* 搜索a */
    printf("bsearch  ");
    printf((char *)bsearch(&a,p,10,sizeof(char),cmptest));
    free(p);
    putchar('\n');
    
/// ### 返回x的绝对值
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c
/// int abs(int x)
/// long int labs(long int x)
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    printf("abs(-5)  %d\n",abs(-5));
    
/// ### 做除法，分别得到除数和被除数
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c
/// div_t div(int numer, int denom)
/// ldiv_t ldiv(long int numer, long int denom)
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    div_t div_out = div(7,2);
    printf("div(7,2)={%d,%d}\n",div_out.quot,div_out.rem);
    
/// ### 返回一个随机数，范围(0~RAND_MAX)
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c
/// int rand(void)
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    printf("rand() = %d\n",rand());
    
/// ### 对随机函数设置种子
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c
/// void srand(unsigned int seed)
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    srand(15);
    
/// ### 计算一个多字节字符的长度
/// * n 是多字节字符的长度的最大值
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c
/// int mblen(const char *str, size_t n)
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    wchar_t mywchar = L'汉';      /***** todo: 换成'国'就不行了 */
    printf("mblen('%x',MB_CUR_MAX)  %u\n",L'汉',mblen((char *)&mywchar,MB_CUR_MAX));
    
/// ### 多字节字符串转换为数组
/// 将由参数str指向的多字节字符串转换为由pwcs指向的数组
/// * n 是多字节字符的长度的最大值
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c
/// size_t mbstowcs(schar_t *pwcs, const char *str, size_t n)
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    /***** todo: 添加实例 */
/*  todu 多字节处理都不懂
    int mbtowc(whcar_t *pwc, const char *str, size_t n)
    Examines the multibyte character pointed to by the argument str.
    
    size_t wcstombs(char *str, const wchar_t *pwcs, size_t n)
    Converts the codes stored in the array pwcs to multibyte characters and stores them in the string str.
    
    int wctomb(char *str, wchar_t wchar)
    Examines the code which corresponds to a multibyte character given by the argument wchar.
     */
/// ### 在程序正常退出时执行 
/// * func 要执行的函数
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c
/// int atexit(void (*func)(void))
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    atexit(test);
    
/// ### 程序异常退出
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c
/// void abort(void)
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    /* abort(); */
    
/// ### 程序正常退出 ,返回给操作系统 status
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~c
/// void exit(int status)
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    exit(0);
}