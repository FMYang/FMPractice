//
//  struct.c
//  Learn_C
//
//  Created by yfm on 2022/8/31.
//

#include "struct.h"
#include <string.h>  // 提供 strcpy()、strlen() 的原型
#include <stdlib.h>  // 提供 malloc()、free() 的原型

char * s_gets(char * st, int n);

// 结构基础
void struct_example1(void) {
    // 1.声明结构
    struct book { // 结构模版，标记是book
        char title[41]; /** 书名最大长度+1 */
        char author[31]; /** 作者姓名最大长度+1 */
        float value;
    }; // 结构模版结束
    
    // 2.定义结构变量
//    struct book library;
    
    /**
     就计算机而言：
     struct book library;
     是下面的简化：
     struct book {
         char title[41];
         char author[31];
         float value;
     } library;
     
     struct { // 无标记结构
         char title[41];
         char author[31];
         float value;
     } library;
     
     然而，如果打算多次使用结构模板，就要使用带标记的形式;或者，使 用本章后面介绍的typedef。
     */
    
    // 3.初始化结构
//    struct book library = {
//        "The Pious Pirate and the Devious Damsel",
//        "Renee Vivotte",
//        1.95
//    };
    
    // 指定初始化器
    struct book library = {
        .title = "The Pious Pirate and the Devious Damsel",
        .author = "Renee Vivotte",
        .value = 1.95
    };
    
    // 4.访问结构成员
    printf("title = %s\nauthor = %s\nvalue = %f\n", library.title, library.author, library.value);
}

// 结构数组（包含多本书的图书目录）
void struct_example2(void) {
    struct book {
        char title[40];
        char author[40];
        float value;
    };
    
    struct book library[100];
    int count = 0;
    int index;
    printf("Plese enter the book title.\n");
    printf("Plese [enter] at the start of a line to stop.\n");
    while (count < 100 &&
           s_gets(library[count].title, 40) != NULL &&
           library[count].title[0] != '\0') {
        printf("Now enter the author.\n");
        s_gets(library[count].author, 40);
        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n') continue;
        if(count < 100) {
            printf("Enter the next title.\n");
        }
        if(count > 0) {
            printf("Here is the list of your books: \n");
            for(index = 0; index < count; index++) {
                printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
            }
        } else {
            printf("No books? Too bad.\n");
            return;
        }
    }
}

// 结构和指针
void struct_example3(void) {
    struct names {
        char first[20];
        char last[20];
    };
    struct guy {
        struct names handle;
        char favfood[20];
        char job[20];
        float income;
    }; // 结构占用字节数20 + 20 + 20 + 4 = 84
    // 结构数组
    struct guy fellow[2] = {
        {
            { "Ewen", "Villard" },
            "grilled salmon",
            "personality coach",
            68112.00
        },
        {
            { "Rodney", "Swillbelly" },
            "tripe",
            "tabloid editor",
            432400.00
        }
    };
    struct guy *him; // 这是一个指向结构的指针
    him = &fellow[0];
    printf("address #1: %p #2: %p\n", him, him+1); // 两个地址相差84
    printf("hime->income is $%.2f:(*him).income is %.2f\n", him->income, (*him).income);
    him++; // 指向下一个结构
    printf("hime->favfood is %s:(*handle).last is %s\n", him->favfood, him->handle.last);
    
    /**
     和数组不同，结构名并不是结构的地址，因此要在结构名前面加上&运算符。
     本例中，fellow是一个结构数组，这意味着fellow[0]是一个结构。所以，要让him指向fellow[0]，可以这样写
     him = &fellow[0];
     */
}

// 结构和函数
struct funds {
    char bank[50];
    double bankfund;
    char save[50];
    double savefund;
};

double sum(double x, double y) { // 传递结构成员变量
    return (x + y);
}

/**
 声明为const不让函数修改结构的值
 
 注意：必须使用&运算符来获取结构的地址。和数组名不同，结构名只是其地址的别名。
 
 传递结构指针，使用的是原stan结构，引用
 */
double sum1(const struct funds *money) {
    return (money->bankfund + money->savefund);
}

/**
 传递结构，创建了一个结构的副本moolah（值拷贝），并用stan的值初始化
 
 moolah和stan是两个不同的对象
 */
