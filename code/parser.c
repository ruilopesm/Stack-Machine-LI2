#include "stack.h"
#include "operations.h"
#include "parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int is_double(char *token) { // se número é double (tem de só ter algarismos, exceto um .)  
    for (int i = 0; token[i] != '\0'; i++) {
        if (token[i] < 48 || token[i] > 57) {
            if (token[i] == '.') {
                return 1;
            }
        }
    }
    
    return 0;
}

int is_long(char *token) { // se é apenas algarismos
    for (int i = 0; token[i] != '\0'; i++){
        if (token[i] < 48 || token[i] > 57) {
            return 0;
        }
    }

    return 1;
}

void remove_char(char *s,int p){
    for(int i=p; s[i]!='\0';i++){
        s[i]=s[i+1];
    }
}

void handle_token(STACK *s, char *token) {
    // Se o símbolo for um operador, irá procurar a operação pretendida e realizá-la
    if (is_operator(token)) { 
        dispatch_table(s, token[0]);
    }
    // Caso contrário, irá ler esse elemento e de seguida adicioná-lo à stack, se possível
    else {
        if (is_long(token)){
            long value;
            sscanf(token, "%ld", &value);

            STACK_ELEM new = {
                .t = LONG,
                .data = { .l = value }
            };
            assert(push(s, new) == 0);
            // Testing purposes
            printf("A long has been pushed into the stack!\n");
        }
        else if (is_double(token)) {
            double value;
            sscanf(token, "%lg", &value);

            STACK_ELEM new = {
                .t = DOUBLE,
                .data = { .d = value }
            };
            assert(push(s, new) == 0);
            // Testing purposes
            printf("A double has been pushed into the stack!\n");
        }
        else { // Se não for long nem int é string
            char *value = malloc(sizeof(char) * BUFSIZ);
            sscanf(token, "%s", value);
            
            int len = strlen (value);
            
            if (value[0] == '"' && value[len - 1] == '"') {
                remove_char(value, 0);
                remove_char(value, len - 2);

                STACK_ELEM new = {
                    .t = STRING,
                    .data={ .s = value }
                };
                assert(push(s, new) == 0);
                // Testing purposes
                printf("A string has been pushed into the stack!\n");
            
            }
        }
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
