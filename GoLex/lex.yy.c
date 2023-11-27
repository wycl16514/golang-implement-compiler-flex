#include<string.h>
enum {
    LOOKUP = 0,
    VERB,
    ADJ,
    ADV,
    NOUN,
    PREP,
    PRON,
    CONJ
};
int state;
int add_word(int type, char* word);
int lookup_word(char* word);
void handle_string();

#ifdef __NEVER__
/*------------------------------------------------
DFA (start state is 0) is :
 *
* State 0 [nonaccepting]

 * goto 1 on \n
 * goto 2 on  
 * goto 3 on ABCDEFGHIJKLMNOPQRSTUVWXYZ
 * goto 16 on a
 * goto 3 on b
 * goto 21 on c
 * goto 3 on defghijklm
 * goto 22 on n
 * goto 3 on o
 * goto 23 on p
 * goto 3 on qrstu
 * goto 24 on v
 * goto 3 on wxyz
* State 1 [accepting, line 0, < {state = LOOKUP;}>]

* State 2 [accepting, line 0, < {;}>]

* State 3 [accepting, line 0, <  {handle_string();}>]

 * goto 3 on ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
* State 4 [accepting, line 0, < {state = ADJ;}>]

 * goto 3 on ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
* State 5 [accepting, line 0, < {state = CONJ;}>]

 * goto 3 on ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
* State 6 [accepting, line 0, < {state = NOUN;}>]

 * goto 3 on ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
* State 7 [accepting, line 0, < {state = PREP;}>]

 * goto 3 on ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
* State 8 [accepting, line 0, < {state = PRON;}>]

 * goto 3 on ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
* State 9 [accepting, line 0, < {state = VERB;}>]

 * goto 3 on ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
* State 10 [accepting, line 0, <  {handle_string();}>]

 * goto 3 on ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghi
 * goto 4 on j
 * goto 3 on klmnopqrstuvwxyz
* State 11 [accepting, line 0, <  {handle_string();}>]

 * goto 3 on ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghi
 * goto 5 on j
 * goto 3 on klmnopqrstuvwxyz
* State 12 [accepting, line 0, <  {handle_string();}>]

 * goto 3 on ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklm
 * goto 6 on n
 * goto 3 on opqrstuvwxyz
* State 13 [accepting, line 0, <  {handle_string();}>]

 * goto 3 on ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmno
 * goto 7 on p
 * goto 3 on qrstuvwxyz
* State 14 [accepting, line 0, <  {handle_string();}>]

 * goto 3 on ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklm
 * goto 8 on n
 * goto 3 on opqrstuvwxyz
* State 15 [accepting, line 0, <  {handle_string();}>]

 * goto 3 on ABCDEFGHIJKLMNOPQRSTUVWXYZa
 * goto 9 on b
 * goto 3 on cdefghijklmnopqrstuvwxyz
* State 16 [accepting, line 0, <  {handle_string();}>]

 * goto 3 on ABCDEFGHIJKLMNOPQRSTUVWXYZabc
 * goto 10 on d
 * goto 3 on efghijklmnopqrstuvwxyz
* State 17 [accepting, line 0, <  {handle_string();}>]

 * goto 3 on ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklm
 * goto 11 on n
 * goto 3 on opqrstuvwxyz
* State 18 [accepting, line 0, <  {handle_string();}>]

 * goto 3 on ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrst
 * goto 12 on u
 * goto 3 on vwxyz
* State 19 [accepting, line 0, <  {handle_string();}>]

 * goto 3 on ABCDEFGHIJKLMNOPQRSTUVWXYZabcd
 * goto 13 on e
 * goto 3 on fghijklmn
 * goto 14 on o
 * goto 3 on pqrstuvwxyz
* State 20 [accepting, line 0, <  {handle_string();}>]

 * goto 3 on ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopq
 * goto 15 on r
 * goto 3 on stuvwxyz
* State 21 [accepting, line 0, <  {handle_string();}>]

 * goto 3 on ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmn
 * goto 17 on o
 * goto 3 on pqrstuvwxyz
* State 22 [accepting, line 0, <  {handle_string();}>]

 * goto 3 on ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmn
 * goto 18 on o
 * goto 3 on pqrstuvwxyz
* State 23 [accepting, line 0, <  {handle_string();}>]

 * goto 3 on ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopq
 * goto 19 on r
 * goto 3 on stuvwxyz
* State 24 [accepting, line 0, <  {handle_string();}>]

 * goto 3 on ABCDEFGHIJKLMNOPQRSTUVWXYZabcd
 * goto 20 on e
 * goto 3 on fghijklmnopqrstuvwxyz
*/ 

