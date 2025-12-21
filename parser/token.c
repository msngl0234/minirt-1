#include "parser.h"
#include "./libft.h"

t_token scan_token(t_parser *parser)
{
    t_token token;
    token = init_token();
    parser->file_start = parser->current_pos;
    while(ft_isspace(parser->current_pos))
        parser->current_pos++;
    if (parser->current_pos == '#')
        while (parser->current_pos != '\0' || parser->current_pos != '\n')
            parser->current_pos++;
    parser->file_start = parser->current_pos - parser->file_start;
    if (parser->current_pos == '\0')
        return (token.type == TOK_EOF);
    if (parser->current_pos == '\n')
    {
        parser->line_number++;
        token.type = TOK_NEWLINE;
    }
    if (parser->current_pos == ',')
        token.type = TOK_COMMA;
    
    if (ft_isdigit(parser->current_pos) || (parser->current_pos == '-' && ft_isdigit((parser->current_pos + 1))))
    {
        while (ft_isdigit(parser->current_pos))
            parser->current_pos++;
        if (parser->current_pos == '.' && ft_isdigit(parser->current_pos + 1))
            parser->current_pos++;
        while (ft_isdigit(parser->current_pos))
            parser->current_pos++;
        return (TOK_NUMBER);
    }
    if (ft_isalpha(parser->current_pos))
    {
        while (parser->current_pos == '_' || ft_isdigit(parser->current_pos) || ft_isalpha(parser->current_pos))
            parser->current_pos++;
    }


}
