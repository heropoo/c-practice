%option noyywrap

%%
[\n\t ]	;

-?(([0-9]+)|([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?) { printf("number: %s \n", yytext); }

.	ECHO;
%%
int main()
{
	yylex();
	return 0;
}