#endif
/*
YY_TTYPE 是宏定义，用于 DFA 状态转换表Yy_nxt[],它将会在下面进行定义。 宏定义YYF表示错误的状态跳转，当状态机跳转到错误状态时
模板代码会自动进行相应处理.DFA 状态机的起始状态为 0，同时宏定义 YYPRIVATE 也会在本模板文件中定义
*/
#ifndef YYPRIVATE
#define YYPRIVATE  static
#endif
#include <stdio.h>
#include <errno.h>
#include"debug.h"
#include"l.h"
#ifndef YYPRIVATE
#define YYPRIVATE static
#endif
#ifdef YYDEBUG
  int yydebug = 0;
#define YY_D(x) if(yydebug){x;}else
#else
#define YY_D(x)
#endif
typedef unsigned char YY_TTYPE;
#define YYF  ((YY_TTYPE)(-1))
unsigned char* ii_text();

/*--------------------------------------
* The Yy_cmap[] and Yy_rmap arrays are used as follows:
* 
*  next_state= Yydtran[ Yy_rmap[current_state] ][ Yy_cmap[input_char] ];
* 
* Character positions in the Yy_cmap array are:
* 
*    ^@  ^A  ^B  ^C  ^D  ^E  ^F  ^G  ^H  ^I  ^J  ^K  ^L  ^M  ^N  ^O
*    ^P  ^Q  ^R  ^S  ^T  ^U  ^V  ^W  ^X  ^Y  ^Z  ^[  ^\  ^]  ^^  ^_
*         !   "   #   $   %   &   '   (   )   *   +   ,   -   .   /
*     0   1   2   3   4   5   6   7   8   9   :   ;   <   =   >   ?
*     @   A   B   C   D   E   F   G   H   I   J   K   L   M   N   O
*     P   Q   R   S   T   U   V   W   X   Y   Z   [   \   ]   ^   _
*     `   a   b   c   d   e   f   g   h   i   j   k   l   m   n   o
*     p   q   r   s   t   u   v   w   x   y   z   {   |   }   ~   DEL
*/

static unsigned char Yy_cmap[128]=
{
  0,0,0,0,0,0,0,0,0,0,
    1,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,
    0,0,2,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,3,3,3,3,3,
    3,3,3,3,3,3,3,3,3,3,
    3,3,3,3,3,3,3,3,3,3,
    3,0,0,0,0,0,0,4,5,6,
    7,8,3,3,3,3,9,3,3,3,
    10,11,12,3,13,3,3,14,15,3,
    3,3,3,0,0,0,0,0
};

static  unsigned char  Yy_rmap[25]=
{
    0,1,1,2,2,2,2,2,2,2,
    3,4,5,6,7,8,9,10,11,12,
    13,14,15,16,17
};

