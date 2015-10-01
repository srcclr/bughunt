#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

enum TOKEN_TYPES {
	TOK_UNKNOWN,
	TOK_IDENTIFIER,
	TOK_INTEGER,
};

struct token {
	struct token *next;
	char *lexeme;
	int type;
};

struct token *token_list = NULL;

void emit_token(char *lexeme_start, char *lexeme_end, int type){
	struct token *token;
	struct token **p;

	token = malloc(sizeof(*token));
	if(!token)
		goto alloc_error;
	token->next = NULL;
	token->lexeme = calloc(lexeme_end - lexeme_start, sizeof(char));
	if(!token->lexeme)
		goto alloc_error;
	strncat(token->lexeme, lexeme_start, lexeme_end - lexeme_start);
	token->type = type;

	p = &token_list;
	while(*p){
		p = &(*p)->next;
	}
	*p = token;
	return;

alloc_error:
	fflush(stdout);
	fprintf(stderr, "Allocation error, exiting...\n");
	exit(1);
}

void tokenize(char *input){
	// TODO: support operators
	char *start;

	while(1){
		while(*input == ' '){
			input++;
		}
		start = input;
		if(isalpha(*input)){
			while(isalpha(*input)){
				input++;
			}
			emit_token(start, input, TOK_IDENTIFIER);
		} else if(isdigit(*input)){
			while(isdigit(*input)){
				input++;
			}
			emit_token(start, input, TOK_INTEGER);
		} else if(*input == '\0'){
			return;
		} else {
			input++;
			emit_token(start, input, TOK_UNKNOWN);
		}
	}
}

void debug_dump_tokens(void){
	struct token *t;

	t = token_list;
	while(t){
		printf("[type:%d lexeme:'%s']\n", t->type, t->lexeme);
		t = t->next;
	}
}

int main(int argc, char *argv[]){
	tokenize("This is a test 2 + 2 = 5 erry day");
	debug_dump_tokens();
	return 0;
}
