#include "levels.h"
#include <stdio.h>

#define LEVEL_FILE "levels.json"

void load_level(int level) {
    FILE *fp;
    struct json_object *parsed_json;
    struct json_object *levels;

}