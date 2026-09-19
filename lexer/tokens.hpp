#pragma once

enum class TokenType {

  // Keywords

  kw_fn,
  kw_output,
  kw_outputln,
  kw_input,

  kw_var,
  kw_const,

  kw_repeat,
  kw_if,
  kw_elseif,
  kw_else,

  kw_for,
  kw_while,
  kw_until,

  kw_return,
  kw_break,
  kw_continue,

  kw_use,

  // Advanced
  kw_struct,
  kw_public,
  kw_private,
  kw_enum,
  kw_class,
  kw_container,
  kw_map,
  kw_set,
  kw_namespace,
  kw_this,

  // Error handling
  kw_try,
  kw_catch,
  kw_throw,

  // Compile-time
  kw_comptime,

  // Low-level
  kw_ptr,
  kw_allocate,
  kw_deallocate,
  kw_NULL,
  kw_allocateRaw,
  kw_freeRaw,
  kw_memcopy,
  kw_memset,

  // Low-level / native
  kw_asm,
  kw_extern,

  // Built-in Types

  t_int,

  t_int8,
  t_int16,
  t_int32,
  t_int64,

  t_uint,

  t_uint8,
  t_uint16,
  t_uint32,
  t_uint64,

  t_float,

  t_float16,
  t_float32,
  t_float64,

  t_char,
  t_string,
  t_bool,
  t_void,

  // Boolean / Null Literals

  literal_true,
  literal_false,
  literal_null,

  // Literals

  literal_integer,
  literal_float,
  literal_char,
  literal_string,

  // Identifiers

  identifier,

  // Arithmetic Operators

  plus,        // +
  minus,       // -
  star,        // *
  slash,       // /
  doubleslash, // //
  modulo,      // %

  doublestar, // **

  // Assignment Operators

  assignment,       // =
  plusequal,        // +=
  minusequal,       // -=
  starequal,        // *=
  slashequal,       // /=
  doubleslashequal, // //=
  moduloequal,      // %=
  doublestarequal,  // **=

  // Increment / Decrement

  doubleplus,  // ++
  doubleminus, // --

  // Comparison Operators

  equal,    // ==
  notequal, // !=

  greater,      // >
  greaterequal, // >=

  less,      // <
  lessequal, // <=

  // Logical Operators

  logical_and,  // &&
  logical_or,   // ||
  logical_xor,  // ^^
  logical_not,  // !
  logical_nand, // !&
  logical_nor,  // !|
  logical_xnor, // !^

  // Bitwise Operators

  bit_and, // &
  bit_or,  // |
  bit_xor, // ^
  bit_not, // ~

  leftshift,  // <<
  rightshift, // >>

  // Bitwise assignment
  bitandequal,     // &=
  bitorequal,      // |=
  bitxorequal,     // ^=
  leftshiftequal,  // <<=
  rightshiftequal, // >>=

  // References / Pointers

  reference, // &

  // Punctuation

  semicolon, // ;
  dot,       // .
  comma,     // ,
  colon,     // :

  lparen, // (
  rparen, // )

  lbrace, // {
  rbrace, // }

  lbrack, // [
  rbrack, // ]

  // Special Tokens

  eof,
  unknown
};
