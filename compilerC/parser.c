#include "global.h"

int lookahead;

int parser() {
	lookahead = lexan();
	while (lookahead != DONE) {
		expr();
		match(';');
	}
}

int expr() {
	int t;
	term();
	while (1)
	{
		switch (lookahead) {
		case '+': case '-':
			t = lookahead;
			match(lookahead);
			term();
			emit(t, NONE);
			continue;
		default:
			return;
		}
	}
}

term() {
	int t;
	factor();
	while (1)
	{
		switch (lookahead) {
		case'*':case '/':case DIV:case MOD:
			t = lookahead;
			match(lookahead);
			factor();
			emit(t, NONE);
			continue;
		default:
			return;
		}
	}
}

int factor() {
	switch (lookahead)
	{
	case'(':
		match('(');
		expr();
		match(')');
		break;
	case NUM:
		emit(NUM, tokenval);
		match(NUM);
		break;
	case ID:
		emit(ID, tokenval);
		match(ID);
		break;
	default:
		error("syntax error");
		break;
	}
}

int match(int t) {
	if (lookahead == t) lookahead = lexan();
	else error("syntax error");
}