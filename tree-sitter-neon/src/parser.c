#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 45
#define LARGE_STATE_COUNT 34
#define SYMBOL_COUNT 59
#define ALIAS_COUNT 2
#define TOKEN_COUNT 37
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 4
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 6

enum ts_symbol_identifiers {
  anon_sym_DASH = 1,
  anon_sym_COLON = 2,
  anon_sym_EQ = 3,
  anon_sym_LBRACK = 4,
  anon_sym_RBRACK = 5,
  anon_sym_LBRACE = 6,
  anon_sym_RBRACE = 7,
  anon_sym_LPAREN = 8,
  anon_sym_RPAREN = 9,
  sym_single_quote_string = 10,
  anon_sym_DQUOTE = 11,
  aux_sym_double_quote_string_token1 = 12,
  sym_triple_single_quote_string = 13,
  sym_triple_double_quote_string = 14,
  sym_escape_sequence = 15,
  sym_number = 16,
  sym_date = 17,
  anon_sym_true = 18,
  anon_sym_TRUE = 19,
  anon_sym_True = 20,
  anon_sym_false = 21,
  anon_sym_FALSE = 22,
  anon_sym_False = 23,
  anon_sym_yes = 24,
  anon_sym_YES = 25,
  anon_sym_Yes = 26,
  anon_sym_no = 27,
  anon_sym_NO = 28,
  anon_sym_No = 29,
  anon_sym_null = 30,
  anon_sym_NULL = 31,
  anon_sym_Null = 32,
  sym_unquoted_string = 33,
  sym_comment = 34,
  anon_sym_COMMA = 35,
  sym__newline = 36,
  sym_source_file = 37,
  sym__statement = 38,
  sym_block_sequence_item = 39,
  sym_block_mapping_pair = 40,
  sym__value = 41,
  sym_inline_sequence = 42,
  sym_inline_mapping = 43,
  sym_inline_mapping_pair = 44,
  sym_entity_chain = 45,
  sym_entity = 46,
  sym_entity_argument = 47,
  sym__key = 48,
  sym_double_quote_string = 49,
  sym_multiline_string = 50,
  sym_boolean = 51,
  sym_null = 52,
  sym__separator = 53,
  aux_sym_source_file_repeat1 = 54,
  aux_sym_inline_sequence_repeat1 = 55,
  aux_sym_entity_chain_repeat1 = 56,
  aux_sym_entity_repeat1 = 57,
  aux_sym_double_quote_string_repeat1 = 58,
  alias_sym_entity_name = 59,
  alias_sym_identifier = 60,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_DASH] = "-",
  [anon_sym_COLON] = ":",
  [anon_sym_EQ] = "=",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [sym_single_quote_string] = "single_quote_string",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_double_quote_string_token1] = "double_quote_string_token1",
  [sym_triple_single_quote_string] = "triple_single_quote_string",
  [sym_triple_double_quote_string] = "triple_double_quote_string",
  [sym_escape_sequence] = "escape_sequence",
  [sym_number] = "number",
  [sym_date] = "date",
  [anon_sym_true] = "true",
  [anon_sym_TRUE] = "TRUE",
  [anon_sym_True] = "True",
  [anon_sym_false] = "false",
  [anon_sym_FALSE] = "FALSE",
  [anon_sym_False] = "False",
  [anon_sym_yes] = "yes",
  [anon_sym_YES] = "YES",
  [anon_sym_Yes] = "Yes",
  [anon_sym_no] = "no",
  [anon_sym_NO] = "NO",
  [anon_sym_No] = "No",
  [anon_sym_null] = "null",
  [anon_sym_NULL] = "NULL",
  [anon_sym_Null] = "Null",
  [sym_unquoted_string] = "unquoted_string",
  [sym_comment] = "comment",
  [anon_sym_COMMA] = ",",
  [sym__newline] = "_newline",
  [sym_source_file] = "source_file",
  [sym__statement] = "_statement",
  [sym_block_sequence_item] = "block_sequence_item",
  [sym_block_mapping_pair] = "block_mapping_pair",
  [sym__value] = "_value",
  [sym_inline_sequence] = "inline_sequence",
  [sym_inline_mapping] = "inline_mapping",
  [sym_inline_mapping_pair] = "inline_mapping_pair",
  [sym_entity_chain] = "entity_chain",
  [sym_entity] = "entity",
  [sym_entity_argument] = "entity_argument",
  [sym__key] = "_key",
  [sym_double_quote_string] = "double_quote_string",
  [sym_multiline_string] = "multiline_string",
  [sym_boolean] = "boolean",
  [sym_null] = "null",
  [sym__separator] = "_separator",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_inline_sequence_repeat1] = "inline_sequence_repeat1",
  [aux_sym_entity_chain_repeat1] = "entity_chain_repeat1",
  [aux_sym_entity_repeat1] = "entity_repeat1",
  [aux_sym_double_quote_string_repeat1] = "double_quote_string_repeat1",
  [alias_sym_entity_name] = "entity_name",
  [alias_sym_identifier] = "identifier",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [sym_single_quote_string] = sym_single_quote_string,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_double_quote_string_token1] = aux_sym_double_quote_string_token1,
  [sym_triple_single_quote_string] = sym_triple_single_quote_string,
  [sym_triple_double_quote_string] = sym_triple_double_quote_string,
  [sym_escape_sequence] = sym_escape_sequence,
  [sym_number] = sym_number,
  [sym_date] = sym_date,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_TRUE] = anon_sym_TRUE,
  [anon_sym_True] = anon_sym_True,
  [anon_sym_false] = anon_sym_false,
  [anon_sym_FALSE] = anon_sym_FALSE,
  [anon_sym_False] = anon_sym_False,
  [anon_sym_yes] = anon_sym_yes,
  [anon_sym_YES] = anon_sym_YES,
  [anon_sym_Yes] = anon_sym_Yes,
  [anon_sym_no] = anon_sym_no,
  [anon_sym_NO] = anon_sym_NO,
  [anon_sym_No] = anon_sym_No,
  [anon_sym_null] = anon_sym_null,
  [anon_sym_NULL] = anon_sym_NULL,
  [anon_sym_Null] = anon_sym_Null,
  [sym_unquoted_string] = sym_unquoted_string,
  [sym_comment] = sym_comment,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [sym__newline] = sym__newline,
  [sym_source_file] = sym_source_file,
  [sym__statement] = sym__statement,
  [sym_block_sequence_item] = sym_block_sequence_item,
  [sym_block_mapping_pair] = sym_block_mapping_pair,
  [sym__value] = sym__value,
  [sym_inline_sequence] = sym_inline_sequence,
  [sym_inline_mapping] = sym_inline_mapping,
  [sym_inline_mapping_pair] = sym_inline_mapping_pair,
  [sym_entity_chain] = sym_entity_chain,
  [sym_entity] = sym_entity,
  [sym_entity_argument] = sym_entity_argument,
  [sym__key] = sym__key,
  [sym_double_quote_string] = sym_double_quote_string,
  [sym_multiline_string] = sym_multiline_string,
  [sym_boolean] = sym_boolean,
  [sym_null] = sym_null,
  [sym__separator] = sym__separator,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_inline_sequence_repeat1] = aux_sym_inline_sequence_repeat1,
  [aux_sym_entity_chain_repeat1] = aux_sym_entity_chain_repeat1,
  [aux_sym_entity_repeat1] = aux_sym_entity_repeat1,
  [aux_sym_double_quote_string_repeat1] = aux_sym_double_quote_string_repeat1,
  [alias_sym_entity_name] = alias_sym_entity_name,
  [alias_sym_identifier] = alias_sym_identifier,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [sym_single_quote_string] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_double_quote_string_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_triple_single_quote_string] = {
    .visible = true,
    .named = true,
  },
  [sym_triple_double_quote_string] = {
    .visible = true,
    .named = true,
  },
  [sym_escape_sequence] = {
    .visible = true,
    .named = true,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [sym_date] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_true] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_TRUE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_True] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_false] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_FALSE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_False] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_yes] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_YES] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Yes] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_no] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_NO] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_No] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_null] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_NULL] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Null] = {
    .visible = true,
    .named = false,
  },
  [sym_unquoted_string] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [sym__newline] = {
    .visible = false,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__statement] = {
    .visible = false,
    .named = true,
  },
  [sym_block_sequence_item] = {
    .visible = true,
    .named = true,
  },
  [sym_block_mapping_pair] = {
    .visible = true,
    .named = true,
  },
  [sym__value] = {
    .visible = false,
    .named = true,
  },
  [sym_inline_sequence] = {
    .visible = true,
    .named = true,
  },
  [sym_inline_mapping] = {
    .visible = true,
    .named = true,
  },
  [sym_inline_mapping_pair] = {
    .visible = true,
    .named = true,
  },
  [sym_entity_chain] = {
    .visible = true,
    .named = true,
  },
  [sym_entity] = {
    .visible = true,
    .named = true,
  },
  [sym_entity_argument] = {
    .visible = true,
    .named = true,
  },
  [sym__key] = {
    .visible = false,
    .named = true,
  },
  [sym_double_quote_string] = {
    .visible = true,
    .named = true,
  },
  [sym_multiline_string] = {
    .visible = true,
    .named = true,
  },
  [sym_boolean] = {
    .visible = true,
    .named = true,
  },
  [sym_null] = {
    .visible = true,
    .named = true,
  },
  [sym__separator] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_inline_sequence_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_entity_chain_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_entity_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_double_quote_string_repeat1] = {
    .visible = false,
    .named = false,
  },
  [alias_sym_entity_name] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_identifier] = {
    .visible = true,
    .named = true,
  },
};

enum ts_field_identifiers {
  field_key = 1,
  field_name = 2,
  field_operator = 3,
  field_value = 4,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_key] = "key",
  [field_name] = "name",
  [field_operator] = "operator",
  [field_value] = "value",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [3] = {.index = 0, .length = 2},
  [4] = {.index = 2, .length = 1},
  [5] = {.index = 3, .length = 3},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_key, 0},
    {field_operator, 1},
  [2] =
    {field_name, 0},
  [3] =
    {field_key, 0},
    {field_operator, 1},
    {field_value, 2},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [1] = {
    [0] = alias_sym_identifier,
  },
  [2] = {
    [0] = alias_sym_entity_name,
  },
  [4] = {
    [0] = alias_sym_entity_name,
  },
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
};

static TSCharacterRange sym_unquoted_string_character_set_2[] = {
  {0, 0x08}, {0x0e, 0x1f}, {'!', '!'}, {'#', '&'}, {'*', '+'}, {'-', '<'}, {'>', 'Z'}, {'\\', '\\'},
  {'^', 'z'}, {'|', '|'}, {'~', 0x10ffff},
};

static TSCharacterRange sym_unquoted_string_character_set_4[] = {
  {0, 0x08}, {0x0e, 0x1f}, {'!', '\''}, {'*', '+'}, {'-', '<'}, {'>', 'Z'}, {'\\', '\\'}, {'^', 'z'},
  {'|', '|'}, {'~', 0x10ffff},
};

