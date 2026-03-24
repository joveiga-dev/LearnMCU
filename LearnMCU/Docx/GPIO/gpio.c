
#define BUTTONA     0b00000010
#define LEDA        0b00000001

void do_init() {
    // Stop watchdog timer
    // Initializing led1
    PADIR |= LED1;

    // Initalizing Switch B
    PADIR |= & ~BUTTONA;
    PAREN |= BUTTONA;
    PAOUT |= BUTTONA;

}


int main()
{
    do_init();

    while (1)
    {
        // if the button is pressed
        if((PAIN & BUTTONA) == 0){
            PAOUT |= LEDA;
        }
        else{
            PAOUT &= ~LEDA;
        }
    }
    
}