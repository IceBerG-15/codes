-- CUSTOMER (Cus_code, Cus_fname, Cus_lname, Cus_balance)
-- INVOICE (Inv_no, Cus_code, Inv_date, Inv_amount)
-- LINE (Inv_no, Line_no, P_code, Line_units, Line_price)
-- PRODUCT (P_code, P_desc, P_qoh, P_price, V_code)
-- VENDOR (V_code, V_name, V_Contact)
-- The primary keys are underlined and foreign keys are self-explanatory.
create table customer(
    cus_code number(10) primary key,
    cus_fname varchar2(15),
    cus_lname varchar2(15),
    cus_balance number(10)
);
create table invoice(
    inv_no number(10) primary key,
    cus_code number(10) references customer(cus_code),
    inv_date date,
    inv_amount number(10)
);
create table vendor(
    v_code number(10) primary key,
    v_name varchar2(10),
    v_contact varchar2(10),
    constraint contact check (length(v_contact)=10)
);
create table product(
    p_code number(10) primary key,
    p_desc varchar2(20),
    p_qoh varchar2(10),
    p_price number(10),
    v_code number(10) references vendor(v_code)
);
create table line(
    inv_no number(10) references invoice(inv_no),
    line_no number(10) primary key,
    p_code number(10) references product(p_code),
    line_units number(10),
    line_price number(10)
);

-- value insertion
insert into customer(1000,'Tony','Stark',2000.00);
insert into customer(1001,'Steve','Rogers',400.00);
insert into customer(1003,'Bruce','Wayne',4000.00);
insert into customer(1004,'Patrick','Bateman',0.00);

insert into invoice(8000,'','',);
insert into invoice('','','',);
insert into invoice('','','',);
insert into invoice('','','',);

insert into vendor('','','');
insert into product('','','',,'');
insert into line('','','',,);


-- 1. Write a procedure to add a new customer to the CUSTOMER table. Use the following values in the new record: <1002, 'Rauthor', 'Peter', 0.00>. 
-- Run a query to see if the record has been added.
insert into customer(1002,'Rauthor','Peter',0.00);


-- 2. Write a procedure to add a new invoice record to the INVOICE table. Use the following values in the new record: <8006, 1000, '30-APR-16', 301.72>.
-- Run a query to see if therecord has been added.
insert into invoice(8006,'1000','30-APR-16',301.72);

-- 3. Write a cursor to retrieve the customer details who has an invoice amount greater than 10000 made yesterday.

-- 4. Write a cursor to display the list of vendors and their contacts whose product’s stock is zero.

-- 5. Write a PL/SQL function to compute purchase made by a given customer for a particular invoice.
-- Test the function in another function to compute the total purchase made by a customer.

-- 6. Write a procedure to delete an invoice, giving the invoice number as a parameter. 
-- Test the procedure by deleting invoices 8005 and 8006.

-- 7. Write a procedure to display the INV_SUBTOTAL, INV_TAX, and INV_TOTAL. The procedure takes the invoice number as a parameter. 
-- The INV_SUBTOTAL is the sum of the LINE_TOTAL amounts for the invoice, the INV_TAX is the product of the INV_SUBTOTAL and the tax rate
-- (12 percent), and the INV_TOTAL is the sum of the INV_SUBTOTAL and the INV_TAX.

-- 8. MongoDB (Optional)
-- a) Create an Employee Collection add 5 documents:
-- Example:{eno:111,ename:”Francis”, sal:40000.00, dept:{deptno:12, dname:”Hr”, dloc:”Mumbai}, Desg:”Analyst”,mgr:{name:”Sally”,num:101},project:[{name:”Project-1”,Hrs:4},{name:”project- 2”,Hrs:4}]}

-- b) Query the Employee collection to get all documents.

-- c) Perform an update operation for the document by adding project-3 of 6 Hrs.

-- d) Delete one of the documents.