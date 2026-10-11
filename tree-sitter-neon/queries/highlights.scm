; Zed loads queries from the language directory.
; Keep this file in sync with tree-sitter-neon/queries/highlights.scm.

(comment) @comment

[
  (single_quote_string)
  (double_quote_string)
  (triple_single_quote_string)
  (triple_double_quote_string)
  (unquoted_string)
] @string

(escape_sequence) @string.escape
(number) @number
(boolean) @boolean
(null) @constant.builtin
(date) @constant

(block_mapping_pair
  key: (_) @property)

(inline_mapping_pair
  key: (_) @property)

(entity
  name: (entity_name) @constructor)

(entity_argument
  key: (_) @variable.parameter)

((unquoted_string) @variable.special
  (#match? @variable.special "^@"))

((entity_name) @variable.special
  (#match? @variable.special "^@"))

((unquoted_string) @type
  (#match? @type "^\\\\?[A-Za-z_][A-Za-z0-9_]*\\\\"))

[
  ":"
  "="
] @operator

[
  "-"
  ","
] @punctuation.delimiter

[
  "["
  "]"
  "{"
  "}"
  "("
  ")"
] @punctuation.bracket
