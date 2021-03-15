
#include"global.h"

char lexbuf[BSIZE];
int tokenval = NONE;
int lineno = 1;

int lexan() {
	int t;
	while (1) {
		t = getchar();
		if (t == ' ' || t == '\t');
		else if (t == '\n') lineno++;
		else if (isdigit(t)) {
			//printf("lexan");
			ungetc(t, stdin);
			scanf_s("%d", &tokenval);

			/*tokenval = t - '0';
			t = getchar();
			while (isdigit(t)) {
				tokenval = tokenval * 10 + t - '0';
				t = getchar();
			}
			ungetc(t, stdin);*/
			return NUM;
		}
		else if (isalpha(t)) {
			int p = 0, b = 0;
			while (isalnum(t)) {
				lexbuf[b++] = t;
				t = getchar();
				if (b >= BSIZE)
					error("compiler error!");

			}
			lexbuf[b] = EOS;
			if (t != EOF) ungetc(t, stdin);
			p = lookup(lexbuf);
			if (p == 0) p = insert(lexbuf, ID);
			tokenval = p;
			return symtable[p].token;
		}
		else if (t == EOF) return DONE;
		else {
			tokenval = NONE;
			return t;
		}
	}
}