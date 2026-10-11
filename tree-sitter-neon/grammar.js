const literal = seq(
  choice(
    /[^#\s"'`,:=\[\]{}()-]/,
    seq(/[:-]/, /[^\s"',=\[\]{}()]/),
  ),
  repeat(choice(
    /[^\s,:=\[\]{}()]+/,
    seq(":", /[^\s,=\[\]{}()]/),
    seq(/[ \t]+/, /[^#\s,:=\[\]{}()]/),
  )),
);

module.exports = grammar({
  name: "neon",

  extras: $ => [
    /[ \t\r]+/,
    $.comment,
  ],

  rules: {
    source_file: $ => repeat(choice(
      $._newline,
      $._statement,
    )),

    _statement: $ => choice(
      $.block_sequence_item,
      $.block_mapping_pair,
      $._value,
    ),

    block_sequence_item: $ => prec.right(seq(
      "-",
      optional(choice($.block_mapping_pair, $._value)),
    )),

    block_mapping_pair: $ => prec.right(seq(
      field("key", $._key),
      field("operator", choice(":", "=")),
      optional(field("value", $._value)),
    )),

    _value: $ => choice(
      $.entity_chain,
      $.entity,
      $.inline_sequence,
      $.inline_mapping,
      $.multiline_string,
      $.single_quote_string,
      $.double_quote_string,
      $.number,
      $.date,
      $.boolean,
      $.null,
      $.unquoted_string,
    ),

    inline_sequence: $ => seq(
      "[",
      repeat(choice($._separator, $.inline_mapping_pair, $._value)),
      "]",
    ),

    inline_mapping: $ => seq(
      "{",
      repeat(choice($._separator, $.inline_mapping_pair, $._value)),
      "}",
    ),

    inline_mapping_pair: $ => prec.right(seq(
      field("key", $._key),
      field("operator", choice(":", "=")),
      optional(field("value", $._value)),
    )),

    entity_chain: $ => prec.right(2, seq(
      $.entity,
      repeat1(choice($.entity, alias($.unquoted_string, $.entity_name))),
    )),

    entity: $ => prec(3, seq(
      field("name", alias($.unquoted_string, $.entity_name)),
      "(",
      repeat(choice($._separator, $.entity_argument, $._value)),
      ")",
    )),

    entity_argument: $ => prec.right(seq(
      field("key", $._key),
      field("operator", choice(":", "=")),
      optional(field("value", $._value)),
    )),

    _key: $ => choice(
      $.single_quote_string,
      $.double_quote_string,
      $.number,
      $.boolean,
      $.null,
      alias($.unquoted_string, $.identifier),
    ),

    single_quote_string: _ => token(seq(
      "'",
      repeat(choice(/[^'\n]+/, "''")),
      "'",
    )),

    double_quote_string: $ => seq(
      "\"",
      repeat(choice(
        $.escape_sequence,
        token.immediate(/[^"\\\n]+/),
      )),
      "\"",
    ),

    multiline_string: $ => choice(
      $.triple_single_quote_string,
      $.triple_double_quote_string,
    ),

    triple_single_quote_string: _ => token(seq(
      "'''", /\r?\n/,
      repeat(seq(
        /[ \t]*/,
        optional(choice(
          /[^' \t\n][^\n]*/,
          seq("'", optional(/[^'\n][^\n]*/)),
          seq("''", optional(/[^'\n][^\n]*/)),
        )),
        "\n",
      )),
      /[ \t]*/,
      "'''",
    )),

    triple_double_quote_string: _ => token(seq(
      "\"\"\"", /\r?\n/,
      repeat(seq(
        /[ \t]*/,
        optional(choice(
          /[^" \t\n][^\n]*/,
          seq("\"", optional(/[^"\n][^\n]*/)),
          seq("\"\"", optional(/[^"\n][^\n]*/)),
        )),
        "\n",
      )),
      /[ \t]*/,
      "\"\"\"",
    )),

    escape_sequence: _ => token.immediate(seq(
      "\\",
      choice(
        /["\\\/bfnrt_]/,
        /u[0-9a-fA-F]{4}/,
      ),
    )),

    number: _ => token(/[+-]?(0[bB][01]+|0[oO][0-7]+|0[xX][0-9a-fA-F]+|([0-9]+(\.[0-9]*)?|\.[0-9]+)([eE][+-]?[0-9]+)?)/),

    date: _ => token(/[0-9]{4}-[0-9]{2}-[0-9]{2}([ \t]+[0-9]{2}:[0-9]{2}:[0-9]{2}(\.[0-9]+)?([ \t]+[+-][0-9]{2}:?[0-9]{2})?)?/),

    boolean: _ => choice(
      "true",
      "TRUE",
      "True",
      "false",
      "FALSE",
      "False",
      "yes",
      "YES",
      "Yes",
      "no",
      "NO",
      "No",
    ),

    null: _ => choice("null", "NULL", "Null"),

    unquoted_string: _ => token(literal),

    comment: _ => token(seq("#", /.*/)),
    _separator: $ => choice(",", $._newline),
    _newline: _ => /\n+/,
  },
});
