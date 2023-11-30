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
insert into customer values(1, 'John', 'Doe', 1000);
insert into customer values(2, 'Jane', 'Smith', 1500);
insert into customer values(3, 'Michael', 'Johnson', 800);
insert into customer values(4, 'Emily', 'Williams', 2000);
insert into customer values(5, 'Robert', 'Brown', 1200);
insert into customer values(1000, 'Tony', 'Stark', 1000);


insert into invoice values(101, 1, TO_DATE('2023-01-15', 'YYYY-MM-DD'), 500);
insert into invoice values(102, 2, TO_DATE('2023-02-20', 'YYYY-MM-DD'), 750);
insert into invoice values(103, 3, TO_DATE('2023-03-10', 'YYYY-MM-DD'), 300);
insert into invoice values(104, 4, TO_DATE('2023-04-05', 'YYYY-MM-DD'), 1000);
insert into invoice values(105, 5, TO_DATE('2023-05-12', 'YYYY-MM-DD'), 600);

insert into vendor values(1, 'VendorA', '1234567890');
insert into vendor values(2, 'VendorB', '9876543210');
insert into vendor values(3, 'VendorC', '5555555555');
insert into vendor values(4, 'VendorD', '9998887777');
insert into vendor values(5, 'VendorE', '4443332222');

insert into product values(101, 'ProductA', '20 units', 50, 1);
insert into product values(102, 'ProductB', '15 units', 30, 2);
insert into product values(103, 'ProductC', '25 units', 20, 3);
insert into product values(104, 'ProductD', '10 units', 80, 4);
insert into product values(105, 'ProductE', '30 units', 40, 5);

insert into line values(101, 1, 101, 5, 250);
insert into line values(101, 2, 102, 3, 90);
insert into line values(102, 3, 103, 8, 160);
insert into line values(103, 4, 104, 2, 160);
insert into line values(104, 5, 105, 6, 240);


-- 1. Write a procedure to add a new customer to the CUSTOMER table. Use the following values in the new record: <1002, 'Rauthor', 'Peter', 0.00>. 
-- Run a query to see if the record has been added.
-- Create a procedure to add a new customer
CREATE OR REPLACE PROCEDURE Add_New_Customer (
    new_Cus_code NUMBER,
    new_Cus_fname VARCHAR2,
    new_Cus_lname VARCHAR2,
    new_Cus_balance NUMBER
)
AS
BEGIN
    INSERT INTO CUSTOMER_1
    VALUES (new_Cus_code, new_Cus_fname, new_Cus_lname, new_Cus_balance);
    COMMIT;
END;
/
-- Call the procedure to add a new customer
BEGIN
    Add_New_Customer(1002, 'Rauthor', 'Peter', 0.00);
END;
/

--Q2
-- Create a procedure to add a new invoice record
CREATE OR REPLACE PROCEDURE Add_New_Invoice (
    new_Inv_no NUMBER,
    new_Cus_code NUMBER,
    new_Inv_date DATE,
    new_Inv_amount NUMBER
)
AS
BEGIN
    INSERT INTO INVOICE
    VALUES (new_Inv_no, new_Cus_code, new_Inv_date, new_Inv_amount);
    COMMIT;
END;
/

-- Call the procedure to add a new invoice record
BEGIN
    Add_New_Invoice(8006, 1000, '30-APR-16', 301.72);
END;
/

-- Query to see if the record has been added
SELECT * FROM INVOICE WHERE Inv_no = 8006;


--Q3
DECLARE
    CURSOR invoice_cursor IS
        SELECT CUSTOMER.Cus_code, CUSTOMER.Cus_fname, CUSTOMER.Cus_lname, INVOICE.Inv_amount, INVOICE.Inv_date
        FROM CUSTOMER, INVOICE
        WHERE CUSTOMER.Cus_code = INVOICE.Cus_code AND INVOICE.Inv_amount > 10000
        AND TRUNC(INVOICE.Inv_date) = TRUNC(SYSDATE - 1); -- Filters for invoices made yesterday

    v_Cus_code CUSTOMER.Cus_code%TYPE;
    v_Cus_fname CUSTOMER.Cus_fname%TYPE;
    v_Cus_lname CUSTOMER.Cus_lname%TYPE;
    v_Inv_amount INVOICE.Inv_amount%TYPE;
    v_Inv_date INVOICE.Inv_date%TYPE;
