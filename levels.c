#include "levels.h"
#include <json-c/json.h>
#include <stdio.h>

#define LEVEL_FILE "levels.json"
#define JSON_BUFFER_SIZE 1024

void load_level(int n_level) {
    FILE *fp;
    char buffer[JSON_BUFFER_SIZE];

    size_t n_levels, i;

    struct json_object *parsed_json;
    struct json_object *levels;
    struct json_object *level;
    struct json_object *name;
    struct json_object *id;
    struct json_object *background;
    
    
    fp = fopen(LEVEL_FILE, "r");
    fread(buffer, JSON_BUFFER_SIZE, 1, fp);
    fclose(fp);

    parsed_json = json_tokener_parse(buffer);

    json_object_object_get_ex(parsed_json, "levels", &levels);

    n_levels = json_object_array_length(levels);

    for(i=0;i<n_levels;i++) {
        level = json_object_array_get_idx(levels, i);
        // json_object_get_string(friend)
        json_object_object_get_ex(level, "id", &id);
        json_object_object_get_ex(level, "name", &name);
        json_object_object_get_ex(level, "background", &background);

        printf("%lu. %d, %s, %s\n", 
        i,
        json_object_get_int(id),
        json_object_get_string(name),
        json_object_get_string(background)
        );
    }
}
