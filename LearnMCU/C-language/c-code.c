void jose() {
    int i = 2;
    int j = 2;

    if(i == 1) {
        j = j + 1;
    }
    else if (i == 2) {
        j = j + 2;
    }
    else {
        j = j + 3;
    }

    return;
}

void jose1() {
    int i = 3;
    int j = 2;

    switch (i) {
        case 1:
            j = j +1;
            //break;
        case 2:
            j = j +2;
            break;
        case 3:
            j = j +3;
            break;
        default:
            j = j + 100;
    }

    return;
}

void jose2() {
    int i = 10;
    int j = 0;

    do {
        j = j +1;
        i = i -1;
    }
    while (i > 0);
}

void jose3() {
    int i = 10;
    int j = 0;

    while ( i > 0) {
        j = j +1;
        i = i - 1;
    }
}

void jose4() {
    int j = 0;

    for(int i = 10 ; i > 0 ; i = i -1) {
        j = j +1;
    }
}

void jose5() {
    int i = 2;
    if (i == 2) {
        goto end;
    }
    i = i +5;
    end:
        i = i +21;
}