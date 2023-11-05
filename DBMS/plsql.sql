--fibonacci series
set serveroutput on;
declare
    a int;
    b int;
    c int;
    n int;
begin
    n:=&n;
    a:=0;
    b:=1;
    dbms_output.put_line('FIBONACCI SERIES: ');
    dbms_output.put_line(a);
    dbms_output.put_line(b);
    for i in 1..n-2
    loop
        c:=a+b;
        dbms_output.put_line(c);
        a:=b;
        b:=c;
    end loop;
end;
/

--factorial
set serveroutput on;
declare
    n int;
    f int;
begin
    n:=&n;
    f:=1;
    for i in reverse 1..n
    loop
        f:=f*i;
    end loop;
    dbms_output.put_line('FACTORIAL OF '||n||' = '||f);
end;
/

--age checker
set serveroutput on;
declare
    a int;
begin
    a:=&a;
    if a>59 then
        dbms_output.put_line('senior citizen');
    else
        dbms_output.put_line('not a senior citizen');
    end if;
end;
/

--prime or not
set serveroutput on;
declare
    n int;
    c int;
    a int;
begin
    n:=&n;
    c:=0;
    a:=n/2;
    for i in 2..a
    loop
        if n mod(i)=0 then
            c:=c+1;
        end if;
    end loop;
    if c=0 then
        dbms_output.put_line(n||' is prime');
    else
        dbms_output.put_line(n||' is not prime');
    end if;
end;
/    