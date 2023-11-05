
--question-1 string manipulation
--lower
select lower(sname) from student;
--upper
select upper(sname) from student;
--initcap
select initcap(sname) from student;
--length
select sname,length(sname) from student;
--lpad
select lpad(sname,7,'*') from student;
--rpad
select rpad(sname,7,'*') from student;
--trim
select lpad(sname,9,' ') as l,trim(lpad(sname,9,' ')) as t from student;
--ltrim
select lpad(sname,9,' ') as l,ltrim(lpad(sname,9,' ')) as lt from student;
--rtrim
select rpad(sname,11,' ') as r,rtrim(rpad(sname,11,' ')) as rt from student;

--question-2
--nvl
select nvl(sname,email) from student;
--nvl2
select nvl2(sname,reg_no,mobile) from student;
--nullif
select length(sname) "expr1",length(address) "expr2",
nullif(length(sname),length(address))
result from student;

--question-3
-- Display the name of the students who were born on a specified month. 
select sname,dob from student where extract(month from dob)=2; 

--question-4
-- Display the name of the students with a specified date of birth. 
select sname,dob from student where dob='04-FEB-98';

--question-5
-- Display the date of birth of a specified student in the format ‘Day of week, Month dd, yyyy’. 
select sname,to_char(dob,'dd-mm-yyyy') as dob from student;
select sname,to_char(dob,'dd-mm-yyyy') as dob from student where reg_no=22003; 

--question-6
-- Display the hour and minutes of the start time and end time of a specified slot. 
select slot,
extract(hour from stime) as stime_hr,
extract(minute from stime) as stime_min,
extract(hour from etime) as etime_hr,
extract(minute from etime) as etime_min 
from class
where slot='A1/B1';

--question-7
-- Display the day of week of the start date and end date of Winter semester 22-23 (Winter 2022). 
select sem_code,
to_char(sdate,'D') as sday,
to_char(edate,'D') as eday
from semester
where sem_code='WIN22';

--question-8
-- Display the duration of Winter semester 22-23 (Winter 2022) in terms of number of weeks. 
select sem_code,sdate,edate,months_between(edate,sdate)*4+1 as weeks
from semester
where sem_code='WIN22';

--question-9
CREATE SEQUENCE customer_seq
START WITH 100
INCREMENT BY 1
NOCACHE
NOCYCLE;

CREATE TABLE CUSTOMER (
Cus_code NUMBER PRIMARY KEY,
Cus_name VARCHAR2(10),
Cus_address VARCHAR2(20),
Cus_mobile VARCHAR2(10)
);

-- Insert the first customer
INSERT INTO CUSTOMER VALUES (customer_seq.NEXTVAL, 'Mehul', '123 New Delhi', '1234367243');
INSERT INTO CUSTOMER VALUES (customer_seq.NEXTVAL, 'Sidhant', '456 West Bengal', '4562387643');
INSERT INTO CUSTOMER VALUES (customer_seq.NEXTVAL, 'Jay', '789 Pune', '6534128744');
