-- procedure
create or replace procedure raise_invoice(id in number, amt in number)
is 
begin 
update invoice set inv_amount=inv_amount + amt
where inv_no=id;
commit;
end;
/

-- cursor
declare
cursor c1 is select inv_no,inv_amount from invoice;
vid invoice.inv_no%type;
vamt invoice.inv_amount%type;
begin
  open c1;
  loop
    fetch c1 into vid,vamt;
    exit when c1%notfound;
    dbms_output.put_line('---'||vid||' '||vamt); 
  end loop;
  close c1;
end;
/

--function
create or replace function calculator(a number,b number,op char) return number
is 
begin
   if op='+' then
      return (a+b);
   elsif op='-' then
      return (a-b);
   elsif op='/' then
      return (a/b);
   elsif op='*' then
      return (a*b);
   end if;
end;
/

create or replace function factorial(a number) return number
is 
f number;
begin
   f:=1;
   for i in reverse 1..a  
   loop
      f:=f*i;
   end loop;
   return f;
end;
/

create or replace function prime(a number) return varchar2
is 
f number;
n number;
begin
   f:=0;
   n:=a/2;
   for i in 3..n
   loop
      if a mod(i)=0 then
         f:=f+1;
      end if;
   end loop;
   if f=0 then 
      return 'true';
   else 
      return 'false';
   end if;
end;
/