static unsigned char Yy_nxt[18][16]=
{
/*  0 */ {-1, 1, 2, 3, 16, 3, 21, 3, 3, 3, 
        22, 3, 23, 3, 3, 24},
/*  1 */ {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 
        -1, -1, -1, -1, -1, -1},
/*  2 */ {-1, -1, -1, 3, 3, 3, 3, 3, 3, 3, 
        3, 3, 3, 3, 3, 3},
/*  3 */ {-1, -1, -1, 3, 3, 3, 3, 3, 3, 4, 
        3, 3, 3, 3, 3, 3},
/*  4 */ {-1, -1, -1, 3, 3, 3, 3, 3, 3, 5, 
        3, 3, 3, 3, 3, 3},
/*  5 */ {-1, -1, -1, 3, 3, 3, 3, 3, 3, 3, 
        6, 3, 3, 3, 3, 3},
/*  6 */ {-1, -1, -1, 3, 3, 3, 3, 3, 3, 3, 
        3, 3, 7, 3, 3, 3},
/*  7 */ {-1, -1, -1, 3, 3, 3, 3, 3, 3, 3, 
        8, 3, 3, 3, 3, 3},
/*  8 */ {-1, -1, -1, 3, 3, 9, 3, 3, 3, 3, 
        3, 3, 3, 3, 3, 3},
/*  9 */ {-1, -1, -1, 3, 3, 3, 3, 10, 3, 3, 
        3, 3, 3, 3, 3, 3},
/*  10 */ {-1, -1, -1, 3, 3, 3, 3, 3, 3, 3, 
        11, 3, 3, 3, 3, 3},
/*  11 */ {-1, -1, -1, 3, 3, 3, 3, 3, 3, 3, 
        3, 3, 3, 3, 12, 3},
/*  12 */ {-1, -1, -1, 3, 3, 3, 3, 3, 13, 3, 
        3, 14, 3, 3, 3, 3},
/*  13 */ {-1, -1, -1, 3, 3, 3, 3, 3, 3, 3, 
        3, 3, 3, 15, 3, 3},
/*  14 */ {-1, -1, -1, 3, 3, 3, 3, 3, 3, 3, 
        3, 17, 3, 3, 3, 3},
/*  15 */ {-1, -1, -1, 3, 3, 3, 3, 3, 3, 3, 
        3, 18, 3, 3, 3, 3},
/*  16 */ {-1, -1, -1, 3, 3, 3, 3, 3, 3, 3, 
        3, 3, 3, 19, 3, 3},
/*  17 */ {-1, -1, -1, 3, 3, 3, 3, 3, 20, 3, 
        3, 3, 3, 3, 3, 3} 
};

/*--------------------------------------
* yy_next(state,c) is given the current state number and input
* character and evaluates to the next state.
*/

#define yy_next(state, c) (Yy_nxt[Yy_rmap[state]][Yy_cmap[c]])

/*--------------------------------------
 * 输出基于 DFA 的跳转表,首先我们将生成一个 Yyaccept数组，如果 Yyaccept[i]取值为 0，
	那表示节点 i 不是接收态，如果它的值不是 0，那么节点是接受态，此时他的值对应以下几种情况：
	1 表示节点对应的正则表达式需要开头匹配，也就是正则表达式以符号^开始，2 表示正则表达式需要
	末尾匹配，也就是表达式以符号$结尾，3 表示同时开头和结尾匹配，4 表示不需要开头或结尾匹配
 */

YYPRIVATE YY_TTYPE Yyaccept[]=
{
	0  ,  /*State 0  */
	4  ,  /*State 1  */
	4  ,  /*State 2  */
	4  ,  /*State 3  */
	4  ,  /*State 4  */
	4  ,  /*State 5  */
	4  ,  /*State 6  */
	4  ,  /*State 7  */
	4  ,  /*State 8  */
	4  ,  /*State 9  */
	4  ,  /*State 10 */
	4  ,  /*State 11 */
	4  ,  /*State 12 */
	4  ,  /*State 13 */
	4  ,  /*State 14 */
	4  ,  /*State 15 */
	4  ,  /*State 16 */
	4  ,  /*State 17 */
	4  ,  /*State 18 */
	4  ,  /*State 19 */
	4  ,  /*State 20 */
	4  ,  /*State 21 */
	4  ,  /*State 22 */
	4  ,  /*State 23 */
	4     /*State 24 */
};