double sum2(struct funds moolah) {
//    moolah.bankfund = 10; // 改变结构的值不影响原结构，因为是一个新的对象
    return (moolah.bankfund + moolah.savefund);
}

// 传递结构的地址
void struct_example4(void) {
    struct funds stan = {
        "Garlic-Melon Bank",
        4032.27,
        "Lucky's Savings and Loan",
        8543.94
    };
//    printf("Stan has a total of $%.2f.\n", sum(stan.bankfund, stan.savefund));
    printf("Stan has a total of $%.2f.\n", sum1(&stan));
}

// 传递结构
void struct_example5(void) {
    struct funds stan = {
        "Garlic-Melon Bank",
        4032.27,
        "Lucky's Savings and Loan",
        8543.94
    };
//    printf("Stan has a total of $%.2f.\n", sum(stan.bankfund, stan.savefund));
    printf("Stan has a total of $%.2f.\n", sum2(stan));
}

/**
 结构和结构指针的选择：
 把指针作为参数有两个优点：无论是以前还是现在的C实现都能使用这种方法，而且执行起来很快，只需要传递一个地址。缺点是无法保护数据。被调函数中的某些操作可能会意外影响原来结构中的数据。不过，ANSI C新增了const限定符解决了这个问题。
 
 把结构作为参数传递的优点是，函数处理的是原始数据的副本，这保护了原始数据。另外，代码风格更清楚。缺点是：较老版本的实现可能无法处理这样的代码，而且传递结构浪费时间和空间。尤其是把大型结构传递给函数，而它只使用了结构中的一两个成员时特别浪费。这种情况下传递指针或只传递函数所需的成员更合理。
 
 按值传递结构是处理小型结构最常用的方法。
 */


/**
 结构中的字符数组和字符指针
 
 到目前为止，我们在结构中都使用字符数组来存储字符串。是否可以使用指向char的指针来替代字符数组？
 */
void struct_example6(void) {
    struct names {
        char first[20];
        char last[20];
    };
    struct pnames {
        char *first;
        char *last;
    };
    // 考虑下面的代码：
    
    // 字符串被存储在结构内部
    struct names veep = { "Talia", "Summers" };
    /*
     字符串被存储在编译器存储常量的地方，结构本身只存储了两个地址（16字节，64位系统中一个指针8个字节）。
     尤其是，struct pnames结构不用为字符串分配任何空间。它使用的是存储在别处的字符串。
     */
    struct pnames treas = { "Brad", "Fallingjaw" };
    printf("%s and %s\n", veep.first, treas.first);
    
    // 考虑下面的代码：
    struct names accountant;
    struct pnames attorney;
    puts("Enter the last name of you accountant:");
    scanf("%s", accountant.last);
    puts("Enter the last name of you attorney:");
    scanf("%s", attorney.last); // 这里有一个潜在的危险, 运行时可能会崩溃
    
    /**
     对于会计师accountant，它的名存储在accountant结构变量的last成员中，该结构中有一个存储字符串的数组。对于律师attorney，scanf()把字符串放到attorney.last表示的地址上。由于这是未经初始化的变量，地址可以是任何值，因此程序可以把名放在任何地方。如果走运的话程序不会出问题，否则这一操作会导致崩溃。
     
     总结：用字符数组比较好。
     */
}

// 结构、指针和malloc
struct namect {
    char *fname;
    char *lname;
    long letters;
};

void getinfo(struct namect *pst) {
    char temp[81];
    printf("Please enter you first name.\n");
    s_gets(temp, 81);
    // 分配内存以存储名
    pst->fname = (char *)malloc(strlen(temp) + 1);
    // 把名拷贝到动态分配的内存中
    strcpy(pst->fname, temp);
    printf("Please enter you last name.\n");
    s_gets(temp, 81);
    pst->lname = (char *)malloc(strlen(temp) + 1);
    strcpy(pst->lname, temp);
}

