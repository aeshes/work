BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS employee
(
    id        INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
    firstname TEXT NOT NULL,
    lastname  TEXT NOT NULL,
    base_rate DOUBLE,
    hire_date DATE,
    position  INTEGER NOT NULL,
    superior  INTEGER,
	
    FOREIGN KEY(position) REFERENCES department(id),
    FOREIGN KEY(superior) REFERENCES employee(id)
);

INSERT INTO employee VALUES (NULL, 'Haruhi', 'Suzumiya',  50.00, '2017-06-14', 1, 4);
INSERT INTO employee VALUES (NULL, 'Asuka', 'Langley',    50.00, '2014-03-21', 1, 4);
INSERT INTO employee VALUES (NULL, 'Shana', 'Flame Haze', 50.00, '2013-09-17', 1, 5);
INSERT INTO employee VALUES (NULL, 'Shiki', 'Ryogi',      50.00, '2016-11-29', 2, NULL);
INSERT INTO employee VALUES (NULL, 'Kirie', 'Fujou',      50.00, '2011-09-28', 3, NULL);
COMMIT;

BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS department
(
    id   INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL UNIQUE
);

INSERT INTO department(id, name) VALUES
    (NULL, "Employee"),
    (NULL, "Manager"),
    (NULL, "Sales");
COMMIT;

BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS position
(
    employee_id   INTEGER NOT NULL,
    department_id INTEGER NOT NULL
);

INSERT INTO position(employee_id, department_id) VALUES
    (1, 1),
    (2, 1),
    (3, 1),
    (4, 2),
    (5, 3);
COMMIT;

BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS career
(
    employee_id INTEGER NOT NULL,
    position    INTEGER,
    change_date DATE NOT NULL,

    FOREIGN KEY(employee_id) REFERENCES employee(id),
    FOREIGN KEY(position)    REFERENCES department(id)
);

INSERT INTO career(employee_id, position, change_date)
    SELECT id, position, hire_date FROM employee; 
COMMIT;

BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS base_rate_history
(
    position    INTEGER NOT NULL,
    base_rate   DOUBLE  NOT NULL,
    change_date DATE    NOT NULL,

    FOREIGN KEY(position) REFERENCES department(id)
);
COMMIT;

BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS coeff_for_experience_history
(
    position    INTEGER NOT NULL,
    coeff       DOUBLE  NOT NULL,
    change_date DATE    NOT NULL,

    FOREIGN KEY(position) REFERENCES department(id)
);

INSERT INTO coeff_for_experience_history VALUES (1, 0.03, '2011-02-01');
COMMIT;

BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS coeff_for_employees_history
(
    position    INTEGER NOT NULL,
    coeff       DOUBLE  NOT NULL,
    change_date DATE    NOT NULL,

    FOREIGN KEY(position) REFERENCES department(id)
);

INSERT INTO coeff_for_employees_history VALUES (2, 0.0005, '2011-02-01');
INSERT INTO coeff_for_employees_history VALUES (3, 0.0005, '2011-02-01');
COMMIT;

BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS extra_pay_limit_history
(
    position    INTEGER NOT NULL,
    extra_pay   DOUBLE  NOT NULL,
    change_date DATE    NOT NULL,

    FOREIGN KEY(position) REFERENCES department(id)
);

INSERT INTO extra_pay_limit_history VALUES (1, 0.3, '2011-02-01');
INSERT INTO extra_pay_limit_history VALUES (2, 0.4, '2011-02-01');
INSERT INTO extra_pay_limit_history VALUES (3, 0.4, '2011-02-01');
COMMIT;