BEGIN
    OPEN invoice_cursor;
    LOOP
        FETCH invoice_cursor INTO v_Cus_code, v_Cus_fname, v_Cus_lname, v_Inv_amount, v_Inv_date;
        EXIT WHEN invoice_cursor%NOTFOUND;

        -- Outputting the retrieved customer details
        DBMS_OUTPUT.PUT_LINE('Customer Code: ' || v_Cus_code || ', Name: ' || v_Cus_fname || ' ' || v_Cus_lname || ', Invoice Amount: ' || v_Inv_amount || ', Invoice Date: ' || v_Inv_date);
    END LOOP;

    CLOSE invoice_cursor;
END;
/


--Q4
DECLARE
    CURSOR zero_stock_products IS
        SELECT V_name, V_Contact
        FROM PRODUCT, VENDOR
        WHERE PRODUCT.V_code = VENDOR.V_code AND P_qoh = 0;

    v_V_name VENDOR.V_name%TYPE;
    v_V_Contact VENDOR.V_Contact%TYPE;
BEGIN
    OPEN zero_stock_products;
    LOOP
        FETCH zero_stock_products INTO v_V_name, v_V_Contact;
        EXIT WHEN zero_stock_products%NOTFOUND;

        -- Outputting the vendor details for zero stock products
        DBMS_OUTPUT.PUT_LINE('Vendor Name: ' || v_V_name || ', Contact: ' || v_V_Contact);
    END LOOP;

    CLOSE zero_stock_products;
END;
/


--Q5
-- Function to compute purchase made by a given customer for a particular invoice
CREATE OR REPLACE FUNCTION Compute_Customer_Purchase(
    customer_id IN NUMBER,
    invoice_id IN NUMBER
) RETURN NUMBER
AS
    total_purchase NUMBER;
BEGIN
    SELECT SUM(Line_units * Line_price) INTO total_purchase
    FROM LINE, INVOICE
    WHERE LINE.Inv_no = INVOICE.Inv_no AND INVOICE.Cus_code = customer_id
    AND INVOICE.Inv_no = invoice_id;

    RETURN total_purchase;
END;
/

-- Function to compute total purchase made by a customer
CREATE OR REPLACE FUNCTION Total_Customer_Purchase(
    customer_id IN NUMBER
) RETURN NUMBER
AS
    total_purchase_all NUMBER := 0;
    temp_purchase NUMBER;
BEGIN
    FOR invoice_rec IN (SELECT Inv_no FROM INVOICE WHERE Cus_code = customer_id) LOOP
        temp_purchase := Compute_Customer_Purchase(customer_id, invoice_rec.Inv_no);
        total_purchase_all := total_purchase_all + NVL(temp_purchase, 0);
    END LOOP;

    RETURN total_purchase_all;
END;
/
--testing function
DECLARE
    total_for_customer NUMBER;
BEGIN
    total_for_customer := Total_Customer_Purchase(1000);
    DBMS_OUTPUT.PUT_LINE('Total purchase for customer 1000 across all invoices: ' || total_for_customer);
END;
/

--Q6
CREATE OR REPLACE PROCEDURE Delete_Invoice (
    invoice_no IN NUMBER
)
AS
BEGIN
    DELETE FROM LINE WHERE Inv_no = invoice_no;
    DELETE FROM INVOICE WHERE Inv_no = invoice_no;
    COMMIT;
END;
/
-- Delete invoice 8005
BEGIN
    Delete_Invoice(8005);
END;
/
-- Delete invoice 8006
BEGIN
    Delete_Invoice(8006);
END;
/


--Q7
CREATE OR REPLACE PROCEDURE Calculate_Invoice_Total(
    invoice_number IN NUMBER
)
AS
    inv_subtotal NUMBER;
    inv_tax NUMBER;
    inv_total NUMBER;
BEGIN
    SELECT SUM(Line_units * Line_price) INTO inv_subtotal
    FROM LINE
    WHERE Inv_no = invoice_number;

    inv_tax := inv_subtotal * 0.12; -- Assuming 12% tax rate
    inv_total := inv_subtotal + inv_tax;

    DBMS_OUTPUT.PUT_LINE('Invoice Subtotal: ' || inv_subtotal);
    DBMS_OUTPUT.PUT_LINE('Invoice Tax: ' || inv_tax);
    DBMS_OUTPUT.PUT_LINE('Invoice Total: ' || inv_total);
END;
/
-- Execute the procedure for invoice number 8001
BEGIN
    Calculate_Invoice_Total(8001);
END;
/