void makeinfo(struct namect *pst) {
    pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void showinfo(const struct namect *pst) {
    printf("%s %s you name contains %ld letter.\n", pst->fname, pst->lname, pst->letters);
}

void cleanup(struct namect *pst) {
    free(pst->fname);
    free(pst->lname);
}

void struct_example7(void) {
    /**
     如果使用malloc()分配内存并使用指针存储该地址，那么在结构中使用指针处理字符串就比较合理。这种方式的优点是，可与请求malloc()为字符串分配合适的存储空间。可以要求用4字节存储"joe"和利用18字节存储"Rasolofomasoandro"。
     */
    struct namect person;
    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);
    cleanup(&person);
}

/**
 伸缩型数组成员
 
 C99新增了一个特性：伸缩型数组成员（flexible array member），利用这项特性声明的结构，其最后一个数组成员具有一些特性。
 - 第1个特性是，该数组不会立即存在。
 - 第2个特性是，使用这个伸缩型数组成员可以编写合适的代码，就好像它确实存在并具有所需数目的元素一样。
 
 声明伸缩型数组成员有如下规则：
 - 1、伸缩型数组成员必须是结构的最后一个成员；
 - 2、结构中必须至少有一个成员；
 - 3、伸缩型数组的声明类似于普通数组，只是它的方括号中是空的。
 */
struct flex {
    int count;
    double average;
    double scores[]; // 伸缩型数组成员
};

void showFlex(const struct flex *p) {
    printf("Scores:");
    for(int i=0; i<p->count; i++) {
        printf("%g ", p->scores[i]);
    }
    printf("\nAverage: %g\n", p->average);
}

void struct_example8(void) {
    /**
     声明一个struct flex类型的结构变量时，不能用scores做任何事，因为没有给这个数组预留存储空间。实际上，C99的意图并不是让你声明struct flex类型的变量，而是希望你声明一个指向struct flex类型的指针，然后用malloc()来分配足够的空间，以存储struct flex类型结构的常规内容和伸缩型数组成员所需的额外空间。
     
     例如，加上用scores表示一个内含5个double类型的数组，可以这样做：
     */
    struct flex * pf; // 声明一个指针
    // 请求为结构和一个数组分配存储空间
    pf = malloc(sizeof(struct flex) + 5*sizeof(double));
    // 现在有足够的存储空间存储count、average和一个内含5个double类型值的数组。
    pf->count = 5;
    pf->scores[2] = 18.5; // 访问数组成员的一个元素
    
    struct flex *pf1, *pf2;
    int n = 5;
    int tol = 0;
    pf1 = malloc(sizeof(struct flex) + n * sizeof(double));
    pf1->count = n;
    for(int i=0; i<n; i++) {
        pf1->scores[i] = 20.0 - i;
        tol += pf1->scores[i];
    }
    pf1->average = tol / n;
    showFlex(pf1);
    n = 9;
    tol = 0;
    pf2 = malloc(sizeof(struct flex) + n * sizeof(double));
    pf2->count = n;
    for(int i=0; i<n; i++) {
        pf2->scores[i] = 20.0 - i / 2.0;
        tol += pf2->scores[i];
    }
    pf2->average = tol / n;
    showFlex(pf2);
    free(pf1);
    free(pf2);
    
    /**
     总结：
     带伸缩型数组成员的结构确实有有些特殊的处理要求。
     - 第一，不能使用结构进行赋值和拷贝；
     - 第二，不要以按值方式把这种结构传递给结构。相同的原因，按值传递一个参数与赋值类型。要把结构的地址传递给函数。
     - 第三，不要使用带伸缩型数组成员的结构作为数组成员或另一个结构的成员。
     */
    struct flex *pf4, *pf5; // *pf4和*pf5都是结构
    *pf4 = *pf5; // 不要这样做，这样只能拷贝除伸缩型数组成员之外的其他成员。确实要拷贝，使用memcpy函数
}

void struct_example(void) {
    printf("============= 结构 ==============\n");
//    struct_example1();
//    struct_example2();
//    struct_example3();
//    struct_example4();
//    struct_example5();
//    struct_example6();
//    struct_example7();
    struct_example8();
    printf("============= End ==============\n\n");
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');  // 查找换行符
        if (find)          // 如果地址不是 NULL，
            *find = '\0';     // 在此处放置一个空字符
        else
            while (getchar() != '\n')
                continue;     // 处理输入行中剩余的字符
    }
    return ret_val;
}
