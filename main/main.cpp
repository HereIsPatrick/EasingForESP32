
#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "EasingLib.h"

extern "C" void app_main();

void app_main(void)
{
    //printf("Easing Test\n");

	int values[8] = { 0, 1000, 4000, 2000, 1000, 3000, 5000, 1000 };
	Easing* easing1 = new Easing(EASE_IN_BOUNCE,1000);
	Easing* easing2 = new Easing(EASE_OUT_BOUNCE,1000);
	Easing* easing3 = new Easing(EASE_IN_OUT_BOUNCE,1000);


	while(1)
	{
		for(auto i = 0; i < 240; i++)
		{
			auto index = i / 30;
			float newValue = values[index];

			printf("%f", newValue);
			printf(",");
			printf("%f", easing1->SetSetpoint(newValue));
			printf(",");
			printf("%f", easing2->SetSetpoint(newValue));
			printf(",");
			printf("%f", easing3->SetSetpoint(newValue));
			printf("\n");

			vTaskDelay(50 / portTICK_PERIOD_MS);
			//delay(50);
		}
	}
	vTaskDelete(NULL);
}
