#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX(x, y)     ((x) > (y) ? (x) : (y))
#define ABS(x)        ((x) > 0 ? (x) : -(x))
#define MAX_SENSORS    10
#define TEMPERATURE_THRESHOLD    33.0f
// Multi-line macro

/*
#define INIT_SENSOR(sensor, id, threshold) \
    do { \
        sensor.id = id; \
        sensor.threshold = threshold; \    
  
        } while(0)
*/
// Debug code

#define DEBUG
#ifdef DEBUG
    #define DEBUG_PRINTF(msg)  printf("DEBUG: %s\n", msg)
#else
    #define DEBUG_PRINTF(msg)    ((void)0)
#endif

// Data structure

typedef struct 
{
    uint32_t id;
    float temperature;
    bool status;
}sensor_t;

typedef struct 
{
    sensor_t sensor[MAX_SENSORS];
    uint8_t sensor_count;
    bool system_status;
}system_state_t;

// Function prototypes
void system_init(system_state_t *state);
void read_sensors(system_state_t* state);
void process_data(system_state_t *state);
void update_outputs(system_state_t *state);
sensor_t* find_hottest_sensor(system_state_t *state);
void stop_count(system_state_t *state, int count);
void read_sensor_data(system_state_t* state);

int compare_values(const void* a, const void* b)
{
    float ta = *(const float*)a;
    float tb = *(const float*)b;

    return (ta > tb) - (ta < tb);

}

int main()
{   
    srand(time(NULL));

    system_state_t system;
    int cycles = 0;

    system_init(&system);
    while (system.system_status)
    {
        read_sensors(&system);
        read_sensor_data(&system);
        process_data(&system);

        sensor_t *hs =  find_hottest_sensor(&system);

        if(hs != NULL)
        {
            printf("Hottest sensor -> ID: %u, Temp: %.2f\n", hs->id, hs->temperature);
        }
        printf("\n\n");

        cycles++;
        
        stop_count(&system, 6);
    }
    
    return 0;
}

void system_init(system_state_t *state)
{
    for (int i = 0; i < MAX_SENSORS; i++)
    {
        state->sensor[i].id = i;
        state->sensor[i].temperature = 0.0;
        state->sensor[i].status = true;
    }
    
    state->sensor_count = MAX_SENSORS;
    state->system_status = true;
    
}
void read_sensors(system_state_t* state)
{
    
    for (int i = 0; i < state->sensor_count; i++)
    {
        if (state->sensor[i].status)
        {
            state->sensor[i].temperature = -12.0f + ((float)rand() / (float)RAND_MAX) * 82.0f;
        }
    }
    
}

sensor_t*  find_hottest_sensor(system_state_t *state)
{
    if (state->sensor_count == 0)
    {
        return NULL;
    }

    sensor_t *hottest = &state->sensor[0]; // consider as the hottest
    for (int i = 1; i < state->sensor_count; i++)
    {
        if(compare_values(&state->sensor[i].temperature, &hottest->temperature) > 0)
        {
            hottest = &state->sensor[i];
        }
    }

    return hottest;
    
}

void stop_count(system_state_t *state, int count)
{
    if (count >= 6)
    {
        state->system_status = false;
    }
}

void read_sensor_data(system_state_t* state)
{
    for (uint8_t i = 0; i < state->sensor_count; i++)
    {
        printf("Sensor ID: %u, Temp: %.2f\n", state->sensor[i].id, state->sensor[i].temperature);
    }
    
}

void process_data(system_state_t *state)
{
    for (uint8_t i = 0; i < state->sensor_count; i++)
    {
        if(state->sensor[i].temperature > TEMPERATURE_THRESHOLD)
        {
            DEBUG_PRINTF("High Temperature detected---Cooling the system");
            printf("Sensor ID: %u\n", state->sensor[i].id);
            // active_cooling();
        }
    }
    
}



