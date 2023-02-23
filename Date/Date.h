#ifndef DATE_H
#define DATE_H

#include <iomanip>	//setfill   setw    formateo de los números de una fecha

#include <iostream>
using namespace std;


enum DATE_PART { DP_Day_of_Week = 0,
           	 	 DP_Month = 1, 
           	 	 DP_Year = 2,
			   }; 


enum DATE_FORMAT { DF_USA = 0,
	           	   DF_ANSI = 1, 
	           	   DF_British = 2,
	           	   DF_French = 3,
	           	   DF_German = 4,
	           	   DF_Italian = 5
				 }; 

class Date {
		int day;							//Datos miembro
		int month;
		int year;
		
		bool isValidDate();
		
		bool isLeap();
		
		int offsetDays();					//Retorna el número de días transcurridos del año  //addDays
		void revoffsetDays( int offset, 
						    int y, 
							int *d, 
							int *m);
		void addDays( int x );
		
		int countLeapYears(int m, int y);	//Difference
		
		string getNameMonth();				//PartName
		string getNameDayOfWeek();

		int getNumberDayOfWeek( int d, 		//La semana empieza en 0 (Domingo)
								int m, 
								int y);		
	public:
		Date();								//Constructores
		Date( int Day,
			  int Month,
			  int Year );
		
		
		void setDay( int Day );				//Funciones SETs y GETs
		int getDay();
		
		void setMonth( int Month );
		int getMonth();
		
		void setYear( int Year );
		int getYear();
			  
		
		void add( DATE_PART dp, 			//Sumar días, meses o años a la fecha del objeto
				  int x );
		
		int getDifferenceBetweenDates( int d, 	//Diferencia en días de esta fecha contra la almacenada en el objeto
									   int m, 
									   int y );
		
		string getPartName( DATE_PART dp );	//Nombre del día o mes de la fecha almacenada
		
		int getPartNumber( DATE_PART dp );	//Número del día o mes de la fecha almacenada

		void printDate( DATE_FORMAT df );	//Impresión de la fecha en diferentes formatos
};

#endif