/*--------------------------------------
*  语法解析器使用的全局变量放到这里，在词法解析器阶段，这里可以忽略
*/
char*  yytext;  /*指向当前正在读取的字符串*/
int    yyleng;  /*当前读取字符串的长度*/
int    yylineno;  /*当前读取字符串所在的行*/
FILE*  yyout = NULL;  /*默认情况下输入从控制台读取*/
#define output(c)  putc(c, yyout)
#define ECHO       fprintf(yyout, "%s", yytext)
#ifndef YYERROR
#define YYERROR  printf
#endif
#define  yymore() yymoreflg = 1
#define unput(c)   (ii_unput(c), --yyleng)
#define yyless(n) (ii_unterm(), yyleng -= ii_pushback(n) ? n : yyleng), ii_term() )
int input(void) {
    int c;
    if ((c = ii_input()) && (c != -1)) {
        yytext = (char*) ii_text();
        yylineno = ii_lineno();
        ++yyleng;
    }
    return c;
}
/*--------------------------------*/
void yy_init_lex() {
    //做一些初始化工作，默认什么都不做
}
int yywrap() {
    //默认不要打开新文件
    if (ii_console()) {
        //如果输入来自控制台，那么程序不要返回
        ii_newfile(NULL);
        return 0;
    }
    return 1;
}
int yylex() {
    int  yymoreflg;
    static  int yystate = -1;
    int  yylastaccept;
    int  yyprev;
    int yynstate;
    int yylook;
    int  yyanchor;
    if (yystate == -1) {
        //函数第一次执行时进入这里进行初始化
        yy_init_lex();
        ii_advance();
        ii_pushback(1);
    }
    yystate = 0;
    yylastaccept = 0;
    yymoreflg = 0;
    ii_unterm();
    ii_mark_start();
    while(1) {
        /*
        首先检测当前读入的文件是否已经到了末尾。如果是，并且当前有没有处理的接收状态,yylastaccept 的值就不是 0
        ，那么此时就先执行对应接收状态的代码，如果在到了文件末尾还没有遇到过接收状态，那么尝试打开新的输入文件，
        如果新文件打开失败则返回
        */
        while(1) {
            if((yylook = ii_look(1)) != EOF) {
                yynstate = yy_next(yystate, yylook);
                break;
            } else {
                if (yylastaccept) {
                    yynstate = YYF;
                    break;
                } else if (yywrap()) {
                    //yywrap 打开新的输入文件,进入到这里说明没有新的文件要打开
                    yytext = "";
                    yyleng = 0;
                    return 0;
                } else {
                    //这里说明打开了新的输入文件
                    ii_advance(); //读取数据到缓冲区
                    ii_pushback(1);
                }
            }
        }
        if (yynstate != YYF) {
            YY_D(printf("    Transition from state %d", yystate));
            YY_D(printf(" to state %d on <%c>\n", yystate, yylook));
            if (ii_advance() < 0) {
                YYERROR("Line %d, lexeme too long. Discarding extra characters.\n", ii_lineno());
                ii_flush(1);
            }
            if (yyanchor = Yyaccept[yynstate]) {
                //当前状态是接收状态
                yyprev = yystate;
                yylastaccept = yynstate;
                ii_mark_end();
            }
            yystate = yynstate;
        } else {
            //在这里意味着当前状态机接收字符后进入错误状态，于是我们处理之前进入的接收状态
            if (!yylastaccept) {
                //此前没有进入过接收状态
                YYERROR("Ignoring bad input\n");
                ii_advance();
            } else {
                //处理之前进入的接收状态
                ii_to_mark();
                if (yyanchor & 2) {
                    //末尾匹配，先将当前回车字符放回缓冲区
                    ii_pushback(1);
                }
                if (yyanchor & 1) {
                    //开头匹配，忽略掉当前输入字符串开头的回车字符
                    ii_move_start();
                }
                ii_term();  //将当前输入字符串的末尾添加\0 符号
                yytext = (char*)ii_text();
                yyleng = ii_length();
                yylineno = ii_lineno();
                YY_D(printf("Accepting state %d, ", yylastaccept));
                YY_D(printf("line %d: <%s>\n", yylineno, yytext));
                switch(yylastaccept) {
			case 1:					/* State 1   */
		     {state = LOOKUP;}
		    break;
			case 2:					/* State 2   */
		     {;}
		    break;
			case 3:					/* State 3   */
		      {handle_string();}
		    break;
			case 4:					/* State 4   */
		     {state = ADJ;}
		    break;
			case 5:					/* State 5   */
		     {state = CONJ;}
		    break;
			case 6:					/* State 6   */
		     {state = NOUN;}
		    break;
			case 7:					/* State 7   */
		     {state = PREP;}
		    break;
			case 8:					/* State 8   */
		     {state = PRON;}
		    break;
			case 9:					/* State 9   */
		     {state = VERB;}
		    break;
			case 10:					/* State 10  */
		      {handle_string();}
		    break;
			case 11:					/* State 11  */
		      {handle_string();}
		    break;
			case 12:					/* State 12  */
		      {handle_string();}
		    break;
			case 13:					/* State 13  */
		      {handle_string();}
		    break;
			case 14:					/* State 14  */
		      {handle_string();}
		    break;
			case 15:					/* State 15  */
		      {handle_string();}
		    break;
			case 16:					/* State 16  */
		      {handle_string();}
		    break;
			case 17:					/* State 17  */
		      {handle_string();}
		    break;
			case 18:					/* State 18  */
		      {handle_string();}
		    break;
			case 19:					/* State 19  */
		      {handle_string();}
		    break;
			case 20:					/* State 20  */
		      {handle_string();}
		    break;
			case 21:					/* State 21  */
		      {handle_string();}
		    break;
			case 22:					/* State 22  */
		      {handle_string();}
		    break;
			case 23:					/* State 23  */
		      {handle_string();}
		    break;
			case 24:					/* State 24  */
		      {handle_string();}
		    break;
                default:
                    YYERROR("INTERNAL ERROR, yylex: Unkonw accept state %d.\n", yylastaccept);
                    break;
                }
            }
            ii_unterm();
            yylastaccept = 0;
            if (!yymoreflg) {
                yystate = 0;
                ii_mark_start();
            } else {
                yystate = yyprev; //记录上一次遇到的状态
                yymoreflg = 0;
            }
        }
    }
    return -1;
}
int main() {
    yylex();
    return 0;
}

