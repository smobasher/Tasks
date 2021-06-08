/*Salma Mobasher
8120214
Due: Feb 1, 2021

Task create makes an instance of a task.
Task start scheduler starts the tasks and interrupts.
Tick interupts are timer interupts that are triggered when a period is hit.
*/

#include "FreeRTOS.h"
#include "task.h"


#include "supporting_functions.h"

#define mainDELAY_LOOP_COUNT		( 0xffffff )
//making the tasks
void vTask1(void *pvParameters);
void vTask2(void *pvParameters);
void vTask3(void *pvParameters);
void vTask4(void *pvParameters);

int main(void)
{
	char *task3Param = "Right now, task 3 is running!!!"; //parameter for task 3

	xTaskCreate(vTask1, "Task 1", 1000, NULL, 1, NULL);		
	xTaskCreate(vTask2, "Task 2", 1000, NULL, 1, NULL);
	xTaskCreate(vTask3, "Task 3", 1000, task3Param, 1, NULL);
	xTaskCreate(vTask4, "Task 4", 1000, NULL, 1, NULL);
	//starting the schedule
	vTaskStartScheduler();
	for (;; );
	return 0;
}

void vTask1(void *pvParameters) //task 1
{
	const char *pcTaskName = "Task 1 is running\r\n";
	volatile uint32_t ul;


	for (int i = 0; i < 20; i++) /////////////////////////so now the loop is only running 20 times
	{
		vPrintString(pcTaskName);

		for (ul = 0; ul < mainDELAY_LOOP_COUNT; ul++)
		{
			
		}
	}
}

void vTask2(void *pvParameters) //task 2
{
	const char *pcTaskName = "Task 2 is running\r\n";
	volatile uint32_t ul;


	for (int i = 0; i < 20; i++) //////////////So now the loop is only running 20 times 
	{
		vPrintString(pcTaskName);

		
		for (ul = 0; ul < mainDELAY_LOOP_COUNT; ul++)
		{
		}
	}
}

void vTask3(void *pvParameters) //task 3
{
	vTaskDelay(3); ////forces the task 3 to be the last one of 1 2 and 3 by waiting 3 ticks
	const char *pcTaskName = "Task 3 is running\r\n";
	volatile uint32_t ul;


	for (int i = 0; i < 20; i++) //////////////So now the loop is only running 20 times 
	{
		vPrintString(pcTaskName);

		for (ul = 0; ul < mainDELAY_LOOP_COUNT; ul++)
		{
		}
	}
}

void vTask4(void *pvParameters) 
{
	const char *pcTaskName = "Task 4 is running\r\n";
	volatile uint32_t ul;


	for (int i = 0; i < 20; i++) //////////////So now the loop is only running 20 times 
	{
		vTaskDelete(NULL); /////////kills the task :D
		vPrintString(pcTaskName); ///kept it to show its not running

		for (ul = 0; ul < mainDELAY_LOOP_COUNT; ul++)
		{
			
		}
	}
}



