#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <cjson/cJSON.h>
#include "API_H.h"
#include "JSON_H.h"

int main() {
  char* city = "Karachi";
  const char* api = "572f7ccfe2c582a830dfddb06e0f2236";
  char* abc;
  abc = response(city,api);
  FILE* wes = fopen("raw_data.json","a");
  if (wes == NULL){
    printf("Error opening file for writing.\n");
    exit(1);
  }
  fprintf(wes,"%s\n",abc);
  system("notify-send 'completed'");
  json(abc,city);
  free(abc);
  return 0;
}

