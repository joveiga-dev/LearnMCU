
## Variables and Data Types
- Static:
- Automatic (stack)
- Dynamic (heap)

Static inside a function behaves like a global with functions scope
Const data may reside in non-volatile memory; don't cast away const to write to it

```c

// .rodata (FLASH) --const + global scope = read-only data in flash
const uint32_t firmware_version = 0x0101;

// .data (RAM, copied from flash at boot) -- initialized global
uint32_t sensor_count = 10; 

// .bss (RAM, zeroed at boot) -- uninitialized global (zero by default)
uint32_t error_count;

// .data --static global, same as non-static
static uint32_t component_id = 34;

// .bss --uninitialized static global
static uint32_t call_count;

void read_sensor(uint16_t channel) {

    // Stack --automatic storage, NOT initialized, destroyed on return
    uint8_t buffer[45];

    // .bss ---static LOCAL, persists between calls, zero-initialized once
    static uint32_t invocation_count;
    invocation_count++;

    // .rodata --static const local, stored in flash
    static const uint16_t lookup[] = {0, 100, 200, 300, 400};
}

```

The `static` keyword on local variable moves it from the stack to `.bss` or `.data`. This means it persists between function calls
(useful for counters, state machines) but also means the funtion is no longer reetrant-- if two threads call it simultaneously, they
share the same static variable.

Local (automatic) variables are not initialized. They contain whatever happened to be on the stack. 


```c
/* Typicall register pointer: volatile pointer-to-volatile data, const address */
#define GPIOA_ODR   (*(volatile uint32_t *)0x40020014)    /* output data re */
#define GPIOA_IDR   (*(volatile uint32_t *)0x40020010)

void toggle_led(uint8_t pin) {
    GPIOA_ODR ^= (1U << pin);         /* read-modify-write */
}

uint8_t read_button(uint8_t pin) {
    return (GPIOA_IDR >> pin) & 1U;
    //return (GPIOA_IDR & (1U << pin))
}

```

`volatile const` variable that cannot be written by the program but can change at any time due to hardware `volatile`. An 
example is a Hardware Status Register.

```c
/* Status register: hardware updates it, firmware only reads it */

volatile const uint32_t * const STATUS_REG = 
    (volatile const uint32_t *)0x40020008;

uint32_t get_status(void) {
    return *STATUS_REG;   /* always reads hardware. never cached */
}

/* *STATUS_REG = 0; */ /* compile error --const prevents writes */



```

# Pointer Fundamentals

## Pointer Basics
The `&` operator is used to retrieve the address of a variable while `*` operator go to that address to and read the stored value.

```c
uint16_t adc_raw = 1023;
uint16_t *ptr = &adc_raw;   /* ptr holds the address of adc_raw */

uint16_t val = *ptr;   /* val == 1023 - dereference reads value */
*ptr = 512;            /* adc_raw is now 512 - dereference writes */


/* *(&adc_raw) = x same thing */

```
Embedded systems way:

```c
volatile uint32_t * const GPIOA_ODR = (volatile uint32_t *)0x40020014;
/* #define GPIOA_ODR  = (*(volatile uint32_t *)0x40020014);   same thing then GPIOA_ODR |= (1U << 5)*/

*GPIOA_ODR |= (1U << 5);       /* set bit 5 - turn on LED */
```
Pointer arithmetic

```c

uint8_t  *bp = (uint8_t  *)0x2000;   /* byte pointer    */
uint16_t *hp = (uint16_t *)0x2000;   /* halfword pointer */
uint32_t *wp = (uint32_t *)0x2000;   /* word pointer     */

bp++;  /* 0x2001  — advances 1 byte  */
hp++;  /* 0x2002  — advances 2 bytes */
wp++;  /* 0x2004  — advances 4 bytes */
```

## Void Pointers
We can assign any object pointer to a `void*` without cast, but we cannot dereference or do arithmetic on a `void*` without casting it first.
In embedded systems `void*` appears often in:
- Callback context pointers-  passing user data to an ISR callback or RTOS task
- (memcpy / memset) works on any buffer as their signatures allow it
- Generic  data structures - a ring buffer library that stores any element type


```c

void swap(void *a, void *b, size_t size) {
    uint8_t temp[size];                 /* VLA - aceptable for small sizes */
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

int x = 1, y = 2;

swap(&x, &y, sizeof(int));


```

## NULL Pointer
Dereference `NULL` is undefined behavior. On cortex-M it triggers a HardFault (addr 0x00000000 is the initial SP, not a valid data address).
In safety-critical code (MISRA C) every pointer must be checked against `NULL` before dereference, and functions must document whether
`NULL` is a valid argument.

```c
/* Guard every pointer before use */

void uart_send(const uint8_t *buf, size_t len) {
    if (buf == NULL || len == 0) {
        return;
    }
    for (size_t i = 0; i < len; i++) {
        UART_TX_REG = buf[i];
    }
}

```

## Dangling Pointer
Points to memory that has been free'd or has gone out of scope. 

```c
/* BUG: returning a pointer to a local variable */
uint8_t *get_buffer(void) {
    uint8_t buf[64];   /* lives on the stack */
    fill_buffer(buf, 64);
    return buf;             /* buffer is destroyed when function returns */
}

```

- Never return the address of a local variable
- Set pointers to `NULL` after `free()`
- Use `static` or caller-provided buffers instead of returning local arrays


## Function Pointers
is a pointer that stores the address of a function, enabling runtime dispatch. 

```c

typedef void (*iqr_handler_t)(void);

/* Dispatch table - one handler per IRQ line */

static irq_handler_t handlers[16] = {NULL};

void register_handler(uint8_t irq, irq_handler_t fn) {
    if (irq < 16) handlers[irq] = fn;
}

void dispatch(uint8_t irq) {
    if (irq < 16 && handlers[irq] != NULL) {
        handlers[irq]();                  /* Call through pointer */
    }
}



```