struct word {
    char* word_name;
    int word_type;
    struct word* next;
};

struct word* word_list;

extern void *malloc();

int add_word(int type, char* word) {
    struct word* wp;
    if (lookup_word(word) != LOOKUP) {
        printf("!!! warning: word %s already defined\n", word);
        return 0;
    }

    wp = (struct word*)malloc(sizeof(struct word));
    wp->next = word_list;
    wp->word_name = (char*) malloc(strlen(word)+1);
    strcpy(wp->word_name, word);
    wp->word_type = type;
    word_list = wp;
    return 1;
}

int lookup_word(char* word) {
    struct word* wp = word_list;
    for(; wp; wp = wp->next) {
        if (strcmp(wp->word_name, word)==0) {
            return wp->word_type;
        }
    }

    return LOOKUP;
}

void handle_string() {
    if (state != LOOKUP) {
        add_word(state, yytext);
    }else {
        switch(lookup_word(yytext)) {
            case VERB:  printf("%s: verb\n", yytext); break;
            case ADJ:   printf("%s: adjective\n", yytext); break;
            case ADV:   printf("%s: adverb\n", yytext); break;
            case NOUN:  printf("%s: noun\n", yytext); break;
            case PREP:  printf("%s: propsition\n", yytext); break;
            case PRON:  printf("%s: pronoun\n", yytext); break;
            case CONJ:  printf("%s: conjunction\n", yytext); break;
            default:
                 printf("%s: don't recognize\n", yytext); break;
        }
    }
}





