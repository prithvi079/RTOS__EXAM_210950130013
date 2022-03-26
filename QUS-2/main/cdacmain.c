#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/timers.h>

TimerHandle_t timer;

void timerfunction(TimerHandle_t xTimer)
{
    printf("timer callback function\n");
}
void task_1(void *pv)
{
    while(1)
    {
        printf("TASK 1 RUNNING\n");
        vTaskDelay(1000/portTICK_PERIOD_MS);
    }
   
}
void task_2(void *pv)
{
    while(1)
    {
        printf("TASK 2 RUNNING\n");
        vTaskDelay(2000/portTICK_PERIOD_MS);
    }

    
}
void task_3(void *pv)
{
    uint32_t count=0;
    while(1)
    {
        count++;
        printf("TASK 3 RUNNING\n");
        vTaskDelay(5000/portTICK_PERIOD_MS);
        if(count==2)
        {
             xTimerStart(timer,0);  
        }
                         
    }
    
}
void app_main()
{
    BaseType_t result;
    result=xTaskCreate(task_1,"task_1",2048,NULL,5,NULL);
    if(result==pdTRUE)
    {
        printf("task 1 created\n");
    }
    result=xTaskCreate(task_2,"task_2",2048,NULL,6,NULL);
    if(result==pdTRUE)
    {
        printf("task 2 created\n");
    }
    result=xTaskCreate(task_3,"task_3",2048,NULL,7,NULL);
    if(result==pdTRUE)
    {
        printf("task 3 created\n");
    }
    timer=xTimerCreate("timer_1",pdMS_TO_TICKS(10),pdFALSE,NULL,timerfunction);    // software timer
    
}
