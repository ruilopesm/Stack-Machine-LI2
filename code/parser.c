#include "stack.h"
#include "operations.h"
#include "parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void handle_token(STACK *s, char *token) {
    // Se o símbolo for um operador, irá procurar a operação pretendida e realizá-la
    if (is_operator(token)) { 
        dispatch_table(s, token[0]);
    }
    // Caso contrário, irá ler esse elemento e de seguida adicioná-lo à stack, se possível
    else {
        int value;
        sscanf(token, "%d", &value); 
        assert(push(s, value) == 0);
    }
}

int parse_line(STACK *s) { 
    char line[BUFSIZ];
    char token[BUFSIZ];

    if (fgets(line, BUFSIZ, stdin) != NULL) {
        while (sscanf(line, "%s%[^\n]", token, line) == 2) {
            handle_token(s, token);
        }
        handle_token(s, token);
    }

    return 0;
}
