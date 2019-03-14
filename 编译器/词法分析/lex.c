#include"word.h"
TkWord* tkword_direct_insert(TkWord* tp);
TkWord* tkword_insert(char * p);
DynString tkstr;
DynString sourcestr;
int tkvalue;
DynString tkstr;
char ch;
int token;
int tkvalue;
int line_num;
//跳过空格，tab，回车
void skip_space_white() {
	while (' ' == ch || '\t' == ch || '\r' == ch) {
		if ('\r' == ch) {
			getch();
			if ('\n' != ch) {
				return;
			}
			line_num++;
		}
		printf("%c", ch);
		getch();
	}
}
int is_nodigit(char c) {
	return (c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z') || '_' == c;
}
int is_digit(char c) {
	return c >= '0'&&c <= '9';
}
void getch() {
	ch = getc(fp);
}
void parse_num() {
	dynstring_reset(&tkstr);
	dynstring_reset(&sourcestr);
	do {
		dynstring_chcat(&tkstr, ch);
		dynstring_chcat(&sourcestr, ch);
		getch();
	} while (is_digit(ch));
	if ('.' == ch) {
		do {
			dynstring_chcat(&tkstr, ch);
			dynstring_chcat(&sourcestr, ch);
			getch();
		} while (is_digit(ch));
	}
	dynstring_chcat(&tkstr, '\0');
	dynstring_chcat(&sourcestr, '\0');
	tkvalue = atoi(tkstr.data);
}
TkWord* parse_identifier() {
	dynstring_reset(&tkstr);
	dynstring_chcat(&tkstr, ch);
	getch();
	while (is_nodigit(ch) || is_digit(ch)) {
		dynstring_chcat(&tkstr, ch);
		getch();
	}
	dynstring_chcat(&tkstr, '\0');
	return tkword_insert(tkstr.data);
}
void parse_string(char sep) {
	char c;
	dynstring_reset(&tkstr);
	dynstring_reset(&sourcestr);
	dynstring_chcat(&sourcestr, sep);
	getch();
	for (;;)
	{
		if (ch == sep)
			break;
		else if (ch == '\\')
		{
			dynstring_chcat(&sourcestr, ch);
			getch();
			switch (ch)
			{
			case '0':
				c = '\0';
				break;
			case 'a':
				c = '\a';
				break;
			case 'b':
				c = '\b';
				break;
			case 't':
				c = '\t';
				break;
			case 'n':
				c = '\n';
				break;
			case 'v':
				c = '\v';
				break;
			case 'f':
				c = '\f';
				break;
			case 'r':
				c = '\r';
				break;
			case '\"':
				c = '\"';
				break;
			case '\'':
				c = '\'';
				break;
			case '\\':
				c = '\\';
				break;
			default:
				c = ch;
				if (c >= '!' && c <= '~')
					printf("非法转义字符: \'\\%c\'", c); // 33-126 0x21-0x7E可显示字符部分
				else
					printf("非法转义字符: \'\\0x%x\'", c);
				break;
			}
			dynstring_chcat(&tkstr, c);
			dynstring_chcat(&sourcestr, ch);
			getch();
		}
		else
		{
			dynstring_chcat(&tkstr, ch);
			dynstring_chcat(&sourcestr, ch);
			getch();
		}

	}
	dynstring_chcat(&tkstr, '\0');
	dynstring_chcat(&sourcestr, sep);
	dynstring_chcat(&sourcestr, '\0');
	getch();

}
//处理注释
void parse_comment() {
	getch();
	while (1) {
		while (1) {
			if ('\n' == ch || CH_EOF == ch || '*' == ch) {
				break;
			}
			else {
				getch();
			}
		}
		if ('\n' == ch) {
			line_num++;
			getch();
		}
		else if ('*' == ch) {
			getch();
			if ('/' == ch) {
				getch();
				return;
			}
		}
		else {
			printf("未找到注释结束符");
			return;
		}
	}
}
//文件预处理
void preprocess() {
	while (1) {
		if (' ' == ch || '\t' == ch || '\r' == ch) {
			skip_space_white();
		}
		else if ('/' == ch) {
			getch();
			if ('*' == ch) {
				parse_comment();
			}
			else {
				ungetc(ch, fp);
				ch = '/';
				break;
			}
		}
		else {
			break;
		}
	}
}
void get_token() {
	preprocess();
	if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || ('_' == ch)) {
		TkWord *tp;
		tp = parse_identifier();
		token = tp->tkcode;
	}
	else if (ch >= '0'&&ch <= '9') {
		parse_num();
		token = TK_CINT;
	}
	else if ('+' == ch) {
		getch();
		token = TK_PLUS;
	}
	else if ('-' == ch) {
		getch();
		if ('>' == ch) {
			token = TK_POINTSTO;
			getch();
		}
		else {
			token = TK_MINUS;
		}
	}
	else if ('/' == ch) {
		token = TK_DIVIDE;
		getch();
	}
	else if ('%' == ch) {
		token = TK_MOD;
		getch();
	}
	else if ('=' == ch) {
		getch();
		if ('=' == ch) {
			token = TK_EQ;
			getch();
		}
		else {
			token = TK_ASSIGN;
		}
	}
	else if ('!' == ch) {
		getch();
		if ('=' == ch) {
			token = TK_NEQ;
			getch();
		}
		else {
			printf("!操作符不被支持");
		}
	}
	else if ('>' == ch) {
		if ('=' == ch) {
			token = TK_LEQ;
			getch();
		}
		else {
			token = TK_LT;
		}
	}
	else if ('>' == ch) {
		getch();
		if (ch == '=')
		{
			token = TK_GEQ;
			getch();
		}
		else {
			token = TK_GT;
		}
	}
	else if ('.' == ch) {
		getch();
		if ('.' == ch) {
			getch();
			if (ch != '.') {
				printf("省略号输入错误");
			}
			else {
				token = TK_ELLIPSIS;
			}
			getch();
		}
		else {
			token = TK_DOT;
		}
	}
	else if ('&' == ch) {
		token = TK_AND;
		getch();
	}
	else if (';' == ch) {
		token = TK_SEMICOLON;
		getch();
	}
	else if (']' == ch) {
		token = TK_CLOSEBR;
		getch();
	}
	else if ('}' == ch) {
		token = TK_END;
		getch();
	}
	else if (')'==ch){
		token = TK_CLOSEPA;
		getch();
	}
	else if ('[' == ch) {
		token = TK_OPENBR;
		getch();
	}
	else if ('{'==ch) {
		token = TK_BEGIN;
		getch();
	}
	else if (',' == ch) {
	token = TK_COMMA;
	getch();
}
	else if ('(' == ch) {
		token = TK_OPENPA;
		getch();
	}
	else if ('*'==ch) {
		token = TK_STAR;
		getch();
	}
	else if ('\'' == ch) {
		parse_string(ch);
		token = TK_CCHAR;
		tkvalue = *(char*)tkstr.data;
	}
	else if ('\"' == ch) {
	parse_string(ch);
	token = TK_CSTR;
}
	else if (EOF == ch) {
	token = TK_EOF;
}
	else {
	printf("不认识的字符！");
	getch();
}
}
char *get_tkstr(int v) {
	if (v > tktable.count)
		return NULL;
	else if (v >= TK_CINT && v <= TK_CSTR)
		return sourcestr.data;
	else
		return ((TkWord*)tktable.data[v])->spelling;
}
void init_lex() {
	TkWord* tp;
	static TkWord keywords[] = {
	{TK_PLUS,		NULL,	  "+",	NULL,	NULL},
	{TK_MINUS,		NULL,	  "-",	NULL,	NULL},
	{TK_STAR,		NULL,	  "*",	NULL,	NULL},
	{TK_DIVIDE,		NULL,	  "/",	NULL,	NULL},
	{TK_MOD,		NULL,	  "%",	NULL,	NULL},
	{TK_EQ,			NULL,	  "==",	NULL,	NULL},
	{TK_NEQ,		NULL,	  "!=",	NULL,	NULL},
	{TK_LT,			NULL,	  "<",	NULL,	NULL},
	{TK_LEQ,		NULL,	  "<=",	NULL,	NULL},
	{TK_GT,			NULL,	  ">",	NULL,	NULL},
	{TK_GEQ,		NULL,	  ">=",	NULL,	NULL},
	{TK_ASSIGN,		NULL,	  "=",	NULL,	NULL},
	{TK_POINTSTO,	NULL,	  "->",	NULL,	NULL},
	{TK_DOT,		NULL,	  ".",	NULL,	NULL},
	{TK_AND,		NULL,	  "&",	NULL,	NULL},
	{TK_OPENPA,		NULL,	  "(",	NULL,	NULL},
	{TK_CLOSEPA,	NULL,	  ")",	NULL,	NULL},
	{TK_OPENBR,		NULL,	  "[",	NULL,	NULL},
	{TK_CLOSEBR,	NULL,	  "]",	NULL,	NULL},
	{TK_BEGIN,		NULL,	  "{",	NULL,	NULL},
	{TK_END,		NULL,	  "}",	NULL,	NULL},
	{TK_SEMICOLON,	NULL,	  ";",	NULL,	NULL},
	{TK_COMMA,		NULL,	  ",",	NULL,	NULL},
	{TK_ELLIPSIS,	NULL,	"...",	NULL,	NULL},
	{TK_EOF,		NULL,	 "End_Of_File",	NULL,	NULL},

	{TK_CINT,		NULL,	 	"整型常量",	NULL,	NULL},
	{TK_CCHAR,		NULL,		"字符常量",	NULL,	NULL},
	{TK_CSTR,		NULL,		"字符串常量",	NULL,	NULL},

	{KW_CHAR,		NULL,		"char",	NULL,	NULL},
	{KW_SHORT,		NULL,		"short",	NULL,	NULL},
	{KW_INT,		NULL,		"int",	NULL,	NULL},
	{KW_VOID,		NULL,		"void",	NULL,	NULL},
	{KW_STRUCT,		NULL,		"struct",	NULL,	NULL},

	{KW_IF,			NULL,		"if"	,	NULL,	NULL},
	{KW_ELSE,		NULL,		"else",	NULL,	NULL},
	{KW_FOR,		NULL,		"for",	NULL,	NULL},
	{KW_CONTINUE,	NULL,		"continue",	NULL,	NULL},
	{KW_BREAK,		NULL,		"break",	NULL,	NULL},
	{KW_RETURN,		NULL,		"return",	NULL,	NULL},
	{KW_SIZEOF,		NULL,		"sizeof",	NULL,	NULL},
	{KW_ALIGN,		NULL,		"__align",	NULL,	NULL},
	{KW_CDECL,		NULL,		"__cdecl",	NULL,	NULL},
	{KW_STDCALL,	NULL,		"__stdcall",	NULL,	NULL},
	{0,				NULL,	NULL,	NULL,		NULL}
	};

	dynarray_init(&tktable, 8);
	for (tp = &keywords[0]; tp->spelling != NULL; tp++)
		tkword_direct_insert(tp);
}

void test_lex() {
	do
	{
		get_token();
		color_token(LEX_NORMAL);
	} while (token != TK_EOF);
	printf("\n代码行数: %d行\n", line_num);
}
void color_token(int lex_state) {
	void* h = GetStdHandle(STD_OUTPUT_HANDLE);
	char *p;
	switch (lex_state)
	{
	case LEX_NORMAL:
	{
		if (token >= TK_IDENT)
			SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);
		else if (token >= KW_CHAR)
			SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		else if (token >= TK_CINT)
			SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN);
		else
			SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
		p = get_tkstr(token);
		printf("%s", p);
		break;
	}
	case LEX_SEP:
		printf("%c", ch);
		break;
	}
}