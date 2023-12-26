//
// Created by Sascha Roggatz on 26.12.23.
//

#include "string_view"
#include "unordered_map"

typedef struct Token {
    std::string_view Type;
    std::string_view Literal;
} Token;

enum TokenType {
    Illegal, Eof, Identifier, Label, Int, String, Comma,

    // math
    Add, And, Dec, Div, Inc, Mul, Or, Sub, Xor,

    // control-flow
    Call, Jmp, Jmpnz, Jmpz, Ret,

    // stack
    Push, Pop,

    // types
    Is_String, Is_Integer, String2Int, Int2String,

    // compare
    Cmp,

    // store
    Store,

    // print
    Print_Int, Print_Str,

    // memory
    Peek, Poke,

    // misc
    Concat, Data, Db, Exit, Memcpy, Nop, Random, System, Trap

};

std::unordered_map<std::string_view, TokenType> keywords =
        {
                // math
                {"add", Add},
                {"and", And},
                {"dec", Dec},
                {"div", Div},
                {"inc", Inc},
                {"mul", Mul},
                {"or", Or},
                {"sub", Sub},
                {"xor", Xor},

                // control-flow
                {"call", Call},
                {"jmp", Jmp},
                {"jmpnz", Jmpnz},
                {"jmpz", Jmpz},
                {"ret", Ret},

                // stack
                {"push", Push},
                {"pop", Pop},

                // types
                {"is_integer", Is_Integer},
                {"is_string", Is_String},
                {"int2string", Int2String},
                {"string2int", String2Int},

                // compare
                {"cmp", Cmp},

                // store
                {"store", Store},

                // print
                {"print_int", Print_Int},
                {"print_str", Print_Str},

                // memory
                {"peek", Peek},
                {"poke", Poke},

                // misc
                {"exit", Exit},
                {"concat", Concat},
                {"data", Data},
                {"db", Db},
                {"trap", Trap},
                {"memcpy", Memcpy},
                {"nop", Nop},
                {"random", Random},
                {"system", System}
        };

TokenType LookupKeywordTokenType(const std::string_view identifier) {
    auto iter = keywords.find(identifier);
    if (iter != keywords.end())
        return iter->second;

    return Identifier;
}
