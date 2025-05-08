#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

// Queue handles for inter-task communication
QueueHandle_t frameQueue;   // Queue for passing frame numbers from FrameCaptureTask to FaceRecognitionTask
QueueHandle_t resultQueue;  // Queue for passing recognition results from FaceRecognitionTask to LoggerTask

// Define task priorities
#define FRAME_CAPTURE_PRIORITY 3  // High priority
#define FACE_RECOGNITION_PRIORITY 2  // Medium priority
#define LOGGER_PRIORITY 1  // Low priority

// Task function prototypes
void FrameCaptureTask(void *pvParameters);
void FaceRecognitionTask(void *pvParameters);
void LoggerTask(void *pvParameters);

// Main function to setup FreeRTOS tasks and start the scheduler
int main(void) {
    // Create two queues
    frameQueue = xQueueCreate(10, sizeof(int));   // Queue to hold frame numbers
    resultQueue = xQueueCreate(10, sizeof(char));  // Queue to hold recognition results (using char for simplicity)

    // Check if queue creation was successful
    if (frameQueue == NULL || resultQueue == NULL) {
        // If queue creation fails, enter an infinite loop (for error handling)
        while (1);
    }

    // Create tasks
    xTaskCreate(FrameCaptureTask, "FrameCaptureTask", 1000, NULL, FRAME_CAPTURE_PRIORITY, NULL);
    xTaskCreate(FaceRecognitionTask, "FaceRecognitionTask", 1000, NULL, FACE_RECOGNITION_PRIORITY, NULL);
    xTaskCreate(LoggerTask, "LoggerTask", 1000, NULL, LOGGER_PRIORITY, NULL);

    // Start the FreeRTOS scheduler
    vTaskStartScheduler();

    // The scheduler should never return, but if it does, enter an infinite loop
    while (1);
    return 0;
}

// FrameCaptureTask: Simulates capturing frames every 100 ms
void FrameCaptureTask(void *pvParameters) {
    int frameNumber = 0;

    while (1) {
        // Simulate frame capture every 100 ms
        vTaskDelay(pdMS_TO_TICKS(100));  // Convert 100 ms to ticks

        // Increment the frame number
        frameNumber++;

        // Send the frame number to the frameQueue
        if (xQueueSend(frameQueue, &frameNumber, portMAX_DELAY) != pdPASS) {
            // If sending the frame number to the queue fails, print an error
            printf("Failed to send frame number to queue\n");
        }
    }
}

// FaceRecognitionTask: Receives frame numbers and simulates image processing
void FaceRecognitionTask(void *pvParameters) {
    int receivedFrameNumber;
    char recognitionResult;  // 'S' for success, 'F' for failure

    while (1) {
        // Receive the frame number from the frameQueue
        if (xQueueReceive(frameQueue, &receivedFrameNumber, portMAX_DELAY) == pdPASS) {
            // Simulate face recognition processing with a 100 ms delay
            vTaskDelay(pdMS_TO_TICKS(100));  // Simulate processing delay

            // Alternate recognition result (just for simulation purposes)
            recognitionResult = (receivedFrameNumber % 2 == 0) ? 'S' : 'F';  // Success for even, failure for odd frame numbers

            // Send the recognition result to the resultQueue
            if (xQueueSend(resultQueue, &recognitionResult, portMAX_DELAY) != pdPASS) {
                // If sending the recognition result to the queue fails, print an error
                printf("Failed to send recognition result to queue\n");
            }
        }
    }
}

// LoggerTask: Logs the frame number, recognition status, and timestamp
void LoggerTask(void *pvParameters) {
    char recognitionResult;
    TickType_t timestamp;

    while (1) {
        // Receive the recognition result from the resultQueue
        if (xQueueReceive(resultQueue, &recognitionResult, portMAX_DELAY) == pdPASS) {
            // Get the current tick count (timestamp)
            timestamp = xTaskGetTickCount();

            // Log the frame number, recognition result, and timestamp
            printf("Frame processed: Recognition status: %c, Timestamp: %u\n", recognitionResult, timestamp);
        }
    }
}

