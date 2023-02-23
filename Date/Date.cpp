#include "Date.h"

/*---------------------------------------------------------------------------------------------------------------------*/
/*		CONSTRUCTORES		*/
Date::Date(){
	day = 1;
	month = 1;
	year = 2020;
}


Date::Date( int Day,
			int Month,
			int Year ){
	day = Day;
	month = Month;
	year = Year;
	
	if (!isValidDate())
		cout << "Fecha invalida" << endl;
}

/*---------------------------------------------------------------------------------------------------------------------*/
/*		FUNCIONES   SET Y  GET		*/
void Date::setDay( int Day ){
	this->day = Day;
}

int Date::getDay(){
	return this->day;
}



void Date::setMonth( int Month ){
	this->month = Month;
}

int Date::getMonth(){
	return this->month;
}



void Date::setYear( int Year ){
	this->year = Year;
}

int Date::getYear(){
	return this->year;
}



/*---------------------------------------------------------------------------------------------------------------------*/
/*		PRIVADAS		*/
bool Date::isValidDate(){
	if ( year <= 0)					//Valida que año sea mayor que 0
		return false;
			
	if ( month < 1 || month > 12)	//Valida el número de mes
		return false;
	
	
	//Valida el número de día de acuerdo al mes
	if ( day < 1 )					//a) número de día menor que 1
		return false;
		
	bool isDayCorrect = false;		//b) número de día mayor al máximo del mes
	switch (month) {
        case 2:
        	//Febrero
            if (isLeap())
                isDayCorrect = day <= 29;
            else
                isDayCorrect = day <= 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
        	//Abril, Junio, Septiembre, Noviembre
            isDayCorrect = day <= 30;
            break;
        default:
        	//Enero, Marzo, Mayo, Julio, Agosto, Octubre, Diciembre
            isDayCorrect = day <= 31;
    }
    
    
    return isDayCorrect;
}



bool Date::isLeap(){
	return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}




string Date::getNameMonth(){
	switch ( this->month ){
		case 1: return "Enero"; break;
		case 2: return "Febrero"; break;
		case 3: return "Marzo"; break;
		case 4: return "Abril"; break;
		case 5: return "Mayo"; break;
		case 6: return "Junio"; break;
		case 7: return "Julio"; break;
		case 8: return "Agosto"; break;
		case 9: return "Septiembre"; break;
		case 10: return "Octubre"; break;
		case 11: return "Noviembre"; break;
		case 12: return "Diciembre"; break;
	}
}

			
			
			
string Date::getNameDayOfWeek(){
	string arrDay[] = {
		"Domingo",
		"Lunes",
		"Martes",
		"Miercoles",
		"Jueves",
		"Viernes",
		"Sabado"
	};
	
	int dn = getNumberDayOfWeek(day, month, year);
	
	return arrDay[dn % 7];
}



//La semana empieza en 0 (Domingo)
int Date::getNumberDayOfWeek(int d, int m, int y) {  
    static int t[] = { 0, 3, 2, 5, 0, 3, 
                       5, 1, 4, 6, 2, 4 };  
    y -= m < 3;  
    return ( y + y / 4 - y / 100 +  
             y / 400 + t[m - 1] + d) % 7;  
}




//Retorna el número de días transcurridos del año 
int Date::offsetDays() { 
    int offset = day; //Toma los días del mes de la fecha dada. Enero ya no tiene que calcular días transcurridos
  
    switch (month - 1) { 
	    case 11: 
	        offset += 30; 
	    case 10: 
	        offset += 31; 
	    case 9: 
	        offset += 30; 
	    case 8: 
	        offset += 31; 
	    case 7: 
	        offset += 31; 
	    case 6: 
	        offset += 30; 
	    case 5: 
	        offset += 31; 
	    case 4: 
	        offset += 30; 
	    case 3: 
	        offset += 31; 
	    case 2: //Marzo + 28 días de Febrero + 31 de Enero
	        offset += 28; 
	    case 1: //Febrero + 31 días de Enero
	        offset += 31; 
    } 
  
  	//Validación de los años bisiestos
    if (isLeap() && month > 2) 
        offset += 1; 
  
    return offset; 
} 
  
  
  
  
// Given a year and days elapsed in it, finds 
// date by storing results in d and m. 
//Para addDays
void Date::revoffsetDays(int offset, int y, int *d, int *m) { 
    int month[13] = { 0, 31, 28, 31, 30, 31, 30, 
                      31, 31, 30, 31, 30, 31 }; 
  
    if (isLeap()) 
        month[2] = 29; 
  
    int i; 
    for (i = 1; i <= 12; i++) { 
        if (offset <= month[i]) 
            break; 
        offset = offset - month[i]; 
    } 
  
    *d = offset; 
    *m = i; 
} 




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This function counts number of leap years before the 
// given date 
int Date::countLeapYears(int m, int y) { 
//https://www.geeksforgeeks.org/find-number-of-days-between-two-given-dates/
    int years = y; 
  
    // Check if the current year needs to be considered 
    // for the count of leap years or not 
    if (m <= 2) 
        years--; 
  
    // An year is a leap year if it is a multiple of 4, 
    // multiple of 400 and not a multiple of 100. 
    return years / 4 - years / 100 + years / 400; 
} 


