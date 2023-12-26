//
// Created by Sascha Roggatz on 26.12.23.
//

#include <string_view>
#include <unordered_map>

/**
 * @class Token
 * @brief Represents a token with a type and a literal value.
 */
typedef struct Token {
    std::string_view Type;
    std::string_view Literal;
} Token;

/**
 * @enum TokenType
 * @brief Enumeration of all possible token types in the system.
 *
 * This enumeration represents all possible token types that can be encountered
 * while tokenizing a source code or during parsing. Each token type has a unique
 * identifier that can be used to distinguish it from other token types.
 *
 */
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

namespace Utils {
    /**
     * @brief Finds the value associated with a given key in the provided unordered map.
     *        If the key is not found, returns the specified default value.
     *
     * @tparam K The type of the key.
     * @tparam V The type of the value.
     * @param m The unordered map to search in.
     * @param key The key to search for.
     * @param default_value The default value to return if the key is not found.
     * @return The value associated with the key if found, otherwise the default value.
     */
    template<class K, class V>
    V FindOrDefault(const std::unordered_map<K, V>& m, K key, V default_value) {
        auto iter = m.find(key);
        return (iter != m.end()) ? iter->second : default_value;
    }
}

/**
 * @fn TokenType KeywordType(const std::string_view identifier)
 * @brief Determines the token type based on a given identifier.
 *
 * This function takes a string_view representing an identifier and returns
 * the corresponding token type. It searches for the identifier in a pre-defined
 * unordered map called keywords. If the identifier is found, it returns the
 * corresponding token type. If the identifier is not found, it returns the
 * Identifier token type.
 *
 * @param identifier The identifier to be checked.
 * @return The token type corresponding to the identifier.
 */
TokenType KeywordType(const std::string_view identifier) {
    return Utils::FindOrDefault(keywords, identifier, Identifier);
}