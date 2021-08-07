%{
/*
 * A lexer for the basic grammar to use for recognizing english sentences.
 */
#include <stdio.h>
%}

%token NOUN PRONOUN VERB ADVERB ADJECTIVE PREPOSITION CONJUNCTION

%%
sentence: subject VERB object	{ printf("Sentence is valid.\n"); }
	;

subject:	NOUN
	|	PRONOUN
	;

object:		NOUN
	;
%%

// extern FILE *yyin;

// int main()
// {
// 	while(!feof(yyin)) {
// 		yyparse();
// 	}
// 	return 0;
// }

int main(void) {
    yyparse();
    return 0;
}

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}
