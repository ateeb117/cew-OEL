#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cjson/cJSON.h>
#include "JSON_H.h"

void json(char* response,const char* city){
  cJSON *json = cJSON_Parse(response);
  if (json == NULL){
    printf("Error parsing JSON response\n");
    exit(1);
  }
  else{
     cJSON *main12 = cJSON_GetObjectItemCaseSensitive(json, "main");
     if (main12 == NULL){
        printf("Main object not found in the response.\n");
        exit(1);
     }
     cJSON *temp = cJSON_GetObjectItemCaseSensitive(main12, "temp");
     if (temp == NULL) {
        printf("Temperature data not found!\n");
        exit(1);
     }
     printf("%s \nCurrent temperature : %.2f°C\n", city, temp->valuedouble);
     cJSON *feels_like = cJSON_GetObjectItemCaseSensitive(main12,"feels_like");
     if (temp->valuedouble > 30){
         system("notify-send 'High Temperature' '>Be hydrated and try to stay home<' ");
     }
     else if (temp->valuedouble < 5){
         system("notify-send 'Low Temperature' '>Wear warm clothes<' ");
     }
     if (feels_like == NULL){
        printf("feels like data not found!\n");
     }
     printf("feels like : %.2f°C\n",feels_like->valuedouble);
     cJSON *humidity = cJSON_GetObjectItemCaseSensitive(main12,"humidity");
     if (feels_like == NULL){
        printf("humidity data not found!\n");
     }
     printf("Humidity : %d\n",humidity->valueint);
     cJSON_Delete(json);
  }
}
