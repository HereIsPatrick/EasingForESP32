![alt text](./images/easing.gif)
# Easing functions for ESP32
Easing function is beautiful thing. In real world, everything's movements are not constant speed.

It can make our design become humanity, better user experience.

We can use it in animations and slides transitions. Lots of the easing function have been applying in GUI(Graphics User Interface). 

## Example setup & exectue.
1. git pull this repo.
2. Use ESP32 IDF to compile source code for this respo.
3. Flash the image binary file to your ESP32 controller.
4. Visual Information was get from 'Arduino Serial Plotter' 

There are 33 easing functions for ESP32. 
	
	LINEAR,
	EASE_IN_SINE,
	EASE_OUT_SINE,
	EASE_IN_OUT_SINE,

	EASE_IN_QUAD,
	EASE_OUT_QUAD,
	EASE_IN_OUT_QUAD,

	EASE_IN_CUBIC,
	EASE_OUT_CUBIC,
	EASE_IN_OUT_CUBIC,

	EASE_IN_QUART,
	EASE_OUT_QUART,
	EASE_IN_OUT_QUART,

	EASE_IN_QUINT,
	EASE_OUT_QUINT,
	EASE_IN_OUT_QUINT,

	EASE_IN_EXPO,
	EASE_OUT_EXPO,
	EASE_IN_OUT_EXPO,

	EASE_IN_CIRC,
	EASE_OUT_CIRC,
	EASE_IN_OUT_CIRC,

	EASE_IN_BACK,
	EASE_OUT_BACK,
	EASE_IN_OUT_BACK,

	EASE_IN_ELASTIC,
	EASE_OUT_ELASTIC,
	EASE_IN_OUT_ELASTIC,

	EASE_IN_BOUNCE,
	EASE_OUT_BOUNCE,
	EASE_IN_OUT_BOUNCE
## Example
```
void app_main(void)
{
	int values[8] = { 0, 4000, 1000, 3000, 2000, 3000, 1000, 5000 };
	std::vector<EASING> v;
	// Step. Easing sine function
	v.push_back({"in_sine",Easing(EASE_IN_SINE,DURATION)});
	v.push_back({"out_sine",Easing(EASE_OUT_SINE,DURATION)});
	v.push_back({"in/out_sine",Easing(EASE_IN_OUT_SINE,DURATION)});

	// Step. Easing quid function
	v.push_back({"in_quad",Easing(EASE_IN_QUAD,DURATION)});
	v.push_back({"out_quad",Easing(EASE_OUT_QUAD,DURATION)});
	v.push_back({"in/out_quad",Easing(EASE_IN_OUT_QUAD,DURATION)});

	// Step. Easing cubic function
	v.push_back({"in_cubic",Easing(EASE_IN_CUBIC,DURATION)});
	v.push_back({"out_cubic",Easing(EASE_OUT_CUBIC,DURATION)});
	v.push_back({"in/out_cubic",Easing(EASE_IN_OUT_CUBIC,DURATION)});

	// Step. Easing quart function
	v.push_back({"in_quart",Easing(EASE_IN_QUART,DURATION)});
	v.push_back({"out_quart",Easing(EASE_OUT_QUART,DURATION)});
	v.push_back({"in/out_quart",Easing(EASE_IN_OUT_QUART,DURATION)});

	// Step. Easing quint function
	v.push_back({"in_quint",Easing(EASE_IN_QUINT,DURATION)});
	v.push_back({"out_quint",Easing(EASE_OUT_QUINT,DURATION)});
	v.push_back({"in/out_quint",Easing(EASE_IN_OUT_QUINT,DURATION)});

	// Step. Easing expo function
	v.push_back({"in_expo",Easing(EASE_IN_EXPO,DURATION)});
	v.push_back({"out_expo",Easing(EASE_OUT_EXPO,DURATION)});
	v.push_back({"in/out_expo",Easing(EASE_IN_OUT_EXPO,DURATION)});

	// Step. Easing circ function
	v.push_back({"in_circ",Easing(EASE_IN_CIRC,DURATION)});
	v.push_back({"out_circ",Easing(EASE_OUT_CIRC,DURATION)});
	v.push_back({"in/out_circ",Easing(EASE_IN_OUT_CIRC,DURATION)});

	// Step. Easing back function
	v.push_back({"in_back",Easing(EASE_IN_BACK,DURATION)});
	v.push_back({"out_back",Easing(EASE_OUT_BACK,DURATION)});
	v.push_back({"in/out_back",Easing(EASE_IN_OUT_BACK,DURATION)});

	// Step. Easing elastic function
	v.push_back({"in_elastic",Easing(EASE_IN_ELASTIC,DURATION)});
	v.push_back({"out_elastic",Easing(EASE_OUT_ELASTIC,DURATION)});
	v.push_back({"in/out_elastic",Easing(EASE_IN_OUT_ELASTIC,DURATION)});

	// Step. Easing bounce function
	v.push_back({"in_bounce",Easing(EASE_IN_BOUNCE,DURATION)});
	v.push_back({"out_bounce",Easing(EASE_OUT_BOUNCE,DURATION)});
	v.push_back({"in/out_bounce",Easing(EASE_IN_OUT_BOUNCE,DURATION)});

	while(1)
	{
		// Step. Draw 3 easing functions at the same time.
		for(int j=0; j<10; j++)
		{
			// Step. print legend to arduino serial plotter.
			char legend[32]="";
			sprintf(legend, "%d_target, %s, %s, %s",j+1, v[0+j*3].name.c_str(), v[1+j*3].name.c_str(), v[2+j*3].name.c_str());
			printf("%s\n",legend);

			// Step. Print value of easing function in plotter.
			for(auto i = 0; i < 240; i++)
			{
				auto index = i / 30;
				float newValue = values[index];

				printf("%f", newValue);
				printf(",");
				printf("%f", v[0+j*3].e.SetSetpoint(newValue));
				printf(",");
				printf("%f", v[1+j*3].e.SetSetpoint(newValue));
				printf(",");
				printf("%f", v[2+j*3].e.SetSetpoint(newValue));
				printf("\n");

				// Step. delay 50ms
				vTaskDelay(50 / portTICK_PERIOD_MS);
			}
		}
	}
	vTaskDelete(NULL);
}
```

###Reference
1. https://easings.net/en
2. https://github.com/luisllamasbinaburo/Arduino-Easing
3. https://github.com/nicolausYes/easing-functions

###License
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
