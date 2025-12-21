#ifndef PARSER_H
# define PARSER_H

# include "./objects.h"


typedef enum 
{
    TOK_EOF,
    TOK_NEWLINE,
    TOK_IDENTIFIER,
    TOK_ERROR,
    TOK_NUMBER,
    TOK_SP,
    TOK_CY,
    TOK_PL,
    TOK_A,
    TOK_C,
    TOK_L,
    TOK_COMMA
} token_type;


typedef struct s_token
{
    const char  *start;
    int         length;
    int         line;
    token_type  type;
}   t_token;

typedef struct s_parser
{
    const char *file_start; //dosyabaslangici
    const char *current_pos; //metin degismeyecegi icin const
    int line_number; //satirsayaci
    t_token token; //sonblunantoken
    int had_error;//hata flagi
}   t_parser;




t_token scan_token(t_parser *parser);

void    init_token(t_token t);


#endif