/*---------------------------------------------------------------------------------------------------------------------*/
/*		PUBLICAS      */
void Date::printDate( DATE_FORMAT df ){
	switch ( df ){
		case DF_USA: cout << setfill('0') << setw(2) << this->month << "/"
						  << setfill('0') << setw(2) << this->day << "/"
						  << setfill('0') << setw(2) << this->year % 100 << endl;
					 break; // MM/DD/YY
					 
	    case DF_ANSI: cout << setfill('0') << setw(2) << this->year % 100 << "."
						  << setfill('0') << setw(2) << this->month << "."
						  << setfill('0') << setw(2) << this->day << endl;
					  break; // YY.MM.DD
					  
	    case DF_British: 
	    case DF_French: cout << setfill('0') << setw(2) << this->day << "/"
							 << setfill('0') << setw(2) << this->month << "/"
							 << setfill('0') << setw(2) << this->year % 100 << endl; break; // DD/MM/YY
	    case DF_German: break; // DD.MM.YY
	    case DF_Italian: cout << setfill('0') << setw(2) << this->day << "-"
							 << setfill('0') << setw(2) << this->month << "-"
							 << setfill('0') << setw(2) << this->year % 100 << endl; break; // DD-MM-YY
	}
	
	//cout << day << "-" << month << "-" << year << endl;
}




string Date::getPartName( DATE_PART dp ){
	switch ( dp ){
		case DP_Day_of_Week: return getNameDayOfWeek(); break;
		case DP_Month: return getNameMonth(); break;
		case DP_Year: break;
	}
}



int Date::getPartNumber( DATE_PART dp ){
	switch ( dp ){
		case DP_Day_of_Week: return getNumberDayOfWeek(day, month, year); break;
		case DP_Month: return this->month; break;
		case DP_Year: return this->year; break;
	}
}








// Add x days to the given date. 
void Date::addDays( int x ){
	//https://www.geeksforgeeks.org/date-after-adding-given-number-of-days-to-the-given-date/
    int offset1 = offsetDays(); 
    int remDays = isLeap()?(366-offset1):(365-offset1); 
  
    // y2 is going to store result year and 
    // offset2 is going to store offset days 
    // in result year. 
    int y2, offset2; 
    if (x <= remDays){ 
        y2 = year; 
        offset2 = offset1 + x; 
    }   
    else    { 
        // x may store thousands of days. 
        // We find correct year and offset 
        // in the year. 
        x -= remDays; 
        y2 = year + 1; 
        int y2days = isLeap()?366:365; 
        while (x >= y2days){ 
            x -= y2days; 
            y2++; 
            y2days = isLeap()?366:365; 
        } 
        offset2 = x; 
    } 
  
    // Find values of day and month from 
    // offset of result year. 
    int m2, d2; 
    revoffsetDays(offset2, y2, &d2, &m2); 
  
  
  	day = d2;
  	month = m2;
  	year = y2;
}


void Date::add( DATE_PART dp, 
			    int x ){ 
	switch ( dp ){
		case DP_Day_of_Week: addDays( x ); break;
		case DP_Month: this->month += (x % 12); 
					   this->year += (x / 12); break;
		case DP_Year: this->year += x; break;
	}
} 

  
  
  
// This function returns number of days between two given 
// dates 
int Date::getDifferenceBetweenDates( int d, 
									 int m, 
									 int y ){ 
	int monthDays[12] = {31, 28, 31, 30, 31, 30, 
                           31, 31, 30, 31, 30, 31}; 
	
	
    // COUNT TOTAL NUMBER OF DAYS BEFORE FIRST DATE 'dt1' 
  
    // initialize count using years and day 
    long int n1 = year*365 + day; 
  
    // Add days for months in given date 
    for (int i=0; i<month - 1; i++) 
        n1 += monthDays[i]; 
  
    // Since every leap year is of 366 days, 
    // Add a day for every leap year 
    n1 += countLeapYears(month, year); 
  
    // SIMILARLY, COUNT TOTAL NUMBER OF DAYS BEFORE 'dt2' 
  
  
  
    long int n2 = y*365 + d; 
    for (int i=0; i<m - 1; i++) 
        n2 += monthDays[i]; 
    n2 += countLeapYears(m, y); 
  
    // return difference between two counts 
    return (n2 - n1); 
} 
