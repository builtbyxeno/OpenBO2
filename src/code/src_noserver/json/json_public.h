#pragma once

#include "types.h"

//t6/code/src_noserver/json/json.cpp
int jsmn_parse_primitive(jsmn_parser *parser, const char *js, jsmntok_t *tokens, unsigned int num_tokens);
int jsmn_parse_string(jsmn_parser *parser, const char *js, jsmntok_t *tokens, unsigned int num_tokens);
int jsmn_parse(jsmn_parser *parser, const char *js, jsmntok_t *tokens, unsigned int num_tokens, int *errorPos);
void jsmn_init(jsmn_parser *parser);
jsmntok_t *JSMN_GetToken();
void JSMN_UnGetToken();
jsmntok_t *JSMN_GetKey(const char *key);
const GfxViewParms *JSMN_GetLocalizedString(const char *loc);
int jsmn_parse(jsmn_parser *parser, const char *js, jsmntok_t *tokens, unsigned int num_tokens);
char JSMN_BeginParseSession(const char *json, jsmntok_t *tokens, int maxTokens);