static TSCharacterRange sym_unquoted_string_character_set_5[] = {
  {0, '\t'}, {0x0e, '"'}, {'$', '\''}, {'*', '+'}, {'-', '9'}, {';', '<'}, {'>', 'Z'}, {'\\', '\\'},
  {'^', 'z'}, {'|', '|'}, {'~', 0x10ffff},
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(90);
      ADVANCE_MAP(
        '\n', 231,
        '"', 105,
        '#', 229,
        '\'', 15,
        '(', 100,
        ')', 101,
        '+', 18,
        ',', 230,
        '-', 91,
        '.', 63,
        '0', 114,
        ':', 93,
        '=', 95,
        'F', 22,
        'N', 29,
        'T', 30,
        'Y', 23,
        '[', 96,
        '\\', 53,
        ']', 97,
        'f', 34,
        'n', 46,
        't', 47,
        'y', 39,
        '{', 98,
        '}', 99,
      );
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(88);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(118);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(3);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(3);
      if (lookahead == '\r') ADVANCE(1);
      END_STATE();
    case 3:
      if (lookahead == '\n') ADVANCE(3);
      if (lookahead == '"') ADVANCE(5);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(3);
      if (lookahead != 0) ADVANCE(6);
      END_STATE();
    case 4:
      if (lookahead == '\n') ADVANCE(3);
      if (lookahead == '"') ADVANCE(110);
      if (lookahead != 0) ADVANCE(6);
      END_STATE();
    case 5:
      if (lookahead == '\n') ADVANCE(3);
      if (lookahead == '"') ADVANCE(4);
      if (lookahead != 0) ADVANCE(6);
      END_STATE();
    case 6:
      if (lookahead == '\n') ADVANCE(3);
      if (lookahead != 0) ADVANCE(6);
      END_STATE();
    case 7:
      if (lookahead == '\n') ADVANCE(10);
      if (lookahead == '\r') ADVANCE(9);
      if (lookahead == '\'') ADVANCE(103);
      if (lookahead != 0) ADVANCE(16);
      END_STATE();
    case 8:
      if (lookahead == '\n') ADVANCE(10);
      if (lookahead == '\'') ADVANCE(109);
      if (lookahead != 0) ADVANCE(12);
      END_STATE();
    case 9:
      if (lookahead == '\n') ADVANCE(10);
      if (lookahead == '\'') ADVANCE(103);
      if (lookahead != 0) ADVANCE(16);
      END_STATE();
    case 10:
      if (lookahead == '\n') ADVANCE(10);
      if (lookahead == '\'') ADVANCE(11);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(10);
      if (lookahead != 0) ADVANCE(12);
      END_STATE();
    case 11:
      if (lookahead == '\n') ADVANCE(10);
      if (lookahead == '\'') ADVANCE(8);
      if (lookahead != 0) ADVANCE(12);
      END_STATE();
    case 12:
      if (lookahead == '\n') ADVANCE(10);
      if (lookahead != 0) ADVANCE(12);
      END_STATE();
    case 13:
      if (lookahead == '"') ADVANCE(2);
      END_STATE();
    case 14:
      if (lookahead == '"') ADVANCE(104);
      if (lookahead == '#') ADVANCE(107);
      if (lookahead == '\\') ADVANCE(53);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(106);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n') ADVANCE(108);
      END_STATE();
    case 15:
      if (lookahead == '\'') ADVANCE(102);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(16);
      END_STATE();
    case 16:
      if (lookahead == '\'') ADVANCE(103);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(16);
      END_STATE();
    case 17:
      if (lookahead == '-') ADVANCE(73);
      END_STATE();
    case 18:
      if (lookahead == '.') ADVANCE(63);
      if (lookahead == '0') ADVANCE(115);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(119);
      END_STATE();
    case 19:
      if (lookahead == ':') ADVANCE(81);
      END_STATE();
    case 20:
      if (lookahead == ':') ADVANCE(74);
      END_STATE();
    case 21:
      if (lookahead == ':') ADVANCE(77);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(71);
      END_STATE();
    case 22:
      if (lookahead == 'A') ADVANCE(27);
      if (lookahead == 'a') ADVANCE(43);
      END_STATE();
    case 23:
      if (lookahead == 'E') ADVANCE(31);
      if (lookahead == 'e') ADVANCE(48);
      END_STATE();
    case 24:
      if (lookahead == 'E') ADVANCE(146);
      END_STATE();
    case 25:
      if (lookahead == 'E') ADVANCE(152);
      END_STATE();
    case 26:
      if (lookahead == 'L') ADVANCE(170);
      END_STATE();
    case 27:
      if (lookahead == 'L') ADVANCE(32);
      END_STATE();
    case 28:
      if (lookahead == 'L') ADVANCE(26);
      END_STATE();
    case 29:
      if (lookahead == 'O') ADVANCE(164);
      if (lookahead == 'U') ADVANCE(28);
      if (lookahead == 'o') ADVANCE(166);
      if (lookahead == 'u') ADVANCE(42);
      END_STATE();
    case 30:
      if (lookahead == 'R') ADVANCE(33);
      if (lookahead == 'r') ADVANCE(52);
      END_STATE();
    case 31:
      if (lookahead == 'S') ADVANCE(158);
      END_STATE();
    case 32:
      if (lookahead == 'S') ADVANCE(25);
      END_STATE();
    case 33:
      if (lookahead == 'U') ADVANCE(24);
      END_STATE();
    case 34:
      if (lookahead == 'a') ADVANCE(45);
      END_STATE();
    case 35:
      if (lookahead == 'e') ADVANCE(148);
      END_STATE();
    case 36:
      if (lookahead == 'e') ADVANCE(144);
      END_STATE();
    case 37:
      if (lookahead == 'e') ADVANCE(154);
      END_STATE();
    case 38:
      if (lookahead == 'e') ADVANCE(150);
      END_STATE();
    case 39:
      if (lookahead == 'e') ADVANCE(49);
      END_STATE();
    case 40:
      if (lookahead == 'l') ADVANCE(172);
      END_STATE();
    case 41:
      if (lookahead == 'l') ADVANCE(168);
      END_STATE();
    case 42:
      if (lookahead == 'l') ADVANCE(40);
      END_STATE();
    case 43:
      if (lookahead == 'l') ADVANCE(50);
      END_STATE();
    case 44:
      if (lookahead == 'l') ADVANCE(41);
      END_STATE();
    case 45:
      if (lookahead == 'l') ADVANCE(51);
      END_STATE();
    case 46:
      if (lookahead == 'o') ADVANCE(162);
      if (lookahead == 'u') ADVANCE(44);
      END_STATE();
    case 47:
      if (lookahead == 'r') ADVANCE(54);
      END_STATE();
    case 48:
      if (lookahead == 's') ADVANCE(160);
      END_STATE();
    case 49:
      if (lookahead == 's') ADVANCE(156);
      END_STATE();
    case 50:
      if (lookahead == 's') ADVANCE(37);
      END_STATE();
    case 51:
      if (lookahead == 's') ADVANCE(38);
      END_STATE();
    case 52:
      if (lookahead == 'u') ADVANCE(35);
      END_STATE();
    case 53:
      ADVANCE_MAP(
        'u', 86,
        '"', 111,
        '/', 111,
        '\\', 111,
        '_', 111,
        'b', 111,
        'f', 111,
        'n', 111,
        'r', 111,
        't', 111,
      );
      END_STATE();
    case 54:
      if (lookahead == 'u') ADVANCE(36);
      END_STATE();
    case 55:
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(55);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(67);
      END_STATE();
    case 56:
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(56);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(76);
      END_STATE();
    case 57:
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_5, 11, lookahead))) ADVANCE(225);
      END_STATE();
    case 58:
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(58);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(217);
      if ((!eof && set_contains(sym_unquoted_string_character_set_5, 11, lookahead))) ADVANCE(225);
      END_STATE();
    case 59:
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(59);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(223);
      if ((!eof && set_contains(sym_unquoted_string_character_set_5, 11, lookahead))) ADVANCE(225);
      END_STATE();
    case 60:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(64);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(134);
      END_STATE();
    case 61:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(132);
      END_STATE();
    case 62:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(133);
      END_STATE();
    case 63:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(131);
      END_STATE();
    case 64:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(134);
      END_STATE();
    case 65:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(17);
      END_STATE();
    case 66:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(142);
      END_STATE();
    case 67:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(19);
      END_STATE();
    case 68:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(137);
      END_STATE();
    case 69:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(143);
      END_STATE();
    case 70:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(21);
      END_STATE();
    case 71:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(136);
      END_STATE();
    case 72:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(65);
      END_STATE();
    case 73:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(66);
      END_STATE();
    case 74:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(68);
      END_STATE();
    case 75:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(215);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 76:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(70);
      END_STATE();
    case 77:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(71);
      END_STATE();
    case 78:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(218);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 79:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(222);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 80:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(20);
      END_STATE();
    case 81:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(80);
      END_STATE();
    case 82:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(111);
      END_STATE();
    case 83:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(135);
      END_STATE();
    case 84:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(82);
      END_STATE();
    case 85:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(84);
      END_STATE();
    case 86:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(85);
      END_STATE();
    case 87:
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 88:
      if (eof) ADVANCE(90);
      ADVANCE_MAP(
        '\n', 231,
        '"', 105,
        '#', 229,
        '\'', 15,
        '(', 100,
        ')', 101,
        '+', 18,
        ',', 230,
        '-', 91,
        '.', 63,
        '0', 114,
        ':', 93,
        '=', 95,
        'F', 22,
        'N', 29,
        'T', 30,
        'Y', 23,
        '[', 96,
        ']', 97,
        'f', 34,
        'n', 46,
        't', 47,
        'y', 39,
        '{', 98,
        '}', 99,
      );
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(88);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(118);
      END_STATE();
    case 89:
      if (eof) ADVANCE(90);
      ADVANCE_MAP(
        '\n', 231,
        '"', 105,
        '#', 229,
        '\'', 15,
        '(', 100,
        ')', 101,
        '+', 175,
        ',', 230,
        '-', 92,
        '.', 211,
        '0', 120,
        ':', 94,
        '=', 95,
        'F', 176,
        'N', 183,
        'T', 184,
        'Y', 177,
        '[', 96,
        ']', 97,
        'f', 188,
        'n', 200,
        't', 201,
        'y', 193,
        '{', 98,
        '}', 99,
      );
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(89);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(124);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '`') ADVANCE(225);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '.') ADVANCE(63);
      if (lookahead == '0') ADVANCE(115);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(119);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '.') ADVANCE(211);
      if (lookahead == '0') ADVANCE(121);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(125);
      if ((!eof && set_contains(sym_unquoted_string_character_set_2, 11, lookahead))) ADVANCE(225);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(anon_sym_COLON);
      if ((!eof && set_contains(sym_unquoted_string_character_set_2, 11, lookahead))) ADVANCE(225);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(sym_single_quote_string);
      if (lookahead == '\'') ADVANCE(7);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(sym_single_quote_string);
      if (lookahead == '\'') ADVANCE(16);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      if (lookahead == '"') ADVANCE(13);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(aux_sym_double_quote_string_token1);
      if (lookahead == '#') ADVANCE(107);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(106);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '#' &&
          lookahead != '\\') ADVANCE(108);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(aux_sym_double_quote_string_token1);
      if (lookahead == '"' ||
          lookahead == '\\') ADVANCE(229);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(107);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(aux_sym_double_quote_string_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(108);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(sym_triple_single_quote_string);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(sym_triple_double_quote_string);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '-') ADVANCE(72);
      if (lookahead == '.') ADVANCE(131);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(119);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '-') ADVANCE(219);
      if (lookahead == '.') ADVANCE(126);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(208);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(125);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(sym_number);
      ADVANCE_MAP(
        '.', 131,
        'B', 61,
        'b', 61,
        'E', 60,
        'e', 60,
        'O', 62,
        'o', 62,
        'X', 83,
        'x', 83,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(117);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(sym_number);
      ADVANCE_MAP(
        '.', 131,
        'B', 61,
        'b', 61,
        'E', 60,
        'e', 60,
        'O', 62,
        'o', 62,
        'X', 83,
        'x', 83,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(119);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.') ADVANCE(131);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(112);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.') ADVANCE(131);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(116);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.') ADVANCE(131);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(117);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.') ADVANCE(131);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(119);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym_number);
      ADVANCE_MAP(
        '.', 126,
        ':', 87,
        '\t', 57,
        ' ', 57,
        'B', 209,
        'b', 209,
        'E', 208,
        'e', 208,
        'O', 210,
        'o', 210,
        'X', 224,
        'x', 224,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(123);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(sym_number);
      ADVANCE_MAP(
        '.', 126,
        ':', 87,
        '\t', 57,
        ' ', 57,
        'B', 209,
        'b', 209,
        'E', 208,
        'e', 208,
        'O', 210,
        'o', 210,
        'X', 224,
        'x', 224,
      );
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(125);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.') ADVANCE(126);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(208);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(113);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.') ADVANCE(126);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(208);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(122);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.') ADVANCE(126);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(208);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(123);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.') ADVANCE(126);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(208);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(125);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(208);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(126);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(127);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(128);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(129);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(130);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(131);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(132);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(133);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(134);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(135);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(sym_date);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(sym_date);
      if (lookahead == '.') ADVANCE(69);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(56);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(sym_date);
      if (lookahead == '.') ADVANCE(216);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(59);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(sym_date);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(sym_date);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(58);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(sym_date);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(59);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(141);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(sym_date);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(55);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(sym_date);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(56);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(143);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(anon_sym_true);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(anon_sym_TRUE);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(anon_sym_TRUE);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(anon_sym_True);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(anon_sym_True);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(anon_sym_false);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(anon_sym_FALSE);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(anon_sym_FALSE);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(anon_sym_False);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(anon_sym_False);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(anon_sym_yes);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(anon_sym_yes);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(anon_sym_YES);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(anon_sym_YES);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(anon_sym_Yes);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(anon_sym_Yes);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(anon_sym_no);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(anon_sym_no);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(anon_sym_NO);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(anon_sym_NO);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(anon_sym_No);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(anon_sym_No);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(anon_sym_null);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(anon_sym_null);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(anon_sym_NULL);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(anon_sym_NULL);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(anon_sym_Null);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(anon_sym_Null);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == '-') ADVANCE(220);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == '.') ADVANCE(211);
      if (lookahead == '0') ADVANCE(121);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(125);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == 'A') ADVANCE(181);
      if (lookahead == 'a') ADVANCE(197);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == 'E') ADVANCE(185);
      if (lookahead == 'e') ADVANCE(202);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == 'E') ADVANCE(147);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == 'E') ADVANCE(153);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == 'L') ADVANCE(171);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == 'L') ADVANCE(186);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == 'L') ADVANCE(180);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == 'O') ADVANCE(165);
      if (lookahead == 'U') ADVANCE(182);
      if (lookahead == 'o') ADVANCE(167);
      if (lookahead == 'u') ADVANCE(196);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == 'R') ADVANCE(187);
      if (lookahead == 'r') ADVANCE(206);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == 'S') ADVANCE(159);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == 'S') ADVANCE(179);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == 'U') ADVANCE(178);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == 'a') ADVANCE(199);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == 'e') ADVANCE(149);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == 'e') ADVANCE(145);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == 'e') ADVANCE(155);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == 'e') ADVANCE(151);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == 'e') ADVANCE(203);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == 'l') ADVANCE(173);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == 'l') ADVANCE(169);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == 'l') ADVANCE(194);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == 'l') ADVANCE(204);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == 'l') ADVANCE(195);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == 'l') ADVANCE(205);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == 'o') ADVANCE(163);
      if (lookahead == 'u') ADVANCE(198);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == 'r') ADVANCE(207);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == 's') ADVANCE(161);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == 's') ADVANCE(157);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == 's') ADVANCE(191);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == 's') ADVANCE(192);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == 'u') ADVANCE(189);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == 'u') ADVANCE(190);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(212);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(129);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(127);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(128);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(126);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(129);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(174);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(140);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(138);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(141);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(226);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(139);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(213);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(214);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(228);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(227);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(221);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(130);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(79);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(75);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(sym_unquoted_string);
      if (lookahead == ':') ADVANCE(78);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(218);
      if ((!eof && set_contains(sym_unquoted_string_character_set_4, 10, lookahead))) ADVANCE(225);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(229);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(sym__newline);
      if (lookahead == '\n') ADVANCE(231);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 89},
  [2] = {.lex_state = 89},
  [3] = {.lex_state = 89},
  [4] = {.lex_state = 89},
  [5] = {.lex_state = 89},
  [6] = {.lex_state = 89},
  [7] = {.lex_state = 89},
  [8] = {.lex_state = 89},
  [9] = {.lex_state = 89},
  [10] = {.lex_state = 89},
  [11] = {.lex_state = 89},
  [12] = {.lex_state = 89},
  [13] = {.lex_state = 89},
  [14] = {.lex_state = 89},
  [15] = {.lex_state = 89},
  [16] = {.lex_state = 89},
  [17] = {.lex_state = 89},
  [18] = {.lex_state = 89},
  [19] = {.lex_state = 89},
  [20] = {.lex_state = 89},
  [21] = {.lex_state = 89},
  [22] = {.lex_state = 89},
  [23] = {.lex_state = 89},
  [24] = {.lex_state = 89},
  [25] = {.lex_state = 89},
  [26] = {.lex_state = 89},
  [27] = {.lex_state = 89},
  [28] = {.lex_state = 89},
  [29] = {.lex_state = 89},
  [30] = {.lex_state = 89},
  [31] = {.lex_state = 89},
  [32] = {.lex_state = 89},
  [33] = {.lex_state = 89},
  [34] = {.lex_state = 89},
  [35] = {.lex_state = 89},
  [36] = {.lex_state = 89},
  [37] = {.lex_state = 89},
  [38] = {.lex_state = 14},
  [39] = {.lex_state = 14},
  [40] = {.lex_state = 14},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [sym_single_quote_string] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [sym_triple_single_quote_string] = ACTIONS(1),
    [sym_triple_double_quote_string] = ACTIONS(1),
    [sym_escape_sequence] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
    [sym_date] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_TRUE] = ACTIONS(1),
    [anon_sym_True] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [anon_sym_FALSE] = ACTIONS(1),
    [anon_sym_False] = ACTIONS(1),
    [anon_sym_yes] = ACTIONS(1),
    [anon_sym_YES] = ACTIONS(1),
    [anon_sym_Yes] = ACTIONS(1),
    [anon_sym_no] = ACTIONS(1),
    [anon_sym_NO] = ACTIONS(1),
    [anon_sym_No] = ACTIONS(1),
    [anon_sym_null] = ACTIONS(1),
    [anon_sym_NULL] = ACTIONS(1),
    [anon_sym_Null] = ACTIONS(1),
    [sym_comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(1),
    [sym__newline] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(44),
    [sym__statement] = STATE(2),
    [sym_block_sequence_item] = STATE(2),
    [sym_block_mapping_pair] = STATE(2),
    [sym__value] = STATE(2),
    [sym_inline_sequence] = STATE(2),
    [sym_inline_mapping] = STATE(2),
    [sym_entity_chain] = STATE(2),
    [sym_entity] = STATE(17),
    [sym__key] = STATE(41),
    [sym_double_quote_string] = STATE(22),
    [sym_multiline_string] = STATE(2),
    [sym_boolean] = STATE(22),
    [sym_null] = STATE(22),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(5),
    [anon_sym_DASH] = ACTIONS(7),
    [anon_sym_LBRACK] = ACTIONS(9),
    [anon_sym_LBRACE] = ACTIONS(11),
    [sym_single_quote_string] = ACTIONS(13),
    [anon_sym_DQUOTE] = ACTIONS(15),
    [sym_triple_single_quote_string] = ACTIONS(17),
    [sym_triple_double_quote_string] = ACTIONS(17),
    [sym_number] = ACTIONS(19),
    [sym_date] = ACTIONS(21),
    [anon_sym_true] = ACTIONS(23),
    [anon_sym_TRUE] = ACTIONS(23),
    [anon_sym_True] = ACTIONS(23),
    [anon_sym_false] = ACTIONS(23),
    [anon_sym_FALSE] = ACTIONS(23),
    [anon_sym_False] = ACTIONS(23),
    [anon_sym_yes] = ACTIONS(23),
    [anon_sym_YES] = ACTIONS(23),
    [anon_sym_Yes] = ACTIONS(23),
    [anon_sym_no] = ACTIONS(23),
    [anon_sym_NO] = ACTIONS(23),
    [anon_sym_No] = ACTIONS(23),
    [anon_sym_null] = ACTIONS(25),
    [anon_sym_NULL] = ACTIONS(25),
    [anon_sym_Null] = ACTIONS(25),
    [sym_unquoted_string] = ACTIONS(27),
    [sym_comment] = ACTIONS(3),
    [sym__newline] = ACTIONS(29),
  },
  [2] = {
    [sym__statement] = STATE(3),
    [sym_block_sequence_item] = STATE(3),
    [sym_block_mapping_pair] = STATE(3),
    [sym__value] = STATE(3),
    [sym_inline_sequence] = STATE(3),
    [sym_inline_mapping] = STATE(3),
    [sym_entity_chain] = STATE(3),
    [sym_entity] = STATE(17),
    [sym__key] = STATE(41),
    [sym_double_quote_string] = STATE(22),
    [sym_multiline_string] = STATE(3),
    [sym_boolean] = STATE(22),
    [sym_null] = STATE(22),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(31),
    [anon_sym_DASH] = ACTIONS(7),
    [anon_sym_LBRACK] = ACTIONS(9),
    [anon_sym_LBRACE] = ACTIONS(11),
    [sym_single_quote_string] = ACTIONS(13),
    [anon_sym_DQUOTE] = ACTIONS(15),
    [sym_triple_single_quote_string] = ACTIONS(17),
    [sym_triple_double_quote_string] = ACTIONS(17),
    [sym_number] = ACTIONS(19),
    [sym_date] = ACTIONS(33),
    [anon_sym_true] = ACTIONS(23),
    [anon_sym_TRUE] = ACTIONS(23),
    [anon_sym_True] = ACTIONS(23),
    [anon_sym_false] = ACTIONS(23),
    [anon_sym_FALSE] = ACTIONS(23),
    [anon_sym_False] = ACTIONS(23),
    [anon_sym_yes] = ACTIONS(23),
    [anon_sym_YES] = ACTIONS(23),
    [anon_sym_Yes] = ACTIONS(23),
    [anon_sym_no] = ACTIONS(23),
    [anon_sym_NO] = ACTIONS(23),
    [anon_sym_No] = ACTIONS(23),
    [anon_sym_null] = ACTIONS(25),
    [anon_sym_NULL] = ACTIONS(25),
    [anon_sym_Null] = ACTIONS(25),
    [sym_unquoted_string] = ACTIONS(27),
    [sym_comment] = ACTIONS(3),
    [sym__newline] = ACTIONS(35),
  },
  [3] = {
    [sym__statement] = STATE(3),
    [sym_block_sequence_item] = STATE(3),
    [sym_block_mapping_pair] = STATE(3),
    [sym__value] = STATE(3),
    [sym_inline_sequence] = STATE(3),
    [sym_inline_mapping] = STATE(3),
    [sym_entity_chain] = STATE(3),
    [sym_entity] = STATE(17),
    [sym__key] = STATE(41),
    [sym_double_quote_string] = STATE(22),
    [sym_multiline_string] = STATE(3),
    [sym_boolean] = STATE(22),
    [sym_null] = STATE(22),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(37),
    [anon_sym_DASH] = ACTIONS(39),
    [anon_sym_LBRACK] = ACTIONS(42),
    [anon_sym_LBRACE] = ACTIONS(45),
    [sym_single_quote_string] = ACTIONS(48),
    [anon_sym_DQUOTE] = ACTIONS(51),
    [sym_triple_single_quote_string] = ACTIONS(54),
    [sym_triple_double_quote_string] = ACTIONS(54),
    [sym_number] = ACTIONS(57),
    [sym_date] = ACTIONS(60),
    [anon_sym_true] = ACTIONS(63),
    [anon_sym_TRUE] = ACTIONS(63),
    [anon_sym_True] = ACTIONS(63),
    [anon_sym_false] = ACTIONS(63),
    [anon_sym_FALSE] = ACTIONS(63),
    [anon_sym_False] = ACTIONS(63),
    [anon_sym_yes] = ACTIONS(63),
    [anon_sym_YES] = ACTIONS(63),
    [anon_sym_Yes] = ACTIONS(63),
    [anon_sym_no] = ACTIONS(63),
    [anon_sym_NO] = ACTIONS(63),
    [anon_sym_No] = ACTIONS(63),
    [anon_sym_null] = ACTIONS(66),
    [anon_sym_NULL] = ACTIONS(66),
    [anon_sym_Null] = ACTIONS(66),
    [sym_unquoted_string] = ACTIONS(69),
    [sym_comment] = ACTIONS(3),
    [sym__newline] = ACTIONS(72),
  },
  [4] = {
    [sym__value] = STATE(4),
    [sym_inline_sequence] = STATE(4),
    [sym_inline_mapping] = STATE(4),
    [sym_inline_mapping_pair] = STATE(4),
    [sym_entity_chain] = STATE(4),
    [sym_entity] = STATE(17),
    [sym__key] = STATE(43),
    [sym_double_quote_string] = STATE(22),
    [sym_multiline_string] = STATE(4),
    [sym_boolean] = STATE(22),
    [sym_null] = STATE(22),
    [sym__separator] = STATE(4),
    [aux_sym_inline_sequence_repeat1] = STATE(4),
    [anon_sym_LBRACK] = ACTIONS(75),
    [anon_sym_RBRACK] = ACTIONS(78),
    [anon_sym_LBRACE] = ACTIONS(80),
    [anon_sym_RBRACE] = ACTIONS(78),
    [sym_single_quote_string] = ACTIONS(83),
    [anon_sym_DQUOTE] = ACTIONS(86),
    [sym_triple_single_quote_string] = ACTIONS(89),
    [sym_triple_double_quote_string] = ACTIONS(89),
    [sym_number] = ACTIONS(92),
    [sym_date] = ACTIONS(95),
    [anon_sym_true] = ACTIONS(98),
    [anon_sym_TRUE] = ACTIONS(98),
    [anon_sym_True] = ACTIONS(98),
    [anon_sym_false] = ACTIONS(98),
    [anon_sym_FALSE] = ACTIONS(98),
    [anon_sym_False] = ACTIONS(98),
    [anon_sym_yes] = ACTIONS(98),
    [anon_sym_YES] = ACTIONS(98),
    [anon_sym_Yes] = ACTIONS(98),
    [anon_sym_no] = ACTIONS(98),
    [anon_sym_NO] = ACTIONS(98),
    [anon_sym_No] = ACTIONS(98),
    [anon_sym_null] = ACTIONS(101),
    [anon_sym_NULL] = ACTIONS(101),
    [anon_sym_Null] = ACTIONS(101),
    [sym_unquoted_string] = ACTIONS(104),
    [sym_comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(107),
    [sym__newline] = ACTIONS(107),
  },
  [5] = {
    [sym__value] = STATE(4),
    [sym_inline_sequence] = STATE(4),
    [sym_inline_mapping] = STATE(4),
    [sym_inline_mapping_pair] = STATE(4),
    [sym_entity_chain] = STATE(4),
    [sym_entity] = STATE(17),
    [sym__key] = STATE(43),
    [sym_double_quote_string] = STATE(22),
    [sym_multiline_string] = STATE(4),
    [sym_boolean] = STATE(22),
    [sym_null] = STATE(22),
    [sym__separator] = STATE(4),
    [aux_sym_inline_sequence_repeat1] = STATE(4),
    [anon_sym_LBRACK] = ACTIONS(9),
    [anon_sym_LBRACE] = ACTIONS(11),
    [anon_sym_RBRACE] = ACTIONS(110),
    [sym_single_quote_string] = ACTIONS(13),
    [anon_sym_DQUOTE] = ACTIONS(15),
    [sym_triple_single_quote_string] = ACTIONS(17),
    [sym_triple_double_quote_string] = ACTIONS(17),
    [sym_number] = ACTIONS(19),
    [sym_date] = ACTIONS(112),
    [anon_sym_true] = ACTIONS(23),
    [anon_sym_TRUE] = ACTIONS(23),
    [anon_sym_True] = ACTIONS(23),
    [anon_sym_false] = ACTIONS(23),
    [anon_sym_FALSE] = ACTIONS(23),
    [anon_sym_False] = ACTIONS(23),
    [anon_sym_yes] = ACTIONS(23),
    [anon_sym_YES] = ACTIONS(23),
    [anon_sym_Yes] = ACTIONS(23),
    [anon_sym_no] = ACTIONS(23),
    [anon_sym_NO] = ACTIONS(23),
    [anon_sym_No] = ACTIONS(23),
    [anon_sym_null] = ACTIONS(25),
    [anon_sym_NULL] = ACTIONS(25),
    [anon_sym_Null] = ACTIONS(25),
    [sym_unquoted_string] = ACTIONS(27),
    [sym_comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(114),
    [sym__newline] = ACTIONS(114),
  },
  [6] = {
    [sym__value] = STATE(10),
    [sym_inline_sequence] = STATE(10),
    [sym_inline_mapping] = STATE(10),
    [sym_entity_chain] = STATE(10),
    [sym_entity] = STATE(17),
    [sym_entity_argument] = STATE(10),
    [sym__key] = STATE(42),
    [sym_double_quote_string] = STATE(22),
    [sym_multiline_string] = STATE(10),
    [sym_boolean] = STATE(22),
    [sym_null] = STATE(22),
    [sym__separator] = STATE(10),
    [aux_sym_entity_repeat1] = STATE(10),
    [anon_sym_LBRACK] = ACTIONS(9),
    [anon_sym_LBRACE] = ACTIONS(11),
    [anon_sym_RPAREN] = ACTIONS(116),
    [sym_single_quote_string] = ACTIONS(13),
    [anon_sym_DQUOTE] = ACTIONS(15),
    [sym_triple_single_quote_string] = ACTIONS(17),
    [sym_triple_double_quote_string] = ACTIONS(17),
    [sym_number] = ACTIONS(19),
    [sym_date] = ACTIONS(118),
    [anon_sym_true] = ACTIONS(23),
    [anon_sym_TRUE] = ACTIONS(23),
    [anon_sym_True] = ACTIONS(23),
    [anon_sym_false] = ACTIONS(23),
    [anon_sym_FALSE] = ACTIONS(23),
    [anon_sym_False] = ACTIONS(23),
    [anon_sym_yes] = ACTIONS(23),
    [anon_sym_YES] = ACTIONS(23),
    [anon_sym_Yes] = ACTIONS(23),
    [anon_sym_no] = ACTIONS(23),
    [anon_sym_NO] = ACTIONS(23),
    [anon_sym_No] = ACTIONS(23),
    [anon_sym_null] = ACTIONS(25),
    [anon_sym_NULL] = ACTIONS(25),
    [anon_sym_Null] = ACTIONS(25),
    [sym_unquoted_string] = ACTIONS(27),
    [sym_comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(120),
    [sym__newline] = ACTIONS(120),
  },
  [7] = {
    [sym__value] = STATE(8),
    [sym_inline_sequence] = STATE(8),
    [sym_inline_mapping] = STATE(8),
    [sym_inline_mapping_pair] = STATE(8),
    [sym_entity_chain] = STATE(8),
    [sym_entity] = STATE(17),
    [sym__key] = STATE(43),
    [sym_double_quote_string] = STATE(22),
    [sym_multiline_string] = STATE(8),
    [sym_boolean] = STATE(22),
    [sym_null] = STATE(22),
    [sym__separator] = STATE(8),
    [aux_sym_inline_sequence_repeat1] = STATE(8),
    [anon_sym_LBRACK] = ACTIONS(9),
    [anon_sym_RBRACK] = ACTIONS(122),
    [anon_sym_LBRACE] = ACTIONS(11),
    [sym_single_quote_string] = ACTIONS(13),
    [anon_sym_DQUOTE] = ACTIONS(15),
    [sym_triple_single_quote_string] = ACTIONS(17),
    [sym_triple_double_quote_string] = ACTIONS(17),
    [sym_number] = ACTIONS(19),
    [sym_date] = ACTIONS(124),
    [anon_sym_true] = ACTIONS(23),
    [anon_sym_TRUE] = ACTIONS(23),
    [anon_sym_True] = ACTIONS(23),
    [anon_sym_false] = ACTIONS(23),
    [anon_sym_FALSE] = ACTIONS(23),
    [anon_sym_False] = ACTIONS(23),
    [anon_sym_yes] = ACTIONS(23),
    [anon_sym_YES] = ACTIONS(23),
    [anon_sym_Yes] = ACTIONS(23),
    [anon_sym_no] = ACTIONS(23),
    [anon_sym_NO] = ACTIONS(23),
    [anon_sym_No] = ACTIONS(23),
    [anon_sym_null] = ACTIONS(25),
    [anon_sym_NULL] = ACTIONS(25),
    [anon_sym_Null] = ACTIONS(25),
    [sym_unquoted_string] = ACTIONS(27),
    [sym_comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(126),
    [sym__newline] = ACTIONS(126),
  },
  [8] = {
    [sym__value] = STATE(4),
    [sym_inline_sequence] = STATE(4),
    [sym_inline_mapping] = STATE(4),
    [sym_inline_mapping_pair] = STATE(4),
    [sym_entity_chain] = STATE(4),
    [sym_entity] = STATE(17),
    [sym__key] = STATE(43),
    [sym_double_quote_string] = STATE(22),
    [sym_multiline_string] = STATE(4),
    [sym_boolean] = STATE(22),
    [sym_null] = STATE(22),
    [sym__separator] = STATE(4),
    [aux_sym_inline_sequence_repeat1] = STATE(4),
    [anon_sym_LBRACK] = ACTIONS(9),
    [anon_sym_RBRACK] = ACTIONS(128),
    [anon_sym_LBRACE] = ACTIONS(11),
    [sym_single_quote_string] = ACTIONS(13),
    [anon_sym_DQUOTE] = ACTIONS(15),
    [sym_triple_single_quote_string] = ACTIONS(17),
    [sym_triple_double_quote_string] = ACTIONS(17),
    [sym_number] = ACTIONS(19),
    [sym_date] = ACTIONS(112),
    [anon_sym_true] = ACTIONS(23),
    [anon_sym_TRUE] = ACTIONS(23),
    [anon_sym_True] = ACTIONS(23),
    [anon_sym_false] = ACTIONS(23),
    [anon_sym_FALSE] = ACTIONS(23),
    [anon_sym_False] = ACTIONS(23),
    [anon_sym_yes] = ACTIONS(23),
    [anon_sym_YES] = ACTIONS(23),
    [anon_sym_Yes] = ACTIONS(23),
    [anon_sym_no] = ACTIONS(23),
    [anon_sym_NO] = ACTIONS(23),
    [anon_sym_No] = ACTIONS(23),
    [anon_sym_null] = ACTIONS(25),
    [anon_sym_NULL] = ACTIONS(25),
    [anon_sym_Null] = ACTIONS(25),
    [sym_unquoted_string] = ACTIONS(27),
    [sym_comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(114),
    [sym__newline] = ACTIONS(114),
  },
  [9] = {
    [sym__value] = STATE(5),
    [sym_inline_sequence] = STATE(5),
    [sym_inline_mapping] = STATE(5),
    [sym_inline_mapping_pair] = STATE(5),
    [sym_entity_chain] = STATE(5),
    [sym_entity] = STATE(17),
    [sym__key] = STATE(43),
    [sym_double_quote_string] = STATE(22),
    [sym_multiline_string] = STATE(5),
    [sym_boolean] = STATE(22),
    [sym_null] = STATE(22),
    [sym__separator] = STATE(5),
    [aux_sym_inline_sequence_repeat1] = STATE(5),
    [anon_sym_LBRACK] = ACTIONS(9),
    [anon_sym_LBRACE] = ACTIONS(11),
    [anon_sym_RBRACE] = ACTIONS(130),
    [sym_single_quote_string] = ACTIONS(13),
    [anon_sym_DQUOTE] = ACTIONS(15),
    [sym_triple_single_quote_string] = ACTIONS(17),
    [sym_triple_double_quote_string] = ACTIONS(17),
    [sym_number] = ACTIONS(19),
    [sym_date] = ACTIONS(132),
    [anon_sym_true] = ACTIONS(23),
    [anon_sym_TRUE] = ACTIONS(23),
    [anon_sym_True] = ACTIONS(23),
    [anon_sym_false] = ACTIONS(23),
    [anon_sym_FALSE] = ACTIONS(23),
    [anon_sym_False] = ACTIONS(23),
    [anon_sym_yes] = ACTIONS(23),
    [anon_sym_YES] = ACTIONS(23),
    [anon_sym_Yes] = ACTIONS(23),
    [anon_sym_no] = ACTIONS(23),
    [anon_sym_NO] = ACTIONS(23),
    [anon_sym_No] = ACTIONS(23),
    [anon_sym_null] = ACTIONS(25),
    [anon_sym_NULL] = ACTIONS(25),
    [anon_sym_Null] = ACTIONS(25),
    [sym_unquoted_string] = ACTIONS(27),
    [sym_comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(134),
    [sym__newline] = ACTIONS(134),
  },
  [10] = {
    [sym__value] = STATE(11),
    [sym_inline_sequence] = STATE(11),
    [sym_inline_mapping] = STATE(11),
    [sym_entity_chain] = STATE(11),
    [sym_entity] = STATE(17),
    [sym_entity_argument] = STATE(11),
    [sym__key] = STATE(42),
    [sym_double_quote_string] = STATE(22),
    [sym_multiline_string] = STATE(11),
    [sym_boolean] = STATE(22),
    [sym_null] = STATE(22),
    [sym__separator] = STATE(11),
    [aux_sym_entity_repeat1] = STATE(11),
    [anon_sym_LBRACK] = ACTIONS(9),
    [anon_sym_LBRACE] = ACTIONS(11),
    [anon_sym_RPAREN] = ACTIONS(136),
    [sym_single_quote_string] = ACTIONS(13),
    [anon_sym_DQUOTE] = ACTIONS(15),
    [sym_triple_single_quote_string] = ACTIONS(17),
    [sym_triple_double_quote_string] = ACTIONS(17),
    [sym_number] = ACTIONS(19),
    [sym_date] = ACTIONS(138),
    [anon_sym_true] = ACTIONS(23),
    [anon_sym_TRUE] = ACTIONS(23),
    [anon_sym_True] = ACTIONS(23),
    [anon_sym_false] = ACTIONS(23),
    [anon_sym_FALSE] = ACTIONS(23),
    [anon_sym_False] = ACTIONS(23),
    [anon_sym_yes] = ACTIONS(23),
    [anon_sym_YES] = ACTIONS(23),
    [anon_sym_Yes] = ACTIONS(23),
    [anon_sym_no] = ACTIONS(23),
    [anon_sym_NO] = ACTIONS(23),
    [anon_sym_No] = ACTIONS(23),
    [anon_sym_null] = ACTIONS(25),
    [anon_sym_NULL] = ACTIONS(25),
    [anon_sym_Null] = ACTIONS(25),
    [sym_unquoted_string] = ACTIONS(27),
    [sym_comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(140),
    [sym__newline] = ACTIONS(140),
  },
  [11] = {
    [sym__value] = STATE(11),
    [sym_inline_sequence] = STATE(11),
    [sym_inline_mapping] = STATE(11),
    [sym_entity_chain] = STATE(11),
    [sym_entity] = STATE(17),
    [sym_entity_argument] = STATE(11),
    [sym__key] = STATE(42),
    [sym_double_quote_string] = STATE(22),
    [sym_multiline_string] = STATE(11),
    [sym_boolean] = STATE(22),
    [sym_null] = STATE(22),
    [sym__separator] = STATE(11),
    [aux_sym_entity_repeat1] = STATE(11),
    [anon_sym_LBRACK] = ACTIONS(142),
    [anon_sym_LBRACE] = ACTIONS(145),
    [anon_sym_RPAREN] = ACTIONS(148),
    [sym_single_quote_string] = ACTIONS(150),
    [anon_sym_DQUOTE] = ACTIONS(153),
    [sym_triple_single_quote_string] = ACTIONS(156),
    [sym_triple_double_quote_string] = ACTIONS(156),
    [sym_number] = ACTIONS(159),
    [sym_date] = ACTIONS(162),
    [anon_sym_true] = ACTIONS(165),
    [anon_sym_TRUE] = ACTIONS(165),
    [anon_sym_True] = ACTIONS(165),
    [anon_sym_false] = ACTIONS(165),
    [anon_sym_FALSE] = ACTIONS(165),
    [anon_sym_False] = ACTIONS(165),
    [anon_sym_yes] = ACTIONS(165),
    [anon_sym_YES] = ACTIONS(165),
    [anon_sym_Yes] = ACTIONS(165),
    [anon_sym_no] = ACTIONS(165),
    [anon_sym_NO] = ACTIONS(165),
    [anon_sym_No] = ACTIONS(165),
    [anon_sym_null] = ACTIONS(168),
    [anon_sym_NULL] = ACTIONS(168),
    [anon_sym_Null] = ACTIONS(168),
    [sym_unquoted_string] = ACTIONS(171),
    [sym_comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(174),
    [sym__newline] = ACTIONS(174),
  },
  [12] = {
    [sym_block_mapping_pair] = STATE(35),
    [sym__value] = STATE(35),
    [sym_inline_sequence] = STATE(35),
    [sym_inline_mapping] = STATE(35),
    [sym_entity_chain] = STATE(35),
    [sym_entity] = STATE(17),
    [sym__key] = STATE(41),
    [sym_double_quote_string] = STATE(22),
    [sym_multiline_string] = STATE(35),
    [sym_boolean] = STATE(22),
    [sym_null] = STATE(22),
    [ts_builtin_sym_end] = ACTIONS(177),
    [anon_sym_DASH] = ACTIONS(179),
    [anon_sym_LBRACK] = ACTIONS(9),
    [anon_sym_LBRACE] = ACTIONS(11),
    [sym_single_quote_string] = ACTIONS(13),
    [anon_sym_DQUOTE] = ACTIONS(15),
    [sym_triple_single_quote_string] = ACTIONS(17),
    [sym_triple_double_quote_string] = ACTIONS(17),
    [sym_number] = ACTIONS(19),
    [sym_date] = ACTIONS(181),
    [anon_sym_true] = ACTIONS(23),
    [anon_sym_TRUE] = ACTIONS(23),
    [anon_sym_True] = ACTIONS(23),
    [anon_sym_false] = ACTIONS(23),
    [anon_sym_FALSE] = ACTIONS(23),
    [anon_sym_False] = ACTIONS(23),
    [anon_sym_yes] = ACTIONS(23),
    [anon_sym_YES] = ACTIONS(23),
    [anon_sym_Yes] = ACTIONS(23),
    [anon_sym_no] = ACTIONS(23),
    [anon_sym_NO] = ACTIONS(23),
    [anon_sym_No] = ACTIONS(23),
    [anon_sym_null] = ACTIONS(25),
    [anon_sym_NULL] = ACTIONS(25),
    [anon_sym_Null] = ACTIONS(25),
    [sym_unquoted_string] = ACTIONS(27),
    [sym_comment] = ACTIONS(3),
    [sym__newline] = ACTIONS(177),
  },
  [13] = {
    [sym__value] = STATE(34),
    [sym_inline_sequence] = STATE(34),
    [sym_inline_mapping] = STATE(34),
    [sym_entity_chain] = STATE(34),
    [sym_entity] = STATE(17),
    [sym_double_quote_string] = STATE(34),
    [sym_multiline_string] = STATE(34),
    [sym_boolean] = STATE(34),
    [sym_null] = STATE(34),
    [anon_sym_LBRACK] = ACTIONS(9),
    [anon_sym_RBRACK] = ACTIONS(183),
    [anon_sym_LBRACE] = ACTIONS(11),
    [anon_sym_RBRACE] = ACTIONS(183),
    [sym_single_quote_string] = ACTIONS(185),
    [anon_sym_DQUOTE] = ACTIONS(15),
    [sym_triple_single_quote_string] = ACTIONS(17),
    [sym_triple_double_quote_string] = ACTIONS(17),
    [sym_number] = ACTIONS(187),
    [sym_date] = ACTIONS(187),
    [anon_sym_true] = ACTIONS(23),
    [anon_sym_TRUE] = ACTIONS(23),
    [anon_sym_True] = ACTIONS(23),
    [anon_sym_false] = ACTIONS(23),
    [anon_sym_FALSE] = ACTIONS(23),
    [anon_sym_False] = ACTIONS(23),
    [anon_sym_yes] = ACTIONS(23),
    [anon_sym_YES] = ACTIONS(23),
    [anon_sym_Yes] = ACTIONS(23),
    [anon_sym_no] = ACTIONS(23),
    [anon_sym_NO] = ACTIONS(23),
    [anon_sym_No] = ACTIONS(23),
    [anon_sym_null] = ACTIONS(25),
    [anon_sym_NULL] = ACTIONS(25),
    [anon_sym_Null] = ACTIONS(25),
    [sym_unquoted_string] = ACTIONS(189),
    [sym_comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(183),
    [sym__newline] = ACTIONS(183),
  },
  [14] = {
    [sym__value] = STATE(36),
    [sym_inline_sequence] = STATE(36),
    [sym_inline_mapping] = STATE(36),
    [sym_entity_chain] = STATE(36),
    [sym_entity] = STATE(17),
    [sym_double_quote_string] = STATE(36),
    [sym_multiline_string] = STATE(36),
    [sym_boolean] = STATE(36),
    [sym_null] = STATE(36),
    [ts_builtin_sym_end] = ACTIONS(191),
    [anon_sym_DASH] = ACTIONS(193),
    [anon_sym_LBRACK] = ACTIONS(9),
    [anon_sym_LBRACE] = ACTIONS(11),
    [sym_single_quote_string] = ACTIONS(195),
    [anon_sym_DQUOTE] = ACTIONS(15),
    [sym_triple_single_quote_string] = ACTIONS(17),
    [sym_triple_double_quote_string] = ACTIONS(17),
    [sym_number] = ACTIONS(197),
    [sym_date] = ACTIONS(197),
    [anon_sym_true] = ACTIONS(23),
    [anon_sym_TRUE] = ACTIONS(23),
    [anon_sym_True] = ACTIONS(23),
    [anon_sym_false] = ACTIONS(23),
    [anon_sym_FALSE] = ACTIONS(23),
    [anon_sym_False] = ACTIONS(23),
    [anon_sym_yes] = ACTIONS(23),
    [anon_sym_YES] = ACTIONS(23),
    [anon_sym_Yes] = ACTIONS(23),
    [anon_sym_no] = ACTIONS(23),
    [anon_sym_NO] = ACTIONS(23),
    [anon_sym_No] = ACTIONS(23),
    [anon_sym_null] = ACTIONS(25),
    [anon_sym_NULL] = ACTIONS(25),
    [anon_sym_Null] = ACTIONS(25),
    [sym_unquoted_string] = ACTIONS(189),
    [sym_comment] = ACTIONS(3),
    [sym__newline] = ACTIONS(191),
  },
  [15] = {
    [sym__value] = STATE(37),
    [sym_inline_sequence] = STATE(37),
    [sym_inline_mapping] = STATE(37),
    [sym_entity_chain] = STATE(37),
    [sym_entity] = STATE(17),
    [sym_double_quote_string] = STATE(37),
    [sym_multiline_string] = STATE(37),
    [sym_boolean] = STATE(37),
    [sym_null] = STATE(37),
    [anon_sym_LBRACK] = ACTIONS(9),
    [anon_sym_LBRACE] = ACTIONS(11),
    [anon_sym_RPAREN] = ACTIONS(199),
    [sym_single_quote_string] = ACTIONS(201),
    [anon_sym_DQUOTE] = ACTIONS(15),
    [sym_triple_single_quote_string] = ACTIONS(17),
    [sym_triple_double_quote_string] = ACTIONS(17),
    [sym_number] = ACTIONS(203),
    [sym_date] = ACTIONS(203),
    [anon_sym_true] = ACTIONS(23),
    [anon_sym_TRUE] = ACTIONS(23),
    [anon_sym_True] = ACTIONS(23),
    [anon_sym_false] = ACTIONS(23),
    [anon_sym_FALSE] = ACTIONS(23),
    [anon_sym_False] = ACTIONS(23),
    [anon_sym_yes] = ACTIONS(23),
    [anon_sym_YES] = ACTIONS(23),
    [anon_sym_Yes] = ACTIONS(23),
    [anon_sym_no] = ACTIONS(23),
    [anon_sym_NO] = ACTIONS(23),
    [anon_sym_No] = ACTIONS(23),
    [anon_sym_null] = ACTIONS(25),
    [anon_sym_NULL] = ACTIONS(25),
    [anon_sym_Null] = ACTIONS(25),
    [sym_unquoted_string] = ACTIONS(189),
    [sym_comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(199),
    [sym__newline] = ACTIONS(199),
  },
  [16] = {
    [ts_builtin_sym_end] = ACTIONS(205),
    [anon_sym_DASH] = ACTIONS(207),
    [anon_sym_COLON] = ACTIONS(209),
    [anon_sym_EQ] = ACTIONS(211),
    [anon_sym_LBRACK] = ACTIONS(205),
    [anon_sym_RBRACK] = ACTIONS(205),
    [anon_sym_LBRACE] = ACTIONS(205),
    [anon_sym_RBRACE] = ACTIONS(205),
    [anon_sym_LPAREN] = ACTIONS(213),
    [anon_sym_RPAREN] = ACTIONS(205),
    [sym_single_quote_string] = ACTIONS(205),
    [anon_sym_DQUOTE] = ACTIONS(207),
    [sym_triple_single_quote_string] = ACTIONS(205),
    [sym_triple_double_quote_string] = ACTIONS(205),
    [sym_number] = ACTIONS(207),
    [sym_date] = ACTIONS(207),
    [anon_sym_true] = ACTIONS(207),
    [anon_sym_TRUE] = ACTIONS(207),
    [anon_sym_True] = ACTIONS(207),
    [anon_sym_false] = ACTIONS(207),
    [anon_sym_FALSE] = ACTIONS(207),
    [anon_sym_False] = ACTIONS(207),
    [anon_sym_yes] = ACTIONS(207),
    [anon_sym_YES] = ACTIONS(207),
    [anon_sym_Yes] = ACTIONS(207),
    [anon_sym_no] = ACTIONS(207),
    [anon_sym_NO] = ACTIONS(207),
    [anon_sym_No] = ACTIONS(207),
    [anon_sym_null] = ACTIONS(207),
    [anon_sym_NULL] = ACTIONS(207),
    [anon_sym_Null] = ACTIONS(207),
    [sym_unquoted_string] = ACTIONS(207),
    [sym_comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(205),
    [sym__newline] = ACTIONS(205),
  },
  [17] = {
    [sym_entity] = STATE(21),
    [aux_sym_entity_chain_repeat1] = STATE(21),
    [ts_builtin_sym_end] = ACTIONS(205),
    [anon_sym_DASH] = ACTIONS(207),
    [anon_sym_LBRACK] = ACTIONS(205),
    [anon_sym_RBRACK] = ACTIONS(205),
    [anon_sym_LBRACE] = ACTIONS(205),
    [anon_sym_RBRACE] = ACTIONS(205),
    [anon_sym_RPAREN] = ACTIONS(205),
    [sym_single_quote_string] = ACTIONS(205),
    [anon_sym_DQUOTE] = ACTIONS(207),
    [sym_triple_single_quote_string] = ACTIONS(205),
    [sym_triple_double_quote_string] = ACTIONS(205),
    [sym_number] = ACTIONS(207),
    [sym_date] = ACTIONS(207),
    [anon_sym_true] = ACTIONS(207),
    [anon_sym_TRUE] = ACTIONS(207),
    [anon_sym_True] = ACTIONS(207),
    [anon_sym_false] = ACTIONS(207),
    [anon_sym_FALSE] = ACTIONS(207),
    [anon_sym_False] = ACTIONS(207),
    [anon_sym_yes] = ACTIONS(207),
    [anon_sym_YES] = ACTIONS(207),
    [anon_sym_Yes] = ACTIONS(207),
    [anon_sym_no] = ACTIONS(207),
    [anon_sym_NO] = ACTIONS(207),
    [anon_sym_No] = ACTIONS(207),
    [anon_sym_null] = ACTIONS(207),
    [anon_sym_NULL] = ACTIONS(207),
    [anon_sym_Null] = ACTIONS(207),
    [sym_unquoted_string] = ACTIONS(215),
    [sym_comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(205),
    [sym__newline] = ACTIONS(205),
  },
  [18] = {
    [ts_builtin_sym_end] = ACTIONS(217),
    [anon_sym_DASH] = ACTIONS(219),
    [anon_sym_COLON] = ACTIONS(219),
    [anon_sym_EQ] = ACTIONS(217),
    [anon_sym_LBRACK] = ACTIONS(217),
    [anon_sym_RBRACK] = ACTIONS(217),
    [anon_sym_LBRACE] = ACTIONS(217),
    [anon_sym_RBRACE] = ACTIONS(217),
    [anon_sym_RPAREN] = ACTIONS(217),
    [sym_single_quote_string] = ACTIONS(217),
    [anon_sym_DQUOTE] = ACTIONS(219),
    [sym_triple_single_quote_string] = ACTIONS(217),
    [sym_triple_double_quote_string] = ACTIONS(217),
    [sym_number] = ACTIONS(219),
    [sym_date] = ACTIONS(219),
    [anon_sym_true] = ACTIONS(219),
    [anon_sym_TRUE] = ACTIONS(219),
    [anon_sym_True] = ACTIONS(219),
    [anon_sym_false] = ACTIONS(219),
    [anon_sym_FALSE] = ACTIONS(219),
    [anon_sym_False] = ACTIONS(219),
    [anon_sym_yes] = ACTIONS(219),
    [anon_sym_YES] = ACTIONS(219),
    [anon_sym_Yes] = ACTIONS(219),
    [anon_sym_no] = ACTIONS(219),
    [anon_sym_NO] = ACTIONS(219),
    [anon_sym_No] = ACTIONS(219),
    [anon_sym_null] = ACTIONS(219),
    [anon_sym_NULL] = ACTIONS(219),
    [anon_sym_Null] = ACTIONS(219),
    [sym_unquoted_string] = ACTIONS(219),
    [sym_comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(217),
    [sym__newline] = ACTIONS(217),
  },
  [19] = {
    [ts_builtin_sym_end] = ACTIONS(221),
    [anon_sym_DASH] = ACTIONS(223),
    [anon_sym_COLON] = ACTIONS(223),
    [anon_sym_EQ] = ACTIONS(221),
    [anon_sym_LBRACK] = ACTIONS(221),
    [anon_sym_RBRACK] = ACTIONS(221),
    [anon_sym_LBRACE] = ACTIONS(221),
    [anon_sym_RBRACE] = ACTIONS(221),
    [anon_sym_RPAREN] = ACTIONS(221),
    [sym_single_quote_string] = ACTIONS(221),
    [anon_sym_DQUOTE] = ACTIONS(223),
    [sym_triple_single_quote_string] = ACTIONS(221),
    [sym_triple_double_quote_string] = ACTIONS(221),
    [sym_number] = ACTIONS(223),
    [sym_date] = ACTIONS(223),
    [anon_sym_true] = ACTIONS(223),
    [anon_sym_TRUE] = ACTIONS(223),
    [anon_sym_True] = ACTIONS(223),
    [anon_sym_false] = ACTIONS(223),
    [anon_sym_FALSE] = ACTIONS(223),
    [anon_sym_False] = ACTIONS(223),
    [anon_sym_yes] = ACTIONS(223),
    [anon_sym_YES] = ACTIONS(223),
    [anon_sym_Yes] = ACTIONS(223),
    [anon_sym_no] = ACTIONS(223),
    [anon_sym_NO] = ACTIONS(223),
    [anon_sym_No] = ACTIONS(223),
    [anon_sym_null] = ACTIONS(223),
    [anon_sym_NULL] = ACTIONS(223),
    [anon_sym_Null] = ACTIONS(223),
    [sym_unquoted_string] = ACTIONS(223),
    [sym_comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(221),
    [sym__newline] = ACTIONS(221),
  },
  [20] = {
    [ts_builtin_sym_end] = ACTIONS(225),
    [anon_sym_DASH] = ACTIONS(227),
    [anon_sym_COLON] = ACTIONS(227),
    [anon_sym_EQ] = ACTIONS(225),
    [anon_sym_LBRACK] = ACTIONS(225),
    [anon_sym_RBRACK] = ACTIONS(225),
    [anon_sym_LBRACE] = ACTIONS(225),
    [anon_sym_RBRACE] = ACTIONS(225),
    [anon_sym_RPAREN] = ACTIONS(225),
    [sym_single_quote_string] = ACTIONS(225),
    [anon_sym_DQUOTE] = ACTIONS(227),
    [sym_triple_single_quote_string] = ACTIONS(225),
    [sym_triple_double_quote_string] = ACTIONS(225),
    [sym_number] = ACTIONS(227),
    [sym_date] = ACTIONS(227),
    [anon_sym_true] = ACTIONS(227),
    [anon_sym_TRUE] = ACTIONS(227),
    [anon_sym_True] = ACTIONS(227),
    [anon_sym_false] = ACTIONS(227),
    [anon_sym_FALSE] = ACTIONS(227),
    [anon_sym_False] = ACTIONS(227),
    [anon_sym_yes] = ACTIONS(227),
    [anon_sym_YES] = ACTIONS(227),
    [anon_sym_Yes] = ACTIONS(227),
    [anon_sym_no] = ACTIONS(227),
    [anon_sym_NO] = ACTIONS(227),
    [anon_sym_No] = ACTIONS(227),
    [anon_sym_null] = ACTIONS(227),
    [anon_sym_NULL] = ACTIONS(227),
    [anon_sym_Null] = ACTIONS(227),
    [sym_unquoted_string] = ACTIONS(227),
    [sym_comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(225),
    [sym__newline] = ACTIONS(225),
  },
  [21] = {
    [sym_entity] = STATE(24),
    [aux_sym_entity_chain_repeat1] = STATE(24),
    [ts_builtin_sym_end] = ACTIONS(229),
    [anon_sym_DASH] = ACTIONS(231),
    [anon_sym_LBRACK] = ACTIONS(229),
    [anon_sym_RBRACK] = ACTIONS(229),
    [anon_sym_LBRACE] = ACTIONS(229),
    [anon_sym_RBRACE] = ACTIONS(229),
    [anon_sym_RPAREN] = ACTIONS(229),
    [sym_single_quote_string] = ACTIONS(229),
    [anon_sym_DQUOTE] = ACTIONS(231),
    [sym_triple_single_quote_string] = ACTIONS(229),
    [sym_triple_double_quote_string] = ACTIONS(229),
    [sym_number] = ACTIONS(231),
    [sym_date] = ACTIONS(231),
    [anon_sym_true] = ACTIONS(231),
    [anon_sym_TRUE] = ACTIONS(231),
    [anon_sym_True] = ACTIONS(231),
    [anon_sym_false] = ACTIONS(231),
    [anon_sym_FALSE] = ACTIONS(231),
    [anon_sym_False] = ACTIONS(231),
    [anon_sym_yes] = ACTIONS(231),
    [anon_sym_YES] = ACTIONS(231),
    [anon_sym_Yes] = ACTIONS(231),
    [anon_sym_no] = ACTIONS(231),
    [anon_sym_NO] = ACTIONS(231),
    [anon_sym_No] = ACTIONS(231),
    [anon_sym_null] = ACTIONS(231),
    [anon_sym_NULL] = ACTIONS(231),
    [anon_sym_Null] = ACTIONS(231),
    [sym_unquoted_string] = ACTIONS(231),
    [sym_comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(229),
    [sym__newline] = ACTIONS(229),
  },
  [22] = {
    [ts_builtin_sym_end] = ACTIONS(205),
    [anon_sym_DASH] = ACTIONS(207),
    [anon_sym_COLON] = ACTIONS(233),
    [anon_sym_EQ] = ACTIONS(235),
    [anon_sym_LBRACK] = ACTIONS(205),
    [anon_sym_RBRACK] = ACTIONS(205),
    [anon_sym_LBRACE] = ACTIONS(205),
    [anon_sym_RBRACE] = ACTIONS(205),
    [anon_sym_RPAREN] = ACTIONS(205),
    [sym_single_quote_string] = ACTIONS(205),
    [anon_sym_DQUOTE] = ACTIONS(207),
    [sym_triple_single_quote_string] = ACTIONS(205),
    [sym_triple_double_quote_string] = ACTIONS(205),
    [sym_number] = ACTIONS(207),
    [sym_date] = ACTIONS(207),
    [anon_sym_true] = ACTIONS(207),
    [anon_sym_TRUE] = ACTIONS(207),
    [anon_sym_True] = ACTIONS(207),
    [anon_sym_false] = ACTIONS(207),
    [anon_sym_FALSE] = ACTIONS(207),
    [anon_sym_False] = ACTIONS(207),
    [anon_sym_yes] = ACTIONS(207),
    [anon_sym_YES] = ACTIONS(207),
    [anon_sym_Yes] = ACTIONS(207),
    [anon_sym_no] = ACTIONS(207),
    [anon_sym_NO] = ACTIONS(207),
    [anon_sym_No] = ACTIONS(207),
    [anon_sym_null] = ACTIONS(207),
    [anon_sym_NULL] = ACTIONS(207),
    [anon_sym_Null] = ACTIONS(207),
    [sym_unquoted_string] = ACTIONS(207),
    [sym_comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(205),
    [sym__newline] = ACTIONS(205),
  },
  [23] = {
    [ts_builtin_sym_end] = ACTIONS(237),
    [anon_sym_DASH] = ACTIONS(239),
    [anon_sym_COLON] = ACTIONS(239),
    [anon_sym_EQ] = ACTIONS(237),
    [anon_sym_LBRACK] = ACTIONS(237),
    [anon_sym_RBRACK] = ACTIONS(237),
    [anon_sym_LBRACE] = ACTIONS(237),
    [anon_sym_RBRACE] = ACTIONS(237),
    [anon_sym_RPAREN] = ACTIONS(237),
    [sym_single_quote_string] = ACTIONS(237),
    [anon_sym_DQUOTE] = ACTIONS(239),
    [sym_triple_single_quote_string] = ACTIONS(237),
    [sym_triple_double_quote_string] = ACTIONS(237),
    [sym_number] = ACTIONS(239),
    [sym_date] = ACTIONS(239),
    [anon_sym_true] = ACTIONS(239),
    [anon_sym_TRUE] = ACTIONS(239),
    [anon_sym_True] = ACTIONS(239),
    [anon_sym_false] = ACTIONS(239),
    [anon_sym_FALSE] = ACTIONS(239),
    [anon_sym_False] = ACTIONS(239),
    [anon_sym_yes] = ACTIONS(239),
    [anon_sym_YES] = ACTIONS(239),
    [anon_sym_Yes] = ACTIONS(239),
    [anon_sym_no] = ACTIONS(239),
    [anon_sym_NO] = ACTIONS(239),
    [anon_sym_No] = ACTIONS(239),
    [anon_sym_null] = ACTIONS(239),
    [anon_sym_NULL] = ACTIONS(239),
    [anon_sym_Null] = ACTIONS(239),
    [sym_unquoted_string] = ACTIONS(239),
    [sym_comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(237),
    [sym__newline] = ACTIONS(237),
  },
  [24] = {
    [sym_entity] = STATE(24),
    [aux_sym_entity_chain_repeat1] = STATE(24),
    [ts_builtin_sym_end] = ACTIONS(241),
    [anon_sym_DASH] = ACTIONS(243),
    [anon_sym_LBRACK] = ACTIONS(241),
    [anon_sym_RBRACK] = ACTIONS(241),
    [anon_sym_LBRACE] = ACTIONS(241),
    [anon_sym_RBRACE] = ACTIONS(241),
    [anon_sym_RPAREN] = ACTIONS(241),
    [sym_single_quote_string] = ACTIONS(241),
    [anon_sym_DQUOTE] = ACTIONS(243),
    [sym_triple_single_quote_string] = ACTIONS(241),
    [sym_triple_double_quote_string] = ACTIONS(241),
    [sym_number] = ACTIONS(243),
    [sym_date] = ACTIONS(243),
    [anon_sym_true] = ACTIONS(243),
    [anon_sym_TRUE] = ACTIONS(243),
    [anon_sym_True] = ACTIONS(243),
    [anon_sym_false] = ACTIONS(243),
    [anon_sym_FALSE] = ACTIONS(243),
    [anon_sym_False] = ACTIONS(243),
    [anon_sym_yes] = ACTIONS(243),
    [anon_sym_YES] = ACTIONS(243),
    [anon_sym_Yes] = ACTIONS(243),
    [anon_sym_no] = ACTIONS(243),
    [anon_sym_NO] = ACTIONS(243),
    [anon_sym_No] = ACTIONS(243),
    [anon_sym_null] = ACTIONS(243),
    [anon_sym_NULL] = ACTIONS(243),
    [anon_sym_Null] = ACTIONS(243),
    [sym_unquoted_string] = ACTIONS(245),
    [sym_comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(241),
    [sym__newline] = ACTIONS(241),
  },
  [25] = {
    [ts_builtin_sym_end] = ACTIONS(248),
    [anon_sym_DASH] = ACTIONS(250),
    [anon_sym_LBRACK] = ACTIONS(248),
    [anon_sym_RBRACK] = ACTIONS(248),
    [anon_sym_LBRACE] = ACTIONS(248),
    [anon_sym_RBRACE] = ACTIONS(248),
    [anon_sym_LPAREN] = ACTIONS(213),
    [anon_sym_RPAREN] = ACTIONS(248),
    [sym_single_quote_string] = ACTIONS(248),
    [anon_sym_DQUOTE] = ACTIONS(250),
    [sym_triple_single_quote_string] = ACTIONS(248),
    [sym_triple_double_quote_string] = ACTIONS(248),
    [sym_number] = ACTIONS(250),
    [sym_date] = ACTIONS(250),
    [anon_sym_true] = ACTIONS(250),
    [anon_sym_TRUE] = ACTIONS(250),
    [anon_sym_True] = ACTIONS(250),
    [anon_sym_false] = ACTIONS(250),
    [anon_sym_FALSE] = ACTIONS(250),
    [anon_sym_False] = ACTIONS(250),
    [anon_sym_yes] = ACTIONS(250),
    [anon_sym_YES] = ACTIONS(250),
    [anon_sym_Yes] = ACTIONS(250),
    [anon_sym_no] = ACTIONS(250),
    [anon_sym_NO] = ACTIONS(250),
    [anon_sym_No] = ACTIONS(250),
    [anon_sym_null] = ACTIONS(250),
    [anon_sym_NULL] = ACTIONS(250),
    [anon_sym_Null] = ACTIONS(250),
    [sym_unquoted_string] = ACTIONS(250),
    [sym_comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(248),
    [sym__newline] = ACTIONS(248),
  },
  [26] = {
    [ts_builtin_sym_end] = ACTIONS(205),
    [anon_sym_DASH] = ACTIONS(207),
    [anon_sym_LBRACK] = ACTIONS(205),
    [anon_sym_RBRACK] = ACTIONS(205),
    [anon_sym_LBRACE] = ACTIONS(205),
    [anon_sym_RBRACE] = ACTIONS(205),
    [anon_sym_LPAREN] = ACTIONS(213),
    [anon_sym_RPAREN] = ACTIONS(205),
    [sym_single_quote_string] = ACTIONS(205),
    [anon_sym_DQUOTE] = ACTIONS(207),
    [sym_triple_single_quote_string] = ACTIONS(205),
    [sym_triple_double_quote_string] = ACTIONS(205),
    [sym_number] = ACTIONS(207),
    [sym_date] = ACTIONS(207),
    [anon_sym_true] = ACTIONS(207),
    [anon_sym_TRUE] = ACTIONS(207),
    [anon_sym_True] = ACTIONS(207),
    [anon_sym_false] = ACTIONS(207),
    [anon_sym_FALSE] = ACTIONS(207),
    [anon_sym_False] = ACTIONS(207),
    [anon_sym_yes] = ACTIONS(207),
    [anon_sym_YES] = ACTIONS(207),
    [anon_sym_Yes] = ACTIONS(207),
    [anon_sym_no] = ACTIONS(207),
    [anon_sym_NO] = ACTIONS(207),
    [anon_sym_No] = ACTIONS(207),
    [anon_sym_null] = ACTIONS(207),
    [anon_sym_NULL] = ACTIONS(207),
    [anon_sym_Null] = ACTIONS(207),
    [sym_unquoted_string] = ACTIONS(207),
    [sym_comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(205),
    [sym__newline] = ACTIONS(205),
  },
  [27] = {
    [ts_builtin_sym_end] = ACTIONS(252),
    [anon_sym_DASH] = ACTIONS(254),
    [anon_sym_LBRACK] = ACTIONS(252),
    [anon_sym_RBRACK] = ACTIONS(252),
    [anon_sym_LBRACE] = ACTIONS(252),
    [anon_sym_RBRACE] = ACTIONS(252),
    [anon_sym_RPAREN] = ACTIONS(252),
    [sym_single_quote_string] = ACTIONS(252),
    [anon_sym_DQUOTE] = ACTIONS(254),
    [sym_triple_single_quote_string] = ACTIONS(252),
    [sym_triple_double_quote_string] = ACTIONS(252),
    [sym_number] = ACTIONS(254),
    [sym_date] = ACTIONS(254),
    [anon_sym_true] = ACTIONS(254),
    [anon_sym_TRUE] = ACTIONS(254),
    [anon_sym_True] = ACTIONS(254),
    [anon_sym_false] = ACTIONS(254),
    [anon_sym_FALSE] = ACTIONS(254),
    [anon_sym_False] = ACTIONS(254),
    [anon_sym_yes] = ACTIONS(254),
    [anon_sym_YES] = ACTIONS(254),
    [anon_sym_Yes] = ACTIONS(254),
    [anon_sym_no] = ACTIONS(254),
    [anon_sym_NO] = ACTIONS(254),
    [anon_sym_No] = ACTIONS(254),
    [anon_sym_null] = ACTIONS(254),
    [anon_sym_NULL] = ACTIONS(254),
    [anon_sym_Null] = ACTIONS(254),
    [sym_unquoted_string] = ACTIONS(254),
    [sym_comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(252),
    [sym__newline] = ACTIONS(252),
  },
  [28] = {
    [ts_builtin_sym_end] = ACTIONS(256),
    [anon_sym_DASH] = ACTIONS(258),
    [anon_sym_LBRACK] = ACTIONS(256),
    [anon_sym_RBRACK] = ACTIONS(256),
    [anon_sym_LBRACE] = ACTIONS(256),
    [anon_sym_RBRACE] = ACTIONS(256),
    [anon_sym_RPAREN] = ACTIONS(256),
    [sym_single_quote_string] = ACTIONS(256),
    [anon_sym_DQUOTE] = ACTIONS(258),
    [sym_triple_single_quote_string] = ACTIONS(256),
    [sym_triple_double_quote_string] = ACTIONS(256),
    [sym_number] = ACTIONS(258),
    [sym_date] = ACTIONS(258),
    [anon_sym_true] = ACTIONS(258),
    [anon_sym_TRUE] = ACTIONS(258),
    [anon_sym_True] = ACTIONS(258),
    [anon_sym_false] = ACTIONS(258),
    [anon_sym_FALSE] = ACTIONS(258),
    [anon_sym_False] = ACTIONS(258),
    [anon_sym_yes] = ACTIONS(258),
    [anon_sym_YES] = ACTIONS(258),
    [anon_sym_Yes] = ACTIONS(258),
    [anon_sym_no] = ACTIONS(258),
    [anon_sym_NO] = ACTIONS(258),
    [anon_sym_No] = ACTIONS(258),
    [anon_sym_null] = ACTIONS(258),
    [anon_sym_NULL] = ACTIONS(258),
    [anon_sym_Null] = ACTIONS(258),
    [sym_unquoted_string] = ACTIONS(258),
    [sym_comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(256),
    [sym__newline] = ACTIONS(256),
  },
  [29] = {
    [ts_builtin_sym_end] = ACTIONS(260),
    [anon_sym_DASH] = ACTIONS(262),
    [anon_sym_LBRACK] = ACTIONS(260),
    [anon_sym_RBRACK] = ACTIONS(260),
    [anon_sym_LBRACE] = ACTIONS(260),
    [anon_sym_RBRACE] = ACTIONS(260),
    [anon_sym_RPAREN] = ACTIONS(260),
    [sym_single_quote_string] = ACTIONS(260),
    [anon_sym_DQUOTE] = ACTIONS(262),
    [sym_triple_single_quote_string] = ACTIONS(260),
    [sym_triple_double_quote_string] = ACTIONS(260),
    [sym_number] = ACTIONS(262),
    [sym_date] = ACTIONS(262),
    [anon_sym_true] = ACTIONS(262),
    [anon_sym_TRUE] = ACTIONS(262),
    [anon_sym_True] = ACTIONS(262),
    [anon_sym_false] = ACTIONS(262),
    [anon_sym_FALSE] = ACTIONS(262),
    [anon_sym_False] = ACTIONS(262),
    [anon_sym_yes] = ACTIONS(262),
    [anon_sym_YES] = ACTIONS(262),
    [anon_sym_Yes] = ACTIONS(262),
    [anon_sym_no] = ACTIONS(262),
    [anon_sym_NO] = ACTIONS(262),
    [anon_sym_No] = ACTIONS(262),
    [anon_sym_null] = ACTIONS(262),
    [anon_sym_NULL] = ACTIONS(262),
    [anon_sym_Null] = ACTIONS(262),
    [sym_unquoted_string] = ACTIONS(262),
    [sym_comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(260),
    [sym__newline] = ACTIONS(260),
  },
  [30] = {
    [ts_builtin_sym_end] = ACTIONS(264),
    [anon_sym_DASH] = ACTIONS(266),
    [anon_sym_LBRACK] = ACTIONS(264),
    [anon_sym_RBRACK] = ACTIONS(264),
    [anon_sym_LBRACE] = ACTIONS(264),
    [anon_sym_RBRACE] = ACTIONS(264),
    [anon_sym_RPAREN] = ACTIONS(264),
    [sym_single_quote_string] = ACTIONS(264),
    [anon_sym_DQUOTE] = ACTIONS(266),
    [sym_triple_single_quote_string] = ACTIONS(264),
    [sym_triple_double_quote_string] = ACTIONS(264),
    [sym_number] = ACTIONS(266),
    [sym_date] = ACTIONS(266),
    [anon_sym_true] = ACTIONS(266),
    [anon_sym_TRUE] = ACTIONS(266),
    [anon_sym_True] = ACTIONS(266),
    [anon_sym_false] = ACTIONS(266),
    [anon_sym_FALSE] = ACTIONS(266),
    [anon_sym_False] = ACTIONS(266),
    [anon_sym_yes] = ACTIONS(266),
    [anon_sym_YES] = ACTIONS(266),
    [anon_sym_Yes] = ACTIONS(266),
    [anon_sym_no] = ACTIONS(266),
    [anon_sym_NO] = ACTIONS(266),
    [anon_sym_No] = ACTIONS(266),
    [anon_sym_null] = ACTIONS(266),
    [anon_sym_NULL] = ACTIONS(266),
    [anon_sym_Null] = ACTIONS(266),
    [sym_unquoted_string] = ACTIONS(266),
    [sym_comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(264),
    [sym__newline] = ACTIONS(264),
  },
  [31] = {
    [ts_builtin_sym_end] = ACTIONS(268),
    [anon_sym_DASH] = ACTIONS(270),
    [anon_sym_LBRACK] = ACTIONS(268),
    [anon_sym_RBRACK] = ACTIONS(268),
    [anon_sym_LBRACE] = ACTIONS(268),
    [anon_sym_RBRACE] = ACTIONS(268),
    [anon_sym_RPAREN] = ACTIONS(268),
    [sym_single_quote_string] = ACTIONS(268),
    [anon_sym_DQUOTE] = ACTIONS(270),
    [sym_triple_single_quote_string] = ACTIONS(268),
    [sym_triple_double_quote_string] = ACTIONS(268),
    [sym_number] = ACTIONS(270),
    [sym_date] = ACTIONS(270),
    [anon_sym_true] = ACTIONS(270),
    [anon_sym_TRUE] = ACTIONS(270),
    [anon_sym_True] = ACTIONS(270),
    [anon_sym_false] = ACTIONS(270),
    [anon_sym_FALSE] = ACTIONS(270),
    [anon_sym_False] = ACTIONS(270),
    [anon_sym_yes] = ACTIONS(270),
    [anon_sym_YES] = ACTIONS(270),
    [anon_sym_Yes] = ACTIONS(270),
    [anon_sym_no] = ACTIONS(270),
    [anon_sym_NO] = ACTIONS(270),
    [anon_sym_No] = ACTIONS(270),
    [anon_sym_null] = ACTIONS(270),
    [anon_sym_NULL] = ACTIONS(270),
    [anon_sym_Null] = ACTIONS(270),
    [sym_unquoted_string] = ACTIONS(270),
    [sym_comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(268),
    [sym__newline] = ACTIONS(268),
  },
  [32] = {
    [ts_builtin_sym_end] = ACTIONS(272),
    [anon_sym_DASH] = ACTIONS(274),
    [anon_sym_LBRACK] = ACTIONS(272),
    [anon_sym_RBRACK] = ACTIONS(272),
    [anon_sym_LBRACE] = ACTIONS(272),
    [anon_sym_RBRACE] = ACTIONS(272),
    [anon_sym_RPAREN] = ACTIONS(272),
    [sym_single_quote_string] = ACTIONS(272),
    [anon_sym_DQUOTE] = ACTIONS(274),
    [sym_triple_single_quote_string] = ACTIONS(272),
    [sym_triple_double_quote_string] = ACTIONS(272),
    [sym_number] = ACTIONS(274),
    [sym_date] = ACTIONS(274),
    [anon_sym_true] = ACTIONS(274),
    [anon_sym_TRUE] = ACTIONS(274),
    [anon_sym_True] = ACTIONS(274),
    [anon_sym_false] = ACTIONS(274),
    [anon_sym_FALSE] = ACTIONS(274),
    [anon_sym_False] = ACTIONS(274),
    [anon_sym_yes] = ACTIONS(274),
    [anon_sym_YES] = ACTIONS(274),
    [anon_sym_Yes] = ACTIONS(274),
    [anon_sym_no] = ACTIONS(274),
    [anon_sym_NO] = ACTIONS(274),
    [anon_sym_No] = ACTIONS(274),
    [anon_sym_null] = ACTIONS(274),
    [anon_sym_NULL] = ACTIONS(274),
    [anon_sym_Null] = ACTIONS(274),
    [sym_unquoted_string] = ACTIONS(274),
    [sym_comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(272),
    [sym__newline] = ACTIONS(272),
  },
  [33] = {
    [ts_builtin_sym_end] = ACTIONS(276),
    [anon_sym_DASH] = ACTIONS(278),
    [anon_sym_LBRACK] = ACTIONS(276),
    [anon_sym_RBRACK] = ACTIONS(276),
    [anon_sym_LBRACE] = ACTIONS(276),
    [anon_sym_RBRACE] = ACTIONS(276),
    [anon_sym_RPAREN] = ACTIONS(276),
    [sym_single_quote_string] = ACTIONS(276),
    [anon_sym_DQUOTE] = ACTIONS(278),
    [sym_triple_single_quote_string] = ACTIONS(276),
    [sym_triple_double_quote_string] = ACTIONS(276),
    [sym_number] = ACTIONS(278),
    [sym_date] = ACTIONS(278),
    [anon_sym_true] = ACTIONS(278),
    [anon_sym_TRUE] = ACTIONS(278),
    [anon_sym_True] = ACTIONS(278),
    [anon_sym_false] = ACTIONS(278),
    [anon_sym_FALSE] = ACTIONS(278),
    [anon_sym_False] = ACTIONS(278),
    [anon_sym_yes] = ACTIONS(278),
    [anon_sym_YES] = ACTIONS(278),
    [anon_sym_Yes] = ACTIONS(278),
    [anon_sym_no] = ACTIONS(278),
    [anon_sym_NO] = ACTIONS(278),
    [anon_sym_No] = ACTIONS(278),
    [anon_sym_null] = ACTIONS(278),
    [anon_sym_NULL] = ACTIONS(278),
    [anon_sym_Null] = ACTIONS(278),
    [sym_unquoted_string] = ACTIONS(278),
    [sym_comment] = ACTIONS(3),
    [anon_sym_COMMA] = ACTIONS(276),
    [sym__newline] = ACTIONS(276),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(280), 9,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_single_quote_string,
      sym_triple_single_quote_string,
      sym_triple_double_quote_string,
      anon_sym_COMMA,
      sym__newline,
    ACTIONS(282), 19,
      anon_sym_DQUOTE,
      sym_number,
      sym_date,
      anon_sym_true,
      anon_sym_TRUE,
      anon_sym_True,
      anon_sym_false,
      anon_sym_FALSE,
      anon_sym_False,
      anon_sym_yes,
      anon_sym_YES,
      anon_sym_Yes,
      anon_sym_no,
      anon_sym_NO,
      anon_sym_No,
      anon_sym_null,
      anon_sym_NULL,
      anon_sym_Null,
      sym_unquoted_string,
  [36] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(284), 7,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
      sym_single_quote_string,
      sym_triple_single_quote_string,
      sym_triple_double_quote_string,
      sym__newline,
    ACTIONS(286), 20,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      sym_number,
      sym_date,
      anon_sym_true,
      anon_sym_TRUE,
      anon_sym_True,
      anon_sym_false,
      anon_sym_FALSE,
      anon_sym_False,
      anon_sym_yes,
      anon_sym_YES,
      anon_sym_Yes,
      anon_sym_no,
      anon_sym_NO,
      anon_sym_No,
      anon_sym_null,
      anon_sym_NULL,
      anon_sym_Null,
      sym_unquoted_string,
  [71] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(288), 7,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
      sym_single_quote_string,
      sym_triple_single_quote_string,
      sym_triple_double_quote_string,
      sym__newline,
    ACTIONS(290), 20,
      anon_sym_DASH,
      anon_sym_DQUOTE,
      sym_number,
      sym_date,
      anon_sym_true,
      anon_sym_TRUE,
      anon_sym_True,
      anon_sym_false,
      anon_sym_FALSE,
      anon_sym_False,
      anon_sym_yes,
      anon_sym_YES,
      anon_sym_Yes,
      anon_sym_no,
      anon_sym_NO,
      anon_sym_No,
      anon_sym_null,
      anon_sym_NULL,
      anon_sym_Null,
      sym_unquoted_string,
  [106] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(292), 8,
      anon_sym_LBRACK,
      anon_sym_LBRACE,
      anon_sym_RPAREN,
      sym_single_quote_string,
      sym_triple_single_quote_string,
      sym_triple_double_quote_string,
      anon_sym_COMMA,
      sym__newline,
    ACTIONS(294), 19,
      anon_sym_DQUOTE,
      sym_number,
      sym_date,
      anon_sym_true,
      anon_sym_TRUE,
      anon_sym_True,
      anon_sym_false,
      anon_sym_FALSE,
      anon_sym_False,
      anon_sym_yes,
      anon_sym_YES,
      anon_sym_Yes,
      anon_sym_no,
      anon_sym_NO,
      anon_sym_No,
      anon_sym_null,
      anon_sym_NULL,
      anon_sym_Null,
      sym_unquoted_string,
  [141] = 5,
    ACTIONS(296), 1,
      anon_sym_DQUOTE,
    ACTIONS(298), 1,
      aux_sym_double_quote_string_token1,
    ACTIONS(300), 1,
      sym_escape_sequence,
    ACTIONS(302), 1,
      sym_comment,
    STATE(39), 1,
      aux_sym_double_quote_string_repeat1,
  [157] = 5,
    ACTIONS(302), 1,
      sym_comment,
    ACTIONS(304), 1,
      anon_sym_DQUOTE,
    ACTIONS(306), 1,
      aux_sym_double_quote_string_token1,
    ACTIONS(309), 1,
      sym_escape_sequence,
    STATE(39), 1,
      aux_sym_double_quote_string_repeat1,
  [173] = 5,
    ACTIONS(302), 1,
      sym_comment,
    ACTIONS(312), 1,
      anon_sym_DQUOTE,
    ACTIONS(314), 1,
      aux_sym_double_quote_string_token1,
    ACTIONS(316), 1,
      sym_escape_sequence,
    STATE(38), 1,
      aux_sym_double_quote_string_repeat1,
  [189] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(318), 2,
      anon_sym_COLON,
      anon_sym_EQ,
  [197] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(320), 2,
      anon_sym_COLON,
      anon_sym_EQ,
  [205] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(322), 2,
      anon_sym_COLON,
      anon_sym_EQ,
  [213] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(324), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(34)] = 0,
  [SMALL_STATE(35)] = 36,
  [SMALL_STATE(36)] = 71,
  [SMALL_STATE(37)] = 106,
  [SMALL_STATE(38)] = 141,
  [SMALL_STATE(39)] = 157,
  [SMALL_STATE(40)] = 173,
  [SMALL_STATE(41)] = 189,
  [SMALL_STATE(42)] = 197,
  [SMALL_STATE(43)] = 205,
  [SMALL_STATE(44)] = 213,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [39] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(12),
  [42] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(7),
  [45] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(9),
  [48] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(22),
  [51] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(40),
  [54] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(28),
  [57] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(22),
  [60] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [63] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(19),
  [66] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(18),
  [69] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(16),
  [72] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [75] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_inline_sequence_repeat1, 2, 0, 0), SHIFT_REPEAT(7),
  [78] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_inline_sequence_repeat1, 2, 0, 0),
  [80] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_inline_sequence_repeat1, 2, 0, 0), SHIFT_REPEAT(9),
  [83] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_inline_sequence_repeat1, 2, 0, 0), SHIFT_REPEAT(22),
  [86] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_inline_sequence_repeat1, 2, 0, 0), SHIFT_REPEAT(40),
  [89] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_inline_sequence_repeat1, 2, 0, 0), SHIFT_REPEAT(28),
  [92] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_inline_sequence_repeat1, 2, 0, 0), SHIFT_REPEAT(22),
  [95] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_inline_sequence_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [98] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_inline_sequence_repeat1, 2, 0, 0), SHIFT_REPEAT(19),
  [101] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_inline_sequence_repeat1, 2, 0, 0), SHIFT_REPEAT(18),
  [104] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_inline_sequence_repeat1, 2, 0, 0), SHIFT_REPEAT(16),
  [107] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_inline_sequence_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [110] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [112] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [114] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [116] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [118] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [120] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [122] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [124] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [126] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [128] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [130] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [132] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [134] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [138] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [140] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [142] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_entity_repeat1, 2, 0, 0), SHIFT_REPEAT(7),
  [145] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_entity_repeat1, 2, 0, 0), SHIFT_REPEAT(9),
  [148] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entity_repeat1, 2, 0, 0),
  [150] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_entity_repeat1, 2, 0, 0), SHIFT_REPEAT(22),
  [153] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_entity_repeat1, 2, 0, 0), SHIFT_REPEAT(40),
  [156] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_entity_repeat1, 2, 0, 0), SHIFT_REPEAT(28),
  [159] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_entity_repeat1, 2, 0, 0), SHIFT_REPEAT(22),
  [162] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_entity_repeat1, 2, 0, 0), SHIFT_REPEAT(11),
  [165] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_entity_repeat1, 2, 0, 0), SHIFT_REPEAT(19),
  [168] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_entity_repeat1, 2, 0, 0), SHIFT_REPEAT(18),
  [171] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_entity_repeat1, 2, 0, 0), SHIFT_REPEAT(16),
  [174] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_entity_repeat1, 2, 0, 0), SHIFT_REPEAT(11),
  [177] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_sequence_item, 1, 0, 0),
  [179] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_sequence_item, 1, 0, 0),
  [181] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [183] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inline_mapping_pair, 2, 0, 3),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [187] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [189] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [191] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_mapping_pair, 2, 0, 3),
  [193] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_mapping_pair, 2, 0, 3),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [197] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [199] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_argument, 2, 0, 3),
  [201] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [203] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [205] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__value, 1, 0, 0),
  [207] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__value, 1, 0, 0),
  [209] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__key, 1, 0, 1),
  [211] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__key, 1, 0, 1),
  [213] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [215] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [217] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_null, 1, 0, 0),
  [219] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_null, 1, 0, 0),
  [221] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean, 1, 0, 0),
  [223] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_boolean, 1, 0, 0),
  [225] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_quote_string, 2, 0, 0),
  [227] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_double_quote_string, 2, 0, 0),
  [229] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_chain, 2, 0, 0),
  [231] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_entity_chain, 2, 0, 0),
  [233] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__key, 1, 0, 0),
  [235] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__key, 1, 0, 0),
  [237] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_quote_string, 3, 0, 0),
  [239] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_double_quote_string, 3, 0, 0),
  [241] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entity_chain_repeat1, 2, 0, 0),
  [243] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_entity_chain_repeat1, 2, 0, 0),
  [245] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_entity_chain_repeat1, 2, 0, 0), SHIFT_REPEAT(25),
  [248] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entity_chain_repeat1, 1, 0, 2),
  [250] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_entity_chain_repeat1, 1, 0, 2),
  [252] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inline_mapping, 2, 0, 0),
  [254] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_inline_mapping, 2, 0, 0),
  [256] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_multiline_string, 1, 0, 0),
  [258] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_multiline_string, 1, 0, 0),
  [260] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inline_sequence, 2, 0, 0),
  [262] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_inline_sequence, 2, 0, 0),
  [264] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inline_mapping, 3, 0, 0),
  [266] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_inline_mapping, 3, 0, 0),
  [268] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inline_sequence, 3, 0, 0),
  [270] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_inline_sequence, 3, 0, 0),
  [272] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity, 3, 0, 4),
  [274] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_entity, 3, 0, 4),
  [276] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity, 4, 0, 4),
  [278] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_entity, 4, 0, 4),
  [280] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_inline_mapping_pair, 3, 0, 5),
  [282] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_inline_mapping_pair, 3, 0, 5),
  [284] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_sequence_item, 2, 0, 0),
  [286] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_sequence_item, 2, 0, 0),
  [288] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_mapping_pair, 3, 0, 5),
  [290] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_mapping_pair, 3, 0, 5),
  [292] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entity_argument, 3, 0, 5),
  [294] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_entity_argument, 3, 0, 5),
  [296] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [298] = {.entry = {.count = 1, .reusable = false}}, SHIFT(39),
  [300] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [302] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [304] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_double_quote_string_repeat1, 2, 0, 0),
  [306] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_double_quote_string_repeat1, 2, 0, 0), SHIFT_REPEAT(39),
  [309] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_double_quote_string_repeat1, 2, 0, 0), SHIFT_REPEAT(39),
  [312] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [314] = {.entry = {.count = 1, .reusable = false}}, SHIFT(38),
  [316] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [318] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [320] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [322] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [324] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_neon(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
