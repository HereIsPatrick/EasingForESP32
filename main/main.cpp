
#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "EasingLib.h"
#include <string>
#include <vector>

extern "C" void app_main();

typedef struct {
     std::string name;
     Easing e;
 } EASING;

#define DURATION 1000 //ms

void app_main(void)
{
	int values[8] = { 0, 4000, 1000, 3000, 2000, 3000, 1000, 5000 };

	std::vector<EASING> v;
	v.push_back({"in_back",Easing(EASE_IN_BACK,DURATION)});
	v.push_back({"out_back",Easing(EASE_OUT_BACK,DURATION)});
	v.push_back({"in/out_back",Easing(EASE_IN_OUT_BACK,DURATION)});

	while(1)
	{
		char legend[32]="";
		sprintf(legend, "target, %s, %s, %s", v[0].name.c_str(), v[1].name.c_str(), v[2].name.c_str());
		printf("%s\n",legend);

		for(auto i = 0; i < 240; i++)
		{
			auto index = i / 30;
			float newValue = values[index];

			printf("%f", newValue);
			printf(",");
			printf("%f", v[0].e.SetSetpoint(newValue));
			printf(",");
			printf("%f", v[1].e.SetSetpoint(newValue));
			printf(",");
			printf("%f", v[2].e.SetSetpoint(newValue));
			printf("\n");

			vTaskDelay(50 / portTICK_PERIOD_MS);
			//delay(50);
		}
	}
	vTaskDelete(NULL);
}
