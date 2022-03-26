#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>

QueueHandle_t queue;

void task_1(void *pv)
{
    while(1)
    {
        printf("TASK 1 RUNIING\n");
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
    while(1)
    {
        printf("TASK 3 RUNNING\n");
        vTaskDelay(5000/portTICK_PERIOD_MS);
    }
}
void task_4(void *pv)
{
    int send=0;
    while(1)
    {
        send++;
        printf("TASK 4 RUNNING\n");
        xQueueSend(queue,&send,portMAX_DELAY);
        vTaskDelay(2000/portTICK_PERIOD_MS);
    }
}
void task_5(void *pv)
{
    int receive=0;
    while(1)
    {
        printf("TASK 5 RUNNING \n");
        xQueueReceive(queue,&receive,portMAX_DELAY);
        printf("RECEIVED DATA :%d\n",receive);
        vTaskDelay(2000/portTICK_PERIOD_MS);
    }
}
void app_main()
{
    queue=xQueueCreate(10,sizeof(int));
    BaseType_t result;
    result=xTaskCreate(task_1,"Task_1",2048,NULL,6,NULL);
    if(result==pdPASS)
    {
        printf("Task_1 created\n");
    }
    result=xTaskCreate(task_2,"Task_2",2048,NULL,7,NULL);
    if(result==pdPASS)
    {
        printf("Task_2 created\n");
    }
    result=xTaskCreate(task_3,"Task_3",2048,NULL,8,NULL);
    if(result==pdPASS)
    {
        printf("Task_3 created\n");
    }
    result=xTaskCreate(task_4,"Task_4",2048,NULL,9,NULL);
    if(result==pdPASS)
    {
        printf("Task_4 created\n");
    }
    result=xTaskCreate(task_5,"Task_5",2048,NULL,10,NULL);
    if(result==pdPASS)
    {
        printf("Task_5 created\n");
    }
}