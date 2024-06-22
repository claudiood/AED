bool lemonadeChange(int *bills, int billsSize) {
    
    int *ptr = bills;

    int five = 0, ten = 0, twenty = 0, contador = 0;

    for(contador = 0; contador < billsSize; contador++){

        if(*ptr == 5){
            five++;
            ptr++;
        }
        
        else if(*ptr == 10){
            if(five > 0){
                ten++;
                five--;
                ptr++;
            }
            else{
                return false;
            }
        }
            
        else if(*ptr == 20){
            if((five > 0) && (ten > 0)){
                twenty++;
                ten--;
                five--;
                ptr++;
            }else if(five > 2){
                five = five - 3;
                ptr++;
            }
            else{
                return false;
            }
        }
    }

    return true;
}

const int billsSize = 5;