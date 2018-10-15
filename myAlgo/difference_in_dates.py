import os
import datetime

date1 = datetime.date.today()
print date1.weekday()

deltaDay = 3 - date1.weekday()
if deltaDay < 0:
	deltaDay = deltaDay + 7;
date1 = date1  + datetime.timedelta(days=deltaDay)
total_thursday = 0;
date2 = datetime.date(2014,1,5);

while date2 > date1:
	total_thursday = total_thursday + 1;
	print date1
	date1 = date1  + datetime.timedelta(days=7)
print total_thursday ;

print (total_thursday * 1470 - 1.5 * 2000 + 0 + 000) 
print 61.3*(total_thursday * 1470 - 1.5 * 2000 + 0 + 000) 
print 450000 + 165000 - 1000000  ;
print (450000 + 165000 - 1000000)/61.3;
print (total_thursday * 1470 - total_thursday/4 * 2000  + 000)  + (550000 + 65000 - 1000000)/61.3
